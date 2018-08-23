
            

                module Classes = {
                    type classesType = | Root(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~className: string=?,
~onChange: 'any_rse7=?,
~showLabels: bool=?,
~value: 'any_rbs4=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/BottomNavigation/BottomNavigation"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~className: option(string)=?,
~onChange: option((ReactEvent.Form.t, 'any_rkgq) => unit)=?,
~showLabels: option(bool)=?,
~value: option('any_rbs4)=?,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~className=?className,
~onChange=?onChange,
~showLabels=?showLabels,
~value=?value,
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        