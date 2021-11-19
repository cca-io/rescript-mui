type answer = [#Yes | #No | #Maybe]

@react.component
let make = () => {
  let (state, setState) = React.useState(() => #Yes)

  open MaterialUi
  <RadioGroup
    name="answer"
    value=Any(state)
    onChange={e => {
      let value = (e->ReactEvent.Form.target)["value"]
      setState(_ => value->Types.anyUnpack)
    }}>
    <FormControlLabel value=Any(#Yes) control={<Radio />} label={React.string("Yes")} />
    <FormControlLabel value=Any(#No) control={<Radio />} label={React.string("No")} />
    <FormControlLabel value=Any(#Maybe) control={<Radio />} label={React.string("Maybe")} />
  </RadioGroup>
}
