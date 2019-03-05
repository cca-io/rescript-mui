module Icons = {
  open MscharleyBsMaterialUiIcons;

  module SupervisedUserCircle_Filled = SupervisedUserCircle.Filled;
  module SupervisedUserCircle_Outlined = SupervisedUserCircle.Outlined;
  module SupervisedUserCircle_Rounded = SupervisedUserCircle.Rounded;
  module SupervisedUserCircle_TwoTone = SupervisedUserCircle.TwoTone;
  module SupervisedUserCircle_Sharp = SupervisedUserCircle.Sharp;
};

let rs = ReasonReact.string;
let component = ReasonReact.statelessComponent(__MODULE__);

let make = _ => {
  ...component,
  render: _ =>
    <>
      <div>
        <MaterialUi_Typography variant=`H6>
          "Icon Types:"
        </MaterialUi_Typography>
        <MaterialUi_Tooltip title={"Default"->rs}>
          <Icons.SupervisedUserCircle_Filled />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Outlined"->rs}>
          <Icons.SupervisedUserCircle_Outlined />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Rounded"->rs}>
          <Icons.SupervisedUserCircle_Rounded />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"TwoTone"->rs}>
          <Icons.SupervisedUserCircle_TwoTone />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Sharp"->rs}>
          <Icons.SupervisedUserCircle_Sharp />
        </MaterialUi_Tooltip>
      </div>
      <hr />
      <div>
        <MaterialUi_Typography variant=`H6>
          "Icon Colors:"
        </MaterialUi_Typography>
        <MaterialUi_Tooltip title={"Primary"->rs}>
          <Icons.SupervisedUserCircle_Filled color=`Primary />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Secondary"->rs}>
          <Icons.SupervisedUserCircle_Filled color=`Secondary />
        </MaterialUi_Tooltip>
      </div>
      <hr />
      <div>
        <MaterialUi_Typography variant=`H6>
          "Icon Sizes:"
        </MaterialUi_Typography>
        <MaterialUi_Tooltip title={"Large"->rs}>
          <Icons.SupervisedUserCircle_Filled fontSize=`Large />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Default"->rs}>
          <Icons.SupervisedUserCircle_Filled fontSize=`Default />
        </MaterialUi_Tooltip>
        <MaterialUi_Tooltip title={"Small"->rs}>
          <Icons.SupervisedUserCircle_Filled fontSize=`Small />
        </MaterialUi_Tooltip>
      </div>
    </>,
};