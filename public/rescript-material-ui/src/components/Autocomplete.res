type blurOnSelect_enum = [#mouse | #touch]

module BlurOnSelect = {
  type t
  external enum: blurOnSelect_enum => t = "%identity"
  external bool: bool => t = "%identity"
}

module ComponentsProps = {
  type t = {
    "clearIndicator": option<Any.t>,
    "paper": option<Any.t>,
    "popper": option<Any.t>,
    "popupIndicator": option<Any.t>,
  }
  @obj
  external make: (
    ~clearIndicator: Any.t=?,
    ~paper: Any.t=?,
    ~popper: Any.t=?,
    ~popupIndicator: Any.t=?,
    unit,
  ) => t = ""
}

type forcePopupIcon_enum = [#auto]

module ForcePopupIcon = {
  type t
  external enum: forcePopupIcon_enum => t = "%identity"
  external bool: bool => t = "%identity"
}

module Value = {
  type t
  external arrayOf: array<Any.t> => t = "%identity"
}

type size_enum = [#small | #medium]

module Size = {
  type t
  external enum: size_enum => t = "%identity"
  external string: string => t = "%identity"
}

module SlotProps = {
  type t = {
    "clearIndicator": option<Any.t>,
    "paper": option<Any.t>,
    "popper": option<Any.t>,
    "popupIndicator": option<Any.t>,
  }
  @obj
  external make: (
    ~clearIndicator: Any.t=?,
    ~paper: Any.t=?,
    ~popper: Any.t=?,
    ~popupIndicator: Any.t=?,
    unit,
  ) => t = ""
}

module Sx_arrayOf = {
  type t
  external sx_arrayOf_func: Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
  external bool: bool => t = "%identity"
}

module Sx = {
  type t
  external arrayOf: array<Sx_arrayOf.t> => t = "%identity"
  external sx_func: Any.t => t = "%identity"
  external obj: {..} => t = "%identity"
}

@react.component @module("@mui/material")
external make: (
  ~autoComplete: bool=?,
  ~autoHighlight: bool=?,
  ~autoSelect: bool=?,
  ~blurOnSelect: BlurOnSelect.t=?,
  ~\"ChipProps": {..}=?,
  ~className: string=?,
  ~clearIcon: React.element=?,
  ~clearOnBlur: bool=?,
  ~clearOnEscape: bool=?,
  ~clearText: string=?,
  ~closeText: string=?,
  ~componentsProps: ComponentsProps.t=?,
  ~disableClearable: bool=?,
  ~disableCloseOnSelect: bool=?,
  ~disabled: bool=?,
  ~disabledItemsFocusable: bool=?,
  ~disableListWrap: bool=?,
  ~disablePortal: bool=?,
  ~filterOptions: Any.t=?,
  ~filterSelectedOptions: bool=?,
  ~forcePopupIcon: ForcePopupIcon.t=?,
  ~freeSolo: bool=?,
  ~fullWidth: bool=?,
  ~getLimitTagsText: int => React.element=?,
  ~getOptionDisabled: 't => bool=?,
  ~getOptionLabel: 't => string=?,
  ~groupBy: 't => string=?,
  ~handleHomeEndKeys: bool=?,
  ~id: string=?,
  ~includeInputInList: bool=?,
  ~inputValue: string=?,
  ~isOptionEqualToValue: ('t, 't) => bool=?,
  ~\"ListboxComponent": React.element=?,
  ~\"ListboxProps": {..}=?,
  ~loading: bool=?,
  ~loadingText: React.element=?,
  ~multiple: bool=?,
  ~noOptionsText: React.element=?,
  ~onChange: (ReactEvent.Form.t, Value.t, string, string) => unit=?,
  ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
  ~onHighlightChange: ({..}, 't, string) => unit=?,
  ~onInputChange: ({..}, string, string) => unit=?,
  ~onOpen: ReactEvent.Synthetic.t => unit=?,
  ~\"open": bool=?,
  ~openOnFocus: bool=?,
  ~openText: string=?,
  ~options: array<Any.t>,
  ~\"PaperComponent": React.element=?,
  ~\"PopperComponent": React.element=?,
  ~popupIcon: React.element=?,
  ~readOnly: bool=?,
  ~renderGroup: {..} => React.element=?,
  ~renderInput: {..} => React.element,
  ~renderOption: ('t, {..}) => React.element=?,
  ~renderTags: (array<'t>, {"index": int} => unit) => React.element=?,
  ~selectOnFocus: bool=?,
  ~size: Size.t=?,
  ~slotProps: SlotProps.t=?,
  ~sx: Sx.t=?,
  ~value: Any.t=?,
  ~style: ReactDOM.Style.t=?,
  ~getOptionSelected: ('t, 't) => string=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Autocomplete"
