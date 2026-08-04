/**
 * Helpers for MUI picker values, which are represented as a date-library value or `null`.
 *
 * Prefer these helpers over constructing `Common.dateValue` directly. Several picker types
 * expose constructors with overlapping names, while these conversions remain unambiguous.
 */
type t<'date> = Common.dateValue<'date>

external fromDate: 'date => t<'date> = "%identity"
external fromNull: Null.t<'date> => t<'date> = "%identity"
external toNull: t<'date> => Null.t<'date> = "%identity"
external fromNullable: Nullable.t<'date> => t<'date> = "%identity"
external toNullable: t<'date> => Nullable.t<'date> = "%identity"

let fromOption = value => value->Null.fromOption->fromNull
let toOption = value => value->toNull->Null.toOption
