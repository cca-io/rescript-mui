open Mui

@react.component
let make = () => {
  let (checked, setChecked) = React.useState(_ => true)
  let (indeterminate, setIndeterminate) = React.useState(_ => true)

  let handleChange = (_event, checked) => {
    setChecked(_ => checked)
  }

  let handleIndeterminateChange = (_event, checked) => {
    setIndeterminate(_ => checked)
  }

  <div>
    <Typography variant=H6> {"Checkbox Examples:"->React.string} </Typography>
    <Box>
      <FormGroup>
        <FormControlLabel
          control={<Checkbox id="checkbox-default" defaultChecked=true />}
          label={"Default"->React.string}
        />
        <FormControlLabel
          control={
            <Checkbox 
              id="checkbox-controlled" 
              checked 
              onChange=handleChange 
            />
          }
          label={"Controlled"->React.string}
        />
        <FormControlLabel
          control={
            <Checkbox 
              id="checkbox-indeterminate" 
              indeterminate=indeterminate 
              checked={!indeterminate && checked} 
              onChange=handleIndeterminateChange
            />
          }
          label={"Indeterminate"->React.string}
        />
        <FormControlLabel
          control={<Checkbox id="checkbox-disabled" disabled=true />}
          label={"Disabled"->React.string}
        />
        <FormControlLabel
          control={
            <Checkbox 
              id="checkbox-color-success" 
              color=Success 
              defaultChecked=true 
            />
          }
          label={"Success Color"->React.string}
        />
        <FormControlLabel
          control={
            <Checkbox 
              id="checkbox-color-error" 
              color=Error 
              defaultChecked=true 
            />
          }
          label={"Error Color"->React.string}
        />
        <FormControlLabel
          control={
            <Checkbox 
              id="checkbox-icon" 
              icon={<span>{"☐"->React.string}</span>} 
              checkedIcon={<span>{"☑"->React.string}</span>}
              defaultChecked=true 
            />
          }
          label={"Custom Icon"->React.string}
        />
      </FormGroup>
    </Box>
  </div>
}
