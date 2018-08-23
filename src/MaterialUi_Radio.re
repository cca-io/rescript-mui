
            

                [@bs.deriving jsConverter]
                type color = [
                    | [@bs.as "primary"] `Primary
| [@bs.as "secondary"] `Secondary
| [@bs.as "default"] `Default
                ];

                module Classes = {
                    type classesType = | Root(string)
| Checked(string)
| Disabled(string)
| ColorPrimary(string)
| ColorSecondary(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| Checked(_) => "checked"
| Disabled(_) => "disabled"
| ColorPrimary(_) => "colorPrimary"
| ColorSecondary(_) => "colorSecondary";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| Checked(className)
| Disabled(className)
| ColorPrimary(className)
| ColorSecondary(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~checked: 'union_rcsm=?,
~checkedIcon: ReasonReact.reactElement=?,
~color: string=?,
~disabled: bool=?,
~disableRipple: bool=?,
~icon: ReasonReact.reactElement=?,
~id: string=?,
~inputProps: Js.t({..})=?,
~inputRef: 'union_rvlu=?,
~onChange: 'any_rfa1=?,
~_type: string=?,
~value: string=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/Radio/Radio"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~checked: option([ | `Bool(bool) | `String(string)  ])=?,
~checkedIcon: option(ReasonReact.reactElement)=?,
~color: option(color)=?,
~disabled: option(bool)=?,
~disableRipple: option(bool)=?,
~icon: option(ReasonReact.reactElement)=?,
~id: option(string)=?,
~inputProps: option(Js.t({..}))=?,
~inputRef: option([ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
~type_: option(string)=?,
~value: option(string)=?,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~checked=?checked |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~checkedIcon=?checkedIcon,
~color=?color |. Belt.Option.map((v => colorToJs(v))),
~disabled=?disabled,
~disableRipple=?disableRipple,
~icon=?icon,
~id=?id,
~inputProps=?inputProps,
~inputRef=?inputRef |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~onChange=?onChange,
~_type=?type_,
~value=?value,
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        