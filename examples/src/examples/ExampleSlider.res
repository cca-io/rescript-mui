open Mui

module VolumeUpIcon = {
  @react.component @module("@mui/icons-material/VolumeUp")
  external make: unit => React.element = "default"
}

@react.component
let make = () => {
  let (value, setValue) = React.useReducer((_, v) => v, 0.)

  <div>
    <Typography gutterBottom=true> {"Volume"->React.string} </Typography>
    <Grid container=true spacing=Int(2) alignItems=String("center")>
      <Grid item=true>
        <VolumeUpIcon />
      </Grid>
      <Grid item=true xs=True>
        <Slider value onChange={(_, v, _) => setValue(v)} ariaLabelledby="input-slider" />
      </Grid>
      <Grid item=true>
        <Input
          value
          margin=Dense
          onChange={e => setValue((e->ReactEvent.Form.target)["value"]->float_of_string)}
          onBlur={_ =>
            if value < 0. {
              setValue(0.)
            } else if value > 100. {
              setValue(100.)
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
