open Mui

@react.component
let make = () => {
  let (checked, setChecked) = React.useState(_ => true)

  let handleChange = (_event, newChecked) => {
    setChecked(_ => newChecked)
  }

  <div>
    <Typography variant=H6> {"Switch Examples:"->React.string} </Typography>
    <Box >
      <FormGroup>
        <FormControlLabel 
          control={<Switch id="switch-default" defaultChecked=true />} 
          label={"Default"->React.string} 
        />
        <FormControlLabel
          control={
            <Switch 
              id="switch-controlled" 
              checked 
              onChange=handleChange 
            />
          }
          label={"Controlled"->React.string}
        />
        <FormControlLabel 
          control={<Switch id="switch-disabled" disabled=true />} 
          label={"Disabled"->React.string} 
        />
        <FormControlLabel
          control={<Switch id="switch-disabled-checked" disabled=true checked=true />}
          label={"Disabled Checked"->React.string}
        />
        <FormControlLabel
          control={
            <Switch 
              id="switch-color-primary" 
              color=Primary 
              defaultChecked=true 
            />
          }
          label={"Primary Color"->React.string}
        />
        <FormControlLabel
          control={
            <Switch 
              id="switch-color-secondary" 
              color=Secondary 
              defaultChecked=true 
            />
          }
          label={"Secondary Color"->React.string}
        />
        <FormControlLabel
          control={
            <Switch 
              id="switch-color-success" 
              color=Success 
              defaultChecked=true 
            />
          }
          label={"Success Color"->React.string}
        />
        <FormControlLabel
          control={
            <Switch 
              id="switch-color-error" 
              color=Error 
              defaultChecked=true 
            />
          }
          label={"Error Color"->React.string}
        />
      </FormGroup>
    </Box>
  </div>
}
