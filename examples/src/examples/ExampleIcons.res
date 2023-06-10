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
    <Mui.Typography variant=H6> {"Icon Types:"->rs} </Mui.Typography>
    <Mui.Tooltip title={"Default"->rs} arrow=true placement=Top>
      <span>
        <SupervisedUserCircle.Filled />
      </span>
    </Mui.Tooltip>
    <Mui.Tooltip title={"Outlined"->rs} arrow=true placement=Left>
      <span>
        <SupervisedUserCircle.Outlined />
      </span>
    </Mui.Tooltip>
    <Mui.Tooltip title={"Rounded"->rs} arrow=true placement=TopEnd>
      <span>
        <SupervisedUserCircle.Rounded />
      </span>
    </Mui.Tooltip>
    <Mui.Tooltip title={"TwoTone"->rs} arrow=true placement=Bottom>
      <span>
        <SupervisedUserCircle.TwoTone />
      </span>
    </Mui.Tooltip>
    <Mui.Tooltip title={"Sharp"->rs} arrow=true placement=Right>
      <span>
        <SupervisedUserCircle.Sharp />
      </span>
    </Mui.Tooltip>
  </div>
  <hr />
  <div>
    <Mui.Typography variant=H6> {"Icon Colors:"->rs} </Mui.Typography>
    <Mui.Tooltip title={"Primary"->rs}>
      <span>
        <SupervisedUserCircle.Filled color="primary" />
      </span>
    </Mui.Tooltip>
    <Mui.Tooltip title={"Secondary"->rs}>
      <span>
        <SupervisedUserCircle.Filled color="secondary" />
      </span>
    </Mui.Tooltip>
  </div>
  <hr />
  <div>
    <Mui.Typography variant=H6> {"Icon Sizes:"->rs} </Mui.Typography>
    <Mui.Tooltip title={"Large"->rs}>
      <span>
        <SupervisedUserCircle.Filled fontSize="large" />
      </span>
    </Mui.Tooltip>
    <Mui.Tooltip title={"Default"->rs}>
      <span>
        <SupervisedUserCircle.Filled fontSize="default" />
      </span>
    </Mui.Tooltip>
    <Mui.Tooltip title={"Small"->rs}>
      <span>
        <SupervisedUserCircle.Filled fontSize="small" />
      </span>
    </Mui.Tooltip>
  </div>
</>
