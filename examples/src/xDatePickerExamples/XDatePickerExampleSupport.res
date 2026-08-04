module Dayjs = {
  type t

  @module("dayjs") external make: string => t = "default"
  @module("dayjs") external now: unit => t = "default"
  @send external format: (t, string) => string = "format"
  @send external day: t => int = "day"
  @send external date: t => int = "date"
  @send external month: t => int = "month"
  @send external year: t => int = "year"
  @send external hour: t => int = "hour"
  @send external minute: t => int = "minute"
  @send external add: (t, int, string) => t = "add"
}

let value = isoDate => isoDate->Dayjs.make->MuiXDatePickers.DateValue.fromDate

let formatValue = pickerValue =>
  switch pickerValue->MuiXDatePickers.DateValue.toOption {
  | Some(date) => date->Dayjs.format("YYYY-MM-DD HH:mm")
  | None => "Empty"
  }

module Card = {
  @react.component
  let make = (~title: string, ~source: option<string>=?, ~children) =>
    <Mui.Paper
      variant=Outlined
      sx={Mui.Sx.obj({
        padding: String("20px"),
        display: String("flex"),
        flexDirection: String("column"),
        gap: String("16px"),
        minWidth: Number(0.),
      })}
    >
      <Mui.Box>
        <Mui.Typography variant=H6> {title->React.string} </Mui.Typography>
        {switch source {
        | Some(source) =>
          <Mui.Typography variant=Caption color=TextSecondary>
            {("Upstream demo: " ++ source)->React.string}
          </Mui.Typography>
        | None => React.null
        }}
      </Mui.Box>
      {children}
    </Mui.Paper>
}

module Section = {
  @react.component
  let make = (~title: string, ~description: string, ~children) =>
    <Mui.Box
      component={Mui.OverridableComponent.string("section")}
      sx={Mui.Sx.obj({
        display: String("flex"),
        flexDirection: String("column"),
        gap: String("16px"),
      })}
    >
      <Mui.Box>
        <Mui.Typography variant=H5> {title->React.string} </Mui.Typography>
        <Mui.Typography variant=Body2 color=TextSecondary>
          {description->React.string}
        </Mui.Typography>
      </Mui.Box>
      <Mui.Box
        sx={Mui.Sx.obj({
          display: String("grid"),
          gridTemplateColumns: String("repeat(auto-fit, minmax(min(100%, 360px), 1fr))"),
          gap: String("16px"),
          alignItems: String("start"),
        })}
      >
        {children}
      </Mui.Box>
    </Mui.Box>
}
