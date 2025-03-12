open Mui

@react.component
let make = () => {
  <div>
    <Typography variant=H6> {"ButtonBase Examples:"->React.string} </Typography>
    <Box>
      <ButtonBase
        id="buttonbase-default">
        {"Default ButtonBase"->React.string}
      </ButtonBase>
      
      <ButtonBase
        id="buttonbase-ripple"
        focusRipple=true>
        {"With Focus Ripple"->React.string}
      </ButtonBase>
      
      <ButtonBase
        id="buttonbase-centered"
        centerRipple=true>
        {"Centered Ripple"->React.string}
      </ButtonBase>
      
      <ButtonBase
        id="buttonbase-disabled"
        disabled=true>
        {"Disabled"->React.string}
      </ButtonBase>
      
      <ButtonBase
        id="buttonbase-component-a"
        href="#">
        {"Link Component"->React.string}
      </ButtonBase>
    </Box>
  </div>
}
