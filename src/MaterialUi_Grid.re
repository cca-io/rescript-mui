[@bs.deriving jsConverter]
type alignContent = [
  | [@bs.as "stretch"] `Stretch
  | [@bs.as "center"] `Center
  | [@bs.as "flex-start"] `Flex_Start
  | [@bs.as "flex-end"] `Flex_End
  | [@bs.as "space-between"] `Space_Between
  | [@bs.as "space-around"] `Space_Around
];

[@bs.deriving jsConverter]
type alignItems = [
  | [@bs.as "flex-start"] `Flex_Start
  | [@bs.as "center"] `Center
  | [@bs.as "flex-end"] `Flex_End
  | [@bs.as "stretch"] `Stretch
  | [@bs.as "baseline"] `Baseline
];

[@bs.deriving jsConverter]
type direction = [
  | [@bs.as "row"] `Row
  | [@bs.as "row-reverse"] `Row_Reverse
  | [@bs.as "column"] `Column
  | [@bs.as "column-reverse"] `Column_Reverse
];

[@bs.deriving jsConverter]
type justify = [
  | [@bs.as "flex-start"] `Flex_Start
  | [@bs.as "center"] `Center
  | [@bs.as "flex-end"] `Flex_End
  | [@bs.as "space-between"] `Space_Between
  | [@bs.as "space-around"] `Space_Around
];

[@bs.deriving jsConverter]
type lg = [
  | [@bs.as "false"] `False
  | [@bs.as "true"] `True
  | [@bs.as "1"] `V1
  | [@bs.as "2"] `V2
  | [@bs.as "3"] `V3
  | [@bs.as "4"] `V4
  | [@bs.as "5"] `V5
  | [@bs.as "6"] `V6
  | [@bs.as "7"] `V7
  | [@bs.as "8"] `V8
  | [@bs.as "9"] `V9
  | [@bs.as "10"] `V10
  | [@bs.as "11"] `V11
  | [@bs.as "12"] `V12
];

[@bs.deriving jsConverter]
type md = [
  | [@bs.as "false"] `False
  | [@bs.as "true"] `True
  | [@bs.as "1"] `V1
  | [@bs.as "2"] `V2
  | [@bs.as "3"] `V3
  | [@bs.as "4"] `V4
  | [@bs.as "5"] `V5
  | [@bs.as "6"] `V6
  | [@bs.as "7"] `V7
  | [@bs.as "8"] `V8
  | [@bs.as "9"] `V9
  | [@bs.as "10"] `V10
  | [@bs.as "11"] `V11
  | [@bs.as "12"] `V12
];

[@bs.deriving jsConverter]
type sm = [
  | [@bs.as "false"] `False
  | [@bs.as "true"] `True
  | [@bs.as "1"] `V1
  | [@bs.as "2"] `V2
  | [@bs.as "3"] `V3
  | [@bs.as "4"] `V4
  | [@bs.as "5"] `V5
  | [@bs.as "6"] `V6
  | [@bs.as "7"] `V7
  | [@bs.as "8"] `V8
  | [@bs.as "9"] `V9
  | [@bs.as "10"] `V10
  | [@bs.as "11"] `V11
  | [@bs.as "12"] `V12
];

[@bs.deriving jsConverter]
type spacing =
  | [@bs.as 0] V0
  | [@bs.as 8] V8
  | [@bs.as 16] V16
  | [@bs.as 24] V24
  | [@bs.as 40] V40;

[@bs.deriving jsConverter]
type wrap = [
  | [@bs.as "nowrap"] `Nowrap
  | [@bs.as "wrap"] `Wrap
  | [@bs.as "wrap-reverse"] `Wrap_Reverse
];

[@bs.deriving jsConverter]
type xl = [
  | [@bs.as "false"] `False
  | [@bs.as "true"] `True
  | [@bs.as "1"] `V1
  | [@bs.as "2"] `V2
  | [@bs.as "3"] `V3
  | [@bs.as "4"] `V4
  | [@bs.as "5"] `V5
  | [@bs.as "6"] `V6
  | [@bs.as "7"] `V7
  | [@bs.as "8"] `V8
  | [@bs.as "9"] `V9
  | [@bs.as "10"] `V10
  | [@bs.as "11"] `V11
  | [@bs.as "12"] `V12
];

[@bs.deriving jsConverter]
type xs = [
  | [@bs.as "false"] `False
  | [@bs.as "true"] `True
  | [@bs.as "1"] `V1
  | [@bs.as "2"] `V2
  | [@bs.as "3"] `V3
  | [@bs.as "4"] `V4
  | [@bs.as "5"] `V5
  | [@bs.as "6"] `V6
  | [@bs.as "7"] `V7
  | [@bs.as "8"] `V8
  | [@bs.as "9"] `V9
  | [@bs.as "10"] `V10
  | [@bs.as "11"] `V11
  | [@bs.as "12"] `V12
];

module Classes = {
  type classesType =
    | Container(string)
    | Item(string)
    | ZeroMinWidth(string)
    | Direction_Xs_Column(string)
    | Direction_Xs_Column_Reverse(string)
    | Direction_Xs_Row_Reverse(string)
    | Wrap_Xs_Nowrap(string)
    | Wrap_Xs_Wrap_Reverse(string)
    | Align_Items_Xs_Center(string)
    | Align_Items_Xs_Flex_Start(string)
    | Align_Items_Xs_Flex_End(string)
    | Align_Items_Xs_Baseline(string)
    | Align_Content_Xs_Center(string)
    | Align_Content_Xs_Flex_Start(string)
    | Align_Content_Xs_Flex_End(string)
    | Align_Content_Xs_Space_Between(string)
    | Align_Content_Xs_Space_Around(string)
    | Justify_Xs_Center(string)
    | Justify_Xs_Flex_End(string)
    | Justify_Xs_Space_Between(string)
    | Justify_Xs_Space_Around(string)
    | Spacing_Xs_8(string)
    | Spacing_Xs_16(string)
    | Spacing_Xs_24(string)
    | Spacing_Xs_40(string)
    | Grid_Xs(string)
    | Grid_Xs_1(string)
    | Grid_Xs_2(string)
    | Grid_Xs_3(string)
    | Grid_Xs_4(string)
    | Grid_Xs_5(string)
    | Grid_Xs_6(string)
    | Grid_Xs_7(string)
    | Grid_Xs_8(string)
    | Grid_Xs_9(string)
    | Grid_Xs_10(string)
    | Grid_Xs_11(string)
    | Grid_Xs_12(string);
  type t = list(classesType);
  let to_string =
    fun
    | Container(_) => "container"
    | Item(_) => "item"
    | ZeroMinWidth(_) => "zeroMinWidth"
    | Direction_Xs_Column(_) => "direction-xs-column"
    | Direction_Xs_Column_Reverse(_) => "direction-xs-column-reverse"
    | Direction_Xs_Row_Reverse(_) => "direction-xs-row-reverse"
    | Wrap_Xs_Nowrap(_) => "wrap-xs-nowrap"
    | Wrap_Xs_Wrap_Reverse(_) => "wrap-xs-wrap-reverse"
    | Align_Items_Xs_Center(_) => "align-items-xs-center"
    | Align_Items_Xs_Flex_Start(_) => "align-items-xs-flex-start"
    | Align_Items_Xs_Flex_End(_) => "align-items-xs-flex-end"
    | Align_Items_Xs_Baseline(_) => "align-items-xs-baseline"
    | Align_Content_Xs_Center(_) => "align-content-xs-center"
    | Align_Content_Xs_Flex_Start(_) => "align-content-xs-flex-start"
    | Align_Content_Xs_Flex_End(_) => "align-content-xs-flex-end"
    | Align_Content_Xs_Space_Between(_) => "align-content-xs-space-between"
    | Align_Content_Xs_Space_Around(_) => "align-content-xs-space-around"
    | Justify_Xs_Center(_) => "justify-xs-center"
    | Justify_Xs_Flex_End(_) => "justify-xs-flex-end"
    | Justify_Xs_Space_Between(_) => "justify-xs-space-between"
    | Justify_Xs_Space_Around(_) => "justify-xs-space-around"
    | Spacing_Xs_8(_) => "spacing-xs-8"
    | Spacing_Xs_16(_) => "spacing-xs-16"
    | Spacing_Xs_24(_) => "spacing-xs-24"
    | Spacing_Xs_40(_) => "spacing-xs-40"
    | Grid_Xs(_) => "grid-xs"
    | Grid_Xs_1(_) => "grid-xs-1"
    | Grid_Xs_2(_) => "grid-xs-2"
    | Grid_Xs_3(_) => "grid-xs-3"
    | Grid_Xs_4(_) => "grid-xs-4"
    | Grid_Xs_5(_) => "grid-xs-5"
    | Grid_Xs_6(_) => "grid-xs-6"
    | Grid_Xs_7(_) => "grid-xs-7"
    | Grid_Xs_8(_) => "grid-xs-8"
    | Grid_Xs_9(_) => "grid-xs-9"
    | Grid_Xs_10(_) => "grid-xs-10"
    | Grid_Xs_11(_) => "grid-xs-11"
    | Grid_Xs_12(_) => "grid-xs-12";
  let to_obj = listOfClasses =>
    listOfClasses
    |> StdLabels.List.fold_left(
         ~f=
           (obj, classType) => {
             switch (classType) {
             | Container(className)
             | Item(className)
             | ZeroMinWidth(className)
             | Direction_Xs_Column(className)
             | Direction_Xs_Column_Reverse(className)
             | Direction_Xs_Row_Reverse(className)
             | Wrap_Xs_Nowrap(className)
             | Wrap_Xs_Wrap_Reverse(className)
             | Align_Items_Xs_Center(className)
             | Align_Items_Xs_Flex_Start(className)
             | Align_Items_Xs_Flex_End(className)
             | Align_Items_Xs_Baseline(className)
             | Align_Content_Xs_Center(className)
             | Align_Content_Xs_Flex_Start(className)
             | Align_Content_Xs_Flex_End(className)
             | Align_Content_Xs_Space_Between(className)
             | Align_Content_Xs_Space_Around(className)
             | Justify_Xs_Center(className)
             | Justify_Xs_Flex_End(className)
             | Justify_Xs_Space_Between(className)
             | Justify_Xs_Space_Around(className)
             | Spacing_Xs_8(className)
             | Spacing_Xs_16(className)
             | Spacing_Xs_24(className)
             | Spacing_Xs_40(className)
             | Grid_Xs(className)
             | Grid_Xs_1(className)
             | Grid_Xs_2(className)
             | Grid_Xs_3(className)
             | Grid_Xs_4(className)
             | Grid_Xs_5(className)
             | Grid_Xs_6(className)
             | Grid_Xs_7(className)
             | Grid_Xs_8(className)
             | Grid_Xs_9(className)
             | Grid_Xs_10(className)
             | Grid_Xs_11(className)
             | Grid_Xs_12(className) =>
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
    ~alignContent: string=?,
    ~alignItems: string=?,
    ~className: string=?,
    ~component: 'union_rmng=?,
    ~container: bool=?,
    ~direction: string=?,
    ~hidden: Js.t({..})=?,
    ~item: bool=?,
    ~justify: string=?,
    ~lg: string=?,
    ~md: string=?,
    ~sm: string=?,
    ~spacing: 'number_r8st=?,
    ~wrap: string=?,
    ~xl: string=?,
    ~xs: string=?,
    ~zeroMinWidth: bool=?,
    ~classes: Js.Dict.t(string)=?,
    ~style: ReactDOMRe.Style.t=?,
    unit
  ) =>
  _ =
  "";

[@bs.module "material-ui/Grid/Grid"]
external reactClass : ReasonReact.reactClass = "default";

let make =
    (
      ~alignContent: option(alignContent)=?,
      ~alignItems: option(alignItems)=?,
      ~className: option(string)=?,
      ~component: option([ | `String(string) | `Callback('genericCallback)])=?,
      ~container: option(bool)=?,
      ~direction: option(direction)=?,
      ~hidden: option(Js.t({..}))=?,
      ~item: option(bool)=?,
      ~justify: option(justify)=?,
      ~lg: option(lg)=?,
      ~md: option(md)=?,
      ~sm: option(sm)=?,
      ~spacing: option(spacing)=?,
      ~wrap: option(wrap)=?,
      ~xl: option(xl)=?,
      ~xs: option(xs)=?,
      ~zeroMinWidth: option(bool)=?,
      ~classes: option(Classes.t)=?,
      ~style: option(ReactDOMRe.Style.t)=?,
      children,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=
      makeProps(
        ~alignContent=?
          Js.Option.map((. v) => alignContentToJs(v), alignContent),
        ~alignItems=?Js.Option.map((. v) => alignItemsToJs(v), alignItems),
        ~className?,
        ~component=?
          Js.Option.map(
            (. v) => MaterialUi_Helpers.unwrapValue(v),
            component,
          ),
        ~container?,
        ~direction=?Js.Option.map((. v) => directionToJs(v), direction),
        ~hidden?,
        ~item?,
        ~justify=?Js.Option.map((. v) => justifyToJs(v), justify),
        ~lg=?Js.Option.map((. v) => lgToJs(v), lg),
        ~md=?Js.Option.map((. v) => mdToJs(v), md),
        ~sm=?Js.Option.map((. v) => smToJs(v), sm),
        ~spacing=?Js.Option.map((. v) => spacingToJs(v), spacing),
        ~wrap=?Js.Option.map((. v) => wrapToJs(v), wrap),
        ~xl=?Js.Option.map((. v) => xlToJs(v), xl),
        ~xs=?Js.Option.map((. v) => xsToJs(v), xs),
        ~zeroMinWidth?,
        ~classes=?Js.Option.map((. v) => Classes.to_obj(v), classes),
        ~style?,
        (),
      ),
    children,
  );
