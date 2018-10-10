let component = ReasonReact.statelessComponent("Example");

[%mui.withStyles
  "StyledExample"({
    alignRight: ReactDOMRe.Style.make(~width="100%", ~textAlign="right", ()),
  })
];

let make = _children => {
  ...component,
  render: _self =>
    <StyledExample
      render={
        classes =>
          <div className={classes.alignRight}>
            {ReasonReact.string("Example text - aligned to the right")}
          </div>
      }
    />,
};