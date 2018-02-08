let component = ReasonReact.statelessComponent("Example");

let make = _children => {
  ...component,
  render: _self =>
    <MaterialUi.WithStyles
      classes=[
        {
          name: "alignRight",
          styles: ReactDOMRe.Style.make(~width="100%", ~textAlign="right", ())
        }
      ]
      render=(
        classes =>
          <div className=classes##alignRight>
            (
              ReasonReact.stringToElement("Example text - aligned to the right")
            )
          </div>
      )
    />
};