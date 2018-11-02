open Belt;

external toDomElement: 'a => Dom.element = "%identity";

let messages: array(string) = [%bs.raw {| [...'养绌聭'] |}];

type state = {
  anchorEl: option(Dom.element),
  popupMessage: string,
};

type action =
  | OpenPopup((Dom.element, string))
  | ClosePopup;

/* This is the basic component. */
let component = ReasonReact.reducerComponent("PopoverExample");

let make = _children => {
  ...component,
  initialState: () => {anchorEl: None, popupMessage: ""},
  reducer: (action, state) =>
    switch (action) {
    | OpenPopup((el, message)) =>
      ReasonReact.Update({anchorEl: Some(el), popupMessage: message})
    | ClosePopup => ReasonReact.Update({...state, anchorEl: None})
    },
  render: self =>
    MaterialUi.(
      <div>
        <Popover
          open_={Option.isSome(self.state.anchorEl)}
          onClose={_evt => self.send(ClosePopup)}
          anchorEl=?{
            self.state.anchorEl
            ->(
                Option.map(el =>
                  `ObjectGeneric(el->ReactDOMRe.domElementToObj)
                )
              )
          }>
          <div
            style={
              ReactDOMRe.Style.make(
                ~fontSize="6rem",
                ~margin="1rem",
                ~backgroundColor="salmon",
                (),
              )
            }>
            {ReasonReact.string(self.state.popupMessage)}
          </div>
        </Popover>
        <MaterialUi.List>
          messages->(
                      Array.mapWithIndex((i, message) =>
                        <ListItem
                          button=true
                          key={string_of_int(i)}
                          onClick={
                            evt =>
                              self.send(
                                OpenPopup((
                                  evt->ReactEvent.Mouse.target->toDomElement,
                                  message,
                                )),
                              )
                          }>
                          <ListItemText
                            primary={ReasonReact.string(message)}
                          />
                        </ListItem>
                      )
                    )
        </MaterialUi.List>
      </div>
    ),
};