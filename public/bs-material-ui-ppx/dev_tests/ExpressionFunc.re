[%mui.withStyles
  "StyledExample"(theme => {
    Js.log(theme);
    let x = "hellooo";
    Js.log(x);
    {
      alignRight: ReactDOM.Style.make(~width="100%", ~textAlign="right", ()),
    };
  })
];
