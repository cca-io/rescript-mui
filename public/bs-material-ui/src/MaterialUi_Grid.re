type alignContent = [
  | `Stretch
  | `Center
  | `Flex_Start
  | `Flex_End
  | `Space_Between
  | `Space_Around
];

type alignItems = [
  | `Flex_Start
  | `Center
  | `Flex_End
  | `Stretch
  | `Baseline
];

module Classes = {
  type t = {
    .
    "root": option(option(string)),
    "container": option(option(string)),
    "item": option(option(string)),
    "zeroMinWidth": option(option(string)),
    "direction_xs_column": option(option(string)),
    "direction_xs_column_reverse": option(option(string)),
    "direction_xs_row_reverse": option(option(string)),
    "wrap_xs_nowrap": option(option(string)),
    "wrap_xs_wrap_reverse": option(option(string)),
    "align_items_xs_center": option(option(string)),
    "align_items_xs_flex_start": option(option(string)),
    "align_items_xs_flex_end": option(option(string)),
    "align_items_xs_baseline": option(option(string)),
    "align_content_xs_center": option(option(string)),
    "align_content_xs_flex_start": option(option(string)),
    "align_content_xs_flex_end": option(option(string)),
    "align_content_xs_space_between": option(option(string)),
    "align_content_xs_space_around": option(option(string)),
    "justify_xs_center": option(option(string)),
    "justify_xs_flex_end": option(option(string)),
    "justify_xs_space_between": option(option(string)),
    "justify_xs_space_around": option(option(string)),
    "justify_xs_space_evenly": option(option(string)),
    "spacing_xs_1": option(option(string)),
    "spacing_xs_2": option(option(string)),
    "spacing_xs_3": option(option(string)),
    "spacing_xs_4": option(option(string)),
    "spacing_xs_5": option(option(string)),
    "spacing_xs_6": option(option(string)),
    "spacing_xs_7": option(option(string)),
    "spacing_xs_8": option(option(string)),
    "spacing_xs_9": option(option(string)),
    "spacing_xs_10": option(option(string)),
    "grid_xs_auto": option(option(string)),
    "grid_xs_true": option(option(string)),
    "grid_xs_1": option(option(string)),
    "grid_xs_2": option(option(string)),
    "grid_xs_3": option(option(string)),
    "grid_xs_4": option(option(string)),
    "grid_xs_5": option(option(string)),
    "grid_xs_6": option(option(string)),
    "grid_xs_7": option(option(string)),
    "grid_xs_8": option(option(string)),
    "grid_xs_9": option(option(string)),
    "grid_xs_10": option(option(string)),
    "grid_xs_11": option(option(string)),
    "grid_xs_12": option(option(string)),
  };
  [@bs.obj]
  external make:
    (
      ~root: string=?,
      ~container: string=?,
      ~item: string=?,
      ~zeroMinWidth: string=?,
      ~direction_xs_column: string=?,
      ~direction_xs_column_reverse: string=?,
      ~direction_xs_row_reverse: string=?,
      ~wrap_xs_nowrap: string=?,
      ~wrap_xs_wrap_reverse: string=?,
      ~align_items_xs_center: string=?,
      ~align_items_xs_flex_start: string=?,
      ~align_items_xs_flex_end: string=?,
      ~align_items_xs_baseline: string=?,
      ~align_content_xs_center: string=?,
      ~align_content_xs_flex_start: string=?,
      ~align_content_xs_flex_end: string=?,
      ~align_content_xs_space_between: string=?,
      ~align_content_xs_space_around: string=?,
      ~justify_xs_center: string=?,
      ~justify_xs_flex_end: string=?,
      ~justify_xs_space_between: string=?,
      ~justify_xs_space_around: string=?,
      ~justify_xs_space_evenly: string=?,
      ~spacing_xs_1: string=?,
      ~spacing_xs_2: string=?,
      ~spacing_xs_3: string=?,
      ~spacing_xs_4: string=?,
      ~spacing_xs_5: string=?,
      ~spacing_xs_6: string=?,
      ~spacing_xs_7: string=?,
      ~spacing_xs_8: string=?,
      ~spacing_xs_9: string=?,
      ~spacing_xs_10: string=?,
      ~grid_xs_auto: string=?,
      ~grid_xs_true: string=?,
      ~grid_xs_1: string=?,
      ~grid_xs_2: string=?,
      ~grid_xs_3: string=?,
      ~grid_xs_4: string=?,
      ~grid_xs_5: string=?,
      ~grid_xs_6: string=?,
      ~grid_xs_7: string=?,
      ~grid_xs_8: string=?,
      ~grid_xs_9: string=?,
      ~grid_xs_10: string=?,
      ~grid_xs_11: string=?,
      ~grid_xs_12: string=?,
      unit
    ) =>
    t;
};

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

type direction = [ | `Row | `Row_Reverse | `Column | `Column_Reverse];

type justify = [
  | `Flex_Start
  | `Center
  | `Flex_End
  | `Space_Between
  | `Space_Around
  | `Space_Evenly
];

module Lg: {
  type t;
  let _false: t;
  let auto: t;
  let _true: t;
  let _1: t;
  let _2: t;
  let _3: t;
  let _4: t;
  let _5: t;
  let _6: t;
  let _7: t;
  let _8: t;
  let _9: t;
  let _10: t;
  let _11: t;
  let _12: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let _false = Any(false);
  let auto = Any("auto");
  let _true = Any(true);
  let _1 = Any(1);
  let _2 = Any(2);
  let _3 = Any(3);
  let _4 = Any(4);
  let _5 = Any(5);
  let _6 = Any(6);
  let _7 = Any(7);
  let _8 = Any(8);
  let _9 = Any(9);
  let _10 = Any(10);
  let _11 = Any(11);
  let _12 = Any(12);
};

module Md: {
  type t;
  let _false: t;
  let auto: t;
  let _true: t;
  let _1: t;
  let _2: t;
  let _3: t;
  let _4: t;
  let _5: t;
  let _6: t;
  let _7: t;
  let _8: t;
  let _9: t;
  let _10: t;
  let _11: t;
  let _12: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let _false = Any(false);
  let auto = Any("auto");
  let _true = Any(true);
  let _1 = Any(1);
  let _2 = Any(2);
  let _3 = Any(3);
  let _4 = Any(4);
  let _5 = Any(5);
  let _6 = Any(6);
  let _7 = Any(7);
  let _8 = Any(8);
  let _9 = Any(9);
  let _10 = Any(10);
  let _11 = Any(11);
  let _12 = Any(12);
};

module Sm: {
  type t;
  let _false: t;
  let auto: t;
  let _true: t;
  let _1: t;
  let _2: t;
  let _3: t;
  let _4: t;
  let _5: t;
  let _6: t;
  let _7: t;
  let _8: t;
  let _9: t;
  let _10: t;
  let _11: t;
  let _12: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let _false = Any(false);
  let auto = Any("auto");
  let _true = Any(true);
  let _1 = Any(1);
  let _2 = Any(2);
  let _3 = Any(3);
  let _4 = Any(4);
  let _5 = Any(5);
  let _6 = Any(6);
  let _7 = Any(7);
  let _8 = Any(8);
  let _9 = Any(9);
  let _10 = Any(10);
  let _11 = Any(11);
  let _12 = Any(12);
};

type spacing = [
  | `V0
  | `V1
  | `V2
  | `V3
  | `V4
  | `V5
  | `V6
  | `V7
  | `V8
  | `V9
  | `V10
];

type wrap = [ | `Nowrap | `Wrap | `Wrap_Reverse];

module Xl: {
  type t;
  let _false: t;
  let auto: t;
  let _true: t;
  let _1: t;
  let _2: t;
  let _3: t;
  let _4: t;
  let _5: t;
  let _6: t;
  let _7: t;
  let _8: t;
  let _9: t;
  let _10: t;
  let _11: t;
  let _12: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let _false = Any(false);
  let auto = Any("auto");
  let _true = Any(true);
  let _1 = Any(1);
  let _2 = Any(2);
  let _3 = Any(3);
  let _4 = Any(4);
  let _5 = Any(5);
  let _6 = Any(6);
  let _7 = Any(7);
  let _8 = Any(8);
  let _9 = Any(9);
  let _10 = Any(10);
  let _11 = Any(11);
  let _12 = Any(12);
};

module Xs: {
  type t;
  let _false: t;
  let auto: t;
  let _true: t;
  let _1: t;
  let _2: t;
  let _3: t;
  let _4: t;
  let _5: t;
  let _6: t;
  let _7: t;
  let _8: t;
  let _9: t;
  let _10: t;
  let _11: t;
  let _12: t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;

  let _false = Any(false);
  let auto = Any("auto");
  let _true = Any(true);
  let _1 = Any(1);
  let _2 = Any(2);
  let _3 = Any(3);
  let _4 = Any(4);
  let _5 = Any(5);
  let _6 = Any(6);
  let _7 = Any(7);
  let _8 = Any(8);
  let _9 = Any(9);
  let _10 = Any(10);
  let _11 = Any(11);
  let _12 = Any(12);
};

[@react.component] [@bs.module "@material-ui/core"]
external make:
  (
    ~alignContent: option(
                     [@bs.string] [
                       | [@bs.as "stretch"] `Stretch
                       | [@bs.as "center"] `Center
                       | [@bs.as "flex-start"] `Flex_Start
                       | [@bs.as "flex-end"] `Flex_End
                       | [@bs.as "space-between"] `Space_Between
                       | [@bs.as "space-around"] `Space_Around
                     ],
                   )
                     =?,
    ~alignItems: option(
                   [@bs.string] [
                     | [@bs.as "flex-start"] `Flex_Start
                     | [@bs.as "center"] `Center
                     | [@bs.as "flex-end"] `Flex_End
                     | [@bs.as "stretch"] `Stretch
                     | [@bs.as "baseline"] `Baseline
                   ],
                 )
                   =?,
    ~children: option('children)=?,
    ~classes: option(Classes.t)=?,
    ~className: option(string)=?,
    ~component: option(Component.t)=?,
    ~container: option(bool)=?,
    ~direction: option(
                  [@bs.string] [
                    | [@bs.as "row"] `Row
                    | [@bs.as "row-reverse"] `Row_Reverse
                    | [@bs.as "column"] `Column
                    | [@bs.as "column-reverse"] `Column_Reverse
                  ],
                )
                  =?,
    ~item: option(bool)=?,
    ~justify: option(
                [@bs.string] [
                  | [@bs.as "flex-start"] `Flex_Start
                  | [@bs.as "center"] `Center
                  | [@bs.as "flex-end"] `Flex_End
                  | [@bs.as "space-between"] `Space_Between
                  | [@bs.as "space-around"] `Space_Around
                  | [@bs.as "space-evenly"] `Space_Evenly
                ],
              )
                =?,
    ~lg: option(Lg.t)=?,
    ~md: option(Md.t)=?,
    ~sm: option(Sm.t)=?,
    ~spacing: option(
                [@bs.int] [
                  | [@bs.as 0] `V0
                  | [@bs.as 1] `V1
                  | [@bs.as 2] `V2
                  | [@bs.as 3] `V3
                  | [@bs.as 4] `V4
                  | [@bs.as 5] `V5
                  | [@bs.as 6] `V6
                  | [@bs.as 7] `V7
                  | [@bs.as 8] `V8
                  | [@bs.as 9] `V9
                  | [@bs.as 10] `V10
                ],
              )
                =?,
    ~wrap: option(
             [@bs.string] [
               | [@bs.as "nowrap"] `Nowrap
               | [@bs.as "wrap"] `Wrap
               | [@bs.as "wrap-reverse"] `Wrap_Reverse
             ],
           )
             =?,
    ~xl: option(Xl.t)=?,
    ~xs: option(Xs.t)=?,
    ~zeroMinWidth: option(bool)=?,
    ~id: option(string)=?,
    ~key: option(string)=?,
    ~ref: option(ReactDOMRe.domRef)=?
  ) =>
  React.element =
  "Grid";
