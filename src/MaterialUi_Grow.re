type typeTimeout_shape;

[@bs.obj]
external makeTimeout_shape :
  (~enter: 'number_o=?, ~exit: 'number_f=?, unit) => typeTimeout_shape =
  "";

[@bs.get_index]
external getFromTimeout_shape : (typeTimeout_shape, string) => 'a = "";

let convertTimeout_shape = (madeObj: typeTimeout_shape) => {
  let returnObj: Js.Dict.t(string) = Js.Dict.empty();
  Js.Dict.set(
    returnObj,
    "enter",
    MaterialUi_Helpers.toJsUnsafe(
      Js.Option.map(
        (. v) => MaterialUi_Helpers.unwrapValue(v),
        getFromTimeout_shape(madeObj, "enter"),
      ),
    ),
  );
  Js.Dict.set(
    returnObj,
    "exit",
    MaterialUi_Helpers.toJsUnsafe(
      Js.Option.map(
        (. v) => MaterialUi_Helpers.unwrapValue(v),
        getFromTimeout_shape(madeObj, "exit"),
      ),
    ),
  );
  returnObj;
};

[@bs.deriving jsConverter]
type timeout_enum = [ | [@bs.as "auto"] `Auto];

[@bs.obj]
external makeProps :
  (
    ~_in: bool=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~theme: Js.t({..})=?,
    ~timeout: 'union_rpt2=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/transitions/Grow"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~_in: option(bool)=?,
      ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExit: option(ReactEventRe.Synthetic.t => unit)=?,
      ~theme: option(Js.t({..}))=?,
      ~timeout:
         option(
           [
             | `Int(int)
             | `Float(float)
             | `Object(typeTimeout_shape)
             | `Enum(timeout_enum)
           ],
         )=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~_in?,
        ~onEnter?,
        ~onExit?,
        ~theme?,
        ~timeout=?
          Js.Option.map(
            (. v) =>
              switch (v) {
              | `Enum(v) =>
                MaterialUi_Helpers.unwrapValue(`String(timeout_enumToJs(v)))
              | `Object(v) =>
                MaterialUi_Helpers.unwrapValue(
                  `Element(convertTimeout_shape(v)),
                )
              | v => MaterialUi_Helpers.unwrapValue(v)
              },
            timeout,
          ),
        (),
      ),
    children,
  );
