[@bs.deriving jsConverter]
type blurOnSelect_enum = [
  | [@bs.as "mouse"] `Mouse
  | [@bs.as "touch"] `Touch
];

[@bs.deriving jsConverter]
type forcePopupIcon_enum = [ | [@bs.as "auto"] `Auto];

[@bs.deriving jsConverter]
type size = [ | [@bs.as "medium"] `Medium | [@bs.as "small"] `Small];

module Classes = {
  type classesType =
    | Root(string)
    | FullWidth(string)
    | Focused(string)
    | Tag(string)
    | TagSizeSmall(string)
    | HasPopupIcon(string)
    | HasClearIcon(string)
    | InputRoot(string)
    | Input(string)
    | InputFocused(string)
    | EndAdornment(string)
    | ClearIndicator(string)
    | ClearIndicatorDirty(string)
    | PopupIndicator(string)
    | PopupIndicatorOpen(string)
    | Popper(string)
    | PopperDisablePortal(string)
    | Paper(string)
    | Listbox(string)
    | Loading(string)
    | NoOptions(string)
    | Option(string)
    | GroupLabel(string)
    | GroupUl(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | FullWidth(_) => "fullWidth"
    | Focused(_) => "focused"
    | Tag(_) => "tag"
    | TagSizeSmall(_) => "tagSizeSmall"
    | HasPopupIcon(_) => "hasPopupIcon"
    | HasClearIcon(_) => "hasClearIcon"
    | InputRoot(_) => "inputRoot"
    | Input(_) => "input"
    | InputFocused(_) => "inputFocused"
    | EndAdornment(_) => "endAdornment"
    | ClearIndicator(_) => "clearIndicator"
    | ClearIndicatorDirty(_) => "clearIndicatorDirty"
    | PopupIndicator(_) => "popupIndicator"
    | PopupIndicatorOpen(_) => "popupIndicatorOpen"
    | Popper(_) => "popper"
    | PopperDisablePortal(_) => "popperDisablePortal"
    | Paper(_) => "paper"
    | Listbox(_) => "listbox"
    | Loading(_) => "loading"
    | NoOptions(_) => "noOptions"
    | Option(_) => "option"
    | GroupLabel(_) => "groupLabel"
    | GroupUl(_) => "groupUl";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | FullWidth(className)
                         | Focused(className)
                         | Tag(className)
                         | TagSizeSmall(className)
                         | HasPopupIcon(className)
                         | HasClearIcon(className)
                         | InputRoot(className)
                         | Input(className)
                         | InputFocused(className)
                         | EndAdornment(className)
                         | ClearIndicator(className)
                         | ClearIndicatorDirty(className)
                         | PopupIndicator(className)
                         | PopupIndicatorOpen(className)
                         | Popper(className)
                         | PopperDisablePortal(className)
                         | Paper(className)
                         | Listbox(className)
                         | Loading(className)
                         | NoOptions(className)
                         | Option(className)
                         | GroupLabel(className)
                         | GroupUl(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~autoComplete: bool=?,
    ~autoHighlight: bool=?,
    ~autoSelect: bool=?,
    ~blurOnSelect: 'union_ri7b=?,
    ~_ChipProps: Js.t({..})=?,
    ~className: string=?,
    ~clearOnEscape: bool=?,
    ~clearText: string=?,
    ~closeIcon: React.element=?,
    ~closeText: string=?,
    ~debug: bool=?,
    ~defaultValue: 'union_ruqy=?,
    ~disableClearable: bool=?,
    ~disableCloseOnSelect: bool=?,
    ~disabled: bool=?,
    ~disabledItemsFocusable: bool=?,
    ~disableListWrap: bool=?,
    ~disablePortal: bool=?,
    ~filterOptions: 'genericCallback=?,
    ~filterSelectedOptions: bool=?,
    ~forcePopupIcon: 'union_rd47=?,
    ~freeSolo: bool=?,
    ~fullWidth: bool=?,
    ~getLimitTagsText: 'any_rd6j=?,
    ~getOptionDisabled: 'genericCallback=?,
    ~getOptionLabel: 'genericCallback=?,
    ~getOptionSelected: 'genericCallback=?,
    ~groupBy: 'any_rafe=?,
    ~id: string=?,
    ~includeInputInList: bool=?,
    ~inputValue: string=?,
    ~limitTags: 'number_j=?,
    ~_ListboxComponent: 'union_ru7o=?,
    ~_ListboxProps: Js.t({..})=?,
    ~loading: bool=?,
    ~loadingText: React.element=?,
    ~multiple: bool=?,
    ~noOptionsText: React.element=?,
    ~onChange: 'any_rbg6=?,
    ~onClose: 'any_r02v=?,
    ~onInputChange: 'any_rkbk=?,
    ~onOpen: 'any_r4ca=?,
    ~_open: bool=?,
    ~openOnFocus: bool=?,
    ~openText: string=?,
    ~options: array('any_r4td),
    ~_PaperComponent: 'union_rcft=?,
    ~_PopperComponent: 'union_rgmv=?,
    ~popupIcon: React.element=?,
    ~renderGroup: 'any_rcq1=?,
    ~renderInput: 'any_rs4f,
    ~renderOption: 'any_rusm=?,
    ~renderTags: 'any_r2k5=?,
    ~selectOnFocus: bool=?,
    ~size: string=?,
    ~value: 'union_r9o6=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~autoComplete: option(bool)=?,
      ~autoHighlight: option(bool)=?,
      ~autoSelect: option(bool)=?,
      ~blurOnSelect: option([ | `Enum(blurOnSelect_enum) | `Bool(bool)])=?,
      ~_ChipProps: option(Js.t({..}))=?,
      ~className: option(string)=?,
      ~clearOnEscape: option(bool)=?,
      ~clearText: option(string)=?,
      ~closeIcon: option(React.element)=?,
      ~closeText: option(string)=?,
      ~debug: option(bool)=?,
      ~defaultValue: option([ | `Any('any_r0n6) | `Array('any_r2y2)])=?,
      ~disableClearable: option(bool)=?,
      ~disableCloseOnSelect: option(bool)=?,
      ~disabled: option(bool)=?,
      ~disabledItemsFocusable: option(bool)=?,
      ~disableListWrap: option(bool)=?,
      ~disablePortal: option(bool)=?,
      ~filterOptions: option('genericCallback)=?,
      ~filterSelectedOptions: option(bool)=?,
      ~forcePopupIcon: option([ | `Enum(forcePopupIcon_enum) | `Bool(bool)])=?,
      ~freeSolo: option(bool)=?,
      ~fullWidth: option(bool)=?,
      ~getLimitTagsText: option(int => 'any_rixb)=?,
      ~getOptionDisabled: option('genericCallback)=?,
      ~getOptionLabel: option('genericCallback)=?,
      ~getOptionSelected: option('genericCallback)=?,
      ~groupBy: option(unit => string)=?,
      ~id: option(string)=?,
      ~includeInputInList: option(bool)=?,
      ~inputValue: option(string)=?,
      ~limitTags: option([ | `Int(int) | `Float(float)])=?,
      ~_ListboxComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~_ListboxProps: option(Js.t({..}))=?,
      ~loading: option(bool)=?,
      ~loadingText: option(React.element)=?,
      ~multiple: option(bool)=?,
      ~noOptionsText: option(React.element)=?,
      ~onChange: option((ReactEvent.Form.t, string) => unit)=?,
      ~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
      ~onInputChange: option((Js.t({..}), string, string) => unit)=?,
      ~onOpen: option(ReactEvent.Synthetic.t => unit)=?,
      ~open_: option(bool)=?,
      ~openOnFocus: option(bool)=?,
      ~openText: option(string)=?,
      ~options: array('any_r4td),
      ~_PaperComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~_PopperComponent:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `Element(React.element)
           ],
         )=?,
      ~popupIcon: option(React.element)=?,
      ~renderGroup: option('any_rjq2 => 'any_rmrq)=?,
      ~renderInput: Js.t({..}) => 'any_rhld,
      ~renderOption: option(Js.t({..}) => 'any_rq21)=?,
      ~renderTags: option(unit => 'any_rowg)=?,
      ~selectOnFocus: option(bool)=?,
      ~size: option(size)=?,
      ~value: option([ | `Any('any_re9g) | `Array('any_rj0p)])=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~autoComplete?,
    ~autoHighlight?,
    ~autoSelect?,
    ~blurOnSelect=?
      blurOnSelect->(
                      Belt.Option.map(v =>
                        switch (v) {
                        | `Enum(v) =>
                          MaterialUi_Helpers.unwrapValue(
                            `String(blurOnSelect_enumToJs(v)),
                          )

                        | v => MaterialUi_Helpers.unwrapValue(v)
                        }
                      )
                    ),
    ~_ChipProps?,
    ~className?,
    ~clearOnEscape?,
    ~clearText?,
    ~closeIcon?,
    ~closeText?,
    ~debug?,
    ~defaultValue=?
      defaultValue->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disableClearable?,
    ~disableCloseOnSelect?,
    ~disabled?,
    ~disabledItemsFocusable?,
    ~disableListWrap?,
    ~disablePortal?,
    ~filterOptions?,
    ~filterSelectedOptions?,
    ~forcePopupIcon=?
      forcePopupIcon->(
                        Belt.Option.map(v =>
                          switch (v) {
                          | `Enum(v) =>
                            MaterialUi_Helpers.unwrapValue(
                              `String(forcePopupIcon_enumToJs(v)),
                            )

                          | v => MaterialUi_Helpers.unwrapValue(v)
                          }
                        )
                      ),
    ~freeSolo?,
    ~fullWidth?,
    ~getLimitTagsText?,
    ~getOptionDisabled?,
    ~getOptionLabel?,
    ~getOptionSelected?,
    ~groupBy?,
    ~id?,
    ~includeInputInList?,
    ~inputValue?,
    ~limitTags=?
      limitTags->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~_ListboxComponent=?
      _ListboxComponent->(
                           Belt.Option.map(v =>
                             MaterialUi_Helpers.unwrapValue(v)
                           )
                         ),
    ~_ListboxProps?,
    ~loading?,
    ~loadingText?,
    ~multiple?,
    ~noOptionsText?,
    ~onChange?,
    ~onClose?,
    ~onInputChange?,
    ~onOpen?,
    ~_open=?open_,
    ~openOnFocus?,
    ~openText?,
    ~options,
    ~_PaperComponent=?
      _PaperComponent->(
                         Belt.Option.map(v =>
                           MaterialUi_Helpers.unwrapValue(v)
                         )
                       ),
    ~_PopperComponent=?
      _PopperComponent->(
                          Belt.Option.map(v =>
                            MaterialUi_Helpers.unwrapValue(v)
                          )
                        ),
    ~popupIcon?,
    ~renderGroup?,
    ~renderInput,
    ~renderOption?,
    ~renderTags?,
    ~selectOnFocus?,
    ~size=?size->Belt.Option.map(v => sizeToJs(v)),
    ~value=?value->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/lab"]
external make: React.component('a) = "Autocomplete";
