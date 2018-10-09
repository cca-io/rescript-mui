module Classes = {
  type classesType =
    | Root(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root";
  let to_obj = listOfClasses =>
    listOfClasses
    ->(
        Belt.List.reduce(
          Js.Dict.empty(),
          (obj, classType) => {
            switch (classType) {
            | Root(className) =>
              Js.Dict.set(obj, to_string(classType), className)
            };
            obj;
          },
        )
      );
};

[@bs.obj]
external makeProps:
  (
    ~className: string=?,
    ~raised: bool=?,
    ~component: 'union_r2jf=?,
    ~elevation: 'number_9=?,
    ~square: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "Card";
let make =
    (
      ~className: option(string)=?,
      ~raised: option(bool)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~elevation: option([ | `Int(int) | `Float(float)])=?,
      ~square: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~raised?,
        ~component=?
          component
          ->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~elevation=?
          elevation
          ->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~square?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
