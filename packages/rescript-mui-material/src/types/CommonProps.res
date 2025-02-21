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
  /**
    * The ARIA role attribute of the element.
    */
  role?: string,
}

type autoCapitalize =
  | @as("none") None
  | @as("sentences") Sentences
  | @as("words") Words
  | @as("characters") Characters

type autoCorrect = | @as("on") On | @as("off") Off
type dir = | @as("ltr") Ltr | @as("rtl") Rtl | @as("auto") Auto
type contentEditable = | @as(true) True | @as(false) False | @as("inherit") Inherit

/**
https://developer.mozilla.org/en-US/docs/Web/HTML/Global_attributes/enterkeyhint
 */
type enterKeyHint =
  | @as("enter") Enter
  | @as("done") Done
  | @as("go") Go
  | @as("next") Next
  | @as("previous") Previous
  | @as("search") Search
  | @as("send") Send

/**
https://developer.mozilla.org/en-US/docs/Web/HTML/Global_attributes/inputmode
 */
type inputMode =
  | @as("none") None
  | @as("text") Text
  | @as("decimal") Decimal
  | @as("numeric") Numeric
  | @as("tel") Tel
  | @as("search") Search
  | @as("email") Email
  | @as("url") Url

type globalAttributes = {
  autoCorrect?: autoCorrect,
  /**
    * If `true`, the element is focused during the first mount.
    */
  autoFocus?: bool,
  className?: string,
  contentEditable?: contentEditable,
  contextMenu?: string,
  @as("data-testid") dataTestId?: string,
  dir?: dir,
  draggable?: bool,
  enterKeyHint?: enterKeyHint,
  hidden?: bool,
  inert?: bool,
  lang?: string,
  nonce?: string,
  slot?: string,
  spellCheck?: bool,
  /**
   * @default 0
   */
  tabIndex?: int,
  // title is defined & overwritten elsewhere
  style?: ReactDOM.Style.t,
}

/**
 https://developer.mozilla.org/en-US/docs/Web/HTML/Element/textarea#wrap
 */
type wrap =
  | @as("hard") Hard
  | @as("soft") Soft
  | @as("off") Off

type inputTextareaProps = {
  /**
    * This prop helps users to fill forms faster, especially on mobile devices.
    * The name can be confusing, as it's more like an autofill.
    * You can learn more about it [following the specification](https://html.spec.whatwg.org/multipage/form-control-infrastructure.html#autofill).
    */
  autoComplete?: string,
  autoCapitalize?: autoCapitalize,
  // https://developer.mozilla.org/en-US/docs/Web/HTML/Element/input#attr-inputmode
  inputMode?: inputMode,
  /**
    * Type of the `input` element. It should be [a valid HTML5 input type](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/input#Form_%3Cinput%3E_types).
    */
  @as("type")
  type_?: string,
  /**
    * The maximum value the user can enter in the input. See [MDN](https://developer.mozilla.org/en-US/docs/Web/HTML/Attributes/max) for more details.
    */
  max?: int,
  /**
    * The maximum # of characters the user must enter in the input. See [MDN](https://developer.mozilla.org/en-US/docs/Web/HTML/Attributes/maxlength) for more details.
    */
  maxLength?: int,
  /**
    * The minimum value the user can enter in the input. See [MDN](https://developer.mozilla.org/en-US/docs/Web/HTML/Attributes/min) for more details.
    */
  min?: int,
  /**
    * The minimum # of characters the user must enter in the input. See [MDN](https://developer.mozilla.org/en-US/docs/Web/HTML/Attributes/minlength) for more details.
    */
  minLength?: int,
  name?: string,
  /**
    * The step interval for the input. See [MDN](https://developer.mozilla.org/en-US/docs/Web/HTML/Attributes/step) for more details.
    */
  step?: int,
  /**
    * A regular expression that the value of the input must match. See [MDN](https://developer.mozilla.org/en-US/docs/Web/HTML/Attributes/pattern) for more details.
    */
  pattern?: string,
  /**
    * Defines the text displayed in the input when it is empty. See [MDN](https://developer.mozilla.org/en-US/docs/Web/HTML/Attributes/placeholder) for more details.
    */
  placeholder?: string,
  /**
    * Makes the input read-only. See [MDN](https://developer.mozilla.org/en-US/docs/Web/HTML/Attributes/readonly) for more details.
    */
  readOnly?: bool,
  required?: bool,
  wrap?: wrap,
}

type t_NoId = {
  // Cannot spread whole dom props since overwriting is not possible.
  ...ariaProps,
  ...globalAttributes,
  ref?: ReactDOM.domRef,
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

type eventHandlerProps = {
  // Form Events
  // onChange's signature is overridden by some of MUI's components so is omitted here.
  onBeforeInput?: ReactEvent.Form.t => unit,
  onInput?: ReactEvent.Form.t => unit,
  onReset?: ReactEvent.Form.t => unit,
  onSubmit?: ReactEvent.Form.t => unit,
  onInvalid?: ReactEvent.Form.t => unit,

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
  ...eventHandlerProps,
  onClick?: ReactEvent.Mouse.t => unit,
  onDoubleClick?: ReactEvent.Mouse.t => unit,
}
