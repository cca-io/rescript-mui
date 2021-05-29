[@react.component] [@bs.module "@material-ui/core/styles"]
external make:
  (
    ~disableGeneration: bool=?,
    ~generateClassName: unit => string=?,
    ~injectFirst: bool=?,
    ~jss: Js.t({..})=?,
    ~children: 'children
  ) =>
  React.element =
  "StylesProvider";
