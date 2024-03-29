// Generated by ReScript, PLEASE EDIT WITH CARE

import * as CssJs from "bs-css-emotion/src/CssJs.bs.js";
import * as JsxRuntime from "react/jsx-runtime";
import Button from "@mui/material/Button";
import * as Styles from "@mui/material/styles";

var categoryButton = CssJs.style([
      CssJs.textTransform("none"),
      CssJs.justifyContent("flexStart")
    ]);

var Styles$1 = {
  categoryButton: categoryButton
};

function ExampleStylingBsCss(props) {
  return JsxRuntime.jsx(Styles.StyledEngineProvider, {
              children: JsxRuntime.jsx(Button, {
                    children: "Hello, BS-CSS & MUI!",
                    onClick: (function (prim) {
                        
                      }),
                    classes: {
                      root: categoryButton
                    },
                    color: "primary"
                  }),
              injectFirst: true
            });
}

var make = ExampleStylingBsCss;

export {
  Styles$1 as Styles,
  make ,
}
/* categoryButton Not a pure module */
