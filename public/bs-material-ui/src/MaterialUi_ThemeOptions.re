module BreakpointValues = {
  type t = {
    .
    "lg": option(float),
    "md": option(float),
    "sm": option(float),
    "xl": option(float),
    "xs": option(float),
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
    "between": option(MaterialUi_Types.any),
    "down": option(MaterialUi_Types.any),
    "keys": option(array(string)),
    "only": option(MaterialUi_Types.any),
    "step": option(float),
    "unit": option(string),
    "up": option(MaterialUi_Types.any),
    "values": option(BreakpointValues.t),
    "width": option(MaterialUi_Types.any),
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
    "gutters": option(MaterialUi_Types.any),
    "toolbar": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (~gutters: MaterialUi_Types.any=?, ~toolbar: ReactDOMRe.Style.t=?, unit) =>
    t;
};

module AccordionClassKey = {
  type t = {
    .
    "disabled": option(ReactDOMRe.Style.t),
    "expanded": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "rounded": option(ReactDOMRe.Style.t),
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

module AccordionActionsClassKey = {
  type t = {
    .
    "root": option(ReactDOMRe.Style.t),
    "spacing": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (~root: ReactDOMRe.Style.t=?, ~spacing: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiAccordionDetails = {
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module AccordionSummaryClassKey = {
  type t = {
    .
    "content": option(ReactDOMRe.Style.t),
    "disabled": option(ReactDOMRe.Style.t),
    "expandIcon": option(ReactDOMRe.Style.t),
    "expanded": option(ReactDOMRe.Style.t),
    "focused": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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

module AppBarClassKey = {
  type t = {
    .
    "colorDefault": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "positionAbsolute": option(ReactDOMRe.Style.t),
    "positionFixed": option(ReactDOMRe.Style.t),
    "positionRelative": option(ReactDOMRe.Style.t),
    "positionStatic": option(ReactDOMRe.Style.t),
    "positionSticky": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "circle": option(ReactDOMRe.Style.t),
    "colorDefault": option(string),
    "fallback": option(ReactDOMRe.Style.t),
    "img": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "rounded": option(ReactDOMRe.Style.t),
    "square": option(ReactDOMRe.Style.t),
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
    "invisible": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (~invisible: ReactDOMRe.Style.t=?, ~root: ReactDOMRe.Style.t=?, unit) => t;
};

module BadgeClassKey = {
  type t = {
    .
    "anchorOriginBottomLeftRectangle": option(ReactDOMRe.Style.t),
    "anchorOriginBottomRightCircle": option(ReactDOMRe.Style.t),
    "anchorOriginBottomRightRectangle": option(ReactDOMRe.Style.t),
    "anchorOriginTopLeftCircle": option(ReactDOMRe.Style.t),
    "anchorOriginTopLeftRectangle": option(ReactDOMRe.Style.t),
    "anchorOriginTopRightCircle": option(ReactDOMRe.Style.t),
    "anchorOriginTopRightRectangle": option(ReactDOMRe.Style.t),
    "badge": option(ReactDOMRe.Style.t),
    "colorError": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "dot": option(ReactDOMRe.Style.t),
    "invisible": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module BottomNavigationActionClassKey = {
  type t = {
    .
    "iconOnly": option(ReactDOMRe.Style.t),
    "label": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "selected": option(ReactDOMRe.Style.t),
    "wrapper": option(ReactDOMRe.Style.t),
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
    "li": option(ReactDOMRe.Style.t),
    "ol": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "separator": option(ReactDOMRe.Style.t),
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
    "colorInherit": option(string),
    "contained": option(ReactDOMRe.Style.t),
    "containedPrimary": option(ReactDOMRe.Style.t),
    "containedSecondary": option(ReactDOMRe.Style.t),
    "containedSizeLarge": option(ReactDOMRe.Style.t),
    "containedSizeSmall": option(ReactDOMRe.Style.t),
    "disableElevation": option(ReactDOMRe.Style.t),
    "disabled": option(ReactDOMRe.Style.t),
    "endIcon": option(ReactDOMRe.Style.t),
    "focusVisible": option(ReactDOMRe.Style.t),
    "fullWidth": option(ReactDOMRe.Style.t),
    "iconSizeLarge": option(ReactDOMRe.Style.t),
    "iconSizeMedium": option(ReactDOMRe.Style.t),
    "iconSizeSmall": option(ReactDOMRe.Style.t),
    "label": option(ReactDOMRe.Style.t),
    "outlined": option(ReactDOMRe.Style.t),
    "outlinedPrimary": option(ReactDOMRe.Style.t),
    "outlinedSecondary": option(ReactDOMRe.Style.t),
    "outlinedSizeLarge": option(ReactDOMRe.Style.t),
    "outlinedSizeSmall": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "sizeLarge": option(ReactDOMRe.Style.t),
    "sizeSmall": option(ReactDOMRe.Style.t),
    "startIcon": option(ReactDOMRe.Style.t),
    "text": option(ReactDOMRe.Style.t),
    "textPrimary": option(ReactDOMRe.Style.t),
    "textSecondary": option(ReactDOMRe.Style.t),
    "textSizeLarge": option(ReactDOMRe.Style.t),
    "textSizeSmall": option(ReactDOMRe.Style.t),
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
    "disabled": option(ReactDOMRe.Style.t),
    "focusVisible": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "contained": option(ReactDOMRe.Style.t),
    "disableElevation": option(ReactDOMRe.Style.t),
    "disabled": option(ReactDOMRe.Style.t),
    "fullWidth": option(ReactDOMRe.Style.t),
    "grouped": option(ReactDOMRe.Style.t),
    "groupedContained": option(ReactDOMRe.Style.t),
    "groupedContainedHorizontal": option(ReactDOMRe.Style.t),
    "groupedContainedPrimary": option(ReactDOMRe.Style.t),
    "groupedContainedSecondary": option(ReactDOMRe.Style.t),
    "groupedContainedVertical": option(ReactDOMRe.Style.t),
    "groupedHorizontal": option(ReactDOMRe.Style.t),
    "groupedOutlined": option(ReactDOMRe.Style.t),
    "groupedOutlinedHorizontal": option(ReactDOMRe.Style.t),
    "groupedOutlinedPrimary": option(ReactDOMRe.Style.t),
    "groupedOutlinedSecondary": option(ReactDOMRe.Style.t),
    "groupedOutlinedVertical": option(ReactDOMRe.Style.t),
    "groupedText": option(ReactDOMRe.Style.t),
    "groupedTextHorizontal": option(ReactDOMRe.Style.t),
    "groupedTextPrimary": option(ReactDOMRe.Style.t),
    "groupedTextSecondary": option(ReactDOMRe.Style.t),
    "groupedTextVertical": option(ReactDOMRe.Style.t),
    "groupedVertical": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "vertical": option(ReactDOMRe.Style.t),
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
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module CardActionAreaClassKey = {
  type t = {
    .
    "focusHighlight": option(ReactDOMRe.Style.t),
    "focusVisible": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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

module MuiCardContent = {
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module CardHeaderClassKey = {
  type t = {
    .
    "action": option(ReactDOMRe.Style.t),
    "avatar": option(ReactDOMRe.Style.t),
    "content": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "subheader": option(ReactDOMRe.Style.t),
    "title": option(ReactDOMRe.Style.t),
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
    "media": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (~media: ReactDOMRe.Style.t=?, ~root: ReactDOMRe.Style.t=?, unit) => t;
};

module CheckboxClassKey = {
  type t = {
    .
    "checked": option(ReactDOMRe.Style.t),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "disabled": option(ReactDOMRe.Style.t),
    "indeterminate": option(ReactDOMRe.Style.t),
    "input": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "avatar": option(ReactDOMRe.Style.t),
    "avatarColorPrimary": option(ReactDOMRe.Style.t),
    "avatarColorSecondary": option(ReactDOMRe.Style.t),
    "avatarSmall": option(ReactDOMRe.Style.t),
    "clickable": option(ReactDOMRe.Style.t),
    "clickableColorPrimary": option(ReactDOMRe.Style.t),
    "clickableColorSecondary": option(ReactDOMRe.Style.t),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "deletable": option(ReactDOMRe.Style.t),
    "deletableColorPrimary": option(ReactDOMRe.Style.t),
    "deletableColorSecondary": option(ReactDOMRe.Style.t),
    "deleteIcon": option(ReactDOMRe.Style.t),
    "deleteIconColorPrimary": option(ReactDOMRe.Style.t),
    "deleteIconColorSecondary": option(ReactDOMRe.Style.t),
    "deleteIconOutlinedColorPrimary": option(ReactDOMRe.Style.t),
    "deleteIconOutlinedColorSecondary": option(ReactDOMRe.Style.t),
    "deleteIconSmall": option(ReactDOMRe.Style.t),
    "disabled": option(ReactDOMRe.Style.t),
    "icon": option(ReactDOMRe.Style.t),
    "iconColorPrimary": option(ReactDOMRe.Style.t),
    "iconColorSecondary": option(ReactDOMRe.Style.t),
    "iconSmall": option(ReactDOMRe.Style.t),
    "label": option(ReactDOMRe.Style.t),
    "labelSmall": option(ReactDOMRe.Style.t),
    "outlined": option(ReactDOMRe.Style.t),
    "outlinedPrimary": option(ReactDOMRe.Style.t),
    "outlinedSecondary": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "sizeSmall": option(ReactDOMRe.Style.t),
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
    "circle": option(ReactDOMRe.Style.t),
    "circleDisableShrink": option(ReactDOMRe.Style.t),
    "circleIndeterminate": option(ReactDOMRe.Style.t),
    "circleStatic": option(ReactDOMRe.Style.t),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "indeterminate": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "static": option(ReactDOMRe.Style.t),
    "svg": option(ReactDOMRe.Style.t),
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
    "container": option(ReactDOMRe.Style.t),
    "entered": option(ReactDOMRe.Style.t),
    "hidden": option(ReactDOMRe.Style.t),
    "wrapper": option(ReactDOMRe.Style.t),
    "wrapperInner": option(ReactDOMRe.Style.t),
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
    "disableGutters": option(ReactDOMRe.Style.t),
    "fixed": option(ReactDOMRe.Style.t),
    "maxWidthLg": option(ReactDOMRe.Style.t),
    "maxWidthMd": option(ReactDOMRe.Style.t),
    "maxWidthSm": option(ReactDOMRe.Style.t),
    "maxWidthXl": option(ReactDOMRe.Style.t),
    "maxWidthXs": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
  type t = {. "@font-face": option(MaterialUi_Types.any)};
  [@bs.obj] external make: (~fontFace: MaterialUi_Types.any=?, unit) => t;
};

module MuiCssBaseline = {
  type t = {. "@global": option(Global.t)};
  [@bs.obj] external make: (~global: Global.t=?, unit) => t;
};

module DialogClassKey = {
  type t = {
    .
    "container": option(ReactDOMRe.Style.t),
    "paper": option(ReactDOMRe.Style.t),
    "paperFullScreen": option(ReactDOMRe.Style.t),
    "paperFullWidth": option(ReactDOMRe.Style.t),
    "paperScrollBody": option(ReactDOMRe.Style.t),
    "paperScrollPaper": option(ReactDOMRe.Style.t),
    "paperWidthFalse": option(ReactDOMRe.Style.t),
    "paperWidthLg": option(ReactDOMRe.Style.t),
    "paperWidthMd": option(ReactDOMRe.Style.t),
    "paperWidthSm": option(ReactDOMRe.Style.t),
    "paperWidthXl": option(ReactDOMRe.Style.t),
    "paperWidthXs": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "scrollBody": option(ReactDOMRe.Style.t),
    "scrollPaper": option(ReactDOMRe.Style.t),
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
    "dividers": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (~dividers: ReactDOMRe.Style.t=?, ~root: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiDialogContentText = {
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiDialogTitle = {
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module DividerClassKey = {
  type t = {
    .
    "absolute": option(ReactDOMRe.Style.t),
    "inset": option(ReactDOMRe.Style.t),
    "light": option(ReactDOMRe.Style.t),
    "middle": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "vertical": option(ReactDOMRe.Style.t),
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
    "docked": option(ReactDOMRe.Style.t),
    "modal": option(ReactDOMRe.Style.t),
    "paper": option(ReactDOMRe.Style.t),
    "paperAnchorBottom": option(ReactDOMRe.Style.t),
    "paperAnchorDockedBottom": option(ReactDOMRe.Style.t),
    "paperAnchorDockedLeft": option(ReactDOMRe.Style.t),
    "paperAnchorDockedRight": option(ReactDOMRe.Style.t),
    "paperAnchorDockedTop": option(ReactDOMRe.Style.t),
    "paperAnchorLeft": option(ReactDOMRe.Style.t),
    "paperAnchorRight": option(ReactDOMRe.Style.t),
    "paperAnchorTop": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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

module MuiExpansionPanelDetails = {
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module FabClassKey = {
  type t = {
    .
    "colorInherit": option(string),
    "disabled": option(ReactDOMRe.Style.t),
    "extended": option(ReactDOMRe.Style.t),
    "focusVisible": option(ReactDOMRe.Style.t),
    "label": option(ReactDOMRe.Style.t),
    "primary": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "secondary": option(ReactDOMRe.Style.t),
    "sizeMedium": option(ReactDOMRe.Style.t),
    "sizeSmall": option(ReactDOMRe.Style.t),
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
    "adornedEnd": option(ReactDOMRe.Style.t),
    "adornedStart": option(ReactDOMRe.Style.t),
    "colorSecondary": option(string),
    "disabled": option(ReactDOMRe.Style.t),
    "error": option(ReactDOMRe.Style.t),
    "focused": option(ReactDOMRe.Style.t),
    "formControl": option(ReactDOMRe.Style.t),
    "fullWidth": option(ReactDOMRe.Style.t),
    "input": option(ReactDOMRe.Style.t),
    "inputAdornedEnd": option(ReactDOMRe.Style.t),
    "inputAdornedStart": option(ReactDOMRe.Style.t),
    "inputHiddenLabel": option(ReactDOMRe.Style.t),
    "inputMarginDense": option(ReactDOMRe.Style.t),
    "inputMultiline": option(ReactDOMRe.Style.t),
    "inputTypeSearch": option(ReactDOMRe.Style.t),
    "marginDense": option(ReactDOMRe.Style.t),
    "multiline": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "underline": option(ReactDOMRe.Style.t),
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
    "fullWidth": option(ReactDOMRe.Style.t),
    "marginDense": option(ReactDOMRe.Style.t),
    "marginNormal": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "disabled": option(ReactDOMRe.Style.t),
    "label": option(ReactDOMRe.Style.t),
    "labelPlacementBottom": option(ReactDOMRe.Style.t),
    "labelPlacementStart": option(ReactDOMRe.Style.t),
    "labelPlacementTop": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "root": option(ReactDOMRe.Style.t),
    "row": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (~root: ReactDOMRe.Style.t=?, ~row: ReactDOMRe.Style.t=?, unit) => t;
};

module FormHelperTextClassKey = {
  type t = {
    .
    "contained": option(ReactDOMRe.Style.t),
    "disabled": option(ReactDOMRe.Style.t),
    "error": option(ReactDOMRe.Style.t),
    "filled": option(ReactDOMRe.Style.t),
    "focused": option(ReactDOMRe.Style.t),
    "marginDense": option(ReactDOMRe.Style.t),
    "required": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "asterisk": option(ReactDOMRe.Style.t),
    "colorSecondary": option(string),
    "disabled": option(ReactDOMRe.Style.t),
    "error": option(ReactDOMRe.Style.t),
    "filled": option(ReactDOMRe.Style.t),
    "focused": option(ReactDOMRe.Style.t),
    "required": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "align-content-xs-center": option(ReactDOMRe.Style.t),
    "align-content-xs-flex-end": option(ReactDOMRe.Style.t),
    "align-content-xs-flex-start": option(ReactDOMRe.Style.t),
    "align-content-xs-space-around": option(ReactDOMRe.Style.t),
    "align-content-xs-space-between": option(ReactDOMRe.Style.t),
    "align-items-xs-baseline": option(ReactDOMRe.Style.t),
    "align-items-xs-center": option(ReactDOMRe.Style.t),
    "align-items-xs-flex-end": option(ReactDOMRe.Style.t),
    "align-items-xs-flex-start": option(ReactDOMRe.Style.t),
    "container": option(ReactDOMRe.Style.t),
    "direction-xs-column": option(ReactDOMRe.Style.t),
    "direction-xs-column-reverse": option(ReactDOMRe.Style.t),
    "direction-xs-row-reverse": option(ReactDOMRe.Style.t),
    "grid-xs-1": option(ReactDOMRe.Style.t),
    "grid-xs-10": option(ReactDOMRe.Style.t),
    "grid-xs-11": option(ReactDOMRe.Style.t),
    "grid-xs-12": option(ReactDOMRe.Style.t),
    "grid-xs-2": option(ReactDOMRe.Style.t),
    "grid-xs-3": option(ReactDOMRe.Style.t),
    "grid-xs-4": option(ReactDOMRe.Style.t),
    "grid-xs-5": option(ReactDOMRe.Style.t),
    "grid-xs-6": option(ReactDOMRe.Style.t),
    "grid-xs-7": option(ReactDOMRe.Style.t),
    "grid-xs-8": option(ReactDOMRe.Style.t),
    "grid-xs-9": option(ReactDOMRe.Style.t),
    "grid-xs-auto": option(ReactDOMRe.Style.t),
    "grid-xs-true": option(ReactDOMRe.Style.t),
    "item": option(ReactDOMRe.Style.t),
    "justify-xs-center": option(ReactDOMRe.Style.t),
    "justify-xs-flex-end": option(ReactDOMRe.Style.t),
    "justify-xs-space-around": option(ReactDOMRe.Style.t),
    "justify-xs-space-between": option(ReactDOMRe.Style.t),
    "justify-xs-space-evenly": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "spacing-xs-1": option(ReactDOMRe.Style.t),
    "spacing-xs-10": option(ReactDOMRe.Style.t),
    "spacing-xs-2": option(ReactDOMRe.Style.t),
    "spacing-xs-3": option(ReactDOMRe.Style.t),
    "spacing-xs-4": option(ReactDOMRe.Style.t),
    "spacing-xs-5": option(ReactDOMRe.Style.t),
    "spacing-xs-6": option(ReactDOMRe.Style.t),
    "spacing-xs-7": option(ReactDOMRe.Style.t),
    "spacing-xs-8": option(ReactDOMRe.Style.t),
    "spacing-xs-9": option(ReactDOMRe.Style.t),
    "wrap-xs-nowrap": option(ReactDOMRe.Style.t),
    "wrap-xs-wrap-reverse": option(ReactDOMRe.Style.t),
    "zeroMinWidth": option(ReactDOMRe.Style.t),
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
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module GridListTileClassKey = {
  type t = {
    .
    "imgFullHeight": option(ReactDOMRe.Style.t),
    "imgFullWidth": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "tile": option(ReactDOMRe.Style.t),
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
    "actionIcon": option(ReactDOMRe.Style.t),
    "actionIconActionPosLeft": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "rootSubtitle": option(ReactDOMRe.Style.t),
    "subtitle": option(ReactDOMRe.Style.t),
    "title": option(ReactDOMRe.Style.t),
    "titlePositionBottom": option(ReactDOMRe.Style.t),
    "titlePositionTop": option(ReactDOMRe.Style.t),
    "titleWrap": option(ReactDOMRe.Style.t),
    "titleWrapActionPosLeft": option(ReactDOMRe.Style.t),
    "titleWrapActionPosRight": option(ReactDOMRe.Style.t),
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
    "colorAction": option(string),
    "colorDisabled": option(string),
    "colorError": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "fontSizeInherit": option(float),
    "fontSizeLarge": option(float),
    "fontSizeSmall": option(float),
    "root": option(ReactDOMRe.Style.t),
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
    "colorInherit": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "disabled": option(ReactDOMRe.Style.t),
    "edgeEnd": option(ReactDOMRe.Style.t),
    "edgeStart": option(ReactDOMRe.Style.t),
    "label": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "sizeSmall": option(ReactDOMRe.Style.t),
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
    "colorSecondary": option(string),
    "disabled": option(ReactDOMRe.Style.t),
    "error": option(ReactDOMRe.Style.t),
    "focused": option(ReactDOMRe.Style.t),
    "formControl": option(ReactDOMRe.Style.t),
    "fullWidth": option(ReactDOMRe.Style.t),
    "input": option(ReactDOMRe.Style.t),
    "inputMarginDense": option(ReactDOMRe.Style.t),
    "inputMultiline": option(ReactDOMRe.Style.t),
    "inputTypeSearch": option(ReactDOMRe.Style.t),
    "marginDense": option(ReactDOMRe.Style.t),
    "multiline": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "underline": option(ReactDOMRe.Style.t),
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
    "disablePointerEvents": option(ReactDOMRe.Style.t),
    "filled": option(ReactDOMRe.Style.t),
    "hiddenLabel": option(ReactDOMRe.Style.t),
    "marginDense": option(ReactDOMRe.Style.t),
    "positionEnd": option(ReactDOMRe.Style.t),
    "positionStart": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "adornedEnd": option(ReactDOMRe.Style.t),
    "adornedStart": option(ReactDOMRe.Style.t),
    "colorSecondary": option(string),
    "disabled": option(ReactDOMRe.Style.t),
    "error": option(ReactDOMRe.Style.t),
    "focused": option(ReactDOMRe.Style.t),
    "formControl": option(ReactDOMRe.Style.t),
    "fullWidth": option(ReactDOMRe.Style.t),
    "input": option(ReactDOMRe.Style.t),
    "inputAdornedEnd": option(ReactDOMRe.Style.t),
    "inputAdornedStart": option(ReactDOMRe.Style.t),
    "inputHiddenLabel": option(ReactDOMRe.Style.t),
    "inputMarginDense": option(ReactDOMRe.Style.t),
    "inputMultiline": option(ReactDOMRe.Style.t),
    "inputTypeSearch": option(ReactDOMRe.Style.t),
    "marginDense": option(ReactDOMRe.Style.t),
    "multiline": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "animated": option(ReactDOMRe.Style.t),
    "asterisk": option(ReactDOMRe.Style.t),
    "disabled": option(ReactDOMRe.Style.t),
    "error": option(ReactDOMRe.Style.t),
    "filled": option(ReactDOMRe.Style.t),
    "focused": option(ReactDOMRe.Style.t),
    "formControl": option(ReactDOMRe.Style.t),
    "marginDense": option(ReactDOMRe.Style.t),
    "outlined": option(ReactDOMRe.Style.t),
    "required": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "shrink": option(ReactDOMRe.Style.t),
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
    "bar": option(ReactDOMRe.Style.t),
    "bar1Buffer": option(ReactDOMRe.Style.t),
    "bar1Determinate": option(ReactDOMRe.Style.t),
    "bar1Indeterminate": option(ReactDOMRe.Style.t),
    "bar2Buffer": option(ReactDOMRe.Style.t),
    "bar2Indeterminate": option(ReactDOMRe.Style.t),
    "barColorPrimary": option(ReactDOMRe.Style.t),
    "barColorSecondary": option(ReactDOMRe.Style.t),
    "buffer": option(ReactDOMRe.Style.t),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "dashed": option(ReactDOMRe.Style.t),
    "dashedColorPrimary": option(ReactDOMRe.Style.t),
    "dashedColorSecondary": option(ReactDOMRe.Style.t),
    "determinate": option(ReactDOMRe.Style.t),
    "indeterminate": option(ReactDOMRe.Style.t),
    "query": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "button": option(ReactDOMRe.Style.t),
    "focusVisible": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "underlineAlways": option(ReactDOMRe.Style.t),
    "underlineHover": option(ReactDOMRe.Style.t),
    "underlineNone": option(ReactDOMRe.Style.t),
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
    "dense": option(ReactDOMRe.Style.t),
    "padding": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "subheader": option(ReactDOMRe.Style.t),
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
    "button": option(ReactDOMRe.Style.t),
    "container": option(ReactDOMRe.Style.t),
    "default": option(ReactDOMRe.Style.t),
    "dense": option(ReactDOMRe.Style.t),
    "disabled": option(ReactDOMRe.Style.t),
    "divider": option(ReactDOMRe.Style.t),
    "focusVisible": option(ReactDOMRe.Style.t),
    "gutters": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "secondaryAction": option(ReactDOMRe.Style.t),
    "selected": option(ReactDOMRe.Style.t),
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
    "icon": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (~icon: ReactDOMRe.Style.t=?, ~root: ReactDOMRe.Style.t=?, unit) => t;
};

module ListItemIconClassKey = {
  type t = {
    .
    "alignItemsFlexStart": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (
      ~alignItemsFlexStart: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
      unit
    ) =>
    t;
};

module MuiListItemSecondaryAction = {
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module ListItemTextClassKey = {
  type t = {
    .
    "dense": option(ReactDOMRe.Style.t),
    "inset": option(ReactDOMRe.Style.t),
    "multiline": option(ReactDOMRe.Style.t),
    "primary": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "secondary": option(ReactDOMRe.Style.t),
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
    "colorInherit": option(string),
    "colorPrimary": option(string),
    "gutters": option(ReactDOMRe.Style.t),
    "inset": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "sticky": option(ReactDOMRe.Style.t),
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
    "list": option(ReactDOMRe.Style.t),
    "paper": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (~list: ReactDOMRe.Style.t=?, ~paper: ReactDOMRe.Style.t=?, unit) => t;
};

module MenuItemClassKey = {
  type t = {
    .
    "dense": option(ReactDOMRe.Style.t),
    "gutters": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "selected": option(ReactDOMRe.Style.t),
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
    "dot": option(ReactDOMRe.Style.t),
    "dotActive": option(ReactDOMRe.Style.t),
    "dots": option(ReactDOMRe.Style.t),
    "positionBottom": option(ReactDOMRe.Style.t),
    "positionStatic": option(ReactDOMRe.Style.t),
    "positionTop": option(ReactDOMRe.Style.t),
    "progress": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "disabled": option(ReactDOMRe.Style.t),
    "filled": option(ReactDOMRe.Style.t),
    "icon": option(ReactDOMRe.Style.t),
    "iconFilled": option(ReactDOMRe.Style.t),
    "iconOutlined": option(ReactDOMRe.Style.t),
    "outlined": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "select": option(ReactDOMRe.Style.t),
    "selectMenu": option(ReactDOMRe.Style.t),
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
    "adornedEnd": option(ReactDOMRe.Style.t),
    "adornedStart": option(ReactDOMRe.Style.t),
    "colorSecondary": option(string),
    "disabled": option(ReactDOMRe.Style.t),
    "error": option(ReactDOMRe.Style.t),
    "focused": option(ReactDOMRe.Style.t),
    "input": option(ReactDOMRe.Style.t),
    "inputAdornedEnd": option(ReactDOMRe.Style.t),
    "inputAdornedStart": option(ReactDOMRe.Style.t),
    "inputMarginDense": option(ReactDOMRe.Style.t),
    "inputMultiline": option(ReactDOMRe.Style.t),
    "marginDense": option(ReactDOMRe.Style.t),
    "multiline": option(ReactDOMRe.Style.t),
    "notchedOutline": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "elevation0": option(ReactDOMRe.Style.t),
    "elevation1": option(ReactDOMRe.Style.t),
    "elevation10": option(ReactDOMRe.Style.t),
    "elevation11": option(ReactDOMRe.Style.t),
    "elevation12": option(ReactDOMRe.Style.t),
    "elevation13": option(ReactDOMRe.Style.t),
    "elevation14": option(ReactDOMRe.Style.t),
    "elevation15": option(ReactDOMRe.Style.t),
    "elevation16": option(ReactDOMRe.Style.t),
    "elevation17": option(ReactDOMRe.Style.t),
    "elevation18": option(ReactDOMRe.Style.t),
    "elevation19": option(ReactDOMRe.Style.t),
    "elevation2": option(ReactDOMRe.Style.t),
    "elevation20": option(ReactDOMRe.Style.t),
    "elevation21": option(ReactDOMRe.Style.t),
    "elevation22": option(ReactDOMRe.Style.t),
    "elevation23": option(ReactDOMRe.Style.t),
    "elevation24": option(ReactDOMRe.Style.t),
    "elevation3": option(ReactDOMRe.Style.t),
    "elevation4": option(ReactDOMRe.Style.t),
    "elevation5": option(ReactDOMRe.Style.t),
    "elevation6": option(ReactDOMRe.Style.t),
    "elevation7": option(ReactDOMRe.Style.t),
    "elevation8": option(ReactDOMRe.Style.t),
    "elevation9": option(ReactDOMRe.Style.t),
    "outlined": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "rounded": option(ReactDOMRe.Style.t),
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
    "paper": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (~paper: ReactDOMRe.Style.t=?, ~root: ReactDOMRe.Style.t=?, unit) => t;
};

module RadioClassKey = {
  type t = {
    .
    "checked": option(ReactDOMRe.Style.t),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "disabled": option(ReactDOMRe.Style.t),
    "input": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module SelectClassKey = {
  type t = {
    .
    "disabled": option(ReactDOMRe.Style.t),
    "filled": option(ReactDOMRe.Style.t),
    "icon": option(ReactDOMRe.Style.t),
    "iconFilled": option(ReactDOMRe.Style.t),
    "iconOpen": option(ReactDOMRe.Style.t),
    "iconOutlined": option(ReactDOMRe.Style.t),
    "outlined": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "select": option(ReactDOMRe.Style.t),
    "selectMenu": option(ReactDOMRe.Style.t),
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
    "active": option(ReactDOMRe.Style.t),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "disabled": option(ReactDOMRe.Style.t),
    "focusVisible": option(ReactDOMRe.Style.t),
    "mark": option(ReactDOMRe.Style.t),
    "markActive": option(ReactDOMRe.Style.t),
    "markLabel": option(ReactDOMRe.Style.t),
    "markLabelActive": option(ReactDOMRe.Style.t),
    "marked": option(ReactDOMRe.Style.t),
    "rail": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "thumb": option(ReactDOMRe.Style.t),
    "thumbColorPrimary": option(ReactDOMRe.Style.t),
    "thumbColorSecondary": option(ReactDOMRe.Style.t),
    "track": option(ReactDOMRe.Style.t),
    "trackFalse": option(ReactDOMRe.Style.t),
    "trackInverted": option(ReactDOMRe.Style.t),
    "valueLabel": option(ReactDOMRe.Style.t),
    "vertical": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (
      ~active: ReactDOMRe.Style.t=?,
      ~colorPrimary: string=?,
      ~colorSecondary: string=?,
      ~disabled: ReactDOMRe.Style.t=?,
      ~focusVisible: ReactDOMRe.Style.t=?,
      ~mark: ReactDOMRe.Style.t=?,
      ~markActive: ReactDOMRe.Style.t=?,
      ~markLabel: ReactDOMRe.Style.t=?,
      ~markLabelActive: ReactDOMRe.Style.t=?,
      ~marked: ReactDOMRe.Style.t=?,
      ~rail: ReactDOMRe.Style.t=?,
      ~root: ReactDOMRe.Style.t=?,
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
    "anchorOriginBottomCenter": option(ReactDOMRe.Style.t),
    "anchorOriginBottomLeft": option(ReactDOMRe.Style.t),
    "anchorOriginBottomRight": option(ReactDOMRe.Style.t),
    "anchorOriginTopCenter": option(ReactDOMRe.Style.t),
    "anchorOriginTopLeft": option(ReactDOMRe.Style.t),
    "anchorOriginTopRight": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "action": option(ReactDOMRe.Style.t),
    "message": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "alternativeLabel": option(ReactDOMRe.Style.t),
    "completed": option(ReactDOMRe.Style.t),
    "horizontal": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "vertical": option(ReactDOMRe.Style.t),
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
    "root": option(ReactDOMRe.Style.t),
    "touchRipple": option(ReactDOMRe.Style.t),
    "vertical": option(ReactDOMRe.Style.t),
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
    "active": option(ReactDOMRe.Style.t),
    "alternativeLabel": option(ReactDOMRe.Style.t),
    "completed": option(ReactDOMRe.Style.t),
    "disabled": option(ReactDOMRe.Style.t),
    "horizontal": option(ReactDOMRe.Style.t),
    "line": option(ReactDOMRe.Style.t),
    "lineHorizontal": option(ReactDOMRe.Style.t),
    "lineVertical": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "vertical": option(ReactDOMRe.Style.t),
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
    "last": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "transition": option(ReactDOMRe.Style.t),
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
    "active": option(ReactDOMRe.Style.t),
    "completed": option(ReactDOMRe.Style.t),
    "error": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "text": option(ReactDOMRe.Style.t),
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
    "active": option(ReactDOMRe.Style.t),
    "alternativeLabel": option(ReactDOMRe.Style.t),
    "completed": option(ReactDOMRe.Style.t),
    "disabled": option(ReactDOMRe.Style.t),
    "error": option(ReactDOMRe.Style.t),
    "horizontal": option(ReactDOMRe.Style.t),
    "iconContainer": option(ReactDOMRe.Style.t),
    "label": option(ReactDOMRe.Style.t),
    "labelContainer": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "vertical": option(ReactDOMRe.Style.t),
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
    "alternativeLabel": option(ReactDOMRe.Style.t),
    "horizontal": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "vertical": option(ReactDOMRe.Style.t),
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
    "checked": option(ReactDOMRe.Style.t),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "disabled": option(ReactDOMRe.Style.t),
    "input": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "sizeSmall": option(ReactDOMRe.Style.t),
    "switchBase": option(ReactDOMRe.Style.t),
    "thumb": option(ReactDOMRe.Style.t),
    "track": option(ReactDOMRe.Style.t),
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
    "disabled": option(ReactDOMRe.Style.t),
    "fullWidth": option(ReactDOMRe.Style.t),
    "labelIcon": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "selected": option(ReactDOMRe.Style.t),
    "textColorInherit": option(ReactDOMRe.Style.t),
    "textColorPrimary": option(ReactDOMRe.Style.t),
    "textColorSecondary": option(ReactDOMRe.Style.t),
    "wrapped": option(ReactDOMRe.Style.t),
    "wrapper": option(ReactDOMRe.Style.t),
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
    "root": option(ReactDOMRe.Style.t),
    "stickyHeader": option(ReactDOMRe.Style.t),
  };
  [@bs.obj]
  external make:
    (~root: ReactDOMRe.Style.t=?, ~stickyHeader: ReactDOMRe.Style.t=?, unit) =>
    t;
};

module MuiTableBody = {
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module TableCellClassKey = {
  type t = {
    .
    "alignCenter": option(ReactDOMRe.Style.t),
    "alignJustify": option(ReactDOMRe.Style.t),
    "alignLeft": option(ReactDOMRe.Style.t),
    "alignRight": option(ReactDOMRe.Style.t),
    "body": option(ReactDOMRe.Style.t),
    "footer": option(ReactDOMRe.Style.t),
    "head": option(ReactDOMRe.Style.t),
    "paddingCheckbox": option(ReactDOMRe.Style.t),
    "paddingNone": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "sizeSmall": option(ReactDOMRe.Style.t),
    "stickyHeader": option(ReactDOMRe.Style.t),
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
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiTableFooter = {
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module MuiTableHead = {
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module TablePaginationClassKey = {
  type t = {
    .
    "actions": option(ReactDOMRe.Style.t),
    "caption": option(ReactDOMRe.Style.t),
    "input": option(ReactDOMRe.Style.t),
    "menuItem": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "select": option(ReactDOMRe.Style.t),
    "selectIcon": option(ReactDOMRe.Style.t),
    "selectRoot": option(ReactDOMRe.Style.t),
    "spacer": option(ReactDOMRe.Style.t),
    "toolbar": option(ReactDOMRe.Style.t),
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
    "footer": option(ReactDOMRe.Style.t),
    "head": option(ReactDOMRe.Style.t),
    "hover": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "selected": option(ReactDOMRe.Style.t),
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
    "active": option(ReactDOMRe.Style.t),
    "icon": option(ReactDOMRe.Style.t),
    "iconDirectionAsc": option(ReactDOMRe.Style.t),
    "iconDirectionDesc": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "centered": option(ReactDOMRe.Style.t),
    "fixed": option(ReactDOMRe.Style.t),
    "flexContainer": option(ReactDOMRe.Style.t),
    "indicator": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "scrollButtons": option(ReactDOMRe.Style.t),
    "scrollButtonsDesktop": option(ReactDOMRe.Style.t),
    "scrollable": option(ReactDOMRe.Style.t),
    "scroller": option(ReactDOMRe.Style.t),
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
  type t = {. "root": option(ReactDOMRe.Style.t)};
  [@bs.obj] external make: (~root: ReactDOMRe.Style.t=?, unit) => t;
};

module ToolbarClassKey = {
  type t = {
    .
    "dense": option(ReactDOMRe.Style.t),
    "gutters": option(ReactDOMRe.Style.t),
    "regular": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "arrow": option(ReactDOMRe.Style.t),
    "popper": option(ReactDOMRe.Style.t),
    "popperArrow": option(ReactDOMRe.Style.t),
    "popperInteractive": option(ReactDOMRe.Style.t),
    "tooltip": option(ReactDOMRe.Style.t),
    "tooltipArrow": option(ReactDOMRe.Style.t),
    "tooltipPlacementBottom": option(ReactDOMRe.Style.t),
    "tooltipPlacementLeft": option(ReactDOMRe.Style.t),
    "tooltipPlacementRight": option(ReactDOMRe.Style.t),
    "tooltipPlacementTop": option(ReactDOMRe.Style.t),
    "touch": option(ReactDOMRe.Style.t),
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
    "child": option(ReactDOMRe.Style.t),
    "childLeaving": option(ReactDOMRe.Style.t),
    "childPulsate": option(ReactDOMRe.Style.t),
    "ripple": option(ReactDOMRe.Style.t),
    "ripplePulsate": option(ReactDOMRe.Style.t),
    "rippleVisible": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
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
    "alignCenter": option(ReactDOMRe.Style.t),
    "alignJustify": option(ReactDOMRe.Style.t),
    "alignLeft": option(ReactDOMRe.Style.t),
    "alignRight": option(ReactDOMRe.Style.t),
    "body1": option(ReactDOMRe.Style.t),
    "body2": option(ReactDOMRe.Style.t),
    "button": option(ReactDOMRe.Style.t),
    "caption": option(ReactDOMRe.Style.t),
    "colorError": option(string),
    "colorInherit": option(string),
    "colorPrimary": option(string),
    "colorSecondary": option(string),
    "colorTextPrimary": option(string),
    "colorTextSecondary": option(string),
    "displayBlock": option(ReactDOMRe.Style.t),
    "displayInline": option(ReactDOMRe.Style.t),
    "gutterBottom": option(ReactDOMRe.Style.t),
    "h1": option(ReactDOMRe.Style.t),
    "h2": option(ReactDOMRe.Style.t),
    "h3": option(ReactDOMRe.Style.t),
    "h4": option(ReactDOMRe.Style.t),
    "h5": option(ReactDOMRe.Style.t),
    "h6": option(ReactDOMRe.Style.t),
    "noWrap": option(ReactDOMRe.Style.t),
    "overline": option(ReactDOMRe.Style.t),
    "paragraph": option(ReactDOMRe.Style.t),
    "root": option(ReactDOMRe.Style.t),
    "srOnly": option(ReactDOMRe.Style.t),
    "subtitle1": option(ReactDOMRe.Style.t),
    "subtitle2": option(ReactDOMRe.Style.t),
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
    "MuiAccordion": option(AccordionClassKey.t),
    "MuiAccordionActions": option(AccordionActionsClassKey.t),
    "MuiAccordionDetails": option(MuiAccordionDetails.t),
    "MuiAccordionSummary": option(AccordionSummaryClassKey.t),
    "MuiAppBar": option(AppBarClassKey.t),
    "MuiAvatar": option(AvatarClassKey.t),
    "MuiBackdrop": option(BackdropClassKey.t),
    "MuiBadge": option(BadgeClassKey.t),
    "MuiBottomNavigation": option(MuiBottomNavigation.t),
    "MuiBottomNavigationAction": option(BottomNavigationActionClassKey.t),
    "MuiBreadcrumbs": option(BreadcrumbsClassKey.t),
    "MuiButton": option(ButtonClassKey.t),
    "MuiButtonBase": option(ButtonBaseClassKey.t),
    "MuiButtonGroup": option(ButtonGroupClassKey.t),
    "MuiCard": option(MuiCard.t),
    "MuiCardActionArea": option(CardActionAreaClassKey.t),
    "MuiCardActions": option(AccordionActionsClassKey.t),
    "MuiCardContent": option(MuiCardContent.t),
    "MuiCardHeader": option(CardHeaderClassKey.t),
    "MuiCardMedia": option(CardMediaClassKey.t),
    "MuiCheckbox": option(CheckboxClassKey.t),
    "MuiChip": option(ChipClassKey.t),
    "MuiCircularProgress": option(CircularProgressClassKey.t),
    "MuiCollapse": option(CollapseClassKey.t),
    "MuiContainer": option(ContainerClassKey.t),
    "MuiCssBaseline": option(MuiCssBaseline.t),
    "MuiDialog": option(DialogClassKey.t),
    "MuiDialogActions": option(AccordionActionsClassKey.t),
    "MuiDialogContent": option(DialogContentClassKey.t),
    "MuiDialogContentText": option(MuiDialogContentText.t),
    "MuiDialogTitle": option(MuiDialogTitle.t),
    "MuiDivider": option(DividerClassKey.t),
    "MuiDrawer": option(DrawerClassKey.t),
    "MuiExpansionPanel": option(AccordionClassKey.t),
    "MuiExpansionPanelActions": option(AccordionActionsClassKey.t),
    "MuiExpansionPanelDetails": option(MuiExpansionPanelDetails.t),
    "MuiExpansionPanelSummary": option(AccordionSummaryClassKey.t),
    "MuiFab": option(FabClassKey.t),
    "MuiFilledInput": option(FilledInputClassKey.t),
    "MuiFormControl": option(FormControlClassKey.t),
    "MuiFormControlLabel": option(FormControlLabelClassKey.t),
    "MuiFormGroup": option(FormGroupClassKey.t),
    "MuiFormHelperText": option(FormHelperTextClassKey.t),
    "MuiFormLabel": option(FormLabelClassKey.t),
    "MuiGrid": option(GridClassKey.t),
    "MuiGridList": option(MuiGridList.t),
    "MuiGridListTile": option(GridListTileClassKey.t),
    "MuiGridListTileBar": option(GridListTileBarClassKey.t),
    "MuiIcon": option(SvgIconClassKey.t),
    "MuiIconButton": option(IconButtonClassKey.t),
    "MuiInput": option(InputClassKey.t),
    "MuiInputAdornment": option(InputAdornmentClassKey.t),
    "MuiInputBase": option(InputBaseClassKey.t),
    "MuiInputLabel": option(InputLabelClassKey.t),
    "MuiLinearProgress": option(LinearProgressClassKey.t),
    "MuiLink": option(LinkClassKey.t),
    "MuiList": option(ListClassKey.t),
    "MuiListItem": option(ListItemClassKey.t),
    "MuiListItemAvatar": option(ListItemAvatarClassKey.t),
    "MuiListItemIcon": option(ListItemIconClassKey.t),
    "MuiListItemSecondaryAction": option(MuiListItemSecondaryAction.t),
    "MuiListItemText": option(ListItemTextClassKey.t),
    "MuiListSubheader": option(ListSubheaderClassKey.t),
    "MuiMenu": option(MenuClassKey.t),
    "MuiMenuItem": option(MenuItemClassKey.t),
    "MuiMobileStepper": option(MobileStepperClassKey.t),
    "MuiNativeSelect": option(NativeSelectClassKey.t),
    "MuiOutlinedInput": option(OutlinedInputClassKey.t),
    "MuiPaper": option(PaperClassKey.t),
    "MuiPopover": option(PopoverClassKey.t),
    "MuiRadio": option(RadioClassKey.t),
    "MuiScopedCssBaseline": option(MuiScopedCssBaseline.t),
    "MuiSelect": option(SelectClassKey.t),
    "MuiSlider": option(SliderClassKey.t),
    "MuiSnackbar": option(SnackbarClassKey.t),
    "MuiSnackbarContent": option(SnackbarContentClassKey.t),
    "MuiStep": option(StepClasskey.t),
    "MuiStepButton": option(StepButtonClasskey.t),
    "MuiStepConnector": option(StepConnectorClasskey.t),
    "MuiStepContent": option(StepContentClasskey.t),
    "MuiStepIcon": option(StepIconClasskey.t),
    "MuiStepLabel": option(StepLabelClasskey.t),
    "MuiStepper": option(StepperClasskey.t),
    "MuiSvgIcon": option(SvgIconClassKey.t),
    "MuiSwitch": option(SwitchClassKey.t),
    "MuiTab": option(TabClassKey.t),
    "MuiTable": option(TableClassKey.t),
    "MuiTableBody": option(MuiTableBody.t),
    "MuiTableCell": option(TableCellClassKey.t),
    "MuiTableContainer": option(MuiTableContainer.t),
    "MuiTableFooter": option(MuiTableFooter.t),
    "MuiTableHead": option(MuiTableHead.t),
    "MuiTablePagination": option(TablePaginationClassKey.t),
    "MuiTableRow": option(TableRowClassKey.t),
    "MuiTableSortLabel": option(TableSortLabelClassKey.t),
    "MuiTabs": option(TabsClassKey.t),
    "MuiTextField": option(MuiTextField.t),
    "MuiToolbar": option(ToolbarClassKey.t),
    "MuiTooltip": option(TooltipClassKey.t),
    "MuiTouchRipple": option(TouchRippleClassKey.t),
    "MuiTypography": option(TypographyClassKey.t),
  };
  [@bs.obj]
  external make:
    (
      ~muiAccordion: AccordionClassKey.t=?,
      ~muiAccordionActions: AccordionActionsClassKey.t=?,
      ~muiAccordionDetails: MuiAccordionDetails.t=?,
      ~muiAccordionSummary: AccordionSummaryClassKey.t=?,
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
      ~muiCardActions: AccordionActionsClassKey.t=?,
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
      ~muiDialogActions: AccordionActionsClassKey.t=?,
      ~muiDialogContent: DialogContentClassKey.t=?,
      ~muiDialogContentText: MuiDialogContentText.t=?,
      ~muiDialogTitle: MuiDialogTitle.t=?,
      ~muiDivider: DividerClassKey.t=?,
      ~muiDrawer: DrawerClassKey.t=?,
      ~muiExpansionPanel: AccordionClassKey.t=?,
      ~muiExpansionPanelActions: AccordionActionsClassKey.t=?,
      ~muiExpansionPanelDetails: MuiExpansionPanelDetails.t=?,
      ~muiExpansionPanelSummary: AccordionSummaryClassKey.t=?,
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
      ~muiListItemIcon: ListItemIconClassKey.t=?,
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
    "activatedOpacity": option(float),
    "active": option(string),
    "disabled": option(string),
    "disabledBackground": option(string),
    "disabledOpacity": option(float),
    "focus": option(string),
    "focusOpacity": option(float),
    "hover": option(string),
    "hoverOpacity": option(float),
    "selected": option(string),
    "selectedOpacity": option(float),
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
    "default": option(string),
    "paper": option(string),
  };
  [@bs.obj] external make: (~default: string=?, ~paper: string=?, unit) => t;
};

module CommonColors = {
  type t = {
    .
    "black": option(string),
    "white": option(string),
  };
  [@bs.obj] external make: (~black: string=?, ~white: string=?, unit) => t;
};

module Error = {
  type t = {
    .
    "50": option(string),
    "100": option(string),
    "200": option(string),
    "300": option(string),
    "400": option(string),
    "500": option(string),
    "600": option(string),
    "700": option(string),
    "800": option(string),
    "900": option(string),
    "A100": option(string),
    "A200": option(string),
    "A400": option(string),
    "A700": option(string),
    "contrastText": option(string),
    "dark": option(string),
    "light": option(string),
    "main": option(string),
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
    "50": option(string),
    "100": option(string),
    "200": option(string),
    "300": option(string),
    "400": option(string),
    "500": option(string),
    "600": option(string),
    "700": option(string),
    "800": option(string),
    "900": option(string),
    "A100": option(string),
    "A200": option(string),
    "A400": option(string),
    "A700": option(string),
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
    "50": option(string),
    "100": option(string),
    "200": option(string),
    "300": option(string),
    "400": option(string),
    "500": option(string),
    "600": option(string),
    "700": option(string),
    "800": option(string),
    "900": option(string),
    "A100": option(string),
    "A200": option(string),
    "A400": option(string),
    "A700": option(string),
    "contrastText": option(string),
    "dark": option(string),
    "light": option(string),
    "main": option(string),
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
    "50": option(string),
    "100": option(string),
    "200": option(string),
    "300": option(string),
    "400": option(string),
    "500": option(string),
    "600": option(string),
    "700": option(string),
    "800": option(string),
    "900": option(string),
    "A100": option(string),
    "A200": option(string),
    "A400": option(string),
    "A700": option(string),
    "contrastText": option(string),
    "dark": option(string),
    "light": option(string),
    "main": option(string),
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
    "50": option(string),
    "100": option(string),
    "200": option(string),
    "300": option(string),
    "400": option(string),
    "500": option(string),
    "600": option(string),
    "700": option(string),
    "800": option(string),
    "900": option(string),
    "A100": option(string),
    "A200": option(string),
    "A400": option(string),
    "A700": option(string),
    "contrastText": option(string),
    "dark": option(string),
    "light": option(string),
    "main": option(string),
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
    "50": option(string),
    "100": option(string),
    "200": option(string),
    "300": option(string),
    "400": option(string),
    "500": option(string),
    "600": option(string),
    "700": option(string),
    "800": option(string),
    "900": option(string),
    "A100": option(string),
    "A200": option(string),
    "A400": option(string),
    "A700": option(string),
    "contrastText": option(string),
    "dark": option(string),
    "light": option(string),
    "main": option(string),
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
    "disabled": option(string),
    "hint": option(string),
    "primary": option(string),
    "secondary": option(string),
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
    "dark": option(float),
    "light": option(float),
  };
  [@bs.obj] external make: (~dark: float=?, ~light: float=?, unit) => t;
};

module Warning = {
  type t = {
    .
    "50": option(string),
    "100": option(string),
    "200": option(string),
    "300": option(string),
    "400": option(string),
    "500": option(string),
    "600": option(string),
    "700": option(string),
    "800": option(string),
    "900": option(string),
    "A100": option(string),
    "A200": option(string),
    "A400": option(string),
    "A700": option(string),
    "contrastText": option(string),
    "dark": option(string),
    "light": option(string),
    "main": option(string),
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
    "action": option(TypeAction.t),
    "background": option(TypeBackground.t),
    "common": option(CommonColors.t),
    "contrastThreshold": option(float),
    "divider": option(string),
    "error": option(Error.t),
    "getContrastText": option(MaterialUi_Types.any),
    "grey": option(Color.t),
    "info": option(Info.t),
    "primary": option(Primary.t),
    "secondary": option(Secondary.t),
    "success": option(Success.t),
    "text": option(TypeText.t),
    "tonalOffset": option(TonalOffset.t),
    "type": option(string),
    "warning": option(Warning.t),
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
  type t = {. "borderRadius": option(float)};
  [@bs.obj] external make: (~borderRadius: float=?, unit) => t;
};

module Duration = {
  type t = {
    .
    "complex": option(float),
    "enteringScreen": option(float),
    "leavingScreen": option(float),
    "short": option(float),
    "shorter": option(float),
    "shortest": option(float),
    "standard": option(float),
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
    "easeIn": option(string),
    "easeInOut": option(string),
    "easeOut": option(string),
    "sharp": option(string),
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
    "create": option(MaterialUi_Types.any),
    "duration": option(Duration.t),
    "easing": option(Easing.t),
    "getAutoHeightDuration": option(MaterialUi_Types.any),
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
  type t = {. "@font-face": option(MaterialUi_Types.any)};
  [@bs.obj] external make: (~fontFace: MaterialUi_Types.any=?, unit) => t;
};

module Typography = {
  type t = {
    .
    "body1": option(TypographyStyleOptions.t),
    "body2": option(TypographyStyleOptions.t),
    "button": option(TypographyStyleOptions.t),
    "caption": option(TypographyStyleOptions.t),
    "fontFamily": option(string),
    "fontSize": option(float),
    "fontWeightBold": option(string),
    "fontWeightLight": option(string),
    "fontWeightMedium": option(string),
    "fontWeightRegular": option(string),
    "h1": option(TypographyStyleOptions.t),
    "h2": option(TypographyStyleOptions.t),
    "h3": option(TypographyStyleOptions.t),
    "h4": option(TypographyStyleOptions.t),
    "h5": option(TypographyStyleOptions.t),
    "h6": option(TypographyStyleOptions.t),
    "htmlFontSize": option(float),
    "overline": option(TypographyStyleOptions.t),
    "subtitle1": option(TypographyStyleOptions.t),
    "subtitle2": option(TypographyStyleOptions.t),
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
    "appBar": option(float),
    "drawer": option(float),
    "mobileStepper": option(float),
    "modal": option(float),
    "snackbar": option(float),
    "speedDial": option(float),
    "tooltip": option(float),
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
  "breakpoints": option(Breakpoints.t),
  "direction": option(string),
  "mixins": option(MixinsOptions.t),
  "overrides": option(Overrides.t),
  "palette": option(PaletteOptions.t),
  "props": option(MaterialUi_Types.any),
  "shadows": option(array(string)),
  "shape": option(Shape.t),
  "spacing": option(MaterialUi_Types.any),
  "transitions": option(TransitionsOptions.t),
  "typography": option(Typography.t),
  "unstable_strictMode": option(bool),
  "zIndex": option(ZIndex.t),
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
    ~unstable_strictMode: bool=?,
    ~zIndex: ZIndex.t=?,
    unit
  ) =>
  t;
