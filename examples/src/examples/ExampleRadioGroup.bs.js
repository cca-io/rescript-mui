// Generated by ReScript, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Caml_option from "rescript/lib/es6/caml_option.js";
import * as JsxRuntime from "react/jsx-runtime";
import Radio from "@mui/material/Radio";
import RadioGroup from "@mui/material/RadioGroup";
import FormControlLabel from "@mui/material/FormControlLabel";

function ExampleRadioGroup(props) {
  var match = React.useState(function () {
        return "Yes";
      });
  var setState = match[1];
  return JsxRuntime.jsxs(RadioGroup, {
              children: [
                JsxRuntime.jsx(FormControlLabel, {
                      control: JsxRuntime.jsx(Radio, {}),
                      label: "Yes",
                      value: "Yes"
                    }),
                JsxRuntime.jsx(FormControlLabel, {
                      control: JsxRuntime.jsx(Radio, {}),
                      label: "No",
                      value: "No"
                    }),
                JsxRuntime.jsx(FormControlLabel, {
                      control: JsxRuntime.jsx(Radio, {}),
                      label: "Maybe",
                      value: "Maybe"
                    })
              ],
              name: "answer",
              onChange: (function (e, param) {
                  var value = e.target.value;
                  setState(function (param) {
                        return value;
                      });
                }),
              value: Caml_option.some(match[0])
            });
}

var make = ExampleRadioGroup;

export {
  make ,
}
/* react Not a pure module */
