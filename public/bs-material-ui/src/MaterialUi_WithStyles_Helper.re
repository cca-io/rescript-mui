[@bs.module "@material-ui/core/styles"]
external withStyles: (. 'a) => (. 'b) => React.component('c) = "";

let createStyled = styles =>
  (withStyles(. styles))(. props =>
    props##children({"classes": props##classes})
  );
