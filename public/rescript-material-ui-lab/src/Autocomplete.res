type blurOnSelect_enum = [#mouse | #touch]

module BlurOnSelect = {
  type t
  external enum: blurOnSelect_enum => t = "%identity"
  external bool: bool => t = "%identity"
}

module Classes = {
  type t = {
    "root": option<string>,
    "fullWidth": option<string>,
    "focused": option<string>,
    "tag": option<string>,
    "tagSizeSmall": option<string>,
    "hasPopupIcon": option<string>,
    "hasClearIcon": option<string>,
    "inputRoot": option<string>,
    "input": option<string>,
    "inputFocused": option<string>,
    "endAdornment": option<string>,
    "clearIndicator": option<string>,
    "clearIndicatorDirty": option<string>,
    "popupIndicator": option<string>,
    "popupIndicatorOpen": option<string>,
    "popper": option<string>,
    "popperDisablePortal": option<string>,
    "paper": option<string>,
    "listbox": option<string>,
    "loading": option<string>,
    "noOptions": option<string>,
    "option": option<string>,
    "groupLabel": option<string>,
    "groupUl": option<string>,
  }
  @obj
  external make: (
    ~root: string=?,
    ~fullWidth: string=?,
    ~focused: string=?,
    ~tag: string=?,
    ~tagSizeSmall: string=?,
    ~hasPopupIcon: string=?,
    ~hasClearIcon: string=?,
    ~inputRoot: string=?,
    ~input: string=?,
    ~inputFocused: string=?,
    ~endAdornment: string=?,
    ~clearIndicator: string=?,
    ~clearIndicatorDirty: string=?,
    ~popupIndicator: string=?,
    ~popupIndicatorOpen: string=?,
    ~popper: string=?,
    ~popperDisablePortal: string=?,
    ~paper: string=?,
    ~listbox: string=?,
    ~loading: string=?,
    ~noOptions: string=?,
    ~option: string=?,
    ~groupLabel: string=?,
    ~groupUl: string=?,
    unit,
  ) => t = ""
}

type forcePopupIcon_enum = [#auto]

module ForcePopupIcon = {
  type t
  external enum: forcePopupIcon_enum => t = "%identity"
  external bool: bool => t = "%identity"
}

module ListboxComponent = {
  type t
  external string: string => t = "%identity"
  external listboxComponent_func: MaterialUi.Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

module Value = {
  type t
  external arrayOf: array<MaterialUi.Types.any> => t = "%identity"
}

module PaperComponent = {
  type t
  external string: string => t = "%identity"
  external paperComponent_func: MaterialUi.Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

module PopperComponent = {
  type t
  external string: string => t = "%identity"
  external popperComponent_func: MaterialUi.Types.any => t = "%identity"
  external element: React.element => t = "%identity"
}

type size = [#medium | #small]

@react.component @module("@material-ui/lab")
external make: (
  ~autoComplete: bool=?,
  ~autoHighlight: bool=?,
  ~autoSelect: bool=?,
  ~blurOnSelect: BlurOnSelect.t=?,
  ~\"ChipProps": {..}=?,
  ~classes: Classes.t=?,
  ~className: string=?,
  ~clearOnBlur: bool=?,
  ~clearOnEscape: bool=?,
  ~clearText: string=?,
  ~closeIcon: React.element=?,
  ~closeText: string=?,
  ~debug: bool=?,
  ~defaultValue: MaterialUi.Types.any=?,
  ~disableClearable: bool=?,
  ~disableCloseOnSelect: bool=?,
  ~disabled: bool=?,
  ~disabledItemsFocusable: bool=?,
  ~disableListWrap: bool=?,
  ~disablePortal: bool=?,
  ~filterOptions: MaterialUi.Types.any=?,
  ~filterSelectedOptions: bool=?,
  ~forcePopupIcon: ForcePopupIcon.t=?,
  ~freeSolo: bool=?,
  ~fullWidth: bool=?,
  ~getLimitTagsText: int => React.element=?,
  ~getOptionDisabled: 't => bool=?,
  ~getOptionLabel: 't => string=?,
  ~getOptionSelected: ('t, 't) => string=?,
  ~groupBy: 't => string=?,
  ~handleHomeEndKeys: bool=?,
  ~id: string=?,
  ~includeInputInList: bool=?,
  ~inputValue: string=?,
  ~limitTags: MaterialUi.Number.t=?,
  ~\"ListboxComponent": ListboxComponent.t=?,
  ~\"ListboxProps": {..}=?,
  ~loading: bool=?,
  ~loadingText: React.element=?,
  ~multiple: bool=?,
  ~noOptionsText: React.element=?,
  ~onChange: (ReactEvent.Form.t, Value.t, string) => unit=?,
  ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
  ~onHighlightChange: ({..}, 't, string) => unit=?,
  ~onInputChange: ({..}, string, string) => unit=?,
  ~onOpen: ReactEvent.Synthetic.t => unit=?,
  ~\"open": bool=?,
  ~openOnFocus: bool=?,
  ~openText: string=?,
  ~options: array<MaterialUi.Types.any>,
  ~\"PaperComponent": PaperComponent.t=?,
  ~\"PopperComponent": PopperComponent.t=?,
  ~popupIcon: React.element=?,
  ~renderGroup: MaterialUi.Types.any => React.element=?,
  ~renderInput: {..} => React.element,
  ~renderOption: ('t, {..}) => React.element=?,
  ~renderTags: (array<'t>, {"index": int} => unit) => React.element=?,
  ~selectOnFocus: bool=?,
  ~size: size=?,
  ~value: MaterialUi.Types.any=?,
  ~style: ReactDOM.Style.t=?,
  ~key: string=?,
  ~ref: ReactDOM.domRef=?,
) => React.element = "Autocomplete"
