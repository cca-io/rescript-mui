switch ReactDOM.querySelector("#app") {
| Some(domElement) => ReactDOM.Client.createRoot(domElement)->ReactDOM.Client.Root.render(<App />)
| None => ()
}
