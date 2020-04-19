module ExpandMoreIcon =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/ExpandMore"]
    external reactClass: React.component('a) = "default";
  });
module ChevronRightIcon =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/ChevronRight"]
    external reactClass: React.component('a) = "default";
  });

[@react.component]
let make = () => {
  MaterialUi_Lab.(
    <MaterialUi_Box height="240px" flexGrow="1" maxWidth="400px" clone=true>
      <TreeView
        defaultCollapseIcon={<ExpandMoreIcon />}
        defaultExpandIcon={<ChevronRightIcon />}>
        <TreeItem nodeId="1" label={"Applications"->React.string}>
          <TreeItem nodeId="2" label={"Calendar"->React.string} />
          <TreeItem nodeId="3" label={"Chrome"->React.string} />
          <TreeItem nodeId="4" label={"Webstorm"->React.string} />
        </TreeItem>
        <TreeItem nodeId="5" label={"Documents"->React.string}>
          <TreeItem nodeId="10" label={"OSS"->React.string} />
          <TreeItem nodeId="6" label={"Material-UI"->React.string}>
            <TreeItem nodeId="7" label={"src"->React.string}>
              <TreeItem nodeId="8" label={"index.js"->React.string} />
              <TreeItem nodeId="9" label={"tree-view.js"->React.string} />
            </TreeItem>
          </TreeItem>
        </TreeItem>
      </TreeView>
    </MaterialUi_Box>
  );
};