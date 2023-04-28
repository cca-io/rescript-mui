type t

external make: 'a => t = "%identity"
external fromString: string => t = "%identity"
external fromInt: int => t = "%identity"
external unsafeToString: 'a => string = "%identity"
external unsafeToInt: 'a => int = "%identity"
external unsafeGetValue: t => 'a = "%identity"
