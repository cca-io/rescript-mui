
            

                [@bs.deriving jsConverter]
                type direction = [
                    | [@bs.as "asc"] `Asc
| [@bs.as "desc"] `Desc
                ];

                module Classes = {
                    type classesType = | Root(string)
| Active(string)
| Icon(string)
| IconDirectionDesc(string)
| IconDirectionAsc(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| Active(_) => "active"
| Icon(_) => "icon"
| IconDirectionDesc(_) => "iconDirectionDesc"
| IconDirectionAsc(_) => "iconDirectionAsc";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| Active(className)
| Icon(className)
| IconDirectionDesc(className)
| IconDirectionAsc(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~active: bool=?,
~className: string=?,
~direction: string=?,
~action: 'any_r64j=?,
~buttonRef: 'union_rvia=?,
~centerRipple: bool=?,
~component: 'union_riei=?,
~disabled: bool=?,
~disableRipple: bool=?,
~disableTouchRipple: bool=?,
~focusRipple: bool=?,
~focusVisibleClassName: string=?,
~onBlur: ReactEvent.Focus.t => unit=?,
~onClick: ReactEvent.Mouse.t => unit=?,
~onFocus: ReactEvent.Focus.t => unit=?,
~onFocusVisible: 'genericCallback=?,
~onKeyDown: ReactEvent.Keyboard.t => unit=?,
~onKeyUp: ReactEvent.Keyboard.t => unit=?,
~onMouseDown: ReactEvent.Mouse.t => unit=?,
~onMouseLeave: ReactEvent.Mouse.t => unit=?,
~onMouseUp: ReactEvent.Mouse.t => unit=?,
~onTouchEnd: ReactEvent.Touch.t => unit=?,
~onTouchMove: ReactEvent.Touch.t => unit=?,
~onTouchStart: ReactEvent.Touch.t => unit=?,
~role: string=?,
~tabIndex: 'union_r1z7=?,
~_TouchRippleProps: Js.t({..})=?,
~_type: string=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/TableSortLabel/TableSortLabel"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~active: option(bool)=?,
~className: option(string)=?,
~direction: option(direction)=?,
~action: option((Js.t({..})) => unit)=?,
~buttonRef: option([ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~centerRipple: option(bool)=?,
~component: option([ | `String(string) | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~disabled: option(bool)=?,
~disableRipple: option(bool)=?,
~disableTouchRipple: option(bool)=?,
~focusRipple: option(bool)=?,
~focusVisibleClassName: option(string)=?,
~onBlur: option(ReactEvent.Focus.t => unit)=?,
~onClick: option(ReactEvent.Mouse.t => unit)=?,
~onFocus: option(ReactEvent.Focus.t => unit)=?,
~onFocusVisible: option('genericCallback)=?,
~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
~onKeyUp: option(ReactEvent.Keyboard.t => unit)=?,
~onMouseDown: option(ReactEvent.Mouse.t => unit)=?,
~onMouseLeave: option(ReactEvent.Mouse.t => unit)=?,
~onMouseUp: option(ReactEvent.Mouse.t => unit)=?,
~onTouchEnd: option(ReactEvent.Touch.t => unit)=?,
~onTouchMove: option(ReactEvent.Touch.t => unit)=?,
~onTouchStart: option(ReactEvent.Touch.t => unit)=?,
~role: option(string)=?,
~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~_TouchRippleProps: option(Js.t({..}))=?,
~type_: option(string)=?,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~active=?active,
~className=?className,
~direction=?direction |. Belt.Option.map((v => directionToJs(v))),
~action=?action,
~buttonRef=?buttonRef |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~centerRipple=?centerRipple,
~component=?component |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~disabled=?disabled,
~disableRipple=?disableRipple,
~disableTouchRipple=?disableTouchRipple,
~focusRipple=?focusRipple,
~focusVisibleClassName=?focusVisibleClassName,
~onBlur=?onBlur,
~onClick=?onClick,
~onFocus=?onFocus,
~onFocusVisible=?onFocusVisible,
~onKeyDown=?onKeyDown,
~onKeyUp=?onKeyUp,
~onMouseDown=?onMouseDown,
~onMouseLeave=?onMouseLeave,
~onMouseUp=?onMouseUp,
~onTouchEnd=?onTouchEnd,
~onTouchMove=?onTouchMove,
~onTouchStart=?onTouchStart,
~role=?role,
~tabIndex=?tabIndex |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~_TouchRippleProps=?_TouchRippleProps,
~_type=?type_,
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        