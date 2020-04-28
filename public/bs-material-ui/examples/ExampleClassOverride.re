module OverrideExample = [%makeStyles
  {
    fontSize: ReactDOMRe.Style.make(~fontSize="30px", ()),
    bgColor:
      ReactDOMRe.Style.make(~backgroundColor=MaterialUi.Colors.red.c300, ()),
  }
];

[@react.component]
let make = () => {
  let classes = OverrideExample.useStyles();

  MaterialUi.(
    <Button
      color=`Primary
      variant=`Contained
      classes={Button.Classes.make(
        ~root=classes.fontSize,
        ~containedPrimary=classes.bgColor,
        (),
      )}>
      {ReasonReact.string("Example Button")}
    </Button>
  );
};
