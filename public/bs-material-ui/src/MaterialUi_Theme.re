module BreakpointValues = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "lg"]
    lg: float,
    [@bs.as "md"]
    md: float,
    [@bs.as "sm"]
    sm: float,
    [@bs.as "xl"]
    xl: float,
    [@bs.as "xs"]
    xs: float,
  };

  let make = t;
};

module Breakpoints = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "between"]
    between: Js.Json.t,
    [@bs.as "down"]
    down: Js.Json.t,
    [@bs.as "keys"]
    keys: array(string),
    [@bs.as "only"]
    only: Js.Json.t,
    [@bs.as "up"]
    up: Js.Json.t,
    [@bs.as "values"]
    values: BreakpointValues.t,
    [@bs.as "width"]
    width: Js.Json.t,
  };

  let make = t;
};

module Mixins = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "gutters"]
    gutters: Js.Json.t,
    [@bs.as "toolbar"]
    toolbar: ReactDOMRe.Style.t,
  };

  let make = t;
};

module AppBarClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "colorDefault"]
    colorDefault: string,
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "positionAbsolute"]
    positionAbsolute: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "positionFixed"]
    positionFixed: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "positionRelative"]
    positionRelative: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "positionStatic"]
    positionStatic: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "positionSticky"]
    positionSticky: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module AvatarClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "colorDefault"]
    colorDefault: string,
    [@bs.optional] [@bs.as "img"]
    img: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module BackdropClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "invisible"]
    invisible: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module BadgeClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "anchorOriginBottomLeftRectangle"]
    anchorOriginBottomLeftRectangle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "anchorOriginBottomRightCircle"]
    anchorOriginBottomRightCircle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "anchorOriginBottomRightRectangle"]
    anchorOriginBottomRightRectangle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "anchorOriginTopLeftCircle"]
    anchorOriginTopLeftCircle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "anchorOriginTopLeftRectangle"]
    anchorOriginTopLeftRectangle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "anchorOriginTopRightCircle"]
    anchorOriginTopRightCircle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "anchorOriginTopRightRectangle"]
    anchorOriginTopRightRectangle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "badge"]
    badge: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "colorError"]
    colorError: string,
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "dot"]
    dot: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "invisible"]
    invisible: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiBottomNavigation = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module BottomNavigationActionClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "iconOnly"]
    iconOnly: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "label"]
    label: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "selected"]
    selected: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "wrapper"]
    wrapper: ReactDOMRe.Style.t,
  };

  let make = t;
};

module BreadcrumbsClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "li"]
    li: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "ol"]
    ol: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "separator"]
    separator: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ButtonClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "colorInherit"]
    colorInherit: string,
    [@bs.optional] [@bs.as "contained"]
    contained: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "containedPrimary"]
    containedPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "containedSecondary"]
    containedSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "containedSizeLarge"]
    containedSizeLarge: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "containedSizeSmall"]
    containedSizeSmall: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "endIcon"]
    endIcon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focusVisible"]
    focusVisible: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "fullWidth"]
    fullWidth: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "iconSizeLarge"]
    iconSizeLarge: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "iconSizeMedium"]
    iconSizeMedium: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "iconSizeSmall"]
    iconSizeSmall: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "label"]
    label: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "outlined"]
    outlined: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "outlinedPrimary"]
    outlinedPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "outlinedSecondary"]
    outlinedSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "outlinedSizeLarge"]
    outlinedSizeLarge: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "outlinedSizeSmall"]
    outlinedSizeSmall: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "sizeLarge"]
    sizeLarge: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "sizeSmall"]
    sizeSmall: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "startIcon"]
    startIcon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "text"]
    text: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "textPrimary"]
    textPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "textSecondary"]
    textSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "textSizeLarge"]
    textSizeLarge: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "textSizeSmall"]
    textSizeSmall: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ButtonBaseClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focusVisible"]
    focusVisible: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ButtonGroupClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "contained"]
    contained: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "fullWidth"]
    fullWidth: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grouped"]
    grouped: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "groupedContained"]
    groupedContained: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "groupedContainedPrimary"]
    groupedContainedPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "groupedContainedSecondary"]
    groupedContainedSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "groupedOutlined"]
    groupedOutlined: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "groupedOutlinedPrimary"]
    groupedOutlinedPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "groupedOutlinedSecondary"]
    groupedOutlinedSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "groupedText"]
    groupedText: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "groupedTextPrimary"]
    groupedTextPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "groupedTextSecondary"]
    groupedTextSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiCard = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module CardActionAreaClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "focusHighlight"]
    focusHighlight: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focusVisible"]
    focusVisible: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module CardActionsClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacing"]
    spacing: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiCardContent = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module CardHeaderClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "action"]
    action: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "avatar"]
    avatar: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "content"]
    content: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "subheader"]
    subheader: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "title"]
    title: ReactDOMRe.Style.t,
  };

  let make = t;
};

module CardMediaClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "media"]
    media: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module CheckboxClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "checked"]
    checked: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "indeterminate"]
    indeterminate: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "input"]
    input: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ChipClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "avatar"]
    avatar: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "avatarColorPrimary"]
    avatarColorPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "avatarColorSecondary"]
    avatarColorSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "avatarSmall"]
    avatarSmall: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "clickable"]
    clickable: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "clickableColorPrimary"]
    clickableColorPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "clickableColorSecondary"]
    clickableColorSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "deletable"]
    deletable: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "deletableColorPrimary"]
    deletableColorPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "deletableColorSecondary"]
    deletableColorSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "deleteIcon"]
    deleteIcon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "deleteIconColorPrimary"]
    deleteIconColorPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "deleteIconColorSecondary"]
    deleteIconColorSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "deleteIconOutlinedColorPrimary"]
    deleteIconOutlinedColorPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "deleteIconOutlinedColorSecondary"]
    deleteIconOutlinedColorSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "deleteIconSmall"]
    deleteIconSmall: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "icon"]
    icon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "iconColorPrimary"]
    iconColorPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "iconColorSecondary"]
    iconColorSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "iconSmall"]
    iconSmall: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "label"]
    label: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "labelSmall"]
    labelSmall: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "outlined"]
    outlined: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "outlinedPrimary"]
    outlinedPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "outlinedSecondary"]
    outlinedSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "sizeSmall"]
    sizeSmall: ReactDOMRe.Style.t,
  };

  let make = t;
};

module CircularProgressClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "circle"]
    circle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "circleDisableShrink"]
    circleDisableShrink: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "circleIndeterminate"]
    circleIndeterminate: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "circleStatic"]
    circleStatic: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "indeterminate"]
    indeterminate: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "static"]
    static: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "svg"]
    svg: ReactDOMRe.Style.t,
  };

  let make = t;
};

module CollapseClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "container"]
    container: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "entered"]
    entered: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "wrapper"]
    wrapper: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "wrapperInner"]
    wrapperInner: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ContainerClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "fixed"]
    fixed: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "maxWidthLg"]
    maxWidthLg: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "maxWidthMd"]
    maxWidthMd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "maxWidthSm"]
    maxWidthSm: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "maxWidthXl"]
    maxWidthXl: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "maxWidthXs"]
    maxWidthXs: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiCssBaseline = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "@global"]
    global: ReactDOMRe.Style.t,
  };

  let make = t;
};

module DialogClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "container"]
    container: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paper"]
    paper: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperFullScreen"]
    paperFullScreen: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperFullWidth"]
    paperFullWidth: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperScrollBody"]
    paperScrollBody: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperScrollPaper"]
    paperScrollPaper: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperWidthFalse"]
    paperWidthFalse: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperWidthLg"]
    paperWidthLg: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperWidthMd"]
    paperWidthMd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperWidthSm"]
    paperWidthSm: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperWidthXl"]
    paperWidthXl: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperWidthXs"]
    paperWidthXs: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "scrollBody"]
    scrollBody: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "scrollPaper"]
    scrollPaper: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiDialogContent = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiDialogContentText = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiDialogTitle = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module DividerClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "absolute"]
    absolute: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inset"]
    inset: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "light"]
    light: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "middle"]
    middle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "vertical"]
    vertical: ReactDOMRe.Style.t,
  };

  let make = t;
};

module DrawerClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "docked"]
    docked: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "modal"]
    modal: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paper"]
    paper: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperAnchorBottom"]
    paperAnchorBottom: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperAnchorDockedBottom"]
    paperAnchorDockedBottom: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperAnchorDockedLeft"]
    paperAnchorDockedLeft: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperAnchorDockedRight"]
    paperAnchorDockedRight: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperAnchorDockedTop"]
    paperAnchorDockedTop: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperAnchorLeft"]
    paperAnchorLeft: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperAnchorRight"]
    paperAnchorRight: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paperAnchorTop"]
    paperAnchorTop: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ExpansionPanelClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "expanded"]
    expanded: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "rounded"]
    rounded: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiExpansionPanelDetails = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ExpansionPanelSummaryClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "content"]
    content: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "expandIcon"]
    expandIcon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "expanded"]
    expanded: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focused"]
    focused: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module FabClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "colorInherit"]
    colorInherit: string,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "extended"]
    extended: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focusVisible"]
    focusVisible: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "label"]
    label: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "primary"]
    primary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "secondary"]
    secondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "sizeMedium"]
    sizeMedium: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "sizeSmall"]
    sizeSmall: ReactDOMRe.Style.t,
  };

  let make = t;
};

module FilledInputClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "adornedEnd"]
    adornedEnd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "adornedStart"]
    adornedStart: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "error"]
    error: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focused"]
    focused: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "formControl"]
    formControl: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "fullWidth"]
    fullWidth: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "input"]
    input: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputAdornedEnd"]
    inputAdornedEnd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputAdornedStart"]
    inputAdornedStart: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputHiddenLabel"]
    inputHiddenLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputMarginDense"]
    inputMarginDense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputMultiline"]
    inputMultiline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputTypeSearch"]
    inputTypeSearch: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "marginDense"]
    marginDense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "multiline"]
    multiline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "underline"]
    underline: ReactDOMRe.Style.t,
  };

  let make = t;
};

module FormControlClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "fullWidth"]
    fullWidth: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "marginDense"]
    marginDense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "marginNormal"]
    marginNormal: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module FormControlLabelClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "label"]
    label: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "start"]
    start: ReactDOMRe.Style.t,
  };

  let make = t;
};

module FormGroupClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "row"]
    row: ReactDOMRe.Style.t,
  };

  let make = t;
};

module FormHelperTextClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "contained"]
    contained: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "error"]
    error: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "filled"]
    filled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focused"]
    focused: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "marginDense"]
    marginDense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "required"]
    required: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module FormLabelClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "asterisk"]
    asterisk: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "error"]
    error: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "filled"]
    filled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focused"]
    focused: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "required"]
    required: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module GridClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "align-content-xs-center"]
    alignContentXsCenter: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "align-content-xs-flex-end"]
    alignContentXsFlexEnd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "align-content-xs-flex-start"]
    alignContentXsFlexStart: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "align-content-xs-space-around"]
    alignContentXsSpaceAround: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "align-content-xs-space-between"]
    alignContentXsSpaceBetween: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "align-items-xs-baseline"]
    alignItemsXsBaseline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "align-items-xs-center"]
    alignItemsXsCenter: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "align-items-xs-flex-end"]
    alignItemsXsFlexEnd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "align-items-xs-flex-start"]
    alignItemsXsFlexStart: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "container"]
    container: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "direction-xs-column"]
    directionXsColumn: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "direction-xs-column-reverse"]
    directionXsColumnReverse: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "direction-xs-row-reverse"]
    directionXsRowReverse: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-1"]
    gridXs1: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-10"]
    gridXs10: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-11"]
    gridXs11: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-12"]
    gridXs12: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-2"]
    gridXs2: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-3"]
    gridXs3: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-4"]
    gridXs4: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-5"]
    gridXs5: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-6"]
    gridXs6: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-7"]
    gridXs7: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-8"]
    gridXs8: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-9"]
    gridXs9: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-auto"]
    gridXsAuto: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "grid-xs-true"]
    gridXsTrue: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "item"]
    item: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "justify-xs-center"]
    justifyXsCenter: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "justify-xs-flex-end"]
    justifyXsFlexEnd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "justify-xs-space-around"]
    justifyXsSpaceAround: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "justify-xs-space-between"]
    justifyXsSpaceBetween: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacing-xs-1"]
    spacingXs1: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacing-xs-10"]
    spacingXs10: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacing-xs-2"]
    spacingXs2: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacing-xs-3"]
    spacingXs3: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacing-xs-4"]
    spacingXs4: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacing-xs-5"]
    spacingXs5: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacing-xs-6"]
    spacingXs6: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacing-xs-7"]
    spacingXs7: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacing-xs-8"]
    spacingXs8: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacing-xs-9"]
    spacingXs9: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "wrap-xs-nowrap"]
    wrapXsNowrap: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "wrap-xs-wrap-reverse"]
    wrapXsWrapReverse: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiGridList = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module GridListTileClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "imgFullHeight"]
    imgFullHeight: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "imgFullWidth"]
    imgFullWidth: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "tile"]
    tile: ReactDOMRe.Style.t,
  };

  let make = t;
};

module GridListTileBarClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "actionIcon"]
    actionIcon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "actionIconActionPosLeft"]
    actionIconActionPosLeft: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "rootSubtitle"]
    rootSubtitle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "subtitle"]
    subtitle: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "title"]
    title: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "titlePositionBottom"]
    titlePositionBottom: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "titlePositionTop"]
    titlePositionTop: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "titleWrap"]
    titleWrap: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "titleWrapActionPosLeft"]
    titleWrapActionPosLeft: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "titleWrapActionPosRight"]
    titleWrapActionPosRight: ReactDOMRe.Style.t,
  };

  let make = t;
};

module IconClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "colorAction"]
    colorAction: string,
    [@bs.optional] [@bs.as "colorDisabled"]
    colorDisabled: string,
    [@bs.optional] [@bs.as "colorError"]
    colorError: string,
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "fontSizeInherit"]
    fontSizeInherit: string,
    [@bs.optional] [@bs.as "fontSizeLarge"]
    fontSizeLarge: string,
    [@bs.optional] [@bs.as "fontSizeSmall"]
    fontSizeSmall: string,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module IconButtonClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "colorInherit"]
    colorInherit: string,
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "edgeEnd"]
    edgeEnd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "edgeStart"]
    edgeStart: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "label"]
    label: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "sizeSmall"]
    sizeSmall: ReactDOMRe.Style.t,
  };

  let make = t;
};

module InputClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "error"]
    error: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focused"]
    focused: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "formControl"]
    formControl: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "fullWidth"]
    fullWidth: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "input"]
    input: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputMarginDense"]
    inputMarginDense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputMultiline"]
    inputMultiline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputTypeSearch"]
    inputTypeSearch: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "multiline"]
    multiline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "underline"]
    underline: ReactDOMRe.Style.t,
  };

  let make = t;
};

module InputAdornmentClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "disablePointerEvents"]
    disablePointerEvents: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "filled"]
    filled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "hiddenLabel"]
    hiddenLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "marginDense"]
    marginDense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "positionEnd"]
    positionEnd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "positionStart"]
    positionStart: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module InputBaseClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "adornedEnd"]
    adornedEnd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "adornedStart"]
    adornedStart: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "error"]
    error: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focused"]
    focused: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "formControl"]
    formControl: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "fullWidth"]
    fullWidth: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "input"]
    input: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputAdornedEnd"]
    inputAdornedEnd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputAdornedStart"]
    inputAdornedStart: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputHiddenLabel"]
    inputHiddenLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputMarginDense"]
    inputMarginDense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputMultiline"]
    inputMultiline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputTypeSearch"]
    inputTypeSearch: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "marginDense"]
    marginDense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "multiline"]
    multiline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module InputLabelClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "animated"]
    animated: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "asterisk"]
    asterisk: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "error"]
    error: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "filled"]
    filled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focused"]
    focused: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "formControl"]
    formControl: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "marginDense"]
    marginDense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "outlined"]
    outlined: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "required"]
    required: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "shrink"]
    shrink: ReactDOMRe.Style.t,
  };

  let make = t;
};

module LinearProgressClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "bar"]
    bar: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "bar1Buffer"]
    bar1Buffer: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "bar1Determinate"]
    bar1Determinate: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "bar1Indeterminate"]
    bar1Indeterminate: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "bar2Buffer"]
    bar2Buffer: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "bar2Indeterminate"]
    bar2Indeterminate: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "barColorPrimary"]
    barColorPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "barColorSecondary"]
    barColorSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "buffer"]
    buffer: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "dashed"]
    dashed: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "dashedColorPrimary"]
    dashedColorPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "dashedColorSecondary"]
    dashedColorSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "determinate"]
    determinate: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "indeterminate"]
    indeterminate: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "query"]
    query: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module LinkClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "button"]
    button: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focusVisible"]
    focusVisible: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "underlineAlways"]
    underlineAlways: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "underlineHover"]
    underlineHover: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "underlineNone"]
    underlineNone: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ListClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "dense"]
    dense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "padding"]
    padding: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "subheader"]
    subheader: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ListItemClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "button"]
    button: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "container"]
    container: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "default"]
    default: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "dense"]
    dense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "divider"]
    divider: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focusVisible"]
    focusVisible: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "gutters"]
    gutters: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "secondaryAction"]
    secondaryAction: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "selected"]
    selected: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ListItemAvatarClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "icon"]
    icon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiListItemIcon = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiListItemSecondaryAction = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ListItemTextClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "dense"]
    dense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inset"]
    inset: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "multiline"]
    multiline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "primary"]
    primary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "secondary"]
    secondary: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ListSubheaderClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "colorInherit"]
    colorInherit: string,
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "gutters"]
    gutters: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inset"]
    inset: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "sticky"]
    sticky: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MenuClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "list"]
    list: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paper"]
    paper: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MenuItemClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "dense"]
    dense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "gutters"]
    gutters: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "selected"]
    selected: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MobileStepperClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "dot"]
    dot: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "dotActive"]
    dotActive: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "dots"]
    dots: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "positionBottom"]
    positionBottom: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "positionStatic"]
    positionStatic: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "positionTop"]
    positionTop: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "progress"]
    progress: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module NativeSelectClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "filled"]
    filled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "icon"]
    icon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "iconFilled"]
    iconFilled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "iconOutlined"]
    iconOutlined: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "outlined"]
    outlined: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "select"]
    select: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "selectMenu"]
    selectMenu: ReactDOMRe.Style.t,
  };

  let make = t;
};

module OutlinedInputClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "adornedEnd"]
    adornedEnd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "adornedStart"]
    adornedStart: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "error"]
    error: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "focused"]
    focused: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "input"]
    input: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputAdornedEnd"]
    inputAdornedEnd: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputAdornedStart"]
    inputAdornedStart: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputMarginDense"]
    inputMarginDense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputMultiline"]
    inputMultiline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "inputSelect"]
    inputSelect: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "marginDense"]
    marginDense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "multiline"]
    multiline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "notchedOutline"]
    notchedOutline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module PaperClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "elevation0"]
    elevation0: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation1"]
    elevation1: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation10"]
    elevation10: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation11"]
    elevation11: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation12"]
    elevation12: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation13"]
    elevation13: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation14"]
    elevation14: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation15"]
    elevation15: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation16"]
    elevation16: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation17"]
    elevation17: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation18"]
    elevation18: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation19"]
    elevation19: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation2"]
    elevation2: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation20"]
    elevation20: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation21"]
    elevation21: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation22"]
    elevation22: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation23"]
    elevation23: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation24"]
    elevation24: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation3"]
    elevation3: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation4"]
    elevation4: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation5"]
    elevation5: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation6"]
    elevation6: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation7"]
    elevation7: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation8"]
    elevation8: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "elevation9"]
    elevation9: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "rounded"]
    rounded: ReactDOMRe.Style.t,
  };

  let make = t;
};

module PopoverClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "paper"]
    paper: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module RadioClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "checked"]
    checked: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "input"]
    input: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module SliderClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "mark"]
    mark: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "markActive"]
    markActive: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "markLabel"]
    markLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "markLabelActive"]
    markLabelActive: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "marked"]
    marked: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "rail"]
    rail: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "rtl"]
    rtl: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "thumb"]
    thumb: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "thumbColorPrimary"]
    thumbColorPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "thumbColorSecondary"]
    thumbColorSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "track"]
    track: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "trackFalse"]
    trackFalse: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "trackInverted"]
    trackInverted: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "valueLabel"]
    valueLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "vertical"]
    vertical: ReactDOMRe.Style.t,
  };

  let make = t;
};

module SnackbarClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "anchorOriginBottomCenter"]
    anchorOriginBottomCenter: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "anchorOriginBottomLeft"]
    anchorOriginBottomLeft: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "anchorOriginBottomRight"]
    anchorOriginBottomRight: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "anchorOriginTopCenter"]
    anchorOriginTopCenter: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "anchorOriginTopLeft"]
    anchorOriginTopLeft: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "anchorOriginTopRight"]
    anchorOriginTopRight: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module SnackbarContentClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "action"]
    action: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "message"]
    message: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module StepClasskey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "alternativeLabel"]
    alternativeLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "completed"]
    completed: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "horizontal"]
    horizontal: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "vertical"]
    vertical: ReactDOMRe.Style.t,
  };

  let make = t;
};

module StepButtonClasskey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "touchRipple"]
    touchRipple: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "vertical"]
    vertical: ReactDOMRe.Style.t,
  };

  let make = t;
};

module StepConnectorClasskey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "active"]
    active: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "alternativeLabel"]
    alternativeLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "completed"]
    completed: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "horizontal"]
    horizontal: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "line"]
    line: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "lineHorizontal"]
    lineHorizontal: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "lineVertical"]
    lineVertical: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "vertical"]
    vertical: ReactDOMRe.Style.t,
  };

  let make = t;
};

module StepContentClasskey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "last"]
    last: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "transition"]
    transition: ReactDOMRe.Style.t,
  };

  let make = t;
};

module StepIconClasskey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "active"]
    active: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "completed"]
    completed: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "error"]
    error: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "text"]
    text: ReactDOMRe.Style.t,
  };

  let make = t;
};

module StepLabelClasskey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "active"]
    active: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "alternativeLabel"]
    alternativeLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "completed"]
    completed: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "error"]
    error: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "horizontal"]
    horizontal: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "iconContainer"]
    iconContainer: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "label"]
    label: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "labelContainer"]
    labelContainer: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "vertical"]
    vertical: ReactDOMRe.Style.t,
  };

  let make = t;
};

module StepperClasskey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "alternativeLabel"]
    alternativeLabel: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "horizontal"]
    horizontal: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "vertical"]
    vertical: ReactDOMRe.Style.t,
  };

  let make = t;
};

module SwitchClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "checked"]
    checked: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "colorPrimary"]
    colorPrimary: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "input"]
    input: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "sizeSmall"]
    sizeSmall: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "switchBase"]
    switchBase: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "thumb"]
    thumb: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "track"]
    track: ReactDOMRe.Style.t,
  };

  let make = t;
};

module TabClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "disabled"]
    disabled: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "fullWidth"]
    fullWidth: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "labelIcon"]
    labelIcon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "selected"]
    selected: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "textColorInherit"]
    textColorInherit: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "textColorPrimary"]
    textColorPrimary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "textColorSecondary"]
    textColorSecondary: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "wrapped"]
    wrapped: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "wrapper"]
    wrapper: ReactDOMRe.Style.t,
  };

  let make = t;
};

module TableClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "stickyHeader"]
    stickyHeader: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiTableBody = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module TableCellClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "alignCenter"]
    alignCenter: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "alignJustify"]
    alignJustify: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "alignLeft"]
    alignLeft: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "alignRight"]
    alignRight: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "body"]
    body: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "footer"]
    footer: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "head"]
    head: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paddingCheckbox"]
    paddingCheckbox: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paddingNone"]
    paddingNone: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "sizeSmall"]
    sizeSmall: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "stickyHeader"]
    stickyHeader: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiTableFooter = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiTableHead = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module TablePaginationClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "actions"]
    actions: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "caption"]
    caption: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "input"]
    input: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "menuItem"]
    menuItem: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "select"]
    select: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "selectIcon"]
    selectIcon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "selectRoot"]
    selectRoot: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "spacer"]
    spacer: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "toolbar"]
    toolbar: ReactDOMRe.Style.t,
  };

  let make = t;
};

module TableRowClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "footer"]
    footer: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "head"]
    head: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "hover"]
    hover: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "selected"]
    selected: ReactDOMRe.Style.t,
  };

  let make = t;
};

module TableSortLabelClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "active"]
    active: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "icon"]
    icon: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "iconDirectionAsc"]
    iconDirectionAsc: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "iconDirectionDesc"]
    iconDirectionDesc: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module TabsClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "centered"]
    centered: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "fixed"]
    fixed: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "flexContainer"]
    flexContainer: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "indicator"]
    indicator: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "scrollButtons"]
    scrollButtons: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "scrollButtonsDesktop"]
    scrollButtonsDesktop: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "scrollable"]
    scrollable: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "scroller"]
    scroller: ReactDOMRe.Style.t,
  };

  let make = t;
};

module MuiTextField = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module ToolbarClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "dense"]
    dense: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "gutters"]
    gutters: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "regular"]
    regular: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module TooltipClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "popper"]
    popper: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "popperInteractive"]
    popperInteractive: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "tooltip"]
    tooltip: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "tooltipPlacementBottom"]
    tooltipPlacementBottom: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "tooltipPlacementLeft"]
    tooltipPlacementLeft: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "tooltipPlacementRight"]
    tooltipPlacementRight: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "tooltipPlacementTop"]
    tooltipPlacementTop: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "touch"]
    touch: ReactDOMRe.Style.t,
  };

  let make = t;
};

module TouchRippleClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "child"]
    child: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "childLeaving"]
    childLeaving: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "childPulsate"]
    childPulsate: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "ripple"]
    ripple: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "ripplePulsate"]
    ripplePulsate: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "rippleVisible"]
    rippleVisible: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
  };

  let make = t;
};

module TypographyClassKey = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "alignCenter"]
    alignCenter: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "alignJustify"]
    alignJustify: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "alignLeft"]
    alignLeft: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "alignRight"]
    alignRight: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "body1"]
    body1: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "body2"]
    body2: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "button"]
    button: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "caption"]
    caption: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "colorError"]
    colorError: string,
    [@bs.optional] [@bs.as "colorInherit"]
    colorInherit: string,
    [@bs.optional] [@bs.as "colorSecondary"]
    colorSecondary: string,
    [@bs.optional] [@bs.as "colorTextSecondary"]
    colorTextSecondary: string,
    [@bs.optional] [@bs.as "displayBlock"]
    displayBlock: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "displayInline"]
    displayInline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "gutterBottom"]
    gutterBottom: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "h1"]
    h1: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "h2"]
    h2: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "h3"]
    h3: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "h4"]
    h4: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "h5"]
    h5: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "h6"]
    h6: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "noWrap"]
    noWrap: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "overline"]
    overline: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "paragraph"]
    paragraph: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "root"]
    root: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "srOnly"]
    srOnly: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "subtitle1"]
    subtitle1: ReactDOMRe.Style.t,
    [@bs.optional] [@bs.as "subtitle2"]
    subtitle2: ReactDOMRe.Style.t,
  };

  let make = t;
};

module Overrides = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional] [@bs.as "MuiAppBar"]
    muiAppBar: AppBarClassKey.t,
    [@bs.optional] [@bs.as "MuiAvatar"]
    muiAvatar: AvatarClassKey.t,
    [@bs.optional] [@bs.as "MuiBackdrop"]
    muiBackdrop: BackdropClassKey.t,
    [@bs.optional] [@bs.as "MuiBadge"]
    muiBadge: BadgeClassKey.t,
    [@bs.optional] [@bs.as "MuiBottomNavigation"]
    muiBottomNavigation: MuiBottomNavigation.t,
    [@bs.optional] [@bs.as "MuiBottomNavigationAction"]
    muiBottomNavigationAction: BottomNavigationActionClassKey.t,
    [@bs.optional] [@bs.as "MuiBreadcrumbs"]
    muiBreadcrumbs: BreadcrumbsClassKey.t,
    [@bs.optional] [@bs.as "MuiButton"]
    muiButton: ButtonClassKey.t,
    [@bs.optional] [@bs.as "MuiButtonBase"]
    muiButtonBase: ButtonBaseClassKey.t,
    [@bs.optional] [@bs.as "MuiButtonGroup"]
    muiButtonGroup: ButtonGroupClassKey.t,
    [@bs.optional] [@bs.as "MuiCard"]
    muiCard: MuiCard.t,
    [@bs.optional] [@bs.as "MuiCardActionArea"]
    muiCardActionArea: CardActionAreaClassKey.t,
    [@bs.optional] [@bs.as "MuiCardActions"]
    muiCardActions: CardActionsClassKey.t,
    [@bs.optional] [@bs.as "MuiCardContent"]
    muiCardContent: MuiCardContent.t,
    [@bs.optional] [@bs.as "MuiCardHeader"]
    muiCardHeader: CardHeaderClassKey.t,
    [@bs.optional] [@bs.as "MuiCardMedia"]
    muiCardMedia: CardMediaClassKey.t,
    [@bs.optional] [@bs.as "MuiCheckbox"]
    muiCheckbox: CheckboxClassKey.t,
    [@bs.optional] [@bs.as "MuiChip"]
    muiChip: ChipClassKey.t,
    [@bs.optional] [@bs.as "MuiCircularProgress"]
    muiCircularProgress: CircularProgressClassKey.t,
    [@bs.optional] [@bs.as "MuiCollapse"]
    muiCollapse: CollapseClassKey.t,
    [@bs.optional] [@bs.as "MuiContainer"]
    muiContainer: ContainerClassKey.t,
    [@bs.optional] [@bs.as "MuiCssBaseline"]
    muiCssBaseline: MuiCssBaseline.t,
    [@bs.optional] [@bs.as "MuiDialog"]
    muiDialog: DialogClassKey.t,
    [@bs.optional] [@bs.as "MuiDialogActions"]
    muiDialogActions: CardActionsClassKey.t,
    [@bs.optional] [@bs.as "MuiDialogContent"]
    muiDialogContent: MuiDialogContent.t,
    [@bs.optional] [@bs.as "MuiDialogContentText"]
    muiDialogContentText: MuiDialogContentText.t,
    [@bs.optional] [@bs.as "MuiDialogTitle"]
    muiDialogTitle: MuiDialogTitle.t,
    [@bs.optional] [@bs.as "MuiDivider"]
    muiDivider: DividerClassKey.t,
    [@bs.optional] [@bs.as "MuiDrawer"]
    muiDrawer: DrawerClassKey.t,
    [@bs.optional] [@bs.as "MuiExpansionPanel"]
    muiExpansionPanel: ExpansionPanelClassKey.t,
    [@bs.optional] [@bs.as "MuiExpansionPanelActions"]
    muiExpansionPanelActions: CardActionsClassKey.t,
    [@bs.optional] [@bs.as "MuiExpansionPanelDetails"]
    muiExpansionPanelDetails: MuiExpansionPanelDetails.t,
    [@bs.optional] [@bs.as "MuiExpansionPanelSummary"]
    muiExpansionPanelSummary: ExpansionPanelSummaryClassKey.t,
    [@bs.optional] [@bs.as "MuiFab"]
    muiFab: FabClassKey.t,
    [@bs.optional] [@bs.as "MuiFilledInput"]
    muiFilledInput: FilledInputClassKey.t,
    [@bs.optional] [@bs.as "MuiFormControl"]
    muiFormControl: FormControlClassKey.t,
    [@bs.optional] [@bs.as "MuiFormControlLabel"]
    muiFormControlLabel: FormControlLabelClassKey.t,
    [@bs.optional] [@bs.as "MuiFormGroup"]
    muiFormGroup: FormGroupClassKey.t,
    [@bs.optional] [@bs.as "MuiFormHelperText"]
    muiFormHelperText: FormHelperTextClassKey.t,
    [@bs.optional] [@bs.as "MuiFormLabel"]
    muiFormLabel: FormLabelClassKey.t,
    [@bs.optional] [@bs.as "MuiGrid"]
    muiGrid: GridClassKey.t,
    [@bs.optional] [@bs.as "MuiGridList"]
    muiGridList: MuiGridList.t,
    [@bs.optional] [@bs.as "MuiGridListTile"]
    muiGridListTile: GridListTileClassKey.t,
    [@bs.optional] [@bs.as "MuiGridListTileBar"]
    muiGridListTileBar: GridListTileBarClassKey.t,
    [@bs.optional] [@bs.as "MuiIcon"]
    muiIcon: IconClassKey.t,
    [@bs.optional] [@bs.as "MuiIconButton"]
    muiIconButton: IconButtonClassKey.t,
    [@bs.optional] [@bs.as "MuiInput"]
    muiInput: InputClassKey.t,
    [@bs.optional] [@bs.as "MuiInputAdornment"]
    muiInputAdornment: InputAdornmentClassKey.t,
    [@bs.optional] [@bs.as "MuiInputBase"]
    muiInputBase: InputBaseClassKey.t,
    [@bs.optional] [@bs.as "MuiInputLabel"]
    muiInputLabel: InputLabelClassKey.t,
    [@bs.optional] [@bs.as "MuiLinearProgress"]
    muiLinearProgress: LinearProgressClassKey.t,
    [@bs.optional] [@bs.as "MuiLink"]
    muiLink: LinkClassKey.t,
    [@bs.optional] [@bs.as "MuiList"]
    muiList: ListClassKey.t,
    [@bs.optional] [@bs.as "MuiListItem"]
    muiListItem: ListItemClassKey.t,
    [@bs.optional] [@bs.as "MuiListItemAvatar"]
    muiListItemAvatar: ListItemAvatarClassKey.t,
    [@bs.optional] [@bs.as "MuiListItemIcon"]
    muiListItemIcon: MuiListItemIcon.t,
    [@bs.optional] [@bs.as "MuiListItemSecondaryAction"]
    muiListItemSecondaryAction: MuiListItemSecondaryAction.t,
    [@bs.optional] [@bs.as "MuiListItemText"]
    muiListItemText: ListItemTextClassKey.t,
    [@bs.optional] [@bs.as "MuiListSubheader"]
    muiListSubheader: ListSubheaderClassKey.t,
    [@bs.optional] [@bs.as "MuiMenu"]
    muiMenu: MenuClassKey.t,
    [@bs.optional] [@bs.as "MuiMenuItem"]
    muiMenuItem: MenuItemClassKey.t,
    [@bs.optional] [@bs.as "MuiMobileStepper"]
    muiMobileStepper: MobileStepperClassKey.t,
    [@bs.optional] [@bs.as "MuiNativeSelect"]
    muiNativeSelect: NativeSelectClassKey.t,
    [@bs.optional] [@bs.as "MuiOutlinedInput"]
    muiOutlinedInput: OutlinedInputClassKey.t,
    [@bs.optional] [@bs.as "MuiPaper"]
    muiPaper: PaperClassKey.t,
    [@bs.optional] [@bs.as "MuiPopover"]
    muiPopover: PopoverClassKey.t,
    [@bs.optional] [@bs.as "MuiRadio"]
    muiRadio: RadioClassKey.t,
    [@bs.optional] [@bs.as "MuiSelect"]
    muiSelect: NativeSelectClassKey.t,
    [@bs.optional] [@bs.as "MuiSlider"]
    muiSlider: SliderClassKey.t,
    [@bs.optional] [@bs.as "MuiSnackbar"]
    muiSnackbar: SnackbarClassKey.t,
    [@bs.optional] [@bs.as "MuiSnackbarContent"]
    muiSnackbarContent: SnackbarContentClassKey.t,
    [@bs.optional] [@bs.as "MuiStep"]
    muiStep: StepClasskey.t,
    [@bs.optional] [@bs.as "MuiStepButton"]
    muiStepButton: StepButtonClasskey.t,
    [@bs.optional] [@bs.as "MuiStepConnector"]
    muiStepConnector: StepConnectorClasskey.t,
    [@bs.optional] [@bs.as "MuiStepContent"]
    muiStepContent: StepContentClasskey.t,
    [@bs.optional] [@bs.as "MuiStepIcon"]
    muiStepIcon: StepIconClasskey.t,
    [@bs.optional] [@bs.as "MuiStepLabel"]
    muiStepLabel: StepLabelClasskey.t,
    [@bs.optional] [@bs.as "MuiStepper"]
    muiStepper: StepperClasskey.t,
    [@bs.optional] [@bs.as "MuiSvgIcon"]
    muiSvgIcon: IconClassKey.t,
    [@bs.optional] [@bs.as "MuiSwitch"]
    muiSwitch: SwitchClassKey.t,
    [@bs.optional] [@bs.as "MuiTab"]
    muiTab: TabClassKey.t,
    [@bs.optional] [@bs.as "MuiTable"]
    muiTable: TableClassKey.t,
    [@bs.optional] [@bs.as "MuiTableBody"]
    muiTableBody: MuiTableBody.t,
    [@bs.optional] [@bs.as "MuiTableCell"]
    muiTableCell: TableCellClassKey.t,
    [@bs.optional] [@bs.as "MuiTableFooter"]
    muiTableFooter: MuiTableFooter.t,
    [@bs.optional] [@bs.as "MuiTableHead"]
    muiTableHead: MuiTableHead.t,
    [@bs.optional] [@bs.as "MuiTablePagination"]
    muiTablePagination: TablePaginationClassKey.t,
    [@bs.optional] [@bs.as "MuiTableRow"]
    muiTableRow: TableRowClassKey.t,
    [@bs.optional] [@bs.as "MuiTableSortLabel"]
    muiTableSortLabel: TableSortLabelClassKey.t,
    [@bs.optional] [@bs.as "MuiTabs"]
    muiTabs: TabsClassKey.t,
    [@bs.optional] [@bs.as "MuiTextField"]
    muiTextField: MuiTextField.t,
    [@bs.optional] [@bs.as "MuiToolbar"]
    muiToolbar: ToolbarClassKey.t,
    [@bs.optional] [@bs.as "MuiTooltip"]
    muiTooltip: TooltipClassKey.t,
    [@bs.optional] [@bs.as "MuiTouchRipple"]
    muiTouchRipple: TouchRippleClassKey.t,
    [@bs.optional] [@bs.as "MuiTypography"]
    muiTypography: TypographyClassKey.t,
  };

  let make = t;
};

module TypeAction = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "active"]
    active: string,
    [@bs.as "disabled"]
    disabled: string,
    [@bs.as "disabledBackground"]
    disabledBackground: string,
    [@bs.as "hover"]
    hover: string,
    [@bs.as "hoverOpacity"]
    hoverOpacity: float,
    [@bs.as "selected"]
    selected: string,
  };

  let make = t;
};

module TypeBackground = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "default"]
    default: string,
    [@bs.as "paper"]
    paper: string,
  };

  let make = t;
};

module CommonColors = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "black"]
    black: string,
    [@bs.as "white"]
    white: string,
  };

  let make = t;
};

module PaletteColor = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "contrastText"]
    contrastText: string,
    [@bs.as "dark"]
    dark: string,
    [@bs.as "light"]
    light: string,
    [@bs.as "main"]
    main: string,
  };

  let make = t;
};

module Color = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "50"]
    _50: string,
    [@bs.as "100"]
    _100: string,
    [@bs.as "200"]
    _200: string,
    [@bs.as "300"]
    _300: string,
    [@bs.as "400"]
    _400: string,
    [@bs.as "500"]
    _500: string,
    [@bs.as "600"]
    _600: string,
    [@bs.as "700"]
    _700: string,
    [@bs.as "800"]
    _800: string,
    [@bs.as "900"]
    _900: string,
    [@bs.as "A100"]
    a100: string,
    [@bs.as "A200"]
    a200: string,
    [@bs.as "A400"]
    a400: string,
    [@bs.as "A700"]
    a700: string,
  };

  let make = t;
};

module TypeText = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "disabled"]
    disabled: string,
    [@bs.as "hint"]
    hint: string,
    [@bs.as "primary"]
    primary: string,
    [@bs.as "secondary"]
    secondary: string,
  };

  let make = t;
};

module Palette = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "action"]
    action: TypeAction.t,
    [@bs.as "augmentColor"]
    augmentColor: Js.Json.t,
    [@bs.as "background"]
    background: TypeBackground.t,
    [@bs.as "common"]
    common: CommonColors.t,
    [@bs.as "contrastThreshold"]
    contrastThreshold: float,
    [@bs.as "divider"]
    divider: string,
    [@bs.as "error"]
    error: PaletteColor.t,
    [@bs.as "getContrastText"]
    getContrastText: Js.Json.t,
    [@bs.as "grey"]
    grey: Color.t,
    [@bs.as "primary"]
    primary: PaletteColor.t,
    [@bs.as "secondary"]
    secondary: PaletteColor.t,
    [@bs.as "text"]
    text: TypeText.t,
    [@bs.as "tonalOffset"]
    tonalOffset: float,
    [@bs.as "type"]
    type_: string,
  };

  let make = t;
};

module Shape = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "borderRadius"]
    borderRadius: float,
  };

  let make = t;
};

module Duration = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "complex"]
    complex: float,
    [@bs.as "enteringScreen"]
    enteringScreen: float,
    [@bs.as "leavingScreen"]
    leavingScreen: float,
    [@bs.as "short"]
    short: float,
    [@bs.as "shorter"]
    shorter: float,
    [@bs.as "shortest"]
    shortest: float,
    [@bs.as "standard"]
    standard: float,
  };

  let make = t;
};

module Easing = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "easeIn"]
    easeIn: string,
    [@bs.as "easeInOut"]
    easeInOut: string,
    [@bs.as "easeOut"]
    easeOut: string,
    [@bs.as "sharp"]
    sharp: string,
  };

  let make = t;
};

module Transitions = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "duration"]
    duration: Duration.t,
    [@bs.as "easing"]
    easing: Easing.t,
  };

  let make = t;
};

module Body1 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module Body2 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module Button = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module Caption = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module H1 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module H2 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module H3 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module H4 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module H5 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module H6 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module Overline = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module Subtitle1 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module Subtitle2 = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "color"]
    color: string,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontStyle"]
    fontStyle: string,
    [@bs.as "fontWeight"]
    fontWeight: string,
    [@bs.optional] [@bs.as "letterSpacing"]
    letterSpacing: string,
    [@bs.optional] [@bs.as "lineHeight"]
    lineHeight: string,
    [@bs.optional] [@bs.as "textTransform"]
    textTransform: string,
  };

  let make = t;
};

module Typography = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "body1"]
    body1: Body1.t,
    [@bs.as "body2"]
    body2: Body2.t,
    [@bs.as "button"]
    button: Button.t,
    [@bs.as "caption"]
    caption: Caption.t,
    [@bs.as "fontFamily"]
    fontFamily: string,
    [@bs.as "fontSize"]
    fontSize: string,
    [@bs.as "fontWeightBold"]
    fontWeightBold: string,
    [@bs.as "fontWeightLight"]
    fontWeightLight: string,
    [@bs.as "fontWeightMedium"]
    fontWeightMedium: string,
    [@bs.as "fontWeightRegular"]
    fontWeightRegular: string,
    [@bs.as "h1"]
    h1: H1.t,
    [@bs.as "h2"]
    h2: H2.t,
    [@bs.as "h3"]
    h3: H3.t,
    [@bs.as "h4"]
    h4: H4.t,
    [@bs.as "h5"]
    h5: H5.t,
    [@bs.as "h6"]
    h6: H6.t,
    [@bs.as "overline"]
    overline: Overline.t,
    [@bs.as "pxToRem"]
    pxToRem: Js.Json.t,
    [@bs.as "subtitle1"]
    subtitle1: Subtitle1.t,
    [@bs.as "subtitle2"]
    subtitle2: Subtitle2.t,
  };

  let make = t;
};

module ZIndex = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "appBar"]
    appBar: float,
    [@bs.as "drawer"]
    drawer: float,
    [@bs.as "mobileStepper"]
    mobileStepper: float,
    [@bs.as "modal"]
    modal: float,
    [@bs.as "snackbar"]
    snackbar: float,
    [@bs.as "tooltip"]
    tooltip: float,
  };

  let make = t;
};

module Theme = {
  [@bs.deriving abstract]
  type t = {
    [@bs.as "breakpoints"]
    breakpoints: Breakpoints.t,
    [@bs.as "direction"]
    direction: string,
    [@bs.as "mixins"]
    mixins: Mixins.t,
    [@bs.optional] [@bs.as "overrides"]
    overrides: Overrides.t,
    [@bs.as "palette"]
    palette: Palette.t,
    [@bs.optional] [@bs.as "props"]
    props: Js.Json.t,
    [@bs.as "shadows"]
    shadows: array(string),
    [@bs.as "shape"]
    shape: Shape.t,
    [@bs.as "spacing"]
    spacing: int => int,
    [@bs.as "transitions"]
    transitions: Transitions.t,
    [@bs.as "typography"]
    typography: Typography.t,
    [@bs.as "zIndex"]
    zIndex: ZIndex.t,
  };

  let make = t;
};
type t = Theme.t;
let make = Theme.make;

[@bs.module "@material-ui/core/styles"]
external create: MaterialUi_ThemeOptions.t => t = "createMuiTheme";
