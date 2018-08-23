
            

                [@bs.deriving jsConverter]
                type margin = [
                    | [@bs.as "dense"] `Dense
                ];

                module Classes = {
                    type classesType = | Root(string)
| FormControl(string)
| MarginDense(string)
| Shrink(string)
| Animated(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| FormControl(_) => "formControl"
| MarginDense(_) => "marginDense"
| Shrink(_) => "shrink"
| Animated(_) => "animated";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| FormControl(className)
| MarginDense(className)
| Shrink(className)
| Animated(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~className: string=?,
~disableAnimation: bool=?,
~disabled: bool=?,
~error: bool=?,
~focused: bool=?,
~_FormLabelClasses: Js.t({..})=?,
~margin: string=?,
~required: bool=?,
~shrink: bool=?,
~component: 'union_rgjx=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/InputLabel/InputLabel"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~className: option(string)=?,
~disableAnimation: option(bool)=?,
~disabled: option(bool)=?,
~error: option(bool)=?,
~focused: option(bool)=?,
~_FormLabelClasses: option(Js.t({..}))=?,
~margin: option(margin)=?,
~required: option(bool)=?,
~shrink: option(bool)=?,
~component: option([ | `String(string) | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~className=?className,
~disableAnimation=?disableAnimation,
~disabled=?disabled,
~error=?error,
~focused=?focused,
~_FormLabelClasses=?_FormLabelClasses,
~margin=?margin |. Belt.Option.map((v => marginToJs(v))),
~required=?required,
~shrink=?shrink,
~component=?component |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        