module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  @unboxed
  type rec t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

module PaletteColor: {
  type t;

  @bs.inline("common.black")
  let common_black: t;
  @bs.inline("common.white")
  let common_white: t;
  @bs.inline("primary.light")
  let primary_light: t;
  @bs.inline("primary.main")
  let primary_main: t;
  @bs.inline("primary.dark")
  let primary_dark: t;
  @bs.inline("primary.contrastText")
  let primary_contrastText: t;
  @bs.inline("secondary.light")
  let secondary_light: t;
  @bs.inline("secondary.main")
  let secondary_main: t;
  @bs.inline("secondary.dark")
  let secondary_dark: t;
  @bs.inline("secondary.contrastText")
  let secondary_contrastText: t;
  @bs.inline("error.light")
  let error_light: t;
  @bs.inline("error.main")
  let error_main: t;
  @bs.inline("error.dark")
  let error_dark: t;
  @bs.inline("error.contrastText")
  let error_contrastText: t;
  @bs.inline("warning.light")
  let warning_light: t;
  @bs.inline("warning.main")
  let warning_main: t;
  @bs.inline("warning.dark")
  let warning_dark: t;
  @bs.inline("warning.contrastText")
  let warning_contrastText: t;
  @bs.inline("info.light")
  let info_light: t;
  @bs.inline("info.main")
  let info_main: t;
  @bs.inline("info.dark")
  let info_dark: t;
  @bs.inline("info.contrastText")
  let info_contrastText: t;
  @bs.inline("success.light")
  let success_light: t;
  @bs.inline("success.main")
  let success_main: t;
  @bs.inline("success.dark")
  let success_dark: t;
  @bs.inline("success.contrastText")
  let success_contrastText: t;
  @bs.inline("text.primary")
  let text_primary: t;
  @bs.inline("text.secondary")
  let text_secondary: t;
  @bs.inline("text.disabled")
  let text_disabled: t;
  @bs.inline("text.hint")
  let text_hint: t;
  @bs.inline("divider")
  let divider: t;
  @bs.inline("action.active")
  let action_active: t;
  @bs.inline("action.hover")
  let action_hover: t;
  @bs.inline("action.hoverOpacity")
  let action_hoverOpacity: t;
  @bs.inline("action.selected")
  let action_selected: t;
  @bs.inline("action.selectedOpacity")
  let action_selectedOpacity: t;
  @bs.inline("action.disabled")
  let action_disabled: t;
  @bs.inline("action.disabledOpacity")
  let action_disabledOpacity: t;
  @bs.inline("action.disabledBackground")
  let action_disabledBackground: t;
  @bs.inline("action.focus")
  let action_focus: t;
  @bs.inline("action.focusOpacity")
  let action_focusOpacity: t;
  @bs.inline("action.activatedOpacity")
  let action_activatedOpacity: t;
  @bs.inline("background.default")
  let background_default: t;
  @bs.inline("background.paper")
  let background_paper: t;
} = {
  type t = string;

  @bs.inline
  let common_black = "common.black";
  @bs.inline
  let common_white = "common.white";
  @bs.inline
  let primary_light = "primary.light";
  @bs.inline
  let primary_main = "primary.main";
  @bs.inline
  let primary_dark = "primary.dark";
  @bs.inline
  let primary_contrastText = "primary.contrastText";
  @bs.inline
  let secondary_light = "secondary.light";
  @bs.inline
  let secondary_main = "secondary.main";
  @bs.inline
  let secondary_dark = "secondary.dark";
  @bs.inline
  let secondary_contrastText = "secondary.contrastText";
  @bs.inline
  let error_light = "error.light";
  @bs.inline
  let error_main = "error.main";
  @bs.inline
  let error_dark = "error.dark";
  @bs.inline
  let error_contrastText = "error.contrastText";
  @bs.inline
  let warning_light = "warning.light";
  @bs.inline
  let warning_main = "warning.main";
  @bs.inline
  let warning_dark = "warning.dark";
  @bs.inline
  let warning_contrastText = "warning.contrastText";
  @bs.inline
  let info_light = "info.light";
  @bs.inline
  let info_main = "info.main";
  @bs.inline
  let info_dark = "info.dark";
  @bs.inline
  let info_contrastText = "info.contrastText";
  @bs.inline
  let success_light = "success.light";
  @bs.inline
  let success_main = "success.main";
  @bs.inline
  let success_dark = "success.dark";
  @bs.inline
  let success_contrastText = "success.contrastText";
  @bs.inline
  let text_primary = "text.primary";
  @bs.inline
  let text_secondary = "text.secondary";
  @bs.inline
  let text_disabled = "text.disabled";
  @bs.inline
  let text_hint = "text.hint";
  @bs.inline
  let divider = "divider";
  @bs.inline
  let action_active = "action.active";
  @bs.inline
  let action_hover = "action.hover";
  @bs.inline
  let action_hoverOpacity = "action.hoverOpacity";
  @bs.inline
  let action_selected = "action.selected";
  @bs.inline
  let action_selectedOpacity = "action.selectedOpacity";
  @bs.inline
  let action_disabled = "action.disabled";
  @bs.inline
  let action_disabledOpacity = "action.disabledOpacity";
  @bs.inline
  let action_disabledBackground = "action.disabledBackground";
  @bs.inline
  let action_focus = "action.focus";
  @bs.inline
  let action_focusOpacity = "action.focusOpacity";
  @bs.inline
  let action_activatedOpacity = "action.activatedOpacity";
  @bs.inline
  let background_default = "background.default";
  @bs.inline
  let background_paper = "background.paper";
};

module BreakpointObj = {
  @bs.deriving(abstract)
  type t<'a> = {
    @bs.optional
    xs: 'a,
    @bs.optional
    sm: 'a,
    @bs.optional
    md: 'a,
    @bs.optional
    lg: 'a,
    @bs.optional
    xl: 'a,
  };
  let make = t;
};

module Value: {
  type t;
  let string: string => t;
  let int: int => t;
  let float: float => t;
  let paletteColor: PaletteColor.t => t;
  let array: array<t> => t;
  let breakpointObj: BreakpointObj.t<t> => t;
} = {
  @unboxed
  type rec t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
  let paletteColor = (v: PaletteColor.t) => Any(v);
  let array = (v: array<t>) => Any(v);
  let breakpointObj = (v: BreakpointObj.t<t>) => Any(v);
};

@react.component @bs.module("@material-ui/core")
external make:
  (
    ~component: option<Component.t>=?,
    ~className: option<string>=?,
    ~style: option<ReactDOMRe.Style.t>=?,
    ~clone: option<bool>=?,
    ~children: option<'children>=?,
    ~alignContent: option<Value.t>=?,
    ~alignItems: option<Value.t>=?,
    ~alignSelf: option<Value.t>=?,
    ~bgcolor: option<Value.t>=?,
    ~border: option<Value.t>=?,
    ~borderBottom: option<Value.t>=?,
    ~borderColor: option<Value.t>=?,
    ~borderLeft: option<Value.t>=?,
    ~borderRadius: option<Value.t>=?,
    ~borderRight: option<Value.t>=?,
    ~borderTop: option<Value.t>=?,
    ~boxShadow: option<Value.t>=?,
    ~boxSizing: option<Value.t>=?,
    ~color: option<Value.t>=?,
    ~display: option<Value.t>=?,
    ~displayPrint: option<Value.t>=?,
    ~flex: option<Value.t>=?,
    ~flexBasis: option<Value.t>=?,
    ~flexDirection: option<Value.t>=?,
    ~flexGrow: option<Value.t>=?,
    ~flexShrink: option<Value.t>=?,
    ~flexWrap: option<Value.t>=?,
    ~fontFamily: option<Value.t>=?,
    ~fontSize: option<Value.t>=?,
    ~fontStyle: option<Value.t>=?,
    ~fontWeight: option<Value.t>=?,
    ~gridArea: option<Value.t>=?,
    ~gridAutoColumns: option<Value.t>=?,
    ~gridAutoFlow: option<Value.t>=?,
    ~gridAutoRows: option<Value.t>=?,
    ~gridColumn: option<Value.t>=?,
    ~gridColumnGap: option<Value.t>=?,
    ~gridGap: option<Value.t>=?,
    ~gridRow: option<Value.t>=?,
    ~gridRowGap: option<Value.t>=?,
    ~gridTemplateAreas: option<Value.t>=?,
    ~gridTemplateColumns: option<Value.t>=?,
    ~gridTemplateRows: option<Value.t>=?,
    ~height: option<Value.t>=?,
    ~justifyContent: option<Value.t>=?,
    ~justifyItems: option<Value.t>=?,
    ~justifySelf: option<Value.t>=?,
    ~letterSpacing: option<Value.t>=?,
    ~lineHeight: option<Value.t>=?,
    ~m: option<Value.t>=?,
    ~margin: option<Value.t>=?,
    ~marginBottom: option<Value.t>=?,
    ~marginLeft: option<Value.t>=?,
    ~marginRight: option<Value.t>=?,
    ~marginTop: option<Value.t>=?,
    ~marginX: option<Value.t>=?,
    ~marginY: option<Value.t>=?,
    ~maxHeight: option<Value.t>=?,
    ~maxWidth: option<Value.t>=?,
    ~mb: option<Value.t>=?,
    ~minHeight: option<Value.t>=?,
    ~minWidth: option<Value.t>=?,
    ~ml: option<Value.t>=?,
    ~mr: option<Value.t>=?,
    ~mt: option<Value.t>=?,
    ~mx: option<Value.t>=?,
    ~my: option<Value.t>=?,
    ~order: option<Value.t>=?,
    ~overflow: option<Value.t>=?,
    ~p: option<Value.t>=?,
    ~padding: option<Value.t>=?,
    ~paddingBottom: option<Value.t>=?,
    ~paddingLeft: option<Value.t>=?,
    ~paddingRight: option<Value.t>=?,
    ~paddingTop: option<Value.t>=?,
    ~paddingX: option<Value.t>=?,
    ~paddingY: option<Value.t>=?,
    ~pb: option<Value.t>=?,
    ~pl: option<Value.t>=?,
    ~pr: option<Value.t>=?,
    ~pt: option<Value.t>=?,
    ~px: option<Value.t>=?,
    ~py: option<Value.t>=?,
    ~sizeHeight: option<Value.t>=?,
    ~sizeWidth: option<Value.t>=?,
    ~textAlign: option<Value.t>=?,
    ~textOverflow: option<Value.t>=?,
    ~visibility: option<Value.t>=?,
    ~whiteSpace: option<Value.t>=?,
    ~width: option<Value.t>=?,
    ~zIndex: option<int>=?,
    ~id: option<string>=?,
    ~key: option<string>=?,
    ~ref: option<ReactDOMRe.domRef>=?
  ) =>
  React.element =
  "Box";