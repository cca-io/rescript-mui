module App = {
  [@react.component]
  let make = () => {
    <>
      <NewImplementation />
      <br />
      <br />
      <NewImplementationTheme />
      <br />
      <br />
      <center>
        MaterialUi.(<Typography variant=`H4> "PPX Result" </Typography>)
      </center>
      <br />
      <br />
      <NewImplementationPpx />
      <br />
      <br />
      <NewImplementationThemePpx />
    </>;
  };
};
ReactDOMRe.renderToElementWithId(<App />, "app");