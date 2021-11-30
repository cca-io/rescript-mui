open MaterialUi

let useStyles = Styles.makeStyles({
  "root": ReactDOM.Style.make(~width="250px", ()),
  "input": ReactDOM.Style.make(~width="250px", ()),
})

module VolumeUpIcon = {
  @react.component @module("@material-ui/icons/VolumeUp")
  external make: unit => React.element = "default"
}

@react.component
let make = () => {
  let classes = useStyles(.)
  let (value, setValue) = React.useReducer((_, v) => v, 0)

  <div className={classes["root"]}>
    <Typography gutterBottom=true> {"Volume"->React.string} </Typography>
    <Grid container=true spacing=#2 alignItems=#center>
      <Grid item=true> <VolumeUpIcon /> </Grid>
      <Grid item=true xs=Grid.Xs.\"true">
        <Slider
          value={Slider.Value.int(value)}
          onChange={(_, v) => setValue(v)}
          \"aria-labelledby"="input-slider"
        />
      </Grid>
      <Grid item=true>
        <Input
          className={classes["input"]}
          value={Any.fromInt(value)}
          margin=#dense
          onChange={e => setValue((e->ReactEvent.Form.target)["value"]->int_of_string)}
          onBlur={_ =>
            if value < 0 {
              setValue(0)
            } else if value > 100 {
              setValue(100)
            }}
          inputProps={
            "step": 10,
            "min": 0,
            "max": 100,
            "type": "number",
            "aria-labelledby": "input-slider",
          }
        />
      </Grid>
    </Grid>
  </div>
}
