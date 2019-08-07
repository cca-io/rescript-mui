[%mui.withStyles
  "SliderStyles"({
    root: ReactDOMRe.Style.make(~width="250px", ()),
    input: ReactDOMRe.Style.make(~width="250px", ()),
  })
];

module VolumeUp =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/VolumeUP"]
    external reactClass: React.component('a) = "default";
  });

[@react.component]
let make = () => {
  let (value, setValue) = React.useReducer((_, v) => v, 0);

  MaterialUi.(
    <SliderStyles>
      ...{classes =>
        <div className={classes.root}>
          <Typography gutterBottom=true> "Volume" </Typography>
          <Grid container=true spacing=V2 alignItems=`Center>
            <Grid item=true> <VolumeUp /> </Grid>
            <Grid item=true xsAuto=true>
              <Slider
                value={`Int(value)}
                onChange={(_, v) => setValue(v)}
                aria_labelledby="input-slider"
              />
            </Grid>
            <Grid item=true>
              <Input
                className={classes.input}
                value
                margin=`Dense
                onChange={e =>
                  setValue(e->ReactEvent.Form.target##value->int_of_string)
                }
                onBlur={_ =>
                  if (value < 0) {
                    setValue(0);
                  } else if (value > 100) {
                    setValue(100);
                  }
                }
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
    </SliderStyles>
  );
};