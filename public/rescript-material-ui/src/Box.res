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

@react.component @module("@material-ui/core")
external make: (
  ~component: Component.t=?,
  ~className: string=?,
  ~style: ReactDOM.Style.t=?,
  ~clone: bool=?,
  ~children: React.element=?,
  ~alignContent: Value.t=?,
  ~alignItems: Value.t=?,
  ~alignSelf: Value.t=?,
  ~bgcolor: Value.t=?,
  ~border: Value.t=?,
  ~borderBottom: Value.t=?,
  ~borderColor: Value.t=?,
  ~borderLeft: Value.t=?,
  ~borderRadius: Value.t=?,
  ~borderRight: Value.t=?,
  ~borderTop: Value.t=?,
  ~boxShadow: Value.t=?,
  ~boxSizing: Value.t=?,
  ~color: Value.t=?,
  ~display: Value.t=?,
  ~displayPrint: Value.t=?,
  ~flex: Value.t=?,
  ~flexBasis: Value.t=?,
  ~flexDirection: Value.t=?,
  ~flexGrow: Value.t=?,
  ~flexShrink: Value.t=?,
  ~flexWrap: Value.t=?,
  ~fontFamily: Value.t=?,
  ~fontSize: Value.t=?,
  ~fontStyle: Value.t=?,
  ~fontWeight: Value.t=?,
  ~gridArea: Value.t=?,
  ~gridAutoColumns: Value.t=?,
  ~gridAutoFlow: Value.t=?,
  ~gridAutoRows: Value.t=?,
  ~gridColumn: Value.t=?,
  ~gridColumnGap: Value.t=?,
  ~gridGap: Value.t=?,
  ~gridRow: Value.t=?,
  ~gridRowGap: Value.t=?,
  ~gridTemplateAreas: Value.t=?,
  ~gridTemplateColumns: Value.t=?,
  ~gridTemplateRows: Value.t=?,
  ~height: Value.t=?,
  ~justifyContent: Value.t=?,
  ~justifyItems: Value.t=?,
  ~justifySelf: Value.t=?,
  ~letterSpacing: Value.t=?,
  ~lineHeight: Value.t=?,
  ~m: Value.t=?,
  ~margin: Value.t=?,
  ~marginBottom: Value.t=?,
  ~marginLeft: Value.t=?,
  ~marginRight: Value.t=?,
  ~marginTop: Value.t=?,
  ~marginX: Value.t=?,
  ~marginY: Value.t=?,
  ~maxHeight: Value.t=?,
  ~maxWidth: Value.t=?,
  ~mb: Value.t=?,
  ~minHeight: Value.t=?,
  ~minWidth: Value.t=?,
  ~ml: Value.t=?,
  ~mr: Value.t=?,
  ~mt: Value.t=?,
  ~mx: Value.t=?,
  ~my: Value.t=?,
  ~order: Value.t=?,
  ~overflow: Value.t=?,
  ~p: Value.t=?,
  ~padding: Value.t=?,
  ~paddingBottom: Value.t=?,
  ~paddingLeft: Value.t=?,
  ~paddingRight: Value.t=?,
  ~paddingTop: Value.t=?,
  ~paddingX: Value.t=?,
  ~paddingY: Value.t=?,
  ~pb: Value.t=?,
  ~pl: Value.t=?,
  ~pr: Value.t=?,
  ~pt: Value.t=?,
  ~px: Value.t=?,
  ~py: Value.t=?,
  ~sizeHeight: Value.t=?,
  ~sizeWidth: Value.t=?,
  ~textAlign: Value.t=?,
  ~textOverflow: Value.t=?,
  ~visibility: Value.t=?,
  ~whiteSpace: Value.t=?,
  ~width: Value.t=?,
  ~zIndex: int=?,
  ~id: string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Box"
