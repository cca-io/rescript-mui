switch ReactDOM.querySelector("#app") {
| Some(domElement) =>
  open ReactDOM.Client

  createRoot(domElement)->Root.render(<App />)
| None => ()
}
