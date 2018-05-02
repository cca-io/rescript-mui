[@bs.deriving jsConverter]
type direction = [
  | [@bs.as "left"] `Left
  | [@bs.as "right"] `Right
  | [@bs.as "up"] `Up
  | [@bs.as "down"] `Down
];

type typeTimeout_shape;

[@bs.obj]
external makeTimeout_shape :
  (~enter: 'number_k=?, ~exit: 'number_5=?, unit) => typeTimeout_shape =
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

[@bs.obj]
external makeProps :
  (
    ~direction: string=?,
    ~_in: bool=?,
    ~onEnter: ReactEventRe.Synthetic.t => unit=?,
    ~onEntering: ReactEventRe.Synthetic.t => unit=?,
    ~onExit: ReactEventRe.Synthetic.t => unit=?,
    ~onExited: ReactEventRe.Synthetic.t => unit=?,
    ~theme: Js.t({..})=?,
    ~timeout: 'union_rzb7=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/transitions/Slide"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~direction: option(direction)=?,
      ~_in: option(bool)=?,
      ~onEnter: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onEntering: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExit: option(ReactEventRe.Synthetic.t => unit)=?,
      ~onExited: option(ReactEventRe.Synthetic.t => unit)=?,
      ~theme: option(Js.t({..}))=?,
      ~timeout:
         option(
           [ | `Int(int) | `Float(float) | `Object(typeTimeout_shape)],
         )=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~direction=?Js.Option.map((. v) => directionToJs(v), direction),
        ~_in?,
        ~onEnter?,
        ~onEntering?,
        ~onExit?,
        ~onExited?,
        ~theme?,
        ~timeout=?
          Js.Option.map(
            (. v) =>
              switch (v) {
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
