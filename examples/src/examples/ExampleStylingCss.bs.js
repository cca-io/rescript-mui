// Generated by ReScript, PLEASE EDIT WITH CARE

import * as Styles from "@mui/styles";
import * as Material from "@mui/material";
import * as JsxRuntime from "react/jsx-runtime";

function ExampleStylingCss(props) {
  return JsxRuntime.jsx(Styles.StylesProvider, {
              injectFirst: true,
              children: JsxRuntime.jsx((function (prim) {
                      return Material.Button(prim);
                    }), {
                    className: "my-global-class-name",
                    onClick: (function (prim) {
                        
                      }),
                    children: "Hello, plain CSS & MUI!",
                    color: "primary"
                  })
            });
}

var make = ExampleStylingCss;

export {
  make ,
}
/* @mui/styles Not a pure module */
