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

module Classes = {
  [@bs.deriving abstract]
  type t = {
    [@bs.optional]
    root: string,
    [@bs.optional]
    focused: string,
    [@bs.optional]
    disabled: string,
    [@bs.optional]
    error: string,
    [@bs.optional]
    required: string,
    [@bs.optional]
    asterisk: string,
    [@bs.optional]
    formControl: string,
    [@bs.optional]
    marginDense: string,
    [@bs.optional]
    shrink: string,
    [@bs.optional]
    animated: string,
    [@bs.optional]
    filled: string,
    [@bs.optional]
    outlined: string,
  };
  let make = t;
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~component: option(Component.t)=?,
    ~filled: option(bool)=?,
    ~id: option(string)=?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~color: option(
              [@bs.string] [
                | [@bs.as "primary"] `Primary
                | [@bs.as "secondary"] `Secondary
              ],
            )
              =?,
    ~disableAnimation: option(bool)=?,
    ~disabled: option(bool)=?,
    ~error: option(bool)=?,
    ~focused: option(bool)=?,
    ~margin: option([@bs.string] [ | [@bs.as "dense"] `Dense])=?,
    ~required: option(bool)=?,
    ~shrink: option(bool)=?,
    ~variant: option(
                [@bs.string] [
                  | [@bs.as "standard"] `Standard
                  | [@bs.as "outlined"] `Outlined
                  | [@bs.as "filled"] `Filled
                ],
              )
                =?,
    ~htmlFor: string,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "InputLabel";
