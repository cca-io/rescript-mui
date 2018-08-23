
            

                module Classes = {
                    type classesType = | Root(string)
| Disabled(string)
| Label(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| Disabled(_) => "disabled"
| Label(_) => "label";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| Disabled(className)
| Label(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~checked: 'union_r6zy=?,
~className: string=?,
~control: ReasonReact.reactElement=?,
~disabled: bool=?,
~inputRef: 'union_r6k1=?,
~label: ReasonReact.reactElement=?,
~name: string=?,
~onChange: 'any_ruq7=?,
~value: string=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/FormControlLabel/FormControlLabel"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~checked: option([ | `Bool(bool) | `String(string)  ])=?,
~className: option(string)=?,
~control: option(ReasonReact.reactElement)=?,
~disabled: option(bool)=?,
~inputRef: option([ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~label: option(ReasonReact.reactElement)=?,
~name: option(string)=?,
~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
~value: option(string)=?,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~checked=?checked |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~className=?className,
~control=?control,
~disabled=?disabled,
~inputRef=?inputRef |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~label=?label,
~name=?name,
~onChange=?onChange,
~value=?value,
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        