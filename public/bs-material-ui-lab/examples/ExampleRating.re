[@react.component]
let make = () => {
  let (value, setValue) = React.useReducer((_, v) => v, 2);

  MaterialUi.(
    MaterialUi_Lab.(
      <div>
        <Box
          component={Box.Component.string("fieldset")}
          mb={Box.Value.int(3)}
          borderColor={Box.Value.string("transparent")}>
          <Typography component={Typography.Component.string("legend")}>
            "Controlled"
          </Typography>
          <Rating
            name="simple-controlled"
            value={Number.int(value)}
            onChange={(event, newValue) => {setValue(newValue)}}
          />
        </Box>
        <Box
          component={Box.Component.string("fieldset")}
          mb={Box.Value.int(3)}
          borderColor={Box.Value.string("transparent")}>
          <Typography component={Typography.Component.string("legend")}>
            "Read only"
          </Typography>
          <Rating name="read-only" value={Number.int(value)} readOnly=true />
        </Box>
        <Box
          component={Box.Component.string("fieldset")}
          mb={Box.Value.int(3)}
          borderColor={Box.Value.string("transparent")}>
          <Typography component={Typography.Component.string("legend")}>
            "Disabled"
          </Typography>
          <Rating name="disabled" value={Number.int(value)} disabled=true />
        </Box>
        <Box
          component={Box.Component.string("fieldset")}
          mb={Box.Value.int(3)}
          borderColor={Box.Value.string("transparent")}>
          <Typography component={Typography.Component.string("legend")}>
            "Pristine"
          </Typography>
          <Rating name="pristine" value={Number.int(0)} />
        </Box>
      </div>
    )
  );
};