[@bs.module "@material-ui/core/colors/common"]
external commonExt : Js.Dict.t(string) = "default";

let black: string = Js.Dict.unsafeGet(commonExt, "black");

let white: string = Js.Dict.unsafeGet(commonExt, "white");
