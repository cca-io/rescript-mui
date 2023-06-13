switch ReactDOM.querySelector("#root") {
| Some(domElement) =>
  open ReactDOM.Client

  createRoot(domElement)->Root.render(<App />)
| None => ()
}
