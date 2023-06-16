module Fs = {
  @module("fs")
  external readdirSync: string => array<string> = "readdirSync"

  type fileOptions = {encoding: string}

  @module("fs")
  external readFileSync: (string, fileOptions) => string = "readFileSync"

  @module("fs")
  external writeFileSync: (string, string, fileOptions) => unit = "writeFileSync"
}

module Path = {
  type t = {
    dir: string,
    root: string,
    base: string,
    name: string,
    ext: string,
  }

  @module("path") @variadic
  external join: array<string> => string = "join"
}
