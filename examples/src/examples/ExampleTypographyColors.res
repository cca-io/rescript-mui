open Mui

@react.component
let make = () =>
  <Box display={String("flex")} flexDirection={Column} gap={Number(1.)}>
    <Typography variant=H6> {"Semantic Colors"->React.string} </Typography>
    <Typography color=Primary> {`Primary — "primary"`->React.string} </Typography>
    <Typography color=Secondary> {`Secondary — "secondary"`->React.string} </Typography>
    <Typography color=Success> {`Success — "success"`->React.string} </Typography>
    <Typography color=Error> {`Error — "error"`->React.string} </Typography>
    <Typography color=Info> {`Info — "info"`->React.string} </Typography>
    <Typography color=Warning> {`Warning — "warning"`->React.string} </Typography>
    <Typography variant=H6> {"Text Colors"->React.string} </Typography>
    <Typography color=TextPrimary> {`TextPrimary — "textPrimary"`->React.string} </Typography>
    <Typography color=TextSecondary>
      {`TextSecondary — "textSecondary"`->React.string}
    </Typography>
    <Typography color=TextDisabled> {`TextDisabled — "textDisabled"`->React.string} </Typography>
    <Typography variant=H6> {"Palette Tokens (dot notation)"->React.string} </Typography>
    <Typography color=PrimaryLight>
      {`PrimaryLight — "primary.light"`->React.string}
    </Typography>
    <Typography color=PrimaryMain> {`PrimaryMain — "primary.main"`->React.string} </Typography>
    <Typography color=PrimaryDark> {`PrimaryDark — "primary.dark"`->React.string} </Typography>
    <Typography color=SecondaryLight>
      {`SecondaryLight — "secondary.light"`->React.string}
    </Typography>
    <Typography color=SecondaryMain>
      {`SecondaryMain — "secondary.main"`->React.string}
    </Typography>
    <Typography color=SecondaryDark>
      {`SecondaryDark — "secondary.dark"`->React.string}
    </Typography>
    <Typography color=ErrorLight> {`ErrorLight — "error.light"`->React.string} </Typography>
    <Typography color=ErrorMain> {`ErrorMain — "error.main"`->React.string} </Typography>
    <Typography color=ErrorDark> {`ErrorDark — "error.dark"`->React.string} </Typography>
    <Typography color=WarningLight>
      {`WarningLight — "warning.light"`->React.string}
    </Typography>
    <Typography color=WarningMain> {`WarningMain — "warning.main"`->React.string} </Typography>
    <Typography color=WarningDark> {`WarningDark — "warning.dark"`->React.string} </Typography>
    <Typography color=InfoLight> {`InfoLight — "info.light"`->React.string} </Typography>
    <Typography color=InfoMain> {`InfoMain — "info.main"`->React.string} </Typography>
    <Typography color=InfoDark> {`InfoDark — "info.dark"`->React.string} </Typography>
    <Typography color=SuccessLight>
      {`SuccessLight — "success.light"`->React.string}
    </Typography>
    <Typography color=SuccessMain> {`SuccessMain — "success.main"`->React.string} </Typography>
    <Typography color=SuccessDark> {`SuccessDark — "success.dark"`->React.string} </Typography>
    <Typography variant=H6> {"Special Colors"->React.string} </Typography>
    <Typography color=Inherit> {`Inherit — "inherit"`->React.string} </Typography>
    <Typography color=Divider> {`Divider — "divider"`->React.string} </Typography>
    <Box bgcolor={BackgroundPaper} p={Number(1.)}>
      <Typography color=BackgroundDefault>
        {`BackgroundDefault — "background.default" (on paper)`->React.string}
      </Typography>
    </Box>
    <Typography variant=H6> {"String Escape Hatch"->React.string} </Typography>
    <Typography color={String("#ff5722")}>
      {`String("#ff5722") — "#ff5722"`->React.string}
    </Typography>
    <Typography color={String("rgb(156, 39, 176)")}>
      {`String("rgb(156, 39, 176)") — "rgb(156, 39, 176)"`->React.string}
    </Typography>
  </Box>
