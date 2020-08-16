module BlurOnSelect_enum: {
  type t;
  let mouse: t;
  let touch: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let mouse = Any("mouse");
  let touch = Any("touch");
};

module BlurOnSelect: {
  type t;
  let enum: BlurOnSelect_enum.t => t;
  let bool: bool => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let enum = (v: BlurOnSelect_enum.t) => Any(v);
  let bool = (v: bool) => Any(v);
};

module Classes = {
  type t = {
    .
    "root": option(string),
    "fullWidth": option(string),
    "focused": option(string),
    "tag": option(string),
    "tagSizeSmall": option(string),
    "hasPopupIcon": option(string),
    "hasClearIcon": option(string),
    "inputRoot": option(string),
    "input": option(string),
    "inputFocused": option(string),
    "endAdornment": option(string),
    "clearIndicator": option(string),
    "clearIndicatorDirty": option(string),
    "popupIndicator": option(string),
    "popupIndicatorOpen": option(string),
    "popper": option(string),
    "popperDisablePortal": option(string),
    "paper": option(string),
    "listbox": option(string),
    "loading": option(string),
    "noOptions": option(string),
    "option": option(string),
    "groupLabel": option(string),
    "groupUl": option(string),
  };
  [@bs.obj]
  external make:
    (
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
      unit
    ) =>
    t;
};

module ForcePopupIcon_enum: {
  type t;
  let auto: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let auto = Any("auto");
};

module ForcePopupIcon: {
  type t;
  let enum: ForcePopupIcon_enum.t => t;
  let bool: bool => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let enum = (v: ForcePopupIcon_enum.t) => Any(v);
  let bool = (v: bool) => Any(v);
};

module ListboxComponent: {
  type t;
  let string: string => t;
  let listboxComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let listboxComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

module Value: {
  type t;
  let arrayOf: array(MaterialUi_Types.any) => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let arrayOf = (v: array(MaterialUi_Types.any)) => Any(v);
};

module PaperComponent: {
  type t;
  let string: string => t;
  let paperComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let paperComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

module PopperComponent: {
  type t;
  let string: string => t;
  let popperComponent_func: MaterialUi_Types.any => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let popperComponent_func = (v: MaterialUi_Types.any) => Any(v);
  let element = (v: React.element) => Any(v);
};

type size = [ | `Medium | `Small];

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~autoComplete: bool=?,
    ~autoHighlight: bool=?,
    ~autoSelect: bool=?,
    ~blurOnSelect: BlurOnSelect.t=?,
    ~_ChipProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~classes: Classes.t=?,
    ~className: string=?,
    ~clearOnBlur: bool=?,
    ~clearOnEscape: bool=?,
    ~clearText: string=?,
    ~closeIcon: React.element=?,
    ~closeText: string=?,
    ~debug: bool=?,
    ~defaultValue: MaterialUi_Types.any=?,
    ~disableClearable: bool=?,
    ~disableCloseOnSelect: bool=?,
    ~disabled: bool=?,
    ~disabledItemsFocusable: bool=?,
    ~disableListWrap: bool=?,
    ~disablePortal: bool=?,
    ~filterOptions: MaterialUi_Types.any=?,
    ~filterSelectedOptions: bool=?,
    ~forcePopupIcon: ForcePopupIcon.t=?,
    ~freeSolo: bool=?,
    ~fullWidth: bool=?,
    ~getLimitTagsText: int => MaterialUi_Types.any=?,
    ~getOptionDisabled: unit => bool=?,
    ~getOptionLabel: unit => string=?,
    ~getOptionSelected: unit => bool=?,
    ~groupBy: unit => string=?,
    ~handleHomeEndKeys: bool=?,
    ~id: string=?,
    ~includeInputInList: bool=?,
    ~inputValue: string=?,
    ~limitTags: MaterialUi_Types.Number.t=?,
    ~_ListboxComponent: ListboxComponent.t=?,
    ~_ListboxProps: Js.Dict.t(MaterialUi_Types.any)=?,
    ~loading: bool=?,
    ~loadingText: React.element=?,
    ~multiple: bool=?,
    ~noOptionsText: React.element=?,
    ~onChange: (ReactEvent.Form.t, Value.t, string) => unit=?,
    ~onClose: (ReactEvent.Synthetic.t, string) => unit=?,
    ~onHighlightChange: (Js.Dict.t(MaterialUi_Types.any), string) => unit=?,
    ~onInputChange: (Js.Dict.t(MaterialUi_Types.any), string, string) => unit
                      =?,
    ~onOpen: ReactEvent.Synthetic.t => unit=?,
    ~_open: bool=?,
    ~openOnFocus: bool=?,
    ~openText: string=?,
    ~options: array(MaterialUi_Types.any),
    ~_PaperComponent: PaperComponent.t=?,
    ~_PopperComponent: PopperComponent.t=?,
    ~popupIcon: React.element=?,
    ~renderGroup: MaterialUi_Types.any => MaterialUi_Types.any=?,
    ~renderInput: Js.Dict.t(MaterialUi_Types.any) => MaterialUi_Types.any,
    ~renderOption: Js.Dict.t(MaterialUi_Types.any) => MaterialUi_Types.any=?,
    ~renderTags: unit => MaterialUi_Types.any=?,
    ~selectOnFocus: bool=?,
    ~size: [@bs.string] [
             | [@bs.as "medium"] `Medium
             | [@bs.as "small"] `Small
           ]
             =?,
    ~value: MaterialUi_Types.any=?,
    ~style: ReactDOMRe.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Autocomplete";
