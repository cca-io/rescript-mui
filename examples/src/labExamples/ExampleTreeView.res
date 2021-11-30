open Mui
open MuiLab

module ExpandMoreIcon = {
  @react.component @module("@material-ui/icons/ExpandMore")
  external make: unit => React.element = "default"
}

module ChevronRightIcon = {
  @react.component @module("@material-ui/icons/ChevronRight")
  external make: unit => React.element = "default"
}

@react.component
let make = () => {
  <Box
    height={Box.Value.string("240px")}
    flexGrow={Box.Value.int(1)}
    maxWidth={Box.Value.string("400px")}
    clone=true>
    <TreeView defaultCollapseIcon={<ExpandMoreIcon />} defaultExpandIcon={<ChevronRightIcon />}>
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
  </Box>
}
