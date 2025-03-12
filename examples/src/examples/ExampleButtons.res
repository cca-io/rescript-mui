open Mui

@react.component
let make = () => {
  <>
    <IconButton id="icon-button-1" color=Primary>
      <Icon id="icon-1">{React.string("AddCircleFilled")}</Icon>
    </IconButton>
    <Button id="button-1" variant=Text color=Primary>
      {React.string("Text Button")}
    </Button>
    <Button id="button-2" variant=Outlined color=Primary>
      {React.string("Outlined Button")}
    </Button>
    <Button id="button-3" variant=Contained color=Primary>
      {React.string("Contained Button")}
    </Button>
  </>
}