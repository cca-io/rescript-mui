module Component = {
  type t

  external string: string => t = "%identity"
  external callback: (unit => React.element) => t = "%identity"
  external element: React.element => t = "%identity"
}

module PaletteColor = {
  type t = [
    | #"common.black"
    | #"common.white"
    | #"primary.light"
    | #"primary.main"
    | #"primary.dark"
    | #"primary.contrastText"
    | #"secondary.light"
    | #"secondary.main"
    | #"secondary.dark"
    | #"secondary.contrastText"
    | #"error.light"
    | #"error.main"
    | #"error.dark"
    | #"error.contrastText"
    | #"warning.light"
    | #"warning.main"
    | #"warning.dark"
    | #"warning.contrastText"
    | #"info.light"
    | #"info.main"
    | #"info.dark"
    | #"info.contrastText"
    | #"success.light"
    | #"success.main"
    | #"success.dark"
    | #"success.contrastText"
    | #"text.primary"
    | #"text.secondary"
    | #"text.disabled"
    | #"text.hint"
    | #divider
    | #"action.active"
    | #"action.hover"
    | #"action.hoverOpacity"
    | #"action.selected"
    | #"action.selectedOpacity"
    | #"action.disabled"
    | #"action.disabledOpacity"
    | #"action.disabledBackground"
    | #"action.focus"
    | #"action.focusOpacity"
    | #"action.activatedOpacity"
    | #"background.default"
    | #"background.paper"
  ]
}

module BreakpointObj = {
  type t<'a> = {
    "xs": option<'a>,
    "sm": option<'a>,
    "md": option<'a>,
    "lg": option<'a>,
    "xl": option<'a>,
  }
  @obj external make: (~xs: 'a=?, ~sm: 'a=?, ~md: 'a=?, ~lg: 'a=?, ~xl: 'a=?, unit) => t<'a> = ""
}

module Value = {
  type t

  external string: string => t = "%identity"
  external int: int => t = "%identity"
  external float: float => t = "%identity"
  external paletteColor: PaletteColor.t => t = "%identity"
  external array: array<t> => t = "%identity"
  external breakpointObj: BreakpointObj.t<t> => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~component: option<Component.t>=?,
  ~className: option<string>=?,
  ~style: option<ReactDOM.Style.t>=?,
  ~clone: option<bool>=?,
  ~children: option<React.element>=?,
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
