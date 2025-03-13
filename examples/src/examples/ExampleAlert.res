open Mui

@react.component
let make = () => {
  <div>
    <Alert id="error" severity=Error> {`This is an error alert — check it out!`->React.string} </Alert>
    <Alert id="warning" severity=Warning> {`This is a warning alert — check it out!`->React.string} </Alert>
    <Alert id="info" severity=Info> {`This is an info alert — check it out!`->React.string} </Alert>
    <Alert id="success" severity=Success> {`This is a success alert — check it out!`->React.string} </Alert>
  </div>
}
