type answer = Yes | No | Maybe

@react.component
let make = () => {
  let (state, setState) = React.useState(() => Yes)

  open Mui
  <RadioGroup
    name="answer"
    value=state
    onChange={(e, _) => {
      let value = (e->ReactEvent.Form.target)["value"]
      setState(_ => value)
    }}>
    <FormControlLabel value=Yes control={<Radio />} label={React.string("Yes")} />
    <FormControlLabel value=No control={<Radio />} label={React.string("No")} />
    <FormControlLabel value=Maybe control={<Radio />} label={React.string("Maybe")} />
  </RadioGroup>
}
