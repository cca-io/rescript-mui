module Classes = {
  type classesType =
    | Root(string)
    | Absolute(string)
    | Inset(string)
    | Light(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Absolute(_) => "absolute"
    | Inset(_) => "inset"
    | Light(_) => "light";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | Absolute(className)
           | Inset(className)
           | Light(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~absolute: bool=?,
    ~className: string=?,
    ~component: 'union_rfl6=?,
    ~inset: bool=?,
    ~light: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Divider/Divider"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~absolute: option(bool)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~inset: option(bool)=?,
      ~light: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~absolute?,
        ~className?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~inset?,
        ~light?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
