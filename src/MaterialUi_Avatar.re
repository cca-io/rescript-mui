module Classes = {
  type classesType =
    | Root(string)
    | ColorDefault(string)
    | Img(string);
  type t = list(classesType);
  let to_string =
    fun
    | Root(_) => "root"
    | ColorDefault(_) => "colorDefault"
    | Img(_) => "img";
  let to_obj = listOfClasses =>
    listOfClasses
    |. Belt.List.reduce(
         Js.Dict.empty(),
         (obj, classType) => {
           switch (classType) {
           | Root(className)
           | ColorDefault(className)
           | Img(className) =>
             Js.Dict.set(obj, to_string(classType), className)
           };
           obj;
         },
       );
};

[@bs.obj]
external makeProps :
  (
    ~alt: string=?,
    ~childrenClassName: string=?,
    ~className: string=?,
    ~component: 'union_rj12=?,
    ~imgProps: Js.t({..})=?,
    ~sizes: string=?,
    ~src: string=?,
    ~srcSet: string=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "@material-ui/core/Avatar/Avatar"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~alt: option(string)=?,
      ~childrenClassName: option(string)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback('genericCallback)
             | `ObjectGeneric(Js.t({..}))
           ],
         )=?,
      ~imgProps: option(Js.t({..}))=?,
      ~sizes: option(string)=?,
      ~src: option(string)=?,
      ~srcSet: option(string)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~alt?,
        ~childrenClassName?,
        ~className?,
        ~component=?
          component |. Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v)),
        ~imgProps?,
        ~sizes?,
        ~src?,
        ~srcSet?,
        ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
        ~style?,
        (),
      ),
    children,
  );
