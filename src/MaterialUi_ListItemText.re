module Classes = {
  type classesType =
    | Root(string)
    | Inset(string)
    | Dense(string)
    | Primary(string)
    | Secondary(string)
    | TextDense(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Inset(_) => "inset"
    | Dense(_) => "dense"
    | Primary(_) => "primary"
    | Secondary(_) => "secondary"
    | TextDense(_) => "textDense";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Inset(className)
             | Dense(className)
             | Primary(className)
             | Secondary(className)
             | TextDense(className) =>
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
    ~disableTypography: bool=?,
    ~inset: bool=?,
    ~primary: ReasonReact.reactElement=?,
    ~secondary: ReasonReact.reactElement=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/ListItemText/ListItemText"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~disableTypography: option(bool)=?,
      ~inset: option(bool)=?,
      ~primary: option(ReasonReact.reactElement)=?,
      ~secondary: option(ReasonReact.reactElement)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~disableTypography?,
        ~inset?,
        ~primary?,
        ~secondary?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
