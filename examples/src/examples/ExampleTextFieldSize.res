@react.component
let make = () => {
  open MaterialUi
  <div>
    <TextField variant=#outlined fullWidth=true placeholder="None" />
    <br />
    <br />
    <TextField size=#medium variant=#outlined fullWidth=true placeholder="Medium" />
    <br />
    <br />
    <TextField size=#small variant=#outlined fullWidth=true placeholder="Small" />
  </div>
}
