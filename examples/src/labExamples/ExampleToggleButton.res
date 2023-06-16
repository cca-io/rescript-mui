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
    setAlignment(v->Mui.Any.unsafeGetValue)
  }
  let handleFormats = (_, v) => {
    setFormats(v->Mui.Any.unsafeGetValue)
  }

  <Grid container=true spacing=Int(2)>
    <Grid item=true sm=Number(12) md=Number(6)>
      <Box mb={Number(2.)} mt={Number(2.)}>
        <ToggleButtonGroup
          value={Any.fromString(alignment)} exclusive=true onChange=handleAlignment>
          <ToggleButton value={Any.fromString("left")}>
            <FormatAlignLeftIcon />
          </ToggleButton>
          <ToggleButton value={Any.fromString("center")}>
            <FormatAlignCenterIcon />
          </ToggleButton>
          <ToggleButton value={Any.fromString("right")}>
            <FormatAlignRightIcon />
          </ToggleButton>
          <ToggleButton value={Any.fromString("justify")} disabled=true>
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
    <Grid item=true sm=Number(12) md=Number(6)>
      <Box mb={Number(2.)} mt={Number(2.)}>
        <ToggleButtonGroup value={Any.make(formats)} onChange=handleFormats>
          <ToggleButton value={Any.fromString("bold")}>
            <FormatBoldIcon />
          </ToggleButton>
          <ToggleButton value={Any.fromString("italic")}>
            <FormatItalicIcon />
          </ToggleButton>
          <ToggleButton value={Any.fromString("underlined")}>
            <FormatUnderlinedIcon />
          </ToggleButton>
          <ToggleButton value={Any.fromString("color")} disabled=true>
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
