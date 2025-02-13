module Array = {
  type t
  type cb<'theme> = 'theme => t

  external bool: bool => t = "%identity"
  external func: cb<'theme> => t = "%identity"
  external obj: System.props => t = "%identity"
  external dict: Js.Dict.t<System.props> => t = "%identity"
}

type props

/** Example: 
```rescript
let render = () =>
  <Paper
    sx={Sx.array([
      Sx.Array.obj({mr: 2, color: "red"}),
      Sx.Array.func(theme =>
        Sx.Array.obj({
          color: theme.primaryColor,
        })
      ),
    ])}>
    {React.string("I am in a paper!")}
  </Paper>
 ```
 */
external array: array<Array.t> => props = "%identity"

external func: 'theme => props = "%identity"

external obj: System.props => props = "%identity"

external dict: Js.Dict.t<System.props> => props = "%identity"
