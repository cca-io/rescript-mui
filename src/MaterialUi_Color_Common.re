[@bs.module "@material-ui/core/colors"]
external commonExt: Js.Dict.t(string) = "common";

let black: string = Js.Dict.unsafeGet(commonExt, "black");

let white: string = Js.Dict.unsafeGet(commonExt, "white");
