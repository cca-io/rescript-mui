switch ReactDOM.querySelector("#app") {
| Some(domElement) => ReactDOM.render(<App />, domElement)
| None => ()
}
