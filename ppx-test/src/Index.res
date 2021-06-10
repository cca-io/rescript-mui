module App = {
  open MaterialUi

  @react.component
  let make = () => <>
    <NewImplementation />
    <br />
    <br />
    <NewImplementationTheme />
    <br />
    <br />
    <center> <Typography variant=#h4> "PPX Result" </Typography> </center>
    <br />
    <br />
    <NewImplementationPpx />
    <br />
    <br />
    <NewImplementationThemePpx />
  </>
}

switch ReactDOM.querySelector("#app") {
| Some(domElement) => ReactDOM.render(<App />, domElement)
| None => ()
}
