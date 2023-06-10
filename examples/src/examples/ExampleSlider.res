open Mui

let useStyles = Styles.makeStyles({
  "root": {JsxDOMStyle.width: "250px"},
  "input": {JsxDOMStyle.width: "250px"},
})

module VolumeUpIcon = {
  @react.component @module("@material-ui/icons/VolumeUp")
  external make: unit => React.element = "default"
}

@react.component
let make = () => {
  let classes = useStyles()
  let (value, setValue) = React.useReducer((_, v) => v, 0)

  <div className={classes["root"]}>
    <Typography gutterBottom=true> {"Volume"->React.string} </Typography>
    <Grid container=true spacing=Int(2) alignItems=String("center")>
      <Grid item=true>
        <VolumeUpIcon />
      </Grid>
      <Grid item=true xs=True>
        <Slider
          value={Slider.Value.int(value)}
          onChange={(_, v) => setValue(v)}
          \"aria-labelledby"="input-slider"
        />
      </Grid>
      <Grid item=true>
        <Input
          className={classes["input"]}
          value
          margin=Dense
          onChange={e => setValue((e->ReactEvent.Form.target)["value"]->int_of_string)}
          onBlur={_ =>
            if value < 0 {
              setValue(0)
            } else if value > 100 {
              setValue(100)
            }}
          inputProps={
            step: 10,
            min: 0,
            max: 100,
            type_: "number",
            ariaLabelledby: "input-slider",
          }
        />
      </Grid>
    </Grid>
  </div>
}
