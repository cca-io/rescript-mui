// Generated by ReScript, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Caml_option from "rescript/lib/es6/caml_option.js";
import Box from "@mui/material/Box";
import * as JsxRuntime from "react/jsx-runtime";
import Checkbox from "@mui/material/Checkbox";
import FormGroup from "@mui/material/FormGroup";
import Typography from "@mui/material/Typography";
import FormControlLabel from "@mui/material/FormControlLabel";

function ExampleCheckbox(props) {
  var match = React.useState(function () {
        return true;
      });
  var setChecked = match[1];
  var checked = match[0];
  var match$1 = React.useState(function () {
        return true;
      });
  var setIndeterminate = match$1[1];
  var indeterminate = match$1[0];
  var handleChange = function (_event, checked) {
    setChecked(function (param) {
          return checked;
        });
  };
  var handleIndeterminateChange = function (_event, checked) {
    setIndeterminate(function (param) {
          return checked;
        });
  };
  return JsxRuntime.jsxs("div", {
              children: [
                JsxRuntime.jsx(Typography, {
                      variant: "h6",
                      children: "Checkbox Examples:"
                    }),
                JsxRuntime.jsx(Box, {
                      children: Caml_option.some(JsxRuntime.jsxs(FormGroup, {
                                children: [
                                  JsxRuntime.jsx(FormControlLabel, {
                                        control: JsxRuntime.jsx(Checkbox, {
                                              id: "checkbox-default",
                                              defaultChecked: true
                                            }),
                                        label: "Default"
                                      }),
                                  JsxRuntime.jsx(FormControlLabel, {
                                        control: JsxRuntime.jsx(Checkbox, {
                                              id: "checkbox-controlled",
                                              checked: checked,
                                              onChange: handleChange
                                            }),
                                        label: "Controlled"
                                      }),
                                  JsxRuntime.jsx(FormControlLabel, {
                                        control: JsxRuntime.jsx(Checkbox, {
                                              id: "checkbox-indeterminate",
                                              checked: !indeterminate && checked,
                                              indeterminate: indeterminate,
                                              onChange: handleIndeterminateChange
                                            }),
                                        label: "Indeterminate"
                                      }),
                                  JsxRuntime.jsx(FormControlLabel, {
                                        control: JsxRuntime.jsx(Checkbox, {
                                              id: "checkbox-disabled",
                                              disabled: true
                                            }),
                                        label: "Disabled"
                                      }),
                                  JsxRuntime.jsx(FormControlLabel, {
                                        control: JsxRuntime.jsx(Checkbox, {
                                              id: "checkbox-color-success",
                                              color: "success",
                                              defaultChecked: true
                                            }),
                                        label: "Success Color"
                                      }),
                                  JsxRuntime.jsx(FormControlLabel, {
                                        control: JsxRuntime.jsx(Checkbox, {
                                              id: "checkbox-color-error",
                                              color: "error",
                                              defaultChecked: true
                                            }),
                                        label: "Error Color"
                                      }),
                                  JsxRuntime.jsx(FormControlLabel, {
                                        control: JsxRuntime.jsx(Checkbox, {
                                              id: "checkbox-icon",
                                              checkedIcon: Caml_option.some(JsxRuntime.jsx("span", {
                                                        children: "☑"
                                                      })),
                                              defaultChecked: true,
                                              icon: Caml_option.some(JsxRuntime.jsx("span", {
                                                        children: "☐"
                                                      }))
                                            }),
                                        label: "Custom Icon"
                                      })
                                ]
                              }))
                    })
              ]
            });
}

var make = ExampleCheckbox;

export {
  make ,
}
/* react Not a pure module */
