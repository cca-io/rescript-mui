
            

                [@bs.deriving jsConverter]
                type margin = [
                    | [@bs.as "dense"] `Dense
| [@bs.as "none"] `None
                ];

                module Classes = {
                    type classesType = | Root(string)
| Select(string)
| SelectMenu(string)
| Disabled(string)
| Icon(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| Select(_) => "select"
| SelectMenu(_) => "selectMenu"
| Disabled(_) => "disabled"
| Icon(_) => "icon";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| Select(className)
| SelectMenu(className)
| Disabled(className)
| Icon(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~autoWidth: bool=?,
~displayEmpty: bool=?,
~_IconComponent: 'union_rygo=?,
~input: ReasonReact.reactElement=?,
~inputProps: Js.t({..})=?,
~_MenuProps: Js.t({..})=?,
~multiple: bool=?,
~native: bool=?,
~onChange: 'any_rii7=?,
~onClose: 'any_rbp6=?,
~onOpen: 'any_rn6p=?,
~_open: bool=?,
~renderValue: 'any_r646=?,
~_SelectDisplayProps: Js.t({..})=?,
~value: 'union_rap7=?,
~autoComplete: string=?,
~autoFocus: bool=?,
~className: string=?,
~defaultValue: 'union_rwtp=?,
~disabled: bool=?,
~disableUnderline: bool=?,
~endAdornment: ReasonReact.reactElement=?,
~error: bool=?,
~fullWidth: bool=?,
~id: string=?,
~inputComponent: 'any_rzcb=?,
~inputRef: 'union_r6jz=?,
~margin: string=?,
~multiline: bool=?,
~name: string=?,
~onBlur: ReactEvent.Focus.t => unit=?,
~onEmpty: 'genericCallback=?,
~onFilled: 'genericCallback=?,
~onFocus: ReactEvent.Focus.t => unit=?,
~onKeyDown: ReactEvent.Keyboard.t => unit=?,
~onKeyUp: ReactEvent.Keyboard.t => unit=?,
~placeholder: string=?,
~readOnly: bool=?,
~rows: 'union_rien=?,
~rowsMax: 'union_r9xp=?,
~startAdornment: ReasonReact.reactElement=?,
~_type: string=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/Select/Select"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~autoWidth: option(bool)=?,
~displayEmpty: option(bool)=?,
~_IconComponent: option([ | `String(string) | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~input: option(ReasonReact.reactElement)=?,
~inputProps: option(Js.t({..}))=?,
~_MenuProps: option(Js.t({..}))=?,
~multiple: option(bool)=?,
~native: option(bool)=?,
~onChange: option((ReactEvent.Form.t, Js.t({..})) => unit)=?,
~onClose: option((ReactEvent.Synthetic.t) => unit)=?,
~onOpen: option((ReactEvent.Synthetic.t) => unit)=?,
~open_: option(bool)=?,
~renderValue: option(('any_ruhi) => ReasonReact.reactElement)=?,
~_SelectDisplayProps: option(Js.t({..}))=?,
~value: option([ | `String(string) | `Int(int) | `Float(float) | `Array(array([ | `String(string) | `Int(int) | `Float(float)  ]))  ])=?,
~autoComplete: option(string)=?,
~autoFocus: option(bool)=?,
~className: option(string)=?,
~defaultValue: option([ | `String(string) | `Int(int) | `Float(float)  ])=?,
~disabled: option(bool)=?,
~disableUnderline: option(bool)=?,
~endAdornment: option(ReasonReact.reactElement)=?,
~error: option(bool)=?,
~fullWidth: option(bool)=?,
~id: option(string)=?,
~inputComponent: option('any_rzcb)=?,
~inputRef: option([ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~margin: option(margin)=?,
~multiline: option(bool)=?,
~name: option(string)=?,
~onBlur: option(ReactEvent.Focus.t => unit)=?,
~onEmpty: option('genericCallback)=?,
~onFilled: option('genericCallback)=?,
~onFocus: option(ReactEvent.Focus.t => unit)=?,
~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
~placeholder: option(string)=?,
~readOnly: option(bool)=?,
~rows: option([ | `String(string) | `Int(int) | `Float(float)  ])=?,
~rowsMax: option([ | `String(string) | `Int(int) | `Float(float)  ])=?,
~startAdornment: option(ReasonReact.reactElement)=?,
~type_: option(string)=?,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~autoWidth=?autoWidth,
~displayEmpty=?displayEmpty,
~_IconComponent=?_IconComponent |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~input=?input,
~inputProps=?inputProps,
~_MenuProps=?_MenuProps,
~multiple=?multiple,
~native=?native,
~onChange=?onChange,
~onClose=?onClose,
~onOpen=?onOpen,
~_open=?open_,
~renderValue=?renderValue,
~_SelectDisplayProps=?_SelectDisplayProps,
~value=?value |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~autoComplete=?autoComplete,
~autoFocus=?autoFocus,
~className=?className,
~defaultValue=?defaultValue |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~disabled=?disabled,
~disableUnderline=?disableUnderline,
~endAdornment=?endAdornment,
~error=?error,
~fullWidth=?fullWidth,
~id=?id,
~inputComponent=?inputComponent,
~inputRef=?inputRef |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~margin=?margin |. Belt.Option.map((v => marginToJs(v))),
~multiline=?multiline,
~name=?name,
~onBlur=?onBlur,
~onEmpty=?onEmpty,
~onFilled=?onFilled,
~onFocus=?onFocus,
~onKeyDown=?onKeyDown,
~onKeyUp=?onKeyUp,
~placeholder=?placeholder,
~readOnly=?readOnly,
~rows=?rows |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~rowsMax=?rowsMax |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~startAdornment=?startAdornment,
~_type=?type_,
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        