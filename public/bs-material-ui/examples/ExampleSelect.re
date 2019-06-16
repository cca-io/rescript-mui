external jsonTopSpacingFunc: Js.Json.t => (. int) => int = "%identity";
module T = MaterialUi.Theme;
let getSpacing = (theme, num) =>
  theme->T.Theme.spacingGet->jsonTopSpacingFunc(. num)->string_of_int ++ "px";

[%mui.withStyles
  "ExampleStyles"(theme =>
    {
      root:
        ReactDOMRe.Style.make(
          ~display="flex",
          ~flexDirection="column",
          ~flexWrap="wrap",
          (),
        ),
      formControl:
        ReactDOMRe.Style.make(
          ~margin=theme->getSpacing(1),
          ~minWidth="120px",
          (),
        ),

      selectEmpty:
        ReactDOMRe.Style.make(~marginTop=theme->getSpacing(2), ()),
    }
  )
];

type state = {
  age: string,
  name: string,
};

[@react.component]
let make = () => {
  let classes = ExampleStyles.useStyles();

  Js.log(classes);
  let (values, setValues) =
    React.useReducer((_, v) => v, {age: "", name: "hai"});

  let inputLabel = React.useRef(None);
  let (labelWidth, setLabelWidth) = React.useReducer((_, l) => l, 0);
  React.useEffect(() => {
    switch (inputLabel->React.Ref.current) {
    | None => ()
    | Some(current) => setLabelWidth(current->Obj.magic##offsetWidth)
    };
    None;
  });

  let handleChangeAge = (e: ReactEvent.Form.t, _) => {
    setValues({...values, age: e->ReactEvent.Form.target##value});
  };
  let handleChangeName = (e: ReactEvent.Form.t, _) => {
    setValues({...values, name: e->ReactEvent.Form.target##value});
  };

  MaterialUi.(
    <form autoComplete="off">
      <div className={classes.root}>
        <FormControl className={classes.formControl}>
          <InputLabel htmlFor="age-simple"> "Age"->React.string </InputLabel>
          <Select
            value={`String(values.age)}
            onChange=handleChangeAge
            inputProps={"id": "age-simple", "name": "age"}>
            <MenuItem value={`String("")}>
              <em> "None"->React.string </em>
            </MenuItem>
            <MenuItem value={`String("10")}> "Ten"->React.string </MenuItem>
            <MenuItem value={`String("20")}>
              "Twenty"->React.string
            </MenuItem>
            <MenuItem value={`String("30")}>
              "Thirty"->React.string
            </MenuItem>
          </Select>
        </FormControl>
        <FormControl className={classes.formControl}>
          <InputLabel htmlFor="age-helper"> "Age"->React.string </InputLabel>
          <Select
            value={`String(values.age)}
            onChange=handleChangeAge
            input={<Input name="age" id="age-helper" />}>
            <MenuItem value={`String("")}>
              <em> "None"->React.string </em>
            </MenuItem>
            <MenuItem value={`String("10")}> "Ten"->React.string </MenuItem>
            <MenuItem value={`String("20")}>
              "Twenty"->React.string
            </MenuItem>
            <MenuItem value={`String("30")}>
              "Thirty"->React.string
            </MenuItem>
          </Select>
          <FormHelperText>
            "Some important helper text"->React.string
          </FormHelperText>
        </FormControl>
        <FormControl className={classes.formControl}>
          <Select
            value={`String(values.age)}
            onChange=handleChangeAge
            displayEmpty=true
            name="age"
            className={classes.selectEmpty}>
            <MenuItem value={`String("")}>
              <em> "None"->React.string </em>
            </MenuItem>
            <MenuItem value={`String("10")}> "Ten"->React.string </MenuItem>
            <MenuItem value={`String("20")}>
              "Twenty"->React.string
            </MenuItem>
            <MenuItem value={`String("30")}>
              "Thirty"->React.string
            </MenuItem>
          </Select>
          <FormHelperText> "Without label"->React.string </FormHelperText>
        </FormControl>
        <FormControl className={classes.formControl}>
          <InputLabel shrink=true htmlFor="age-label-placeholder">
            "Age"->React.string
          </InputLabel>
          <Select
            value={`String(values.age)}
            onChange=handleChangeAge
            input={<Input name="age" id="age-label-placeholder" />}
            displayEmpty=true
            name="age"
            className={classes.selectEmpty}>
            <MenuItem value={`String("")}>
              <em> "None"->React.string </em>
            </MenuItem>
            <MenuItem value={`String("10")}> "Ten"->React.string </MenuItem>
            <MenuItem value={`String("20")}>
              "Twenty"->React.string
            </MenuItem>
            <MenuItem value={`String("30")}>
              "Thirty"->React.string
            </MenuItem>
          </Select>
          <FormHelperText>
            "Label + placeholder"->React.string
          </FormHelperText>
        </FormControl>
        <FormControl className={classes.formControl} disabled=true>
          <InputLabel htmlFor="name-disabled"> "Name" </InputLabel>
          <Select
            value={`String(values.name)}
            onChange=handleChangeName
            input={<Input name="name" id="name-disabled" />}>
            <MenuItem value={`String("")}>
              <em> "None"->React.string </em>
            </MenuItem>
            <MenuItem value={`String("hai")}> "Hai"->React.string </MenuItem>
            <MenuItem value={`String("olivier")}>
              "Olivier"->React.string
            </MenuItem>
            <MenuItem value={`String("kevin")}>
              "Kevin"->React.string
            </MenuItem>
          </Select>
          <FormHelperText> "Disabled"->React.string </FormHelperText>
        </FormControl>
        <FormControl className={classes.formControl} error=true>
          <InputLabel htmlFor="name-error"> "Name" </InputLabel>
          <Select
            value={`String(values.name)}
            onChange=handleChangeName
            name="name"
            renderValue={value => ({j|⚠️  - |j} ++ value)->React.string}
            input={<Input id="name-error" />}>
            <MenuItem value={`String("")}>
              <em> "None"->React.string </em>
            </MenuItem>
            <MenuItem value={`String("hai")}> "Hai"->React.string </MenuItem>
            <MenuItem value={`String("olivier")}>
              "Olivier"->React.string
            </MenuItem>
            <MenuItem value={`String("kevin")}>
              "Kevin"->React.string
            </MenuItem>
          </Select>
          <FormHelperText> "Error"->React.string </FormHelperText>
        </FormControl>
        <FormControl className={classes.formControl}>
          <InputLabel htmlFor="name-readonly"> "Name" </InputLabel>
          <Select
            value={`String(values.name)}
            onChange=handleChangeName
            input={<Input name="name" id="name-readonly" readOnly=true />}>
            <MenuItem value={`String("")}>
              <em> "None"->React.string </em>
            </MenuItem>
            <MenuItem value={`String("hai")}> "Hai"->React.string </MenuItem>
            <MenuItem value={`String("olivier")}>
              "Olivier"->React.string
            </MenuItem>
            <MenuItem value={`String("kevin")}>
              "Kevin"->React.string
            </MenuItem>
          </Select>
          <FormHelperText> "Read only"->React.string </FormHelperText>
        </FormControl>
        <FormControl className={classes.formControl}>
          <InputLabel htmlFor="age-auto-width">
            "Age"->React.string
          </InputLabel>
          <Select
            value={`String(values.age)}
            onChange=handleChangeAge
            input={<Input name="age" id="age-auto-width" />}
            autoWidth=true>
            <MenuItem value={`String("")}>
              <em> "None"->React.string </em>
            </MenuItem>
            <MenuItem value={`String("10")}> "Ten"->React.string </MenuItem>
            <MenuItem value={`String("20")}>
              "Twenty"->React.string
            </MenuItem>
            <MenuItem value={`String("30")}>
              "Thirty"->React.string
            </MenuItem>
          </Select>
          <FormHelperText> "Auto width"->React.string </FormHelperText>
        </FormControl>
        <FormControl className={classes.formControl}>
          <Select
            value={`String(values.age)}
            onChange=handleChangeAge
            name="age"
            displayEmpty=true
            className={classes.selectEmpty}>
            <MenuItem value={`String("")} disabled=true>
              "Placeholder"
            </MenuItem>
            <MenuItem value={`String("10")}> "Ten"->React.string </MenuItem>
            <MenuItem value={`String("20")}>
              "Twenty"->React.string
            </MenuItem>
            <MenuItem value={`String("30")}>
              "Thirty"->React.string
            </MenuItem>
          </Select>
          <FormHelperText> "Placeholder"->React.string </FormHelperText>
        </FormControl>
        <FormControl required=true className={classes.formControl}>
          <InputLabel htmlFor="age-required"> "Age"->React.string </InputLabel>
          <Select
            value={`String(values.age)}
            onChange=handleChangeAge
            name="age"
            inputProps={"id": "age-required"}
            className={classes.selectEmpty}>
            <MenuItem value={`String("")}>
              <em> "None"->React.string </em>
            </MenuItem>
            <MenuItem value={`String("10")}> "Ten"->React.string </MenuItem>
            <MenuItem value={`String("20")}>
              "Twenty"->React.string
            </MenuItem>
            <MenuItem value={`String("30")}>
              "Thirty"->React.string
            </MenuItem>
          </Select>
          <FormHelperText> "Required"->React.string </FormHelperText>
        </FormControl>
        <FormControl variant=`Outlined className={classes.formControl}>
          <InputLabel htmlFor="outlined-age-simple" ref_=inputLabel>
            "Age"->React.string
          </InputLabel>
          <Select
            value={`String(values.age)}
            onChange=handleChangeAge
            input={
              <OutlinedInput
                labelWidth={`Int(labelWidth)}
                name="age"
                id="outlined-age-simple"
              />
            }>
            <MenuItem value={`String("")}>
              <em> "None"->React.string </em>
            </MenuItem>
            <MenuItem value={`String("10")}> "Ten"->React.string </MenuItem>
            <MenuItem value={`String("20")}>
              "Twenty"->React.string
            </MenuItem>
            <MenuItem value={`String("30")}>
              "Thirty"->React.string
            </MenuItem>
          </Select>
        </FormControl>
        <FormControl variant=`Filled className={classes.formControl}>
          <InputLabel htmlFor="filled-age-simple">
            "Age"->React.string
          </InputLabel>
          <Select
            value={`String(values.age)}
            onChange=handleChangeAge
            input={<FilledInput name="age" id="filled-age-simple" />}>
            <MenuItem value={`String("")}>
              <em> "None"->React.string </em>
            </MenuItem>
            <MenuItem value={`String("10")}> "Ten"->React.string </MenuItem>
            <MenuItem value={`String("20")}>
              "Twenty"->React.string
            </MenuItem>
            <MenuItem value={`String("30")}>
              "Thirty"->React.string
            </MenuItem>
          </Select>
        </FormControl>
      </div>
    </form>
  );
};