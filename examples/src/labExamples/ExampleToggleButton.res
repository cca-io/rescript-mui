open MaterialUi
open MaterialUiLab

module FormatAlignLeftIcon = {
  @react.component @module("@material-ui/icons/FormatAlignLeft")
  external make: unit => React.element = "default"
}
module FormatAlignCenterIcon = {
  @react.component @module("@material-ui/icons/FormatAlignCenter")
  external make: unit => React.element = "default"
}
module FormatAlignRightIcon = {
  @react.component @module("@material-ui/icons/FormatAlignRight")
  external make: unit => React.element = "default"
}
module FormatAlignJustifyIcon = {
  @react.component @module("@material-ui/icons/FormatAlignJustify")
  external make: unit => React.element = "default"
}
module FormatBoldIcon = {
  @react.component @module("@material-ui/icons/FormatBold")
  external make: unit => React.element = "default"
}
module FormatItalicIcon = {
  @react.component @module("@material-ui/icons/FormatItalic")
  external make: unit => React.element = "default"
}
module FormatUnderlinedIcon = {
  @react.component @module("@material-ui/icons/FormatUnderlined")
  external make: unit => React.element = "default"
}
module FormatColorFillIcon = {
  @react.component @module("@material-ui/icons/FormatColorFill")
  external make: unit => React.element = "default"
}
module ArrowDropDownIcon = {
  @react.component @module("@material-ui/icons/ArrowDropDown")
  external make: unit => React.element = "default"
}

@react.component
let make = () => {
  let (alignment, setAlignment) = React.useReducer((_, v) => v, "left")
  let (formats, setFormats) = React.useReducer((_, v) => v, ["bold"])

  let handleAlignment = (_, v) => {
    setAlignment(v->MaterialUi.Any.unsafeGetValue)
  }
  let handleFormats = (_, v) => {
    setFormats(v->MaterialUi.Any.unsafeGetValue)
  }

  <Grid container=true spacing=#2>
    <Grid item=true sm=Grid.Sm.\"12" md=Grid.Md.\"6">
      <Box mb={Box.Value.int(2)} mt={Box.Value.int(2)}>
        <ToggleButtonGroup
          value={Any.fromString(alignment)} exclusive=true onChange=handleAlignment>
          <ToggleButton value={Any.fromString("left")}> <FormatAlignLeftIcon /> </ToggleButton>
          <ToggleButton value={Any.fromString("center")}> <FormatAlignCenterIcon /> </ToggleButton>
          <ToggleButton value={Any.fromString("right")}> <FormatAlignRightIcon /> </ToggleButton>
          <ToggleButton value={Any.fromString("justify")} disabled=true>
            <FormatAlignJustifyIcon />
          </ToggleButton>
        </ToggleButtonGroup>
      </Box>
      <Typography gutterBottom=true> "Exclusive Selection" </Typography>
      <Typography>
        {`Text justification toggle buttons present options for left, right, center, full, and
      justified text with only one item available for selection at a time. Selecting one option
      deselects any other.`->React.string}
      </Typography>
    </Grid>
    <Grid item=true sm=Grid.Sm.\"12" md=Grid.Md.\"6">
      <Box mb={Box.Value.int(2)} mt={Box.Value.int(2)}>
        <ToggleButtonGroup value={Any.make(formats)} onChange=handleFormats>
          <ToggleButton value={Any.fromString("bold")}> <FormatBoldIcon /> </ToggleButton>
          <ToggleButton value={Any.fromString("italic")}> <FormatItalicIcon /> </ToggleButton>
          <ToggleButton value={Any.fromString("underlined")}>
            <FormatUnderlinedIcon />
          </ToggleButton>
          <ToggleButton value={Any.fromString("color")} disabled=true>
            <FormatColorFillIcon /> <ArrowDropDownIcon />
          </ToggleButton>
        </ToggleButtonGroup>
      </Box>
      <Typography gutterBottom=true> "Multiple Selection" </Typography>
      <Typography>
        "Logically-grouped options, like Bold, Italic, and Underline, allow multiple options to be
      selected."
      </Typography>
    </Grid>
  </Grid>
}
