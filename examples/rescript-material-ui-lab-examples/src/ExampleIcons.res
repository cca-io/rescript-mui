module SupervisedUserCircle = {
  open Belt.Option

  @deriving(jsConverter)
  type color = [
    | @as("default") #Default
    | @as("error") #Error
    | @as("inherit") #Inherit
    | @as("primary") #Primary
    | @as("secondary") #Secondary
    | @as("textPrimary") #TextPrimary
    | @as("textSecondary") #TextSecondary
  ]

  @deriving(jsConverter)
  type fontSize = [
    | @as("default") #Default
    | @as("inherit") #Inherit
    | @as("small") #Small
    | @as("large") #Large
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
