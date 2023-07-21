@module("@mui/system")
external styledElement: string => {..} => React.component<JsxDOM.domProps> = "styled"

@module("@mui/system")
external styledElementWithTheme: string => (Mui.Theme.t => {..}) => React.component<
  JsxDOM.domProps,
> = "styled"

@module("@mui/system")
external styledComponent: React.component<'a> => {..} => React.component<'a> = "styled"

@module("@mui/system")
external styledComponentWithTheme: React.component<'a> => (Mui.Theme.t => {..}) => React.component<
  'a,
> = "styled"
