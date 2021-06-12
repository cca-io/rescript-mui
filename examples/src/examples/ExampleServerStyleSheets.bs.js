// Generated by ReScript, PLEASE EDIT WITH CARE

import * as React from "react";
import * as ExampleBox from "./ExampleBox.bs.js";
import * as Core from "@material-ui/core";
import * as Styles from "@material-ui/styles";
import * as ServerJs from "react-dom/server.js";
import * as MaterialUi_TextField from "rescript-material-ui/src/MaterialUi_TextField.bs.js";
import * as Styles$1 from "@material-ui/core/styles";

var useStyles = Styles.makeStyles({
      code: {
        fontFamily: "SFMono-Regular,Consolas,Liberation Mono,Menlo,monospace",
        marginTop: "15px"
      }
    });

function ExampleServerStyleSheets(Props) {
  var classes = useStyles();
  var match = React.useMemo((function () {
          var sheets = new Styles$1.ServerStyleSheets();
          var html = ServerJs.renderToString(sheets.collect(React.createElement(ExampleBox.make, {})));
          var css = sheets.toString();
          return [
                  html,
                  css
                ];
        }), []);
  return React.createElement("div", undefined, React.createElement(Core.Typography, {
                  children: "ServerSide render of <ExampleBox />",
                  variant: "h5"
                }), React.createElement(Core.TextField, {
                  className: classes.code,
                  defaultValue: MaterialUi_TextField.DefaultValue.string(match[0]),
                  fullWidth: true,
                  label: "HTML",
                  multiline: true,
                  rows: MaterialUi_TextField.Rows.$$int(5),
                  variant: "outlined"
                }), React.createElement(Core.TextField, {
                  className: classes.code,
                  defaultValue: MaterialUi_TextField.DefaultValue.string(match[1]),
                  fullWidth: true,
                  label: "CSS",
                  multiline: true,
                  rows: MaterialUi_TextField.Rows.$$int(5),
                  variant: "outlined"
                }));
}

var make = ExampleServerStyleSheets;

export {
  useStyles ,
  make ,
  
}
/* useStyles Not a pure module */
