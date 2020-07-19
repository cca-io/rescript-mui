module ExampleApp = {
  @react.component
  let make = _ => <AppLayout />
}

ReactDOMRe.renderToElementWithId(<ExampleApp />, "app")
