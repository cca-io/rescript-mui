module Component: {
  type t
  let string: string => t
  let callback: (unit => React.element) => t
  let element: React.element => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let callback = (v: unit => React.element) => Any(v)
  let element = (v: React.element) => Any(v)
}

module PaletteColor: {
  type t = private string

  @inline("common.black")
  let common_black: t
  @inline("common.white")
  let common_white: t
  @inline("primary.light")
  let primary_light: t
  @inline("primary.main")
  let primary_main: t
  @inline("primary.dark")
  let primary_dark: t
  @inline("primary.contrastText")
  let primary_contrastText: t
  @inline("secondary.light")
  let secondary_light: t
  @inline("secondary.main")
  let secondary_main: t
  @inline("secondary.dark")
  let secondary_dark: t
  @inline("secondary.contrastText")
  let secondary_contrastText: t
  @inline("error.light")
  let error_light: t
  @inline("error.main")
  let error_main: t
  @inline("error.dark")
  let error_dark: t
  @inline("error.contrastText")
  let error_contrastText: t
  @inline("warning.light")
  let warning_light: t
  @inline("warning.main")
  let warning_main: t
  @inline("warning.dark")
  let warning_dark: t
  @inline("warning.contrastText")
  let warning_contrastText: t
  @inline("info.light")
  let info_light: t
  @inline("info.main")
  let info_main: t
  @inline("info.dark")
  let info_dark: t
  @inline("info.contrastText")
  let info_contrastText: t
  @inline("success.light")
  let success_light: t
  @inline("success.main")
  let success_main: t
  @inline("success.dark")
  let success_dark: t
  @inline("success.contrastText")
  let success_contrastText: t
  @inline("text.primary")
  let text_primary: t
  @inline("text.secondary")
  let text_secondary: t
  @inline("text.disabled")
  let text_disabled: t
  @inline("text.hint")
  let text_hint: t
  @inline("divider")
  let divider: t
  @inline("action.active")
  let action_active: t
  @inline("action.hover")
  let action_hover: t
  @inline("action.hoverOpacity")
  let action_hoverOpacity: t
  @inline("action.selected")
  let action_selected: t
  @inline("action.selectedOpacity")
  let action_selectedOpacity: t
  @inline("action.disabled")
  let action_disabled: t
  @inline("action.disabledOpacity")
  let action_disabledOpacity: t
  @inline("action.disabledBackground")
  let action_disabledBackground: t
  @inline("action.focus")
  let action_focus: t
  @inline("action.focusOpacity")
  let action_focusOpacity: t
  @inline("action.activatedOpacity")
  let action_activatedOpacity: t
  @inline("background.default")
  let background_default: t
  @inline("background.paper")
  let background_paper: t
} = {
  type t = string

  @inline
  let common_black = "common.black"
  @inline
  let common_white = "common.white"
  @inline
  let primary_light = "primary.light"
  @inline
  let primary_main = "primary.main"
  @inline
  let primary_dark = "primary.dark"
  @inline
  let primary_contrastText = "primary.contrastText"
  @inline
  let secondary_light = "secondary.light"
  @inline
  let secondary_main = "secondary.main"
  @inline
  let secondary_dark = "secondary.dark"
  @inline
  let secondary_contrastText = "secondary.contrastText"
  @inline
  let error_light = "error.light"
  @inline
  let error_main = "error.main"
  @inline
  let error_dark = "error.dark"
  @inline
  let error_contrastText = "error.contrastText"
  @inline
  let warning_light = "warning.light"
  @inline
  let warning_main = "warning.main"
  @inline
  let warning_dark = "warning.dark"
  @inline
  let warning_contrastText = "warning.contrastText"
  @inline
  let info_light = "info.light"
  @inline
  let info_main = "info.main"
  @inline
  let info_dark = "info.dark"
  @inline
  let info_contrastText = "info.contrastText"
  @inline
  let success_light = "success.light"
  @inline
  let success_main = "success.main"
  @inline
  let success_dark = "success.dark"
  @inline
  let success_contrastText = "success.contrastText"
  @inline
  let text_primary = "text.primary"
  @inline
  let text_secondary = "text.secondary"
  @inline
  let text_disabled = "text.disabled"
  @inline
  let text_hint = "text.hint"
  @inline
  let divider = "divider"
  @inline
  let action_active = "action.active"
  @inline
  let action_hover = "action.hover"
  @inline
  let action_hoverOpacity = "action.hoverOpacity"
  @inline
  let action_selected = "action.selected"
  @inline
  let action_selectedOpacity = "action.selectedOpacity"
  @inline
  let action_disabled = "action.disabled"
  @inline
  let action_disabledOpacity = "action.disabledOpacity"
  @inline
  let action_disabledBackground = "action.disabledBackground"
  @inline
  let action_focus = "action.focus"
  @inline
  let action_focusOpacity = "action.focusOpacity"
  @inline
  let action_activatedOpacity = "action.activatedOpacity"
  @inline
  let background_default = "background.default"
  @inline
  let background_paper = "background.paper"
}

module BreakpointObj = {
  @deriving(abstract)
  type t<'a> = {
    @optional
    xs: 'a,
    @optional
    sm: 'a,
    @optional
    md: 'a,
    @optional
    lg: 'a,
    @optional
    xl: 'a,
  }
  let make = t
}

module Value: {
  type t
  let string: string => t
  let int: int => t
  let float: float => t
  let paletteColor: PaletteColor.t => t
  let array: array<t> => t
  let breakpointObj: BreakpointObj.t<t> => t
} = {
  @unboxed
  type rec t = Any('a): t
  let string = (v: string) => Any(v)
  let int = (v: int) => Any(v)
  let float = (v: float) => Any(v)
  let paletteColor = (v: PaletteColor.t) => Any(v)
  let array = (v: array<t>) => Any(v)
  let breakpointObj = (v: BreakpointObj.t<t>) => Any(v)
}

@react.component @module("@material-ui/core")
external make: (
  ~component: option<Component.t>=?,
  ~className: option<string>=?,
  ~style: option<ReactDOM.Style.t>=?,
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
  ~ref: option<ReactDOM.domRef>=?,
) => React.element = "Box"
