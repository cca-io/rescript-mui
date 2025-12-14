open Mui

@react.component
let make = () => {
  <div>
    <Typography variant=H6> {"Slots and SlotProps Examples (MUI v6):"->React.string} </Typography>
    <Typography variant=Body2 sx={Sx.obj({marginBottom: String("16px")})}>
      {"The slots/slotProps pattern allows customizing internal component parts."->React.string}
    </Typography>

    // Alert with slotProps
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("16px")})}>
      {"Alert with slotProps:"->React.string}
    </Typography>
    <Box sx={Sx.obj({display: String("flex"), flexDirection: String("column"), gap: String("8px"), marginBottom: String("16px")})}>
      <Alert
        id="alert-slotprops-basic"
        severity=Info
        slotProps={
          root: {
            style: ReactDOM.Style.make(~border="2px solid blue", ()),
          },
          message: {
            style: ReactDOM.Style.make(~fontStyle="italic", ()),
          },
        }>
        {"Alert with custom root and message styles via slotProps"->React.string}
      </Alert>
      <Alert
        id="alert-slotprops-icon"
        severity=Success
        slotProps={
          icon: {
            style: ReactDOM.Style.make(~fontSize="32px", ()),
          },
        }>
        {"Alert with larger icon via slotProps"->React.string}
      </Alert>
    </Box>

    // Badge with slotProps
    <Typography variant=Subtitle2> {"Badge with slotProps:"->React.string} </Typography>
    <Box sx={Sx.obj({display: String("flex"), gap: String("24px"), marginBottom: String("16px"), alignItems: Center})}>
      <Badge
        id="badge-slotprops-basic"
        badgeContent={"5"->React.string}
        color=Primary
        slotProps={
          badge: {
            style: ReactDOM.Style.make(~transform="scale(1.2)", ()),
          },
        }>
        <Box
          sx={Sx.obj({
            width: String("40px"),
            height: String("40px"),
            bgcolor: String("grey.300"),
            borderRadius: String("4px"),
          })}
        />
      </Badge>
      <Badge
        id="badge-slotprops-root"
        badgeContent={"99+"->React.string}
        color=Error
        slotProps={
          root: {
            style: ReactDOM.Style.make(~padding="8px", ~backgroundColor="#f5f5f5", ()),
          },
        }>
        <Box
          sx={Sx.obj({
            width: String("40px"),
            height: String("40px"),
            bgcolor: String("grey.400"),
            borderRadius: String("4px"),
          })}
        />
      </Badge>
    </Box>

    // TextField with slotProps (new v6 pattern)
    <Typography variant=Subtitle2> {"TextField with slotProps:"->React.string} </Typography>
    <Box sx={Sx.obj({display: String("flex"), flexDirection: String("column"), gap: String("16px"), maxWidth: String("300px")})}>
      <TextField
        id="textfield-slotprops-label"
        label={"Styled Label"->React.string}
        variant=Outlined
        slotProps={
          inputLabel: {
            style: ReactDOM.Style.make(~color="purple", ~fontWeight="bold", ()),
          },
        }
      />
      <TextField
        id="textfield-slotprops-helper"
        label={"With Helper"->React.string}
        helperText={"Custom styled helper text"->React.string}
        variant=Outlined
        slotProps={
          formHelperText: {
            style: ReactDOM.Style.make(~color="green", ~fontStyle="italic", ()),
          },
        }
      />
      <TextField
        id="textfield-slotprops-input"
        label={"Styled Input"->React.string}
        variant=Outlined
        defaultValue="Custom input style"
        slotProps={
          htmlInput: {
            style: ReactDOM.Style.make(~backgroundColor="#fff8e1", ()),
          },
        }
      />
    </Box>

    // Checkbox with slotProps
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("16px")})}>
      {"Checkbox with slotProps:"->React.string}
    </Typography>
    <Box sx={Sx.obj({marginBottom: String("16px")})}>
      <Checkbox
        id="checkbox-slotprops"
        defaultChecked=true
        slotProps={
          input: {
            ariaLabel: "Custom aria label via slotProps",
          },
        }
      />
      <Typography variant=Caption component={OverridableComponent.string("span")}>
        {"Checkbox with custom input props via slotProps"->React.string}
      </Typography>
    </Box>

    // Switch with slotProps
    <Typography variant=Subtitle2> {"Switch with slotProps:"->React.string} </Typography>
    <Box>
      <Switch
        id="switch-slotprops"
        defaultChecked=true
        slotProps={
          input: {
            ariaLabel: "Switch with custom aria label",
          },
        }
      />
      <Typography variant=Caption component={OverridableComponent.string("span")}>
        {"Switch with custom input props via slotProps"->React.string}
      </Typography>
    </Box>
  </div>
}
