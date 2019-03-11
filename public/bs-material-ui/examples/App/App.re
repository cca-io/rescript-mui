[@bs.config {jsx: 3}];

module ExampleApp = {
  [@react.component]
  let make = _ => <AppLayout />;
};

ReactDOMRe.renderToElementWithId(<ExampleApp />, "app");