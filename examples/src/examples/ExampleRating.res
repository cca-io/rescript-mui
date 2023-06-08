open Mui

@react.component
let make = () => {
  let (value, setValue) = React.useReducer((_, v) => v, 2.)

  <div>
    <Box
      component={OverridableComponent.string("fieldset")}
      mb={Number(3.)}
      borderColor={String("transparent")}>
      <Typography component={OverridableComponent.string("legend")}>
        {"Controlled"->React.string}
      </Typography>
      <Rating
        name="simple-controlled"
        value={Number(value)}
        onChange={(_, newValue) =>
          switch newValue {
          | Number(newValue) => setValue(newValue)
          | _ => ()
          }}
      />
    </Box>
    <Box component={String("fieldset")} mb={Number(3.)} borderColor={String("transparent")}>
      <Typography component={OverridableComponent.string("legend")}>
        {"Read only"->React.string}
      </Typography>
      <Rating name="read-only" value={Number(value)} readOnly=true />
    </Box>
    <Box component={String("fieldset")} mb={Number(3.)} borderColor={String("transparent")}>
      <Typography component={OverridableComponent.string("legend")}>
        {"Disabled"->React.string}
      </Typography>
      <Rating name="disabled" value={Number(value)} disabled=true />
    </Box>
    <Box component={String("fieldset")} mb={Number(3.)} borderColor={String("transparent")}>
      <Typography component={OverridableComponent.string("legend")}>
        {"Pristine"->React.string}
      </Typography>
      <Rating name="pristine" value={Number(0.)} />
    </Box>
  </div>
}
