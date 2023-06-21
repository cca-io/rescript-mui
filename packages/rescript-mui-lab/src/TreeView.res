type classes = {
  /** Styles applied to the root element. */
  root?: string,
}

type propsBase = {
  ...Mui.CommonProps.t,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The default icon used to collapse the node.
    */
  defaultCollapseIcon?: React.element,
  /**
    * The default icon displayed next to a end node. This is applied to all
    * tree nodes and can be overridden by the TreeItem `icon` prop.
    */
  defaultEndIcon?: React.element,
  /**
    * Expanded node ids. (Uncontrolled)
    * @default []
    */
  defaultExpanded?: array<string>,
  /**
    * The default icon used to expand the node.
    */
  defaultExpandIcon?: React.element,
  /**
    * The default icon displayed next to a parent node. This is applied to all
    * parent nodes and can be overridden by the TreeItem `icon` prop.
    */
  defaultParentIcon?: React.element,
  /**
    * If `true`, will allow focus on disabled items.
    * @default false
    */
  disabledItemsFocusable?: bool,
  /**
    * If `true` selection is disabled.
    * @default false
    */
  disableSelection?: bool,
  /**
    * Expanded node ids. (Controlled)
    */
  expanded?: array<string>,
  /**
    * Callback fired when tree items are focused.
    *
    * @param {React.SyntheticEvent} event The event source of the callback **Warning**: This is a generic event not a focus event.
    * @param {string} value of the focused node.
    */
  onNodeFocus?: (ReactEvent.Synthetic.t, string) => unit,
  /**
    * Callback fired when tree items are expanded/collapsed.
    *
    * @param {React.SyntheticEvent} event The event source of the callback.
    * @param {array} nodeIds The ids of the expanded nodes.
    */
  onNodeToggle?: (ReactEvent.Synthetic.t, array<string>) => unit,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Mui.Sx.props,
  onBlur?: ReactEvent.Focus.t => unit,
  onFocus?: ReactEvent.Focus.t => unit,
}

@unboxed
type onlyFalse = | @as(false) False

@unboxed
type onlyTrue = | @as(true) True

type props = {
  ...propsBase,
  /**
    * Selected node id. (Uncontrolled)
    */
  defaultSelected?: string,
  /**
    * Selected node id. (Controlled)
    */
  selected?: string,
  /**
    * If true `ctrl` and `shift` will trigger multiselect.
    * @default false
    */
  multiSelect?: onlyFalse,
  /**
    * Callback fired when tree items are selected/unselected.
    *
    * @param {React.SyntheticEvent} event The event source of the callback
    * @param {string} nodeId of the selected node.
    */
  onNodeSelect?: (ReactEvent.Synthetic.t, string) => unit,
}

@module("@mui/lab/TreeView")
external make: React.component<props> = "default"

module MultiSelect = {
  @unboxed
  type multiSelect = | @as(true) True

  type props = {
    ...propsBase,
    /**
      * Selected node ids. (Uncontrolled)
      * When `multiSelect` is true this takes an array of strings; when false (default) a string.
      * @default []
      */
    defaultSelected?: array<string>,
    /**
      * Selected node ids. (Controlled)
      * When `multiSelect` is true this takes an array of strings, when false (default) a string.
      */
    selected?: array<string>,
    /**
      * If true `ctrl` and `shift` will trigger multiselect.
      * @default false
      */
    multiSelect: onlyTrue,
    /**
      * Callback fired when tree items are selected/unselected.
      *
      * @param {React.SyntheticEvent} event The event source of the callback
      * @param {string[]} nodeIds Ids of the selected nodes.
      */
    onNodeSelect?: (ReactEvent.Synthetic.t, array<string>) => unit,
  }

  @module("@mui/lab/TreeView")
  external make: React.component<props> = "default"
}
