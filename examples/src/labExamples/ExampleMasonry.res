open Mui
open MuiLab

// Sample heights for items to demonstrate masonry layout
let itemHeights = [150, 100, 200, 120, 180, 90, 160, 110, 140, 130, 170, 100]

@react.component
let make = () => {
  <div>
    <Typography variant=H6> {"Masonry Examples:"->React.string} </Typography>
    <Typography variant=Body2 sx={Sx.obj({marginBottom: String("16px")})}>
      {"Masonry lays out contents of varying dimensions as blocks packed in a container."->React.string}
    </Typography>

    // Basic Masonry
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("16px"), marginBottom: String("8px")})}>
      {"Basic Masonry (3 columns):"->React.string}
    </Typography>
    <Box sx={Sx.obj({width: String("100%"), minHeight: String("400px")})}>
      <Masonry id="masonry-basic" columns={Number(3.)} spacing={Number(2.)}>
        {itemHeights
        ->Belt.Array.mapWithIndex((i, height) =>
          <Paper
            key={Belt.Int.toString(i)}
            sx={Sx.obj({
              height: String(Belt.Int.toString(height) ++ "px"),
              display: String("flex"),
              alignItems: Center,
              justifyContent: Center,
              bgcolor: switch mod(i, 4) {
              | 0 => PrimaryLight
              | 1 => SecondaryLight
              | 2 => SuccessLight
              | _ => WarningLight
              },
            })}>
            <Typography> {(Belt.Int.toString(i + 1) ++ " (" ++ Belt.Int.toString(height) ++ "px)")->React.string} </Typography>
          </Paper>
        )
        ->React.array}
      </Masonry>
    </Box>

    // Masonry with different columns
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("24px"), marginBottom: String("8px")})}>
      {"Masonry (4 columns, spacing 1):"->React.string}
    </Typography>
    <Box sx={Sx.obj({width: String("100%"), minHeight: String("300px")})}>
      <Masonry id="masonry-4col" columns={Number(4.)} spacing={Number(1.)}>
        {itemHeights
        ->Belt.Array.slice(~offset=0, ~len=8)
        ->Belt.Array.mapWithIndex((i, height) =>
          <Paper
            key={Belt.Int.toString(i)}
            elevation=3
            sx={Sx.obj({
              height: String(Belt.Int.toString(height) ++ "px"),
              display: String("flex"),
              alignItems: Center,
              justifyContent: Center,
            })}>
            <Typography variant=H6> {Belt.Int.toString(i + 1)->React.string} </Typography>
          </Paper>
        )
        ->React.array}
      </Masonry>
    </Box>

    // Masonry with 2 columns
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("24px"), marginBottom: String("8px")})}>
      {"Masonry (2 columns, spacing 3):"->React.string}
    </Typography>
    <Box sx={Sx.obj({width: String("100%"), minHeight: String("300px")})}>
      <Masonry id="masonry-2col" columns={Number(2.)} spacing={Number(3.)}>
        {itemHeights
        ->Belt.Array.slice(~offset=0, ~len=6)
        ->Belt.Array.mapWithIndex((i, height) =>
          <Card key={Belt.Int.toString(i)} sx={Sx.obj({height: String(Belt.Int.toString(height) ++ "px")})}>
            <CardContent>
              <Typography variant=H5 component={OverridableComponent.string("div")}>
                {("Card " ++ Belt.Int.toString(i + 1))->React.string}
              </Typography>
              <Typography variant=Body2 color=TextSecondary>
                {("Height: " ++ Belt.Int.toString(height) ++ "px")->React.string}
              </Typography>
            </CardContent>
          </Card>
        )
        ->React.array}
      </Masonry>
    </Box>

    // Masonry with images (simulated with colored boxes)
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("24px"), marginBottom: String("8px")})}>
      {"Masonry with colored items:"->React.string}
    </Typography>
    <Box sx={Sx.obj({width: String("100%"), minHeight: String("300px")})}>
      <Masonry id="masonry-colors" columns={Number(3.)} spacing={Number(1.)}>
        {[
          ("#f44336", 120),
          ("#e91e63", 180),
          ("#9c27b0", 100),
          ("#673ab7", 150),
          ("#3f51b5", 200),
          ("#2196f3", 90),
          ("#03a9f4", 160),
          ("#00bcd4", 110),
          ("#009688", 140),
        ]
        ->Belt.Array.mapWithIndex((i, (color, height)) =>
          <Box
            key={Belt.Int.toString(i)}
            sx={Sx.obj({
              height: String(Belt.Int.toString(height) ++ "px"),
              bgcolor: String(color),
              borderRadius: String("8px"),
            })}
          />
        )
        ->React.array}
      </Masonry>
    </Box>
  </div>
}
