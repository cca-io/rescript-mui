external jsonTopSpacingFunc: Js.Json.t => (. int) => int = "%identity";
module T = MaterialUi.Theme;
let getSpacing = (theme, num) =>
  theme->T.Theme.spacingGet->jsonTopSpacingFunc(. num)->string_of_int ++ "px";

[%mui.withStyles
  "ExampleStyles"(theme =>
    {
      root: ReactDOMRe.Style.make(~display="flex", ~flexWrap="wrap", ()),
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
  let (values, setValues) =
    React.useReducer((_, v) => v, {age: "", name: "hai"});

  let handleChangeAge = (e: ReactEvent.Form.t, _) => {
    setValues({...values, age: e->ReactEvent.Form.target##value});
  };

  MaterialUi.(
    <form className={classes.root} autoComplete="off">
      <FormControl className={classes.formControl}>
        <InputLabel muiFormControl={"htmlFor": "age-simple"}>
          "Age"->React.string
        </InputLabel>
        <Select
          value={`String(values.age)}
          onChange=handleChangeAge
          inputProps={"id": "age-simple", "name": "ageSimple"}>
          <MenuItem value={`String("")}>
            <em> "None"->React.string </em>
          </MenuItem>
          <MenuItem value={`String("10")}> "Ten"->React.string </MenuItem>
          <MenuItem value={`String("20")}> "Twenty"->React.string </MenuItem>
          <MenuItem value={`String("30")}> "Thirty"->React.string </MenuItem>
        </Select>
      </FormControl>
    </form>
  );
};