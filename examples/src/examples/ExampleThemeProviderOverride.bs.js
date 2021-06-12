// Generated by ReScript, PLEASE EDIT WITH CARE

import * as React from "react";
import * as ReactDOMStyle from "@rescript/react/src/ReactDOMStyle.bs.js";
import * as Core from "@material-ui/core";
import * as Styles from "@material-ui/core/styles";
import SupervisedUserCircle from "@material-ui/icons/SupervisedUserCircle";

var theme = Styles.createMuiTheme({
      overrides: {
        MuiButton: {
          outlined: ReactDOMStyle.unsafeAddProp({
                color: "gray",
                fontSize: "12px",
                fontWeight: "300"
              }, "& svg", {
                fontSize: "16px",
                marginRight: "15px"
              })
        }
      }
    });

var SupervisedUserCircleIcon = {};

function ExampleThemeProviderOverride(Props) {
  return React.createElement("div", undefined, React.createElement(Styles.ThemeProvider, {
                  children: React.createElement(Core.Button, {
                        children: null,
                        color: "secondary",
                        variant: "outlined"
                      }, React.createElement(SupervisedUserCircle, {}), "Overriden Outline Styles"),
                  theme: theme
                }));
}

var make = ExampleThemeProviderOverride;

export {
  theme ,
  SupervisedUserCircleIcon ,
  make ,
  
}
/* theme Not a pure module */
