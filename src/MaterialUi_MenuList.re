
            
            [@bs.obj] external makeProps : (~className: string=?,
~onBlur: ReactEvent.Focus.t => unit=?,
~onKeyDown: ReactEvent.Keyboard.t => unit=?,
~component: 'union_roui=?,
~dense: bool=?,
~disablePadding: bool=?,
~subheader: ReasonReact.reactElement=?,
 unit) => _ = "";
            [@bs.module "@material-ui/core/MenuList/MenuList"] external reactClass : ReasonReact.reactClass = "default";
            let make = (
                ~className: option(string)=?,
~onBlur: option(ReactEvent.Focus.t => unit)=?,
~onKeyDown: option(ReactEvent.Keyboard.t => unit)=?,
~component: option([ | `String(string) | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))  ])=?,
~dense: option(bool)=?,
~disablePadding: option(bool)=?,
~subheader: option(ReasonReact.reactElement)=?,

                children
            ) => ReasonReact.wrapJsForReason(
                    ~reactClass,
                    ~props=makeProps(~className=?className,
~onBlur=?onBlur,
~onKeyDown=?onKeyDown,
~component=?component |. Belt.Option.map((v => MaterialUi_Helpers.unwrapValue(v))),
~dense=?dense,
~disablePadding=?disablePadding,
~subheader=?subheader,
 ()),
                    children
                );
        