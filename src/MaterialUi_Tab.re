
            

                [@bs.deriving jsConverter]
                type textColor = [
                    | [@bs.as "secondary"] `Secondary
| [@bs.as "primary"] `Primary
| [@bs.as "inherit"] `Inherit
                ];

                module Classes = {
                    type classesType = | Root(string)
| LabelIcon(string)
| TextColorInherit(string)
| TextColorPrimary(string)
| TextColorSecondary(string)
| Selected(string)
| Disabled(string)
| FullWidth(string)
| Wrapper(string)
| LabelContainer(string)
| Label(string)
| LabelWrapped(string);
                    type t = list(classesType);
                    let to_string =
                        fun
                        | Root(_) => "root"
| LabelIcon(_) => "labelIcon"
| TextColorInherit(_) => "textColorInherit"
| TextColorPrimary(_) => "textColorPrimary"
| TextColorSecondary(_) => "textColorSecondary"
| Selected(_) => "selected"
| Disabled(_) => "disabled"
| FullWidth(_) => "fullWidth"
| Wrapper(_) => "wrapper"
| LabelContainer(_) => "labelContainer"
| Label(_) => "label"
| LabelWrapped(_) => "labelWrapped";
                    let to_obj = (listOfClasses) =>
                    listOfClasses |. Belt.List.reduce(
                        Js.Dict.empty(),
                        (obj, classType) => {
                            switch classType {
                                | Root(className)
| LabelIcon(className)
| TextColorInherit(className)
| TextColorPrimary(className)
| TextColorSecondary(className)
| Selected(className)
| Disabled(className)
| FullWidth(className)
| Wrapper(className)
| LabelContainer(className)
| Label(className)
| LabelWrapped(className) => Js.Dict.set(obj, to_string(classType), className)
                            };
                            obj
                        },
                    );
                };
            
            [@bs.obj] external makeProps : (~className: string=?,
~disabled: bool=?,
~fullWidth: bool=?,
~icon: ReasonReact.reactElement=?,
~indicator: ReasonReact.reactElement=?,
~label: ReasonReact.reactElement=?,
~onChange: ReactEvent.Form.t => unit=?,
~onClick: ReactEvent.Mouse.t => unit=?,
~selected: bool=?,
~textColor: string=?,
~value: 'any_rdwr=?,
~action: 'any_ru46=?,
~buttonRef: 'union_r9no=?,
~centerRipple: bool=?,
~component: 'union_rzp4=?,
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
~tabIndex: 'union_ruhl=?,
~_TouchRippleProps: Js.t({..})=?,
~_type: string=?,
~classes: Js.Dict.t(string)=?,~style: ReactDOMRe.Style.t=?, unit) => _ = "";
            [@bs.module "@material-ui/core/Tab/Tab"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~className: option(string)=?,
~disabled: option(bool)=?,
~fullWidth: option(bool)=?,
~icon: option(ReasonReact.reactElement)=?,
~indicator: option(ReasonReact.reactElement)=?,
~label: option(ReasonReact.reactElement)=?,
~onChange: option(ReactEvent.Form.t => unit)=?,
~onClick: option(ReactEvent.Mouse.t => unit)=?,
~selected: option(bool)=?,
~textColor: option(textColor)=?,
~value: option('any_rdwr)=?,
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
~fullWidth=?fullWidth,
~icon=?icon,
~indicator=?indicator,
~label=?label,
~onChange=?onChange,
~onClick=?onClick,
~selected=?selected,
~textColor=?textColor |. Belt.Option.map((v => textColorToJs(v))),
~value=?value,
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
        