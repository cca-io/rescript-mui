module Classes = {
  type classesType =
    | Root(string)
    | Selected(string)
    | Hover(string)
    | Head(string)
    | Footer(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Selected(_) => "selected"
    | Hover(_) => "hover"
    | Head(_) => "head"
    | Footer(_) => "footer";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Selected(className)
                         | Hover(className)
                         | Head(className)
                         | Footer(className) =>
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
    ~component: 'union_rcnp=?,
    ~hover: bool=?,
    ~selected: bool=?,
    ~onDoubleClick: ReactEvent.Mouse.t => unit=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "TableRow";
let make =
    (
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~hover: option(bool)=?,
      ~selected: option(bool)=?,
      ~onDoubleClick: option(ReactEvent.Mouse.t => unit)=?,
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
          component->(
                       Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))
                     ),
        ~hover?,
        ~selected?,
        ~onDoubleClick?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
