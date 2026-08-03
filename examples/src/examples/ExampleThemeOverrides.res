open Mui

// Overrides for @mui/lab components live in a separate record type (`MuiLab.Overrides.t`).
let labOverrides: MuiLab.Overrides.t = {
  muiTimelineDot: {
    defaultProps: {variant: MuiLab.TimelineDot.Outlined},
    styleOverrides: {
      root: {borderWidth: "3px", borderColor: "#6a1b9a"},
    },
  },
}

// `components` = theme-level customization: default props + per-CSS-class style overrides.
let theme = Theme.create({
  components: {
    // Lab overrides are a different record type, so they are merged into `components` via interop.
    ...labOverrides->Obj.magic,
    muiButton: {
      defaultProps: {variant: Button.Contained, disableElevation: true},
      styleOverrides: {
        root: {textTransform: "none", borderRadius: "12px"},
      },
    },
    muiChip: {
      styleOverrides: {
        root: {fontWeight: "bold"},
      },
    },
  },
})

@react.component
let make = () =>
  <div>
    <Button color=Primary variant=Text> {"Default Button"->React.string} </Button>
    <ThemeProvider theme=Func(_ => theme)>
      <div style={marginTop: "12px"}>
        // Button picks up the default props (contained, no elevation) + styleOverrides.
        <Button color=Primary> {"Themed Button"->React.string} </Button>
        {" "->React.string}
        <Chip label={"Themed Chip"->React.string} />
        // The lab TimelineDot picks up the merged lab override (outlined, thick purple border).
        <MuiLab.Timeline>
          <MuiLab.TimelineItem>
            <MuiLab.TimelineSeparator>
              <MuiLab.TimelineDot />
              <MuiLab.TimelineConnector />
            </MuiLab.TimelineSeparator>
            <MuiLab.TimelineContent> {"Themed dot"->React.string} </MuiLab.TimelineContent>
          </MuiLab.TimelineItem>
        </MuiLab.Timeline>
      </div>
    </ThemeProvider>
  </div>
