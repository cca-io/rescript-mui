
            

                module Classes = {
                    type classesType = | Root(string)
| Expanded(string)
| Focused(string)
| Disabled(string)
| Content(string)
| ExpandIcon(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| Expanded(_) => "expanded"
| Focused(_) => "focused"
| Disabled(_) => "disabled"
| Content(_) => "content"
| ExpandIcon(_) => "expandIcon";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| Expanded(className)
| Focused(className)
| Disabled(className)
| Content(className)
| ExpandIcon(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~className: string=?,
~disabled: bool=?,
~expanded: bool=?,
~expandIcon: ReasonReact.reactElement=?,
~onChange: ReactEvent.Form.t => unit=?,
~onClick: ReactEvent.Mouse.t => unit=?,
~action: 'any_rvit=?,
~buttonRef: 'union_rhwk=?,
~centerRipple: bool=?,
~component: 'union_rrun=?,
~disableRipple: bool=?,
~disableTouchRipple: bool=?,
~focusRipple: bool=?,
~focusVisibleClassName: string=?,
~onBlur: ReactEvent.Focus.t => unit=?,
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
~tabIndex: 'union_rku2=?,
~_TouchRippleProps: Js.t({..})=?,
~_type: string=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/ExpansionPanelSummary/ExpansionPanelSummary"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~className: option(string)=?,
~disabled: option(bool)=?,
~expanded: option(bool)=?,
~expandIcon: option(ReasonReact.reactElement)=?,
~onChange: option(ReactEvent.Form.t => unit)=?,
~onClick: option(ReactEvent.Mouse.t => unit)=?,
~action: option((Js.t({..})) => unit)=?,
~buttonRef: option([ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~centerRipple: option(bool)=?,
~component: option([ | `String(string) | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~disableRipple: option(bool)=?,
~disableTouchRipple: option(bool)=?,
~focusRipple: option(bool)=?,
~focusVisibleClassName: option(string)=?,
~onBlur: option(ReactEvent.Focus.t => unit)=?,
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
                    ~props=makeProps(~className=?className,
~disabled=?disabled,
~expanded=?expanded,
~expandIcon=?expandIcon,
~onChange=?onChange,
~onClick=?onClick,
~action=?action,
~buttonRef=?buttonRef |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~centerRipple=?centerRipple,
~component=?component |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~disableRipple=?disableRipple,
~disableTouchRipple=?disableTouchRipple,
~focusRipple=?focusRipple,
~focusVisibleClassName=?focusVisibleClassName,
~onBlur=?onBlur,
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
        