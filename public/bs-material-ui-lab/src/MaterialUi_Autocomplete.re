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
    "root": option(option(string)),
    "fullWidth": option(option(string)),
    "focused": option(option(string)),
    "tag": option(option(string)),
    "tagSizeSmall": option(option(string)),
    "hasPopupIcon": option(option(string)),
    "hasClearIcon": option(option(string)),
    "inputRoot": option(option(string)),
    "input": option(option(string)),
    "inputFocused": option(option(string)),
    "endAdornment": option(option(string)),
    "clearIndicator": option(option(string)),
    "clearIndicatorDirty": option(option(string)),
    "popupIndicator": option(option(string)),
    "popupIndicatorOpen": option(option(string)),
    "popper": option(option(string)),
    "popperDisablePortal": option(option(string)),
    "paper": option(option(string)),
    "listbox": option(option(string)),
    "loading": option(option(string)),
    "noOptions": option(option(string)),
    "option": option(option(string)),
    "groupLabel": option(option(string)),
    "groupUl": option(option(string)),
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

module DefaultValue: {
  type t;
  let any: MaterialUi_Types.any => t;
  let array: array(MaterialUi_Types.any) => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let any = (v: MaterialUi_Types.any) => Any(v);
  let array = (v: array(MaterialUi_Types.any)) => Any(v);
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

module Value: {
  type t;
  let any: MaterialUi_Types.any => t;
  let array: array(MaterialUi_Types.any) => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let any = (v: MaterialUi_Types.any) => Any(v);
  let array = (v: array(MaterialUi_Types.any)) => Any(v);
};

[@react.component] [@bs.module "@material-ui/lab"]
external make:
  (
    ~autoComplete: option(bool)=?,
    ~autoHighlight: option(bool)=?,
    ~autoSelect: option(bool)=?,
    ~blurOnSelect: option(BlurOnSelect.t)=?,
    ~_ChipProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~clearOnBlur: option(bool)=?,
    ~clearOnEscape: option(bool)=?,
    ~clearText: option(string)=?,
    ~closeIcon: option(React.element)=?,
    ~closeText: option(string)=?,
    ~debug: option(bool)=?,
    ~defaultValue: option(DefaultValue.t)=?,
    ~disableClearable: option(bool)=?,
    ~disableCloseOnSelect: option(bool)=?,
    ~disabled: option(bool)=?,
    ~disabledItemsFocusable: option(bool)=?,
    ~disableListWrap: option(bool)=?,
    ~disablePortal: option(bool)=?,
    ~filterOptions: option(MaterialUi_Types.any)=?,
    ~filterSelectedOptions: option(bool)=?,
    ~forcePopupIcon: option(ForcePopupIcon.t)=?,
    ~freeSolo: option(bool)=?,
    ~fullWidth: option(bool)=?,
    ~getLimitTagsText: option(int => MaterialUi_Types.any)=?,
    ~getOptionDisabled: option(unit => bool)=?,
    ~getOptionLabel: option(unit => string)=?,
    ~getOptionSelected: option(unit => bool)=?,
    ~groupBy: option(unit => string)=?,
    ~id: option(string)=?,
    ~includeInputInList: option(bool)=?,
    ~inputValue: option(string)=?,
    ~limitTags: option(MaterialUi_Types.Number.t)=?,
    ~_ListboxComponent: option(ListboxComponent.t)=?,
    ~_ListboxProps: option(Js.Dict.t(MaterialUi_Types.any))=?,
    ~loading: option(bool)=?,
    ~loadingText: option(React.element)=?,
    ~multiple: option(bool)=?,
    ~noOptionsText: option(React.element)=?,
    ~onChange: option((ReactEvent.Form.t, string) => unit)=?,
    ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
    ~onHighlightChange: option(
                          (Js.Dict.t(MaterialUi_Types.any), string) => unit,
                        )
                          =?,
    ~onInputChange: option(
                      (Js.Dict.t(MaterialUi_Types.any), string, string) =>
                      unit,
                    )
                      =?,
    ~onOpen: option(ReactEvent.Synthetic.t => unit)=?,
    ~_open: option(bool)=?,
    ~openOnFocus: option(bool)=?,
    ~openText: option(string)=?,
    ~options: array(MaterialUi_Types.any),
    ~_PaperComponent: option(PaperComponent.t)=?,
    ~_PopperComponent: option(PopperComponent.t)=?,
    ~popupIcon: option(React.element)=?,
    ~renderGroup: option(MaterialUi_Types.any => MaterialUi_Types.any)=?,
    ~renderInput: Js.Dict.t(MaterialUi_Types.any) => MaterialUi_Types.any,
    ~renderOption: option(
                     Js.Dict.t(MaterialUi_Types.any) => MaterialUi_Types.any,
                   )
                     =?,
    ~renderTags: option(unit => MaterialUi_Types.any)=?,
    ~selectOnFocus: option(bool)=?,
    ~size: option(
             [@bs.string] [
               | [@bs.as "medium"] `Medium
               | [@bs.as "small"] `Small
             ],
           )
             =?,
    ~value: option(Value.t)=?,
    ~style: option(ReactDOMRe.Style.t)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Autocomplete";
