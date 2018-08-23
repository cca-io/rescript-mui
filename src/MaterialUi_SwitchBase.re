
            

                [@bs.deriving jsConverter]
                type color = [
                    | [@bs.as "default"] `Default
| [@bs.as "inherit"] `Inherit
| [@bs.as "primary"] `Primary
| [@bs.as "secondary"] `Secondary
                ];

                module Classes = {
                    type classesType = | Root(string)
| Checked(string)
| Disabled(string)
| Input(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| Checked(_) => "checked"
| Disabled(_) => "disabled"
| Input(_) => "input";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| Checked(className)
| Disabled(className)
| Input(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~checked: 'union_rqru=?,
~checkedIcon: ReasonReact.reactElement,
~className: string=?,
~defaultChecked: bool=?,
~disabled: bool=?,
~disableRipple: bool=?,
~icon: ReasonReact.reactElement,
~id: string=?,
~indeterminate: bool=?,
~indeterminateIcon: ReasonReact.reactElement=?,
~inputProps: Js.t({..})=?,
~inputRef: 'union_rlsi=?,
~name: string=?,
~onBlur: ReactEvent.Focus.t => unit=?,
~onChange: 'any_ro71=?,
~onFocus: ReactEvent.Focus.t => unit=?,
~tabIndex: 'union_rmll=?,
~_type: string=?,
~value: string=?,
~color: string=?,
~action: 'any_ro2g=?,
~buttonRef: 'union_rrxw=?,
~centerRipple: bool=?,
~component: 'union_rxdw=?,
~disableTouchRipple: bool=?,
~focusRipple: bool=?,
~focusVisibleClassName: string=?,
~onClick: ReactEvent.Mouse.t => unit=?,
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
~_TouchRippleProps: Js.t({..})=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/internal/SwitchBase"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~checked: option([ | `Bool(bool) | `String(string)  ])=?,
~checkedIcon: ReasonReact.reactElement,
~className: option(string)=?,
~defaultChecked: option(bool)=?,
~disabled: option(bool)=?,
~disableRipple: option(bool)=?,
~icon: ReasonReact.reactElement,
~id: option(string)=?,
~indeterminate: option(bool)=?,
~indeterminateIcon: option(ReasonReact.reactElement)=?,
~inputProps: option(Js.t({..}))=?,
~inputRef: option([ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~name: option(string)=?,
~onBlur: option(ReactEvent.Focus.t => unit)=?,
~onChange: option((ReactEvent.Form.t, bool) => unit)=?,
~onFocus: option(ReactEvent.Focus.t => unit)=?,
~tabIndex: option([ | `Int(int) | `Float(float) | `String(string)  ])=?,
~type_: option(string)=?,
~value: option(string)=?,
~color: option(color)=?,
~action: option((Js.t({..})) => unit)=?,
~buttonRef: option([ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~centerRipple: option(bool)=?,
~component: option([ | `String(string) | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~disableTouchRipple: option(bool)=?,
~focusRipple: option(bool)=?,
~focusVisibleClassName: option(string)=?,
~onClick: option(ReactEvent.Mouse.t => unit)=?,
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
~_TouchRippleProps: option(Js.t({..}))=?,
~classes: option(Classes.t)=?,~style: option(ReactDOMRe.Style.t)=?,
                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~checked=?checked |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~checkedIcon=checkedIcon,
~className=?className,
~defaultChecked=?defaultChecked,
~disabled=?disabled,
~disableRipple=?disableRipple,
~icon=icon,
~id=?id,
~indeterminate=?indeterminate,
~indeterminateIcon=?indeterminateIcon,
~inputProps=?inputProps,
~inputRef=?inputRef |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~name=?name,
~onBlur=?onBlur,
~onChange=?onChange,
~onFocus=?onFocus,
~tabIndex=?tabIndex |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~_type=?type_,
~value=?value,
~color=?color |. Belt.Option.map((v => colorToJs(v))),
~action=?action,
~buttonRef=?buttonRef |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~centerRipple=?centerRipple,
~component=?component |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~disableTouchRipple=?disableTouchRipple,
~focusRipple=?focusRipple,
~focusVisibleClassName=?focusVisibleClassName,
~onClick=?onClick,
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
~_TouchRippleProps=?_TouchRippleProps,
~classes=?Belt.Option.map(classes, (v) => Classes.to_obj(v)),~style?, ()),
                    children
                );
        