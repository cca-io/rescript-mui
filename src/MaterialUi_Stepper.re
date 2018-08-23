
            

                [@bs.deriving jsConverter]
                type orientation = [
                    | [@bs.as "horizontal"] `Horizontal
| [@bs.as "vertical"] `Vertical
                ];

                module Classes = {
                    type classesType = | Root(string)
| Horizontal(string)
| Vertical(string)
| AlternativeLabel(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| Horizontal(_) => "horizontal"
| Vertical(_) => "vertical"
| AlternativeLabel(_) => "alternativeLabel";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| Horizontal(className)
| Vertical(className)
| AlternativeLabel(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~activeStep: 'number_q=?,
~alternativeLabel: bool=?,
~className: string=?,
~connector: ReasonReact.reactElement=?,
~nonLinear: bool=?,
~orientation: string=?,
~component: 'union_rqsa=?,
~elevation: 'number_h=?,
~square: bool=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/Stepper/Stepper"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~activeStep: option([ | `Int(int) | `Float(float) ])=?,
~alternativeLabel: option(bool)=?,
~className: option(string)=?,
~connector: option(ReasonReact.reactElement)=?,
~nonLinear: option(bool)=?,
~orientation: option(orientation)=?,
~component: option([ | `String(string) | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~elevation: option([ | `Int(int) | `Float(float) ])=?,
~square: option(bool)=?,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~activeStep=?activeStep |. Belt.Option.map((v) => MaterialUi_Helpers.unwrapValue(v)),
~alternativeLabel=?alternativeLabel,
~className=?className,
~connector=?connector,
~nonLinear=?nonLinear,
~orientation=?orientation |. Belt.Option.map((v => orientationToJs(v))),
~component=?component |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~elevation=?elevation |. Belt.Option.map((v) => MaterialUi_Helpers.unwrapValue(v)),
~square=?square,
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        