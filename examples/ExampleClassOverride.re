let component = ReasonReact.statelessComponent("Example");

[%mui.withStyles
  "OverrideExample"({
    fontSize: ReactDOMRe.Style.make(~fontSize="30px", ()),
    bgColor:
      ReactDOMRe.Style.make(~backgroundColor=MaterialUi.Colors.Red.c300, ())
  })
];

let make = _children => {
  ...component,
  render: _self =>
    <OverrideExample
      render=(
        classes =>
          <MaterialUi.Button
            color=`Primary
            variant=`Raised
            classes=[Root(classes.fontSize), RaisedPrimary(classes.bgColor)]>
            (ReasonReact.stringToElement("Example Button"))
          </MaterialUi.Button>
      )
    />
};