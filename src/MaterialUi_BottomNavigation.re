module Classes = {
  type classesType =
    | Root(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className) =>
               Js.Dict.set(obj, to_string(classType), className)
             };
             obj;
           },
         ~init=Js.Dict.empty(),
       );
};

[@bs.obj]
external makeProps :
  (
    ~className: string=?,
    ~onChange: 'any_r5z6=?,
    ~showLabels: bool=?,
    ~value: 'any_rtv2=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/BottomNavigation/BottomNavigation"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~onChange: option((ReactEventRe.Form.t, 'any_ra4o) => unit)=?,
      ~showLabels: option(bool)=?,
      ~value: option('any_rtv2)=?,
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
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
