open MaterialUi_Lab

@react.component
let make = () => {
  <div>
    <Alert severity=#error> {`This is an error alert — check it out!`->React.string} </Alert>
    <Alert severity=#warning> {`This is a warning alert — check it out!`->React.string} </Alert>
    <Alert severity=#info> {`This is an info alert — check it out!`->React.string} </Alert>
    <Alert severity=#success> {`This is a success alert — check it out!`->React.string} </Alert>
  </div>
}
