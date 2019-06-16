module Classes = {
  type classesType =
    | Root(string)
    | Ripple(string)
    | RippleVisible(string)
    | RipplePulsate(string)
    | Child(string)
    | ChildLeaving(string)
    | ChildPulsate(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Ripple(_) => "ripple"
    | RippleVisible(_) => "rippleVisible"
    | RipplePulsate(_) => "ripplePulsate"
    | Child(_) => "child"
    | ChildLeaving(_) => "childLeaving"
    | ChildPulsate(_) => "childPulsate";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Ripple(className)
                         | RippleVisible(className)
                         | RipplePulsate(className)
                         | Child(className)
                         | ChildLeaving(className)
                         | ChildPulsate(className) =>
                           Js.Dict.set(obj, to_string(classType), className)
                         };
                         obj;
                       },
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~center: bool=?,
    ~className: string=?,
    ~key: string=?,
    ~_ref: React.Ref.t(Dom.element)=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~center: option(bool)=?,
      ~className: option(string)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(Dom.element))=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~center?,
    ~className?,
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "TouchRipple";
