[@bs.deriving jsConverter]
type placement = [
  | [@bs.as "bottom-end"] `Bottom_End
  | [@bs.as "bottom-start"] `Bottom_Start
  | [@bs.as "bottom"] `Bottom
  | [@bs.as "left-end"] `Left_End
  | [@bs.as "left-start"] `Left_Start
  | [@bs.as "left"] `Left
  | [@bs.as "right-end"] `Right_End
  | [@bs.as "right-start"] `Right_Start
  | [@bs.as "right"] `Right
  | [@bs.as "top-end"] `Top_End
  | [@bs.as "top-start"] `Top_Start
  | [@bs.as "top"] `Top
];
[@bs.obj]
external makePropsMui:
  (
    ~anchorEl: 'union_rld3=?,
    ~children: 'children=?,
    ~container: 'union_ry2g=?,
    ~disablePortal: bool=?,
    ~keepMounted: bool=?,
    ~modifiers: Js.t({..})=?,
    ~_open: bool,
    ~placement: string=?,
    ~popperOptions: Js.t({..})=?,
    ~popperRef: 'union_r8el=?,
    ~transition: bool=?,
    ~key: string=?,
    ~_ref: React.Ref.t(option(Dom.element))=?,
    unit
  ) =>
  _ =
  "";

let makeProps =
    (
      ~anchorEl:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
      ~children: option('children)=?,
      ~container:
         option(
           [ | `ObjectGeneric(Js.t({..})) | `Callback('genericCallback)],
         )=?,
      ~disablePortal: option(bool)=?,
      ~keepMounted: option(bool)=?,
      ~modifiers: option(Js.t({..}))=?,
      ~open_: bool,
      ~placement: option(placement)=?,
      ~popperOptions: option(Js.t({..}))=?,
      ~popperRef:
         option(
           [ | `Callback('genericCallback) | `ObjectGeneric(Js.t({..}))],
         )=?,
      ~transition: option(bool)=?,
      ~key: option(string)=?,
      ~ref_: option(React.Ref.t(option(Dom.element)))=?,
      (),
    ) =>
  makePropsMui(
    ~anchorEl=?
      anchorEl->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~children?,
    ~container=?
      container->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~disablePortal?,
    ~keepMounted?,
    ~modifiers?,
    ~_open=open_,
    ~placement=?placement->(Belt.Option.map(v => placementToJs(v))),
    ~popperOptions?,
    ~popperRef=?
      popperRef->(Belt.Option.map(v => MaterialUi_Helpers.unwrapValue(v))),
    ~transition?,
    ~key?,
    ~_ref=?ref_,
    (),
  );

[@bs.module "@material-ui/core"]
external make: React.component('a) = "Popper";
