module MuiTheme: {
  module Direction: {
    type t =
      | Ltr
      | Rtl;
    let toString: t => string;
    let fromString: string => t;
  };
  module Spacing: {type t = {unit: int};};
  module Transitions: {
    module Easing: {
      type t = {
        easeInOut: string,
        easeOut: string,
        easeIn: string,
        sharp: string
      };
    };
    module Duration: {
      type t = {
        shortest: int,
        shorter: int,
        short: int,
        standard: int,
        complex: int,
        enteringScreen: int,
        leavingScreen: int
      };
    };
    type t = {
      easing: Easing.t,
      duration: Duration.t,
      getAutoHeightDuration: int => int,
      create: (string, {. "duration": int}) => string
    };
  };
  type t = {
    direction: Direction.t,
    palette: unit,
    typography: unit,
    mixins: unit,
    breakpoints: unit,
    shadows: list(string),
    transitions: Transitions.t,
    spacing: Spacing.t,
    zIndex: int
  };
};

module WithStyles: {
  let make:
    (
      ~styles: Js.t({..})=?,
      ~stylesWithTheme: MuiTheme.t => Js.t({..})=?,
      ~render: 'a,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Colors: {
  module BlueGrey: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Grey: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Brown: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module DeepOrange: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Orange: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Amber: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Yellow: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Lime: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module LightGreen: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Green: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Teal: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Cyan: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module LightBlue: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Blue: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Indigo: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module DeepPurple: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Purple: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Pink: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Red: {
    let contrastDefaultColor: string;
    let a700: string;
    let a400: string;
    let a200: string;
    let a100: string;
    let c900: string;
    let c800: string;
    let c700: string;
    let c600: string;
    let c500: string;
    let c400: string;
    let c300: string;
    let c200: string;
    let c100: string;
    let c50: string;
  };
  module Common: {
    let lightWhite: string;
    let darkWhite: string;
    let fullWhite: string;
    let faintBlack: string;
    let minBlack: string;
    let lightBlack: string;
    let darkBlack: string;
    let fullBlack: string;
    let transparent: string;
    let white: string;
    let black: string;
  };
};

module Typography: {
  module Type: {
    type t =
      | Display4
      | Display3
      | Display2
      | Display1
      | Headline
      | Title
      | Subheading
      | Body2
      | Body1
      | Caption
      | Button;
    let to_string: t => string;
  };
  module Color: {
    type t =
      | Inherit
      | Primary
      | Secondary
      | Accent
      | Error
      | Default;
    let to_string: t => string;
  };
  module Align: {
    type t =
      | Inherit
      | Left
      | Center
      | Right
      | Justify;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | Display4(string)
      | Display3(string)
      | Display2(string)
      | Display1(string)
      | Headline(string)
      | Title(string)
      | Subheading(string)
      | Body2(string)
      | Body1(string)
      | Caption(string)
      | Button(string)
      | AlignLeft(string)
      | AlignCenter(string)
      | AlignRight(string)
      | AlignJustify(string)
      | NoWrap(string)
      | GutterBottom(string)
      | Paragraph(string)
      | ColorInherit(string)
      | ColorPrimary(string)
      | ColorSecondary(string)
      | ColorAccent(string)
      | ColorError(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Typography
       @param type Applies the theme typography styles.
       @param paragraph If `true`, the text will have a bottom margin.
       @param noWrap If `true`, the text will not wrap, but instead will truncate with an ellipsis.
       @param headlineMapping We are empirically mapping the type property to a range of different DOM element type.
       For instance, h1 to h6. If you wish to change that mapping, you can provide your own.
       Alternatively, you can use the `component` property.
       @param gutterBottom If `true`, the text will have a bottom margin.
       @param color The color of the component. It's using the theme palette when that makes sense.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       By default we map the type to a good default headline component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~type_: Type.t=?,
      ~paragraph: bool=?,
      ~noWrap: bool=?,
      ~headlineMapping: {. "unionProp": string}=?,
      ~gutterBottom: bool=?,
      ~color: Color.t=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~align: Align.t=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Tooltip: {
  module Placement: {
    type t =
      | Bottom_end
      | Bottom_start
      | Bottom
      | Left_end
      | Left_start
      | Left
      | Right_end
      | Right_start
      | Right
      | Top_end
      | Top_start
      | Top;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | Popper(string)
      | PopperClose(string)
      | Tooltip(string)
      | TooltipLeft(string)
      | TooltipRight(string)
      | TooltipTop(string)
      | TooltipBottom(string)
      | TooltipOpen(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Tooltip
       @param PopperProps Properties applied to the `Popper` element.
       @param placement Tooltip placement
       @param leaveDelay The number of milliseconds to wait before hidding the tooltip.
       @param enterDelay The number of milliseconds to wait before showing the tooltip.
       @param title Tooltip title.
       @param open If `true`, the tooltip is shown.
       @param onRequestOpen Callback fired when the tooltip requests to be open.

       @param {object} event The event source of the callback
       @param onRequestClose Callback fired when the tooltip requests to be closed.

       @param {object} event The event source of the callback
       @param id The relationship between the tooltip and the wrapper component is not clear from the DOM.
       By providing this property, we can use aria-describedby to solve the accessibility issue.
       @param disableTriggerTouch Do not respond to long press touch events.
       @param disableTriggerHover Do not respond to hover events.
       @param disableTriggerFocus Do not respond to focus events.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~pPopperProps: Js.t({..})=?,
      ~placement: Placement.t=?,
      ~leaveDelay: float=?,
      ~enterDelay: float=?,
      ~title: ReasonReact.reactElement,
      ~open_: bool=?,
      ~onRequestOpen: ReasonReact.Callback.t(ReactEventRe.Synthetic.t)=?,
      ~onRequestClose: ReasonReact.Callback.t(ReactEventRe.Synthetic.t)=?,
      ~id: string=?,
      ~disableTriggerTouch: bool=?,
      ~disableTriggerHover: bool=?,
      ~disableTriggerFocus: bool=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Toolbar: {
  module Classes: {
    type classesType =
      | Root(string)
      | Gutters(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Toolbar
       @param disableGutters If `true`, disables gutter padding.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~disableGutters: bool=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module TextField: {
  module Margin: {
    type t =
      | None
      | Dense
      | Normal;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | MarginNormal(string)
      | MarginDense(string)
      | FullWidth(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component TextField
       @param margin If `dense` or `normal`, will adjust vertical spacing of this and contained components.
       @param value The value of the `Input` element, required for a controlled component.
       @param type Type attribute of the `Input` element. It should be a valid HTML5 input type.
       @param SelectProps Properties applied to the `Select` element.
       @param select Render a `Select` element while passing the `Input` element to `Select` as `input` parameter.
       If this option is set you must pass the options of the select as children.
       @param rowsMax Maximum number of rows to display when multiline option is set to true.
       @param rows Number of rows to display when multiline option is set to true.
       @param rootRef Use that property to pass a ref callback to the root component.
       @param required If `true`, the label is displayed as required.
       @param placeholder The short hint displayed in the input before the user enters a value.
       @param onChange Callback fired when the value is changed.

       @param {object} event The event source of the callback
       @param name Name attribute of the `input` element.
       @param multiline If `true`, a textarea element will be rendered instead of an input.
       @param labelClassName The CSS class name of the label element.
       @param label The label content.
       @param inputRef Use that property to pass a ref callback to the native input component.
       @param InputProps Properties applied to the `Input` element.
       @param inputProps Properties applied to the `input` element.
       @param InputLabelProps Properties applied to the `InputLabel` element.
       @param InputClassName The CSS class name of the `Input` element.
       @param inputClassName The CSS class name of the `input` element.
       @param id The id of the `input` element.
       @param helperTextClassName The CSS class name of the helper text element.
       @param helperText The helper text content.
       @param fullWidth If `true`, the input will take up the full width of its container.
       @param FormHelperTextProps Properties applied to the `FormHelperText` element.
       @param error If `true`, the label will be displayed in an error state.
       @param disabled If `true`, the input will be disabled.
       @param defaultValue The default value of the `Input` element.
       @param className @ignore
       @param autoFocus If `true`, the input will be focused during the first mount.
       @param autoComplete This property helps users to fill forms faster, especially on mobile devices.
       The name can be confusion, it's more like an autofill.
       You can learn about it with that article
       https://developers.google.com/web/updates/2015/06/checkout-faster-with-autofill
       @param classes Useful to extend the style applied to components.
       @param theme @ignore
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param onBlur @ignore
       @param onFocus @ignore */
  let make:
    (
      ~margin: Margin.t=?,
      ~value: [ | `String(string) | `Float(float)]=?,
      ~type_: string=?,
      ~sSelectProps: Js.t({..})=?,
      ~select: bool=?,
      ~rowsMax: [ | `String(string) | `Float(float)]=?,
      ~rows: [ | `String(string) | `Float(float)]=?,
      ~rootRef: 'a=?,
      ~required: bool=?,
      ~placeholder: string=?,
      ~onChange: ReactEventRe.Form.t => unit=?,
      ~name: string=?,
      ~multiline: bool=?,
      ~labelClassName: string=?,
      ~label: ReasonReact.reactElement=?,
      ~inputRef: 'b=?,
      ~iInputProps: Js.t({..})=?,
      ~inputProps: Js.t({..})=?,
      ~iInputLabelProps: Js.t({..})=?,
      ~iInputClassName: string=?,
      ~inputClassName: string=?,
      ~id: string=?,
      ~helperTextClassName: string=?,
      ~helperText: ReasonReact.reactElement=?,
      ~fullWidth: bool=?,
      ~fFormHelperTextProps: Js.t({..})=?,
      ~error: bool=?,
      ~disabled: bool=?,
      ~defaultValue: string=?,
      ~className: string=?,
      ~autoFocus: bool=?,
      ~autoComplete: string=?,
      ~classes: Classes.t=?,
      ~theme: Js.t({..})=?,
      ~component: Js.t({..})=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Tabs: {
  module TextColor: {
    type t =
      | Accent
      | Primary
      | Inherit;
    let to_string: t => string;
  };
  module ScrollButtons: {
    type t =
      | Auto
      | On
      | Off;
    let to_string: t => string;
  };
  module IndicatorColor: {
    type t =
      | Accent
      | Primary;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | FlexContainer(string)
      | ScrollingContainer(string)
      | Fixed(string)
      | Scrollable(string)
      | Centered(string)
      | ButtonAuto(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Tabs
       @param value The value of the currently selected `Tab`.
       If you don't want any selected `Tab`, you can set this property to `false`.
       @param textColor Determines the color of the `Tab`.
       @param TabScrollButton The component used to render the scroll buttons.
       @param scrollButtons Determine behavior of scroll buttons when tabs are set to scroll
       `auto` will only present them on medium and larger viewports
       `on` will always present them
       `off` will never present them
       @param scrollable True invokes scrolling properties and allow for horizontally scrolling
       (or swiping) the tab bar.
       @param onChange Callback fired when the value changes.

       @param {object} event The event source of the callback
       @param {number} value We default to the index of the child
       @param indicatorColor Determines the color of the indicator.
       @param indicatorClassName The CSS class name of the indicator element.
       @param fullWidth If `true`, the tabs will grow to use all the available space.
       This property is intended for small views, like on mobile.
       @param className @ignore
       @param centered If `true`, the tabs will be centered.
       This property is intended for large views.
       @param buttonClassName The CSS class name of the scroll button elements.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~value: 'a,
      ~textColor: TextColor.t=?,
      ~tTabScrollButton: Js.t({..})=?,
      ~scrollButtons: ScrollButtons.t=?,
      ~scrollable: bool=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t),
      ~indicatorColor: [ | `Enum(IndicatorColor.t) | `String(string)]=?,
      ~indicatorClassName: string=?,
      ~fullWidth: bool=?,
      ~className: string=?,
      ~centered: bool=?,
      ~buttonClassName: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Table: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Table
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module TableSortLabel: {
  module Direction: {
    type t =
      | Asc
      | Desc;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | Active(string)
      | Icon(string)
      | Desc(string)
      | Asc(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component TableSortLabel
       @param direction The current sort direction.
       @param className @ignore
       @param active If `true`, the label will have the active styling (should be true for the sorted column).
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param centerRipple If `true`, the ripples will be centered.
       They won't start at the cursor interaction position.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       The default value is a `button`.
       @param disabled If `true`, the base button will be disabled.
       @param disableRipple If `true`, the ripple effect will be disabled.
       @param focusRipple If `true`, the base button will have a keyboard focus ripple.
       `disableRipple` must also be `false`.
       @param keyboardFocusedClassName The CSS class applied while the component is keyboard focused.
       @param onBlur @ignore
       @param onClick @ignore
       @param onFocus @ignore
       @param onKeyboardFocus Callback fired when the component is focused with a keyboard.
       We trigger a `onFocus` callback too.
       @param onKeyDown @ignore
       @param onKeyUp @ignore
       @param onMouseDown @ignore
       @param onMouseLeave @ignore
       @param onMouseUp @ignore
       @param onTouchEnd @ignore
       @param onTouchMove @ignore
       @param onTouchStart @ignore
       @param role @ignore
       @param rootRef Use that property to pass a ref callback to the root component.
       @param tabIndex @ignore
       @param type @ignore */
  let make:
    (
      ~direction: Direction.t=?,
      ~className: string=?,
      ~active: bool=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~centerRipple: bool=?,
      ~component: Js.t({..})=?,
      ~disabled: bool=?,
      ~disableRipple: bool=?,
      ~focusRipple: bool=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReactEventRe.Synthetic.t => unit=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~rootRef: 'a=?,
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      ~type_: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module TableRow: {
  module Classes: {
    type classesType =
      | Root(string)
      | Head(string)
      | Footer(string)
      | Hover(string)
      | Selected(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component TableRow
       @param selected If `true`, the table row will have the selected shading.
       @param hover If `true`, the table row will shade on hover.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~selected: bool=?,
      ~hover: bool=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module TablePagination: {
  module Padding: {
    type t =
      | Default
      | Checkbox
      | Dense
      | None;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | Toolbar(string)
      | Spacer(string)
      | Caption(string)
      | Input(string)
      | SelectRoot(string)
      | Select(string)
      | Actions(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component TablePagination
       @param rowsPerPageOptions Customizes the options of the rows per page select field. If less than two options are
       available, no select field will be displayed.
       @param rowsPerPage The number of rows per page.
       @param page The zero-based index of the current page.
       @param onChangeRowsPerPage Callback fired when the number of rows per page is changed.

       @param {object} event The event source of the callback
       @param onChangePage Callback fired when the page is changed.

       @param {object} event The event source of the callback
       @param {number} page The page selected
       @param labelRowsPerPage Useful to customize the rows per page label. Invoked with a `{ from, to, count, page }`
       object.
       @param labelDisplayedRows Useful to customize the displayed rows label.
       @param count The total number of rows.
       @param colSpan @ignore
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param className @ignore
       @param numeric If `true`, content will align to the right.
       @param padding Sets the padding applied to the cell. */
  let make:
    (
      ~rowsPerPageOptions: array(float)=?,
      ~rowsPerPage: float,
      ~page: float,
      ~onChangeRowsPerPage: ReactEventRe.Form.t => unit,
      ~onChangePage: (_, int) => unit,
      ~labelRowsPerPage: ReasonReact.reactElement=?,
      ~labelDisplayedRows: {. "from": int, "to": int, "count": int, "page": int} =>
                           ReasonReact.reactElement
                             =?,
      ~count: float,
      ~colSpan: float=?,
      ~component: Js.t({..})=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~className: string=?,
      ~numeric: bool=?,
      ~padding: Padding.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module TableHead: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component TableHead
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module TableFooter: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component TableFooter
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module TableCell: {
  module Padding: {
    type t =
      | Default
      | Checkbox
      | Dense
      | None;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | Numeric(string)
      | Head(string)
      | PaddingDefault(string)
      | PaddingDense(string)
      | PaddingCheckbox(string)
      | Footer(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component TableCell
       @param padding Sets the padding applied to the cell.
       @param numeric If `true`, content will align to the right.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~padding: Padding.t=?,
      ~numeric: bool=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module TableBody: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component TableBody
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Tab: {
  module TextColor: {
    type t =
      | Accent
      | Primary
      | Inherit;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | RootLabelIcon(string)
      | RootAccent(string)
      | RootAccentSelected(string)
      | RootAccentDisabled(string)
      | RootPrimary(string)
      | RootPrimarySelected(string)
      | RootPrimaryDisabled(string)
      | RootInherit(string)
      | RootInheritSelected(string)
      | RootInheritDisabled(string)
      | FullWidth(string)
      | Wrapper(string)
      | LabelContainer(string)
      | Label(string)
      | LabelWrapped(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Tab
       @param value You can provide your own value. Otherwise, we fallback to the child position index.
       @param textColor @ignore
       @param style @ignore
       @param selected @ignore
       @param onClick @ignore
       @param onChange @ignore
       @param label The label element.
       @param indicator @ignore
       For server side rendering consideration, we let the selected tab
       render the indicator.
       @param icon The icon element. If a string is provided, it will be used as a font ligature.
       @param fullWidth @ignore
       @param disabled If `true`, the tab will be disabled.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param centerRipple If `true`, the ripples will be centered.
       They won't start at the cursor interaction position.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       The default value is a `button`.
       @param disableRipple If `true`, the ripple effect will be disabled.
       @param focusRipple If `true`, the base button will have a keyboard focus ripple.
       `disableRipple` must also be `false`.
       @param keyboardFocusedClassName The CSS class applied while the component is keyboard focused.
       @param onBlur @ignore
       @param onFocus @ignore
       @param onKeyboardFocus Callback fired when the component is focused with a keyboard.
       We trigger a `onFocus` callback too.
       @param onKeyDown @ignore
       @param onKeyUp @ignore
       @param onMouseDown @ignore
       @param onMouseLeave @ignore
       @param onMouseUp @ignore
       @param onTouchEnd @ignore
       @param onTouchMove @ignore
       @param onTouchStart @ignore
       @param role @ignore
       @param rootRef Use that property to pass a ref callback to the root component.
       @param tabIndex @ignore
       @param type @ignore */
  let make:
    (
      ~value: 'a=?,
      ~textColor: [ | `Enum(TextColor.t) | `String(string)]=?,
      ~style: Js.t({..})=?,
      ~selected: bool=?,
      ~onClick: ReactEventRe.Synthetic.t => unit=?,
      ~onChange: (ReactEventRe.Synthetic.t, _) => unit=?,
      ~label: [ | `String(string) | `Element(ReasonReact.reactElement)]=?,
      ~indicator: [ | `String(string) | `Element(ReasonReact.reactElement)]=?,
      ~icon: [ | `String(string) | `Element(ReasonReact.reactElement)]=?,
      ~fullWidth: bool=?,
      ~disabled: bool=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~centerRipple: bool=?,
      ~component: Js.t({..})=?,
      ~disableRipple: bool=?,
      ~focusRipple: bool=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReactEventRe.Synthetic.t => unit=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~rootRef: 'b=?,
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      ~type_: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Switch: {
  module Classes: {
    type classesType =
      | Root(string)
      | Bar(string)
      | Icon(string)
      | Default(string)
      | Checked(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Switch
       @param value The value of the component.
       @param tabIndex @ignore
       @param onChange Callback fired when the state is changed.

       @param {object} event The event source of the callback
       @param {boolean} checked The `checked` value of the switch
       @param inputRef Use that property to pass a ref callback to the native input component.
       @param inputProps Properties applied to the `input` element.
       @param icon The icon to display when the component is unchecked.
       If a string is provided, it will be used as a font ligature.
       @param disableRipple If `true`, the ripple effect will be disabled.
       @param disabled If `true`, the switch will be disabled.
       @param defaultChecked @ignore
       @param className @ignore
       @param checkedIcon The icon to display when the component is checked.
       If a string is provided, it will be used as a font ligature.
       @param checked If `true`, the component is checked.
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~value: string=?,
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~name: string=?,
      ~inputRef: 'a=?,
      ~inputProps: Js.t({..})=?,
      ~icon: ReasonReact.reactElement=?,
      ~disableRipple: bool=?,
      ~disabled: bool=?,
      ~defaultChecked: bool=?,
      ~className: string=?,
      ~checkedIcon: ReasonReact.reactElement=?,
      ~checked: [ | `Bool(bool) | `String(string)]=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module SvgIcon: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component SvgIcon
       @param viewBox Allows you to redefine what the coordinates without units mean inside an svg element.
       For example, if the SVG element is 500 (width) by 200 (height),
       and you pass viewBox="0 0 50 20",
       this means that the coordinates inside the svg will go from the top left corner (0,0)
       to bottom right (50,20) and each unit will be worth 10px.
       @param titleAccess Provides a human-readable title for the element that contains it.
       https://www.w3.org/TR/SVG-access/#Equivalent
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~viewBox: string=?,
      ~titleAccess: string=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Stepper: {
  module Orientation: {
    type t =
      | Horizontal
      | Vertical;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | Horizontal(string)
      | Vertical(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Stepper
       @param className @ignore
       @param orientation The stepper orientation (layout flow direction).
       @param nonLinear If set the `Stepper` will not assist in controlling steps for linear flow.
       @param connector A component to be placed between each step.
       @param classes Useful to extend the style applied to components.
       @param alternativeLabel If set to 'true' and orientation is horizontal,
       then the step label will be positioned under the icon.
       @param activeStep Set the active step (zero based index).
       @param theme @ignore
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param elevation Shadow depth, corresponds to `dp` in the spec.
       It's accepting values between 0 and 24 inclusive.
       @param square If `true`, rounded corners are disabled. */
  let make:
    (
      ~className: string=?,
      ~orientation: Orientation.t=?,
      ~nonLinear: bool=?,
      ~connector: [ | `Element(ReasonReact.reactElement) | `Element(ReasonReact.reactElement)]=?,
      ~classes: Classes.t=?,
      ~alternativeLabel: bool=?,
      ~activeStep: float=?,
      ~theme: Js.t({..})=?,
      ~component: Js.t({..})=?,
      ~elevation: float=?,
      ~square: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Step: {
  module Classes: {
    type classesType =
      | Root(string)
      | Horizontal(string)
      | AlternativeLabel(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Step
       @param orientation @ignore
       @param last @ignore
       @param index @ignore
       Used internally for numbering.
       @param connector @ignore
       Passed down from Stepper if alternativeLabel is also set.
       @param className @ignore
       @param alternativeLabel @ignore
       Set internally by Stepper when it's supplied with the alternativeLabel property.
       @param optional Define this step as optional.
       @param disabled Mark the step as disabled, will also disable the button if
       `StepButton` is a child of `Step`. Is passed to child components.
       @param classes @ignore
       @param completed Mark the step as completed. Is passed to child components.
       @param active Sets the step as active. Is passed to child components. */
  let make:
    (
      ~orientation: Js.t({..})=?,
      ~last: bool=?,
      ~index: float=?,
      ~connector: ReasonReact.reactElement=?,
      ~className: string=?,
      ~alternativeLabel: bool=?,
      ~optional: bool=?,
      ~disabled: bool=?,
      ~classes: Classes.t=?,
      ~completed: bool=?,
      ~active: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module StepLabel: {
  module Classes: {
    type classesType =
      | Root(string)
      | Horizontal(string)
      | Vertical(string)
      | Active(string)
      | Completed(string)
      | Disabled(string)
      | IconContainer(string)
      | IconContainerNoAlternative(string)
      | AlternativeLabelRoot(string)
      | AlternativeLabel(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component StepLabel
       @param optional @ignore
       @param className @ignore
       @param orientation @ignore
       @param last @ignore
       @param icon The icon displayed by the step label - if not set will be set by Step component.
       @param disabled Mark the step as disabled, will also disable the button if
       `StepLabelButton` is a child of `StepLabel`. Is passed to child components.
       @param completed @ignore
       Mark the step as completed. Is passed to child components.
       @param classes Custom styles for component.
       @param alternativeLabel @ignore
       Set internally by Stepper when it's supplied with the alternativeLabel property.
       @param active @ignore
       Sets the step as active. Is passed to child components. */
  let make:
    (
      ~optional: bool=?,
      ~className: string=?,
      ~orientation: Js.t({..})=?,
      ~last: bool=?,
      ~icon: Js.t({..})=?,
      ~disabled: bool=?,
      ~completed: bool=?,
      ~classes: Classes.t=?,
      ~alternativeLabel: bool=?,
      ~active: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module StepContent: {
  module Classes: {
    type classesType =
      | Root(string)
      | Last(string)
      | Transition(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component StepContent
       @param orientation @ignore
       @param optional @ignore
       Set internally by Step when it's supplied with the optional property.
       @param last @ignore
       @param completed @ignore
       @param className @ignore
       @param alternativeLabel @ignore
       Set internally by Step when it's supplied with the alternativeLabel property.
       @param active @ignore
       Expands the content.
       @param transitionDuration Adjust the duration of the content expand transition.
       Passed as a property to the transition component.

       Set to 'auto' to automatically calculate transition time based on height.
       @param transition Collapse component.
       @param classes @ignore */
  let make:
    (
      ~orientation: Js.t({..})=?,
      ~optional: bool=?,
      ~last: bool=?,
      ~completed: bool=?,
      ~className: string=?,
      ~alternativeLabel: bool=?,
      ~active: bool=?,
      ~transitionDuration: Js.t({..})=?,
      ~transition: 'a=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module StepButton: {
  module Classes: {
    type classesType =
      | Root(string)
      | AlternativeLabel(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component StepButton
       @param orientation @ignore
       @param optional @ignore
       @param last @ignore
       @param icon The icon displayed by the step label.
       @param disabled @ignore
       Disables the button and sets disabled styling. Is passed to StepLabel.
       @param completed @ignore
       Sets completed styling. Is passed to StepLabel.
       @param className @ignore
       @param alternativeLabel @ignore
       Set internally by Stepper when it's supplied with the alternativeLabel property.
       @param active @ignore
       Passed in via `Step` - passed through to `StepLabel`.
       @param classes @ignore
       @param theme @ignore
       @param centerRipple If `true`, the ripples will be centered.
       They won't start at the cursor interaction position.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       The default value is a `button`.
       @param disableRipple If `true`, the ripple effect will be disabled.
       @param focusRipple If `true`, the base button will have a keyboard focus ripple.
       `disableRipple` must also be `false`.
       @param keyboardFocusedClassName The CSS class applied while the component is keyboard focused.
       @param onBlur @ignore
       @param onClick @ignore
       @param onFocus @ignore
       @param onKeyboardFocus Callback fired when the component is focused with a keyboard.
       We trigger a `onFocus` callback too.
       @param onKeyDown @ignore
       @param onKeyUp @ignore
       @param onMouseDown @ignore
       @param onMouseLeave @ignore
       @param onMouseUp @ignore
       @param onTouchEnd @ignore
       @param onTouchMove @ignore
       @param onTouchStart @ignore
       @param role @ignore
       @param rootRef Use that property to pass a ref callback to the root component.
       @param tabIndex @ignore
       @param type @ignore */
  let make:
    (
      ~orientation: Js.t({..}),
      ~optional: bool=?,
      ~last: bool=?,
      ~icon: [ | `Element(ReasonReact.reactElement) | `String(string) | `Float(float)]=?,
      ~disabled: bool=?,
      ~completed: bool=?,
      ~className: string=?,
      ~alternativeLabel: bool=?,
      ~active: bool=?,
      ~classes: Classes.t=?,
      ~theme: Js.t({..})=?,
      ~centerRipple: bool=?,
      ~component: Js.t({..})=?,
      ~disableRipple: bool=?,
      ~focusRipple: bool=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReactEventRe.Synthetic.t => unit=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~rootRef: 'a=?,
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      ~type_: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Snackbar: {
  module Classes: {
    type classesType =
      | Root(string)
      | AnchorTopCenter(string)
      | AnchorBottomCenter(string)
      | AnchorTopRight(string)
      | AnchorBottomRight(string)
      | AnchorTopLeft(string)
      | AnchorBottomLeft(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Snackbar
       @param transitionDuration The duration for the transition, in milliseconds.
       You may specify a single timeout for all transitions, or individually with an object.
       @param transition Transition component.
       @param SnackbarContentProps Properties applied to the `SnackbarContent` element.
       @param open If true, `Snackbar` is open.
       @param onRequestClose Callback fired when the component requests to be closed.

       Typically `onRequestClose` is used to set state in the parent component,
       which is used to control the `Snackbar` `open` prop.

       The `reason` parameter can optionally be used to control the response to `onRequestClose`,
       for example ignoring `clickaway`.

       @param {object} event The event source of the callback
       @param {string} reason Can be:`"timeout"` (`autoHideDuration` expired) or: `"clickaway"`
       @param onMouseLeave @ignore
       @param onMouseEnter @ignore
       @param onExited Callback fired when the transition has exited.
       @param onExiting Callback fired when the transition is exiting.
       @param onExit Callback fired before the transition is exiting.
       @param onEntered Callback fired when the transition has entered.
       @param onEntering Callback fired when the transition is entering.
       @param onEnter Callback fired before the transition is entering.
       @param message The message to display.
       @param className @ignore
       @param resumeHideDuration The number of milliseconds to wait before dismissing after user interaction.
       If `autoHideDuration` property isn't specified, it does nothing.
       If `autoHideDuration` property is specified but `resumeHideDuration` isn't,
       we default to `autoHideDuration / 2` ms.
       @param autoHideDuration The number of milliseconds to wait before automatically dismissing.
       This behavior is disabled by default with the `null` value.
       @param anchorOrigin The anchor of the `Snackbar`.
       @param action The action to display.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~transitionDuration: Js.t({..})=?,
      ~transition: Js.t({..})=?,
      ~sSnackbarContentProps: Js.t({..})=?,
      ~open_: bool,
      ~onRequestClose: (ReactEventRe.Synthetic.t, string) => unit=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseEnter: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onExited: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExiting: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExit: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntered: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntering: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEnter: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~message: ReasonReact.reactElement=?,
      ~className: string=?,
      ~resumeHideDuration: float=?,
      ~autoHideDuration: float=?,
      ~anchorOrigin: {. "horizontal": _, "vertical": _}=?,
      ~action: ReasonReact.reactElement=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module SnackbarContent: {
  module Classes: {
    type classesType =
      | Root(string)
      | Message(string)
      | Action(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component SnackbarContent
       @param message The message to display.
       @param className @ignore
       @param action The action to display.
       @param classes Useful to extend the style applied to components.
       @param theme @ignore
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param elevation Shadow depth, corresponds to `dp` in the spec.
       It's accepting values between 0 and 24 inclusive.
       @param square If `true`, rounded corners are disabled. */
  let make:
    (
      ~message: ReasonReact.reactElement,
      ~className: string=?,
      ~action: ReasonReact.reactElement=?,
      ~classes: Classes.t=?,
      ~theme: Js.t({..})=?,
      ~component: Js.t({..})=?,
      ~elevation: float=?,
      ~square: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Slide: {
  module Direction: {
    type t =
      | Left
      | Right
      | Up
      | Down;
    let to_string: t => string;
  };

  /*** Component Slide
       @param timeout The duration for the transition, in milliseconds.
       You may specify a single timeout for all transitions, or individually with an object.
       @param style @ignore
       @param onExited @ignore
       @param onExiting @ignore
       @param onExit @ignore
       @param onEntered @ignore
       @param onEntering @ignore
       @param onEnter @ignore
       @param in If `true`, show the component; triggers the enter or exit animation.
       @param direction Direction the child node will enter from.
       @param theme @ignore */
  let make:
    (
      ~timeout: Js.t({..})=?,
      ~style: Js.t({..})=?,
      ~onExited: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExiting: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExit: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntered: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntering: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEnter: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~in_: bool,
      ~direction: Direction.t,
      ~theme: Js.t({..}),
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Select: {
  module Margin: {
    type t =
      | Dense
      | None;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | Select(string)
      | SelectMenu(string)
      | Disabled(string)
      | Icon(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Select
       @param value The input value, required for a controlled component.
       @param renderValue Render the selected value.
       You can only use it when the `native` property is `false` (default).
       @param MenuProps Properties applied to the `Menu` element.
       @param multiple If true, `value` must be an array and the menu will support multiple selections.
       You can only use it when the `native` property is `false` (default).
       @param native If `true`, the component will be using a native `select` element.
       @param input An `Input` element; does not have to be a material-ui specific `Input`.
       @param displayEmpty If `true`, the selected item is displayed even if its value is empty.
       You can only use it when the `native` property is `false` (default).
       @param autoWidth If true, the width of the popover will automatically be set according to the items inside the
       menu, otherwise it will be at least the width of the select input.
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param autoComplete This property helps users to fill forms faster, especially on mobile devices.
       The name can be confusing, it's more like an autofill.
       You can learn more about it in this article
       https://developers.google.com/web/updates/2015/06/checkout-faster-with-autofill
       @param autoFocus If `true`, the input will be focused during the first mount.
       @param className The CSS class name of the wrapper element.
       @param defaultValue The default input value, useful when not controlling the component.
       @param disabled If `true`, the input will be disabled.
       @param disableUnderline If `true`, the input will not have an underline.
       @param endAdornment End `InputAdornment` for this component.
       @param error If `true`, the input will indicate an error. This is normally obtained via context from
       FormControl.
       @param fullWidth If `true`, the input will take up the full width of its container.
       @param id The id of the `input` element.
       @param inputComponent The component used for the input node.
       Either a string to use a DOM element or a component.
       It's an `input` by default.
       @param inputProps Properties applied to the `input` element.
       @param inputRef Use that property to pass a ref callback to the native input component.
       @param margin If `dense`, will adjust vertical spacing. This is normally obtained via context from
       FormControl.
       @param multiline If `true`, a textarea element will be rendered.
       @param name Name attribute of the `input` element.
       @param readOnly @ignore
       @param onBlur @ignore
       @param onChange Callback fired when the value is changed.

       @param {object} event The event source of the callback
       @param onClean TODO
       @param onDirty TODO
       @param onFocus @ignore
       @param onKeyDown @ignore
       @param onKeyUp @ignore
       @param placeholder The short hint displayed in the input before the user enters a value.
       @param rows Number of rows to display when multiline option is set to true.
       @param rowsMax Maximum number of rows to display when multiline option is set to true.
       @param startAdornment Start `InputAdornment` for this component.
       @param type Type of the input element. It should be a valid HTML5 input type. */
  let make:
    (
      ~value: [ | `Object('a) | `String(string) | `Float(float)]=?,
      ~renderValue: 'b=?,
      ~mMenuProps: Js.t({..})=?,
      ~multiple: bool=?,
      ~native: bool=?,
      ~input: ReasonReact.reactElement=?,
      ~displayEmpty: bool=?,
      ~autoWidth: bool=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~autoComplete: string=?,
      ~autoFocus: bool=?,
      ~className: string=?,
      ~defaultValue: [ | `String(string) | `Float(float)]=?,
      ~disabled: bool=?,
      ~disableUnderline: bool=?,
      ~endAdornment: ReasonReact.reactElement=?,
      ~error: bool=?,
      ~fullWidth: bool=?,
      ~id: string=?,
      ~inputComponent: [ | `String(string) | `Object(Js.t({..}))]=?,
      ~inputProps: Js.t({..})=?,
      ~inputRef: 'c=?,
      ~margin: Margin.t=?,
      ~multiline: bool=?,
      ~name: string=?,
      ~readOnly: bool=?,
      ~onBlur: ReactEventRe.Focus.t => unit=?,
      ~onChange: ReactEventRe.Form.t => unit=?,
      ~onClean: unit=?,
      ~onDirty: unit=?,
      ~onFocus: ReactEventRe.Focus.t => unit=?,
      ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
      ~onKeyUp: ReactEventRe.Keyboard.t => unit=?,
      ~placeholder: string=?,
      ~rows: [ | `String(string) | `Float(float)]=?,
      ~rowsMax: [ | `String(string) | `Float(float)]=?,
      ~startAdornment: ReasonReact.reactElement=?,
      ~type_: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Radio: {
  module Classes: {
    type classesType =
      | Default(string)
      | Checked(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Radio
       @param value The value of the component.
       @param tabIndex @ignore
       @param onChange Callback fired when the state is changed.

       @param {object} event The event source of the callback
       @param {boolean} checked The `checked` value of the switch
       @param inputRef Use that property to pass a ref callback to the native input component.
       @param inputProps Properties applied to the `input` element.
       @param icon The icon to display when the component is unchecked.
       If a string is provided, it will be used as a font ligature.
       @param disableRipple If `true`, the ripple effect will be disabled.
       @param disabled If `true`, the switch will be disabled.
       @param defaultChecked @ignore
       @param className @ignore
       @param checkedIcon The icon to display when the component is checked.
       If a string is provided, it will be used as a font ligature.
       @param checked If `true`, the component is checked.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~value: string=?,
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~name: string=?,
      ~inputRef: 'a=?,
      ~inputProps: Js.t({..})=?,
      ~icon: ReasonReact.reactElement=?,
      ~disableRipple: bool=?,
      ~disabled: bool=?,
      ~defaultChecked: bool=?,
      ~className: string=?,
      ~checkedIcon: ReasonReact.reactElement=?,
      ~checked: [ | `Bool(bool) | `String(string)]=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module RadioGroup: {
  module Classes: {
    type classesType =
      | Root(string)
      | Row(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component RadioGroup
       @param value Value of the selected radio button.
       @param onKeyDown @ignore
       @param onChange Callback fired when a radio button is selected.

       @param {object} event The event source of the callback
       @param {string} value The `value` of the selected radio button
       @param onBlur @ignore
       @param name The name used to reference the value of the control.
       @param classes Useful to extend the style applied to components.
       @param theme @ignore
       @param className @ignore
       @param row Display group of elements in a compact row. */
  let make:
    (
      ~value: string=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~name: string=?,
      ~classes: Classes.t=?,
      ~theme: Js.t({..})=?,
      ~className: string=?,
      ~row: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Popover: {
  module TransitionDuration: {
    type t =
      | Auto;
    let to_string: t => string;
  };
  module AnchorReference: {
    type t =
      | AnchorEl
      | AnchorPosition;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Paper(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Popover
       @param transitionDuration Set to 'auto' to automatically calculate transition time based on height.
       @param transitionClasses The animation classNames applied to the component as it enters or exits.
       This property is a direct binding to [`CSSTransition.classNames`](https://reactcommunity.org/react-transition-group/#CSSTransition-prop-classNames).
       @param transformOrigin This is the point on the popover which
       will attach to the anchor's origin.

       Options:
       vertical: [top, center, bottom, x(px)];
       horizontal: [left, center, right, x(px)].
       @param role @ignore
       @param PaperProps Properties applied to the `Paper` element.
       @param open If `true`, the popover is visible.
       @param onRequestClose Callback fired when the component requests to be closed.

       @param {object} event The event source of the callback.
       @param onExited Callback fired when the component has exited.
       @param onExiting Callback fired when the component is exiting.
       @param onExit Callback fired before the component is exiting.
       @param onEntered Callback fired when the component has entered.
       @param onEntering Callback fired when the component is entering.
       @param onEnter Callback fired before the component is entering.
       @param marginThreshold Specifies how close to the edge of the window the popover can appear.
       @param getContentAnchorEl This function is called in order to retrieve the content anchor element.
       It's the opposite of the `anchorEl` property.
       The content anchor element should be an element inside the popover.
       It's used to correctly scroll and set the position of the popover.
       The positioning strategy tries to make the content anchor element just above the
       anchor element.
       @param elevation The elevation of the popover.
       @param anchorOrigin This is the point on the anchor where the popover's
       `anchorEl` will attach to. This is not used when the
       anchorReference is 'anchorPosition'.

       Options:
       vertical: [top, center, bottom];
       horizontal: [left, center, right].
       @param anchorPosition This is the position that may be used
       to set the position of the popover.
       The coordinates are relative to
       the application's client area.
       @param anchorEl This is the DOM element that may be used
       to set the position of the popover.
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param BackdropClassName The CSS class name of the backdrop element.
       @param BackdropComponent Pass a component class to use as the backdrop.
       @param BackdropInvisible If `true`, the backdrop is invisible.
       @param BackdropTransitionDuration The duration for the backdrop transition, in milliseconds.
       You may specify a single timeout for all transitions, or individually with an object.
       @param className @ignore
       @param keepMounted Always keep the children in the DOM.
       This property can be useful in SEO situation or
       when you want to maximize the responsiveness of the Modal.
       @param disableBackdrop If `true`, the backdrop is disabled.
       @param ignoreBackdropClick If `true`, clicking the backdrop will not fire the `onRequestClose` callback.
       @param ignoreEscapeKeyUp If `true`, hitting escape will not fire the `onRequestClose` callback.
       @param modalManager @ignore
       @param onBackdropClick Callback fires when the backdrop is clicked on.
       @param onEscapeKeyUp Callback fires when the escape key is pressed and the modal is in focus.
       @param show If `true`, the Modal is visible. */
  let make:
    (
      ~transitionDuration: [
                             | `Enum(TransitionDuration.t)
                             | `Float(float)
                             | `Object({. "enter": int, "exit": int})
                           ]
                             =?,
      ~transitionClasses: [
                            | `String(string)
                            | `Object(
                                {
                                  .
                                  "appear": string,
                                  "appearActive": string,
                                  "enter": string,
                                  "enterActive": string,
                                  "exit": string,
                                  "exitActive": string
                                }
                              )
                          ]
                            =?,
      ~transformOrigin: {. "horizontal": _, "vertical": _}=?,
      ~role: string=?,
      ~pPaperProps: Js.t({..})=?,
      ~open_: bool,
      ~onRequestClose: ReasonReact.Callback.t(ReactEventRe.Synthetic.t)=?,
      ~onExited: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExiting: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExit: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntered: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntering: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEnter: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~marginThreshold: float=?,
      ~getContentAnchorEl: 'a=?,
      ~elevation: float=?,
      ~anchorOrigin: {. "horizontal": _, "vertical": _}=?,
      ~anchorReference: AnchorReference.t=?,
      ~anchorPosition: {. "top": int, "left": int}=?,
      ~anchorEl: Js.t({..})=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~bBackdropClassName: string=?,
      ~bBackdropComponent: Js.t({..})=?,
      ~bBackdropInvisible: bool=?,
      ~bBackdropTransitionDuration: Js.t({..})=?,
      ~className: string=?,
      ~keepMounted: bool=?,
      ~disableBackdrop: bool=?,
      ~ignoreBackdropClick: bool=?,
      ~ignoreEscapeKeyUp: bool=?,
      ~modalManager: Js.t({..})=?,
      ~onBackdropClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onEscapeKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~show: bool,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Paper: {
  module Classes: {
    type classesType =
      | Root(string)
      | Rounded(string)
      | Shadow0(string)
      | Shadow1(string)
      | Shadow2(string)
      | Shadow3(string)
      | Shadow4(string)
      | Shadow5(string)
      | Shadow6(string)
      | Shadow7(string)
      | Shadow8(string)
      | Shadow9(string)
      | Shadow10(string)
      | Shadow11(string)
      | Shadow12(string)
      | Shadow13(string)
      | Shadow14(string)
      | Shadow15(string)
      | Shadow16(string)
      | Shadow17(string)
      | Shadow18(string)
      | Shadow19(string)
      | Shadow20(string)
      | Shadow21(string)
      | Shadow22(string)
      | Shadow23(string)
      | Shadow24(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Paper
       @param square If `true`, rounded corners are disabled.
       @param elevation Shadow depth, corresponds to `dp` in the spec.
       It's accepting values between 0 and 24 inclusive.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~square: bool=?,
      ~elevation: float=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module MuiThemeProvider: {

  /*** Component MuiThemeProvider
       @param theme A theme object.
       @param sheetsManager The sheetsManager is used to deduplicate style sheet injection in the page.
       It's deduplicating using the (theme, styles) couple.
       On the server, you should provide a new instance for each request.
       @param disableStylesGeneration You can disable the generation of the styles with this option.
       It can be useful when traversing the React tree outside of the HTML
       rendering step on the server.
       Let's say you are using react-apollo to extract all
       the queries made by the interface server side.
       You can significantly speed up the traversal with this property. */
  let make:
    (
      ~theme: 'a,
      ~sheetsManager: Js.t({..})=?,
      ~disableStylesGeneration: Js.t({..})=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Modal: {
  module Classes: {
    type classesType =
      | Root(string)
      | Hidden(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Modal
       @param show If `true`, the Modal is visible.
       @param onRequestClose Callback fired when the component requests to be closed.

       @param {object} event The event source of the callback
       @param onExited Callback fired when the modal has exited.
       @param onExiting Callback fired when the modal is exiting.
       @param onExit Callback fired before the modal is exiting.
       @param onEscapeKeyUp Callback fires when the escape key is pressed and the modal is in focus.
       @param onEntered Callback fired when the modal has entered.
       @param onEntering Callback fired when the modal is entering.
       @param onEnter Callback fired before the modal is entering.
       @param onBackdropClick Callback fires when the backdrop is clicked on.
       @param modalManager @ignore
       @param ignoreEscapeKeyUp If `true`, hitting escape will not fire the `onRequestClose` callback.
       @param ignoreBackdropClick If `true`, clicking the backdrop will not fire the `onRequestClose` callback.
       @param disableBackdrop If `true`, the backdrop is disabled.
       @param keepMounted Always keep the children in the DOM.
       This property can be useful in SEO situation or
       when you want to maximize the responsiveness of the Modal.
       @param className @ignore
       @param BackdropTransitionDuration The duration for the backdrop transition, in milliseconds.
       You may specify a single timeout for all transitions, or individually with an object.
       @param BackdropInvisible If `true`, the backdrop is invisible.
       @param BackdropComponent Pass a component class to use as the backdrop.
       @param BackdropClassName The CSS class name of the backdrop element.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~show: bool,
      ~onRequestClose: ReasonReact.Callback.t(ReactEventRe.Synthetic.t)=?,
      ~onExited: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExiting: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExit: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEscapeKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onEntered: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntering: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEnter: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onBackdropClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~modalManager: Js.t({..})=?,
      ~ignoreEscapeKeyUp: bool=?,
      ~ignoreBackdropClick: bool=?,
      ~disableBackdrop: bool=?,
      ~keepMounted: bool=?,
      ~className: string=?,
      ~bBackdropTransitionDuration: Js.t({..})=?,
      ~bBackdropInvisible: bool=?,
      ~bBackdropComponent: Js.t({..})=?,
      ~bBackdropClassName: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module MobileStepper: {
  module Type: {
    type t =
      | Text
      | Dots
      | Progress;
    let to_string: t => string;
  };
  module Position: {
    type t =
      | Bottom
      | Top
      | Static;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | PositionBottom(string)
      | PositionTop(string)
      | PositionStatic(string)
      | Dots(string)
      | Dot(string)
      | DotActive(string)
      | Progress(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component MobileStepper
       @param type The type of mobile stepper to use.
       @param steps The total steps.
       @param position Set the positioning type.
       @param nextButton A next button element. For instance, it can be be a `Button` or a `IconButton`.
       @param className @ignore
       @param backButton A back button element. For instance, it can be be a `Button` or a `IconButton`.
       @param activeStep Set the active step (zero based index).
       Defines which dot is highlighted when the type is 'dots'.
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param elevation Shadow depth, corresponds to `dp` in the spec.
       It's accepting values between 0 and 24 inclusive.
       @param square If `true`, rounded corners are disabled. */
  let make:
    (
      ~type_: Type.t=?,
      ~steps: float,
      ~position: Position.t=?,
      ~nextButton: ReasonReact.reactElement,
      ~className: string=?,
      ~backButton: ReasonReact.reactElement,
      ~activeStep: float=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~component: Js.t({..})=?,
      ~elevation: float=?,
      ~square: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Menu: {
  module TransitionDuration: {
    type t =
      | Auto;
    let to_string: t => string;
  };
  module AnchorReference: {
    type t =
      | AnchorEl
      | AnchorPosition;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Paper(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Menu
       @param transitionDuration The length of the transition in `ms`, or 'auto'
       @param PopoverClasses `classes` property applied to the `Popover` element.
       @param PaperProps @ignore
       @param open If `true`, the menu is visible.
       @param onRequestClose Callback fired when the component requests to be closed.

       @param {object} event The event source of the callback
       @param onExited Callback fired when the Menu has exited.
       @param onExiting Callback fired when the Menu is exiting.
       @param onExit Callback fired before the Menu exits.
       @param onEntered Callback fired when the Menu has entered.
       @param onEntering Callback fired when the Menu is entering.
       @param onEnter Callback fired before the Menu enters.
       @param MenuListProps Properties applied to the `MenuList` element.
       @param anchorEl The DOM element used to set the position of the menu.
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param anchorPosition This is the position that may be used
       to set the position of the popover.
       The coordinates are relative to
       the application's client area.
       @param anchorOrigin This is the point on the anchor where the popover's
       `anchorEl` will attach to. This is not used when the
       anchorReference is 'anchorPosition'.

       Options:
       vertical: [top, center, bottom];
       horizontal: [left, center, right].
       @param elevation The elevation of the popover.
       @param getContentAnchorEl This function is called in order to retrieve the content anchor element.
       It's the opposite of the `anchorEl` property.
       The content anchor element should be an element inside the popover.
       It's used to correctly scroll and set the position of the popover.
       The positioning strategy tries to make the content anchor element just above the
       anchor element.
       @param marginThreshold Specifies how close to the edge of the window the popover can appear.
       @param role @ignore
       @param transformOrigin This is the point on the popover which
       will attach to the anchor's origin.

       Options:
       vertical: [top, center, bottom, x(px)];
       horizontal: [left, center, right, x(px)].
       @param transitionClasses The animation classNames applied to the component as it enters or exits.
       This property is a direct binding to [`CSSTransition.classNames`](https://reactcommunity.org/react-transition-group/#CSSTransition-prop-classNames). */
  let make:
    (
      ~transitionDuration: [
                             | `Enum(TransitionDuration.t)
                             | `Float(float)
                             | `Object({. "enter": int, "exit": int})
                           ]
                             =?,
      ~pPopoverClasses: Js.t({..})=?,
      ~pPaperProps: Js.t({..})=?,
      ~open_: bool=?,
      ~onRequestClose: ReasonReact.Callback.t(ReactEventRe.Synthetic.t)=?,
      ~onExited: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExiting: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExit: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntered: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntering: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEnter: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~mMenuListProps: Js.t({..})=?,
      ~anchorEl: Js.t({..})=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~anchorPosition: {. "top": int, "left": int}=?,
      ~anchorReference: AnchorReference.t=?,
      ~anchorOrigin: {. "horizontal": _, "vertical": _}=?,
      ~elevation: float=?,
      ~getContentAnchorEl: 'a=?,
      ~marginThreshold: float=?,
      ~role: string=?,
      ~transformOrigin: {. "horizontal": _, "vertical": _}=?,
      ~transitionClasses: [
                            | `String(string)
                            | `Object(
                                {
                                  .
                                  "appear": string,
                                  "appearActive": string,
                                  "enter": string,
                                  "enterActive": string,
                                  "exit": string,
                                  "exitActive": string
                                }
                              )
                          ]
                            =?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module MenuList: {
  module Classes: {
    type classesType =
      | Root(string)
      | Padding(string)
      | Dense(string)
      | Subheader(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component MenuList
       @param onKeyDown @ignore
       @param onBlur @ignore
       @param className @ignore
       @param classes Useful to extend the style applied to components.
       @param theme @ignore
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param dense If `true`, compact vertical padding designed for keyboard and mouse input will be used for
       the list and list items. The property is available to descendant components as the
       `dense` context.
       @param disablePadding If `true`, vertical padding will be removed from the list.
       @param rootRef Use that property to pass a ref callback to the root component.
       @param subheader The content of the component, normally `ListItem`. */
  let make:
    (
      ~onKeyDown: (ReactEventRe.UI.t, string) => unit=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~className: string=?,
      ~classes: Classes.t=?,
      ~theme: Js.t({..})=?,
      ~component: Js.t({..})=?,
      ~dense: bool=?,
      ~disablePadding: bool=?,
      ~rootRef: 'a=?,
      ~subheader: ReasonReact.reactElement=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module MenuItem: {
  module Classes: {
    type classesType =
      | Root(string)
      | Selected(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component MenuItem
       @param selected Use to apply selected styling.
       @param role @ignore
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param button If `true`, the ListItem will be a button.
       @param dense If `true`, compact vertical padding designed for keyboard and mouse input will be used.
       @param disabled @ignore
       @param disableGutters If `true`, the left and right padding is removed.
       @param divider If `true`, a 1px light border is added to the bottom of the list item. */
  let make:
    (
      ~selected: bool=?,
      ~role: string=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~button: bool=?,
      ~dense: bool=?,
      ~disabled: bool=?,
      ~disableGutters: bool=?,
      ~divider: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module List: {
  module Classes: {
    type classesType =
      | Root(string)
      | Padding(string)
      | Dense(string)
      | Subheader(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component List
       @param subheader The content of the component, normally `ListItem`.
       @param rootRef Use that property to pass a ref callback to the root component.
       @param disablePadding If `true`, vertical padding will be removed from the list.
       @param dense If `true`, compact vertical padding designed for keyboard and mouse input will be used for
       the list and list items. The property is available to descendant components as the
       `dense` context.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~subheader: ReasonReact.reactElement=?,
      ~rootRef: 'a=?,
      ~disablePadding: bool=?,
      ~dense: bool=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ListSubheader: {
  module Color: {
    type t =
      | Default
      | Primary
      | Inherit;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | ColorPrimary(string)
      | ColorInherit(string)
      | Inset(string)
      | Sticky(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component ListSubheader
       @param inset If `true`, the List Subheader will be indented.
       @param disableSticky If `true`, the List Subheader will not stick to the top during scroll.
       @param color The color of the component. It's using the theme palette when that makes sense.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       The default value is a `button`.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~inset: bool=?,
      ~disableSticky: bool=?,
      ~color: Color.t=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ListItem: {
  module Classes: {
    type classesType =
      | Root(string)
      | Container(string)
      | KeyboardFocused(string)
      | Default(string)
      | Dense(string)
      | Disabled(string)
      | Divider(string)
      | Gutters(string)
      | Button(string)
      | SecondaryAction(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component ListItem
       @param divider If `true`, a 1px light border is added to the bottom of the list item.
       @param disableGutters If `true`, the left and right padding is removed.
       @param disabled @ignore
       @param dense If `true`, compact vertical padding designed for keyboard and mouse input will be used.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param button If `true`, the ListItem will be a button.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~divider: bool=?,
      ~disableGutters: bool=?,
      ~disabled: bool=?,
      ~dense: bool=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~button: bool=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ListItemText: {
  module Classes: {
    type classesType =
      | Root(string)
      | Inset(string)
      | Dense(string)
      | Text(string)
      | TextDense(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component ListItemText
       @param inset If `true`, the children will be indented.
       This should be used if there is no left avatar or left icon.
       @param disableTypography If `true`, the children won't be wrapped by a typography component.
       For instance, that can be useful to can render an h4 instead of a
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~secondary: ReasonReact.reactElement=?,
      ~primary: ReasonReact.reactElement=?,
      ~inset: bool=?,
      ~disableTypography: bool=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ListItemSecondaryAction: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component ListItemSecondaryAction
       @param className @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (~className: string=?, ~classes: Classes.t=?, array(ReasonReact.reactElement)) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ListItemIcon: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component ListItemIcon
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ListItemAvatar: {
  module Classes: {
    type classesType =
      | Root(string)
      | Icon(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component ListItemAvatar
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module LinearProgress: {
  module Mode: {
    type t =
      | Determinate
      | Indeterminate
      | Buffer
      | Query;
    let to_string: t => string;
  };
  module Color: {
    type t =
      | Primary
      | Accent;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | PrimaryColor(string)
      | PrimaryColorBar(string)
      | PrimaryDashed(string)
      | AccentColor(string)
      | AccentColorBar(string)
      | AccentDashed(string)
      | Bar(string)
      | Dashed(string)
      | BufferBar2(string)
      | RootBuffer(string)
      | RootQuery(string)
      | IndeterminateBar1(string)
      | IndeterminateBar2(string)
      | DeterminateBar1(string)
      | BufferBar1(string)
      | BufferBar2Primary(string)
      | BufferBar2Accent(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component LinearProgress
       @param valueBuffer The value of buffer, only works in buffer mode.
       Value between 0 and 100.
       @param value The value of progress, only works in determinate and buffer mode.
       Value between 0 and 100.
       @param mode The mode of show your progress, indeterminate
       for when there is no value for progress.
       @param color The color of the component. It's using the theme palette when that makes sense.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~valueBuffer: float=?,
      ~value: float=?,
      ~mode: Mode.t=?,
      ~color: Color.t=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Input: {
  module Margin: {
    type t =
      | Dense
      | None;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | FormControl(string)
      | Inkbar(string)
      | Error(string)
      | Disabled(string)
      | Focused(string)
      | Underline(string)
      | Multiline(string)
      | FullWidth(string)
      | Input(string)
      | InputDense(string)
      | InputDisabled(string)
      | InputSingleline(string)
      | InputMultiline(string)
      | InputSearch(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Input
       @param value The input value, required for a controlled component.
       @param type Type of the input element. It should be a valid HTML5 input type.
       @param startAdornment Start `InputAdornment` for this component.
       @param rowsMax Maximum number of rows to display when multiline option is set to true.
       @param rows Number of rows to display when multiline option is set to true.
       @param placeholder The short hint displayed in the input before the user enters a value.
       @param onKeyUp @ignore
       @param onKeyDown @ignore
       @param onFocus @ignore
       @param onDirty TODO
       @param onClean TODO
       @param onChange Callback fired when the value is changed.

       @param {object} event The event source of the callback
       @param onBlur @ignore
       @param readOnly @ignore
       @param name Name attribute of the `input` element.
       @param multiline If `true`, a textarea element will be rendered.
       @param margin If `dense`, will adjust vertical spacing. This is normally obtained via context from
       FormControl.
       @param inputRef Use that property to pass a ref callback to the native input component.
       @param inputProps Properties applied to the `input` element.
       @param inputComponent The component used for the input node.
       Either a string to use a DOM element or a component.
       It's an `input` by default.
       @param id The id of the `input` element.
       @param fullWidth If `true`, the input will take up the full width of its container.
       @param error If `true`, the input will indicate an error. This is normally obtained via context from
       FormControl.
       @param endAdornment End `InputAdornment` for this component.
       @param disableUnderline If `true`, the input will not have an underline.
       @param disabled If `true`, the input will be disabled.
       @param defaultValue The default input value, useful when not controlling the component.
       @param className The CSS class name of the wrapper element.
       @param autoFocus If `true`, the input will be focused during the first mount.
       @param autoComplete This property helps users to fill forms faster, especially on mobile devices.
       The name can be confusing, it's more like an autofill.
       You can learn more about it in this article
       https://developers.google.com/web/updates/2015/06/checkout-faster-with-autofill
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~value: [ | `String(string) | `Float(float) | `Object(Js.t({..}))]=?,
      ~type_: string=?,
      ~startAdornment: ReasonReact.reactElement=?,
      ~rowsMax: [ | `String(string) | `Float(float)]=?,
      ~rows: [ | `String(string) | `Float(float)]=?,
      ~placeholder: string=?,
      ~onKeyUp: ReactEventRe.Keyboard.t => unit=?,
      ~onKeyDown: ReactEventRe.Keyboard.t => unit=?,
      ~onFocus: ReactEventRe.Focus.t => unit=?,
      ~onDirty: unit=?,
      ~onClean: unit=?,
      ~onChange: ReactEventRe.Form.t => unit=?,
      ~onBlur: ReactEventRe.Focus.t => unit=?,
      ~readOnly: bool=?,
      ~name: string=?,
      ~multiline: bool=?,
      ~margin: Margin.t=?,
      ~inputRef: 'a=?,
      ~inputProps: Js.t({..})=?,
      ~inputComponent: [ | `String(string) | `Object(Js.t({..}))]=?,
      ~id: string=?,
      ~fullWidth: bool=?,
      ~error: bool=?,
      ~endAdornment: ReasonReact.reactElement=?,
      ~disableUnderline: bool=?,
      ~disabled: bool=?,
      ~defaultValue: [ | `String(string) | `Float(float)]=?,
      ~className: string=?,
      ~autoFocus: bool=?,
      ~autoComplete: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module InputLabel: {
  module Classes: {
    type classesType =
      | Root(string)
      | FormControl(string)
      | LabelDense(string)
      | Shrink(string)
      | Animated(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component InputLabel
       @param shrink If `true`, the label is shrunk.
       @param required if `true`, the label will indicate that the input is required.
       @param margin If `dense`, will adjust vertical spacing. This is normally obtained via context from
       FormControl.
       @param focused If `true`, the input of this label is focused.
       @param FormControlClasses `classes` property applied to the `FormControl` element.
       @param error If `true`, the label will be displayed in an error state.
       @param disabled If `true`, apply disabled class.
       @param disableAnimation If `true`, the transition animation is disabled.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~shrink: bool=?,
      ~required: bool=?,
      ~margin: Js.t({..})=?,
      ~focused: bool=?,
      ~fFormControlClasses: Js.t({..})=?,
      ~error: bool=?,
      ~disabled: bool=?,
      ~disableAnimation: bool=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module InputAdornment: {
  module Position: {
    type t =
      | Start
      | End;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | PositionStart(string)
      | PositionEnd(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component InputAdornment
       @param position The position this adornment should appear relative to the `Input`.
       @param disableTypography If children is a string then disable wrapping in a Typography component.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~position: Position.t,
      ~disableTypography: bool=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Icon: {
  module Color: {
    type t =
      | Inherit
      | Accent
      | Action
      | Contrast
      | Disabled
      | Error
      | Primary;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | ColorAccent(string)
      | ColorAction(string)
      | ColorContrast(string)
      | ColorDisabled(string)
      | ColorError(string)
      | ColorPrimary(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Icon
       @param color The color of the component. It's using the theme palette when that makes sense.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~color: Color.t=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module IconButton: {
  module Color: {
    type t =
      | Default
      | Inherit
      | Primary
      | Contrast
      | Accent;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | ColorAccent(string)
      | ColorContrast(string)
      | ColorPrimary(string)
      | ColorInherit(string)
      | Disabled(string)
      | Label(string)
      | Icon(string)
      | KeyboardFocused(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component IconButton
       @param rootRef Use that property to pass a ref callback to the root component.
       @param disableRipple If `true`, the ripple will be disabled.
       @param disabled If `true`, the button will be disabled.
       @param color The color of the component. It's using the theme palette when that makes sense.
       @param className @ignore
       @param buttonRef Use that property to pass a ref callback to the native button component.
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param centerRipple If `true`, the ripples will be centered.
       They won't start at the cursor interaction position.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       The default value is a `button`.
       @param focusRipple If `true`, the base button will have a keyboard focus ripple.
       `disableRipple` must also be `false`.
       @param keyboardFocusedClassName The CSS class applied while the component is keyboard focused.
       @param onBlur @ignore
       @param onClick @ignore
       @param onFocus @ignore
       @param onKeyboardFocus Callback fired when the component is focused with a keyboard.
       We trigger a `onFocus` callback too.
       @param onKeyDown @ignore
       @param onKeyUp @ignore
       @param onMouseDown @ignore
       @param onMouseLeave @ignore
       @param onMouseUp @ignore
       @param onTouchEnd @ignore
       @param onTouchMove @ignore
       @param onTouchStart @ignore
       @param role @ignore
       @param tabIndex @ignore
       @param type @ignore */
  let make:
    (
      ~rootRef: 'a=?,
      ~disableRipple: bool=?,
      ~disabled: bool=?,
      ~color: Color.t=?,
      ~className: string=?,
      ~buttonRef: 'b=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~centerRipple: bool=?,
      ~component: Js.t({..})=?,
      ~focusRipple: bool=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReactEventRe.Synthetic.t => unit=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      ~type_: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Hidden: {
  module Implementation: {
    type t =
      | Js
      | Css;
    let to_string: t => string;
  };

  /*** Component Hidden
       @param initialWidth You can use this property when choosing the `js` implementation with server side rendering.

       As `window.innerWidth` is unavailable on the server,
       we default to rendering an empty componenent during the first mount.
       In some situation you might want to use an heristic to approximate
       the screen width of the client browser screen width.

       For instance, you could be using the user-agent or the client-hints.
       http://caniuse.com/#search=client%20hint
       @param implementation Specify which implementation to use.  'js' is the default, 'css' works better for server
       side rendering.
       @param xlDown If true, screens this size and down will be hidden.
       @param lgDown If true, screens this size and down will be hidden.
       @param mdDown If true, screens this size and down will be hidden.
       @param smDown If true, screens this size and down will be hidden.
       @param xsDown If true, screens this size and down will be hidden.
       @param xlUp If true, screens this size and up will be hidden.
       @param lgUp If true, screens this size and up will be hidden.
       @param mdUp If true, screens this size and up will be hidden.
       @param smUp If true, screens this size and up will be hidden.
       @param xsUp If true, screens this size and up will be hidden.
       @param only Hide the given breakpoint(s).
       @param className @ignore */
  let make:
    (
      ~initialWidth: float=?,
      ~implementation: Implementation.t=?,
      ~xlDown: bool=?,
      ~lgDown: bool=?,
      ~mdDown: bool=?,
      ~smDown: bool=?,
      ~xsDown: bool=?,
      ~xlUp: bool=?,
      ~lgUp: bool=?,
      ~mdUp: bool=?,
      ~smUp: bool=?,
      ~xsUp: bool=?,
      ~only: [ | `Object(Js.t({..})) | `Object(Js.t({..}))]=?,
      ~className: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Grow: {
  module Timeout: {
    type t =
      | Auto;
    let to_string: t => string;
  };

  /*** Component Grow
       @param timeout The duration for the transition, in milliseconds.
       You may specify a single timeout for all transitions, or individually with an object.

       Set to 'auto' to automatically calculate transition time based on height.
       @param transitionClasses The animation classNames applied to the component as it enters or exits.
       This property is a direct binding to [`CSSTransition.classNames`](https://reactcommunity.org/react-transition-group/#CSSTransition-prop-classNames).
       @param style @ignore
       @param rootRef Use that property to pass a ref callback to the root component.
       @param onExited @ignore
       @param onExiting @ignore
       @param onExit @ignore
       @param onEntered @ignore
       @param onEntering @ignore
       @param onEnter @ignore
       @param in If `true`, show the component; triggers the enter or exit animation.
       @param appear @ignore
       @param theme @ignore */
  let make:
    (
      ~timeout: [ | `Enum(Timeout.t) | `Float(float) | `Object({. "enter": int, "exit": int})]=?,
      ~transitionClasses: [
                            | `String(string)
                            | `Object(
                                {
                                  .
                                  "appear": string,
                                  "appearActive": string,
                                  "enter": string,
                                  "enterActive": string,
                                  "exit": string,
                                  "exitActive": string
                                }
                              )
                          ]
                            =?,
      ~style: Js.t({..})=?,
      ~rootRef: 'a=?,
      ~onExited: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExiting: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExit: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntered: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntering: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEnter: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~in_: bool,
      ~appear: bool=?,
      ~theme: Js.t({..}),
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Grid: {
  module Xl: {
    type t =
      | V_1
      | V_2
      | V_3
      | V_4
      | V_5
      | V_6
      | V_7
      | V_8
      | V_9
      | V_10
      | V_11
      | V_12;
    let to_string: t => string;
  };
  module Lg: {
    type t =
      | V_1
      | V_2
      | V_3
      | V_4
      | V_5
      | V_6
      | V_7
      | V_8
      | V_9
      | V_10
      | V_11
      | V_12;
    let to_string: t => string;
  };
  module Md: {
    type t =
      | V_1
      | V_2
      | V_3
      | V_4
      | V_5
      | V_6
      | V_7
      | V_8
      | V_9
      | V_10
      | V_11
      | V_12;
    let to_string: t => string;
  };
  module Sm: {
    type t =
      | V_1
      | V_2
      | V_3
      | V_4
      | V_5
      | V_6
      | V_7
      | V_8
      | V_9
      | V_10
      | V_11
      | V_12;
    let to_string: t => string;
  };
  module Xs: {
    type t =
      | V_1
      | V_2
      | V_3
      | V_4
      | V_5
      | V_6
      | V_7
      | V_8
      | V_9
      | V_10
      | V_11
      | V_12;
    let to_string: t => string;
  };
  module Wrap: {
    type t =
      | Nowrap
      | Wrap
      | Wrap_reverse;
    let to_string: t => string;
  };
  module Justify: {
    type t =
      | Flex_start
      | Center
      | Flex_end
      | Space_between
      | Space_around;
    let to_string: t => string;
  };
  module Spacing: {
    type t =
      | V_0
      | V_8
      | V_16
      | V_24
      | V_40;
    let to_string: t => string;
  };
  module Direction: {
    type t =
      | Row
      | Row_reverse
      | Column
      | Column_reverse;
    let to_string: t => string;
  };
  module AlignItems: {
    type t =
      | Flex_start
      | Center
      | Flex_end
      | Stretch
      | Baseline;
    let to_string: t => string;
  };
  module AlignContent: {
    type t =
      | Stretch
      | Center
      | Flex_start
      | Flex_end
      | Space_between
      | Space_around;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | TypeContainer(string)
      | TypeItem(string)
      | Direction_xs_column(string)
      | Direction_xs_column_reverse(string)
      | Direction_xs_row_reverse(string)
      | Wrap_xs_nowrap(string)
      | Wrap_xs_wrap_reverse(string)
      | Align_items_xs_center(string)
      | Align_items_xs_flex_start(string)
      | Align_items_xs_flex_end(string)
      | Align_items_xs_baseline(string)
      | Align_content_xs_center(string)
      | Align_content_xs_flex_start(string)
      | Align_content_xs_flex_end(string)
      | Align_content_xs_space_between(string)
      | Align_content_xs_space_around(string)
      | Justify_xs_center(string)
      | Justify_xs_flex_end(string)
      | Justify_xs_space_between(string)
      | Justify_xs_space_around(string)
      | Spacing_xs_8(string)
      | Spacing_xs_16(string)
      | Spacing_xs_24(string)
      | Spacing_xs_40(string)
      | Grid_xs(string)
      | Grid_xs_1(string)
      | Grid_xs_2(string)
      | Grid_xs_3(string)
      | Grid_xs_4(string)
      | Grid_xs_5(string)
      | Grid_xs_6(string)
      | Grid_xs_7(string)
      | Grid_xs_8(string)
      | Grid_xs_9(string)
      | Grid_xs_10(string)
      | Grid_xs_11(string)
      | Grid_xs_12(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Grid
       @param xl Defines the number of grids the component is going to use.
       It's applied for the `xl` breakpoint and wider screens.
       @param lg Defines the number of grids the component is going to use.
       It's applied for the `lg` breakpoint and wider screens if not overridden.
       @param md Defines the number of grids the component is going to use.
       It's applied for the `md` breakpoint and wider screens if not overridden.
       @param sm Defines the number of grids the component is going to use.
       It's applied for the `sm` breakpoint and wider screens if not overridden.
       @param xs Defines the number of grids the component is going to use.
       It's applied for all the screen sizes with the lowest priority.
       @param wrap Defines the `flex-wrap` style property.
       It's applied for all screen sizes.
       @param justify Defines the `justify-content` style property.
       It is applied for all screen sizes.
       @param hidden If provided, will wrap with [Hidden](/api/hidden) component and given properties.
       @param spacing Defines the space between the type `item` component.
       It can only be used on a type `container` component.
       @param direction Defines the `flex-direction` style property.
       It is applied for all screen sizes.
       @param alignItems Defines the `align-items` style property.
       It's applied for all screen sizes.
       @param alignContent Defines the `align-content` style property.
       It's applied for all screen sizes.
       @param item If `true`, the component will have the flex *item* behavior.
       You should be wrapping *items* with a *container*.
       @param container If `true`, the component will have the flex *container* behavior.
       You should be wrapping *items* with a *container*.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~xl: [ | `Enum(Xl.t) | `Bool(bool)]=?,
      ~lg: [ | `Enum(Lg.t) | `Bool(bool)]=?,
      ~md: [ | `Enum(Md.t) | `Bool(bool)]=?,
      ~sm: [ | `Enum(Sm.t) | `Bool(bool)]=?,
      ~xs: [ | `Enum(Xs.t) | `Bool(bool)]=?,
      ~wrap: Wrap.t=?,
      ~justify: Justify.t=?,
      ~hidden: Js.t({..})=?,
      ~spacing: Spacing.t=?,
      ~direction: Direction.t=?,
      ~alignItems: AlignItems.t=?,
      ~alignContent: AlignContent.t=?,
      ~item: bool=?,
      ~container: bool=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module GridList: {
  module CellHeight: {
    type t =
      | Auto;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component GridList
       @param style @ignore
       @param spacing Number of px for the spacing between tiles.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       By default we map the type to a good default headline component.
       @param cols Number of columns.
       @param className @ignore
       @param cellHeight Number of px for one cell height.
       You can set `'auto'` if you want to let the children determine the height.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~style: Js.t({..})=?,
      ~spacing: float=?,
      ~component: Js.t({..})=?,
      ~cols: float=?,
      ~className: string=?,
      ~cellHeight: [ | `Enum(CellHeight.t) | `Float(float)]=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module GridListTile: {
  module Classes: {
    type classesType =
      | Root(string)
      | Tile(string)
      | ImgFullHeight(string)
      | ImgFullWidth(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component GridListTile
       @param rows Height of the tile in number of grid cells.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param cols Width of the tile in number of grid cells.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~rows: float=?,
      ~component: Js.t({..})=?,
      ~cols: float=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module GridListTileBar: {
  module TitlePosition: {
    type t =
      | Top
      | Bottom;
    let to_string: t => string;
  };
  module ActionPosition: {
    type t =
      | Left
      | Right;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | RootBottom(string)
      | RootTop(string)
      | RootWithSubtitle(string)
      | TitleWrap(string)
      | TitleWrapActionLeft(string)
      | TitleWrapActionRight(string)
      | Title(string)
      | Subtitle(string)
      | ActionIconPositionLeft(string)
      | ChildImg(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component GridListTileBar
       @param titlePosition Position of the title bar.
       @param title Title to be displayed on tile.
       @param subtitle String or element serving as subtitle (support text).
       @param className @ignore
       @param actionPosition Position of secondary action IconButton.
       @param actionIcon An IconButton element to be used as secondary action target
       (primary action target is the tile itself).
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~titlePosition: TitlePosition.t=?,
      ~title: ReasonReact.reactElement,
      ~subtitle: ReasonReact.reactElement=?,
      ~className: string=?,
      ~actionPosition: ActionPosition.t=?,
      ~actionIcon: ReasonReact.reactElement=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module FormLabel: {
  module Classes: {
    type classesType =
      | Root(string)
      | Focused(string)
      | Error(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component FormLabel
       @param required If `true`, the label will indicate that the input is required.
       @param focused If `true`, the input of this label is focused (used by `FormGroup` components).
       @param error If `true`, the label should be displayed in an error state.
       @param disabled If `true`, the label should be displayed in a disabled state.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~required: bool=?,
      ~focused: bool=?,
      ~error: bool=?,
      ~disabled: bool=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module FormHelperText: {
  module Classes: {
    type classesType =
      | Root(string)
      | Dense(string)
      | Error(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component FormHelperText
       @param margin If `dense`, will adjust vertical spacing. This is normally obtained via context from
       FormControl.
       @param error If `true`, helper text should be displayed in an error state.
       @param disabled If `true`, the helper text should be displayed in a disabled state.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~margin: Js.t({..})=?,
      ~error: bool=?,
      ~disabled: bool=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module FormGroup: {
  module Classes: {
    type classesType =
      | Root(string)
      | Row(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component FormGroup
       @param row Display group of elements in a compact row.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~row: bool=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module FormControl: {
  module Margin: {
    type t =
      | None
      | Dense
      | Normal;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | MarginNormal(string)
      | MarginDense(string)
      | FullWidth(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component FormControl
       @param required If `true`, the label will indicate that the input is required.
       @param onFocus @ignore
       @param onBlur @ignore
       @param margin If `dense` or `normal`, will adjust vertical spacing of this and contained components.
       @param fullWidth If `true`, the component, as well as its children,
       will take up the full width of its container.
       @param error If `true`, the label should be displayed in an error state.
       @param disabled If `true`, the label, input and helper text should be displayed in a disabled state.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~required: bool=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~margin: Margin.t=?,
      ~fullWidth: bool=?,
      ~error: bool=?,
      ~disabled: bool=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module FormControlLabel: {
  module Classes: {
    type classesType =
      | Root(string)
      | Disabled(string)
      | Label(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component FormControlLabel
       @param value The value of the component.
       @param onChange Callback fired when the state is changed.

       @param {object} event The event source of the callback
       @param {boolean} checked The `checked` value of the switch
       @param label The text to be used in an enclosing label element.
       @param inputRef Use that property to pass a ref callback to the native input component.
       @param disabled If `true`, the control will be disabled.
       @param control A control element. For instance, it can be be a `Radio`, a `Switch` or a `Checkbox`.
       @param className @ignore
       @param checked If `true`, the component appears selected.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~value: string=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~name: string=?,
      ~label: ReasonReact.reactElement,
      ~inputRef: 'a=?,
      ~disabled: bool=?,
      ~control: ReasonReact.reactElement,
      ~className: string=?,
      ~checked: [ | `Bool(bool) | `String(string)]=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Fade: {

  /*** Component Fade
       @param timeout The duration for the transition, in milliseconds.
       You may specify a single timeout for all transitions, or individually with an object.
       @param style @ignore
       @param onExit @ignore
       @param onEntering @ignore
       @param onEnter @ignore
       @param in If `true`, the component will transition in.
       @param appear @ignore
       @param theme @ignore */
  let make:
    (
      ~timeout: Js.t({..})=?,
      ~style: Js.t({..})=?,
      ~onExit: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntering: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEnter: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~in_: bool,
      ~appear: bool=?,
      ~theme: Js.t({..}),
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ExpansionPanel: {
  module Classes: {
    type classesType =
      | Root(string)
      | Expanded(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component ExpansionPanel
       @param onChange Callback fired when the expand/collapse state is changed.

       @param {object} event The event source of the callback
       @param {boolean} expanded The `expanded` state of the panel
       @param expanded If `true`, expands the panel, otherwise collapse it.
       Setting this prop enables control over the panel.
       @param CollapseProps Properties applied to the `Collapse` element.
       @param className @ignore
       @param theme @ignore
       @param disabled If `true`, the panel will be displayed in a disabled state.
       @param defaultExpanded If `true`, expands the panel by default.
       @param classes Useful to extend the style applied to components.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param elevation Shadow depth, corresponds to `dp` in the spec.
       It's accepting values between 0 and 24 inclusive.
       @param square If `true`, rounded corners are disabled. */
  let make:
    (
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~expanded: bool=?,
      ~cCollapseProps: Js.t({..})=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~disabled: bool=?,
      ~defaultExpanded: bool=?,
      ~classes: Classes.t=?,
      ~component: Js.t({..})=?,
      ~elevation: float=?,
      ~square: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ExpansionPanelSummary: {
  module Classes: {
    type classesType =
      | Root(string)
      | Expanded(string)
      | Focused(string)
      | Disabled(string)
      | Content(string)
      | ContentExpanded(string)
      | ExpandIcon(string)
      | ExpandIconExpanded(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component ExpansionPanelSummary
       @param onClick @ignore
       @param onChange @ignore
       @param expandIcon The icon to display as the expand indicator.
       @param expanded @ignore
       If `true`, expands the summary, otherwise collapse it.
       @param disabled @ignore
       If `true`, the summary will be displayed in a disabled state.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param centerRipple If `true`, the ripples will be centered.
       They won't start at the cursor interaction position.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       The default value is a `button`.
       @param disableRipple If `true`, the ripple effect will be disabled.
       @param focusRipple If `true`, the base button will have a keyboard focus ripple.
       `disableRipple` must also be `false`.
       @param keyboardFocusedClassName The CSS class applied while the component is keyboard focused.
       @param onBlur @ignore
       @param onFocus @ignore
       @param onKeyboardFocus Callback fired when the component is focused with a keyboard.
       We trigger a `onFocus` callback too.
       @param onKeyDown @ignore
       @param onKeyUp @ignore
       @param onMouseDown @ignore
       @param onMouseLeave @ignore
       @param onMouseUp @ignore
       @param onTouchEnd @ignore
       @param onTouchMove @ignore
       @param onTouchStart @ignore
       @param role @ignore
       @param rootRef Use that property to pass a ref callback to the root component.
       @param tabIndex @ignore
       @param type @ignore */
  let make:
    (
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~expandIcon: ReasonReact.reactElement=?,
      ~expanded: bool=?,
      ~disabled: bool=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~centerRipple: bool=?,
      ~component: Js.t({..})=?,
      ~disableRipple: bool=?,
      ~focusRipple: bool=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReactEventRe.Synthetic.t => unit=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~rootRef: 'a=?,
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      ~type_: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ExpansionPanelDetails: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component ExpansionPanelDetails
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ExpansionPanelActions: {
  module Classes: {
    type classesType =
      | Root(string)
      | Action(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component ExpansionPanelActions
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Drawer: {
  module Type: {
    type t =
      | Permanent
      | Persistent
      | Temporary;
    let to_string: t => string;
  };
  module Anchor: {
    type t =
      | Left
      | Top
      | Right
      | Bottom;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Docked(string)
      | Paper(string)
      | PaperAnchorLeft(string)
      | PaperAnchorRight(string)
      | PaperAnchorTop(string)
      | PaperAnchorBottom(string)
      | PaperAnchorDockedLeft(string)
      | PaperAnchorDockedTop(string)
      | PaperAnchorDockedRight(string)
      | PaperAnchorDockedBottom(string)
      | Modal(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Drawer
       @param type The type of drawer.
       @param SlideProps Properties applied to the `Slide` element.
       @param open If `true`, the drawer is open.
       @param onRequestClose Callback fired when the component requests to be closed.

       @param {object} event The event source of the callback
       @param ModalProps Properties applied to the `Modal` element.
       @param transitionDuration The duration for the transition, in milliseconds.
       You may specify a single timeout for all transitions, or individually with an object.
       @param elevation The elevation of the drawer.
       @param className @ignore
       @param anchor Side from which the drawer will appear.
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param BackdropClassName The CSS class name of the backdrop element.
       @param BackdropComponent Pass a component class to use as the backdrop.
       @param BackdropInvisible If `true`, the backdrop is invisible.
       @param BackdropTransitionDuration The duration for the backdrop transition, in milliseconds.
       You may specify a single timeout for all transitions, or individually with an object.
       @param keepMounted Always keep the children in the DOM.
       This property can be useful in SEO situation or
       when you want to maximize the responsiveness of the Modal.
       @param disableBackdrop If `true`, the backdrop is disabled.
       @param ignoreBackdropClick If `true`, clicking the backdrop will not fire the `onRequestClose` callback.
       @param ignoreEscapeKeyUp If `true`, hitting escape will not fire the `onRequestClose` callback.
       @param modalManager @ignore
       @param onBackdropClick Callback fires when the backdrop is clicked on.
       @param onEnter Callback fired before the modal is entering.
       @param onEntering Callback fired when the modal is entering.
       @param onEntered Callback fired when the modal has entered.
       @param onEscapeKeyUp Callback fires when the escape key is pressed and the modal is in focus.
       @param onExit Callback fired before the modal is exiting.
       @param onExiting Callback fired when the modal is exiting.
       @param onExited Callback fired when the modal has exited.
       @param show If `true`, the Modal is visible. */
  let make:
    (
      ~type_: Type.t=?,
      ~sSlideProps: Js.t({..})=?,
      ~open_: bool=?,
      ~onRequestClose: ReasonReact.Callback.t(ReactEventRe.Synthetic.t)=?,
      ~mModalProps: Js.t({..})=?,
      ~transitionDuration: Js.t({..})=?,
      ~elevation: float=?,
      ~className: string=?,
      ~anchor: Anchor.t=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~bBackdropClassName: string=?,
      ~bBackdropComponent: Js.t({..})=?,
      ~bBackdropInvisible: bool=?,
      ~bBackdropTransitionDuration: Js.t({..})=?,
      ~keepMounted: bool=?,
      ~disableBackdrop: bool=?,
      ~ignoreBackdropClick: bool=?,
      ~ignoreEscapeKeyUp: bool=?,
      ~modalManager: Js.t({..})=?,
      ~onBackdropClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onEnter: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntering: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntered: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEscapeKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onExit: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExiting: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExited: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~show: bool,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Divider: {
  module Classes: {
    type classesType =
      | Root(string)
      | Default(string)
      | Inset(string)
      | Light(string)
      | Absolute(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Divider
       @param light If `true`, the divider will have a lighter color.
       @param inset If `true`, the divider will be indented.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~light: bool=?,
      ~inset: bool=?,
      ~className: string=?,
      ~absolute: bool=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Dialog: {
  module MaxWidth: {
    type t =
      | Xs
      | Sm
      | Md;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | Paper(string)
      | PaperWidthXs(string)
      | PaperWidthSm(string)
      | PaperWidthMd(string)
      | FullWidth(string)
      | FullScreen(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Dialog
       @param transition Transition component.
       @param open If `true`, the Dialog is open.
       @param onRequestClose Callback fired when the component requests to be closed.

       @param {object} event The event source of the callback
       @param onExited Callback fired when the dialog has exited.
       @param onExiting Callback fired when the dialog is exiting.
       @param onExit Callback fired before the dialog exits.
       @param onEscapeKeyUp Callback fires when the escape key is released and the modal is in focus.
       @param onEntered Callback fired when the dialog has entered.
       @param onEntering Callback fired when the dialog is entering.
       @param onEnter Callback fired before the dialog enters.
       @param onBackdropClick Callback fired when the backdrop is clicked.
       @param fullWidth If specified, stretches dialog to max width.
       @param maxWidth Determine the max width of the dialog.
       The dialog width grows with the size of the screen, this property is useful
       on the desktop where you might need some coherent different width size across your
       application.
       @param transitionDuration The duration for the transition, in milliseconds.
       You may specify a single timeout for all transitions, or individually with an object.
       @param ignoreEscapeKeyUp If `true`, hitting escape will not fire the `onRequestClose` callback.
       @param ignoreBackdropClick If `true`, clicking the backdrop will not fire the `onRequestClose` callback.
       @param fullScreen If `true`, it will be full-screen
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param BackdropClassName The CSS class name of the backdrop element.
       @param BackdropComponent Pass a component class to use as the backdrop.
       @param BackdropInvisible If `true`, the backdrop is invisible.
       @param BackdropTransitionDuration The duration for the backdrop transition, in milliseconds.
       You may specify a single timeout for all transitions, or individually with an object.
       @param keepMounted Always keep the children in the DOM.
       This property can be useful in SEO situation or
       when you want to maximize the responsiveness of the Modal.
       @param disableBackdrop If `true`, the backdrop is disabled.
       @param modalManager @ignore
       @param show If `true`, the Modal is visible. */
  let make:
    (
      ~transition: Js.t({..})=?,
      ~open_: bool=?,
      ~onRequestClose: ReasonReact.Callback.t(ReactEventRe.Synthetic.t)=?,
      ~onExited: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExiting: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExit: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEscapeKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onEntered: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntering: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEnter: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onBackdropClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~fullWidth: bool=?,
      ~maxWidth: MaxWidth.t=?,
      ~transitionDuration: Js.t({..})=?,
      ~ignoreEscapeKeyUp: bool=?,
      ~ignoreBackdropClick: bool=?,
      ~fullScreen: bool=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~bBackdropClassName: string=?,
      ~bBackdropComponent: Js.t({..})=?,
      ~bBackdropInvisible: bool=?,
      ~bBackdropTransitionDuration: Js.t({..})=?,
      ~keepMounted: bool=?,
      ~disableBackdrop: bool=?,
      ~modalManager: Js.t({..})=?,
      ~show: bool,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module DialogTitle: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component DialogTitle
       @param disableTypography If `true`, the children won't be wrapped by a typography component.
       For instance, that can be useful to can render an h4 instead of a
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~disableTypography: bool=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module DialogContent: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component DialogContent
       @param className @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (~className: string=?, ~classes: Classes.t=?, array(ReasonReact.reactElement)) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module DialogContentText: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component DialogContentText
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module DialogActions: {
  module Classes: {
    type classesType =
      | Root(string)
      | Action(string)
      | Button(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component DialogActions
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Collapse: {
  module Timeout: {
    type t =
      | Auto;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Container(string)
      | Entered(string)
      | Wrapper(string)
      | WrapperInner(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Collapse
       @param unmountOnExit @ignore
       @param timeout The duration for the transition, in milliseconds.
       You may specify a single timeout for all transitions, or individually with an object.

       Set to 'auto' to automatically calculate transition time based on height.
       @param style @ignore
       @param onExiting @ignore
       @param onExit @ignore
       @param onEntered @ignore
       @param onEntering @ignore
       @param onEnter @ignore
       @param in If `true`, the component will transition in.
       @param containerProps Properties applied to the `Collapse` container.
       @param collapsedHeight The height of the container when collapsed.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       The default value is a `button`.
       @param className @ignore
       @param appear @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~unmountOnExit: bool=?,
      ~timeout: [ | `Enum(Timeout.t) | `Float(float) | `Object({. "enter": int, "exit": int})]=?,
      ~style: Js.t({..})=?,
      ~onExiting: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onExit: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntered: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEntering: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~onEnter: ReasonReact.Callback.t(ReactEventRe.Transition.t)=?,
      ~in_: bool,
      ~containerProps: Js.t({..})=?,
      ~collapsedHeight: string=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~appear: bool=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ClickAwayListener: {

  /*** Component ClickAwayListener
   */
  let make:
    (~onClickAway: ReactEventRe.Synthetic.t => unit, array(ReasonReact.reactElement)) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module CircularProgress: {
  module Mode: {
    type t =
      | Determinate
      | Indeterminate;
    let to_string: t => string;
  };
  module Color: {
    type t =
      | Primary
      | Accent
      | Inherit;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | PrimaryColor(string)
      | AccentColor(string)
      | SvgIndeterminate(string)
      | SvgDeterminate(string)
      | Circle(string)
      | CircleIndeterminate(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component CircularProgress
       @param value The value of progress in determinate mode.
       @param thickness The thickness of the circle.
       @param style @ignore
       @param size The size of the circle.
       @param mode The mode of show your progress. Indeterminate
       for when there is no value for progress.
       Determinate for controlled progress value.
       @param min The min value of progress in determinate mode.
       @param max The max value of progress in determinate mode.
       @param color The color of the component. It's using the theme palette when that makes sense.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~value: float=?,
      ~thickness: float=?,
      ~style: Js.t({..})=?,
      ~size: float=?,
      ~mode: Mode.t=?,
      ~min: float=?,
      ~max: float=?,
      ~color: Color.t=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Chip: {
  module Classes: {
    type classesType =
      | Root(string)
      | Clickable(string)
      | Deletable(string)
      | Avatar(string)
      | AvatarChildren(string)
      | Label(string)
      | DeleteIcon(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Chip
       @param tabIndex @ignore
       @param onRequestDelete Callback function fired when the delete icon is clicked.
       If set, the delete icon will be shown.
       @param onKeyDown @ignore
       @param onClick @ignore
       @param label The content of the label.
       @param deleteIcon Custom delete icon. Will be shown only if `onRequestDelete` is set.
       @param className @ignore
       @param avatar Avatar element.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      ~onRequestDelete: ReactEventRe.Synthetic.t => unit=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~label: ReasonReact.reactElement=?,
      ~deleteIcon: ReasonReact.reactElement=?,
      ~className: string=?,
      ~avatar: ReasonReact.reactElement=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Checkbox: {
  module Classes: {
    type classesType =
      | Default(string)
      | Checked(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Checkbox
       @param value The value of the component.
       @param tabIndex @ignore
       @param onChange Callback fired when the state is changed.

       @param {object} event The event source of the callback
       @param {boolean} checked The `checked` value of the switch
       @param inputRef Use that property to pass a ref callback to the native input component.
       @param inputProps Properties applied to the `input` element.
       @param indeterminateIcon The icon to display when the component is indeterminate.
       If a string is provided, it will be used as a font ligature.
       @param indeterminate If `true`, the component appears indeterminate.
       @param icon The icon to display when the component is unchecked.
       If a string is provided, it will be used as a font ligature.
       @param disableRipple If `true`, the ripple effect will be disabled.
       @param disabled If `true`, the switch will be disabled.
       @param defaultChecked @ignore
       @param className @ignore
       @param checkedIcon The icon to display when the component is checked.
       If a string is provided, it will be used as a font ligature.
       @param checked If `true`, the component is checked.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~value: string=?,
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~name: string=?,
      ~inputRef: 'a=?,
      ~inputProps: Js.t({..})=?,
      ~indeterminateIcon: ReasonReact.reactElement=?,
      ~indeterminate: bool=?,
      ~icon: ReasonReact.reactElement=?,
      ~disableRipple: bool=?,
      ~disabled: bool=?,
      ~defaultChecked: bool=?,
      ~className: string=?,
      ~checkedIcon: ReasonReact.reactElement=?,
      ~checked: [ | `Bool(bool) | `String(string)]=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Card: {
  module Classes: {
    type classesType =
      | Root(string)
      | Rounded(string)
      | Shadow0(string)
      | Shadow1(string)
      | Shadow2(string)
      | Shadow3(string)
      | Shadow4(string)
      | Shadow5(string)
      | Shadow6(string)
      | Shadow7(string)
      | Shadow8(string)
      | Shadow9(string)
      | Shadow10(string)
      | Shadow11(string)
      | Shadow12(string)
      | Shadow13(string)
      | Shadow14(string)
      | Shadow15(string)
      | Shadow16(string)
      | Shadow17(string)
      | Shadow18(string)
      | Shadow19(string)
      | Shadow20(string)
      | Shadow21(string)
      | Shadow22(string)
      | Shadow23(string)
      | Shadow24(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Card
       @param className @ignore
       @param raised If `true`, the card will use raised styling.
       @param classes Useful to extend the style applied to components.
       @param theme @ignore
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param elevation Shadow depth, corresponds to `dp` in the spec.
       It's accepting values between 0 and 24 inclusive.
       @param square If `true`, rounded corners are disabled. */
  let make:
    (
      ~className: string=?,
      ~raised: bool=?,
      ~classes: Classes.t=?,
      ~theme: Js.t({..})=?,
      ~component: Js.t({..})=?,
      ~elevation: float=?,
      ~square: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module CardMedia: {
  module Classes: {
    type classesType =
      | Root(string)
      | RootMedia(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component CardMedia
       @param component Component for rendering image.
       @param style @ignore
       @param src An alias for `image` property.
       Available only with media components.
       Media components: `video`, `audio`, `picture`, `iframe`, `img`.
       @param image Image to be displayed as a background image.
       Either `image` or `src` prop must be specified.
       Note that caller must specify height otherwise the image will not be visible.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~component: Js.t({..})=?,
      ~style: Js.t({..})=?,
      ~src: string=?,
      ~image: string=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module CardHeader: {
  module Classes: {
    type classesType =
      | Root(string)
      | Avatar(string)
      | Action(string)
      | Content(string)
      | Title(string)
      | Subheader(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component CardHeader
       @param title The content of the Card Title.
       @param subheader The content of the component.
       @param className @ignore
       @param avatar The Avatar for the Card Header.
       @param action The action to display in the card header.
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~title: ReasonReact.reactElement=?,
      ~subheader: ReasonReact.reactElement=?,
      ~className: string=?,
      ~avatar: ReasonReact.reactElement=?,
      ~action: ReasonReact.reactElement=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module CardContent: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component CardContent
       @param className @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (~className: string=?, ~classes: Classes.t=?, array(ReasonReact.reactElement)) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module CardActions: {
  module Classes: {
    type classesType =
      | Root(string)
      | Action(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component CardActions
       @param disableActionSpacing If `true`, the card actions do not have additional margin.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~disableActionSpacing: bool=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Button: {
  module Color: {
    type t =
      | Default
      | Inherit
      | Primary
      | Accent
      | Contrast;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | Dense(string)
      | Label(string)
      | FlatPrimary(string)
      | FlatAccent(string)
      | FlatContrast(string)
      | ColorInherit(string)
      | Raised(string)
      | KeyboardFocused(string)
      | RaisedPrimary(string)
      | RaisedAccent(string)
      | RaisedContrast(string)
      | Disabled(string)
      | Fab(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Button
       @param type @ignore
       @param raised If `true`, the button will use raised styling.
       @param href The URL to link to when the button is clicked.
       If defined, an `a` element will be used as the root node.
       @param fab If `true`, will use floating action button styling.
       @param disableRipple If `true`, the ripple effect will be disabled.
       @param disableFocusRipple If `true`, the  keyboard focus ripple will be disabled.
       `disableRipple` must also be true.
       @param disabled If `true`, the button will be disabled.
       @param dense Uses a smaller minWidth, ideal for things like card actions.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       The default value is a `button`.
       @param color The color of the component. It's using the theme palette when that makes sense.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param centerRipple If `true`, the ripples will be centered.
       They won't start at the cursor interaction position.
       @param focusRipple If `true`, the base button will have a keyboard focus ripple.
       `disableRipple` must also be `false`.
       @param keyboardFocusedClassName The CSS class applied while the component is keyboard focused.
       @param onBlur @ignore
       @param onClick @ignore
       @param onFocus @ignore
       @param onKeyboardFocus Callback fired when the component is focused with a keyboard.
       We trigger a `onFocus` callback too.
       @param onKeyDown @ignore
       @param onKeyUp @ignore
       @param onMouseDown @ignore
       @param onMouseLeave @ignore
       @param onMouseUp @ignore
       @param onTouchEnd @ignore
       @param onTouchMove @ignore
       @param onTouchStart @ignore
       @param role @ignore
       @param rootRef Use that property to pass a ref callback to the root component.
       @param tabIndex @ignore */
  let make:
    (
      ~type_: string=?,
      ~raised: bool=?,
      ~href: string=?,
      ~fab: bool=?,
      ~disableRipple: bool=?,
      ~disableFocusRipple: bool=?,
      ~disabled: bool=?,
      ~dense: bool=?,
      ~component: Js.t({..})=?,
      ~color: Color.t=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~centerRipple: bool=?,
      ~focusRipple: bool=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReactEventRe.Synthetic.t => unit=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~rootRef: 'a=?,
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module ButtonBase: {
  module Classes: {
    type classesType =
      | Root(string)
      | Disabled(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component ButtonBase
       @param type @ignore
       @param tabIndex @ignore
       @param rootRef Use that property to pass a ref callback to the root component.
       @param role @ignore
       @param onTouchStart @ignore
       @param onTouchMove @ignore
       @param onTouchEnd @ignore
       @param onMouseUp @ignore
       @param onMouseLeave @ignore
       @param onMouseDown @ignore
       @param onKeyUp @ignore
       @param onKeyDown @ignore
       @param onKeyboardFocus Callback fired when the component is focused with a keyboard.
       We trigger a `onFocus` callback too.
       @param onFocus @ignore
       @param onClick @ignore
       @param onBlur @ignore
       @param keyboardFocusedClassName The CSS class applied while the component is keyboard focused.
       @param focusRipple If `true`, the base button will have a keyboard focus ripple.
       `disableRipple` must also be `false`.
       @param disableRipple If `true`, the ripple effect will be disabled.
       @param disabled If `true`, the base button will be disabled.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       The default value is a `button`.
       @param className @ignore
       @param centerRipple If `true`, the ripples will be centered.
       They won't start at the cursor interaction position.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~type_: string=?,
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      ~rootRef: 'a=?,
      ~role: string=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyboardFocus: ReactEventRe.Synthetic.t => unit=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~keyboardFocusedClassName: string=?,
      ~focusRipple: bool=?,
      ~disableRipple: bool=?,
      ~disabled: bool=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~centerRipple: bool=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module BottomNavigation: {
  module Classes: {
    type classesType =
      | Root(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component BottomNavigation
       @param value The value of the currently selected `BottomNavigationButton`.
       @param showLabels If `true`, all `BottomNavigationButton`s will show their labels.
       By default only the selected `BottomNavigationButton` will show its label.
       @param onChange Callback fired when the value changes.

       @param {object} event The event source of the callback
       @param {any} value We default to the index of the child
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~value: 'a,
      ~showLabels: bool=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module BottomNavigationButton: {
  module Classes: {
    type classesType =
      | Root(string)
      | Selected(string)
      | SelectedIconOnly(string)
      | Wrapper(string)
      | Label(string)
      | SelectedLabel(string)
      | HiddenLabel(string)
      | Icon(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component BottomNavigationButton
       @param value You can provide your own value. Otherwise, we fallback to the child position index.
       @param showLabel If `true`, the BottomNavigationButton will show its label.
       @param selected @ignore
       @param onClick @ignore
       @param onChange @ignore
       @param label The label element.
       @param icon The icon element. If a string is provided, it will be used as a font ligature.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param centerRipple If `true`, the ripples will be centered.
       They won't start at the cursor interaction position.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       The default value is a `button`.
       @param disabled If `true`, the base button will be disabled.
       @param disableRipple If `true`, the ripple effect will be disabled.
       @param focusRipple If `true`, the base button will have a keyboard focus ripple.
       `disableRipple` must also be `false`.
       @param keyboardFocusedClassName The CSS class applied while the component is keyboard focused.
       @param onBlur @ignore
       @param onFocus @ignore
       @param onKeyboardFocus Callback fired when the component is focused with a keyboard.
       We trigger a `onFocus` callback too.
       @param onKeyDown @ignore
       @param onKeyUp @ignore
       @param onMouseDown @ignore
       @param onMouseLeave @ignore
       @param onMouseUp @ignore
       @param onTouchEnd @ignore
       @param onTouchMove @ignore
       @param onTouchStart @ignore
       @param role @ignore
       @param rootRef Use that property to pass a ref callback to the root component.
       @param tabIndex @ignore
       @param type @ignore */
  let make:
    (
      ~value: 'a=?,
      ~showLabel: bool=?,
      ~selected: bool=?,
      ~onClick: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onChange: ReasonReact.Callback.t(ReactEventRe.Form.t)=?,
      ~label: ReasonReact.reactElement=?,
      ~icon: [ | `String(string) | `Element(ReasonReact.reactElement)]=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~centerRipple: bool=?,
      ~component: Js.t({..})=?,
      ~disabled: bool=?,
      ~disableRipple: bool=?,
      ~focusRipple: bool=?,
      ~keyboardFocusedClassName: string=?,
      ~onBlur: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onFocus: ReasonReact.Callback.t(ReactEventRe.Focus.t)=?,
      ~onKeyboardFocus: ReactEventRe.Synthetic.t => unit=?,
      ~onKeyDown: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onKeyUp: ReasonReact.Callback.t(ReactEventRe.Keyboard.t)=?,
      ~onMouseDown: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseLeave: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onMouseUp: ReasonReact.Callback.t(ReactEventRe.Mouse.t)=?,
      ~onTouchEnd: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchMove: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~onTouchStart: ReasonReact.Callback.t(ReactEventRe.Touch.t)=?,
      ~role: string=?,
      ~rootRef: 'b=?,
      ~tabIndex: [ | `Float(float) | `String(string)]=?,
      ~type_: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Badge: {
  module Color: {
    type t =
      | Default
      | Primary
      | Accent;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | Badge(string)
      | ColorPrimary(string)
      | ColorAccent(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Badge
       @param color The color of the component. It's using the theme palette when that makes sense.
       @param className @ignore
       @param badgeContent The content rendered within the badge.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~color: Color.t=?,
      ~className: string=?,
      ~badgeContent: ReasonReact.reactElement,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module Avatar: {
  module Classes: {
    type classesType =
      | Root(string)
      | ColorDefault(string)
      | Img(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component Avatar
       @param srcSet The `srcSet` attribute for the `img` element.
       @param src The `src` attribute for the `img` element.
       @param sizes The `sizes` attribute for the `img` element.
       @param imgProps Properties applied to the `img` element when the component
       is used to display an image.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param className @ignore
       @param childrenClassName @ignore
       The className of the child element.
       Used by Chip and ListItemIcon to style the Avatar icon.
       @param alt Used in combination with `src` or `srcSet` to
       provide an alt attribute for the rendered `img` element.
       @param theme @ignore
       @param classes Useful to extend the style applied to components. */
  let make:
    (
      ~srcSet: string=?,
      ~src: string=?,
      ~sizes: string=?,
      ~imgProps: Js.t({..})=?,
      ~component: Js.t({..})=?,
      ~className: string=?,
      ~childrenClassName: string=?,
      ~alt: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};

module AppBar: {
  module Position: {
    type t =
      | Static
      | Fixed
      | Absolute;
    let to_string: t => string;
  };
  module Color: {
    type t =
      | Inherit
      | Primary
      | Accent
      | Default;
    let to_string: t => string;
  };
  module Classes: {
    type classesType =
      | Root(string)
      | PositionFixed(string)
      | PositionAbsolute(string)
      | PositionStatic(string)
      | ColorDefault(string)
      | ColorPrimary(string)
      | ColorAccent(string);
    type t = list(classesType);
    let to_string: classesType => string;
    let to_obj: t => Js.Dict.t(string);
  };

  /*** Component AppBar
       @param position The positioning type.
       @param color The color of the component. It's using the theme palette when that makes sense.
       @param className @ignore
       @param theme @ignore
       @param classes Useful to extend the style applied to components.
       @param component The component used for the root node.
       Either a string to use a DOM element or a component.
       @param elevation Shadow depth, corresponds to `dp` in the spec.
       It's accepting values between 0 and 24 inclusive.
       @param square If `true`, rounded corners are disabled. */
  let make:
    (
      ~position: Position.t=?,
      ~color: Color.t=?,
      ~className: string=?,
      ~theme: Js.t({..})=?,
      ~classes: Classes.t=?,
      ~component: Js.t({..})=?,
      ~elevation: float=?,
      ~square: bool=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      ReasonReact.actionless
    );
};
