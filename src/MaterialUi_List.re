module Classes = {
  type classesType =
    | Root(string)
    | Padding(string)
    | Dense(string)
    | Subheader(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Padding(_) => "padding"
    | Dense(_) => "dense"
    | Subheader(_) => "subheader";
  let to_obj = listOfClasses =>
    listOfClasses
    ->(
        Belt.List.reduce(
          Js.Dict.empty(),
          (obj, classType) => {
            switch (classType) {
            | Root(className)
            | Padding(className)
            | Dense(className)
            | Subheader(className) =>
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
    ~component: 'union_rniu=?,
    ~dense: bool=?,
    ~disablePadding: bool=?,
    ~subheader: ReasonReact.reactElement=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";
[@bs.module "@material-ui/core"]
external reactClass: ReasonReact.reactClass = "List";
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
      ~dense: option(bool)=?,
      ~disablePadding: option(bool)=?,
      ~subheader: option(ReasonReact.reactElement)=?,
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
          component
          ->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
        ~dense?,
        ~disablePadding?,
        ~subheader?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
