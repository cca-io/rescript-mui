module Classes = {
  type classesType =
    | Root(string)
    | Disabled(string)
    | Label(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Disabled(_) => "disabled"
    | Label(_) => "label";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Disabled(className)
             | Label(className) =>
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
    ~checked: 'union_r37r=?,
    ~className: string=?,
    ~control: ReasonReact.reactElement=?,
    ~disabled: bool=?,
    ~inputRef: 'genericCallback=?,
    ~label: ReasonReact.reactElement=?,
    ~name: string=?,
    ~onChange: 'any_rhwo=?,
    ~value: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/FormControlLabel/FormControlLabel"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~checked: option([ | `Bool(bool) | `String(string)])=?,
      ~className: option(string)=?,
      ~control: option(ReasonReact.reactElement)=?,
      ~disabled: option(bool)=?,
      ~inputRef: option('genericCallback)=?,
      ~label: option(ReasonReact.reactElement)=?,
      ~name: option(string)=?,
      ~onChange: option((ReactEventRe.Form.t, bool) => unit)=?,
      ~value: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~checked=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            checked,
          ),
        ~className?,
        ~control?,
        ~disabled?,
        ~inputRef?,
        ~label?,
        ~name?,
        ~onChange?,
        ~value?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
