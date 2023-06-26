type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the container element if `scroll="paper"`. */
  scrollPaper?: string,
  /** Styles applied to the container element if `scroll="body"`. */
  scrollBody?: string,
  /** Styles applied to the container element. */
  container?: string,
  /** Styles applied to the Paper component. */
  paper?: string,
  /** Styles applied to the Paper component if `scroll="paper"`. */
  paperScrollPaper?: string,
  /** Styles applied to the Paper component if `scroll="body"`. */
  paperScrollBody?: string,
  /** Styles applied to the Paper component if `maxWidth=false`. */
  paperWidthFalse?: string,
  /** Styles applied to the Paper component if `maxWidth="xs"`. */
  paperWidthXs?: string,
  /** Styles applied to the Paper component if `maxWidth="sm"`. */
  paperWidthSm?: string,
  /** Styles applied to the Paper component if `maxWidth="md"`. */
  paperWidthMd?: string,
  /** Styles applied to the Paper component if `maxWidth="lg"`. */
  paperWidthLg?: string,
  /** Styles applied to the Paper component if `maxWidth="xl"`. */
  paperWidthXl?: string,
  /** Styles applied to the Paper component if `fullWidth={true}`. */
  paperFullWidth?: string,
  /** Styles applied to the Paper component if `fullScreen={true}`. */
  paperFullScreen?: string,
}

@unboxed
type maxWidth =
  | @as("xs") Xs
  | @as("sm") Sm
  | @as("md") Md
  | @as("lg") Lg
  | @as("xl") Xl
  | @as(false) False
  | String(string)

type scroll =
  | @as("body") Body
  | @as("paper") Paper

type props = {
  ...Modal.publicProps,
  /**
    * If `true`, the component is shown.
    */
  @as("open")
  open_: bool,
  /**
    * The id(s) of the element(s) that describe the dialog.
    */
  @as("aria-describedby")
  ariaDescribedby?: string,
  /**
    * The id(s) of the element(s) that label the dialog.
    */
  @as("aria-labelledby")
  ariaLabelledby?: string,
  /**
    * Dialog children, usually the included sub-components.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * An HTML element or function that returns one.
    * The `container` will have the portal children appended to it.
    *
    * By default, it uses the body of the top-level document object,
    * so it's simply `document.body` most of the time.
    */
  container?: React.element,
  /**
    * If `true`, the dialog is full-screen.
    * @default false
    */
  fullScreen?: bool,
  /**
    * If `true`, the dialog stretches to `maxWidth`.
    *
    * Notice that the dialog width grow is limited by the default margin.
    * @default false
    */
  fullWidth?: bool,
  /**
    * Determine the max-width of the dialog.
    * The dialog width grows with the size of the screen.
    * Set to `false` to disable `maxWidth`.
    * @default 'sm'
    */
  maxWidth?: maxWidth,
  /**
    * Callback fired when the component requests to be closed.
    *
    * @param {object} event The event source of the callback.
    * @param {string} reason Can be: `"escapeKeyDown"`, `"backdropClick"`.
    */
  onClose?: Modal.onClose,
  /**
    * The component used to render the body of the dialog.
    * @default Paper
    */
  @as("PaperComponent")
  paperComponent?: React.component<Paper.props>,
  /**
    * Props applied to the [`Paper`](/material-ui/api/paper/) element.
    * @default {}
    */
  @as("PaperProps")
  paperProps?: Paper.props,
  /**
    * Determine the container for scrolling the dialog.
    * @default 'paper'
    */
  scroll?: scroll,
  /**
    * The components used for each slot inside the Modal.
    * Either a string to use a HTML element or a component.
    * @default {}
    */
  slots?: Modal.slots,
  /**
    * The props used for each slot inside the Modal.
    * @default {}
    */
  slotProps?: Modal.slotProps,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The component used for the transition.
    * [Follow this guide](/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
    * @default Fade
    */
  @as("TransitionComponent")
  transitionComponent?: React.component<Transition.props>,
  /**
    * The duration for the transition, in milliseconds.
    * You may specify a single timeout for all transitions, or individually with an object.
    * @default {
    *   enter: theme.transitions.duration.enteringScreen,
    *   exit: theme.transitions.duration.leavingScreen,
    * }
    */
  transitionDuration?: Transition.duration,
  /**
    * Props applied to the transition element.
    * By default, the element is based on this [`Transition`](http://reactcommunity.org/react-transition-group/transition/) component.
    */
  @as("TransitionProps")
  transitionProps?: Transition.props,
}

@module("@mui/material/Dialog")
external make: React.component<props> = "default"
