module Component: {
  type t;
  let string: string => t;
  let callback: (unit => React.element) => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let callback = (v: unit => React.element) => Any(v);
  let element = (v: React.element) => Any(v);
};

type variant = [ | `Circle | `Circular | `Rounded | `Square];

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~alt: string=?,
    ~children: 'children=?,
    ~className: string=?,
    ~component: Component.t=?,
    ~imgProps: Js.t({..})=?,
    ~sizes: string=?,
    ~src: string=?,
    ~srcSet: string=?,
    ~variant: [@bs.string] [
                | [@bs.as "circle"] `Circle
                | [@bs.as "circular"] `Circular
                | [@bs.as "rounded"] `Rounded
                | [@bs.as "square"] `Square
              ]
                =?,
    ~id: string=?,
    ~style: ReactDOM.Style.t=?,
    ~key: string=?,
    ~ref: ReactDOM.domRef=?
  ) =>
  React.element =
  "Avatar";
