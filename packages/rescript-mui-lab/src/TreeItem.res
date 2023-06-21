module Content = {
  type classes = {
    /** Styles applied to the root element. */
    root?: string,
    /** State class applied to the content element when expanded. */
    expanded?: string,
    /** State class applied to the content element when selected. */
    selected?: string,
    /** State class applied to the content element when focused. */
    focused?: string,
    /** State class applied to the element when disabled. */
    disabled?: string,
    /** Styles applied to the tree node icon and collapse/expand icon. */
    iconContainer?: string,
    /** Styles applied to the label element. */
    label?: string,
  }

  type props = {
    /**
   * className applied to the root element.
   */
    className?: string,
    /**
   * Override or extend the styles applied to the component.
   */
    classes: classes,
    /**
   * The tree node label.
   */
    label?: React.element,
    /**
   * The id of the node.
   */
    nodeId: string,
    /**
   * The icon to display next to the tree node's label.
   */
    icon?: React.element,
    /**
   * The icon to display next to the tree node's label. Either an expansion or collapse icon.
   */
    expansionIcon?: React.element,
    /**
   * The icon to display next to the tree node's label. Either a parent or end icon.
   */
    displayIcon?: React.element,
  }
}

type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the transition component. */
  group?: string,
  /** Styles applied to the content element. */
  content?: string,
  /** State class applied to the content element when expanded. */
  expanded?: string,
  /** State class applied to the content element when selected. */
  selected?: string,
  /** State class applied to the content element when focused. */
  focused?: string,
  /** State class applied to the element when disabled. */
  disabled?: string,
  /** Styles applied to the tree node icon. */
  iconContainer?: string,
  /** Styles applied to the label element. */
  label?: string,
}

type props = {
  ...Mui.CommonProps.clickablePropsWithOnClick,
  /**
   * The id of the node.
   */
  nodeId: string,
  /**
   * The content of the component.
   */
  children?: React.element,
  /**
   * Override or extend the styles applied to the component.
   */
  classes?: classes,
  /**
   * The icon used to collapse the node.
   */
  collapseIcon?: React.element,
  /**
   * The component used for the content node.
   * @default TreeItemContent
   */
  @as("ContentComponent")
  contentComponent?: React.component<Content.props>,
  /**
   * Props applied to ContentComponent
   */
  @as("ContentProps")
  contentProps?: Content.props,
  /**
   * If `true`, the node is disabled.
   * @default false
   */
  disabled?: bool,
  /**
   * The icon displayed next to a end node.
   */
  endIcon?: React.element,
  /**
   * The icon used to expand the node.
   */
  expandIcon?: React.element,
  /**
   * The icon to display next to the tree node's label.
   */
  icon?: React.element,
  /**
   * The tree node label.
   */
  label?: React.element,
  /**
   * The system prop that allows defining system overrides as well as additional CSS styles.
   */
  sx?: Mui.Sx.props,
  /**
   * The component used for the transition.
   * [Follow this guide](/material-ui/transitions/#transitioncomponent-prop) to learn more about the requirements for this component.
   * @default Collapse
   */
  @as("TransitionComponent")
  transitionComponent?: React.component<Mui.Transition.props>,
  /**
   * Props applied to the transition element.
   * By default, the element is based on this [`Transition`](http://reactcommunity.org/react-transition-group/transition/) component.
   */
  @as("TransitionProps")
  transitionProps?: Mui.Transition.props,
}

@module("@mui/lab/TreeItem")
external make: React.component<props> = "default"
