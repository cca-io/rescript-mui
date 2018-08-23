
            
                [@bs.deriving jsConverter]
                type anchor = [
                    | [@bs.as "left"] `Left
| [@bs.as "top"] `Top
| [@bs.as "right"] `Right
| [@bs.as "bottom"] `Bottom
                ];


                    module TransitionDuration_shape {
                        [@bs.deriving abstract]
                        type t = {
                            
                                [@bs.optional]
                                
                                enter: [ | `Int(int) | `Float(float) ]
                            ,
                                [@bs.optional]
                                
                                exit: [ | `Int(int) | `Float(float) ]
                            
                        };
                        let make = t;

                        let unwrap = (obj: t) => {
                            
                                let unwrappedMap = Js.Dict.empty();
                                
                                    switch (obj |. enterGet |. Belt.Option.map((v) => MaterialUi_Helpers.unwrapValue(v))) {
                                        | Some(v) =>
                                            unwrappedMap
                                                |. Js.Dict.set(
                                                    "enter",
                                                    v
                                                    |. MaterialUi_Helpers.toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                    switch (obj |. exitGet |. Belt.Option.map((v) => MaterialUi_Helpers.unwrapValue(v))) {
                                        | Some(v) =>
                                            unwrappedMap
                                                |. Js.Dict.set(
                                                    "exit",
                                                    v
                                                    |. MaterialUi_Helpers.toJsUnsafe
                                                );
                                        | None => ()    
                                    };
                                
                                unwrappedMap;
                            
                            
                        };
                    };
                

                [@bs.deriving jsConverter]
                type variant = [
                    | [@bs.as "permanent"] `Permanent
| [@bs.as "persistent"] `Persistent
| [@bs.as "temporary"] `Temporary
                ];
            [@bs.obj] external makeProps : (~anchor: string=?,
~disableBackdropTransition: bool=?,
~disableDiscovery: bool=?,
~disableSwipeToOpen: bool=?,
~_ModalProps: Js.t({..})=?,
~onClose: 'any_rtil,
~onOpen: 'any_rc67,
~_open: bool,
~_PaperProps: Js.t({..})=?,
~swipeAreaWidth: 'number_r=?,
~theme: Js.t({..})=?,
~transitionDuration: 'union_r5nu=?,
~variant: string=?,
~className: string=?,
~elevation: 'number_n=?,
~_SlideProps: Js.t({..})=?,
 unit) => _ = "";
            [@bs.module "@material-ui/core/SwipeableDrawer/SwipeableDrawer"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~anchor: option(anchor)=?,
~disableBackdropTransition: option(bool)=?,
~disableDiscovery: option(bool)=?,
~disableSwipeToOpen: option(bool)=?,
~_ModalProps: option(Js.t({..}))=?,
~onClose: (ReactEvent.Synthetic.t) => unit,
~onOpen: (ReactEvent.Synthetic.t) => unit,
~open_: bool,
~_PaperProps: option(Js.t({..}))=?,
~swipeAreaWidth: option([ | `Int(int) | `Float(float) ])=?,
~theme: option(Js.t({..}))=?,
~transitionDuration: option([ | `Int(int) | `Float(float) | `Object(TransitionDuration_shape.t)  ])=?,
~variant: option(variant)=?,
~className: option(string)=?,
~elevation: option([ | `Int(int) | `Float(float) ])=?,
~_SlideProps: option(Js.t({..}))=?,

                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~anchor=?anchor |. Belt.Option.map((v => anchorToJs(v))),
~disableBackdropTransition=?disableBackdropTransition,
~disableDiscovery=?disableDiscovery,
~disableSwipeToOpen=?disableSwipeToOpen,
~_ModalProps=?_ModalProps,
~onClose=onClose,
~onOpen=onOpen,
~_open=open_,
~_PaperProps=?_PaperProps,
~swipeAreaWidth=?swipeAreaWidth |. Belt.Option.map((v) => MaterialUi_Helpers.unwrapValue(v)),
~theme=?theme,
~transitionDuration=?transitionDuration |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~variant=?variant |. Belt.Option.map((v => variantToJs(v))),
~className=?className,
~elevation=?elevation |. Belt.Option.map((v) => MaterialUi_Helpers.unwrapValue(v)),
~_SlideProps=?_SlideProps,
 ()),
                    children
                );
        