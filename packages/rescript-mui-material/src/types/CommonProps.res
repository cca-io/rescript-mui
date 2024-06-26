type ariaProps = {
  /* accessibility */
  /* https://www.w3.org/TR/wai-aria-1.1/ */
  /* https://accessibilityresources.org/<aria-tag> is a great resource for these */
  @as("aria-current")
  ariaCurrent?: [#page | #step | #location | #date | #time | #"true" | #"false"],
  @as("aria-details")
  ariaDetails?: string,
  @as("aria-disabled")
  ariaDisabled?: bool,
  @as("aria-hidden")
  ariaHidden?: bool,
  @as("aria-invalid") ariaInvalid?: [#grammar | #"false" | #spelling | #"true"],
  @as("aria-keyshortcuts")
  ariaKeyshortcuts?: string,
  @as("aria-label")
  ariaLabel?: string,
  @as("aria-roledescription")
  ariaRoledescription?: string,
  /* Widget Attributes */
  @as("aria-autocomplete") ariaAutocomplete?: [#inline | #list | #both | #none],
  /* https://www.w3.org/TR/wai-aria-1.1/#valuetype_tristate */
  @as("aria-checked")
  ariaChecked?: [#"true" | #"false" | #mixed],
  @as("aria-expanded")
  ariaExpanded?: bool,
  @as("aria-haspopup")
  ariaHaspopup?: [#menu | #listbox | #tree | #grid | #dialog | #"true" | #"false"],
  @as("aria-level")
  ariaLevel?: int,
  @as("aria-modal")
  ariaModal?: bool,
  @as("aria-multiline")
  ariaMultiline?: bool,
  @as("aria-multiselectable")
  ariaMultiselectable?: bool,
  @as("aria-orientation") ariaOrientation?: [#horizontal | #vertical | #undefined],
  @as("aria-placeholder")
  ariaPlaceholder?: string,
  /* https://www.w3.org/TR/wai-aria-1.1/#valuetype_tristate */
  @as("aria-pressed") ariaPressed?: [#"true" | #"false" | #mixed],
  @as("aria-readonly")
  ariaReadonly?: bool,
  @as("aria-required")
  ariaRequired?: bool,
  @as("aria-selected")
  ariaSelected?: bool,
  @as("aria-sort")
  ariaSort?: string,
  @as("aria-valuemax")
  ariaValuemax?: float,
  @as("aria-valuemin")
  ariaValuemin?: float,
  @as("aria-valuenow")
  ariaValuenow?: float,
  @as("aria-valuetext")
  ariaValuetext?: string,
  /* Live Region Attributes */
  @as("aria-atomic")
  ariaAtomic?: bool,
  @as("aria-busy")
  ariaBusy?: bool,
  @as("aria-live") ariaLive?: [#off | #polite | #assertive | #rude],
  @as("aria-relevant")
  ariaRelevant?: string,
  /* Drag-and-Drop Attributes */
  @as("aria-dropeffect") ariaDropeffect?: [#copy | #move | #link | #execute | #popup | #none],
  @as("aria-grabbed")
  ariaGrabbed?: bool,
  /* Relationship Attributes */
  @as("aria-activedescendant")
  ariaActivedescendant?: string,
  @as("aria-colcount")
  ariaColcount?: int,
  @as("aria-colindex")
  ariaColindex?: int,
  @as("aria-colspan")
  ariaColspan?: int,
  @as("aria-controls")
  ariaControls?: string,
  @as("aria-describedby")
  ariaDescribedby?: string,
  @as("aria-errormessage")
  ariaErrormessage?: string,
  @as("aria-flowto")
  ariaFlowto?: string,
  @as("aria-labelledby")
  ariaLabelledby?: string,
  @as("aria-owns")
  ariaOwns?: string,
  @as("aria-posinset")
  ariaPosinset?: int,
  @as("aria-rowcount")
  ariaRowcount?: int,
  @as("aria-rowindex")
  ariaRowindex?: int,
  @as("aria-rowspan")
  ariaRowspan?: int,
  @as("aria-setsize")
  ariaSetsize?: int,
}

type t_NoId = {
  // Cannot spread whole dom props since overwriting is not possible.
  ...ariaProps,
  className?: string,
  style?: ReactDOM.Style.t,
  ref?: ReactDOM.domRef,
}

type classNameOnly = {className: string}

type t_NoRef = {
  className?: string,
  style?: ReactDOM.Style.t,
  id?: string,
}

type t = {
  ...t_NoId,
  id?: string,
}

type clickableProps = {
  ...t,
  onBlur?: ReactEvent.Focus.t => unit,
  onContextMenu?: ReactEvent.Mouse.t => unit,
  onDragLeave?: ReactEvent.Mouse.t => unit,
  onFocus?: ReactEvent.Focus.t => unit,
  onKeyDown?: ReactEvent.Keyboard.t => unit,
  onKeyPress?: ReactEvent.Keyboard.t => unit,
  onKeyUp?: ReactEvent.Keyboard.t => unit,
  onMouseDown?: ReactEvent.Mouse.t => unit,
  onMouseEnter?: ReactEvent.Mouse.t => unit,
  onMouseLeave?: ReactEvent.Mouse.t => unit,
  onMouseUp?: ReactEvent.Mouse.t => unit,
  onTouchEnd?: ReactEvent.Touch.t => unit,
  onTouchMove?: ReactEvent.Touch.t => unit,
  onTouchStart?: ReactEvent.Touch.t => unit,
}

type clickablePropsWithOnClick = {
  ...clickableProps,
  onClick?: ReactEvent.Mouse.t => unit,
  onDoubleClick?: ReactEvent.Mouse.t => unit,
}
