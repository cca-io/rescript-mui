[@bs.deriving jsConverter]
type implementation = [ | [@bs.as "js"] `Js | [@bs.as "css"] `Css];

[@bs.deriving jsConverter]
type initialWidth = [
  | [@bs.as "xs"] `Xs
  | [@bs.as "sm"] `Sm
  | [@bs.as "md"] `Md
  | [@bs.as "lg"] `Lg
  | [@bs.as "xl"] `Xl
];

[@bs.deriving jsConverter]
type only_enum = [
  | [@bs.as "xs"] `Xs
  | [@bs.as "sm"] `Sm
  | [@bs.as "md"] `Md
  | [@bs.as "lg"] `Lg
  | [@bs.as "xl"] `Xl
];

[@bs.deriving jsConverter]
type only_arrayOf = [
  | [@bs.as "xs"] `Xs
  | [@bs.as "sm"] `Sm
  | [@bs.as "md"] `Md
  | [@bs.as "lg"] `Lg
  | [@bs.as "xl"] `Xl
];
[@bs.obj]
external makeProps:
  (
    ~className: string=?,
    ~implementation: string=?,
    ~initialWidth: string=?,
    ~lgDown: bool=?,
    ~lgUp: bool=?,
    ~mdDown: bool=?,
    ~mdUp: bool=?,
    ~only: 'union_rhx6=?,
    ~smDown: bool=?,
    ~smUp: bool=?,
    ~xlDown: bool=?,
    ~xlUp: bool=?,
    ~xsDown: bool=?,
    ~xsUp: bool=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "Hidden";
let make =
    (
      ~className: option(string)=?,
      ~implementation: option(implementation)=?,
      ~initialWidth: option(initialWidth)=?,
      ~lgDown: option(bool)=?,
      ~lgUp: option(bool)=?,
      ~mdDown: option(bool)=?,
      ~mdUp: option(bool)=?,
      ~only: option([ | `Enum(only_enum) | `Array(array(only_arrayOf))])=?,
      ~smDown: option(bool)=?,
      ~smUp: option(bool)=?,
      ~xlDown: option(bool)=?,
      ~xlUp: option(bool)=?,
      ~xsDown: option(bool)=?,
      ~xsUp: option(bool)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~implementation=?
          implementation->(Belt.Option.map(v => implementationToJs(v))),
        ~initialWidth=?
          initialWidth->(Belt.Option.map(v => initialWidthToJs(v))),
        ~lgDown?,
        ~lgUp?,
        ~mdDown?,
        ~mdUp?,
        ~only=?
          only->(
                  Belt.Option.map(v =>
                    switch (v) {
                    | `Enum(v) =>
                      MaterialUi_Helpers.unwrapValue(
                        `String(only_enumToJs(v)),
                      )

                    | v => MaterialUi_Helpers.unwrapValue(v)
                    }
                  )
                ),
        ~smDown?,
        ~smUp?,
        ~xlDown?,
        ~xlUp?,
        ~xsDown?,
        ~xsUp?,
        (),
      ),
    children,
  );
