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

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~className: option(string)=?,
    ~clone: option(bool)=?,
    ~children: option('children)=?,
    ~component: option(Component.t)=?,
    ~alignContent: option(string)=?,
    ~alignItems: option(string)=?,
    ~alignSelf: option(string)=?,
    ~bgcolor: option(string)=?,
    ~border: option(string)=?,
    ~borderBottom: option(string)=?,
    ~borderColor: option(string)=?,
    ~borderLeft: option(string)=?,
    ~borderRadius: option(string)=?,
    ~borderRight: option(string)=?,
    ~borderTop: option(string)=?,
    ~boxShadow: option(string)=?,
    ~boxSizing: option(string)=?,
    ~color: option(string)=?,
    ~display: option(string)=?,
    ~displayPrint: option(string)=?,
    ~flex: option(string)=?,
    ~flexBasis: option(string)=?,
    ~flexDirection: option(string)=?,
    ~flexGrow: option(string)=?,
    ~flexShrink: option(string)=?,
    ~flexWrap: option(string)=?,
    ~fontFamily: option(string)=?,
    ~fontSize: option(string)=?,
    ~fontStyle: option(string)=?,
    ~fontWeight: option(string)=?,
    ~gridArea: option(string)=?,
    ~gridAutoColumns: option(string)=?,
    ~gridAutoFlow: option(string)=?,
    ~gridAutoRows: option(string)=?,
    ~gridColumn: option(string)=?,
    ~gridColumnGap: option(string)=?,
    ~gridGap: option(string)=?,
    ~gridRow: option(string)=?,
    ~gridRowGap: option(string)=?,
    ~gridTemplateAreas: option(string)=?,
    ~gridTemplateColumns: option(string)=?,
    ~gridTemplateRows: option(string)=?,
    ~height: option(string)=?,
    ~justifyContent: option(string)=?,
    ~justifyItems: option(string)=?,
    ~justifySelf: option(string)=?,
    ~letterSpacing: option(string)=?,
    ~lineHeight: option(string)=?,
    ~maxHeight: option(string)=?,
    ~maxWidth: option(string)=?,
    ~mb: option(int)=?,
    ~minHeight: option(string)=?,
    ~minWidth: option(string)=?,
    ~order: option(string)=?,
    ~overflow: option(string)=?,
    ~sizeHeight: option(string)=?,
    ~sizeWidth: option(string)=?,
    ~textAlign: option(string)=?,
    ~textOverflow: option(string)=?,
    ~visibility: option(string)=?,
    ~whiteSpace: option(string)=?,
    ~width: option(string)=?,
    ~zIndex: option(int)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Box";
