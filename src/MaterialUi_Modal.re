
            

                module Classes = {
                    type classesType = | Root(string)
| Hidden(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| Hidden(_) => "hidden";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| Hidden(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~_BackdropComponent: 'union_r73q=?,
~_BackdropProps: Js.t({..})=?,
~className: string=?,
~container: 'union_rrf6=?,
~disableAutoFocus: bool=?,
~disableBackdropClick: bool=?,
~disableEnforceFocus: bool=?,
~disableEscapeKeyDown: bool=?,
~disableRestoreFocus: bool=?,
~hideBackdrop: bool=?,
~keepMounted: bool=?,
~manager: Js.t({..})=?,
~onBackdropClick: ReactEvent.Mouse.t => unit=?,
~onClose: 'any_rv77=?,
~onEscapeKeyDown: ReactEvent.Keyboard.t => unit=?,
~onRendered: ReactEvent.Synthetic.t => unit=?,
~_open: bool,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/Modal/Modal"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~_BackdropComponent: option([ | `String(string) | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~_BackdropProps: option(Js.t({..}))=?,
~className: option(string)=?,
~container: option([ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)  ])=?,
~disableAutoFocus: option(bool)=?,
~disableBackdropClick: option(bool)=?,
~disableEnforceFocus: option(bool)=?,
~disableEscapeKeyDown: option(bool)=?,
~disableRestoreFocus: option(bool)=?,
~hideBackdrop: option(bool)=?,
~keepMounted: option(bool)=?,
~manager: option(Js.t({..}))=?,
~onBackdropClick: option(ReactEvent.Mouse.t => unit)=?,
~onClose: option((ReactEvent.Synthetic.t, string) => unit)=?,
~onEscapeKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
~onRendered: option(ReactEvent.Synthetic.t => unit)=?,
~open_: bool,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~_BackdropComponent=?_BackdropComponent |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~_BackdropProps=?_BackdropProps,
~className=?className,
~container=?container |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~disableAutoFocus=?disableAutoFocus,
~disableBackdropClick=?disableBackdropClick,
~disableEnforceFocus=?disableEnforceFocus,
~disableEscapeKeyDown=?disableEscapeKeyDown,
~disableRestoreFocus=?disableRestoreFocus,
~hideBackdrop=?hideBackdrop,
~keepMounted=?keepMounted,
~manager=?manager,
~onBackdropClick=?onBackdropClick,
~onClose=?onClose,
~onEscapeKeyDown=?onEscapeKeyDown,
~onRendered=?onRendered,
~_open=open_,
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        