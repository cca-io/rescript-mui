open Mui

module FormatAlignLeftIcon = {
  @react.component @module("@mui/icons-material/FormatAlignLeft")
  external make: unit => React.element = "default"
}
module FormatAlignCenterIcon = {
  @react.component @module("@mui/icons-material/FormatAlignCenter")
  external make: unit => React.element = "default"
}
module FormatAlignRightIcon = {
  @react.component @module("@mui/icons-material/FormatAlignRight")
  external make: unit => React.element = "default"
}
module FormatAlignJustifyIcon = {
  @react.component @module("@mui/icons-material/FormatAlignJustify")
  external make: unit => React.element = "default"
}
module FormatBoldIcon = {
  @react.component @module("@mui/icons-material/FormatBold")
  external make: unit => React.element = "default"
}
module FormatItalicIcon = {
  @react.component @module("@mui/icons-material/FormatItalic")
  external make: unit => React.element = "default"
}
module FormatUnderlinedIcon = {
  @react.component @module("@mui/icons-material/FormatUnderlined")
  external make: unit => React.element = "default"
}
module FormatColorFillIcon = {
  @react.component @module("@mui/icons-material/FormatColorFill")
  external make: unit => React.element = "default"
}
module ArrowDropDownIcon = {
  @react.component @module("@mui/icons-material/ArrowDropDown")
  external make: unit => React.element = "default"
}

@react.component
let make = () => {
  let (alignment, setAlignment) = React.useReducer((_, v) => v, "left")
  let (formats, setFormats) = React.useReducer((_, v) => v, ["bold"])

  let handleAlignment = (_, v) => {
    setAlignment(v)
  }
  let handleFormats = (_, v) => {
    setFormats(v)
  }

  <Grid container=true spacing=Int(2)>
    <Grid size={Breakpoint({sm: Number(12), md: Number(6)})}>
      <Box mb={Number(2.)} mt={Number(2.)}>
        <ToggleButtonGroup value={alignment} exclusive=true onChange=handleAlignment>
          <ToggleButton value={"left"}>
            <FormatAlignLeftIcon />
          </ToggleButton>
          <ToggleButton value={"center"}>
            <FormatAlignCenterIcon />
          </ToggleButton>
          <ToggleButton value={"right"}>
            <FormatAlignRightIcon />
          </ToggleButton>
          <ToggleButton value={"justify"} disabled=true>
            <FormatAlignJustifyIcon />
          </ToggleButton>
        </ToggleButtonGroup>
      </Box>
      <Typography gutterBottom=true> {"Exclusive Selection"->React.string} </Typography>
      <Typography>
        {`Text justification toggle buttons present options for left, right, center, full, and
      justified text with only one item available for selection at a time. Selecting one option
      deselects any other.`->React.string}
      </Typography>
    </Grid>
    <Grid size={Breakpoint({sm: Number(12), md: Number(6)})}>
      <Box mb={Number(2.)} mt={Number(2.)}>
        <ToggleButtonGroup value={formats} onChange=handleFormats>
          <ToggleButton value={"bold"}>
            <FormatBoldIcon />
          </ToggleButton>
          <ToggleButton value={"italic"}>
            <FormatItalicIcon />
          </ToggleButton>
          <ToggleButton value={"underlined"}>
            <FormatUnderlinedIcon />
          </ToggleButton>
          <ToggleButton value={"color"} disabled=true>
            <FormatColorFillIcon />
            <ArrowDropDownIcon />
          </ToggleButton>
        </ToggleButtonGroup>
      </Box>
      <Typography gutterBottom=true> {"Multiple Selection"->React.string} </Typography>
      <Typography>
        {"Logically-grouped options, like Bold, Italic, and Underline, allow multiple options to be
      selected."->React.string}
      </Typography>
    </Grid>
  </Grid>
}
