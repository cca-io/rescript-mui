switch ReactDOM.querySelector("#app") {
| Some(domElement) => ReactDOM.render(<LabLayout />, domElement)
| None => ()
}
