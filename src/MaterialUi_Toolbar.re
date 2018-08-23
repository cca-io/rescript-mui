
            

                module Classes = {
                    type classesType = | Root(string)
| Gutters(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| Gutters(_) => "gutters";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| Gutters(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~className: string=?,
~disableGutters: bool=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/Toolbar/Toolbar"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~className: option(string)=?,
~disableGutters: option(bool)=?,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~className=?className,
~disableGutters=?disableGutters,
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        