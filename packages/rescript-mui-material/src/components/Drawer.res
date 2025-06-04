type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the root element if `variant="permanent or persistent"`. */
  docked?: string,
  /** Styles applied to the Paper component. */
  paper?: string,
  /** Styles applied to the Paper component if `anchor="left"`. */
  paperAnchorLeft?: string,
  /** Styles applied to the Paper component if `anchor="right"`. */
  paperAnchorRight?: string,
  /** Styles applied to the Paper component if `anchor="top"`. */
  paperAnchorTop?: string,
  /** Styles applied to the Paper component if `anchor="bottom"`. */
  paperAnchorBottom?: string,
  /** Styles applied to the Paper component if `anchor="left"` and `variant` is not "temporary". */
  paperAnchorDockedLeft?: string,
  /** Styles applied to the Paper component if `anchor="top"` and `variant` is not "temporary". */
  paperAnchorDockedTop?: string,
  /** Styles applied to the Paper component if `anchor="right"` and `variant` is not "temporary". */
  paperAnchorDockedRight?: string,
  /** Styles applied to the Paper component if `anchor="bottom"` and `variant` is not "temporary". */
  paperAnchorDockedBottom?: string,
  /** Styles applied to the Modal component. */
  modal?: string,
}

type anchor =
  | @as("left") Left
  | @as("top") Top
  | @as("right") Right
  | @as("bottom") Bottom

type variant =
  | @as("permanent") Permanent
  | @as("persistent") Persistent
  | @as("temporary") Temporary

type slotProps = {
  /** Props applied to the backdrop element. */
  backdrop?: Backdrop.props,
  /** Props applied to the docked element. */
  docked?: ReactDOM.domProps,
  /** Props applied to the paper element. */
  paper?: Paper.props,
  /** Props applied to the root element. */
  root?: Modal.props,
  /** Props applied to the transition element. */
  transition?: Slide.props,
}

type slots = {
  /** The component used for the backdrop. */
  backdrop?: OverridableComponent.t<unknown>,
  /** The component used for the docked element. */
  docked?: OverridableComponent.t<unknown>,
  /** The component used for the paper. */
  paper?: OverridableComponent.t<unknown>,
  /** The component used for the root element. */
  root?: OverridableComponent.t<unknown>,
  /** The component used for the transition. */
  transition?: OverridableComponent.t<unknown>,
}

type props = {
  ...Modal.publicProps,
  /**
    * Side from which the drawer will appear.
    * @default 'left'
    */
  anchor?: anchor,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The elevation of the drawer.
    * @default 16
    */
  elevation?: int,
  /**
    * Props applied to the [`Modal`](/material-ui/api/modal/) element.
    * @default {}
    */
  @as("ModalProps")
  modalProps?: Modal.props,
  /**
    * Callback fired when the component requests to be closed.
    *
    * @param {object} event The event source of the callback.
    */
  onClose?: Modal.onClose,
  /**
    * If `true`, the component is shown.
    * @default false
    */
  @as("open")
  open_?: bool,
  /**
    * Props applied to the [`Paper`](/material-ui/api/paper/) element.
    * @default {}
    * @deprecated Use slotProps.paper instead. This prop will be removed in a future major release.
    */
  @as("PaperProps")
  paperProps?: Paper.props,
  /**
    * Props applied to the [`Slide`](/material-ui/api/slide/) element.
    * @deprecated Use slotProps.transition instead. This prop will be removed in a future major release.
    */
  @as("SlideProps")
  slideProps?: Slide.props,
  /**
    * The props used for each slot inside.
    */
  slotProps?: slotProps,
  /**
    * The components used for each slot inside.
    */
  slots?: slots,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
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
    * The variant to use.
    * @default 'temporary'
    */
  variant?: variant,
}

@module("@mui/material/Drawer")
external make: React.component<props> = "default"
