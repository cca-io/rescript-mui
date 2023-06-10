external toDomElement: 'a => Dom.element = "%identity"

let messages: array<string> = %raw(` [...'养绌聭'] `)

type state = {
  anchorEl: option<Dom.element>,
  popupMessage: string,
}

type action =
  | OpenPopup((Dom.element, string))
  | ClosePopup

let reducer = (state: state, action: action) =>
  switch action {
  | OpenPopup((el, message)) => {anchorEl: Some(el), popupMessage: message}
  | ClosePopup => {...state, anchorEl: None}
  }

@react.component
let make = () => {
  let (state, dispatch) = React.useReducer(reducer, {anchorEl: None, popupMessage: ""})

  open Mui
  <div>
    <Popover
      open_={Belt.Option.isSome(state.anchorEl)}
      onClose={(_evt, _) => dispatch(ClosePopup)}
      anchorEl=?{state.anchorEl->Belt.Option.map(el => el->ReactDOM.domElementToObj->Obj.magic)}>
      <div
        style={ReactDOM.Style.make(
          ~fontSize="6rem",
          ~margin="1rem",
          ~backgroundColor="salmon",
          (),
        )}>
        {React.string(state.popupMessage)}
      </div>
    </Popover>
    <Mui.List>
      {messages
      ->Belt.Array.mapWithIndex((i, message) =>
        <ListItem
          button=true
          key={string_of_int(i)}
          onClick={evt =>
            dispatch(OpenPopup((evt->ReactEvent.Mouse.target->toDomElement, message)))}>
          <ListItemText> {React.string(message)} </ListItemText>
        </ListItem>
      )
      ->React.array}
    </Mui.List>
  </div>
}
