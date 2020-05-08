module BreakpointValues = {
  type t = {
    .
    "lg": option(option(float)),
    "md": option(option(float)),
    "sm": option(option(float)),
    "xl": option(option(float)),
    "xs": option(option(float)),
  };
  [@bs.obj]
  external make:
    (
      ~lg: float=?,
      ~md: float=?,
      ~sm: float=?,
      ~xl: float=?,
      ~xs: float=?,
      unit
    ) =>
    t;
};

module Breakpoints = {
  type t = {
    .
    "between": option(option(MaterialUi_Types.any)),
    "down": option(option(MaterialUi_Types.any)),
    "keys": option(option(array(string))),
    "only": option(option(MaterialUi_Types.any)),
    "step": option(option(float)),
    "unit": option(option(string)),
    "up": option(option(MaterialUi_Types.any)),
    "values": option(option(BreakpointValues.t)),
    "width": option(option(MaterialUi_Types.any)),
  };
  [@bs.obj]
  external make:
    (
      ~between: MaterialUi_Types.any=?,
      ~down: MaterialUi_Types.any=?,
      ~keys: array(string)=?,
      ~only: MaterialUi_Types.any=?,
      ~step: float=?,
      ~unit: string=?,
      ~up: MaterialUi_Types.any=?,
      ~values: BreakpointValues.t=?,
      ~width: MaterialUi_Types.any=?,
      unit
    ) =>
    t;
};

module MixinsOptions = {
  type t = {
    .
    "gutters": option(option(MaterialUi_Types.any)),
    "toolbar": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (~gutters: MaterialUi_Types.any=?, ~toolbar: ReactDOMRe.Style.t=?, unit) =>
    t;
};

module AppBarClassKey = {
  type t = {
    .
    "colorDefault": option(option(string)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "positionAbsolute": option(option(ReactDOMRe.Style.t)),
    "positionFixed": option(option(ReactDOMRe.Style.t)),
    "positionRelative": option(option(ReactDOMRe.Style.t)),
    "positionStatic": option(option(ReactDOMRe.Style.t)),
    "positionSticky": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~colorDefault: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~positionAbsolute: ReactDOMRe.Style.t=?,
      ~positionFixed: ReactDOMRe.Style.t=?,
      ~positionRelative: ReactDOMRe.Style.t=?,
      ~positionStatic: ReactDOMRe.Style.t=?,
      ~positionSticky: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module AvatarClassKey = {
  type t = {
    .
    "circle": option(option(ReactDOMRe.Style.t)),
    "colorDefault": option(option(string)),
    "fallback": option(option(ReactDOMRe.Style.t)),
    "img": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "rounded": option(option(ReactDOMRe.Style.t)),
    "square": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~circle: ReactDOMRe.Style.t=?,
      ~colorDefault: string=?,
      ~fallback: ReactDOMRe.Style.t=?,
      ~img: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~rounded: ReactDOMRe.Style.t=?,
      ~square: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module BackdropClassKey = {
  type t = {
    .
    "invisible": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (~invisible: ReactDOMRe.Style.t=?, ~root: ReactDOMRe.Style.t=?, unit) => t;
};

module BadgeClassKey = {
  type t = {
    .
    "anchorOriginBottomLeftRectangle": option(option(ReactDOMRe.Style.t)),
    "anchorOriginBottomRightCircle": option(option(ReactDOMRe.Style.t)),
    "anchorOriginBottomRightRectangle": option(option(ReactDOMRe.Style.t)),
    "anchorOriginTopLeftCircle": option(option(ReactDOMRe.Style.t)),
    "anchorOriginTopLeftRectangle": option(option(ReactDOMRe.Style.t)),
    "anchorOriginTopRightCircle": option(option(ReactDOMRe.Style.t)),
    "anchorOriginTopRightRectangle": option(option(ReactDOMRe.Style.t)),
    "badge": option(option(ReactDOMRe.Style.t)),
    "colorError": option(option(string)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "dot": option(option(ReactDOMRe.Style.t)),
    "invisible": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~anchorOriginBottomLeftRectangle: ReactDOMRe.Style.t=?,
      ~anchorOriginBottomRightCircle: ReactDOMRe.Style.t=?,
      ~anchorOriginBottomRightRectangle: ReactDOMRe.Style.t=?,
      ~anchorOriginTopLeftCircle: ReactDOMRe.Style.t=?,
      ~anchorOriginTopLeftRectangle: ReactDOMRe.Style.t=?,
      ~anchorOriginTopRightCircle: ReactDOMRe.Style.t=?,
      ~anchorOriginTopRightRectangle: ReactDOMRe.Style.t=?,
      ~badge: ReactDOMRe.Style.t=?,
      ~colorError: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~dot: ReactDOMRe.Style.t=?,
      ~invisible: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module MuiBottomNavigation = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module BottomNavigationActionClassKey = {
  type t = {
    .
    "iconOnly": option(option(ReactDOMRe.Style.t)),
    "label": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "selected": option(option(ReactDOMRe.Style.t)),
    "wrapper": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~iconOnly: ReactDOMRe.Style.t=?,
      ~label: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~selected: ReactDOMRe.Style.t=?,
      ~wrapper: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module BreadcrumbsClassKey = {
  type t = {
    .
    "li": option(option(ReactDOMRe.Style.t)),
    "ol": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "separator": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~li: ReactDOMRe.Style.t=?,
      ~ol: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~separator: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module ButtonClassKey = {
  type t = {
    .
    "colorInherit": option(option(string)),
    "contained": option(option(ReactDOMRe.Style.t)),
    "containedPrimary": option(option(ReactDOMRe.Style.t)),
    "containedSecondary": option(option(ReactDOMRe.Style.t)),
    "containedSizeLarge": option(option(ReactDOMRe.Style.t)),
    "containedSizeSmall": option(option(ReactDOMRe.Style.t)),
    "disableElevation": option(option(ReactDOMRe.Style.t)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "endIcon": option(option(ReactDOMRe.Style.t)),
    "focusVisible": option(option(ReactDOMRe.Style.t)),
    "fullWidth": option(option(ReactDOMRe.Style.t)),
    "iconSizeLarge": option(option(ReactDOMRe.Style.t)),
    "iconSizeMedium": option(option(ReactDOMRe.Style.t)),
    "iconSizeSmall": option(option(ReactDOMRe.Style.t)),
    "label": option(option(ReactDOMRe.Style.t)),
    "outlined": option(option(ReactDOMRe.Style.t)),
    "outlinedPrimary": option(option(ReactDOMRe.Style.t)),
    "outlinedSecondary": option(option(ReactDOMRe.Style.t)),
    "outlinedSizeLarge": option(option(ReactDOMRe.Style.t)),
    "outlinedSizeSmall": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "sizeLarge": option(option(ReactDOMRe.Style.t)),
    "sizeSmall": option(option(ReactDOMRe.Style.t)),
    "startIcon": option(option(ReactDOMRe.Style.t)),
    "text": option(option(ReactDOMRe.Style.t)),
    "textPrimary": option(option(ReactDOMRe.Style.t)),
    "textSecondary": option(option(ReactDOMRe.Style.t)),
    "textSizeLarge": option(option(ReactDOMRe.Style.t)),
    "textSizeSmall": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~colorInherit: string=?,
      ~contained: ReactDOMRe.Style.t=?,
      ~containedPrimary: ReactDOMRe.Style.t=?,
      ~containedSecondary: ReactDOMRe.Style.t=?,
      ~containedSizeLarge: ReactDOMRe.Style.t=?,
      ~containedSizeSmall: ReactDOMRe.Style.t=?,
      ~disableElevation: ReactDOMRe.Style.t=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~endIcon: ReactDOMRe.Style.t=?,
      ~focusVisible: ReactDOMRe.Style.t=?,
      ~fullWidth: ReactDOMRe.Style.t=?,
      ~iconSizeLarge: ReactDOMRe.Style.t=?,
      ~iconSizeMedium: ReactDOMRe.Style.t=?,
      ~iconSizeSmall: ReactDOMRe.Style.t=?,
      ~label: ReactDOMRe.Style.t=?,
      ~outlined: ReactDOMRe.Style.t=?,
      ~outlinedPrimary: ReactDOMRe.Style.t=?,
      ~outlinedSecondary: ReactDOMRe.Style.t=?,
      ~outlinedSizeLarge: ReactDOMRe.Style.t=?,
      ~outlinedSizeSmall: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~sizeLarge: ReactDOMRe.Style.t=?,
      ~sizeSmall: ReactDOMRe.Style.t=?,
      ~startIcon: ReactDOMRe.Style.t=?,
      ~text: ReactDOMRe.Style.t=?,
      ~textPrimary: ReactDOMRe.Style.t=?,
      ~textSecondary: ReactDOMRe.Style.t=?,
      ~textSizeLarge: ReactDOMRe.Style.t=?,
      ~textSizeSmall: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module ButtonBaseClassKey = {
  type t = {
    .
    "disabled": option(option(ReactDOMRe.Style.t)),
    "focusVisible": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~disabled: ReactDOMRe.Style.t=?,
      ~focusVisible: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module ButtonGroupClassKey = {
  type t = {
    .
    "contained": option(option(ReactDOMRe.Style.t)),
    "disableElevation": option(option(ReactDOMRe.Style.t)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "fullWidth": option(option(ReactDOMRe.Style.t)),
    "grouped": option(option(ReactDOMRe.Style.t)),
    "groupedContained": option(option(ReactDOMRe.Style.t)),
    "groupedContainedHorizontal": option(option(ReactDOMRe.Style.t)),
    "groupedContainedPrimary": option(option(ReactDOMRe.Style.t)),
    "groupedContainedSecondary": option(option(ReactDOMRe.Style.t)),
    "groupedContainedVertical": option(option(ReactDOMRe.Style.t)),
    "groupedHorizontal": option(option(ReactDOMRe.Style.t)),
    "groupedOutlined": option(option(ReactDOMRe.Style.t)),
    "groupedOutlinedHorizontal": option(option(ReactDOMRe.Style.t)),
    "groupedOutlinedPrimary": option(option(ReactDOMRe.Style.t)),
    "groupedOutlinedSecondary": option(option(ReactDOMRe.Style.t)),
    "groupedOutlinedVertical": option(option(ReactDOMRe.Style.t)),
    "groupedText": option(option(ReactDOMRe.Style.t)),
    "groupedTextHorizontal": option(option(ReactDOMRe.Style.t)),
    "groupedTextPrimary": option(option(ReactDOMRe.Style.t)),
    "groupedTextSecondary": option(option(ReactDOMRe.Style.t)),
    "groupedTextVertical": option(option(ReactDOMRe.Style.t)),
    "groupedVertical": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "vertical": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~contained: ReactDOMRe.Style.t=?,
      ~disableElevation: ReactDOMRe.Style.t=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~fullWidth: ReactDOMRe.Style.t=?,
      ~grouped: ReactDOMRe.Style.t=?,
      ~groupedContained: ReactDOMRe.Style.t=?,
      ~groupedContainedHorizontal: ReactDOMRe.Style.t=?,
      ~groupedContainedPrimary: ReactDOMRe.Style.t=?,
      ~groupedContainedSecondary: ReactDOMRe.Style.t=?,
      ~groupedContainedVertical: ReactDOMRe.Style.t=?,
      ~groupedHorizontal: ReactDOMRe.Style.t=?,
      ~groupedOutlined: ReactDOMRe.Style.t=?,
      ~groupedOutlinedHorizontal: ReactDOMRe.Style.t=?,
      ~groupedOutlinedPrimary: ReactDOMRe.Style.t=?,
      ~groupedOutlinedSecondary: ReactDOMRe.Style.t=?,
      ~groupedOutlinedVertical: ReactDOMRe.Style.t=?,
      ~groupedText: ReactDOMRe.Style.t=?,
      ~groupedTextHorizontal: ReactDOMRe.Style.t=?,
      ~groupedTextPrimary: ReactDOMRe.Style.t=?,
      ~groupedTextSecondary: ReactDOMRe.Style.t=?,
      ~groupedTextVertical: ReactDOMRe.Style.t=?,
      ~groupedVertical: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~vertical: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module MuiCard = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module CardActionAreaClassKey = {
  type t = {
    .
    "focusHighlight": option(option(ReactDOMRe.Style.t)),
    "focusVisible": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~focusHighlight: ReactDOMRe.Style.t=?,
      ~focusVisible: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module CardActionsClassKey = {
  type t = {
    .
    "root": option(option(ReactDOMRe.Style.t)),
    "spacing": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (~root: ReactDOMRe.Style.t=?, ~spacing: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiCardContent = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module CardHeaderClassKey = {
  type t = {
    .
    "action": option(option(ReactDOMRe.Style.t)),
    "avatar": option(option(ReactDOMRe.Style.t)),
    "content": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "subheader": option(option(ReactDOMRe.Style.t)),
    "title": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~action: ReactDOMRe.Style.t=?,
      ~avatar: ReactDOMRe.Style.t=?,
      ~content: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~subheader: ReactDOMRe.Style.t=?,
      ~title: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module CardMediaClassKey = {
  type t = {
    .
    "media": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (~media: ReactDOMRe.Style.t=?, ~root: ReactDOMRe.Style.t=?, unit) => t;
};

module CheckboxClassKey = {
  type t = {
    .
    "checked": option(option(ReactDOMRe.Style.t)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "indeterminate": option(option(ReactDOMRe.Style.t)),
    "input": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~checked: ReactDOMRe.Style.t=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~indeterminate: ReactDOMRe.Style.t=?,
      ~input: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module ChipClassKey = {
  type t = {
    .
    "avatar": option(option(ReactDOMRe.Style.t)),
    "avatarColorPrimary": option(option(ReactDOMRe.Style.t)),
    "avatarColorSecondary": option(option(ReactDOMRe.Style.t)),
    "avatarSmall": option(option(ReactDOMRe.Style.t)),
    "clickable": option(option(ReactDOMRe.Style.t)),
    "clickableColorPrimary": option(option(ReactDOMRe.Style.t)),
    "clickableColorSecondary": option(option(ReactDOMRe.Style.t)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "deletable": option(option(ReactDOMRe.Style.t)),
    "deletableColorPrimary": option(option(ReactDOMRe.Style.t)),
    "deletableColorSecondary": option(option(ReactDOMRe.Style.t)),
    "deleteIcon": option(option(ReactDOMRe.Style.t)),
    "deleteIconColorPrimary": option(option(ReactDOMRe.Style.t)),
    "deleteIconColorSecondary": option(option(ReactDOMRe.Style.t)),
    "deleteIconOutlinedColorPrimary": option(option(ReactDOMRe.Style.t)),
    "deleteIconOutlinedColorSecondary": option(option(ReactDOMRe.Style.t)),
    "deleteIconSmall": option(option(ReactDOMRe.Style.t)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "icon": option(option(ReactDOMRe.Style.t)),
    "iconColorPrimary": option(option(ReactDOMRe.Style.t)),
    "iconColorSecondary": option(option(ReactDOMRe.Style.t)),
    "iconSmall": option(option(ReactDOMRe.Style.t)),
    "label": option(option(ReactDOMRe.Style.t)),
    "labelSmall": option(option(ReactDOMRe.Style.t)),
    "outlined": option(option(ReactDOMRe.Style.t)),
    "outlinedPrimary": option(option(ReactDOMRe.Style.t)),
    "outlinedSecondary": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "sizeSmall": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~avatar: ReactDOMRe.Style.t=?,
      ~avatarColorPrimary: ReactDOMRe.Style.t=?,
      ~avatarColorSecondary: ReactDOMRe.Style.t=?,
      ~avatarSmall: ReactDOMRe.Style.t=?,
      ~clickable: ReactDOMRe.Style.t=?,
      ~clickableColorPrimary: ReactDOMRe.Style.t=?,
      ~clickableColorSecondary: ReactDOMRe.Style.t=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~deletable: ReactDOMRe.Style.t=?,
      ~deletableColorPrimary: ReactDOMRe.Style.t=?,
      ~deletableColorSecondary: ReactDOMRe.Style.t=?,
      ~deleteIcon: ReactDOMRe.Style.t=?,
      ~deleteIconColorPrimary: ReactDOMRe.Style.t=?,
      ~deleteIconColorSecondary: ReactDOMRe.Style.t=?,
      ~deleteIconOutlinedColorPrimary: ReactDOMRe.Style.t=?,
      ~deleteIconOutlinedColorSecondary: ReactDOMRe.Style.t=?,
      ~deleteIconSmall: ReactDOMRe.Style.t=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~icon: ReactDOMRe.Style.t=?,
      ~iconColorPrimary: ReactDOMRe.Style.t=?,
      ~iconColorSecondary: ReactDOMRe.Style.t=?,
      ~iconSmall: ReactDOMRe.Style.t=?,
      ~label: ReactDOMRe.Style.t=?,
      ~labelSmall: ReactDOMRe.Style.t=?,
      ~outlined: ReactDOMRe.Style.t=?,
      ~outlinedPrimary: ReactDOMRe.Style.t=?,
      ~outlinedSecondary: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~sizeSmall: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module CircularProgressClassKey = {
  type t = {
    .
    "circle": option(option(ReactDOMRe.Style.t)),
    "circleDisableShrink": option(option(ReactDOMRe.Style.t)),
    "circleIndeterminate": option(option(ReactDOMRe.Style.t)),
    "circleStatic": option(option(ReactDOMRe.Style.t)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "indeterminate": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "static": option(option(ReactDOMRe.Style.t)),
    "svg": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~circle: ReactDOMRe.Style.t=?,
      ~circleDisableShrink: ReactDOMRe.Style.t=?,
      ~circleIndeterminate: ReactDOMRe.Style.t=?,
      ~circleStatic: ReactDOMRe.Style.t=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~indeterminate: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~static: ReactDOMRe.Style.t=?,
      ~svg: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module CollapseClassKey = {
  type t = {
    .
    "container": option(option(ReactDOMRe.Style.t)),
    "entered": option(option(ReactDOMRe.Style.t)),
    "hidden": option(option(ReactDOMRe.Style.t)),
    "wrapper": option(option(ReactDOMRe.Style.t)),
    "wrapperInner": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~container: ReactDOMRe.Style.t=?,
      ~entered: ReactDOMRe.Style.t=?,
      ~hidden: ReactDOMRe.Style.t=?,
      ~wrapper: ReactDOMRe.Style.t=?,
      ~wrapperInner: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module ContainerClassKey = {
  type t = {
    .
    "disableGutters": option(option(ReactDOMRe.Style.t)),
    "fixed": option(option(ReactDOMRe.Style.t)),
    "maxWidthLg": option(option(ReactDOMRe.Style.t)),
    "maxWidthMd": option(option(ReactDOMRe.Style.t)),
    "maxWidthSm": option(option(ReactDOMRe.Style.t)),
    "maxWidthXl": option(option(ReactDOMRe.Style.t)),
    "maxWidthXs": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~disableGutters: ReactDOMRe.Style.t=?,
      ~fixed: ReactDOMRe.Style.t=?,
      ~maxWidthLg: ReactDOMRe.Style.t=?,
      ~maxWidthMd: ReactDOMRe.Style.t=?,
      ~maxWidthSm: ReactDOMRe.Style.t=?,
      ~maxWidthXl: ReactDOMRe.Style.t=?,
      ~maxWidthXs: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module Global = {
  type t = {. "@font-face": option(option(MaterialUi_Types.any))};
  [@bs.obj] external make: (~fontFace: MaterialUi_Types.any=?, unit) => t;
};

module MuiCssBaseline = {
  type t = {. "@global": option(option(Global.t))};
  [@bs.obj] external make: (~global: Global.t=?, unit) => t;
};

module DialogClassKey = {
  type t = {
    .
    "container": option(option(ReactDOMRe.Style.t)),
    "paper": option(option(ReactDOMRe.Style.t)),
    "paperFullScreen": option(option(ReactDOMRe.Style.t)),
    "paperFullWidth": option(option(ReactDOMRe.Style.t)),
    "paperScrollBody": option(option(ReactDOMRe.Style.t)),
    "paperScrollPaper": option(option(ReactDOMRe.Style.t)),
    "paperWidthFalse": option(option(ReactDOMRe.Style.t)),
    "paperWidthLg": option(option(ReactDOMRe.Style.t)),
    "paperWidthMd": option(option(ReactDOMRe.Style.t)),
    "paperWidthSm": option(option(ReactDOMRe.Style.t)),
    "paperWidthXl": option(option(ReactDOMRe.Style.t)),
    "paperWidthXs": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "scrollBody": option(option(ReactDOMRe.Style.t)),
    "scrollPaper": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~container: ReactDOMRe.Style.t=?,
      ~paper: ReactDOMRe.Style.t=?,
      ~paperFullScreen: ReactDOMRe.Style.t=?,
      ~paperFullWidth: ReactDOMRe.Style.t=?,
      ~paperScrollBody: ReactDOMRe.Style.t=?,
      ~paperScrollPaper: ReactDOMRe.Style.t=?,
      ~paperWidthFalse: ReactDOMRe.Style.t=?,
      ~paperWidthLg: ReactDOMRe.Style.t=?,
      ~paperWidthMd: ReactDOMRe.Style.t=?,
      ~paperWidthSm: ReactDOMRe.Style.t=?,
      ~paperWidthXl: ReactDOMRe.Style.t=?,
      ~paperWidthXs: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~scrollBody: ReactDOMRe.Style.t=?,
      ~scrollPaper: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module DialogContentClassKey = {
  type t = {
    .
    "dividers": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (~dividers: ReactDOMRe.Style.t=?, ~root: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiDialogContentText = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiDialogTitle = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module DividerClassKey = {
  type t = {
    .
    "absolute": option(option(ReactDOMRe.Style.t)),
    "inset": option(option(ReactDOMRe.Style.t)),
    "light": option(option(ReactDOMRe.Style.t)),
    "middle": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "vertical": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~absolute: ReactDOMRe.Style.t=?,
      ~inset: ReactDOMRe.Style.t=?,
      ~light: ReactDOMRe.Style.t=?,
      ~middle: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~vertical: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module DrawerClassKey = {
  type t = {
    .
    "docked": option(option(ReactDOMRe.Style.t)),
    "modal": option(option(ReactDOMRe.Style.t)),
    "paper": option(option(ReactDOMRe.Style.t)),
    "paperAnchorBottom": option(option(ReactDOMRe.Style.t)),
    "paperAnchorDockedBottom": option(option(ReactDOMRe.Style.t)),
    "paperAnchorDockedLeft": option(option(ReactDOMRe.Style.t)),
    "paperAnchorDockedRight": option(option(ReactDOMRe.Style.t)),
    "paperAnchorDockedTop": option(option(ReactDOMRe.Style.t)),
    "paperAnchorLeft": option(option(ReactDOMRe.Style.t)),
    "paperAnchorRight": option(option(ReactDOMRe.Style.t)),
    "paperAnchorTop": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~docked: ReactDOMRe.Style.t=?,
      ~modal: ReactDOMRe.Style.t=?,
      ~paper: ReactDOMRe.Style.t=?,
      ~paperAnchorBottom: ReactDOMRe.Style.t=?,
      ~paperAnchorDockedBottom: ReactDOMRe.Style.t=?,
      ~paperAnchorDockedLeft: ReactDOMRe.Style.t=?,
      ~paperAnchorDockedRight: ReactDOMRe.Style.t=?,
      ~paperAnchorDockedTop: ReactDOMRe.Style.t=?,
      ~paperAnchorLeft: ReactDOMRe.Style.t=?,
      ~paperAnchorRight: ReactDOMRe.Style.t=?,
      ~paperAnchorTop: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module ExpansionPanelClassKey = {
  type t = {
    .
    "disabled": option(option(ReactDOMRe.Style.t)),
    "expanded": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "rounded": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~disabled: ReactDOMRe.Style.t=?,
      ~expanded: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~rounded: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module MuiExpansionPanelDetails = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module ExpansionPanelSummaryClassKey = {
  type t = {
    .
    "content": option(option(ReactDOMRe.Style.t)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "expandIcon": option(option(ReactDOMRe.Style.t)),
    "expanded": option(option(ReactDOMRe.Style.t)),
    "focused": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~content: ReactDOMRe.Style.t=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~expandIcon: ReactDOMRe.Style.t=?,
      ~expanded: ReactDOMRe.Style.t=?,
      ~focused: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module FabClassKey = {
  type t = {
    .
    "colorInherit": option(option(string)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "extended": option(option(ReactDOMRe.Style.t)),
    "focusVisible": option(option(ReactDOMRe.Style.t)),
    "label": option(option(ReactDOMRe.Style.t)),
    "primary": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "secondary": option(option(ReactDOMRe.Style.t)),
    "sizeMedium": option(option(ReactDOMRe.Style.t)),
    "sizeSmall": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~colorInherit: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~extended: ReactDOMRe.Style.t=?,
      ~focusVisible: ReactDOMRe.Style.t=?,
      ~label: ReactDOMRe.Style.t=?,
      ~primary: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~secondary: ReactDOMRe.Style.t=?,
      ~sizeMedium: ReactDOMRe.Style.t=?,
      ~sizeSmall: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module FilledInputClassKey = {
  type t = {
    .
    "adornedEnd": option(option(ReactDOMRe.Style.t)),
    "adornedStart": option(option(ReactDOMRe.Style.t)),
    "colorSecondary": option(option(string)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "error": option(option(ReactDOMRe.Style.t)),
    "focused": option(option(ReactDOMRe.Style.t)),
    "formControl": option(option(ReactDOMRe.Style.t)),
    "fullWidth": option(option(ReactDOMRe.Style.t)),
    "input": option(option(ReactDOMRe.Style.t)),
    "inputAdornedEnd": option(option(ReactDOMRe.Style.t)),
    "inputAdornedStart": option(option(ReactDOMRe.Style.t)),
    "inputHiddenLabel": option(option(ReactDOMRe.Style.t)),
    "inputMarginDense": option(option(ReactDOMRe.Style.t)),
    "inputMultiline": option(option(ReactDOMRe.Style.t)),
    "inputTypeSearch": option(option(ReactDOMRe.Style.t)),
    "marginDense": option(option(ReactDOMRe.Style.t)),
    "multiline": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "underline": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~adornedEnd: ReactDOMRe.Style.t=?,
      ~adornedStart: ReactDOMRe.Style.t=?,
      ~colorSecondary: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~error: ReactDOMRe.Style.t=?,
      ~focused: ReactDOMRe.Style.t=?,
      ~formControl: ReactDOMRe.Style.t=?,
      ~fullWidth: ReactDOMRe.Style.t=?,
      ~input: ReactDOMRe.Style.t=?,
      ~inputAdornedEnd: ReactDOMRe.Style.t=?,
      ~inputAdornedStart: ReactDOMRe.Style.t=?,
      ~inputHiddenLabel: ReactDOMRe.Style.t=?,
      ~inputMarginDense: ReactDOMRe.Style.t=?,
      ~inputMultiline: ReactDOMRe.Style.t=?,
      ~inputTypeSearch: ReactDOMRe.Style.t=?,
      ~marginDense: ReactDOMRe.Style.t=?,
      ~multiline: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~underline: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module FormControlClassKey = {
  type t = {
    .
    "fullWidth": option(option(ReactDOMRe.Style.t)),
    "marginDense": option(option(ReactDOMRe.Style.t)),
    "marginNormal": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~fullWidth: ReactDOMRe.Style.t=?,
      ~marginDense: ReactDOMRe.Style.t=?,
      ~marginNormal: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module FormControlLabelClassKey = {
  type t = {
    .
    "disabled": option(option(ReactDOMRe.Style.t)),
    "label": option(option(ReactDOMRe.Style.t)),
    "labelPlacementBottom": option(option(ReactDOMRe.Style.t)),
    "labelPlacementStart": option(option(ReactDOMRe.Style.t)),
    "labelPlacementTop": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~disabled: ReactDOMRe.Style.t=?,
      ~label: ReactDOMRe.Style.t=?,
      ~labelPlacementBottom: ReactDOMRe.Style.t=?,
      ~labelPlacementStart: ReactDOMRe.Style.t=?,
      ~labelPlacementTop: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module FormGroupClassKey = {
  type t = {
    .
    "root": option(option(ReactDOMRe.Style.t)),
    "row": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (~root: ReactDOMRe.Style.t=?, ~row: ReactDOMRe.Style.t=?, unit) => t;
};

module FormHelperTextClassKey = {
  type t = {
    .
    "contained": option(option(ReactDOMRe.Style.t)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "error": option(option(ReactDOMRe.Style.t)),
    "filled": option(option(ReactDOMRe.Style.t)),
    "focused": option(option(ReactDOMRe.Style.t)),
    "marginDense": option(option(ReactDOMRe.Style.t)),
    "required": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~contained: ReactDOMRe.Style.t=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~error: ReactDOMRe.Style.t=?,
      ~filled: ReactDOMRe.Style.t=?,
      ~focused: ReactDOMRe.Style.t=?,
      ~marginDense: ReactDOMRe.Style.t=?,
      ~required: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module FormLabelClassKey = {
  type t = {
    .
    "asterisk": option(option(ReactDOMRe.Style.t)),
    "colorSecondary": option(option(string)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "error": option(option(ReactDOMRe.Style.t)),
    "filled": option(option(ReactDOMRe.Style.t)),
    "focused": option(option(ReactDOMRe.Style.t)),
    "required": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~asterisk: ReactDOMRe.Style.t=?,
      ~colorSecondary: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~error: ReactDOMRe.Style.t=?,
      ~filled: ReactDOMRe.Style.t=?,
      ~focused: ReactDOMRe.Style.t=?,
      ~required: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module GridClassKey = {
  type t = {
    .
    "align-content-xs-center": option(option(ReactDOMRe.Style.t)),
    "align-content-xs-flex-end": option(option(ReactDOMRe.Style.t)),
    "align-content-xs-flex-start": option(option(ReactDOMRe.Style.t)),
    "align-content-xs-space-around": option(option(ReactDOMRe.Style.t)),
    "align-content-xs-space-between": option(option(ReactDOMRe.Style.t)),
    "align-items-xs-baseline": option(option(ReactDOMRe.Style.t)),
    "align-items-xs-center": option(option(ReactDOMRe.Style.t)),
    "align-items-xs-flex-end": option(option(ReactDOMRe.Style.t)),
    "align-items-xs-flex-start": option(option(ReactDOMRe.Style.t)),
    "container": option(option(ReactDOMRe.Style.t)),
    "direction-xs-column": option(option(ReactDOMRe.Style.t)),
    "direction-xs-column-reverse": option(option(ReactDOMRe.Style.t)),
    "direction-xs-row-reverse": option(option(ReactDOMRe.Style.t)),
    "grid-xs-1": option(option(ReactDOMRe.Style.t)),
    "grid-xs-10": option(option(ReactDOMRe.Style.t)),
    "grid-xs-11": option(option(ReactDOMRe.Style.t)),
    "grid-xs-12": option(option(ReactDOMRe.Style.t)),
    "grid-xs-2": option(option(ReactDOMRe.Style.t)),
    "grid-xs-3": option(option(ReactDOMRe.Style.t)),
    "grid-xs-4": option(option(ReactDOMRe.Style.t)),
    "grid-xs-5": option(option(ReactDOMRe.Style.t)),
    "grid-xs-6": option(option(ReactDOMRe.Style.t)),
    "grid-xs-7": option(option(ReactDOMRe.Style.t)),
    "grid-xs-8": option(option(ReactDOMRe.Style.t)),
    "grid-xs-9": option(option(ReactDOMRe.Style.t)),
    "grid-xs-auto": option(option(ReactDOMRe.Style.t)),
    "grid-xs-true": option(option(ReactDOMRe.Style.t)),
    "item": option(option(ReactDOMRe.Style.t)),
    "justify-xs-center": option(option(ReactDOMRe.Style.t)),
    "justify-xs-flex-end": option(option(ReactDOMRe.Style.t)),
    "justify-xs-space-around": option(option(ReactDOMRe.Style.t)),
    "justify-xs-space-between": option(option(ReactDOMRe.Style.t)),
    "justify-xs-space-evenly": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "spacing-xs-1": option(option(ReactDOMRe.Style.t)),
    "spacing-xs-10": option(option(ReactDOMRe.Style.t)),
    "spacing-xs-2": option(option(ReactDOMRe.Style.t)),
    "spacing-xs-3": option(option(ReactDOMRe.Style.t)),
    "spacing-xs-4": option(option(ReactDOMRe.Style.t)),
    "spacing-xs-5": option(option(ReactDOMRe.Style.t)),
    "spacing-xs-6": option(option(ReactDOMRe.Style.t)),
    "spacing-xs-7": option(option(ReactDOMRe.Style.t)),
    "spacing-xs-8": option(option(ReactDOMRe.Style.t)),
    "spacing-xs-9": option(option(ReactDOMRe.Style.t)),
    "wrap-xs-nowrap": option(option(ReactDOMRe.Style.t)),
    "wrap-xs-wrap-reverse": option(option(ReactDOMRe.Style.t)),
    "zeroMinWidth": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~alignContentXsCenter: ReactDOMRe.Style.t=?,
      ~alignContentXsFlexEnd: ReactDOMRe.Style.t=?,
      ~alignContentXsFlexStart: ReactDOMRe.Style.t=?,
      ~alignContentXsSpaceAround: ReactDOMRe.Style.t=?,
      ~alignContentXsSpaceBetween: ReactDOMRe.Style.t=?,
      ~alignItemsXsBaseline: ReactDOMRe.Style.t=?,
      ~alignItemsXsCenter: ReactDOMRe.Style.t=?,
      ~alignItemsXsFlexEnd: ReactDOMRe.Style.t=?,
      ~alignItemsXsFlexStart: ReactDOMRe.Style.t=?,
      ~container: ReactDOMRe.Style.t=?,
      ~directionXsColumn: ReactDOMRe.Style.t=?,
      ~directionXsColumnReverse: ReactDOMRe.Style.t=?,
      ~directionXsRowReverse: ReactDOMRe.Style.t=?,
      ~gridXs1: ReactDOMRe.Style.t=?,
      ~gridXs10: ReactDOMRe.Style.t=?,
      ~gridXs11: ReactDOMRe.Style.t=?,
      ~gridXs12: ReactDOMRe.Style.t=?,
      ~gridXs2: ReactDOMRe.Style.t=?,
      ~gridXs3: ReactDOMRe.Style.t=?,
      ~gridXs4: ReactDOMRe.Style.t=?,
      ~gridXs5: ReactDOMRe.Style.t=?,
      ~gridXs6: ReactDOMRe.Style.t=?,
      ~gridXs7: ReactDOMRe.Style.t=?,
      ~gridXs8: ReactDOMRe.Style.t=?,
      ~gridXs9: ReactDOMRe.Style.t=?,
      ~gridXsAuto: ReactDOMRe.Style.t=?,
      ~gridXsTrue: ReactDOMRe.Style.t=?,
      ~item: ReactDOMRe.Style.t=?,
      ~justifyXsCenter: ReactDOMRe.Style.t=?,
      ~justifyXsFlexEnd: ReactDOMRe.Style.t=?,
      ~justifyXsSpaceAround: ReactDOMRe.Style.t=?,
      ~justifyXsSpaceBetween: ReactDOMRe.Style.t=?,
      ~justifyXsSpaceEvenly: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~spacingXs1: ReactDOMRe.Style.t=?,
      ~spacingXs10: ReactDOMRe.Style.t=?,
      ~spacingXs2: ReactDOMRe.Style.t=?,
      ~spacingXs3: ReactDOMRe.Style.t=?,
      ~spacingXs4: ReactDOMRe.Style.t=?,
      ~spacingXs5: ReactDOMRe.Style.t=?,
      ~spacingXs6: ReactDOMRe.Style.t=?,
      ~spacingXs7: ReactDOMRe.Style.t=?,
      ~spacingXs8: ReactDOMRe.Style.t=?,
      ~spacingXs9: ReactDOMRe.Style.t=?,
      ~wrapXsNowrap: ReactDOMRe.Style.t=?,
      ~wrapXsWrapReverse: ReactDOMRe.Style.t=?,
      ~zeroMinWidth: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module MuiGridList = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module GridListTileClassKey = {
  type t = {
    .
    "imgFullHeight": option(option(ReactDOMRe.Style.t)),
    "imgFullWidth": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "tile": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~imgFullHeight: ReactDOMRe.Style.t=?,
      ~imgFullWidth: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~tile: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module GridListTileBarClassKey = {
  type t = {
    .
    "actionIcon": option(option(ReactDOMRe.Style.t)),
    "actionIconActionPosLeft": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "rootSubtitle": option(option(ReactDOMRe.Style.t)),
    "subtitle": option(option(ReactDOMRe.Style.t)),
    "title": option(option(ReactDOMRe.Style.t)),
    "titlePositionBottom": option(option(ReactDOMRe.Style.t)),
    "titlePositionTop": option(option(ReactDOMRe.Style.t)),
    "titleWrap": option(option(ReactDOMRe.Style.t)),
    "titleWrapActionPosLeft": option(option(ReactDOMRe.Style.t)),
    "titleWrapActionPosRight": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~actionIcon: ReactDOMRe.Style.t=?,
      ~actionIconActionPosLeft: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~rootSubtitle: ReactDOMRe.Style.t=?,
      ~subtitle: ReactDOMRe.Style.t=?,
      ~title: ReactDOMRe.Style.t=?,
      ~titlePositionBottom: ReactDOMRe.Style.t=?,
      ~titlePositionTop: ReactDOMRe.Style.t=?,
      ~titleWrap: ReactDOMRe.Style.t=?,
      ~titleWrapActionPosLeft: ReactDOMRe.Style.t=?,
      ~titleWrapActionPosRight: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module SvgIconClassKey = {
  type t = {
    .
    "colorAction": option(option(string)),
    "colorDisabled": option(option(string)),
    "colorError": option(option(string)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "fontSizeInherit": option(option(float)),
    "fontSizeLarge": option(option(float)),
    "fontSizeSmall": option(option(float)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~colorAction: string=?,
      ~colorDisabled: string=?,
      ~colorError: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~fontSizeInherit: float=?,
      ~fontSizeLarge: float=?,
      ~fontSizeSmall: float=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module IconButtonClassKey = {
  type t = {
    .
    "colorInherit": option(option(string)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "edgeEnd": option(option(ReactDOMRe.Style.t)),
    "edgeStart": option(option(ReactDOMRe.Style.t)),
    "label": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "sizeSmall": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~colorInherit: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~edgeEnd: ReactDOMRe.Style.t=?,
      ~edgeStart: ReactDOMRe.Style.t=?,
      ~label: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~sizeSmall: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module InputClassKey = {
  type t = {
    .
    "colorSecondary": option(option(string)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "error": option(option(ReactDOMRe.Style.t)),
    "focused": option(option(ReactDOMRe.Style.t)),
    "formControl": option(option(ReactDOMRe.Style.t)),
    "fullWidth": option(option(ReactDOMRe.Style.t)),
    "input": option(option(ReactDOMRe.Style.t)),
    "inputMarginDense": option(option(ReactDOMRe.Style.t)),
    "inputMultiline": option(option(ReactDOMRe.Style.t)),
    "inputTypeSearch": option(option(ReactDOMRe.Style.t)),
    "marginDense": option(option(ReactDOMRe.Style.t)),
    "multiline": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "underline": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~colorSecondary: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~error: ReactDOMRe.Style.t=?,
      ~focused: ReactDOMRe.Style.t=?,
      ~formControl: ReactDOMRe.Style.t=?,
      ~fullWidth: ReactDOMRe.Style.t=?,
      ~input: ReactDOMRe.Style.t=?,
      ~inputMarginDense: ReactDOMRe.Style.t=?,
      ~inputMultiline: ReactDOMRe.Style.t=?,
      ~inputTypeSearch: ReactDOMRe.Style.t=?,
      ~marginDense: ReactDOMRe.Style.t=?,
      ~multiline: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~underline: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module InputAdornmentClassKey = {
  type t = {
    .
    "disablePointerEvents": option(option(ReactDOMRe.Style.t)),
    "filled": option(option(ReactDOMRe.Style.t)),
    "hiddenLabel": option(option(ReactDOMRe.Style.t)),
    "marginDense": option(option(ReactDOMRe.Style.t)),
    "positionEnd": option(option(ReactDOMRe.Style.t)),
    "positionStart": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~disablePointerEvents: ReactDOMRe.Style.t=?,
      ~filled: ReactDOMRe.Style.t=?,
      ~hiddenLabel: ReactDOMRe.Style.t=?,
      ~marginDense: ReactDOMRe.Style.t=?,
      ~positionEnd: ReactDOMRe.Style.t=?,
      ~positionStart: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module InputBaseClassKey = {
  type t = {
    .
    "adornedEnd": option(option(ReactDOMRe.Style.t)),
    "adornedStart": option(option(ReactDOMRe.Style.t)),
    "colorSecondary": option(option(string)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "error": option(option(ReactDOMRe.Style.t)),
    "focused": option(option(ReactDOMRe.Style.t)),
    "formControl": option(option(ReactDOMRe.Style.t)),
    "fullWidth": option(option(ReactDOMRe.Style.t)),
    "input": option(option(ReactDOMRe.Style.t)),
    "inputAdornedEnd": option(option(ReactDOMRe.Style.t)),
    "inputAdornedStart": option(option(ReactDOMRe.Style.t)),
    "inputHiddenLabel": option(option(ReactDOMRe.Style.t)),
    "inputMarginDense": option(option(ReactDOMRe.Style.t)),
    "inputMultiline": option(option(ReactDOMRe.Style.t)),
    "inputTypeSearch": option(option(ReactDOMRe.Style.t)),
    "marginDense": option(option(ReactDOMRe.Style.t)),
    "multiline": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~adornedEnd: ReactDOMRe.Style.t=?,
      ~adornedStart: ReactDOMRe.Style.t=?,
      ~colorSecondary: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~error: ReactDOMRe.Style.t=?,
      ~focused: ReactDOMRe.Style.t=?,
      ~formControl: ReactDOMRe.Style.t=?,
      ~fullWidth: ReactDOMRe.Style.t=?,
      ~input: ReactDOMRe.Style.t=?,
      ~inputAdornedEnd: ReactDOMRe.Style.t=?,
      ~inputAdornedStart: ReactDOMRe.Style.t=?,
      ~inputHiddenLabel: ReactDOMRe.Style.t=?,
      ~inputMarginDense: ReactDOMRe.Style.t=?,
      ~inputMultiline: ReactDOMRe.Style.t=?,
      ~inputTypeSearch: ReactDOMRe.Style.t=?,
      ~marginDense: ReactDOMRe.Style.t=?,
      ~multiline: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module InputLabelClassKey = {
  type t = {
    .
    "animated": option(option(ReactDOMRe.Style.t)),
    "asterisk": option(option(ReactDOMRe.Style.t)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "error": option(option(ReactDOMRe.Style.t)),
    "filled": option(option(ReactDOMRe.Style.t)),
    "focused": option(option(ReactDOMRe.Style.t)),
    "formControl": option(option(ReactDOMRe.Style.t)),
    "marginDense": option(option(ReactDOMRe.Style.t)),
    "outlined": option(option(ReactDOMRe.Style.t)),
    "required": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "shrink": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~animated: ReactDOMRe.Style.t=?,
      ~asterisk: ReactDOMRe.Style.t=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~error: ReactDOMRe.Style.t=?,
      ~filled: ReactDOMRe.Style.t=?,
      ~focused: ReactDOMRe.Style.t=?,
      ~formControl: ReactDOMRe.Style.t=?,
      ~marginDense: ReactDOMRe.Style.t=?,
      ~outlined: ReactDOMRe.Style.t=?,
      ~required: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~shrink: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module LinearProgressClassKey = {
  type t = {
    .
    "bar": option(option(ReactDOMRe.Style.t)),
    "bar1Buffer": option(option(ReactDOMRe.Style.t)),
    "bar1Determinate": option(option(ReactDOMRe.Style.t)),
    "bar1Indeterminate": option(option(ReactDOMRe.Style.t)),
    "bar2Buffer": option(option(ReactDOMRe.Style.t)),
    "bar2Indeterminate": option(option(ReactDOMRe.Style.t)),
    "barColorPrimary": option(option(ReactDOMRe.Style.t)),
    "barColorSecondary": option(option(ReactDOMRe.Style.t)),
    "buffer": option(option(ReactDOMRe.Style.t)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "dashed": option(option(ReactDOMRe.Style.t)),
    "dashedColorPrimary": option(option(ReactDOMRe.Style.t)),
    "dashedColorSecondary": option(option(ReactDOMRe.Style.t)),
    "determinate": option(option(ReactDOMRe.Style.t)),
    "indeterminate": option(option(ReactDOMRe.Style.t)),
    "query": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~bar: ReactDOMRe.Style.t=?,
      ~bar1Buffer: ReactDOMRe.Style.t=?,
      ~bar1Determinate: ReactDOMRe.Style.t=?,
      ~bar1Indeterminate: ReactDOMRe.Style.t=?,
      ~bar2Buffer: ReactDOMRe.Style.t=?,
      ~bar2Indeterminate: ReactDOMRe.Style.t=?,
      ~barColorPrimary: ReactDOMRe.Style.t=?,
      ~barColorSecondary: ReactDOMRe.Style.t=?,
      ~buffer: ReactDOMRe.Style.t=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~dashed: ReactDOMRe.Style.t=?,
      ~dashedColorPrimary: ReactDOMRe.Style.t=?,
      ~dashedColorSecondary: ReactDOMRe.Style.t=?,
      ~determinate: ReactDOMRe.Style.t=?,
      ~indeterminate: ReactDOMRe.Style.t=?,
      ~query: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module LinkClassKey = {
  type t = {
    .
    "button": option(option(ReactDOMRe.Style.t)),
    "focusVisible": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "underlineAlways": option(option(ReactDOMRe.Style.t)),
    "underlineHover": option(option(ReactDOMRe.Style.t)),
    "underlineNone": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~button: ReactDOMRe.Style.t=?,
      ~focusVisible: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~underlineAlways: ReactDOMRe.Style.t=?,
      ~underlineHover: ReactDOMRe.Style.t=?,
      ~underlineNone: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module ListClassKey = {
  type t = {
    .
    "dense": option(option(ReactDOMRe.Style.t)),
    "padding": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "subheader": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~dense: ReactDOMRe.Style.t=?,
      ~padding: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~subheader: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module ListItemClassKey = {
  type t = {
    .
    "button": option(option(ReactDOMRe.Style.t)),
    "container": option(option(ReactDOMRe.Style.t)),
    "default": option(option(ReactDOMRe.Style.t)),
    "dense": option(option(ReactDOMRe.Style.t)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "divider": option(option(ReactDOMRe.Style.t)),
    "focusVisible": option(option(ReactDOMRe.Style.t)),
    "gutters": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "secondaryAction": option(option(ReactDOMRe.Style.t)),
    "selected": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~button: ReactDOMRe.Style.t=?,
      ~container: ReactDOMRe.Style.t=?,
      ~default: ReactDOMRe.Style.t=?,
      ~dense: ReactDOMRe.Style.t=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~divider: ReactDOMRe.Style.t=?,
      ~focusVisible: ReactDOMRe.Style.t=?,
      ~gutters: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~secondaryAction: ReactDOMRe.Style.t=?,
      ~selected: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module ListItemAvatarClassKey = {
  type t = {
    .
    "icon": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (~icon: ReactDOMRe.Style.t=?, ~root: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiListItemIcon = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiListItemSecondaryAction = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module ListItemTextClassKey = {
  type t = {
    .
    "dense": option(option(ReactDOMRe.Style.t)),
    "inset": option(option(ReactDOMRe.Style.t)),
    "multiline": option(option(ReactDOMRe.Style.t)),
    "primary": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "secondary": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~dense: ReactDOMRe.Style.t=?,
      ~inset: ReactDOMRe.Style.t=?,
      ~multiline: ReactDOMRe.Style.t=?,
      ~primary: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~secondary: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module ListSubheaderClassKey = {
  type t = {
    .
    "colorInherit": option(option(string)),
    "colorPrimary": option(option(string)),
    "gutters": option(option(ReactDOMRe.Style.t)),
    "inset": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "sticky": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~colorInherit: string=?,
      ~colorPrimary: string=?,
      ~gutters: ReactDOMRe.Style.t=?,
      ~inset: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~sticky: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module MenuClassKey = {
  type t = {
    .
    "list": option(option(ReactDOMRe.Style.t)),
    "paper": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (~list: ReactDOMRe.Style.t=?, ~paper: ReactDOMRe.Style.t=?, unit) => t;
};

module MenuItemClassKey = {
  type t = {
    .
    "dense": option(option(ReactDOMRe.Style.t)),
    "gutters": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "selected": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~dense: ReactDOMRe.Style.t=?,
      ~gutters: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~selected: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module MobileStepperClassKey = {
  type t = {
    .
    "dot": option(option(ReactDOMRe.Style.t)),
    "dotActive": option(option(ReactDOMRe.Style.t)),
    "dots": option(option(ReactDOMRe.Style.t)),
    "positionBottom": option(option(ReactDOMRe.Style.t)),
    "positionStatic": option(option(ReactDOMRe.Style.t)),
    "positionTop": option(option(ReactDOMRe.Style.t)),
    "progress": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~dot: ReactDOMRe.Style.t=?,
      ~dotActive: ReactDOMRe.Style.t=?,
      ~dots: ReactDOMRe.Style.t=?,
      ~positionBottom: ReactDOMRe.Style.t=?,
      ~positionStatic: ReactDOMRe.Style.t=?,
      ~positionTop: ReactDOMRe.Style.t=?,
      ~progress: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module NativeSelectClassKey = {
  type t = {
    .
    "disabled": option(option(ReactDOMRe.Style.t)),
    "filled": option(option(ReactDOMRe.Style.t)),
    "icon": option(option(ReactDOMRe.Style.t)),
    "iconFilled": option(option(ReactDOMRe.Style.t)),
    "iconOutlined": option(option(ReactDOMRe.Style.t)),
    "outlined": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "select": option(option(ReactDOMRe.Style.t)),
    "selectMenu": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~disabled: ReactDOMRe.Style.t=?,
      ~filled: ReactDOMRe.Style.t=?,
      ~icon: ReactDOMRe.Style.t=?,
      ~iconFilled: ReactDOMRe.Style.t=?,
      ~iconOutlined: ReactDOMRe.Style.t=?,
      ~outlined: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~select: ReactDOMRe.Style.t=?,
      ~selectMenu: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module OutlinedInputClassKey = {
  type t = {
    .
    "adornedEnd": option(option(ReactDOMRe.Style.t)),
    "adornedStart": option(option(ReactDOMRe.Style.t)),
    "colorSecondary": option(option(string)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "error": option(option(ReactDOMRe.Style.t)),
    "focused": option(option(ReactDOMRe.Style.t)),
    "input": option(option(ReactDOMRe.Style.t)),
    "inputAdornedEnd": option(option(ReactDOMRe.Style.t)),
    "inputAdornedStart": option(option(ReactDOMRe.Style.t)),
    "inputMarginDense": option(option(ReactDOMRe.Style.t)),
    "inputMultiline": option(option(ReactDOMRe.Style.t)),
    "marginDense": option(option(ReactDOMRe.Style.t)),
    "multiline": option(option(ReactDOMRe.Style.t)),
    "notchedOutline": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~adornedEnd: ReactDOMRe.Style.t=?,
      ~adornedStart: ReactDOMRe.Style.t=?,
      ~colorSecondary: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~error: ReactDOMRe.Style.t=?,
      ~focused: ReactDOMRe.Style.t=?,
      ~input: ReactDOMRe.Style.t=?,
      ~inputAdornedEnd: ReactDOMRe.Style.t=?,
      ~inputAdornedStart: ReactDOMRe.Style.t=?,
      ~inputMarginDense: ReactDOMRe.Style.t=?,
      ~inputMultiline: ReactDOMRe.Style.t=?,
      ~marginDense: ReactDOMRe.Style.t=?,
      ~multiline: ReactDOMRe.Style.t=?,
      ~notchedOutline: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module PaperClassKey = {
  type t = {
    .
    "elevation0": option(option(ReactDOMRe.Style.t)),
    "elevation1": option(option(ReactDOMRe.Style.t)),
    "elevation10": option(option(ReactDOMRe.Style.t)),
    "elevation11": option(option(ReactDOMRe.Style.t)),
    "elevation12": option(option(ReactDOMRe.Style.t)),
    "elevation13": option(option(ReactDOMRe.Style.t)),
    "elevation14": option(option(ReactDOMRe.Style.t)),
    "elevation15": option(option(ReactDOMRe.Style.t)),
    "elevation16": option(option(ReactDOMRe.Style.t)),
    "elevation17": option(option(ReactDOMRe.Style.t)),
    "elevation18": option(option(ReactDOMRe.Style.t)),
    "elevation19": option(option(ReactDOMRe.Style.t)),
    "elevation2": option(option(ReactDOMRe.Style.t)),
    "elevation20": option(option(ReactDOMRe.Style.t)),
    "elevation21": option(option(ReactDOMRe.Style.t)),
    "elevation22": option(option(ReactDOMRe.Style.t)),
    "elevation23": option(option(ReactDOMRe.Style.t)),
    "elevation24": option(option(ReactDOMRe.Style.t)),
    "elevation3": option(option(ReactDOMRe.Style.t)),
    "elevation4": option(option(ReactDOMRe.Style.t)),
    "elevation5": option(option(ReactDOMRe.Style.t)),
    "elevation6": option(option(ReactDOMRe.Style.t)),
    "elevation7": option(option(ReactDOMRe.Style.t)),
    "elevation8": option(option(ReactDOMRe.Style.t)),
    "elevation9": option(option(ReactDOMRe.Style.t)),
    "outlined": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "rounded": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~elevation0: ReactDOMRe.Style.t=?,
      ~elevation1: ReactDOMRe.Style.t=?,
      ~elevation10: ReactDOMRe.Style.t=?,
      ~elevation11: ReactDOMRe.Style.t=?,
      ~elevation12: ReactDOMRe.Style.t=?,
      ~elevation13: ReactDOMRe.Style.t=?,
      ~elevation14: ReactDOMRe.Style.t=?,
      ~elevation15: ReactDOMRe.Style.t=?,
      ~elevation16: ReactDOMRe.Style.t=?,
      ~elevation17: ReactDOMRe.Style.t=?,
      ~elevation18: ReactDOMRe.Style.t=?,
      ~elevation19: ReactDOMRe.Style.t=?,
      ~elevation2: ReactDOMRe.Style.t=?,
      ~elevation20: ReactDOMRe.Style.t=?,
      ~elevation21: ReactDOMRe.Style.t=?,
      ~elevation22: ReactDOMRe.Style.t=?,
      ~elevation23: ReactDOMRe.Style.t=?,
      ~elevation24: ReactDOMRe.Style.t=?,
      ~elevation3: ReactDOMRe.Style.t=?,
      ~elevation4: ReactDOMRe.Style.t=?,
      ~elevation5: ReactDOMRe.Style.t=?,
      ~elevation6: ReactDOMRe.Style.t=?,
      ~elevation7: ReactDOMRe.Style.t=?,
      ~elevation8: ReactDOMRe.Style.t=?,
      ~elevation9: ReactDOMRe.Style.t=?,
      ~outlined: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~rounded: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module PopoverClassKey = {
  type t = {
    .
    "paper": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (~paper: ReactDOMRe.Style.t=?, ~root: ReactDOMRe.Style.t=?, unit) => t;
};

module RadioClassKey = {
  type t = {
    .
    "checked": option(option(ReactDOMRe.Style.t)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "input": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~checked: ReactDOMRe.Style.t=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~input: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module MuiScopedCssBaseline = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module SelectClassKey = {
  type t = {
    .
    "disabled": option(option(ReactDOMRe.Style.t)),
    "filled": option(option(ReactDOMRe.Style.t)),
    "icon": option(option(ReactDOMRe.Style.t)),
    "iconFilled": option(option(ReactDOMRe.Style.t)),
    "iconOpen": option(option(ReactDOMRe.Style.t)),
    "iconOutlined": option(option(ReactDOMRe.Style.t)),
    "outlined": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "select": option(option(ReactDOMRe.Style.t)),
    "selectMenu": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~disabled: ReactDOMRe.Style.t=?,
      ~filled: ReactDOMRe.Style.t=?,
      ~icon: ReactDOMRe.Style.t=?,
      ~iconFilled: ReactDOMRe.Style.t=?,
      ~iconOpen: ReactDOMRe.Style.t=?,
      ~iconOutlined: ReactDOMRe.Style.t=?,
      ~outlined: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~select: ReactDOMRe.Style.t=?,
      ~selectMenu: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module SliderClassKey = {
  type t = {
    .
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "mark": option(option(ReactDOMRe.Style.t)),
    "markActive": option(option(ReactDOMRe.Style.t)),
    "markLabel": option(option(ReactDOMRe.Style.t)),
    "markLabelActive": option(option(ReactDOMRe.Style.t)),
    "marked": option(option(ReactDOMRe.Style.t)),
    "rail": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "rtl": option(option(ReactDOMRe.Style.t)),
    "thumb": option(option(ReactDOMRe.Style.t)),
    "thumbColorPrimary": option(option(ReactDOMRe.Style.t)),
    "thumbColorSecondary": option(option(ReactDOMRe.Style.t)),
    "track": option(option(ReactDOMRe.Style.t)),
    "trackFalse": option(option(ReactDOMRe.Style.t)),
    "trackInverted": option(option(ReactDOMRe.Style.t)),
    "valueLabel": option(option(ReactDOMRe.Style.t)),
    "vertical": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~mark: ReactDOMRe.Style.t=?,
      ~markActive: ReactDOMRe.Style.t=?,
      ~markLabel: ReactDOMRe.Style.t=?,
      ~markLabelActive: ReactDOMRe.Style.t=?,
      ~marked: ReactDOMRe.Style.t=?,
      ~rail: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~rtl: ReactDOMRe.Style.t=?,
      ~thumb: ReactDOMRe.Style.t=?,
      ~thumbColorPrimary: ReactDOMRe.Style.t=?,
      ~thumbColorSecondary: ReactDOMRe.Style.t=?,
      ~track: ReactDOMRe.Style.t=?,
      ~trackFalse: ReactDOMRe.Style.t=?,
      ~trackInverted: ReactDOMRe.Style.t=?,
      ~valueLabel: ReactDOMRe.Style.t=?,
      ~vertical: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module SnackbarClassKey = {
  type t = {
    .
    "anchorOriginBottomCenter": option(option(ReactDOMRe.Style.t)),
    "anchorOriginBottomLeft": option(option(ReactDOMRe.Style.t)),
    "anchorOriginBottomRight": option(option(ReactDOMRe.Style.t)),
    "anchorOriginTopCenter": option(option(ReactDOMRe.Style.t)),
    "anchorOriginTopLeft": option(option(ReactDOMRe.Style.t)),
    "anchorOriginTopRight": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~anchorOriginBottomCenter: ReactDOMRe.Style.t=?,
      ~anchorOriginBottomLeft: ReactDOMRe.Style.t=?,
      ~anchorOriginBottomRight: ReactDOMRe.Style.t=?,
      ~anchorOriginTopCenter: ReactDOMRe.Style.t=?,
      ~anchorOriginTopLeft: ReactDOMRe.Style.t=?,
      ~anchorOriginTopRight: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module SnackbarContentClassKey = {
  type t = {
    .
    "action": option(option(ReactDOMRe.Style.t)),
    "message": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~action: ReactDOMRe.Style.t=?,
      ~message: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module StepClasskey = {
  type t = {
    .
    "alternativeLabel": option(option(ReactDOMRe.Style.t)),
    "completed": option(option(ReactDOMRe.Style.t)),
    "horizontal": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "vertical": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~alternativeLabel: ReactDOMRe.Style.t=?,
      ~completed: ReactDOMRe.Style.t=?,
      ~horizontal: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~vertical: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module StepButtonClasskey = {
  type t = {
    .
    "root": option(option(ReactDOMRe.Style.t)),
    "touchRipple": option(option(ReactDOMRe.Style.t)),
    "vertical": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~root: ReactDOMRe.Style.t=?,
      ~touchRipple: ReactDOMRe.Style.t=?,
      ~vertical: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module StepConnectorClasskey = {
  type t = {
    .
    "active": option(option(ReactDOMRe.Style.t)),
    "alternativeLabel": option(option(ReactDOMRe.Style.t)),
    "completed": option(option(ReactDOMRe.Style.t)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "horizontal": option(option(ReactDOMRe.Style.t)),
    "line": option(option(ReactDOMRe.Style.t)),
    "lineHorizontal": option(option(ReactDOMRe.Style.t)),
    "lineVertical": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "vertical": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~active: ReactDOMRe.Style.t=?,
      ~alternativeLabel: ReactDOMRe.Style.t=?,
      ~completed: ReactDOMRe.Style.t=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~horizontal: ReactDOMRe.Style.t=?,
      ~line: ReactDOMRe.Style.t=?,
      ~lineHorizontal: ReactDOMRe.Style.t=?,
      ~lineVertical: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~vertical: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module StepContentClasskey = {
  type t = {
    .
    "last": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "transition": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~last: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~transition: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module StepIconClasskey = {
  type t = {
    .
    "active": option(option(ReactDOMRe.Style.t)),
    "completed": option(option(ReactDOMRe.Style.t)),
    "error": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "text": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~active: ReactDOMRe.Style.t=?,
      ~completed: ReactDOMRe.Style.t=?,
      ~error: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~text: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module StepLabelClasskey = {
  type t = {
    .
    "active": option(option(ReactDOMRe.Style.t)),
    "alternativeLabel": option(option(ReactDOMRe.Style.t)),
    "completed": option(option(ReactDOMRe.Style.t)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "error": option(option(ReactDOMRe.Style.t)),
    "horizontal": option(option(ReactDOMRe.Style.t)),
    "iconContainer": option(option(ReactDOMRe.Style.t)),
    "label": option(option(ReactDOMRe.Style.t)),
    "labelContainer": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "vertical": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~active: ReactDOMRe.Style.t=?,
      ~alternativeLabel: ReactDOMRe.Style.t=?,
      ~completed: ReactDOMRe.Style.t=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~error: ReactDOMRe.Style.t=?,
      ~horizontal: ReactDOMRe.Style.t=?,
      ~iconContainer: ReactDOMRe.Style.t=?,
      ~label: ReactDOMRe.Style.t=?,
      ~labelContainer: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~vertical: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module StepperClasskey = {
  type t = {
    .
    "alternativeLabel": option(option(ReactDOMRe.Style.t)),
    "horizontal": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "vertical": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~alternativeLabel: ReactDOMRe.Style.t=?,
      ~horizontal: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~vertical: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module SwitchClassKey = {
  type t = {
    .
    "checked": option(option(ReactDOMRe.Style.t)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "disabled": option(option(ReactDOMRe.Style.t)),
    "input": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "sizeSmall": option(option(ReactDOMRe.Style.t)),
    "switchBase": option(option(ReactDOMRe.Style.t)),
    "thumb": option(option(ReactDOMRe.Style.t)),
    "track": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~checked: ReactDOMRe.Style.t=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~input: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~sizeSmall: ReactDOMRe.Style.t=?,
      ~switchBase: ReactDOMRe.Style.t=?,
      ~thumb: ReactDOMRe.Style.t=?,
      ~track: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module TabClassKey = {
  type t = {
    .
    "disabled": option(option(ReactDOMRe.Style.t)),
    "fullWidth": option(option(ReactDOMRe.Style.t)),
    "labelIcon": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "selected": option(option(ReactDOMRe.Style.t)),
    "textColorInherit": option(option(ReactDOMRe.Style.t)),
    "textColorPrimary": option(option(ReactDOMRe.Style.t)),
    "textColorSecondary": option(option(ReactDOMRe.Style.t)),
    "wrapped": option(option(ReactDOMRe.Style.t)),
    "wrapper": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~disabled: ReactDOMRe.Style.t=?,
      ~fullWidth: ReactDOMRe.Style.t=?,
      ~labelIcon: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~selected: ReactDOMRe.Style.t=?,
      ~textColorInherit: ReactDOMRe.Style.t=?,
      ~textColorPrimary: ReactDOMRe.Style.t=?,
      ~textColorSecondary: ReactDOMRe.Style.t=?,
      ~wrapped: ReactDOMRe.Style.t=?,
      ~wrapper: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module TableClassKey = {
  type t = {
    .
    "root": option(option(ReactDOMRe.Style.t)),
    "stickyHeader": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (~root: ReactDOMRe.Style.t=?, ~stickyHeader: ReactDOMRe.Style.t=?, unit) =>
    t;
};

module MuiTableBody = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module TableCellClassKey = {
  type t = {
    .
    "alignCenter": option(option(ReactDOMRe.Style.t)),
    "alignJustify": option(option(ReactDOMRe.Style.t)),
    "alignLeft": option(option(ReactDOMRe.Style.t)),
    "alignRight": option(option(ReactDOMRe.Style.t)),
    "body": option(option(ReactDOMRe.Style.t)),
    "footer": option(option(ReactDOMRe.Style.t)),
    "head": option(option(ReactDOMRe.Style.t)),
    "paddingCheckbox": option(option(ReactDOMRe.Style.t)),
    "paddingNone": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "sizeSmall": option(option(ReactDOMRe.Style.t)),
    "stickyHeader": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~alignCenter: ReactDOMRe.Style.t=?,
      ~alignJustify: ReactDOMRe.Style.t=?,
      ~alignLeft: ReactDOMRe.Style.t=?,
      ~alignRight: ReactDOMRe.Style.t=?,
      ~body: ReactDOMRe.Style.t=?,
      ~footer: ReactDOMRe.Style.t=?,
      ~head: ReactDOMRe.Style.t=?,
      ~paddingCheckbox: ReactDOMRe.Style.t=?,
      ~paddingNone: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~sizeSmall: ReactDOMRe.Style.t=?,
      ~stickyHeader: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module MuiTableContainer = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiTableFooter = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiTableHead = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module TablePaginationClassKey = {
  type t = {
    .
    "actions": option(option(ReactDOMRe.Style.t)),
    "caption": option(option(ReactDOMRe.Style.t)),
    "input": option(option(ReactDOMRe.Style.t)),
    "menuItem": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "select": option(option(ReactDOMRe.Style.t)),
    "selectIcon": option(option(ReactDOMRe.Style.t)),
    "selectRoot": option(option(ReactDOMRe.Style.t)),
    "spacer": option(option(ReactDOMRe.Style.t)),
    "toolbar": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~actions: ReactDOMRe.Style.t=?,
      ~caption: ReactDOMRe.Style.t=?,
      ~input: ReactDOMRe.Style.t=?,
      ~menuItem: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~select: ReactDOMRe.Style.t=?,
      ~selectIcon: ReactDOMRe.Style.t=?,
      ~selectRoot: ReactDOMRe.Style.t=?,
      ~spacer: ReactDOMRe.Style.t=?,
      ~toolbar: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module TableRowClassKey = {
  type t = {
    .
    "footer": option(option(ReactDOMRe.Style.t)),
    "head": option(option(ReactDOMRe.Style.t)),
    "hover": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "selected": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~footer: ReactDOMRe.Style.t=?,
      ~head: ReactDOMRe.Style.t=?,
      ~hover: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~selected: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module TableSortLabelClassKey = {
  type t = {
    .
    "active": option(option(ReactDOMRe.Style.t)),
    "icon": option(option(ReactDOMRe.Style.t)),
    "iconDirectionAsc": option(option(ReactDOMRe.Style.t)),
    "iconDirectionDesc": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~active: ReactDOMRe.Style.t=?,
      ~icon: ReactDOMRe.Style.t=?,
      ~iconDirectionAsc: ReactDOMRe.Style.t=?,
      ~iconDirectionDesc: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module TabsClassKey = {
  type t = {
    .
    "centered": option(option(ReactDOMRe.Style.t)),
    "fixed": option(option(ReactDOMRe.Style.t)),
    "flexContainer": option(option(ReactDOMRe.Style.t)),
    "indicator": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "scrollButtons": option(option(ReactDOMRe.Style.t)),
    "scrollButtonsDesktop": option(option(ReactDOMRe.Style.t)),
    "scrollable": option(option(ReactDOMRe.Style.t)),
    "scroller": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~centered: ReactDOMRe.Style.t=?,
      ~fixed: ReactDOMRe.Style.t=?,
      ~flexContainer: ReactDOMRe.Style.t=?,
      ~indicator: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~scrollButtons: ReactDOMRe.Style.t=?,
      ~scrollButtonsDesktop: ReactDOMRe.Style.t=?,
      ~scrollable: ReactDOMRe.Style.t=?,
      ~scroller: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module MuiTextField = {
  type t = {. "root": option(option(ReactDOMRe.Style.t))};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module ToolbarClassKey = {
  type t = {
    .
    "dense": option(option(ReactDOMRe.Style.t)),
    "gutters": option(option(ReactDOMRe.Style.t)),
    "regular": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~dense: ReactDOMRe.Style.t=?,
      ~gutters: ReactDOMRe.Style.t=?,
      ~regular: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module TooltipClassKey = {
  type t = {
    .
    "arrow": option(option(ReactDOMRe.Style.t)),
    "popper": option(option(ReactDOMRe.Style.t)),
    "popperArrow": option(option(ReactDOMRe.Style.t)),
    "popperInteractive": option(option(ReactDOMRe.Style.t)),
    "tooltip": option(option(ReactDOMRe.Style.t)),
    "tooltipArrow": option(option(ReactDOMRe.Style.t)),
    "tooltipPlacementBottom": option(option(ReactDOMRe.Style.t)),
    "tooltipPlacementLeft": option(option(ReactDOMRe.Style.t)),
    "tooltipPlacementRight": option(option(ReactDOMRe.Style.t)),
    "tooltipPlacementTop": option(option(ReactDOMRe.Style.t)),
    "touch": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~arrow: ReactDOMRe.Style.t=?,
      ~popper: ReactDOMRe.Style.t=?,
      ~popperArrow: ReactDOMRe.Style.t=?,
      ~popperInteractive: ReactDOMRe.Style.t=?,
      ~tooltip: ReactDOMRe.Style.t=?,
      ~tooltipArrow: ReactDOMRe.Style.t=?,
      ~tooltipPlacementBottom: ReactDOMRe.Style.t=?,
      ~tooltipPlacementLeft: ReactDOMRe.Style.t=?,
      ~tooltipPlacementRight: ReactDOMRe.Style.t=?,
      ~tooltipPlacementTop: ReactDOMRe.Style.t=?,
      ~touch: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module TouchRippleClassKey = {
  type t = {
    .
    "child": option(option(ReactDOMRe.Style.t)),
    "childLeaving": option(option(ReactDOMRe.Style.t)),
    "childPulsate": option(option(ReactDOMRe.Style.t)),
    "ripple": option(option(ReactDOMRe.Style.t)),
    "ripplePulsate": option(option(ReactDOMRe.Style.t)),
    "rippleVisible": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~child: ReactDOMRe.Style.t=?,
      ~childLeaving: ReactDOMRe.Style.t=?,
      ~childPulsate: ReactDOMRe.Style.t=?,
      ~ripple: ReactDOMRe.Style.t=?,
      ~ripplePulsate: ReactDOMRe.Style.t=?,
      ~rippleVisible: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module TypographyClassKey = {
  type t = {
    .
    "alignCenter": option(option(ReactDOMRe.Style.t)),
    "alignJustify": option(option(ReactDOMRe.Style.t)),
    "alignLeft": option(option(ReactDOMRe.Style.t)),
    "alignRight": option(option(ReactDOMRe.Style.t)),
    "body1": option(option(ReactDOMRe.Style.t)),
    "body2": option(option(ReactDOMRe.Style.t)),
    "button": option(option(ReactDOMRe.Style.t)),
    "caption": option(option(ReactDOMRe.Style.t)),
    "colorError": option(option(string)),
    "colorInherit": option(option(string)),
    "colorPrimary": option(option(string)),
    "colorSecondary": option(option(string)),
    "colorTextPrimary": option(option(string)),
    "colorTextSecondary": option(option(string)),
    "displayBlock": option(option(ReactDOMRe.Style.t)),
    "displayInline": option(option(ReactDOMRe.Style.t)),
    "gutterBottom": option(option(ReactDOMRe.Style.t)),
    "h1": option(option(ReactDOMRe.Style.t)),
    "h2": option(option(ReactDOMRe.Style.t)),
    "h3": option(option(ReactDOMRe.Style.t)),
    "h4": option(option(ReactDOMRe.Style.t)),
    "h5": option(option(ReactDOMRe.Style.t)),
    "h6": option(option(ReactDOMRe.Style.t)),
    "noWrap": option(option(ReactDOMRe.Style.t)),
    "overline": option(option(ReactDOMRe.Style.t)),
    "paragraph": option(option(ReactDOMRe.Style.t)),
    "root": option(option(ReactDOMRe.Style.t)),
    "srOnly": option(option(ReactDOMRe.Style.t)),
    "subtitle1": option(option(ReactDOMRe.Style.t)),
    "subtitle2": option(option(ReactDOMRe.Style.t)),
  };
  [@bs.obj]
  external make:
    (
      ~alignCenter: ReactDOMRe.Style.t=?,
      ~alignJustify: ReactDOMRe.Style.t=?,
      ~alignLeft: ReactDOMRe.Style.t=?,
      ~alignRight: ReactDOMRe.Style.t=?,
      ~body1: ReactDOMRe.Style.t=?,
      ~body2: ReactDOMRe.Style.t=?,
      ~button: ReactDOMRe.Style.t=?,
      ~caption: ReactDOMRe.Style.t=?,
      ~colorError: string=?,
      ~colorInherit: string=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~colorTextPrimary: string=?,
      ~colorTextSecondary: string=?,
      ~displayBlock: ReactDOMRe.Style.t=?,
      ~displayInline: ReactDOMRe.Style.t=?,
      ~gutterBottom: ReactDOMRe.Style.t=?,
      ~h1: ReactDOMRe.Style.t=?,
      ~h2: ReactDOMRe.Style.t=?,
      ~h3: ReactDOMRe.Style.t=?,
      ~h4: ReactDOMRe.Style.t=?,
      ~h5: ReactDOMRe.Style.t=?,
      ~h6: ReactDOMRe.Style.t=?,
      ~noWrap: ReactDOMRe.Style.t=?,
      ~overline: ReactDOMRe.Style.t=?,
      ~paragraph: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      ~srOnly: ReactDOMRe.Style.t=?,
      ~subtitle1: ReactDOMRe.Style.t=?,
      ~subtitle2: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module Overrides = {
  type t = {
    .
    "MuiAppBar": option(option(AppBarClassKey.t)),
    "MuiAvatar": option(option(AvatarClassKey.t)),
    "MuiBackdrop": option(option(BackdropClassKey.t)),
    "MuiBadge": option(option(BadgeClassKey.t)),
    "MuiBottomNavigation": option(option(MuiBottomNavigation.t)),
    "MuiBottomNavigationAction":
      option(option(BottomNavigationActionClassKey.t)),
    "MuiBreadcrumbs": option(option(BreadcrumbsClassKey.t)),
    "MuiButton": option(option(ButtonClassKey.t)),
    "MuiButtonBase": option(option(ButtonBaseClassKey.t)),
    "MuiButtonGroup": option(option(ButtonGroupClassKey.t)),
    "MuiCard": option(option(MuiCard.t)),
    "MuiCardActionArea": option(option(CardActionAreaClassKey.t)),
    "MuiCardActions": option(option(CardActionsClassKey.t)),
    "MuiCardContent": option(option(MuiCardContent.t)),
    "MuiCardHeader": option(option(CardHeaderClassKey.t)),
    "MuiCardMedia": option(option(CardMediaClassKey.t)),
    "MuiCheckbox": option(option(CheckboxClassKey.t)),
    "MuiChip": option(option(ChipClassKey.t)),
    "MuiCircularProgress": option(option(CircularProgressClassKey.t)),
    "MuiCollapse": option(option(CollapseClassKey.t)),
    "MuiContainer": option(option(ContainerClassKey.t)),
    "MuiCssBaseline": option(option(MuiCssBaseline.t)),
    "MuiDialog": option(option(DialogClassKey.t)),
    "MuiDialogActions": option(option(CardActionsClassKey.t)),
    "MuiDialogContent": option(option(DialogContentClassKey.t)),
    "MuiDialogContentText": option(option(MuiDialogContentText.t)),
    "MuiDialogTitle": option(option(MuiDialogTitle.t)),
    "MuiDivider": option(option(DividerClassKey.t)),
    "MuiDrawer": option(option(DrawerClassKey.t)),
    "MuiExpansionPanel": option(option(ExpansionPanelClassKey.t)),
    "MuiExpansionPanelActions": option(option(CardActionsClassKey.t)),
    "MuiExpansionPanelDetails": option(option(MuiExpansionPanelDetails.t)),
    "MuiExpansionPanelSummary":
      option(option(ExpansionPanelSummaryClassKey.t)),
    "MuiFab": option(option(FabClassKey.t)),
    "MuiFilledInput": option(option(FilledInputClassKey.t)),
    "MuiFormControl": option(option(FormControlClassKey.t)),
    "MuiFormControlLabel": option(option(FormControlLabelClassKey.t)),
    "MuiFormGroup": option(option(FormGroupClassKey.t)),
    "MuiFormHelperText": option(option(FormHelperTextClassKey.t)),
    "MuiFormLabel": option(option(FormLabelClassKey.t)),
    "MuiGrid": option(option(GridClassKey.t)),
    "MuiGridList": option(option(MuiGridList.t)),
    "MuiGridListTile": option(option(GridListTileClassKey.t)),
    "MuiGridListTileBar": option(option(GridListTileBarClassKey.t)),
    "MuiIcon": option(option(SvgIconClassKey.t)),
    "MuiIconButton": option(option(IconButtonClassKey.t)),
    "MuiInput": option(option(InputClassKey.t)),
    "MuiInputAdornment": option(option(InputAdornmentClassKey.t)),
    "MuiInputBase": option(option(InputBaseClassKey.t)),
    "MuiInputLabel": option(option(InputLabelClassKey.t)),
    "MuiLinearProgress": option(option(LinearProgressClassKey.t)),
    "MuiLink": option(option(LinkClassKey.t)),
    "MuiList": option(option(ListClassKey.t)),
    "MuiListItem": option(option(ListItemClassKey.t)),
    "MuiListItemAvatar": option(option(ListItemAvatarClassKey.t)),
    "MuiListItemIcon": option(option(MuiListItemIcon.t)),
    "MuiListItemSecondaryAction":
      option(option(MuiListItemSecondaryAction.t)),
    "MuiListItemText": option(option(ListItemTextClassKey.t)),
    "MuiListSubheader": option(option(ListSubheaderClassKey.t)),
    "MuiMenu": option(option(MenuClassKey.t)),
    "MuiMenuItem": option(option(MenuItemClassKey.t)),
    "MuiMobileStepper": option(option(MobileStepperClassKey.t)),
    "MuiNativeSelect": option(option(NativeSelectClassKey.t)),
    "MuiOutlinedInput": option(option(OutlinedInputClassKey.t)),
    "MuiPaper": option(option(PaperClassKey.t)),
    "MuiPopover": option(option(PopoverClassKey.t)),
    "MuiRadio": option(option(RadioClassKey.t)),
    "MuiScopedCssBaseline": option(option(MuiScopedCssBaseline.t)),
    "MuiSelect": option(option(SelectClassKey.t)),
    "MuiSlider": option(option(SliderClassKey.t)),
    "MuiSnackbar": option(option(SnackbarClassKey.t)),
    "MuiSnackbarContent": option(option(SnackbarContentClassKey.t)),
    "MuiStep": option(option(StepClasskey.t)),
    "MuiStepButton": option(option(StepButtonClasskey.t)),
    "MuiStepConnector": option(option(StepConnectorClasskey.t)),
    "MuiStepContent": option(option(StepContentClasskey.t)),
    "MuiStepIcon": option(option(StepIconClasskey.t)),
    "MuiStepLabel": option(option(StepLabelClasskey.t)),
    "MuiStepper": option(option(StepperClasskey.t)),
    "MuiSvgIcon": option(option(SvgIconClassKey.t)),
    "MuiSwitch": option(option(SwitchClassKey.t)),
    "MuiTab": option(option(TabClassKey.t)),
    "MuiTable": option(option(TableClassKey.t)),
    "MuiTableBody": option(option(MuiTableBody.t)),
    "MuiTableCell": option(option(TableCellClassKey.t)),
    "MuiTableContainer": option(option(MuiTableContainer.t)),
    "MuiTableFooter": option(option(MuiTableFooter.t)),
    "MuiTableHead": option(option(MuiTableHead.t)),
    "MuiTablePagination": option(option(TablePaginationClassKey.t)),
    "MuiTableRow": option(option(TableRowClassKey.t)),
    "MuiTableSortLabel": option(option(TableSortLabelClassKey.t)),
    "MuiTabs": option(option(TabsClassKey.t)),
    "MuiTextField": option(option(MuiTextField.t)),
    "MuiToolbar": option(option(ToolbarClassKey.t)),
    "MuiTooltip": option(option(TooltipClassKey.t)),
    "MuiTouchRipple": option(option(TouchRippleClassKey.t)),
    "MuiTypography": option(option(TypographyClassKey.t)),
  };
  [@bs.obj]
  external make:
    (
      ~muiAppBar: AppBarClassKey.t=?,
      ~muiAvatar: AvatarClassKey.t=?,
      ~muiBackdrop: BackdropClassKey.t=?,
      ~muiBadge: BadgeClassKey.t=?,
      ~muiBottomNavigation: MuiBottomNavigation.t=?,
      ~muiBottomNavigationAction: BottomNavigationActionClassKey.t=?,
      ~muiBreadcrumbs: BreadcrumbsClassKey.t=?,
      ~muiButton: ButtonClassKey.t=?,
      ~muiButtonBase: ButtonBaseClassKey.t=?,
      ~muiButtonGroup: ButtonGroupClassKey.t=?,
      ~muiCard: MuiCard.t=?,
      ~muiCardActionArea: CardActionAreaClassKey.t=?,
      ~muiCardActions: CardActionsClassKey.t=?,
      ~muiCardContent: MuiCardContent.t=?,
      ~muiCardHeader: CardHeaderClassKey.t=?,
      ~muiCardMedia: CardMediaClassKey.t=?,
      ~muiCheckbox: CheckboxClassKey.t=?,
      ~muiChip: ChipClassKey.t=?,
      ~muiCircularProgress: CircularProgressClassKey.t=?,
      ~muiCollapse: CollapseClassKey.t=?,
      ~muiContainer: ContainerClassKey.t=?,
      ~muiCssBaseline: MuiCssBaseline.t=?,
      ~muiDialog: DialogClassKey.t=?,
      ~muiDialogActions: CardActionsClassKey.t=?,
      ~muiDialogContent: DialogContentClassKey.t=?,
      ~muiDialogContentText: MuiDialogContentText.t=?,
      ~muiDialogTitle: MuiDialogTitle.t=?,
      ~muiDivider: DividerClassKey.t=?,
      ~muiDrawer: DrawerClassKey.t=?,
      ~muiExpansionPanel: ExpansionPanelClassKey.t=?,
      ~muiExpansionPanelActions: CardActionsClassKey.t=?,
      ~muiExpansionPanelDetails: MuiExpansionPanelDetails.t=?,
      ~muiExpansionPanelSummary: ExpansionPanelSummaryClassKey.t=?,
      ~muiFab: FabClassKey.t=?,
      ~muiFilledInput: FilledInputClassKey.t=?,
      ~muiFormControl: FormControlClassKey.t=?,
      ~muiFormControlLabel: FormControlLabelClassKey.t=?,
      ~muiFormGroup: FormGroupClassKey.t=?,
      ~muiFormHelperText: FormHelperTextClassKey.t=?,
      ~muiFormLabel: FormLabelClassKey.t=?,
      ~muiGrid: GridClassKey.t=?,
      ~muiGridList: MuiGridList.t=?,
      ~muiGridListTile: GridListTileClassKey.t=?,
      ~muiGridListTileBar: GridListTileBarClassKey.t=?,
      ~muiIcon: SvgIconClassKey.t=?,
      ~muiIconButton: IconButtonClassKey.t=?,
      ~muiInput: InputClassKey.t=?,
      ~muiInputAdornment: InputAdornmentClassKey.t=?,
      ~muiInputBase: InputBaseClassKey.t=?,
      ~muiInputLabel: InputLabelClassKey.t=?,
      ~muiLinearProgress: LinearProgressClassKey.t=?,
      ~muiLink: LinkClassKey.t=?,
      ~muiList: ListClassKey.t=?,
      ~muiListItem: ListItemClassKey.t=?,
      ~muiListItemAvatar: ListItemAvatarClassKey.t=?,
      ~muiListItemIcon: MuiListItemIcon.t=?,
      ~muiListItemSecondaryAction: MuiListItemSecondaryAction.t=?,
      ~muiListItemText: ListItemTextClassKey.t=?,
      ~muiListSubheader: ListSubheaderClassKey.t=?,
      ~muiMenu: MenuClassKey.t=?,
      ~muiMenuItem: MenuItemClassKey.t=?,
      ~muiMobileStepper: MobileStepperClassKey.t=?,
      ~muiNativeSelect: NativeSelectClassKey.t=?,
      ~muiOutlinedInput: OutlinedInputClassKey.t=?,
      ~muiPaper: PaperClassKey.t=?,
      ~muiPopover: PopoverClassKey.t=?,
      ~muiRadio: RadioClassKey.t=?,
      ~muiScopedCssBaseline: MuiScopedCssBaseline.t=?,
      ~muiSelect: SelectClassKey.t=?,
      ~muiSlider: SliderClassKey.t=?,
      ~muiSnackbar: SnackbarClassKey.t=?,
      ~muiSnackbarContent: SnackbarContentClassKey.t=?,
      ~muiStep: StepClasskey.t=?,
      ~muiStepButton: StepButtonClasskey.t=?,
      ~muiStepConnector: StepConnectorClasskey.t=?,
      ~muiStepContent: StepContentClasskey.t=?,
      ~muiStepIcon: StepIconClasskey.t=?,
      ~muiStepLabel: StepLabelClasskey.t=?,
      ~muiStepper: StepperClasskey.t=?,
      ~muiSvgIcon: SvgIconClassKey.t=?,
      ~muiSwitch: SwitchClassKey.t=?,
      ~muiTab: TabClassKey.t=?,
      ~muiTable: TableClassKey.t=?,
      ~muiTableBody: MuiTableBody.t=?,
      ~muiTableCell: TableCellClassKey.t=?,
      ~muiTableContainer: MuiTableContainer.t=?,
      ~muiTableFooter: MuiTableFooter.t=?,
      ~muiTableHead: MuiTableHead.t=?,
      ~muiTablePagination: TablePaginationClassKey.t=?,
      ~muiTableRow: TableRowClassKey.t=?,
      ~muiTableSortLabel: TableSortLabelClassKey.t=?,
      ~muiTabs: TabsClassKey.t=?,
      ~muiTextField: MuiTextField.t=?,
      ~muiToolbar: ToolbarClassKey.t=?,
      ~muiTooltip: TooltipClassKey.t=?,
      ~muiTouchRipple: TouchRippleClassKey.t=?,
      ~muiTypography: TypographyClassKey.t=?,
      unit
    ) =>
    t;
};

module TypeAction = {
  type t = {
    .
    "activatedOpacity": option(option(float)),
    "active": option(option(string)),
    "disabled": option(option(string)),
    "disabledBackground": option(option(string)),
    "disabledOpacity": option(option(float)),
    "focus": option(option(string)),
    "focusOpacity": option(option(float)),
    "hover": option(option(string)),
    "hoverOpacity": option(option(float)),
    "selected": option(option(string)),
    "selectedOpacity": option(option(float)),
  };
  [@bs.obj]
  external make:
    (
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
      unit
    ) =>
    t;
};

module TypeBackground = {
  type t = {
    .
    "default": option(option(string)),
    "paper": option(option(string)),
  };
  [@bs.obj] external make: (~default: string=?, ~paper: string=?, unit) => t;
};

module CommonColors = {
  type t = {
    .
    "black": option(option(string)),
    "white": option(option(string)),
  };
  [@bs.obj] external make: (~black: string=?, ~white: string=?, unit) => t;
};

module Error = {
  type t = {
    .
    "50": option(option(string)),
    "100": option(option(string)),
    "200": option(option(string)),
    "300": option(option(string)),
    "400": option(option(string)),
    "500": option(option(string)),
    "600": option(option(string)),
    "700": option(option(string)),
    "800": option(option(string)),
    "900": option(option(string)),
    "A100": option(option(string)),
    "A200": option(option(string)),
    "A400": option(option(string)),
    "A700": option(option(string)),
    "contrastText": option(option(string)),
    "dark": option(option(string)),
    "light": option(option(string)),
    "main": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~_50: string=?,
      ~_100: string=?,
      ~_200: string=?,
      ~_300: string=?,
      ~_400: string=?,
      ~_500: string=?,
      ~_600: string=?,
      ~_700: string=?,
      ~_800: string=?,
      ~_900: string=?,
      ~a100: string=?,
      ~a200: string=?,
      ~a400: string=?,
      ~a700: string=?,
      ~contrastText: string=?,
      ~dark: string=?,
      ~light: string=?,
      ~main: string=?,
      unit
    ) =>
    t;
};

module Color = {
  type t = {
    .
    "50": option(option(string)),
    "100": option(option(string)),
    "200": option(option(string)),
    "300": option(option(string)),
    "400": option(option(string)),
    "500": option(option(string)),
    "600": option(option(string)),
    "700": option(option(string)),
    "800": option(option(string)),
    "900": option(option(string)),
    "A100": option(option(string)),
    "A200": option(option(string)),
    "A400": option(option(string)),
    "A700": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~_50: string=?,
      ~_100: string=?,
      ~_200: string=?,
      ~_300: string=?,
      ~_400: string=?,
      ~_500: string=?,
      ~_600: string=?,
      ~_700: string=?,
      ~_800: string=?,
      ~_900: string=?,
      ~a100: string=?,
      ~a200: string=?,
      ~a400: string=?,
      ~a700: string=?,
      unit
    ) =>
    t;
};

module Info = {
  type t = {
    .
    "50": option(option(string)),
    "100": option(option(string)),
    "200": option(option(string)),
    "300": option(option(string)),
    "400": option(option(string)),
    "500": option(option(string)),
    "600": option(option(string)),
    "700": option(option(string)),
    "800": option(option(string)),
    "900": option(option(string)),
    "A100": option(option(string)),
    "A200": option(option(string)),
    "A400": option(option(string)),
    "A700": option(option(string)),
    "contrastText": option(option(string)),
    "dark": option(option(string)),
    "light": option(option(string)),
    "main": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~_50: string=?,
      ~_100: string=?,
      ~_200: string=?,
      ~_300: string=?,
      ~_400: string=?,
      ~_500: string=?,
      ~_600: string=?,
      ~_700: string=?,
      ~_800: string=?,
      ~_900: string=?,
      ~a100: string=?,
      ~a200: string=?,
      ~a400: string=?,
      ~a700: string=?,
      ~contrastText: string=?,
      ~dark: string=?,
      ~light: string=?,
      ~main: string=?,
      unit
    ) =>
    t;
};

module Primary = {
  type t = {
    .
    "50": option(option(string)),
    "100": option(option(string)),
    "200": option(option(string)),
    "300": option(option(string)),
    "400": option(option(string)),
    "500": option(option(string)),
    "600": option(option(string)),
    "700": option(option(string)),
    "800": option(option(string)),
    "900": option(option(string)),
    "A100": option(option(string)),
    "A200": option(option(string)),
    "A400": option(option(string)),
    "A700": option(option(string)),
    "contrastText": option(option(string)),
    "dark": option(option(string)),
    "light": option(option(string)),
    "main": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~_50: string=?,
      ~_100: string=?,
      ~_200: string=?,
      ~_300: string=?,
      ~_400: string=?,
      ~_500: string=?,
      ~_600: string=?,
      ~_700: string=?,
      ~_800: string=?,
      ~_900: string=?,
      ~a100: string=?,
      ~a200: string=?,
      ~a400: string=?,
      ~a700: string=?,
      ~contrastText: string=?,
      ~dark: string=?,
      ~light: string=?,
      ~main: string=?,
      unit
    ) =>
    t;
};

module Secondary = {
  type t = {
    .
    "50": option(option(string)),
    "100": option(option(string)),
    "200": option(option(string)),
    "300": option(option(string)),
    "400": option(option(string)),
    "500": option(option(string)),
    "600": option(option(string)),
    "700": option(option(string)),
    "800": option(option(string)),
    "900": option(option(string)),
    "A100": option(option(string)),
    "A200": option(option(string)),
    "A400": option(option(string)),
    "A700": option(option(string)),
    "contrastText": option(option(string)),
    "dark": option(option(string)),
    "light": option(option(string)),
    "main": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~_50: string=?,
      ~_100: string=?,
      ~_200: string=?,
      ~_300: string=?,
      ~_400: string=?,
      ~_500: string=?,
      ~_600: string=?,
      ~_700: string=?,
      ~_800: string=?,
      ~_900: string=?,
      ~a100: string=?,
      ~a200: string=?,
      ~a400: string=?,
      ~a700: string=?,
      ~contrastText: string=?,
      ~dark: string=?,
      ~light: string=?,
      ~main: string=?,
      unit
    ) =>
    t;
};

module Success = {
  type t = {
    .
    "50": option(option(string)),
    "100": option(option(string)),
    "200": option(option(string)),
    "300": option(option(string)),
    "400": option(option(string)),
    "500": option(option(string)),
    "600": option(option(string)),
    "700": option(option(string)),
    "800": option(option(string)),
    "900": option(option(string)),
    "A100": option(option(string)),
    "A200": option(option(string)),
    "A400": option(option(string)),
    "A700": option(option(string)),
    "contrastText": option(option(string)),
    "dark": option(option(string)),
    "light": option(option(string)),
    "main": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~_50: string=?,
      ~_100: string=?,
      ~_200: string=?,
      ~_300: string=?,
      ~_400: string=?,
      ~_500: string=?,
      ~_600: string=?,
      ~_700: string=?,
      ~_800: string=?,
      ~_900: string=?,
      ~a100: string=?,
      ~a200: string=?,
      ~a400: string=?,
      ~a700: string=?,
      ~contrastText: string=?,
      ~dark: string=?,
      ~light: string=?,
      ~main: string=?,
      unit
    ) =>
    t;
};

module TypeText = {
  type t = {
    .
    "disabled": option(option(string)),
    "hint": option(option(string)),
    "primary": option(option(string)),
    "secondary": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~disabled: string=?,
      ~hint: string=?,
      ~primary: string=?,
      ~secondary: string=?,
      unit
    ) =>
    t;
};

module TonalOffset = {
  type t = {
    .
    "dark": option(option(float)),
    "light": option(option(float)),
  };
  [@bs.obj] external make: (~dark: float=?, ~light: float=?, unit) => t;
};

module Warning = {
  type t = {
    .
    "50": option(option(string)),
    "100": option(option(string)),
    "200": option(option(string)),
    "300": option(option(string)),
    "400": option(option(string)),
    "500": option(option(string)),
    "600": option(option(string)),
    "700": option(option(string)),
    "800": option(option(string)),
    "900": option(option(string)),
    "A100": option(option(string)),
    "A200": option(option(string)),
    "A400": option(option(string)),
    "A700": option(option(string)),
    "contrastText": option(option(string)),
    "dark": option(option(string)),
    "light": option(option(string)),
    "main": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~_50: string=?,
      ~_100: string=?,
      ~_200: string=?,
      ~_300: string=?,
      ~_400: string=?,
      ~_500: string=?,
      ~_600: string=?,
      ~_700: string=?,
      ~_800: string=?,
      ~_900: string=?,
      ~a100: string=?,
      ~a200: string=?,
      ~a400: string=?,
      ~a700: string=?,
      ~contrastText: string=?,
      ~dark: string=?,
      ~light: string=?,
      ~main: string=?,
      unit
    ) =>
    t;
};

module PaletteOptions = {
  type t = {
    .
    "action": option(option(TypeAction.t)),
    "background": option(option(TypeBackground.t)),
    "common": option(option(CommonColors.t)),
    "contrastThreshold": option(option(float)),
    "divider": option(option(string)),
    "error": option(option(Error.t)),
    "getContrastText": option(option(MaterialUi_Types.any)),
    "grey": option(option(Color.t)),
    "info": option(option(Info.t)),
    "primary": option(option(Primary.t)),
    "secondary": option(option(Secondary.t)),
    "success": option(option(Success.t)),
    "text": option(option(TypeText.t)),
    "tonalOffset": option(option(TonalOffset.t)),
    "type": option(option(string)),
    "warning": option(option(Warning.t)),
  };
  [@bs.obj]
  external make:
    (
      ~action: TypeAction.t=?,
      ~background: TypeBackground.t=?,
      ~common: CommonColors.t=?,
      ~contrastThreshold: float=?,
      ~divider: string=?,
      ~error: Error.t=?,
      ~getContrastText: MaterialUi_Types.any=?,
      ~grey: Color.t=?,
      ~info: Info.t=?,
      ~primary: Primary.t=?,
      ~secondary: Secondary.t=?,
      ~success: Success.t=?,
      ~text: TypeText.t=?,
      ~tonalOffset: TonalOffset.t=?,
      ~_type: string=?,
      ~warning: Warning.t=?,
      unit
    ) =>
    t;
};

module Shape = {
  type t = {. "borderRadius": option(option(float))};
  [@bs.obj] external make: (~borderRadius: float=?, unit) => t;
};

module Duration = {
  type t = {
    .
    "complex": option(option(float)),
    "enteringScreen": option(option(float)),
    "leavingScreen": option(option(float)),
    "short": option(option(float)),
    "shorter": option(option(float)),
    "shortest": option(option(float)),
    "standard": option(option(float)),
  };
  [@bs.obj]
  external make:
    (
      ~complex: float=?,
      ~enteringScreen: float=?,
      ~leavingScreen: float=?,
      ~short: float=?,
      ~shorter: float=?,
      ~shortest: float=?,
      ~standard: float=?,
      unit
    ) =>
    t;
};

module Easing = {
  type t = {
    .
    "easeIn": option(option(string)),
    "easeInOut": option(option(string)),
    "easeOut": option(option(string)),
    "sharp": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~easeIn: string=?,
      ~easeInOut: string=?,
      ~easeOut: string=?,
      ~sharp: string=?,
      unit
    ) =>
    t;
};

module TransitionsOptions = {
  type t = {
    .
    "create": option(option(MaterialUi_Types.any)),
    "duration": option(option(Duration.t)),
    "easing": option(option(Easing.t)),
    "getAutoHeightDuration": option(option(MaterialUi_Types.any)),
  };
  [@bs.obj]
  external make:
    (
      ~create: MaterialUi_Types.any=?,
      ~duration: Duration.t=?,
      ~easing: Easing.t=?,
      ~getAutoHeightDuration: MaterialUi_Types.any=?,
      unit
    ) =>
    t;
};

module TypographyStyleOptions = {
  type t = {. "@font-face": option(option(MaterialUi_Types.any))};
  [@bs.obj] external make: (~fontFace: MaterialUi_Types.any=?, unit) => t;
};

module Typography = {
  type t = {
    .
    "body1": option(option(TypographyStyleOptions.t)),
    "body2": option(option(TypographyStyleOptions.t)),
    "button": option(option(TypographyStyleOptions.t)),
    "caption": option(option(TypographyStyleOptions.t)),
    "fontFamily": option(option(string)),
    "fontSize": option(option(float)),
    "fontWeightBold": option(option(string)),
    "fontWeightLight": option(option(string)),
    "fontWeightMedium": option(option(string)),
    "fontWeightRegular": option(option(string)),
    "h1": option(option(TypographyStyleOptions.t)),
    "h2": option(option(TypographyStyleOptions.t)),
    "h3": option(option(TypographyStyleOptions.t)),
    "h4": option(option(TypographyStyleOptions.t)),
    "h5": option(option(TypographyStyleOptions.t)),
    "h6": option(option(TypographyStyleOptions.t)),
    "htmlFontSize": option(option(float)),
    "overline": option(option(TypographyStyleOptions.t)),
    "subtitle1": option(option(TypographyStyleOptions.t)),
    "subtitle2": option(option(TypographyStyleOptions.t)),
  };
  [@bs.obj]
  external make:
    (
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
      unit
    ) =>
    t;
};

module ZIndex = {
  type t = {
    .
    "appBar": option(option(float)),
    "drawer": option(option(float)),
    "mobileStepper": option(option(float)),
    "modal": option(option(float)),
    "snackbar": option(option(float)),
    "speedDial": option(option(float)),
    "tooltip": option(option(float)),
  };
  [@bs.obj]
  external make:
    (
      ~appBar: float=?,
      ~drawer: float=?,
      ~mobileStepper: float=?,
      ~modal: float=?,
      ~snackbar: float=?,
      ~speedDial: float=?,
      ~tooltip: float=?,
      unit
    ) =>
    t;
};

type t = {
  .
  "breakpoints": option(option(Breakpoints.t)),
  "direction": option(option(string)),
  "mixins": option(option(MixinsOptions.t)),
  "overrides": option(option(Overrides.t)),
  "palette": option(option(PaletteOptions.t)),
  "props": option(option(MaterialUi_Types.any)),
  "shadows": option(option(array(string))),
  "shape": option(option(Shape.t)),
  "spacing": option(option(MaterialUi_Types.any)),
  "transitions": option(option(TransitionsOptions.t)),
  "typography": option(option(Typography.t)),
  "zIndex": option(option(ZIndex.t)),
};
[@bs.obj]
external make:
  (
    ~breakpoints: Breakpoints.t=?,
    ~direction: string=?,
    ~mixins: MixinsOptions.t=?,
    ~overrides: Overrides.t=?,
    ~palette: PaletteOptions.t=?,
    ~props: MaterialUi_Types.any=?,
    ~shadows: array(string)=?,
    ~shape: Shape.t=?,
    ~spacing: MaterialUi_Types.any=?,
    ~transitions: TransitionsOptions.t=?,
    ~typography: Typography.t=?,
    ~zIndex: ZIndex.t=?,
    unit
  ) =>
  t;
