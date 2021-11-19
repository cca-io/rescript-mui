module SupervisedUserCircle = {
  module Filled = {
    @react.component @module("@material-ui/icons/SupervisedUserCircle")
    external make: (~color: string=?, ~fontSize: string=?) => React.element = "default"
  }

  module Outlined = {
    @react.component @module("@material-ui/icons/SupervisedUserCircleOutlined")
    external make: unit => React.element = "default"
  }

  module Rounded = {
    @react.component @module("@material-ui/icons/SupervisedUserCircleRounded")
    external make: unit => React.element = "default"
  }

  module Sharp = {
    @react.component @module("@material-ui/icons/SupervisedUserCircleSharp")
    external make: unit => React.element = "default"
  }

  module TwoTone = {
    @react.component @module("@material-ui/icons/SupervisedUserCircleTwoTone")
    external make: unit => React.element = "default"
  }
}

let rs = React.string

@react.component
let make = () => <>
  <div>
    <MaterialUi.Typography variant=#h6> {"Icon Types:"->rs} </MaterialUi.Typography>
    <MaterialUi.Tooltip title={"Default"->rs} arrow=true placement=#top>
      <span> <SupervisedUserCircle.Filled /> </span>
    </MaterialUi.Tooltip>
    <MaterialUi.Tooltip title={"Outlined"->rs} arrow=true placement=#left>
      <span> <SupervisedUserCircle.Outlined /> </span>
    </MaterialUi.Tooltip>
    <MaterialUi.Tooltip title={"Rounded"->rs} arrow=true placement=#"top-end">
      <span> <SupervisedUserCircle.Rounded /> </span>
    </MaterialUi.Tooltip>
    <MaterialUi.Tooltip title={"TwoTone"->rs} arrow=true placement=#bottom>
      <span> <SupervisedUserCircle.TwoTone /> </span>
    </MaterialUi.Tooltip>
    <MaterialUi.Tooltip title={"Sharp"->rs} arrow=true placement=#right>
      <span> <SupervisedUserCircle.Sharp /> </span>
    </MaterialUi.Tooltip>
  </div>
  <hr />
  <div>
    <MaterialUi.Typography variant=#h6> {"Icon Colors:"->rs} </MaterialUi.Typography>
    <MaterialUi.Tooltip title={"Primary"->rs}>
      <span> <SupervisedUserCircle.Filled color="primary" /> </span>
    </MaterialUi.Tooltip>
    <MaterialUi.Tooltip title={"Secondary"->rs}>
      <span> <SupervisedUserCircle.Filled color="secondary" /> </span>
    </MaterialUi.Tooltip>
  </div>
  <hr />
  <div>
    <MaterialUi.Typography variant=#h6> {"Icon Sizes:"->rs} </MaterialUi.Typography>
    <MaterialUi.Tooltip title={"Large"->rs}>
      <span> <SupervisedUserCircle.Filled fontSize="large" /> </span>
    </MaterialUi.Tooltip>
    <MaterialUi.Tooltip title={"Default"->rs}>
      <span> <SupervisedUserCircle.Filled fontSize="default" /> </span>
    </MaterialUi.Tooltip>
    <MaterialUi.Tooltip title={"Small"->rs}>
      <span> <SupervisedUserCircle.Filled fontSize="small" /> </span>
    </MaterialUi.Tooltip>
  </div>
</>
