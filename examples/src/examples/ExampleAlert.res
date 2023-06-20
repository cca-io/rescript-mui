open Mui

@react.component
let make = () => {
  <div>
    <Alert severity=Error> {`This is an error alert — check it out!`->React.string} </Alert>
    <Alert severity=Warning> {`This is a warning alert — check it out!`->React.string} </Alert>
    <Alert severity=Info> {`This is an info alert — check it out!`->React.string} </Alert>
    <Alert severity=Success> {`This is a success alert — check it out!`->React.string} </Alert>
  </div>
}
