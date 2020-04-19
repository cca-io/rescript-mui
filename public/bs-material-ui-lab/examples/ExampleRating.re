[@react.component]
let make = () => {
  let (value, setValue) = React.useReducer((_, v) => v, 2);

  MaterialUi.(
    MaterialUi_Lab.(
      <div>
        <Box
          component={`String("fieldset")}
          mb={3->Obj.magic}
          borderColor="transparent">
          <Typography component={`String("legend")}>
            "Controlled"
          </Typography>
          <Rating
            name="simple-controlled"
            value={`Int(value)}
            onChange={(event, newValue) => {setValue(newValue)}}
          />
        </Box>
        <Box
          component={`String("fieldset")}
          mb={3->Obj.magic}
          borderColor="transparent">
          <Typography component={`String("legend")}> "Read only" </Typography>
          <Rating name="read-only" value={`Int(value)} readOnly=true />
        </Box>
        <Box
          component={`String("fieldset")}
          mb={3->Obj.magic}
          borderColor="transparent">
          <Typography component={`String("legend")}> "Disabled" </Typography>
          <Rating name="disabled" value={`Int(value)} disabled=true />
        </Box>
        <Box
          component={`String("fieldset")}
          mb={3->Obj.magic}
          borderColor="transparent">
          <Typography component={`String("legend")}> "Pristine" </Typography>
          <Rating name="pristine" value={`Int(0)} />
        </Box>
      </div>
    )
  );
};