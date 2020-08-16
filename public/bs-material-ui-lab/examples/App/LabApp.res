module ExampleApp = {
  @react.component
  let make = _ => <LabLayout />;
};

ReactDOMRe.renderToElementWithId(<ExampleApp />, "app");