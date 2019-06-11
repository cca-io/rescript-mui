[%mui.withStyles
  "OverrideExample"({
    fontSize: ReactDOMRe.Style.make(~fontSize="30px", ()),
    bgColor:
      ReactDOMRe.Style.make(~backgroundColor=MaterialUi.Colors.Red.c300, ()),
  })
];

[@react.component]
let make = () =>
  <OverrideExample>
    ...{classes =>
      <MaterialUi.Button
        color=`Primary
        variant=`Contained
        classes=[Root(classes.fontSize), ContainedPrimary(classes.bgColor)]>
        {ReasonReact.string("Example Button")}
      </MaterialUi.Button>
    }
  </OverrideExample>;