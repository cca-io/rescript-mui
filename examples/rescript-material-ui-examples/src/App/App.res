switch ReactDOM.querySelector("#app") {
| Some(domElement) => ReactDOM.render(<AppLayout />, domElement)
| None => ()
}
