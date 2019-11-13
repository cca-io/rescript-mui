[@react.component]
let make = () => {
  let (value, setValue) = React.useReducer((_, v) => v, 2);

  let handleChange = (_, newValue: int) => {
    setValue(newValue);
  };

  MaterialUi.(
    <Paper square=true>
      <Tabs
        value indicatorColor=`Primary textColor=`Primary onChange=handleChange>
        <Tab label={"Active"->React.string} />
        <Tab label={"Disabled"->React.string} disabled=true />
        <Tab label={"Active"->React.string} />
      </Tabs>
    </Paper>
  );
};