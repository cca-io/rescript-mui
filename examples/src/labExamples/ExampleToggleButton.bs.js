// Generated by ReScript, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Caml_option from "rescript/lib/es6/caml_option.js";
import * as Material from "@mui/material";
import * as JsxRuntime from "react/jsx-runtime";
import FormatBold from "@mui/icons-material/FormatBold";
import FormatItalic from "@mui/icons-material/FormatItalic";
import ArrowDropDown from "@mui/icons-material/ArrowDropDown";
import FormatAlignLeft from "@mui/icons-material/FormatAlignLeft";
import FormatColorFill from "@mui/icons-material/FormatColorFill";
import FormatAlignRight from "@mui/icons-material/FormatAlignRight";
import FormatUnderlined from "@mui/icons-material/FormatUnderlined";
import FormatAlignCenter from "@mui/icons-material/FormatAlignCenter";
import FormatAlignJustify from "@mui/icons-material/FormatAlignJustify";

var FormatAlignLeftIcon = {};

var FormatAlignCenterIcon = {};

var FormatAlignRightIcon = {};

var FormatAlignJustifyIcon = {};

var FormatBoldIcon = {};

var FormatItalicIcon = {};

var FormatUnderlinedIcon = {};

var FormatColorFillIcon = {};

var ArrowDropDownIcon = {};

function ExampleToggleButton(props) {
  var match = React.useReducer((function (param, v) {
          return v;
        }), "left");
  var setAlignment = match[1];
  var match$1 = React.useReducer((function (param, v) {
          return v;
        }), ["bold"]);
  var setFormats = match$1[1];
  var handleAlignment = function (param, v) {
    setAlignment(v);
  };
  var handleFormats = function (param, v) {
    setFormats(v);
  };
  return JsxRuntime.jsxs((function (prim) {
                return Material.Grid(prim);
              }), {
              children: [
                JsxRuntime.jsxs((function (prim) {
                        return Material.Grid(prim);
                      }), {
                      children: [
                        JsxRuntime.jsx((function (prim) {
                                return Material.Box(prim);
                              }), {
                              mb: 2,
                              mt: 2,
                              children: Caml_option.some(JsxRuntime.jsxs((function (prim) {
                                          return Material.ToggleButtonGroup(prim);
                                        }), {
                                        children: [
                                          JsxRuntime.jsx((function (prim) {
                                                  return Material.ToggleButton(prim);
                                                }), {
                                                children: Caml_option.some(JsxRuntime.jsx(FormatAlignLeft, {})),
                                                value: "left"
                                              }),
                                          JsxRuntime.jsx((function (prim) {
                                                  return Material.ToggleButton(prim);
                                                }), {
                                                children: Caml_option.some(JsxRuntime.jsx(FormatAlignCenter, {})),
                                                value: "center"
                                              }),
                                          JsxRuntime.jsx((function (prim) {
                                                  return Material.ToggleButton(prim);
                                                }), {
                                                children: Caml_option.some(JsxRuntime.jsx(FormatAlignRight, {})),
                                                value: "right"
                                              }),
                                          JsxRuntime.jsx((function (prim) {
                                                  return Material.ToggleButton(prim);
                                                }), {
                                                children: Caml_option.some(JsxRuntime.jsx(FormatAlignJustify, {})),
                                                disabled: true,
                                                value: "justify"
                                              })
                                        ],
                                        exclusive: true,
                                        onChange: handleAlignment,
                                        value: Caml_option.some(match[0])
                                      }))
                            }),
                        JsxRuntime.jsx((function (prim) {
                                return Material.Typography(prim);
                              }), {
                              gutterBottom: true,
                              children: "Exclusive Selection"
                            }),
                        JsxRuntime.jsx((function (prim) {
                                return Material.Typography(prim);
                              }), {
                              children: "Text justification toggle buttons present options for left, right, center, full, and\n      justified text with only one item available for selection at a time. Selecting one option\n      deselects any other."
                            })
                      ],
                      item: true,
                      md: 6,
                      sm: 12
                    }),
                JsxRuntime.jsxs((function (prim) {
                        return Material.Grid(prim);
                      }), {
                      children: [
                        JsxRuntime.jsx((function (prim) {
                                return Material.Box(prim);
                              }), {
                              mb: 2,
                              mt: 2,
                              children: Caml_option.some(JsxRuntime.jsxs((function (prim) {
                                          return Material.ToggleButtonGroup(prim);
                                        }), {
                                        children: [
                                          JsxRuntime.jsx((function (prim) {
                                                  return Material.ToggleButton(prim);
                                                }), {
                                                children: Caml_option.some(JsxRuntime.jsx(FormatBold, {})),
                                                value: "bold"
                                              }),
                                          JsxRuntime.jsx((function (prim) {
                                                  return Material.ToggleButton(prim);
                                                }), {
                                                children: Caml_option.some(JsxRuntime.jsx(FormatItalic, {})),
                                                value: "italic"
                                              }),
                                          JsxRuntime.jsx((function (prim) {
                                                  return Material.ToggleButton(prim);
                                                }), {
                                                children: Caml_option.some(JsxRuntime.jsx(FormatUnderlined, {})),
                                                value: "underlined"
                                              }),
                                          JsxRuntime.jsxs((function (prim) {
                                                  return Material.ToggleButton(prim);
                                                }), {
                                                children: [
                                                  JsxRuntime.jsx(FormatColorFill, {}),
                                                  JsxRuntime.jsx(ArrowDropDown, {})
                                                ],
                                                disabled: true,
                                                value: "color"
                                              })
                                        ],
                                        onChange: handleFormats,
                                        value: Caml_option.some(match$1[0])
                                      }))
                            }),
                        JsxRuntime.jsx((function (prim) {
                                return Material.Typography(prim);
                              }), {
                              gutterBottom: true,
                              children: "Multiple Selection"
                            }),
                        JsxRuntime.jsx((function (prim) {
                                return Material.Typography(prim);
                              }), {
                              children: "Logically-grouped options, like Bold, Italic, and Underline, allow multiple options to be\n      selected."
                            })
                      ],
                      item: true,
                      md: 6,
                      sm: 12
                    })
              ],
              container: true,
              spacing: 2
            });
}

var make = ExampleToggleButton;

export {
  FormatAlignLeftIcon ,
  FormatAlignCenterIcon ,
  FormatAlignRightIcon ,
  FormatAlignJustifyIcon ,
  FormatBoldIcon ,
  FormatItalicIcon ,
  FormatUnderlinedIcon ,
  FormatColorFillIcon ,
  ArrowDropDownIcon ,
  make ,
}
/* react Not a pure module */
