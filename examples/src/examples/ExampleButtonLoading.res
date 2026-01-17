open Mui

@react.component
let make = () => {
  let (loading, setLoading) = React.useState(_ => false)

  let handleClick = _ => {
    setLoading(_ => true)
    // Simulate async operation
    let _ = Js.Global.setTimeout(() => setLoading(_ => false), 2000)
  }

  <div>
    <Typography variant=H6> {"Button Loading Examples:"->React.string} </Typography>
    <Box sx={Sx.obj({display: String("flex"), flexDirection: String("column"), gap: String("16px"), maxWidth: String("300px")})}>
      // Basic loading button
      <Button
        id="button-loading-basic"
        variant=Contained
        loading={loading ? True : False}
        onClick=handleClick>
        {"Click to Load"->React.string}
      </Button>
      // Loading with different positions
      <Typography variant=Subtitle2> {"Loading Positions:"->React.string} </Typography>
      <Button
        id="button-loading-center"
        variant=Contained
        loading=True
        loadingPosition=Center>
        {"Center (default)"->React.string}
      </Button>
      <Button
        id="button-loading-start"
        variant=Contained
        loading=True
        loadingPosition=Start
        startIcon={<span> {">"->React.string} </span>}>
        {"Start Position"->React.string}
      </Button>
      <Button
        id="button-loading-end"
        variant=Contained
        loading=True
        loadingPosition=End
        endIcon={<span> {">"->React.string} </span>}>
        {"End Position"->React.string}
      </Button>
      // Custom loading indicator
      <Typography variant=Subtitle2> {"Custom Loading Indicator:"->React.string} </Typography>
      <Button
        id="button-loading-custom"
        variant=Outlined
        loading=True
        loadingIndicator={<span> {"Loading..."->React.string} </span>}>
        {"Submit"->React.string}
      </Button>
      // Loading with different variants
      <Typography variant=Subtitle2> {"Loading with Variants:"->React.string} </Typography>
      <Button id="button-loading-text" variant=Text loading=True>
        {"Text"->React.string}
      </Button>
      <Button id="button-loading-outlined" variant=Outlined loading=True>
        {"Outlined"->React.string}
      </Button>
      <Button id="button-loading-contained" variant=Contained loading=True>
        {"Contained"->React.string}
      </Button>
      // Loading with colors
      <Typography variant=Subtitle2> {"Loading with Colors:"->React.string} </Typography>
      <Button id="button-loading-primary" variant=Contained color=Primary loading=True>
        {"Primary"->React.string}
      </Button>
      <Button id="button-loading-secondary" variant=Contained color=Secondary loading=True>
        {"Secondary"->React.string}
      </Button>
      <Button id="button-loading-success" variant=Contained color=Success loading=True>
        {"Success"->React.string}
      </Button>
    </Box>
  </div>
}
