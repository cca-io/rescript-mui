module ExampleApp = {
  let component = ReasonReact.statelessComponent(__MODULE__);

  let make = _children => {...component, render: _self => <AppLayout />};
};

ReactDOMRe.renderToElementWithId(<ExampleApp />, "app");