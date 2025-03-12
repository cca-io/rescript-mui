open Mui

@react.component
let make = () => {
  let (selectedValue, setSelectedValue) = React.useState(_ => "a")

  let handleChange = (event, _) => {
    setSelectedValue(_ => ReactEvent.Form.target(event)["value"])
  }

  let controlProps = (item) => {
    {
      Radio.checked: selectedValue === item,
      onChange: handleChange,
      value: item,
      name: "radio-buttons-group",
      inputProps: {ariaLabel: item},
    }
  }

  <div>
    <Typography variant=H6> {"Radio Examples:"->React.string} </Typography>
    <Box>
      <FormControl>
        <FormLabel id="radio-buttons-group-label"> {"Gender"->React.string} </FormLabel>
        <RadioGroup
          ariaLabelledby="radio-buttons-group-label"
          defaultValue="female"
          name="radio-buttons-group"
          id="radio-group-example">
          <FormControlLabel value="female" control={<Radio id="radio-female" />} label={"Female"->React.string} />
          <FormControlLabel value="male" control={<Radio id="radio-male" />} label={"Male"->React.string} />
          <FormControlLabel value="other" control={<Radio id="radio-other" />} label={"Other"->React.string} />
        </RadioGroup>
      </FormControl>
      
      <Box>
        <Radio {...controlProps("a")} id="radio-custom-a" />
        <Radio {...controlProps("b")} id="radio-custom-b" />
        <Radio {...controlProps("c")} id="radio-custom-c" color=Success />
        <Radio {...controlProps("d")} id="radio-custom-d" color=Error />
        <Radio {...controlProps("e")} id="radio-custom-e" color=Info />
        <Radio
          {...controlProps("f")}
          id="radio-custom-f"
        />
      </Box>
    </Box>
  </div>
}
