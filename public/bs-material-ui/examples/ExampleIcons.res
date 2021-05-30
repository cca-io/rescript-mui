module SupervisedUserCircle = {
  open Belt.Option

  @deriving(jsConverter)
  type color = [
    | #default
    | #error
    | #inherit
    | #primary
    | #secondary
    | #textPrimary
    | #textSecondary
  ]

  @deriving(jsConverter)
  type fontSize = [
    | #default
    | #inherit
    | #small
    | #large
  ]

  @obj
  external makePropsIcon: (
    ~className: string=?,
    ~color: string=?,
    ~fontSize: string=?,
    ~nativeColor: string=?,
    ~titleAccess: string=?,
    ~viewBox: string=?,
    unit,
  ) => _ = ""

  module type IconClass = {
    let reactClass: React.component<'a>
  }

  module Make = (Icon: IconClass) => {
    include Icon

    @react.component
    let make = (
      ~color: option<color>=?,
      ~className: option<string>=?,
      ~fontSize: option<fontSize>=?,
      ~nativeColor: option<string>=?,
      ~titleAccess: option<string>=?,
      ~viewBox: option<string>=?,
    ) =>
      React.createElement(
        reactClass,
        makePropsIcon(
          ~className?,
          ~color=?color->map(colorToJs),
          ~fontSize=?fontSize->map(fontSizeToJs),
          ~nativeColor?,
          ~titleAccess?,
          ~viewBox?,
          (),
        ),
      )
  }

  module Filled = Make({
    @module("@material-ui/icons/SupervisedUserCircle")
    external reactClass: React.component<'a> = "default"
  })

  module Outlined = Make({
    @module("@material-ui/icons/SupervisedUserCircleOutlined")
    external reactClass: React.component<'a> = "default"
  })

  module Rounded = Make({
    @module("@material-ui/icons/SupervisedUserCircleRounded")
    external reactClass: React.component<'a> = "default"
  })

  module Sharp = Make({
    @module("@material-ui/icons/SupervisedUserCircleSharp")
    external reactClass: React.component<'a> = "default"
  })

  module TwoTone = Make({
    @module("@material-ui/icons/SupervisedUserCircleTwoTone")
    external reactClass: React.component<'a> = "default"
  })
}

let rs = React.string

let makeProps = () => ()

@reason.component
let make = () => <>
  <div>
    <MaterialUi_Typography variant=#h6> {"Icon Types:"->rs} </MaterialUi_Typography>
    <MaterialUi_Tooltip title={"Default"->rs} arrow=true placement=#top>
      <span> <SupervisedUserCircle.Filled /> </span>
    </MaterialUi_Tooltip>
    <MaterialUi_Tooltip title={"Outlined"->rs} arrow=true placement=#left>
      <span> <SupervisedUserCircle.Outlined /> </span>
    </MaterialUi_Tooltip>
    <MaterialUi_Tooltip title={"Rounded"->rs} arrow=true placement=#"top-end">
      <span> <SupervisedUserCircle.Rounded /> </span>
    </MaterialUi_Tooltip>
    <MaterialUi_Tooltip title={"TwoTone"->rs} arrow=true placement=#bottom>
      <span> <SupervisedUserCircle.TwoTone /> </span>
    </MaterialUi_Tooltip>
    <MaterialUi_Tooltip title={"Sharp"->rs} arrow=true placement=#right>
      <span> <SupervisedUserCircle.Sharp /> </span>
    </MaterialUi_Tooltip>
  </div>
  <hr />
  <div>
    <MaterialUi_Typography variant=#h6> {"Icon Colors:"->rs} </MaterialUi_Typography>
    <MaterialUi_Tooltip title={"Primary"->rs}>
      <span> <SupervisedUserCircle.Filled color=#primary /> </span>
    </MaterialUi_Tooltip>
    <MaterialUi_Tooltip title={"Secondary"->rs}>
      <span> <SupervisedUserCircle.Filled color=#secondary /> </span>
    </MaterialUi_Tooltip>
  </div>
  <hr />
  <div>
    <MaterialUi_Typography variant=#h6> {"Icon Sizes:"->rs} </MaterialUi_Typography>
    <MaterialUi_Tooltip title={"Large"->rs}>
      <span> <SupervisedUserCircle.Filled fontSize=#large /> </span>
    </MaterialUi_Tooltip>
    <MaterialUi_Tooltip title={"Default"->rs}>
      <span> <SupervisedUserCircle.Filled fontSize=#default /> </span>
    </MaterialUi_Tooltip>
    <MaterialUi_Tooltip title={"Small"->rs}>
      <span> <SupervisedUserCircle.Filled fontSize=#small /> </span>
    </MaterialUi_Tooltip>
  </div>
</>
