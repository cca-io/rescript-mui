
            

                module Classes = {
                    type classesType = | Root(string)
| Active(string)
| Completed(string)
| Error(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| Active(_) => "active"
| Completed(_) => "completed"
| Error(_) => "error";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| Active(className)
| Completed(className)
| Error(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~active: bool=?,
~completed: bool=?,
~error: bool=?,
~icon: ReasonReact.reactElement,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/StepIcon/StepIcon"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~active: option(bool)=?,
~completed: option(bool)=?,
~error: option(bool)=?,
~icon: ReasonReact.reactElement,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~active=?active,
~completed=?completed,
~error=?error,
~icon=icon,
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        