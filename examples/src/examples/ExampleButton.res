open Mui

@react.component
let make = () => {
  <div>
    <Typography variant=H6> {"Button Examples:"->React.string} </Typography>
    <Box>
      <Button variant=Text id="button-text">
        {"Text"->React.string}
      </Button>
      <Button variant=Contained id="button-contained">
        {"Contained"->React.string}
      </Button>
      <Button variant=Outlined id="button-outlined">
        {"Outlined"->React.string}
      </Button>
      <Button variant=Contained color=Primary id="button-primary">
        {"Primary"->React.string}
      </Button>
      <Button variant=Contained color=Secondary id="button-secondary">
        {"Secondary"->React.string}
      </Button>
      <Button variant=Contained color=Success id="button-success">
        {"Success"->React.string}
      </Button>
      <Button variant=Contained color=Error disabled=true id="button-disabled">
        {"Disabled"->React.string}
      </Button>
    </Box>
  </div>
}
