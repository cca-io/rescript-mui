@bs.module("@material-ui/core/styles")
external withStyles: (. 'a) => (. 'b) => React.component<'c> = "withStyles";

let createStyled = styles =>
  (withStyles(. styles))(. props =>
    props["children"]({"classes": props["classes"]})
  );