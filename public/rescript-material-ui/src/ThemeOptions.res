module BreakpointValues = {
  type t = {
    "lg": option<float>,
    "md": option<float>,
    "sm": option<float>,
    "xl": option<float>,
    "xs": option<float>,
  }
  @obj
  external make: (~lg: float=?, ~md: float=?, ~sm: float=?, ~xl: float=?, ~xs: float=?, unit) => t =
    ""
}

module Breakpoints = {
  type t = {
    "between": option<Any.t>,
    "down": option<Any.t>,
    "keys": option<array<string>>,
    "only": option<Any.t>,
    "step": option<float>,
    "unit": option<string>,
    "up": option<Any.t>,
    "values": option<BreakpointValues.t>,
    "width": option<Any.t>,
  }
  @obj
  external make: (
    ~between: Any.t=?,
    ~down: Any.t=?,
    ~keys: array<string>=?,
    ~only: Any.t=?,
    ~step: float=?,
    ~unit: string=?,
    ~up: Any.t=?,
    ~values: BreakpointValues.t=?,
    ~width: Any.t=?,
    unit,
  ) => t = ""
}

module MixinsOptions = {
  type t = {"gutters": option<Any.t>, "toolbar": option<ReactDOM.Style.t>}
  @obj external make: (~gutters: Any.t=?, ~toolbar: ReactDOM.Style.t=?, unit) => t = ""
}

module AccordionClassKey = {
  type t = {
    "disabled": option<ReactDOM.Style.t>,
    "expanded": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "rounded": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~disabled: ReactDOM.Style.t=?,
    ~expanded: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~rounded: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module AccordionActionsClassKey = {
  type t = {"root": option<ReactDOM.Style.t>, "spacing": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, ~spacing: ReactDOM.Style.t=?, unit) => t = ""
}

module MuiAccordionDetails = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module AccordionSummaryClassKey = {
  type t = {
    "content": option<ReactDOM.Style.t>,
    "disabled": option<ReactDOM.Style.t>,
    "expandIcon": option<ReactDOM.Style.t>,
    "expanded": option<ReactDOM.Style.t>,
    "focusVisible": option<ReactDOM.Style.t>,
    "focused": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~content: ReactDOM.Style.t=?,
    ~disabled: ReactDOM.Style.t=?,
    ~expandIcon: ReactDOM.Style.t=?,
    ~expanded: ReactDOM.Style.t=?,
    ~focusVisible: ReactDOM.Style.t=?,
    ~focused: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module AppBarClassKey = {
  type t = {
    "colorDefault": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "positionAbsolute": option<ReactDOM.Style.t>,
    "positionFixed": option<ReactDOM.Style.t>,
    "positionRelative": option<ReactDOM.Style.t>,
    "positionStatic": option<ReactDOM.Style.t>,
    "positionSticky": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~colorDefault: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~positionAbsolute: ReactDOM.Style.t=?,
    ~positionFixed: ReactDOM.Style.t=?,
    ~positionRelative: ReactDOM.Style.t=?,
    ~positionStatic: ReactDOM.Style.t=?,
    ~positionSticky: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module AvatarClassKey = {
  type t = {
    "circle": option<ReactDOM.Style.t>,
    "circular": option<ReactDOM.Style.t>,
    "colorDefault": option<string>,
    "fallback": option<ReactDOM.Style.t>,
    "img": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "rounded": option<ReactDOM.Style.t>,
    "square": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~circle: ReactDOM.Style.t=?,
    ~circular: ReactDOM.Style.t=?,
    ~colorDefault: string=?,
    ~fallback: ReactDOM.Style.t=?,
    ~img: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~rounded: ReactDOM.Style.t=?,
    ~square: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module BackdropClassKey = {
  type t = {"invisible": option<ReactDOM.Style.t>, "root": option<ReactDOM.Style.t>}
  @obj external make: (~invisible: ReactDOM.Style.t=?, ~root: ReactDOM.Style.t=?, unit) => t = ""
}

module BadgeClassKey = {
  type t = {
    "anchorOriginBottomLeftRectangle": option<ReactDOM.Style.t>,
    "anchorOriginBottomLeftRectangular": option<ReactDOM.Style.t>,
    "anchorOriginBottomRightCircle": option<ReactDOM.Style.t>,
    "anchorOriginBottomRightCircular": option<ReactDOM.Style.t>,
    "anchorOriginBottomRightRectangle": option<ReactDOM.Style.t>,
    "anchorOriginBottomRightRectangular": option<ReactDOM.Style.t>,
    "anchorOriginTopLeftCircle": option<ReactDOM.Style.t>,
    "anchorOriginTopLeftCircular": option<ReactDOM.Style.t>,
    "anchorOriginTopLeftRectangle": option<ReactDOM.Style.t>,
    "anchorOriginTopLeftRectangular": option<ReactDOM.Style.t>,
    "anchorOriginTopRightCircle": option<ReactDOM.Style.t>,
    "anchorOriginTopRightCircular": option<ReactDOM.Style.t>,
    "anchorOriginTopRightRectangle": option<ReactDOM.Style.t>,
    "anchorOriginTopRightRectangular": option<ReactDOM.Style.t>,
    "badge": option<ReactDOM.Style.t>,
    "colorError": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "dot": option<ReactDOM.Style.t>,
    "invisible": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~anchorOriginBottomLeftRectangle: ReactDOM.Style.t=?,
    ~anchorOriginBottomLeftRectangular: ReactDOM.Style.t=?,
    ~anchorOriginBottomRightCircle: ReactDOM.Style.t=?,
    ~anchorOriginBottomRightCircular: ReactDOM.Style.t=?,
    ~anchorOriginBottomRightRectangle: ReactDOM.Style.t=?,
    ~anchorOriginBottomRightRectangular: ReactDOM.Style.t=?,
    ~anchorOriginTopLeftCircle: ReactDOM.Style.t=?,
    ~anchorOriginTopLeftCircular: ReactDOM.Style.t=?,
    ~anchorOriginTopLeftRectangle: ReactDOM.Style.t=?,
    ~anchorOriginTopLeftRectangular: ReactDOM.Style.t=?,
    ~anchorOriginTopRightCircle: ReactDOM.Style.t=?,
    ~anchorOriginTopRightCircular: ReactDOM.Style.t=?,
    ~anchorOriginTopRightRectangle: ReactDOM.Style.t=?,
    ~anchorOriginTopRightRectangular: ReactDOM.Style.t=?,
    ~badge: ReactDOM.Style.t=?,
    ~colorError: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~dot: ReactDOM.Style.t=?,
    ~invisible: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module MuiBottomNavigation = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module BottomNavigationActionClassKey = {
  type t = {
    "iconOnly": option<ReactDOM.Style.t>,
    "label": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "selected": option<ReactDOM.Style.t>,
    "wrapper": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~iconOnly: ReactDOM.Style.t=?,
    ~label: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~selected: ReactDOM.Style.t=?,
    ~wrapper: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module BreadcrumbsClassKey = {
  type t = {
    "li": option<ReactDOM.Style.t>,
    "ol": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "separator": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~li: ReactDOM.Style.t=?,
    ~ol: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~separator: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module ButtonClassKey = {
  type t = {
    "colorInherit": option<string>,
    "contained": option<ReactDOM.Style.t>,
    "containedPrimary": option<ReactDOM.Style.t>,
    "containedSecondary": option<ReactDOM.Style.t>,
    "containedSizeLarge": option<ReactDOM.Style.t>,
    "containedSizeSmall": option<ReactDOM.Style.t>,
    "disableElevation": option<ReactDOM.Style.t>,
    "disabled": option<ReactDOM.Style.t>,
    "endIcon": option<ReactDOM.Style.t>,
    "focusVisible": option<ReactDOM.Style.t>,
    "fullWidth": option<ReactDOM.Style.t>,
    "iconSizeLarge": option<ReactDOM.Style.t>,
    "iconSizeMedium": option<ReactDOM.Style.t>,
    "iconSizeSmall": option<ReactDOM.Style.t>,
    "label": option<ReactDOM.Style.t>,
    "outlined": option<ReactDOM.Style.t>,
    "outlinedPrimary": option<ReactDOM.Style.t>,
    "outlinedSecondary": option<ReactDOM.Style.t>,
    "outlinedSizeLarge": option<ReactDOM.Style.t>,
    "outlinedSizeSmall": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "sizeLarge": option<ReactDOM.Style.t>,
    "sizeSmall": option<ReactDOM.Style.t>,
    "startIcon": option<ReactDOM.Style.t>,
    "text": option<ReactDOM.Style.t>,
    "textPrimary": option<ReactDOM.Style.t>,
    "textSecondary": option<ReactDOM.Style.t>,
    "textSizeLarge": option<ReactDOM.Style.t>,
    "textSizeSmall": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~colorInherit: string=?,
    ~contained: ReactDOM.Style.t=?,
    ~containedPrimary: ReactDOM.Style.t=?,
    ~containedSecondary: ReactDOM.Style.t=?,
    ~containedSizeLarge: ReactDOM.Style.t=?,
    ~containedSizeSmall: ReactDOM.Style.t=?,
    ~disableElevation: ReactDOM.Style.t=?,
    ~disabled: ReactDOM.Style.t=?,
    ~endIcon: ReactDOM.Style.t=?,
    ~focusVisible: ReactDOM.Style.t=?,
    ~fullWidth: ReactDOM.Style.t=?,
    ~iconSizeLarge: ReactDOM.Style.t=?,
    ~iconSizeMedium: ReactDOM.Style.t=?,
    ~iconSizeSmall: ReactDOM.Style.t=?,
    ~label: ReactDOM.Style.t=?,
    ~outlined: ReactDOM.Style.t=?,
    ~outlinedPrimary: ReactDOM.Style.t=?,
    ~outlinedSecondary: ReactDOM.Style.t=?,
    ~outlinedSizeLarge: ReactDOM.Style.t=?,
    ~outlinedSizeSmall: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~sizeLarge: ReactDOM.Style.t=?,
    ~sizeSmall: ReactDOM.Style.t=?,
    ~startIcon: ReactDOM.Style.t=?,
    ~text: ReactDOM.Style.t=?,
    ~textPrimary: ReactDOM.Style.t=?,
    ~textSecondary: ReactDOM.Style.t=?,
    ~textSizeLarge: ReactDOM.Style.t=?,
    ~textSizeSmall: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module ButtonBaseClassKey = {
  type t = {
    "disabled": option<ReactDOM.Style.t>,
    "focusVisible": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~disabled: ReactDOM.Style.t=?,
    ~focusVisible: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module ButtonGroupClassKey = {
  type t = {
    "contained": option<ReactDOM.Style.t>,
    "disableElevation": option<ReactDOM.Style.t>,
    "disabled": option<ReactDOM.Style.t>,
    "fullWidth": option<ReactDOM.Style.t>,
    "grouped": option<ReactDOM.Style.t>,
    "groupedContained": option<ReactDOM.Style.t>,
    "groupedContainedHorizontal": option<ReactDOM.Style.t>,
    "groupedContainedPrimary": option<ReactDOM.Style.t>,
    "groupedContainedSecondary": option<ReactDOM.Style.t>,
    "groupedContainedVertical": option<ReactDOM.Style.t>,
    "groupedHorizontal": option<ReactDOM.Style.t>,
    "groupedOutlined": option<ReactDOM.Style.t>,
    "groupedOutlinedHorizontal": option<ReactDOM.Style.t>,
    "groupedOutlinedPrimary": option<ReactDOM.Style.t>,
    "groupedOutlinedSecondary": option<ReactDOM.Style.t>,
    "groupedOutlinedVertical": option<ReactDOM.Style.t>,
    "groupedText": option<ReactDOM.Style.t>,
    "groupedTextHorizontal": option<ReactDOM.Style.t>,
    "groupedTextPrimary": option<ReactDOM.Style.t>,
    "groupedTextSecondary": option<ReactDOM.Style.t>,
    "groupedTextVertical": option<ReactDOM.Style.t>,
    "groupedVertical": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "vertical": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~contained: ReactDOM.Style.t=?,
    ~disableElevation: ReactDOM.Style.t=?,
    ~disabled: ReactDOM.Style.t=?,
    ~fullWidth: ReactDOM.Style.t=?,
    ~grouped: ReactDOM.Style.t=?,
    ~groupedContained: ReactDOM.Style.t=?,
    ~groupedContainedHorizontal: ReactDOM.Style.t=?,
    ~groupedContainedPrimary: ReactDOM.Style.t=?,
    ~groupedContainedSecondary: ReactDOM.Style.t=?,
    ~groupedContainedVertical: ReactDOM.Style.t=?,
    ~groupedHorizontal: ReactDOM.Style.t=?,
    ~groupedOutlined: ReactDOM.Style.t=?,
    ~groupedOutlinedHorizontal: ReactDOM.Style.t=?,
    ~groupedOutlinedPrimary: ReactDOM.Style.t=?,
    ~groupedOutlinedSecondary: ReactDOM.Style.t=?,
    ~groupedOutlinedVertical: ReactDOM.Style.t=?,
    ~groupedText: ReactDOM.Style.t=?,
    ~groupedTextHorizontal: ReactDOM.Style.t=?,
    ~groupedTextPrimary: ReactDOM.Style.t=?,
    ~groupedTextSecondary: ReactDOM.Style.t=?,
    ~groupedTextVertical: ReactDOM.Style.t=?,
    ~groupedVertical: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~vertical: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module MuiCard = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module CardActionAreaClassKey = {
  type t = {
    "focusHighlight": option<ReactDOM.Style.t>,
    "focusVisible": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~focusHighlight: ReactDOM.Style.t=?,
    ~focusVisible: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module MuiCardContent = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module CardHeaderClassKey = {
  type t = {
    "action": option<ReactDOM.Style.t>,
    "avatar": option<ReactDOM.Style.t>,
    "content": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "subheader": option<ReactDOM.Style.t>,
    "title": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~action: ReactDOM.Style.t=?,
    ~avatar: ReactDOM.Style.t=?,
    ~content: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~subheader: ReactDOM.Style.t=?,
    ~title: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module CardMediaClassKey = {
  type t = {"media": option<ReactDOM.Style.t>, "root": option<ReactDOM.Style.t>}
  @obj external make: (~media: ReactDOM.Style.t=?, ~root: ReactDOM.Style.t=?, unit) => t = ""
}

module CheckboxClassKey = {
  type t = {
    "checked": option<ReactDOM.Style.t>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "disabled": option<ReactDOM.Style.t>,
    "indeterminate": option<ReactDOM.Style.t>,
    "input": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~checked: ReactDOM.Style.t=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~disabled: ReactDOM.Style.t=?,
    ~indeterminate: ReactDOM.Style.t=?,
    ~input: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module ChipClassKey = {
  type t = {
    "avatar": option<ReactDOM.Style.t>,
    "avatarColorPrimary": option<ReactDOM.Style.t>,
    "avatarColorSecondary": option<ReactDOM.Style.t>,
    "avatarSmall": option<ReactDOM.Style.t>,
    "clickable": option<ReactDOM.Style.t>,
    "clickableColorPrimary": option<ReactDOM.Style.t>,
    "clickableColorSecondary": option<ReactDOM.Style.t>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "deletable": option<ReactDOM.Style.t>,
    "deletableColorPrimary": option<ReactDOM.Style.t>,
    "deletableColorSecondary": option<ReactDOM.Style.t>,
    "deleteIcon": option<ReactDOM.Style.t>,
    "deleteIconColorPrimary": option<ReactDOM.Style.t>,
    "deleteIconColorSecondary": option<ReactDOM.Style.t>,
    "deleteIconOutlinedColorPrimary": option<ReactDOM.Style.t>,
    "deleteIconOutlinedColorSecondary": option<ReactDOM.Style.t>,
    "deleteIconSmall": option<ReactDOM.Style.t>,
    "disabled": option<ReactDOM.Style.t>,
    "icon": option<ReactDOM.Style.t>,
    "iconColorPrimary": option<ReactDOM.Style.t>,
    "iconColorSecondary": option<ReactDOM.Style.t>,
    "iconSmall": option<ReactDOM.Style.t>,
    "label": option<ReactDOM.Style.t>,
    "labelSmall": option<ReactDOM.Style.t>,
    "outlined": option<ReactDOM.Style.t>,
    "outlinedPrimary": option<ReactDOM.Style.t>,
    "outlinedSecondary": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "sizeSmall": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~avatar: ReactDOM.Style.t=?,
    ~avatarColorPrimary: ReactDOM.Style.t=?,
    ~avatarColorSecondary: ReactDOM.Style.t=?,
    ~avatarSmall: ReactDOM.Style.t=?,
    ~clickable: ReactDOM.Style.t=?,
    ~clickableColorPrimary: ReactDOM.Style.t=?,
    ~clickableColorSecondary: ReactDOM.Style.t=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~deletable: ReactDOM.Style.t=?,
    ~deletableColorPrimary: ReactDOM.Style.t=?,
    ~deletableColorSecondary: ReactDOM.Style.t=?,
    ~deleteIcon: ReactDOM.Style.t=?,
    ~deleteIconColorPrimary: ReactDOM.Style.t=?,
    ~deleteIconColorSecondary: ReactDOM.Style.t=?,
    ~deleteIconOutlinedColorPrimary: ReactDOM.Style.t=?,
    ~deleteIconOutlinedColorSecondary: ReactDOM.Style.t=?,
    ~deleteIconSmall: ReactDOM.Style.t=?,
    ~disabled: ReactDOM.Style.t=?,
    ~icon: ReactDOM.Style.t=?,
    ~iconColorPrimary: ReactDOM.Style.t=?,
    ~iconColorSecondary: ReactDOM.Style.t=?,
    ~iconSmall: ReactDOM.Style.t=?,
    ~label: ReactDOM.Style.t=?,
    ~labelSmall: ReactDOM.Style.t=?,
    ~outlined: ReactDOM.Style.t=?,
    ~outlinedPrimary: ReactDOM.Style.t=?,
    ~outlinedSecondary: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~sizeSmall: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module CircularProgressClassKey = {
  type t = {
    "circle": option<ReactDOM.Style.t>,
    "circleDeterminate": option<ReactDOM.Style.t>,
    "circleDisableShrink": option<ReactDOM.Style.t>,
    "circleIndeterminate": option<ReactDOM.Style.t>,
    "circleStatic": option<ReactDOM.Style.t>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "determinate": option<ReactDOM.Style.t>,
    "indeterminate": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "static": option<ReactDOM.Style.t>,
    "svg": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~circle: ReactDOM.Style.t=?,
    ~circleDeterminate: ReactDOM.Style.t=?,
    ~circleDisableShrink: ReactDOM.Style.t=?,
    ~circleIndeterminate: ReactDOM.Style.t=?,
    ~circleStatic: ReactDOM.Style.t=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~determinate: ReactDOM.Style.t=?,
    ~indeterminate: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~static: ReactDOM.Style.t=?,
    ~svg: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module CollapseClassKey = {
  type t = {
    "entered": option<ReactDOM.Style.t>,
    "hidden": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "wrapper": option<ReactDOM.Style.t>,
    "wrapperInner": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~entered: ReactDOM.Style.t=?,
    ~hidden: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~wrapper: ReactDOM.Style.t=?,
    ~wrapperInner: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module ContainerClassKey = {
  type t = {
    "disableGutters": option<ReactDOM.Style.t>,
    "fixed": option<ReactDOM.Style.t>,
    "maxWidthLg": option<ReactDOM.Style.t>,
    "maxWidthMd": option<ReactDOM.Style.t>,
    "maxWidthSm": option<ReactDOM.Style.t>,
    "maxWidthXl": option<ReactDOM.Style.t>,
    "maxWidthXs": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~disableGutters: ReactDOM.Style.t=?,
    ~fixed: ReactDOM.Style.t=?,
    ~maxWidthLg: ReactDOM.Style.t=?,
    ~maxWidthMd: ReactDOM.Style.t=?,
    ~maxWidthSm: ReactDOM.Style.t=?,
    ~maxWidthXl: ReactDOM.Style.t=?,
    ~maxWidthXs: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module Global = {
  type t = {"@font-face": option<Any.t>}
  @obj external make: (~\"@font-face": Any.t=?, unit) => t = ""
}

module MuiCssBaseline = {
  type t = {"@global": option<Global.t>}
  @obj external make: (~\"@global": Global.t=?, unit) => t = ""
}

module DialogClassKey = {
  type t = {
    "container": option<ReactDOM.Style.t>,
    "paper": option<ReactDOM.Style.t>,
    "paperFullScreen": option<ReactDOM.Style.t>,
    "paperFullWidth": option<ReactDOM.Style.t>,
    "paperScrollBody": option<ReactDOM.Style.t>,
    "paperScrollPaper": option<ReactDOM.Style.t>,
    "paperWidthFalse": option<ReactDOM.Style.t>,
    "paperWidthLg": option<ReactDOM.Style.t>,
    "paperWidthMd": option<ReactDOM.Style.t>,
    "paperWidthSm": option<ReactDOM.Style.t>,
    "paperWidthXl": option<ReactDOM.Style.t>,
    "paperWidthXs": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "scrollBody": option<ReactDOM.Style.t>,
    "scrollPaper": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~container: ReactDOM.Style.t=?,
    ~paper: ReactDOM.Style.t=?,
    ~paperFullScreen: ReactDOM.Style.t=?,
    ~paperFullWidth: ReactDOM.Style.t=?,
    ~paperScrollBody: ReactDOM.Style.t=?,
    ~paperScrollPaper: ReactDOM.Style.t=?,
    ~paperWidthFalse: ReactDOM.Style.t=?,
    ~paperWidthLg: ReactDOM.Style.t=?,
    ~paperWidthMd: ReactDOM.Style.t=?,
    ~paperWidthSm: ReactDOM.Style.t=?,
    ~paperWidthXl: ReactDOM.Style.t=?,
    ~paperWidthXs: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~scrollBody: ReactDOM.Style.t=?,
    ~scrollPaper: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module DialogContentClassKey = {
  type t = {"dividers": option<ReactDOM.Style.t>, "root": option<ReactDOM.Style.t>}
  @obj external make: (~dividers: ReactDOM.Style.t=?, ~root: ReactDOM.Style.t=?, unit) => t = ""
}

module MuiDialogContentText = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module MuiDialogTitle = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module DividerClassKey = {
  type t = {
    "absolute": option<ReactDOM.Style.t>,
    "inset": option<ReactDOM.Style.t>,
    "light": option<ReactDOM.Style.t>,
    "middle": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "vertical": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~absolute: ReactDOM.Style.t=?,
    ~inset: ReactDOM.Style.t=?,
    ~light: ReactDOM.Style.t=?,
    ~middle: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~vertical: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module DrawerClassKey = {
  type t = {
    "docked": option<ReactDOM.Style.t>,
    "modal": option<ReactDOM.Style.t>,
    "paper": option<ReactDOM.Style.t>,
    "paperAnchorBottom": option<ReactDOM.Style.t>,
    "paperAnchorDockedBottom": option<ReactDOM.Style.t>,
    "paperAnchorDockedLeft": option<ReactDOM.Style.t>,
    "paperAnchorDockedRight": option<ReactDOM.Style.t>,
    "paperAnchorDockedTop": option<ReactDOM.Style.t>,
    "paperAnchorLeft": option<ReactDOM.Style.t>,
    "paperAnchorRight": option<ReactDOM.Style.t>,
    "paperAnchorTop": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~docked: ReactDOM.Style.t=?,
    ~modal: ReactDOM.Style.t=?,
    ~paper: ReactDOM.Style.t=?,
    ~paperAnchorBottom: ReactDOM.Style.t=?,
    ~paperAnchorDockedBottom: ReactDOM.Style.t=?,
    ~paperAnchorDockedLeft: ReactDOM.Style.t=?,
    ~paperAnchorDockedRight: ReactDOM.Style.t=?,
    ~paperAnchorDockedTop: ReactDOM.Style.t=?,
    ~paperAnchorLeft: ReactDOM.Style.t=?,
    ~paperAnchorRight: ReactDOM.Style.t=?,
    ~paperAnchorTop: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module MuiExpansionPanelDetails = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module ExpansionPanelSummaryClassKey = {
  type t = {
    "content": option<ReactDOM.Style.t>,
    "disabled": option<ReactDOM.Style.t>,
    "expandIcon": option<ReactDOM.Style.t>,
    "expanded": option<ReactDOM.Style.t>,
    "focused": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~content: ReactDOM.Style.t=?,
    ~disabled: ReactDOM.Style.t=?,
    ~expandIcon: ReactDOM.Style.t=?,
    ~expanded: ReactDOM.Style.t=?,
    ~focused: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module FabClassKey = {
  type t = {
    "colorInherit": option<string>,
    "disabled": option<ReactDOM.Style.t>,
    "extended": option<ReactDOM.Style.t>,
    "focusVisible": option<ReactDOM.Style.t>,
    "label": option<ReactDOM.Style.t>,
    "primary": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "secondary": option<ReactDOM.Style.t>,
    "sizeMedium": option<ReactDOM.Style.t>,
    "sizeSmall": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~colorInherit: string=?,
    ~disabled: ReactDOM.Style.t=?,
    ~extended: ReactDOM.Style.t=?,
    ~focusVisible: ReactDOM.Style.t=?,
    ~label: ReactDOM.Style.t=?,
    ~primary: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~secondary: ReactDOM.Style.t=?,
    ~sizeMedium: ReactDOM.Style.t=?,
    ~sizeSmall: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module FilledInputClassKey = {
  type t = {
    "adornedEnd": option<ReactDOM.Style.t>,
    "adornedStart": option<ReactDOM.Style.t>,
    "colorSecondary": option<string>,
    "disabled": option<ReactDOM.Style.t>,
    "error": option<ReactDOM.Style.t>,
    "focused": option<ReactDOM.Style.t>,
    "formControl": option<ReactDOM.Style.t>,
    "fullWidth": option<ReactDOM.Style.t>,
    "input": option<ReactDOM.Style.t>,
    "inputAdornedEnd": option<ReactDOM.Style.t>,
    "inputAdornedStart": option<ReactDOM.Style.t>,
    "inputHiddenLabel": option<ReactDOM.Style.t>,
    "inputMarginDense": option<ReactDOM.Style.t>,
    "inputMultiline": option<ReactDOM.Style.t>,
    "inputTypeSearch": option<ReactDOM.Style.t>,
    "marginDense": option<ReactDOM.Style.t>,
    "multiline": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "underline": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~adornedEnd: ReactDOM.Style.t=?,
    ~adornedStart: ReactDOM.Style.t=?,
    ~colorSecondary: string=?,
    ~disabled: ReactDOM.Style.t=?,
    ~error: ReactDOM.Style.t=?,
    ~focused: ReactDOM.Style.t=?,
    ~formControl: ReactDOM.Style.t=?,
    ~fullWidth: ReactDOM.Style.t=?,
    ~input: ReactDOM.Style.t=?,
    ~inputAdornedEnd: ReactDOM.Style.t=?,
    ~inputAdornedStart: ReactDOM.Style.t=?,
    ~inputHiddenLabel: ReactDOM.Style.t=?,
    ~inputMarginDense: ReactDOM.Style.t=?,
    ~inputMultiline: ReactDOM.Style.t=?,
    ~inputTypeSearch: ReactDOM.Style.t=?,
    ~marginDense: ReactDOM.Style.t=?,
    ~multiline: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~underline: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module FormControlClassKey = {
  type t = {
    "fullWidth": option<ReactDOM.Style.t>,
    "marginDense": option<ReactDOM.Style.t>,
    "marginNormal": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~fullWidth: ReactDOM.Style.t=?,
    ~marginDense: ReactDOM.Style.t=?,
    ~marginNormal: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module FormControlLabelClassKey = {
  type t = {
    "disabled": option<ReactDOM.Style.t>,
    "label": option<ReactDOM.Style.t>,
    "labelPlacementBottom": option<ReactDOM.Style.t>,
    "labelPlacementStart": option<ReactDOM.Style.t>,
    "labelPlacementTop": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~disabled: ReactDOM.Style.t=?,
    ~label: ReactDOM.Style.t=?,
    ~labelPlacementBottom: ReactDOM.Style.t=?,
    ~labelPlacementStart: ReactDOM.Style.t=?,
    ~labelPlacementTop: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module FormGroupClassKey = {
  type t = {"root": option<ReactDOM.Style.t>, "row": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, ~row: ReactDOM.Style.t=?, unit) => t = ""
}

module FormHelperTextClassKey = {
  type t = {
    "contained": option<ReactDOM.Style.t>,
    "disabled": option<ReactDOM.Style.t>,
    "error": option<ReactDOM.Style.t>,
    "filled": option<ReactDOM.Style.t>,
    "focused": option<ReactDOM.Style.t>,
    "marginDense": option<ReactDOM.Style.t>,
    "required": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~contained: ReactDOM.Style.t=?,
    ~disabled: ReactDOM.Style.t=?,
    ~error: ReactDOM.Style.t=?,
    ~filled: ReactDOM.Style.t=?,
    ~focused: ReactDOM.Style.t=?,
    ~marginDense: ReactDOM.Style.t=?,
    ~required: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module FormLabelClassKey = {
  type t = {
    "asterisk": option<ReactDOM.Style.t>,
    "colorSecondary": option<string>,
    "disabled": option<ReactDOM.Style.t>,
    "error": option<ReactDOM.Style.t>,
    "filled": option<ReactDOM.Style.t>,
    "focused": option<ReactDOM.Style.t>,
    "required": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~asterisk: ReactDOM.Style.t=?,
    ~colorSecondary: string=?,
    ~disabled: ReactDOM.Style.t=?,
    ~error: ReactDOM.Style.t=?,
    ~filled: ReactDOM.Style.t=?,
    ~focused: ReactDOM.Style.t=?,
    ~required: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module GridClassKey = {
  type t = {
    "align-content-xs-center": option<ReactDOM.Style.t>,
    "align-content-xs-flex-end": option<ReactDOM.Style.t>,
    "align-content-xs-flex-start": option<ReactDOM.Style.t>,
    "align-content-xs-space-around": option<ReactDOM.Style.t>,
    "align-content-xs-space-between": option<ReactDOM.Style.t>,
    "align-items-xs-baseline": option<ReactDOM.Style.t>,
    "align-items-xs-center": option<ReactDOM.Style.t>,
    "align-items-xs-flex-end": option<ReactDOM.Style.t>,
    "align-items-xs-flex-start": option<ReactDOM.Style.t>,
    "container": option<ReactDOM.Style.t>,
    "direction-xs-column": option<ReactDOM.Style.t>,
    "direction-xs-column-reverse": option<ReactDOM.Style.t>,
    "direction-xs-row-reverse": option<ReactDOM.Style.t>,
    "grid-xs-1": option<ReactDOM.Style.t>,
    "grid-xs-10": option<ReactDOM.Style.t>,
    "grid-xs-11": option<ReactDOM.Style.t>,
    "grid-xs-12": option<ReactDOM.Style.t>,
    "grid-xs-2": option<ReactDOM.Style.t>,
    "grid-xs-3": option<ReactDOM.Style.t>,
    "grid-xs-4": option<ReactDOM.Style.t>,
    "grid-xs-5": option<ReactDOM.Style.t>,
    "grid-xs-6": option<ReactDOM.Style.t>,
    "grid-xs-7": option<ReactDOM.Style.t>,
    "grid-xs-8": option<ReactDOM.Style.t>,
    "grid-xs-9": option<ReactDOM.Style.t>,
    "grid-xs-auto": option<ReactDOM.Style.t>,
    "grid-xs-true": option<ReactDOM.Style.t>,
    "item": option<ReactDOM.Style.t>,
    "justify-content-xs-center": option<ReactDOM.Style.t>,
    "justify-content-xs-flex-end": option<ReactDOM.Style.t>,
    "justify-content-xs-space-around": option<ReactDOM.Style.t>,
    "justify-content-xs-space-between": option<ReactDOM.Style.t>,
    "justify-content-xs-space-evenly": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "spacing-xs-1": option<ReactDOM.Style.t>,
    "spacing-xs-10": option<ReactDOM.Style.t>,
    "spacing-xs-2": option<ReactDOM.Style.t>,
    "spacing-xs-3": option<ReactDOM.Style.t>,
    "spacing-xs-4": option<ReactDOM.Style.t>,
    "spacing-xs-5": option<ReactDOM.Style.t>,
    "spacing-xs-6": option<ReactDOM.Style.t>,
    "spacing-xs-7": option<ReactDOM.Style.t>,
    "spacing-xs-8": option<ReactDOM.Style.t>,
    "spacing-xs-9": option<ReactDOM.Style.t>,
    "wrap-xs-nowrap": option<ReactDOM.Style.t>,
    "wrap-xs-wrap-reverse": option<ReactDOM.Style.t>,
    "zeroMinWidth": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~\"align-content-xs-center": ReactDOM.Style.t=?,
    ~\"align-content-xs-flex-end": ReactDOM.Style.t=?,
    ~\"align-content-xs-flex-start": ReactDOM.Style.t=?,
    ~\"align-content-xs-space-around": ReactDOM.Style.t=?,
    ~\"align-content-xs-space-between": ReactDOM.Style.t=?,
    ~\"align-items-xs-baseline": ReactDOM.Style.t=?,
    ~\"align-items-xs-center": ReactDOM.Style.t=?,
    ~\"align-items-xs-flex-end": ReactDOM.Style.t=?,
    ~\"align-items-xs-flex-start": ReactDOM.Style.t=?,
    ~container: ReactDOM.Style.t=?,
    ~\"direction-xs-column": ReactDOM.Style.t=?,
    ~\"direction-xs-column-reverse": ReactDOM.Style.t=?,
    ~\"direction-xs-row-reverse": ReactDOM.Style.t=?,
    ~\"grid-xs-1": ReactDOM.Style.t=?,
    ~\"grid-xs-10": ReactDOM.Style.t=?,
    ~\"grid-xs-11": ReactDOM.Style.t=?,
    ~\"grid-xs-12": ReactDOM.Style.t=?,
    ~\"grid-xs-2": ReactDOM.Style.t=?,
    ~\"grid-xs-3": ReactDOM.Style.t=?,
    ~\"grid-xs-4": ReactDOM.Style.t=?,
    ~\"grid-xs-5": ReactDOM.Style.t=?,
    ~\"grid-xs-6": ReactDOM.Style.t=?,
    ~\"grid-xs-7": ReactDOM.Style.t=?,
    ~\"grid-xs-8": ReactDOM.Style.t=?,
    ~\"grid-xs-9": ReactDOM.Style.t=?,
    ~\"grid-xs-auto": ReactDOM.Style.t=?,
    ~\"grid-xs-true": ReactDOM.Style.t=?,
    ~item: ReactDOM.Style.t=?,
    ~\"justify-content-xs-center": ReactDOM.Style.t=?,
    ~\"justify-content-xs-flex-end": ReactDOM.Style.t=?,
    ~\"justify-content-xs-space-around": ReactDOM.Style.t=?,
    ~\"justify-content-xs-space-between": ReactDOM.Style.t=?,
    ~\"justify-content-xs-space-evenly": ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~\"spacing-xs-1": ReactDOM.Style.t=?,
    ~\"spacing-xs-10": ReactDOM.Style.t=?,
    ~\"spacing-xs-2": ReactDOM.Style.t=?,
    ~\"spacing-xs-3": ReactDOM.Style.t=?,
    ~\"spacing-xs-4": ReactDOM.Style.t=?,
    ~\"spacing-xs-5": ReactDOM.Style.t=?,
    ~\"spacing-xs-6": ReactDOM.Style.t=?,
    ~\"spacing-xs-7": ReactDOM.Style.t=?,
    ~\"spacing-xs-8": ReactDOM.Style.t=?,
    ~\"spacing-xs-9": ReactDOM.Style.t=?,
    ~\"wrap-xs-nowrap": ReactDOM.Style.t=?,
    ~\"wrap-xs-wrap-reverse": ReactDOM.Style.t=?,
    ~zeroMinWidth: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module SvgIconClassKey = {
  type t = {
    "colorAction": option<string>,
    "colorDisabled": option<string>,
    "colorError": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "fontSizeInherit": option<float>,
    "fontSizeLarge": option<float>,
    "fontSizeSmall": option<float>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~colorAction: string=?,
    ~colorDisabled: string=?,
    ~colorError: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~fontSizeInherit: float=?,
    ~fontSizeLarge: float=?,
    ~fontSizeSmall: float=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module IconButtonClassKey = {
  type t = {
    "colorInherit": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "disabled": option<ReactDOM.Style.t>,
    "edgeEnd": option<ReactDOM.Style.t>,
    "edgeStart": option<ReactDOM.Style.t>,
    "label": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "sizeSmall": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~colorInherit: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~disabled: ReactDOM.Style.t=?,
    ~edgeEnd: ReactDOM.Style.t=?,
    ~edgeStart: ReactDOM.Style.t=?,
    ~label: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~sizeSmall: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module MuiImageList = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module ImageListItemClassKey = {
  type t = {
    "imgFullHeight": option<ReactDOM.Style.t>,
    "imgFullWidth": option<ReactDOM.Style.t>,
    "item": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~imgFullHeight: ReactDOM.Style.t=?,
    ~imgFullWidth: ReactDOM.Style.t=?,
    ~item: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module ImageListItemBarClassKey = {
  type t = {
    "actionIcon": option<ReactDOM.Style.t>,
    "actionIconActionPosLeft": option<ReactDOM.Style.t>,
    "positionBottom": option<ReactDOM.Style.t>,
    "positionTop": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "rootSubtitle": option<ReactDOM.Style.t>,
    "subtitle": option<ReactDOM.Style.t>,
    "title": option<ReactDOM.Style.t>,
    "titleWrap": option<ReactDOM.Style.t>,
    "titleWrapActionPosLeft": option<ReactDOM.Style.t>,
    "titleWrapActionPosRight": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~actionIcon: ReactDOM.Style.t=?,
    ~actionIconActionPosLeft: ReactDOM.Style.t=?,
    ~positionBottom: ReactDOM.Style.t=?,
    ~positionTop: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~rootSubtitle: ReactDOM.Style.t=?,
    ~subtitle: ReactDOM.Style.t=?,
    ~title: ReactDOM.Style.t=?,
    ~titleWrap: ReactDOM.Style.t=?,
    ~titleWrapActionPosLeft: ReactDOM.Style.t=?,
    ~titleWrapActionPosRight: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module InputClassKey = {
  type t = {
    "colorSecondary": option<string>,
    "disabled": option<ReactDOM.Style.t>,
    "error": option<ReactDOM.Style.t>,
    "focused": option<ReactDOM.Style.t>,
    "formControl": option<ReactDOM.Style.t>,
    "fullWidth": option<ReactDOM.Style.t>,
    "input": option<ReactDOM.Style.t>,
    "inputMarginDense": option<ReactDOM.Style.t>,
    "inputMultiline": option<ReactDOM.Style.t>,
    "inputTypeSearch": option<ReactDOM.Style.t>,
    "marginDense": option<ReactDOM.Style.t>,
    "multiline": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "underline": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~colorSecondary: string=?,
    ~disabled: ReactDOM.Style.t=?,
    ~error: ReactDOM.Style.t=?,
    ~focused: ReactDOM.Style.t=?,
    ~formControl: ReactDOM.Style.t=?,
    ~fullWidth: ReactDOM.Style.t=?,
    ~input: ReactDOM.Style.t=?,
    ~inputMarginDense: ReactDOM.Style.t=?,
    ~inputMultiline: ReactDOM.Style.t=?,
    ~inputTypeSearch: ReactDOM.Style.t=?,
    ~marginDense: ReactDOM.Style.t=?,
    ~multiline: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~underline: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module InputAdornmentClassKey = {
  type t = {
    "disablePointerEvents": option<ReactDOM.Style.t>,
    "filled": option<ReactDOM.Style.t>,
    "hiddenLabel": option<ReactDOM.Style.t>,
    "marginDense": option<ReactDOM.Style.t>,
    "positionEnd": option<ReactDOM.Style.t>,
    "positionStart": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~disablePointerEvents: ReactDOM.Style.t=?,
    ~filled: ReactDOM.Style.t=?,
    ~hiddenLabel: ReactDOM.Style.t=?,
    ~marginDense: ReactDOM.Style.t=?,
    ~positionEnd: ReactDOM.Style.t=?,
    ~positionStart: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module InputBaseClassKey = {
  type t = {
    "adornedEnd": option<ReactDOM.Style.t>,
    "adornedStart": option<ReactDOM.Style.t>,
    "colorSecondary": option<string>,
    "disabled": option<ReactDOM.Style.t>,
    "error": option<ReactDOM.Style.t>,
    "focused": option<ReactDOM.Style.t>,
    "formControl": option<ReactDOM.Style.t>,
    "fullWidth": option<ReactDOM.Style.t>,
    "input": option<ReactDOM.Style.t>,
    "inputAdornedEnd": option<ReactDOM.Style.t>,
    "inputAdornedStart": option<ReactDOM.Style.t>,
    "inputHiddenLabel": option<ReactDOM.Style.t>,
    "inputMarginDense": option<ReactDOM.Style.t>,
    "inputMultiline": option<ReactDOM.Style.t>,
    "inputTypeSearch": option<ReactDOM.Style.t>,
    "marginDense": option<ReactDOM.Style.t>,
    "multiline": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~adornedEnd: ReactDOM.Style.t=?,
    ~adornedStart: ReactDOM.Style.t=?,
    ~colorSecondary: string=?,
    ~disabled: ReactDOM.Style.t=?,
    ~error: ReactDOM.Style.t=?,
    ~focused: ReactDOM.Style.t=?,
    ~formControl: ReactDOM.Style.t=?,
    ~fullWidth: ReactDOM.Style.t=?,
    ~input: ReactDOM.Style.t=?,
    ~inputAdornedEnd: ReactDOM.Style.t=?,
    ~inputAdornedStart: ReactDOM.Style.t=?,
    ~inputHiddenLabel: ReactDOM.Style.t=?,
    ~inputMarginDense: ReactDOM.Style.t=?,
    ~inputMultiline: ReactDOM.Style.t=?,
    ~inputTypeSearch: ReactDOM.Style.t=?,
    ~marginDense: ReactDOM.Style.t=?,
    ~multiline: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module InputLabelClassKey = {
  type t = {
    "animated": option<ReactDOM.Style.t>,
    "asterisk": option<ReactDOM.Style.t>,
    "disabled": option<ReactDOM.Style.t>,
    "error": option<ReactDOM.Style.t>,
    "filled": option<ReactDOM.Style.t>,
    "focused": option<ReactDOM.Style.t>,
    "formControl": option<ReactDOM.Style.t>,
    "marginDense": option<ReactDOM.Style.t>,
    "outlined": option<ReactDOM.Style.t>,
    "required": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "shrink": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~animated: ReactDOM.Style.t=?,
    ~asterisk: ReactDOM.Style.t=?,
    ~disabled: ReactDOM.Style.t=?,
    ~error: ReactDOM.Style.t=?,
    ~filled: ReactDOM.Style.t=?,
    ~focused: ReactDOM.Style.t=?,
    ~formControl: ReactDOM.Style.t=?,
    ~marginDense: ReactDOM.Style.t=?,
    ~outlined: ReactDOM.Style.t=?,
    ~required: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~shrink: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module LinearProgressClassKey = {
  type t = {
    "bar": option<ReactDOM.Style.t>,
    "bar1Buffer": option<ReactDOM.Style.t>,
    "bar1Determinate": option<ReactDOM.Style.t>,
    "bar1Indeterminate": option<ReactDOM.Style.t>,
    "bar2Buffer": option<ReactDOM.Style.t>,
    "bar2Indeterminate": option<ReactDOM.Style.t>,
    "barColorPrimary": option<ReactDOM.Style.t>,
    "barColorSecondary": option<ReactDOM.Style.t>,
    "buffer": option<ReactDOM.Style.t>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "dashed": option<ReactDOM.Style.t>,
    "dashedColorPrimary": option<ReactDOM.Style.t>,
    "dashedColorSecondary": option<ReactDOM.Style.t>,
    "determinate": option<ReactDOM.Style.t>,
    "indeterminate": option<ReactDOM.Style.t>,
    "query": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~bar: ReactDOM.Style.t=?,
    ~bar1Buffer: ReactDOM.Style.t=?,
    ~bar1Determinate: ReactDOM.Style.t=?,
    ~bar1Indeterminate: ReactDOM.Style.t=?,
    ~bar2Buffer: ReactDOM.Style.t=?,
    ~bar2Indeterminate: ReactDOM.Style.t=?,
    ~barColorPrimary: ReactDOM.Style.t=?,
    ~barColorSecondary: ReactDOM.Style.t=?,
    ~buffer: ReactDOM.Style.t=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~dashed: ReactDOM.Style.t=?,
    ~dashedColorPrimary: ReactDOM.Style.t=?,
    ~dashedColorSecondary: ReactDOM.Style.t=?,
    ~determinate: ReactDOM.Style.t=?,
    ~indeterminate: ReactDOM.Style.t=?,
    ~query: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module LinkClassKey = {
  type t = {
    "button": option<ReactDOM.Style.t>,
    "focusVisible": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "underlineAlways": option<ReactDOM.Style.t>,
    "underlineHover": option<ReactDOM.Style.t>,
    "underlineNone": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~button: ReactDOM.Style.t=?,
    ~focusVisible: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~underlineAlways: ReactDOM.Style.t=?,
    ~underlineHover: ReactDOM.Style.t=?,
    ~underlineNone: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module ListClassKey = {
  type t = {
    "dense": option<ReactDOM.Style.t>,
    "padding": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "subheader": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~dense: ReactDOM.Style.t=?,
    ~padding: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~subheader: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module ListItemClassKey = {
  type t = {
    "button": option<ReactDOM.Style.t>,
    "container": option<ReactDOM.Style.t>,
    "default": option<ReactDOM.Style.t>,
    "dense": option<ReactDOM.Style.t>,
    "disabled": option<ReactDOM.Style.t>,
    "divider": option<ReactDOM.Style.t>,
    "focusVisible": option<ReactDOM.Style.t>,
    "gutters": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "secondaryAction": option<ReactDOM.Style.t>,
    "selected": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~button: ReactDOM.Style.t=?,
    ~container: ReactDOM.Style.t=?,
    ~default: ReactDOM.Style.t=?,
    ~dense: ReactDOM.Style.t=?,
    ~disabled: ReactDOM.Style.t=?,
    ~divider: ReactDOM.Style.t=?,
    ~focusVisible: ReactDOM.Style.t=?,
    ~gutters: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~secondaryAction: ReactDOM.Style.t=?,
    ~selected: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module ListItemAvatarClassKey = {
  type t = {"icon": option<ReactDOM.Style.t>, "root": option<ReactDOM.Style.t>}
  @obj external make: (~icon: ReactDOM.Style.t=?, ~root: ReactDOM.Style.t=?, unit) => t = ""
}

module ListItemIconClassKey = {
  type t = {"alignItemsFlexStart": option<ReactDOM.Style.t>, "root": option<ReactDOM.Style.t>}
  @obj
  external make: (~alignItemsFlexStart: ReactDOM.Style.t=?, ~root: ReactDOM.Style.t=?, unit) => t =
    ""
}

module MuiListItemSecondaryAction = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module ListItemTextClassKey = {
  type t = {
    "dense": option<ReactDOM.Style.t>,
    "inset": option<ReactDOM.Style.t>,
    "multiline": option<ReactDOM.Style.t>,
    "primary": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "secondary": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~dense: ReactDOM.Style.t=?,
    ~inset: ReactDOM.Style.t=?,
    ~multiline: ReactDOM.Style.t=?,
    ~primary: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~secondary: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module ListSubheaderClassKey = {
  type t = {
    "colorInherit": option<string>,
    "colorPrimary": option<string>,
    "gutters": option<ReactDOM.Style.t>,
    "inset": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "sticky": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~colorInherit: string=?,
    ~colorPrimary: string=?,
    ~gutters: ReactDOM.Style.t=?,
    ~inset: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~sticky: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module MenuClassKey = {
  type t = {"list": option<ReactDOM.Style.t>, "paper": option<ReactDOM.Style.t>}
  @obj external make: (~list: ReactDOM.Style.t=?, ~paper: ReactDOM.Style.t=?, unit) => t = ""
}

module MenuItemClassKey = {
  type t = {
    "dense": option<ReactDOM.Style.t>,
    "gutters": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "selected": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~dense: ReactDOM.Style.t=?,
    ~gutters: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~selected: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module MobileStepperClassKey = {
  type t = {
    "dot": option<ReactDOM.Style.t>,
    "dotActive": option<ReactDOM.Style.t>,
    "dots": option<ReactDOM.Style.t>,
    "positionBottom": option<ReactDOM.Style.t>,
    "positionStatic": option<ReactDOM.Style.t>,
    "positionTop": option<ReactDOM.Style.t>,
    "progress": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~dot: ReactDOM.Style.t=?,
    ~dotActive: ReactDOM.Style.t=?,
    ~dots: ReactDOM.Style.t=?,
    ~positionBottom: ReactDOM.Style.t=?,
    ~positionStatic: ReactDOM.Style.t=?,
    ~positionTop: ReactDOM.Style.t=?,
    ~progress: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module NativeSelectClassKey = {
  type t = {
    "disabled": option<ReactDOM.Style.t>,
    "filled": option<ReactDOM.Style.t>,
    "icon": option<ReactDOM.Style.t>,
    "iconFilled": option<ReactDOM.Style.t>,
    "iconOutlined": option<ReactDOM.Style.t>,
    "outlined": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "select": option<ReactDOM.Style.t>,
    "selectMenu": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~disabled: ReactDOM.Style.t=?,
    ~filled: ReactDOM.Style.t=?,
    ~icon: ReactDOM.Style.t=?,
    ~iconFilled: ReactDOM.Style.t=?,
    ~iconOutlined: ReactDOM.Style.t=?,
    ~outlined: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~select: ReactDOM.Style.t=?,
    ~selectMenu: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module OutlinedInputClassKey = {
  type t = {
    "adornedEnd": option<ReactDOM.Style.t>,
    "adornedStart": option<ReactDOM.Style.t>,
    "colorSecondary": option<string>,
    "disabled": option<ReactDOM.Style.t>,
    "error": option<ReactDOM.Style.t>,
    "focused": option<ReactDOM.Style.t>,
    "input": option<ReactDOM.Style.t>,
    "inputAdornedEnd": option<ReactDOM.Style.t>,
    "inputAdornedStart": option<ReactDOM.Style.t>,
    "inputMarginDense": option<ReactDOM.Style.t>,
    "inputMultiline": option<ReactDOM.Style.t>,
    "marginDense": option<ReactDOM.Style.t>,
    "multiline": option<ReactDOM.Style.t>,
    "notchedOutline": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~adornedEnd: ReactDOM.Style.t=?,
    ~adornedStart: ReactDOM.Style.t=?,
    ~colorSecondary: string=?,
    ~disabled: ReactDOM.Style.t=?,
    ~error: ReactDOM.Style.t=?,
    ~focused: ReactDOM.Style.t=?,
    ~input: ReactDOM.Style.t=?,
    ~inputAdornedEnd: ReactDOM.Style.t=?,
    ~inputAdornedStart: ReactDOM.Style.t=?,
    ~inputMarginDense: ReactDOM.Style.t=?,
    ~inputMultiline: ReactDOM.Style.t=?,
    ~marginDense: ReactDOM.Style.t=?,
    ~multiline: ReactDOM.Style.t=?,
    ~notchedOutline: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module PaperClassKey = {
  type t = {
    "elevation0": option<ReactDOM.Style.t>,
    "elevation1": option<ReactDOM.Style.t>,
    "elevation10": option<ReactDOM.Style.t>,
    "elevation11": option<ReactDOM.Style.t>,
    "elevation12": option<ReactDOM.Style.t>,
    "elevation13": option<ReactDOM.Style.t>,
    "elevation14": option<ReactDOM.Style.t>,
    "elevation15": option<ReactDOM.Style.t>,
    "elevation16": option<ReactDOM.Style.t>,
    "elevation17": option<ReactDOM.Style.t>,
    "elevation18": option<ReactDOM.Style.t>,
    "elevation19": option<ReactDOM.Style.t>,
    "elevation2": option<ReactDOM.Style.t>,
    "elevation20": option<ReactDOM.Style.t>,
    "elevation21": option<ReactDOM.Style.t>,
    "elevation22": option<ReactDOM.Style.t>,
    "elevation23": option<ReactDOM.Style.t>,
    "elevation24": option<ReactDOM.Style.t>,
    "elevation3": option<ReactDOM.Style.t>,
    "elevation4": option<ReactDOM.Style.t>,
    "elevation5": option<ReactDOM.Style.t>,
    "elevation6": option<ReactDOM.Style.t>,
    "elevation7": option<ReactDOM.Style.t>,
    "elevation8": option<ReactDOM.Style.t>,
    "elevation9": option<ReactDOM.Style.t>,
    "outlined": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "rounded": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~elevation0: ReactDOM.Style.t=?,
    ~elevation1: ReactDOM.Style.t=?,
    ~elevation10: ReactDOM.Style.t=?,
    ~elevation11: ReactDOM.Style.t=?,
    ~elevation12: ReactDOM.Style.t=?,
    ~elevation13: ReactDOM.Style.t=?,
    ~elevation14: ReactDOM.Style.t=?,
    ~elevation15: ReactDOM.Style.t=?,
    ~elevation16: ReactDOM.Style.t=?,
    ~elevation17: ReactDOM.Style.t=?,
    ~elevation18: ReactDOM.Style.t=?,
    ~elevation19: ReactDOM.Style.t=?,
    ~elevation2: ReactDOM.Style.t=?,
    ~elevation20: ReactDOM.Style.t=?,
    ~elevation21: ReactDOM.Style.t=?,
    ~elevation22: ReactDOM.Style.t=?,
    ~elevation23: ReactDOM.Style.t=?,
    ~elevation24: ReactDOM.Style.t=?,
    ~elevation3: ReactDOM.Style.t=?,
    ~elevation4: ReactDOM.Style.t=?,
    ~elevation5: ReactDOM.Style.t=?,
    ~elevation6: ReactDOM.Style.t=?,
    ~elevation7: ReactDOM.Style.t=?,
    ~elevation8: ReactDOM.Style.t=?,
    ~elevation9: ReactDOM.Style.t=?,
    ~outlined: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~rounded: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module PopoverClassKey = {
  type t = {"paper": option<ReactDOM.Style.t>, "root": option<ReactDOM.Style.t>}
  @obj external make: (~paper: ReactDOM.Style.t=?, ~root: ReactDOM.Style.t=?, unit) => t = ""
}

module RadioClassKey = {
  type t = {
    "checked": option<ReactDOM.Style.t>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "disabled": option<ReactDOM.Style.t>,
    "input": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~checked: ReactDOM.Style.t=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~disabled: ReactDOM.Style.t=?,
    ~input: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module MuiScopedCssBaseline = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module SelectClassKey = {
  type t = {
    "disabled": option<ReactDOM.Style.t>,
    "filled": option<ReactDOM.Style.t>,
    "icon": option<ReactDOM.Style.t>,
    "iconFilled": option<ReactDOM.Style.t>,
    "iconOpen": option<ReactDOM.Style.t>,
    "iconOutlined": option<ReactDOM.Style.t>,
    "outlined": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "select": option<ReactDOM.Style.t>,
    "selectMenu": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~disabled: ReactDOM.Style.t=?,
    ~filled: ReactDOM.Style.t=?,
    ~icon: ReactDOM.Style.t=?,
    ~iconFilled: ReactDOM.Style.t=?,
    ~iconOpen: ReactDOM.Style.t=?,
    ~iconOutlined: ReactDOM.Style.t=?,
    ~outlined: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~select: ReactDOM.Style.t=?,
    ~selectMenu: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module SliderClassKey = {
  type t = {
    "active": option<ReactDOM.Style.t>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "disabled": option<ReactDOM.Style.t>,
    "focusVisible": option<ReactDOM.Style.t>,
    "mark": option<ReactDOM.Style.t>,
    "markActive": option<ReactDOM.Style.t>,
    "markLabel": option<ReactDOM.Style.t>,
    "markLabelActive": option<ReactDOM.Style.t>,
    "marked": option<ReactDOM.Style.t>,
    "rail": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "thumb": option<ReactDOM.Style.t>,
    "thumbColorPrimary": option<ReactDOM.Style.t>,
    "thumbColorSecondary": option<ReactDOM.Style.t>,
    "track": option<ReactDOM.Style.t>,
    "trackFalse": option<ReactDOM.Style.t>,
    "trackInverted": option<ReactDOM.Style.t>,
    "valueLabel": option<ReactDOM.Style.t>,
    "vertical": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~active: ReactDOM.Style.t=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~disabled: ReactDOM.Style.t=?,
    ~focusVisible: ReactDOM.Style.t=?,
    ~mark: ReactDOM.Style.t=?,
    ~markActive: ReactDOM.Style.t=?,
    ~markLabel: ReactDOM.Style.t=?,
    ~markLabelActive: ReactDOM.Style.t=?,
    ~marked: ReactDOM.Style.t=?,
    ~rail: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~thumb: ReactDOM.Style.t=?,
    ~thumbColorPrimary: ReactDOM.Style.t=?,
    ~thumbColorSecondary: ReactDOM.Style.t=?,
    ~track: ReactDOM.Style.t=?,
    ~trackFalse: ReactDOM.Style.t=?,
    ~trackInverted: ReactDOM.Style.t=?,
    ~valueLabel: ReactDOM.Style.t=?,
    ~vertical: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module SnackbarClassKey = {
  type t = {
    "anchorOriginBottomCenter": option<ReactDOM.Style.t>,
    "anchorOriginBottomLeft": option<ReactDOM.Style.t>,
    "anchorOriginBottomRight": option<ReactDOM.Style.t>,
    "anchorOriginTopCenter": option<ReactDOM.Style.t>,
    "anchorOriginTopLeft": option<ReactDOM.Style.t>,
    "anchorOriginTopRight": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~anchorOriginBottomCenter: ReactDOM.Style.t=?,
    ~anchorOriginBottomLeft: ReactDOM.Style.t=?,
    ~anchorOriginBottomRight: ReactDOM.Style.t=?,
    ~anchorOriginTopCenter: ReactDOM.Style.t=?,
    ~anchorOriginTopLeft: ReactDOM.Style.t=?,
    ~anchorOriginTopRight: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module SnackbarContentClassKey = {
  type t = {
    "action": option<ReactDOM.Style.t>,
    "message": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~action: ReactDOM.Style.t=?,
    ~message: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module StepClasskey = {
  type t = {
    "alternativeLabel": option<ReactDOM.Style.t>,
    "completed": option<ReactDOM.Style.t>,
    "horizontal": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "vertical": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~alternativeLabel: ReactDOM.Style.t=?,
    ~completed: ReactDOM.Style.t=?,
    ~horizontal: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~vertical: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module StepButtonClasskey = {
  type t = {
    "root": option<ReactDOM.Style.t>,
    "touchRipple": option<ReactDOM.Style.t>,
    "vertical": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~root: ReactDOM.Style.t=?,
    ~touchRipple: ReactDOM.Style.t=?,
    ~vertical: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module StepConnectorClasskey = {
  type t = {
    "active": option<ReactDOM.Style.t>,
    "alternativeLabel": option<ReactDOM.Style.t>,
    "completed": option<ReactDOM.Style.t>,
    "disabled": option<ReactDOM.Style.t>,
    "horizontal": option<ReactDOM.Style.t>,
    "line": option<ReactDOM.Style.t>,
    "lineHorizontal": option<ReactDOM.Style.t>,
    "lineVertical": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "vertical": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~active: ReactDOM.Style.t=?,
    ~alternativeLabel: ReactDOM.Style.t=?,
    ~completed: ReactDOM.Style.t=?,
    ~disabled: ReactDOM.Style.t=?,
    ~horizontal: ReactDOM.Style.t=?,
    ~line: ReactDOM.Style.t=?,
    ~lineHorizontal: ReactDOM.Style.t=?,
    ~lineVertical: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~vertical: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module StepContentClasskey = {
  type t = {
    "last": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "transition": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~last: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~transition: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module StepIconClasskey = {
  type t = {
    "active": option<ReactDOM.Style.t>,
    "completed": option<ReactDOM.Style.t>,
    "error": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "text": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~active: ReactDOM.Style.t=?,
    ~completed: ReactDOM.Style.t=?,
    ~error: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~text: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module StepLabelClasskey = {
  type t = {
    "active": option<ReactDOM.Style.t>,
    "alternativeLabel": option<ReactDOM.Style.t>,
    "completed": option<ReactDOM.Style.t>,
    "disabled": option<ReactDOM.Style.t>,
    "error": option<ReactDOM.Style.t>,
    "horizontal": option<ReactDOM.Style.t>,
    "iconContainer": option<ReactDOM.Style.t>,
    "label": option<ReactDOM.Style.t>,
    "labelContainer": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "vertical": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~active: ReactDOM.Style.t=?,
    ~alternativeLabel: ReactDOM.Style.t=?,
    ~completed: ReactDOM.Style.t=?,
    ~disabled: ReactDOM.Style.t=?,
    ~error: ReactDOM.Style.t=?,
    ~horizontal: ReactDOM.Style.t=?,
    ~iconContainer: ReactDOM.Style.t=?,
    ~label: ReactDOM.Style.t=?,
    ~labelContainer: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~vertical: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module StepperClasskey = {
  type t = {
    "alternativeLabel": option<ReactDOM.Style.t>,
    "horizontal": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "vertical": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~alternativeLabel: ReactDOM.Style.t=?,
    ~horizontal: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~vertical: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module SwitchClassKey = {
  type t = {
    "checked": option<ReactDOM.Style.t>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "disabled": option<ReactDOM.Style.t>,
    "input": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "sizeSmall": option<ReactDOM.Style.t>,
    "switchBase": option<ReactDOM.Style.t>,
    "thumb": option<ReactDOM.Style.t>,
    "track": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~checked: ReactDOM.Style.t=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~disabled: ReactDOM.Style.t=?,
    ~input: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~sizeSmall: ReactDOM.Style.t=?,
    ~switchBase: ReactDOM.Style.t=?,
    ~thumb: ReactDOM.Style.t=?,
    ~track: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module TabClassKey = {
  type t = {
    "disabled": option<ReactDOM.Style.t>,
    "fullWidth": option<ReactDOM.Style.t>,
    "labelIcon": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "selected": option<ReactDOM.Style.t>,
    "textColorInherit": option<ReactDOM.Style.t>,
    "textColorPrimary": option<ReactDOM.Style.t>,
    "textColorSecondary": option<ReactDOM.Style.t>,
    "wrapped": option<ReactDOM.Style.t>,
    "wrapper": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~disabled: ReactDOM.Style.t=?,
    ~fullWidth: ReactDOM.Style.t=?,
    ~labelIcon: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~selected: ReactDOM.Style.t=?,
    ~textColorInherit: ReactDOM.Style.t=?,
    ~textColorPrimary: ReactDOM.Style.t=?,
    ~textColorSecondary: ReactDOM.Style.t=?,
    ~wrapped: ReactDOM.Style.t=?,
    ~wrapper: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module TableClassKey = {
  type t = {"root": option<ReactDOM.Style.t>, "stickyHeader": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, ~stickyHeader: ReactDOM.Style.t=?, unit) => t = ""
}

module MuiTableBody = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module TableCellClassKey = {
  type t = {
    "alignCenter": option<ReactDOM.Style.t>,
    "alignJustify": option<ReactDOM.Style.t>,
    "alignLeft": option<ReactDOM.Style.t>,
    "alignRight": option<ReactDOM.Style.t>,
    "body": option<ReactDOM.Style.t>,
    "footer": option<ReactDOM.Style.t>,
    "head": option<ReactDOM.Style.t>,
    "paddingCheckbox": option<ReactDOM.Style.t>,
    "paddingNone": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "sizeSmall": option<ReactDOM.Style.t>,
    "stickyHeader": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~alignCenter: ReactDOM.Style.t=?,
    ~alignJustify: ReactDOM.Style.t=?,
    ~alignLeft: ReactDOM.Style.t=?,
    ~alignRight: ReactDOM.Style.t=?,
    ~body: ReactDOM.Style.t=?,
    ~footer: ReactDOM.Style.t=?,
    ~head: ReactDOM.Style.t=?,
    ~paddingCheckbox: ReactDOM.Style.t=?,
    ~paddingNone: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~sizeSmall: ReactDOM.Style.t=?,
    ~stickyHeader: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module MuiTableContainer = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module MuiTableFooter = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module MuiTableHead = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module TablePaginationClassKey = {
  type t = {
    "actions": option<ReactDOM.Style.t>,
    "caption": option<ReactDOM.Style.t>,
    "input": option<ReactDOM.Style.t>,
    "menuItem": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "select": option<ReactDOM.Style.t>,
    "selectIcon": option<ReactDOM.Style.t>,
    "selectRoot": option<ReactDOM.Style.t>,
    "spacer": option<ReactDOM.Style.t>,
    "toolbar": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~actions: ReactDOM.Style.t=?,
    ~caption: ReactDOM.Style.t=?,
    ~input: ReactDOM.Style.t=?,
    ~menuItem: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~select: ReactDOM.Style.t=?,
    ~selectIcon: ReactDOM.Style.t=?,
    ~selectRoot: ReactDOM.Style.t=?,
    ~spacer: ReactDOM.Style.t=?,
    ~toolbar: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module TableRowClassKey = {
  type t = {
    "footer": option<ReactDOM.Style.t>,
    "head": option<ReactDOM.Style.t>,
    "hover": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "selected": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~footer: ReactDOM.Style.t=?,
    ~head: ReactDOM.Style.t=?,
    ~hover: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~selected: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module TableSortLabelClassKey = {
  type t = {
    "active": option<ReactDOM.Style.t>,
    "icon": option<ReactDOM.Style.t>,
    "iconDirectionAsc": option<ReactDOM.Style.t>,
    "iconDirectionDesc": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~active: ReactDOM.Style.t=?,
    ~icon: ReactDOM.Style.t=?,
    ~iconDirectionAsc: ReactDOM.Style.t=?,
    ~iconDirectionDesc: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module TabsClassKey = {
  type t = {
    "centered": option<ReactDOM.Style.t>,
    "fixed": option<ReactDOM.Style.t>,
    "flexContainer": option<ReactDOM.Style.t>,
    "indicator": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "scrollButtons": option<ReactDOM.Style.t>,
    "scrollButtonsDesktop": option<ReactDOM.Style.t>,
    "scrollable": option<ReactDOM.Style.t>,
    "scroller": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~centered: ReactDOM.Style.t=?,
    ~fixed: ReactDOM.Style.t=?,
    ~flexContainer: ReactDOM.Style.t=?,
    ~indicator: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~scrollButtons: ReactDOM.Style.t=?,
    ~scrollButtonsDesktop: ReactDOM.Style.t=?,
    ~scrollable: ReactDOM.Style.t=?,
    ~scroller: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module MuiTextField = {
  type t = {"root": option<ReactDOM.Style.t>}
  @obj external make: (~root: ReactDOM.Style.t=?, unit) => t = ""
}

module ToolbarClassKey = {
  type t = {
    "dense": option<ReactDOM.Style.t>,
    "gutters": option<ReactDOM.Style.t>,
    "regular": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~dense: ReactDOM.Style.t=?,
    ~gutters: ReactDOM.Style.t=?,
    ~regular: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module TooltipClassKey = {
  type t = {
    "arrow": option<ReactDOM.Style.t>,
    "popper": option<ReactDOM.Style.t>,
    "popperArrow": option<ReactDOM.Style.t>,
    "popperInteractive": option<ReactDOM.Style.t>,
    "tooltip": option<ReactDOM.Style.t>,
    "tooltipArrow": option<ReactDOM.Style.t>,
    "tooltipPlacementBottom": option<ReactDOM.Style.t>,
    "tooltipPlacementLeft": option<ReactDOM.Style.t>,
    "tooltipPlacementRight": option<ReactDOM.Style.t>,
    "tooltipPlacementTop": option<ReactDOM.Style.t>,
    "touch": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~arrow: ReactDOM.Style.t=?,
    ~popper: ReactDOM.Style.t=?,
    ~popperArrow: ReactDOM.Style.t=?,
    ~popperInteractive: ReactDOM.Style.t=?,
    ~tooltip: ReactDOM.Style.t=?,
    ~tooltipArrow: ReactDOM.Style.t=?,
    ~tooltipPlacementBottom: ReactDOM.Style.t=?,
    ~tooltipPlacementLeft: ReactDOM.Style.t=?,
    ~tooltipPlacementRight: ReactDOM.Style.t=?,
    ~tooltipPlacementTop: ReactDOM.Style.t=?,
    ~touch: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module TouchRippleClassKey = {
  type t = {
    "child": option<ReactDOM.Style.t>,
    "childLeaving": option<ReactDOM.Style.t>,
    "childPulsate": option<ReactDOM.Style.t>,
    "ripple": option<ReactDOM.Style.t>,
    "ripplePulsate": option<ReactDOM.Style.t>,
    "rippleVisible": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~child: ReactDOM.Style.t=?,
    ~childLeaving: ReactDOM.Style.t=?,
    ~childPulsate: ReactDOM.Style.t=?,
    ~ripple: ReactDOM.Style.t=?,
    ~ripplePulsate: ReactDOM.Style.t=?,
    ~rippleVisible: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module TypographyClassKey = {
  type t = {
    "alignCenter": option<ReactDOM.Style.t>,
    "alignJustify": option<ReactDOM.Style.t>,
    "alignLeft": option<ReactDOM.Style.t>,
    "alignRight": option<ReactDOM.Style.t>,
    "body1": option<ReactDOM.Style.t>,
    "body2": option<ReactDOM.Style.t>,
    "button": option<ReactDOM.Style.t>,
    "caption": option<ReactDOM.Style.t>,
    "colorError": option<string>,
    "colorInherit": option<string>,
    "colorPrimary": option<string>,
    "colorSecondary": option<string>,
    "colorTextPrimary": option<string>,
    "colorTextSecondary": option<string>,
    "displayBlock": option<ReactDOM.Style.t>,
    "displayInline": option<ReactDOM.Style.t>,
    "gutterBottom": option<ReactDOM.Style.t>,
    "h1": option<ReactDOM.Style.t>,
    "h2": option<ReactDOM.Style.t>,
    "h3": option<ReactDOM.Style.t>,
    "h4": option<ReactDOM.Style.t>,
    "h5": option<ReactDOM.Style.t>,
    "h6": option<ReactDOM.Style.t>,
    "noWrap": option<ReactDOM.Style.t>,
    "overline": option<ReactDOM.Style.t>,
    "paragraph": option<ReactDOM.Style.t>,
    "root": option<ReactDOM.Style.t>,
    "srOnly": option<ReactDOM.Style.t>,
    "subtitle1": option<ReactDOM.Style.t>,
    "subtitle2": option<ReactDOM.Style.t>,
  }
  @obj
  external make: (
    ~alignCenter: ReactDOM.Style.t=?,
    ~alignJustify: ReactDOM.Style.t=?,
    ~alignLeft: ReactDOM.Style.t=?,
    ~alignRight: ReactDOM.Style.t=?,
    ~body1: ReactDOM.Style.t=?,
    ~body2: ReactDOM.Style.t=?,
    ~button: ReactDOM.Style.t=?,
    ~caption: ReactDOM.Style.t=?,
    ~colorError: string=?,
    ~colorInherit: string=?,
    ~colorPrimary: string=?,
    ~colorSecondary: string=?,
    ~colorTextPrimary: string=?,
    ~colorTextSecondary: string=?,
    ~displayBlock: ReactDOM.Style.t=?,
    ~displayInline: ReactDOM.Style.t=?,
    ~gutterBottom: ReactDOM.Style.t=?,
    ~h1: ReactDOM.Style.t=?,
    ~h2: ReactDOM.Style.t=?,
    ~h3: ReactDOM.Style.t=?,
    ~h4: ReactDOM.Style.t=?,
    ~h5: ReactDOM.Style.t=?,
    ~h6: ReactDOM.Style.t=?,
    ~noWrap: ReactDOM.Style.t=?,
    ~overline: ReactDOM.Style.t=?,
    ~paragraph: ReactDOM.Style.t=?,
    ~root: ReactDOM.Style.t=?,
    ~srOnly: ReactDOM.Style.t=?,
    ~subtitle1: ReactDOM.Style.t=?,
    ~subtitle2: ReactDOM.Style.t=?,
    unit,
  ) => t = ""
}

module Overrides = {
  type t = {
    "MuiAccordion": option<AccordionClassKey.t>,
    "MuiAccordionActions": option<AccordionActionsClassKey.t>,
    "MuiAccordionDetails": option<MuiAccordionDetails.t>,
    "MuiAccordionSummary": option<AccordionSummaryClassKey.t>,
    "MuiAppBar": option<AppBarClassKey.t>,
    "MuiAvatar": option<AvatarClassKey.t>,
    "MuiBackdrop": option<BackdropClassKey.t>,
    "MuiBadge": option<BadgeClassKey.t>,
    "MuiBottomNavigation": option<MuiBottomNavigation.t>,
    "MuiBottomNavigationAction": option<BottomNavigationActionClassKey.t>,
    "MuiBreadcrumbs": option<BreadcrumbsClassKey.t>,
    "MuiButton": option<ButtonClassKey.t>,
    "MuiButtonBase": option<ButtonBaseClassKey.t>,
    "MuiButtonGroup": option<ButtonGroupClassKey.t>,
    "MuiCard": option<MuiCard.t>,
    "MuiCardActionArea": option<CardActionAreaClassKey.t>,
    "MuiCardActions": option<AccordionActionsClassKey.t>,
    "MuiCardContent": option<MuiCardContent.t>,
    "MuiCardHeader": option<CardHeaderClassKey.t>,
    "MuiCardMedia": option<CardMediaClassKey.t>,
    "MuiCheckbox": option<CheckboxClassKey.t>,
    "MuiChip": option<ChipClassKey.t>,
    "MuiCircularProgress": option<CircularProgressClassKey.t>,
    "MuiCollapse": option<CollapseClassKey.t>,
    "MuiContainer": option<ContainerClassKey.t>,
    "MuiCssBaseline": option<MuiCssBaseline.t>,
    "MuiDialog": option<DialogClassKey.t>,
    "MuiDialogActions": option<AccordionActionsClassKey.t>,
    "MuiDialogContent": option<DialogContentClassKey.t>,
    "MuiDialogContentText": option<MuiDialogContentText.t>,
    "MuiDialogTitle": option<MuiDialogTitle.t>,
    "MuiDivider": option<DividerClassKey.t>,
    "MuiDrawer": option<DrawerClassKey.t>,
    "MuiExpansionPanel": option<AccordionClassKey.t>,
    "MuiExpansionPanelActions": option<AccordionActionsClassKey.t>,
    "MuiExpansionPanelDetails": option<MuiExpansionPanelDetails.t>,
    "MuiExpansionPanelSummary": option<ExpansionPanelSummaryClassKey.t>,
    "MuiFab": option<FabClassKey.t>,
    "MuiFilledInput": option<FilledInputClassKey.t>,
    "MuiFormControl": option<FormControlClassKey.t>,
    "MuiFormControlLabel": option<FormControlLabelClassKey.t>,
    "MuiFormGroup": option<FormGroupClassKey.t>,
    "MuiFormHelperText": option<FormHelperTextClassKey.t>,
    "MuiFormLabel": option<FormLabelClassKey.t>,
    "MuiGrid": option<GridClassKey.t>,
    "MuiIcon": option<SvgIconClassKey.t>,
    "MuiIconButton": option<IconButtonClassKey.t>,
    "MuiImageList": option<MuiImageList.t>,
    "MuiImageListItem": option<ImageListItemClassKey.t>,
    "MuiImageListItemBar": option<ImageListItemBarClassKey.t>,
    "MuiInput": option<InputClassKey.t>,
    "MuiInputAdornment": option<InputAdornmentClassKey.t>,
    "MuiInputBase": option<InputBaseClassKey.t>,
    "MuiInputLabel": option<InputLabelClassKey.t>,
    "MuiLinearProgress": option<LinearProgressClassKey.t>,
    "MuiLink": option<LinkClassKey.t>,
    "MuiList": option<ListClassKey.t>,
    "MuiListItem": option<ListItemClassKey.t>,
    "MuiListItemAvatar": option<ListItemAvatarClassKey.t>,
    "MuiListItemIcon": option<ListItemIconClassKey.t>,
    "MuiListItemSecondaryAction": option<MuiListItemSecondaryAction.t>,
    "MuiListItemText": option<ListItemTextClassKey.t>,
    "MuiListSubheader": option<ListSubheaderClassKey.t>,
    "MuiMenu": option<MenuClassKey.t>,
    "MuiMenuItem": option<MenuItemClassKey.t>,
    "MuiMobileStepper": option<MobileStepperClassKey.t>,
    "MuiNativeSelect": option<NativeSelectClassKey.t>,
    "MuiOutlinedInput": option<OutlinedInputClassKey.t>,
    "MuiPaper": option<PaperClassKey.t>,
    "MuiPopover": option<PopoverClassKey.t>,
    "MuiRadio": option<RadioClassKey.t>,
    "MuiScopedCssBaseline": option<MuiScopedCssBaseline.t>,
    "MuiSelect": option<SelectClassKey.t>,
    "MuiSlider": option<SliderClassKey.t>,
    "MuiSnackbar": option<SnackbarClassKey.t>,
    "MuiSnackbarContent": option<SnackbarContentClassKey.t>,
    "MuiStep": option<StepClasskey.t>,
    "MuiStepButton": option<StepButtonClasskey.t>,
    "MuiStepConnector": option<StepConnectorClasskey.t>,
    "MuiStepContent": option<StepContentClasskey.t>,
    "MuiStepIcon": option<StepIconClasskey.t>,
    "MuiStepLabel": option<StepLabelClasskey.t>,
    "MuiStepper": option<StepperClasskey.t>,
    "MuiSvgIcon": option<SvgIconClassKey.t>,
    "MuiSwitch": option<SwitchClassKey.t>,
    "MuiTab": option<TabClassKey.t>,
    "MuiTable": option<TableClassKey.t>,
    "MuiTableBody": option<MuiTableBody.t>,
    "MuiTableCell": option<TableCellClassKey.t>,
    "MuiTableContainer": option<MuiTableContainer.t>,
    "MuiTableFooter": option<MuiTableFooter.t>,
    "MuiTableHead": option<MuiTableHead.t>,
    "MuiTablePagination": option<TablePaginationClassKey.t>,
    "MuiTableRow": option<TableRowClassKey.t>,
    "MuiTableSortLabel": option<TableSortLabelClassKey.t>,
    "MuiTabs": option<TabsClassKey.t>,
    "MuiTextField": option<MuiTextField.t>,
    "MuiToolbar": option<ToolbarClassKey.t>,
    "MuiTooltip": option<TooltipClassKey.t>,
    "MuiTouchRipple": option<TouchRippleClassKey.t>,
    "MuiTypography": option<TypographyClassKey.t>,
  }
  @obj
  external make: (
    ~\"MuiAccordion": AccordionClassKey.t=?,
    ~\"MuiAccordionActions": AccordionActionsClassKey.t=?,
    ~\"MuiAccordionDetails": MuiAccordionDetails.t=?,
    ~\"MuiAccordionSummary": AccordionSummaryClassKey.t=?,
    ~\"MuiAppBar": AppBarClassKey.t=?,
    ~\"MuiAvatar": AvatarClassKey.t=?,
    ~\"MuiBackdrop": BackdropClassKey.t=?,
    ~\"MuiBadge": BadgeClassKey.t=?,
    ~\"MuiBottomNavigation": MuiBottomNavigation.t=?,
    ~\"MuiBottomNavigationAction": BottomNavigationActionClassKey.t=?,
    ~\"MuiBreadcrumbs": BreadcrumbsClassKey.t=?,
    ~\"MuiButton": ButtonClassKey.t=?,
    ~\"MuiButtonBase": ButtonBaseClassKey.t=?,
    ~\"MuiButtonGroup": ButtonGroupClassKey.t=?,
    ~\"MuiCard": MuiCard.t=?,
    ~\"MuiCardActionArea": CardActionAreaClassKey.t=?,
    ~\"MuiCardActions": AccordionActionsClassKey.t=?,
    ~\"MuiCardContent": MuiCardContent.t=?,
    ~\"MuiCardHeader": CardHeaderClassKey.t=?,
    ~\"MuiCardMedia": CardMediaClassKey.t=?,
    ~\"MuiCheckbox": CheckboxClassKey.t=?,
    ~\"MuiChip": ChipClassKey.t=?,
    ~\"MuiCircularProgress": CircularProgressClassKey.t=?,
    ~\"MuiCollapse": CollapseClassKey.t=?,
    ~\"MuiContainer": ContainerClassKey.t=?,
    ~\"MuiCssBaseline": MuiCssBaseline.t=?,
    ~\"MuiDialog": DialogClassKey.t=?,
    ~\"MuiDialogActions": AccordionActionsClassKey.t=?,
    ~\"MuiDialogContent": DialogContentClassKey.t=?,
    ~\"MuiDialogContentText": MuiDialogContentText.t=?,
    ~\"MuiDialogTitle": MuiDialogTitle.t=?,
    ~\"MuiDivider": DividerClassKey.t=?,
    ~\"MuiDrawer": DrawerClassKey.t=?,
    ~\"MuiExpansionPanel": AccordionClassKey.t=?,
    ~\"MuiExpansionPanelActions": AccordionActionsClassKey.t=?,
    ~\"MuiExpansionPanelDetails": MuiExpansionPanelDetails.t=?,
    ~\"MuiExpansionPanelSummary": ExpansionPanelSummaryClassKey.t=?,
    ~\"MuiFab": FabClassKey.t=?,
    ~\"MuiFilledInput": FilledInputClassKey.t=?,
    ~\"MuiFormControl": FormControlClassKey.t=?,
    ~\"MuiFormControlLabel": FormControlLabelClassKey.t=?,
    ~\"MuiFormGroup": FormGroupClassKey.t=?,
    ~\"MuiFormHelperText": FormHelperTextClassKey.t=?,
    ~\"MuiFormLabel": FormLabelClassKey.t=?,
    ~\"MuiGrid": GridClassKey.t=?,
    ~\"MuiIcon": SvgIconClassKey.t=?,
    ~\"MuiIconButton": IconButtonClassKey.t=?,
    ~\"MuiImageList": MuiImageList.t=?,
    ~\"MuiImageListItem": ImageListItemClassKey.t=?,
    ~\"MuiImageListItemBar": ImageListItemBarClassKey.t=?,
    ~\"MuiInput": InputClassKey.t=?,
    ~\"MuiInputAdornment": InputAdornmentClassKey.t=?,
    ~\"MuiInputBase": InputBaseClassKey.t=?,
    ~\"MuiInputLabel": InputLabelClassKey.t=?,
    ~\"MuiLinearProgress": LinearProgressClassKey.t=?,
    ~\"MuiLink": LinkClassKey.t=?,
    ~\"MuiList": ListClassKey.t=?,
    ~\"MuiListItem": ListItemClassKey.t=?,
    ~\"MuiListItemAvatar": ListItemAvatarClassKey.t=?,
    ~\"MuiListItemIcon": ListItemIconClassKey.t=?,
    ~\"MuiListItemSecondaryAction": MuiListItemSecondaryAction.t=?,
    ~\"MuiListItemText": ListItemTextClassKey.t=?,
    ~\"MuiListSubheader": ListSubheaderClassKey.t=?,
    ~\"MuiMenu": MenuClassKey.t=?,
    ~\"MuiMenuItem": MenuItemClassKey.t=?,
    ~\"MuiMobileStepper": MobileStepperClassKey.t=?,
    ~\"MuiNativeSelect": NativeSelectClassKey.t=?,
    ~\"MuiOutlinedInput": OutlinedInputClassKey.t=?,
    ~\"MuiPaper": PaperClassKey.t=?,
    ~\"MuiPopover": PopoverClassKey.t=?,
    ~\"MuiRadio": RadioClassKey.t=?,
    ~\"MuiScopedCssBaseline": MuiScopedCssBaseline.t=?,
    ~\"MuiSelect": SelectClassKey.t=?,
    ~\"MuiSlider": SliderClassKey.t=?,
    ~\"MuiSnackbar": SnackbarClassKey.t=?,
    ~\"MuiSnackbarContent": SnackbarContentClassKey.t=?,
    ~\"MuiStep": StepClasskey.t=?,
    ~\"MuiStepButton": StepButtonClasskey.t=?,
    ~\"MuiStepConnector": StepConnectorClasskey.t=?,
    ~\"MuiStepContent": StepContentClasskey.t=?,
    ~\"MuiStepIcon": StepIconClasskey.t=?,
    ~\"MuiStepLabel": StepLabelClasskey.t=?,
    ~\"MuiStepper": StepperClasskey.t=?,
    ~\"MuiSvgIcon": SvgIconClassKey.t=?,
    ~\"MuiSwitch": SwitchClassKey.t=?,
    ~\"MuiTab": TabClassKey.t=?,
    ~\"MuiTable": TableClassKey.t=?,
    ~\"MuiTableBody": MuiTableBody.t=?,
    ~\"MuiTableCell": TableCellClassKey.t=?,
    ~\"MuiTableContainer": MuiTableContainer.t=?,
    ~\"MuiTableFooter": MuiTableFooter.t=?,
    ~\"MuiTableHead": MuiTableHead.t=?,
    ~\"MuiTablePagination": TablePaginationClassKey.t=?,
    ~\"MuiTableRow": TableRowClassKey.t=?,
    ~\"MuiTableSortLabel": TableSortLabelClassKey.t=?,
    ~\"MuiTabs": TabsClassKey.t=?,
    ~\"MuiTextField": MuiTextField.t=?,
    ~\"MuiToolbar": ToolbarClassKey.t=?,
    ~\"MuiTooltip": TooltipClassKey.t=?,
    ~\"MuiTouchRipple": TouchRippleClassKey.t=?,
    ~\"MuiTypography": TypographyClassKey.t=?,
    unit,
  ) => t = ""
}

module TypeAction = {
  type t = {
    "activatedOpacity": option<float>,
    "active": option<string>,
    "disabled": option<string>,
    "disabledBackground": option<string>,
    "disabledOpacity": option<float>,
    "focus": option<string>,
    "focusOpacity": option<float>,
    "hover": option<string>,
    "hoverOpacity": option<float>,
    "selected": option<string>,
    "selectedOpacity": option<float>,
  }
  @obj
  external make: (
    ~activatedOpacity: float=?,
    ~active: string=?,
    ~disabled: string=?,
    ~disabledBackground: string=?,
    ~disabledOpacity: float=?,
    ~focus: string=?,
    ~focusOpacity: float=?,
    ~hover: string=?,
    ~hoverOpacity: float=?,
    ~selected: string=?,
    ~selectedOpacity: float=?,
    unit,
  ) => t = ""
}

module TypeBackground = {
  type t = {"default": option<string>, "paper": option<string>}
  @obj external make: (~default: string=?, ~paper: string=?, unit) => t = ""
}

module CommonColors = {
  type t = {"black": option<string>, "white": option<string>}
  @obj external make: (~black: string=?, ~white: string=?, unit) => t = ""
}

module Error = {
  type t = {
    "50": option<string>,
    "100": option<string>,
    "200": option<string>,
    "300": option<string>,
    "400": option<string>,
    "500": option<string>,
    "600": option<string>,
    "700": option<string>,
    "800": option<string>,
    "900": option<string>,
    "A100": option<string>,
    "A200": option<string>,
    "A400": option<string>,
    "A700": option<string>,
    "contrastText": option<string>,
    "dark": option<string>,
    "light": option<string>,
    "main": option<string>,
  }
  @obj
  external make: (
    ~\"50": string=?,
    ~\"100": string=?,
    ~\"200": string=?,
    ~\"300": string=?,
    ~\"400": string=?,
    ~\"500": string=?,
    ~\"600": string=?,
    ~\"700": string=?,
    ~\"800": string=?,
    ~\"900": string=?,
    ~\"A100": string=?,
    ~\"A200": string=?,
    ~\"A400": string=?,
    ~\"A700": string=?,
    ~contrastText: string=?,
    ~dark: string=?,
    ~light: string=?,
    ~main: string=?,
    unit,
  ) => t = ""
}

module Color = {
  type t = {
    "50": option<string>,
    "100": option<string>,
    "200": option<string>,
    "300": option<string>,
    "400": option<string>,
    "500": option<string>,
    "600": option<string>,
    "700": option<string>,
    "800": option<string>,
    "900": option<string>,
    "A100": option<string>,
    "A200": option<string>,
    "A400": option<string>,
    "A700": option<string>,
  }
  @obj
  external make: (
    ~\"50": string=?,
    ~\"100": string=?,
    ~\"200": string=?,
    ~\"300": string=?,
    ~\"400": string=?,
    ~\"500": string=?,
    ~\"600": string=?,
    ~\"700": string=?,
    ~\"800": string=?,
    ~\"900": string=?,
    ~\"A100": string=?,
    ~\"A200": string=?,
    ~\"A400": string=?,
    ~\"A700": string=?,
    unit,
  ) => t = ""
}

module Info = {
  type t = {
    "50": option<string>,
    "100": option<string>,
    "200": option<string>,
    "300": option<string>,
    "400": option<string>,
    "500": option<string>,
    "600": option<string>,
    "700": option<string>,
    "800": option<string>,
    "900": option<string>,
    "A100": option<string>,
    "A200": option<string>,
    "A400": option<string>,
    "A700": option<string>,
    "contrastText": option<string>,
    "dark": option<string>,
    "light": option<string>,
    "main": option<string>,
  }
  @obj
  external make: (
    ~\"50": string=?,
    ~\"100": string=?,
    ~\"200": string=?,
    ~\"300": string=?,
    ~\"400": string=?,
    ~\"500": string=?,
    ~\"600": string=?,
    ~\"700": string=?,
    ~\"800": string=?,
    ~\"900": string=?,
    ~\"A100": string=?,
    ~\"A200": string=?,
    ~\"A400": string=?,
    ~\"A700": string=?,
    ~contrastText: string=?,
    ~dark: string=?,
    ~light: string=?,
    ~main: string=?,
    unit,
  ) => t = ""
}

module Primary = {
  type t = {
    "50": option<string>,
    "100": option<string>,
    "200": option<string>,
    "300": option<string>,
    "400": option<string>,
    "500": option<string>,
    "600": option<string>,
    "700": option<string>,
    "800": option<string>,
    "900": option<string>,
    "A100": option<string>,
    "A200": option<string>,
    "A400": option<string>,
    "A700": option<string>,
    "contrastText": option<string>,
    "dark": option<string>,
    "light": option<string>,
    "main": option<string>,
  }
  @obj
  external make: (
    ~\"50": string=?,
    ~\"100": string=?,
    ~\"200": string=?,
    ~\"300": string=?,
    ~\"400": string=?,
    ~\"500": string=?,
    ~\"600": string=?,
    ~\"700": string=?,
    ~\"800": string=?,
    ~\"900": string=?,
    ~\"A100": string=?,
    ~\"A200": string=?,
    ~\"A400": string=?,
    ~\"A700": string=?,
    ~contrastText: string=?,
    ~dark: string=?,
    ~light: string=?,
    ~main: string=?,
    unit,
  ) => t = ""
}

module Secondary = {
  type t = {
    "50": option<string>,
    "100": option<string>,
    "200": option<string>,
    "300": option<string>,
    "400": option<string>,
    "500": option<string>,
    "600": option<string>,
    "700": option<string>,
    "800": option<string>,
    "900": option<string>,
    "A100": option<string>,
    "A200": option<string>,
    "A400": option<string>,
    "A700": option<string>,
    "contrastText": option<string>,
    "dark": option<string>,
    "light": option<string>,
    "main": option<string>,
  }
  @obj
  external make: (
    ~\"50": string=?,
    ~\"100": string=?,
    ~\"200": string=?,
    ~\"300": string=?,
    ~\"400": string=?,
    ~\"500": string=?,
    ~\"600": string=?,
    ~\"700": string=?,
    ~\"800": string=?,
    ~\"900": string=?,
    ~\"A100": string=?,
    ~\"A200": string=?,
    ~\"A400": string=?,
    ~\"A700": string=?,
    ~contrastText: string=?,
    ~dark: string=?,
    ~light: string=?,
    ~main: string=?,
    unit,
  ) => t = ""
}

module Success = {
  type t = {
    "50": option<string>,
    "100": option<string>,
    "200": option<string>,
    "300": option<string>,
    "400": option<string>,
    "500": option<string>,
    "600": option<string>,
    "700": option<string>,
    "800": option<string>,
    "900": option<string>,
    "A100": option<string>,
    "A200": option<string>,
    "A400": option<string>,
    "A700": option<string>,
    "contrastText": option<string>,
    "dark": option<string>,
    "light": option<string>,
    "main": option<string>,
  }
  @obj
  external make: (
    ~\"50": string=?,
    ~\"100": string=?,
    ~\"200": string=?,
    ~\"300": string=?,
    ~\"400": string=?,
    ~\"500": string=?,
    ~\"600": string=?,
    ~\"700": string=?,
    ~\"800": string=?,
    ~\"900": string=?,
    ~\"A100": string=?,
    ~\"A200": string=?,
    ~\"A400": string=?,
    ~\"A700": string=?,
    ~contrastText: string=?,
    ~dark: string=?,
    ~light: string=?,
    ~main: string=?,
    unit,
  ) => t = ""
}

module TypeText = {
  type t = {
    "disabled": option<string>,
    "hint": option<string>,
    "primary": option<string>,
    "secondary": option<string>,
  }
  @obj
  external make: (
    ~disabled: string=?,
    ~hint: string=?,
    ~primary: string=?,
    ~secondary: string=?,
    unit,
  ) => t = ""
}

module TonalOffset = {
  type t = {"dark": option<float>, "light": option<float>}
  @obj external make: (~dark: float=?, ~light: float=?, unit) => t = ""
}

module Warning = {
  type t = {
    "50": option<string>,
    "100": option<string>,
    "200": option<string>,
    "300": option<string>,
    "400": option<string>,
    "500": option<string>,
    "600": option<string>,
    "700": option<string>,
    "800": option<string>,
    "900": option<string>,
    "A100": option<string>,
    "A200": option<string>,
    "A400": option<string>,
    "A700": option<string>,
    "contrastText": option<string>,
    "dark": option<string>,
    "light": option<string>,
    "main": option<string>,
  }
  @obj
  external make: (
    ~\"50": string=?,
    ~\"100": string=?,
    ~\"200": string=?,
    ~\"300": string=?,
    ~\"400": string=?,
    ~\"500": string=?,
    ~\"600": string=?,
    ~\"700": string=?,
    ~\"800": string=?,
    ~\"900": string=?,
    ~\"A100": string=?,
    ~\"A200": string=?,
    ~\"A400": string=?,
    ~\"A700": string=?,
    ~contrastText: string=?,
    ~dark: string=?,
    ~light: string=?,
    ~main: string=?,
    unit,
  ) => t = ""
}

module PaletteOptions = {
  type t = {
    "action": option<TypeAction.t>,
    "background": option<TypeBackground.t>,
    "common": option<CommonColors.t>,
    "contrastThreshold": option<float>,
    "divider": option<string>,
    "error": option<Error.t>,
    "getContrastText": option<Any.t>,
    "grey": option<Color.t>,
    "info": option<Info.t>,
    "primary": option<Primary.t>,
    "secondary": option<Secondary.t>,
    "success": option<Success.t>,
    "text": option<TypeText.t>,
    "tonalOffset": option<TonalOffset.t>,
    "type": option<string>,
    "warning": option<Warning.t>,
  }
  @obj
  external make: (
    ~action: TypeAction.t=?,
    ~background: TypeBackground.t=?,
    ~common: CommonColors.t=?,
    ~contrastThreshold: float=?,
    ~divider: string=?,
    ~error: Error.t=?,
    ~getContrastText: Any.t=?,
    ~grey: Color.t=?,
    ~info: Info.t=?,
    ~primary: Primary.t=?,
    ~secondary: Secondary.t=?,
    ~success: Success.t=?,
    ~text: TypeText.t=?,
    ~tonalOffset: TonalOffset.t=?,
    ~\"type": string=?,
    ~warning: Warning.t=?,
    unit,
  ) => t = ""
}

module Shape = {
  type t = {"borderRadius": option<float>}
  @obj external make: (~borderRadius: float=?, unit) => t = ""
}

module Duration = {
  type t = {
    "complex": option<float>,
    "enteringScreen": option<float>,
    "leavingScreen": option<float>,
    "short": option<float>,
    "shorter": option<float>,
    "shortest": option<float>,
    "standard": option<float>,
  }
  @obj
  external make: (
    ~complex: float=?,
    ~enteringScreen: float=?,
    ~leavingScreen: float=?,
    ~short: float=?,
    ~shorter: float=?,
    ~shortest: float=?,
    ~standard: float=?,
    unit,
  ) => t = ""
}

module Easing = {
  type t = {
    "easeIn": option<string>,
    "easeInOut": option<string>,
    "easeOut": option<string>,
    "sharp": option<string>,
  }
  @obj
  external make: (
    ~easeIn: string=?,
    ~easeInOut: string=?,
    ~easeOut: string=?,
    ~sharp: string=?,
    unit,
  ) => t = ""
}

module TransitionsOptions = {
  type t = {
    "create": option<Any.t>,
    "duration": option<Duration.t>,
    "easing": option<Easing.t>,
    "getAutoHeightDuration": option<Any.t>,
  }
  @obj
  external make: (
    ~create: Any.t=?,
    ~duration: Duration.t=?,
    ~easing: Easing.t=?,
    ~getAutoHeightDuration: Any.t=?,
    unit,
  ) => t = ""
}

module TypographyStyleOptions = {
  type t = {"@font-face": option<Any.t>}
  @obj external make: (~\"@font-face": Any.t=?, unit) => t = ""
}

module Typography = {
  type t = {
    "body1": option<TypographyStyleOptions.t>,
    "body2": option<TypographyStyleOptions.t>,
    "button": option<TypographyStyleOptions.t>,
    "caption": option<TypographyStyleOptions.t>,
    "fontFamily": option<string>,
    "fontSize": option<float>,
    "fontWeightBold": option<string>,
    "fontWeightLight": option<string>,
    "fontWeightMedium": option<string>,
    "fontWeightRegular": option<string>,
    "h1": option<TypographyStyleOptions.t>,
    "h2": option<TypographyStyleOptions.t>,
    "h3": option<TypographyStyleOptions.t>,
    "h4": option<TypographyStyleOptions.t>,
    "h5": option<TypographyStyleOptions.t>,
    "h6": option<TypographyStyleOptions.t>,
    "htmlFontSize": option<float>,
    "overline": option<TypographyStyleOptions.t>,
    "subtitle1": option<TypographyStyleOptions.t>,
    "subtitle2": option<TypographyStyleOptions.t>,
  }
  @obj
  external make: (
    ~body1: TypographyStyleOptions.t=?,
    ~body2: TypographyStyleOptions.t=?,
    ~button: TypographyStyleOptions.t=?,
    ~caption: TypographyStyleOptions.t=?,
    ~fontFamily: string=?,
    ~fontSize: float=?,
    ~fontWeightBold: string=?,
    ~fontWeightLight: string=?,
    ~fontWeightMedium: string=?,
    ~fontWeightRegular: string=?,
    ~h1: TypographyStyleOptions.t=?,
    ~h2: TypographyStyleOptions.t=?,
    ~h3: TypographyStyleOptions.t=?,
    ~h4: TypographyStyleOptions.t=?,
    ~h5: TypographyStyleOptions.t=?,
    ~h6: TypographyStyleOptions.t=?,
    ~htmlFontSize: float=?,
    ~overline: TypographyStyleOptions.t=?,
    ~subtitle1: TypographyStyleOptions.t=?,
    ~subtitle2: TypographyStyleOptions.t=?,
    unit,
  ) => t = ""
}

module ZIndex = {
  type t = {
    "appBar": option<float>,
    "drawer": option<float>,
    "mobileStepper": option<float>,
    "modal": option<float>,
    "snackbar": option<float>,
    "speedDial": option<float>,
    "tooltip": option<float>,
  }
  @obj
  external make: (
    ~appBar: float=?,
    ~drawer: float=?,
    ~mobileStepper: float=?,
    ~modal: float=?,
    ~snackbar: float=?,
    ~speedDial: float=?,
    ~tooltip: float=?,
    unit,
  ) => t = ""
}

type t = {
  "breakpoints": option<Breakpoints.t>,
  "direction": option<string>,
  "mixins": option<MixinsOptions.t>,
  "overrides": option<Overrides.t>,
  "palette": option<PaletteOptions.t>,
  "props": option<Any.t>,
  "shadows": option<array<string>>,
  "shape": option<Shape.t>,
  "spacing": option<Any.t>,
  "transitions": option<TransitionsOptions.t>,
  "typography": option<Typography.t>,
  "unstable_strictMode": option<bool>,
  "zIndex": option<ZIndex.t>,
}
@obj
external make: (
  ~breakpoints: Breakpoints.t=?,
  ~direction: string=?,
  ~mixins: MixinsOptions.t=?,
  ~overrides: Overrides.t=?,
  ~palette: PaletteOptions.t=?,
  ~props: Any.t=?,
  ~shadows: array<string>=?,
  ~shape: Shape.t=?,
  ~spacing: Any.t=?,
  ~transitions: TransitionsOptions.t=?,
  ~typography: Typography.t=?,
  ~unstable_strictMode: bool=?,
  ~zIndex: ZIndex.t=?,
  unit,
) => t = ""
