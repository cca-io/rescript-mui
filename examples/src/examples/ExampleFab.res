open Mui

@react.component
let make = () => {
  <div>
    <Typography variant=H6> {"Floating Action Button Examples:"->React.string} </Typography>
    <Box >
      <Fab color=Primary ariaLabel="add" id="fab-primary">
        <span> {"+"->React.string} </span>
      </Fab>
      <Fab color=Secondary ariaLabel="edit" id="fab-secondary">
        <span> {"✎"->React.string} </span>
      </Fab>
      <Fab variant=Extended color=Info ariaLabel="navigate" id="fab-extended">
        <span> {"Navigate"->React.string} </span>
      </Fab>
      <Fab disabled=true ariaLabel="disabled" id="fab-disabled">
        <span> {"X"->React.string} </span>
      </Fab>
    </Box>
  </div>
}
