
            

                [@bs.deriving jsConverter]
                type color = [
                    | [@bs.as "default"] `Default
| [@bs.as "primary"] `Primary
| [@bs.as "inherit"] `Inherit
                ];

                module Classes = {
                    type classesType = | Root(string)
| ColorPrimary(string)
| ColorInherit(string)
| Inset(string)
| Sticky(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| ColorPrimary(_) => "colorPrimary"
| ColorInherit(_) => "colorInherit"
| Inset(_) => "inset"
| Sticky(_) => "sticky";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| ColorPrimary(className)
| ColorInherit(className)
| Inset(className)
| Sticky(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~className: string=?,
~color: string=?,
~component: 'union_r06u=?,
~disableSticky: bool=?,
~inset: bool=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/ListSubheader/ListSubheader"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~className: option(string)=?,
~color: option(color)=?,
~component: option([ | `String(string) | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~disableSticky: option(bool)=?,
~inset: option(bool)=?,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~className=?className,
~color=?color |. Belt.Option.map((v => colorToJs(v))),
~component=?component |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~disableSticky=?disableSticky,
~inset=?inset,
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        