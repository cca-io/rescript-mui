open Mui

@react.component
let make = () => {
  <div>
    <Typography variant=H6> {"Icon Button Examples:"->React.string} </Typography>
    <Box>
      <IconButton ariaLabel="primary" color=Primary id="icon-button-primary">
        <span> {"A"->React.string} </span>
      </IconButton>
      <IconButton ariaLabel="secondary" color=Secondary id="icon-button-secondary">
        <span> {"B"->React.string} </span>
      </IconButton>
      <IconButton ariaLabel="success" color=Success id="icon-button-success">
        <span> {"C"->React.string} </span>
      </IconButton>
      <IconButton ariaLabel="error" color=Error disabled=true id="icon-button-disabled">
        <span> {"D"->React.string} </span>
      </IconButton>
    </Box>
  </div>
}
