open Mui

type answer = Yes | No | Maybe

let answerToString = v =>
  switch v {
  | Yes => "yes"
  | No => "no"
  | Maybe => "maybe"
  }

let answerFromString = s =>
  switch s {
  | "yes" => Yes
  | "no" => No
  | _ => Maybe
  }

let options = [(Yes, "Yes"), (No, "No"), (Maybe, "Maybe")]

// Helper: combine base System.props with theme-dependent dynamic key entries.
// Wraps Sx.array + Sx.Array.obj/func/dict into a single call.
let sxWithQueries = (base: System.props, f: Theme.t => Js.Dict.t<System.props>): Sx.props =>
  Sx.array([Sx.Array.obj(base), Sx.Array.func((theme: Theme.t) => Sx.Array.dict(f(theme)))])

// -- Example 1: Unnamed container query (radio → select) --
module RadioToSelect = {
  @react.component
  let make = () => {
    let (value, setValue) = React.useState(() => Yes)

    let radioSx = sxWithQueries({display: String("none")}, theme =>
      Js.Dict.fromArray([(theme.containerQueries.up(Sm), {System.display: String("block")})])
    )

    let selectSx = sxWithQueries({display: String("block")}, theme =>
      Js.Dict.fromArray([(theme.containerQueries.up(Sm), {System.display: String("none")})])
    )

    // Resizable container with inline-size containment
    <Box
      sx={Sx.obj({
        border: String("1px solid"),
        borderColor: Divider,
        borderRadius: Number(1.),
        padding: Number(2.),
        overflow: Hidden,
      })}
      style={ReactDOM.Style.make(
        ~resize="horizontal",
        ~minWidth="180px",
        ~maxWidth="100%",
        ~width="100%",
        (),
      )->ReactDOM.Style.unsafeAddProp("containerType", "inline-size")}>
      // Radio version: hidden below sm, shown at sm+
      <Box sx=radioSx>
        <FormLabel> {"Pick one (radio)"->React.string} </FormLabel>
        <RadioGroup
          value={value->answerToString}
          onChange={(e, _) => {
            let v: string = (e->ReactEvent.Form.target)["value"]
            setValue(_ => answerFromString(v))
          }}>
          {options
          ->Belt.Array.map(((v, label)) =>
            <FormControlLabel
              key={answerToString(v)}
              value={answerToString(v)}
              control={<Radio />}
              label={React.string(label)}
            />
          )
          ->React.array}
        </RadioGroup>
      </Box>
      // Select version: shown below sm, hidden at sm+
      <Box sx=selectSx>
        <FormControl fullWidth=true size=Small>
          <InputLabel> {"Pick one"->React.string} </InputLabel>
          <Select
            value={value->answerToString}
            label={React.string("Pick one")}
            onChange={(e, _) => {
              let v: string = (e->ReactEvent.Form.target)["value"]
              setValue(_ => answerFromString(v))
            }}>
            {options
            ->Belt.Array.map(((v, label)) =>
              <MenuItem key={answerToString(v)} value={answerToString(v)}>
                {React.string(label)}
              </MenuItem>
            )
            ->React.array}
          </Select>
        </FormControl>
      </Box>
    </Box>
  }
}

// -- Example 2: Named container query --
module NamedContainer = {
  @react.component
  let make = () => {
    // Named container queries via theme->Theme.containerQueriesNamed("card")
    let cardSx = sxWithQueries(
      {
        display: String("flex"),
        flexDirection: Column,
        gap: Number(1.),
        padding: Number(2.),
      },
      theme => {
        let card = theme->Theme.containerQueriesNamed("card")
        Js.Dict.fromArray([
          (card.up(Sm), {System.flexDirection: Row, alignItems: Center, gap: Number(3.)}),
        ])
      },
    )

    // Named container: "card"
    <Box
      sx={Sx.obj({
        border: String("1px solid"),
        borderColor: Divider,
        borderRadius: Number(1.),
        overflow: Hidden,
      })}
      style={ReactDOM.Style.make(
        ~resize="horizontal",
        ~minWidth="180px",
        ~maxWidth="100%",
        ~width="100%",
        (),
      )
      ->ReactDOM.Style.unsafeAddProp("containerType", "inline-size")
      ->ReactDOM.Style.unsafeAddProp("containerName", "card")}>
      <Box sx=cardSx>
        <Box
          sx={Sx.obj({
            width: String("48px"),
            height: String("48px"),
            borderRadius: String("50%"),
            bgcolor: PrimaryMain,
            flexShrink: Number(0.),
          })}
        />
        <Box>
          <Typography variant=Subtitle1> {"Named container: \"card\""->React.string} </Typography>
          <Typography variant=Body2 color=TextSecondary>
            {"Drag to resize. Layout switches from column to row at the sm breakpoint using theme->Theme.containerQueriesNamed(\"card\").up(Sm)."->React.string}
          </Typography>
        </Box>
      </Box>
    </Box>
  }
}

// -- Example 3: down and between queries --
module DownAndBetween = {
  @react.component
  let make = () => {
    let sx = sxWithQueries(
      {padding: Number(2.), bgcolor: BackgroundPaper, borderRadius: Number(1.)},
      theme => {
        let cq = theme.containerQueries
        Js.Dict.fromArray([
          // down: applies below the breakpoint
          (cq.down(Sm), {System.bgcolor: ErrorMain, color: String("white")}),
          // between: applies within a breakpoint range
          (cq.between(Sm, Md), {System.bgcolor: WarningMain, color: String("white")}),
          // up: applies above the breakpoint (already covered, but included for completeness)
          (cq.up(Md), {System.bgcolor: SuccessMain, color: String("white")}),
        ])
      },
    )

    <Box
      sx={Sx.obj({
        border: String("1px solid"),
        borderColor: Divider,
        borderRadius: Number(1.),
        overflow: Hidden,
      })}
      style={ReactDOM.Style.make(~resize="horizontal", ~minWidth="180px", ~maxWidth="100%", ~width="100%", ())
      ->ReactDOM.Style.unsafeAddProp("containerType", "inline-size")}>
      <Box sx>
        <Typography variant=Body1>
          {"down(Sm) = red, between(Sm, Md) = amber, up(Md) = green"->React.string}
        </Typography>
      </Box>
    </Box>
  }
}

@react.component
let make = () => {
  <Box display={String("flex")} flexDirection={Column} gap={Number(2.)}>
    <Typography variant=H6> {"Container Queries (v6)"->React.string} </Typography>
    <Typography variant=Body2>
      {"Drag the bottom-right corner of each box to resize and observe the layout change."->React.string}
    </Typography>
    <Typography variant=Subtitle2>
      {"Unnamed container: Radio \u2194 Select"->React.string}
    </Typography>
    <RadioToSelect />
    <Typography variant=Subtitle2>
      {"Named container: Column \u2194 Row"->React.string}
    </Typography>
    <NamedContainer />
    <Typography variant=Subtitle2>
      {"down / between / up"->React.string}
    </Typography>
    <DownAndBetween />
  </Box>
}
