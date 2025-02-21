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
  @as("data-testid") dataTestId?: string,
  /**
    * @default 0
    */
  tabIndex?: int,
}

type classNameOnly = {className: string}

type t_NoRef = {
  className?: string,
  style?: ReactDOM.Style.t,
  id?: string,
}

type t_NoTitle = {
  ...t_NoId,
  id?: string,
}

type t = {
  ...t_NoId,
  id?: string,
  title?: string,
}

type clickableProps = {
  ...t,
  // Focus Events
  onBlur?: ReactEvent.Focus.t => unit,
  onFocus?: ReactEvent.Focus.t => unit,

  // Keyboard Events
  onKeyDown?: ReactEvent.Keyboard.t => unit,
  onKeyPress?: ReactEvent.Keyboard.t => unit,
  onKeyUp?: ReactEvent.Keyboard.t => unit,

  // Mouse Events
  onContextMenu?: ReactEvent.Mouse.t => unit,
  onDrag?: ReactEvent.Mouse.t => unit,
  onDragEnd?: ReactEvent.Mouse.t => unit,
  onDragEnter?: ReactEvent.Mouse.t => unit,
  onDragExit?: ReactEvent.Mouse.t => unit,
  onDragLeave?: ReactEvent.Mouse.t => unit,
  onDragOver?: ReactEvent.Mouse.t => unit,
  onDragStart?: ReactEvent.Mouse.t => unit,
  onDrop?: ReactEvent.Mouse.t => unit,
  onMouseDown?: ReactEvent.Mouse.t => unit,
  onMouseEnter?: ReactEvent.Mouse.t => unit,
  onMouseLeave?: ReactEvent.Mouse.t => unit,
  onMouseUp?: ReactEvent.Mouse.t => unit,

  // Touch Events
  onTouchCancel?: ReactEvent.Touch.t => unit,
  onTouchCancelCapture?: ReactEvent.Touch.t => unit,
  onTouchEnd?: ReactEvent.Touch.t => unit,
  onTouchEndCapture?: ReactEvent.Touch.t => unit,
  onTouchMove?: ReactEvent.Touch.t => unit,
  onTouchMoveCapture?: ReactEvent.Touch.t => unit,
  onTouchStart?: ReactEvent.Touch.t => unit,
  onTouchStartCapture?: ReactEvent.Touch.t => unit,

  // Pointer Events
  onGotPointerCapture?: ReactEvent.Pointer.t => unit,
  onGotPointerCaptureCapture?: ReactEvent.Pointer.t => unit,
  onLostPointerCapture?: ReactEvent.Pointer.t => unit,
  onLostPointerCaptureCapture?: ReactEvent.Pointer.t => unit,
  onPointerCancel?: ReactEvent.Pointer.t => unit,
  onPointerCancelCapture?: ReactEvent.Pointer.t => unit,
  onPointerDown?: ReactEvent.Pointer.t => unit,
  onPointerDownCapture?: ReactEvent.Pointer.t => unit,
  onPointerEnter?: ReactEvent.Pointer.t => unit,
  onPointerEnterCapture?: ReactEvent.Pointer.t => unit,
  onPointerLeave?: ReactEvent.Pointer.t => unit,
  onPointerLeaveCapture?: ReactEvent.Pointer.t => unit,
  onPointerMove?: ReactEvent.Pointer.t => unit,
  onPointerMoveCapture?: ReactEvent.Pointer.t => unit,
  onPointerOut?: ReactEvent.Pointer.t => unit,
  onPointerOutCapture?: ReactEvent.Pointer.t => unit,
  onPointerOver?: ReactEvent.Pointer.t => unit,
  onPointerOverCapture?: ReactEvent.Pointer.t => unit,
  onPointerUp?: ReactEvent.Pointer.t => unit,
  onPointerUpCapture?: ReactEvent.Pointer.t => unit,
}

type clickablePropsWithOnClick = {
  ...clickableProps,
  onClick?: ReactEvent.Mouse.t => unit,
  onDoubleClick?: ReactEvent.Mouse.t => unit,
}
