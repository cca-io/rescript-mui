[@react.component]
let make = () => {
  MaterialUi.(
    <div>
      <TextField variant=`Outlined fullWidth=true placeholder="None" />
      <br />
      <br />
      <TextField
        size=`Medium
        variant=`Outlined
        fullWidth=true
        placeholder="Medium"
      />
      <br />
      <br />
      <TextField
        size=`Small
        variant=`Outlined
        fullWidth=true
        placeholder="Small"
      />
    </div>
  );
};
