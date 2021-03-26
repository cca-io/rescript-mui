module ExampleApp = {
  @react.component
  let make = _ => <AppLayout />
}

@bs.send @bs.return(nullable)
external getElementById: (Dom.document, string) => option<Dom.element> = "getElementById"

@bs.val external document: Dom.document = "document"

ReactDOM.render(<ExampleApp />, document->getElementById("app")->Belt.Option.getExn)
