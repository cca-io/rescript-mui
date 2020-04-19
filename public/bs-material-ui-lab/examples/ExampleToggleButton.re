module FormatAlignLeftIcon =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/FormatAlignLeft"]
    external reactClass: React.component('a) = "default";
  });
module FormatAlignCenterIcon =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/FormatAlignCenter"]
    external reactClass: React.component('a) = "default";
  });
module FormatAlignRightIcon =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/FormatAlignRight"]
    external reactClass: React.component('a) = "default";
  });
module FormatAlignJustifyIcon =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/FormatAlignJustify"]
    external reactClass: React.component('a) = "default";
  });
module FormatBoldIcon =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/FormatBold"]
    external reactClass: React.component('a) = "default";
  });
module FormatItalicIcon =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/FormatItalic"]
    external reactClass: React.component('a) = "default";
  });
module FormatUnderlinedIcon =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/FormatUnderlined"]
    external reactClass: React.component('a) = "default";
  });
module FormatColorFillIcon =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/FormatColorFill"]
    external reactClass: React.component('a) = "default";
  });
module ArrowDropDownIcon =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/ArrowDropDown"]
    external reactClass: React.component('a) = "default";
  });

module Filled =
  ExampleIcons.SupervisedUserCircle.Make({
    [@bs.module "@material-ui/icons/SupervisedUserCircle"]
    external reactClass: React.component('a) = "default";
  });

[@react.component]
let make = () => {
  let (alignment, setAlignment) = React.useReducer((_, v) => v, "left");
  let (formats, setFormats) = React.useReducer((_, v) => v, [|"bold"|]);

  let handleAlignment = (evt, v) => {
    setAlignment(v);
  };
  let handleFormats = (evt, v) => {
    setFormats(v);
  };

  MaterialUi.(
    MaterialUi_Lab.(
      <Grid container=true spacing=V2>
        <Grid item=true sm=`V12 md=`V6>
          <Box mb={2->Obj.magic} mt={2->Obj.magic}>
            <ToggleButtonGroup
              value=alignment exclusive=true onChange=handleAlignment>
              <ToggleButton value="left">
                <FormatAlignLeftIcon />
              </ToggleButton>
              <ToggleButton value="center">
                <FormatAlignCenterIcon />
              </ToggleButton>
              <ToggleButton value="right">
                <FormatAlignRightIcon />
              </ToggleButton>
              <ToggleButton value="justify" disabled=true>
                <FormatAlignJustifyIcon />
              </ToggleButton>
            </ToggleButtonGroup>
          </Box>
          <Typography gutterBottom=true> "Exclusive Selection" </Typography>
          <Typography>
            {j|Text justification toggle buttons present options for left, right, center, full, and
          justified text with only one item available for selection at a time. Selecting one option
          deselects any other.|j}
          </Typography>
        </Grid>
        <Grid item=true sm=`V12 md=`V6>
          <Box mb={2->Obj.magic} mt={2->Obj.magic}>
            <ToggleButtonGroup value=formats onChange=handleFormats>
              <ToggleButton value="bold"> <FormatBoldIcon /> </ToggleButton>
              <ToggleButton value="italic">
                <FormatItalicIcon />
              </ToggleButton>
              <ToggleButton value="underlined">
                <FormatUnderlinedIcon />
              </ToggleButton>
              <ToggleButton value="color" disabled=true>
                <FormatColorFillIcon />
                <ArrowDropDownIcon />
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
    )
  );
};