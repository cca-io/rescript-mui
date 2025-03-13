open Mui

@react.component
let make = () => {
  <div>
    <Typography variant=H6> {"Card Action Area Example:"->React.string} </Typography>
    <Card>
      <CardActionArea id="card-action-area-example">
        <Box>
          <Typography variant=Body2 color={TextSecondary}>
            {"Image Placeholder"->React.string}
          </Typography>
        </Box>
        <CardContent>
          <Typography gutterBottom=true variant=H5 component={OverridableComponent.string("div")}>
            {"Clickable Card"->React.string}
          </Typography>
          <Typography variant=Body2 color={TextSecondary}>
            {"This entire card is clickable because it uses CardActionArea."->React.string}
          </Typography>
        </CardContent>
      </CardActionArea>
      <CardActions>
        <Button size=Small color=Primary id="card-button-share">
          {"Share"->React.string}
        </Button>
        <Button size=Small color=Primary id="card-button-learn-more">
          {"Learn More"->React.string}
        </Button>
      </CardActions>
    </Card>
  </div>
}
