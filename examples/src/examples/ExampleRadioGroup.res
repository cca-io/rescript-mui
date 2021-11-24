type answer = [#Yes | #No | #Maybe]

@react.component
let make = () => {
  let (state, setState) = React.useState(() => #Yes)

  open MaterialUi
  <RadioGroup
    name="answer"
    value={Any.make(state)}
    onChange={e => {
      let value = (e->ReactEvent.Form.target)["value"]
      setState(_ => value->Any.unsafeGetValue)
    }}>
    <FormControlLabel value={Any.make(#Yes)} control={<Radio />} label={React.string("Yes")} />
    <FormControlLabel value={Any.make(#No)} control={<Radio />} label={React.string("No")} />
    <FormControlLabel value={Any.make(#Maybe)} control={<Radio />} label={React.string("Maybe")} />
  </RadioGroup>
}
