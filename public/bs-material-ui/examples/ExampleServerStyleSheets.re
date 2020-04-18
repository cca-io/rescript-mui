[%mui.withStyles
  "Styles"({
    code:
      ReactDOMRe.Style.make(
        ~fontFamily="SFMono-Regular,Consolas,Liberation Mono,Menlo,monospace",
        ~marginTop="15px",
        (),
      ),
  })
];

[@react.component]
let make = () => {
  let classes = Styles.useStyles();
  let (html, css) =
    React.useMemo0(() => {
      let sheets = MaterialUi.Core.ServerStyleSheets.make();
      let html =
        ReactDOMServerRe.renderToString(
          sheets->MaterialUi.Core.ServerStyleSheets.collect(<ExampleBox />),
        );
      let css = sheets->MaterialUi.Core.ServerStyleSheets.toString;
      (html, css);
    });

  MaterialUi.(
    <div>
      <Typography variant=`H5>
        "ServerSide render of <ExampleBox />"
      </Typography>
      <TextField
        className={classes.code}
        rows={`Int(5)}
        label={"HTML"->React.string}
        multiline=true
        fullWidth=true
        variant=`Outlined
        defaultValue={`String(html)}
      />
      <TextField
        className={classes.code}
        rows={`Int(5)}
        label={"CSS"->React.string}
        multiline=true
        fullWidth=true
        variant=`Outlined
        defaultValue={`String(css)}
      />
    </div>
  );
};