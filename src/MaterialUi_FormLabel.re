module Classes = {
  type classesType =
    | Root(string)
    | Focused(string)
    | Disabled(string)
    | Error(string)
    | Asterisk(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Focused(_) => "focused"
    | Disabled(_) => "disabled"
    | Error(_) => "error"
    | Asterisk(_) => "asterisk";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | Focused(className)
             | Disabled(className)
             | Error(className)
             | Asterisk(className) =>
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
    ~component: 'union_r4nd=?,
    ~disabled: bool=?,
    ~error: bool=?,
    ~focused: bool=?,
    ~required: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/FormLabel/FormLabel"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~className: option(string)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~disabled: option(bool)=?,
      ~error: option(bool)=?,
      ~focused: option(bool)=?,
      ~required: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~className?,
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~disabled?,
        ~error?,
        ~focused?,
        ~required?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
