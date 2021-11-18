// Generated by ReScript, PLEASE EDIT WITH CARE

import * as React from "react";
import * as ExampleBox from "./ExampleBox.bs.js";
import * as ExampleList from "./ExampleList.bs.js";
import * as ExampleTabs from "./ExampleTabs.bs.js";
import * as ExampleIcons from "./ExampleIcons.bs.js";
import * as ExampleSelect from "./ExampleSelect.bs.js";
import * as ExampleSlider from "./ExampleSlider.bs.js";
import * as ExampleStyles from "./ExampleStyles.bs.js";
import * as ExamplePopover from "./ExamplePopover.bs.js";
import * as ExampleStepper from "./ExampleStepper.bs.js";
import * as Grid$MaterialUi from "rescript-material-ui/src/Grid.bs.js";
import * as ExampleDashboard from "./ExampleDashboard.bs.js";
import * as Core from "@material-ui/core";
import * as ExampleClassOverride from "./ExampleClassOverride.bs.js";
import * as ExampleTextFieldSize from "./ExampleTextFieldSize.bs.js";
import * as ExampleThemeProvider from "./ExampleThemeProvider.bs.js";
import * as ExampleServerStyleSheets from "./ExampleServerStyleSheets.bs.js";
import * as ExampleThemeProviderOverride from "./ExampleThemeProviderOverride.bs.js";

function Examples(Props) {
  return React.createElement(React.Fragment, undefined, React.createElement(Core.Grid, {
                  children: React.createElement(Core.Grid, {
                        children: React.createElement(Core.Typography, {
                              children: "ReScript Material-UI Examples",
                              variant: "h4"
                            }),
                        item: true,
                        md: Grid$MaterialUi.Md[12]
                      }),
                  container: true
                }), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: "Class Override",
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleClassOverride.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: "Icons",
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleIcons.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: "Popover",
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExamplePopover.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: "Styles",
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleStyles.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: "Theme Provider",
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleThemeProvider.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: "Theme Provider Override",
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleThemeProviderOverride.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: "List",
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleList.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: React.createElement("a", {
                                  href: "https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/tabs/DisabledTabs.tsx",
                                  target: "_blank"
                                }, "Tabs"),
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleTabs.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: React.createElement("a", {
                                  href: "https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/steppers/VerticalLinearStepper.tsx",
                                  target: "_blank"
                                }, "Stepper"),
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleStepper.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: React.createElement("a", {
                                  href: "https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/selects/SimpleSelect.tsx",
                                  target: "_blank"
                                }, "Select"),
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleSelect.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: React.createElement("a", {
                                  href: "https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/slider/InputSlider.tsx",
                                  target: "_blank"
                                }, "Slider"),
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleSlider.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: React.createElement("a", {
                                  href: "https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/slider/InputSlider.tsx",
                                  target: "_blank"
                                }, "Dashboard"),
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleDashboard.make, {
                            sidebar: "Sidebar",
                            children: "Content"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: React.createElement("a", {
                                  href: "https://github.com/mui-org/material-ui/blob/master/docs/src/pages/components/box/box.md",
                                  target: "_blank"
                                }, "Box"),
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleBox.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: React.createElement("a", {
                                  href: "https://github.com/mui-org/material-ui/blob/master/docs/src/pages/styles/api/api.md#serverstylesheets",
                                  target: "_blank"
                                }, "ServerStyleSheets"),
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleServerStyleSheets.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Divider, {}), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement(Core.Grid, {
                  alignItems: "center",
                  children: null,
                  container: true
                }, React.createElement(Core.Grid, {
                      children: React.createElement(Core.Typography, {
                            children: "TextField size Prop",
                            variant: "h5"
                          }),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    }), React.createElement(Core.Grid, {
                      children: React.createElement(ExampleTextFieldSize.make, {}),
                      item: true,
                      md: Grid$MaterialUi.Md[6]
                    })), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement("br", undefined), React.createElement("br", undefined));
}

var make = Examples;

export {
  make ,
  
}
/* react Not a pure module */
