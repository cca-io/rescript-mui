@react.component
let make = () =>
  <MuiXDatePickers.LocalizationProvider dateAdapter={MuiXDatePickers.AdapterDayjs.make}>
    <Mui.Box>
      <Mui.Stack spacing={Number(1.)}>
        <Mui.Typography variant=H3> {"MUI X Date and Time Pickers"->React.string} </Mui.Typography>
        <Mui.Typography variant=Body1 color=TextSecondary>
          {"ReScript ports of the upstream MUI X Community examples. Each card names the source demo family it exercises. Pro range pickers are intentionally excluded because this package binds @mui/x-date-pickers, not @mui/x-date-pickers-pro."->React.string}
        </Mui.Typography>
        <Mui.Typography variant=Body2>
          <a
            href="https://github.com/mui/mui-x/tree/master/docs/data/date-pickers"
            target="_blank"
            rel="noreferrer"
          >
            {"Browse the upstream MUI X examples"->React.string}
          </a>
        </Mui.Typography>
      </Mui.Stack>

      <Mui.Box sx={Mui.Sx.obj({marginTop: String("32px")})}>
        <Mui.Stack spacing={Number(6.)}>
          <ExampleXPickerFamilies />
          <ExampleXFields />
          <ExampleXCalendars />
          <ExampleXClocks />
          <ExampleXValidation />
          <ExampleXCustomization />
        </Mui.Stack>
      </Mui.Box>
    </Mui.Box>
  </MuiXDatePickers.LocalizationProvider>
