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
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Root(className)
             | ColorDefault(className)
             | Img(className) =>
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
    ~alt: string=?,
    ~childrenClassName: string=?,
    ~className: string=?,
    ~component: 'union_rkft=?,
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

[@bs.module "material-ui/Avatar/Avatar"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~alt: option(string)=?,
      ~childrenClassName: option(string)=?,
      ~className: option(string)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
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
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~imgProps?,
        ~sizes?,
        ~src?,
        ~srcSet?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
