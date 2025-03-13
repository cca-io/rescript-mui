open Mui

@react.component
let make = () => {
  <div>
    <Typography variant=H6> {"Button Group Examples:"->React.string} </Typography>
    <Box>
      <ButtonGroup variant=Contained ariaLabel="contained button group" id="button-group-contained">
        <Button id="btn-group-one">{"One"->React.string}</Button>
        <Button id="btn-group-two">{"Two"->React.string}</Button>
        <Button id="btn-group-three">{"Three"->React.string}</Button>
      </ButtonGroup>
      
      <ButtonGroup variant=Text ariaLabel="text button group" id="button-group-text">
        <Button id="btn-group-text-one">{"One"->React.string}</Button>
        <Button id="btn-group-text-two">{"Two"->React.string}</Button>
        <Button id="btn-group-text-three">{"Three"->React.string}</Button>
      </ButtonGroup>
      
      <ButtonGroup
        variant=Outlined
        color=Secondary
        ariaLabel="outlined secondary button group"
        id="button-group-outlined">
        <Button id="btn-group-outlined-one">{"One"->React.string}</Button>
        <Button id="btn-group-outlined-two">{"Two"->React.string}</Button>
        <Button id="btn-group-outlined-three">{"Three"->React.string}</Button>
      </ButtonGroup>
    </Box>
  </div>
}
