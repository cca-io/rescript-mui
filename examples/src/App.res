open Mui

@react.component
let make = () => {
  let browserPrefersDark = Core.useMediaQueryString("(prefers-color-scheme: dark)")
  let (modeOverride, setModeOverride) = React.useState(() => None)
  let darkMode = switch modeOverride {
  | Some(darkMode) => darkMode
  | None => browserPrefersDark
  }
  let modeLabel = switch modeOverride {
  | Some(_) => "Dark mode"
  | None => browserPrefersDark ? "System: dark" : "System: light"
  }
  let theme = Theme.create({palette: {mode: darkMode ? "dark" : "light"}})

  <ThemeProvider theme={Theme(theme)}>
    <CssBaseline enableColorScheme=true />
    <Box
      sx={Sx.obj({
        position: String("sticky"),
        top: String("0"),
        zIndex: Number(1200.),
        width: String("100%"),
        boxSizing: String("border-box"),
        display: String("flex"),
        alignItems: Center,
        gap: String("16px"),
        padding: String("8px 16px"),
        bgcolor: BackgroundPaper,
        borderBottom: String("1px solid"),
        borderColor: Divider,
      })}
    >
      <Box
        component={OverridableComponent.string("nav")}
        ariaLabel="Example sections"
        sx={Sx.obj({
          display: String("flex"),
          alignItems: Center,
          gap: String("4px"),
          flex: String("1 1 auto"),
          overflowX: Auto,
          whiteSpace: Nowrap,
        })}
      >
        <Typography variant=Caption color=TextSecondary sx={Sx.obj({fontWeight: Number(700.)})}>
          {"MUI"->React.string}
        </Typography>
        <Button href="#material" size=Small variant=Text color=Inherit>
          {"Material"->React.string}
        </Button>
        <Button href="#lab" size=Small variant=Text color=Inherit>
          {"Lab"->React.string}
        </Button>
        <Divider orientation=Vertical flexItem=true sx={Sx.obj({margin: String("0 8px")})} />
        <Typography variant=Caption color=TextSecondary sx={Sx.obj({fontWeight: Number(700.)})}>
          {"MUI X"->React.string}
        </Typography>
        <Button href="#date-pickers" size=Small variant=Text color=Inherit>
          {"Date Pickers"->React.string}
        </Button>
      </Box>
      <FormControlLabel
        label={modeLabel->React.string}
        sx={Sx.obj({marginRight: String("0"), flexShrink: Number(0.)})}
        control={
          <Switch
            checked=darkMode
            onChange={(_, checked) => setModeOverride(_ => Some(checked))}
            slotProps={input: {ariaLabel: "Toggle dark mode"}}
          />
        }
      />
    </Box>
    <Box
      sx={Sx.obj({
        width: String("100%"),
        minHeight: String("100vh"),
        maxWidth: String("970px"),
        margin: String("0 auto"),
        padding: String("0 16px 48px"),
      })}
    >
      <Box
        id="material"
        sx={Sx.obj({paddingTop: String("48px"), scrollMarginTop: String("64px")})}
      >
        <Examples />
      </Box>
      <Box id="lab" sx={Sx.obj({paddingTop: String("48px"), scrollMarginTop: String("64px")})}>
        <ExamplesLab />
      </Box>
      <Box
        id="date-pickers"
        sx={Sx.obj({paddingTop: String("48px"), scrollMarginTop: String("64px")})}
      >
        <ExamplesXDatePickers />
      </Box>
    </Box>
  </ThemeProvider>
}
