module Classes = {
  type classesType =
    | Root(string)
    | Multiline(string)
    | Dense(string)
    | Inset(string)
    | Primary(string)
    | Secondary(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | Multiline(_) => "multiline"
    | Dense(_) => "dense"
    | Inset(_) => "inset"
    | Primary(_) => "primary"
    | Secondary(_) => "secondary";
  let to_obj = listOfClasses =>
    listOfClasses->(
                     Belt.List.reduce(
                       Js.Dict.empty(),
                       (obj, classType) => {
                         switch (classType) {
                         | Root(className)
                         | Multiline(className)
                         | Dense(className)
                         | Inset(className)
                         | Primary(className)
                         | Secondary(className) =>
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
    ~children: 'children=?,
    ~className: string=?,
    ~disableTypography: bool=?,
    ~inset: bool=?,
    ~primary: React.element=?,
    ~primaryTypographyProps: Js.t({..})=?,
    ~secondary: React.element=?,
    ~secondaryTypographyProps: Js.t({..})=?,
    ~key: string=?,
    ~_ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~disableTypography: option(bool)=?,
      ~inset: option(bool)=?,
      ~primary: option(React.element)=?,
      ~primaryTypographyProps: option(Js.t({..}))=?,
      ~secondary: option(React.element)=?,
      ~secondaryTypographyProps: option(Js.t({..}))=?,
      ~key: option(string)=?,
      ~ref_: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~children?,
    ~className?,
    ~disableTypography?,
    ~inset?,
    ~primary?,
    ~primaryTypographyProps?,
    ~secondary?,
    ~secondaryTypographyProps?,
    ~key?,
    ~_ref=?ref_,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "ListItemText";
