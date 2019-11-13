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
    listOfClasses->(
                     Belt.List.reduce(
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
                     )
                   );
};

[@bs.obj]
external makePropsMui:
  (
    ~alt: string=?,
    ~children: 'children=?,
    ~className: string=?,
    ~component: 'union_rmcc=?,
    ~imgProps: Js.t({..})=?,
    ~sizes: string=?,
    ~src: string=?,
    ~srcSet: string=?,
    ~key: string=?,
    ~ref: ReactDOMRe.domRef=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~alt: option(string)=?,
      ~children: option('children)=?,
      ~className: option(string)=?,
      ~component:
         option(
           [
             | `String(string)
             | `Callback(unit => React.element)
             | `Element(React.element)
           ],
         )=?,
      ~imgProps: option(Js.t({..}))=?,
      ~sizes: option(string)=?,
      ~src: option(string)=?,
      ~srcSet: option(string)=?,
      ~key: option(string)=?,
      ~ref: option(ReactDOMRe.domRef)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      (),
    ) =>
  makePropsMui(
    ~alt?,
    ~children?,
    ~className?,
    ~component=?
      component->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~imgProps?,
    ~sizes?,
    ~src?,
    ~srcSet?,
    ~key?,
    ~ref?,
    ~classes=?Belt.Option.map(classes, v => Classes.to_obj(v)),
    ~style?,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Avatar";
