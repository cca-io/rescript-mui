[@bs.module "@material-ui/core/styles"]
external withStyles: (. 'a) => (. 'b) => ReasonReact.reactClass = "";

let createStyled = styles =>
  (withStyles(. styles))(. props =>
    props##children({"classes": props##classes})
  );