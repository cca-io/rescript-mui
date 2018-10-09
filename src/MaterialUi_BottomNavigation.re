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
    ~onChange: 'any_r9r6=?,
    ~showLabels: bool=?,
    ~value: 'any_rjz6=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "BottomNavigation";
let make =
    (
      ~className: option(string)=?,
      ~onChange: option((ReactEvent.Form.t, 'any_rof9) => unit)=?,
      ~showLabels: option(bool)=?,
      ~value: option('any_rjz6)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~onChange?,
        ~showLabels?,
        ~value?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
