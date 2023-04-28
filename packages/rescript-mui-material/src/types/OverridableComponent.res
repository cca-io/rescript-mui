type t<'props>

external string: string => t<'props> = "%identity"
external component: React.component<'props> => t<'props> = "%identity"
