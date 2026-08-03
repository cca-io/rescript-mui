type displayStaticWrapperAs = [#mobile | #desktop]

type props<'date> = {
  ...DatePicker.props<'date>,
  /** Force rendering in particular picker variant. @default 'mobile' */
  displayStaticWrapperAs?: displayStaticWrapperAs,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date>> = "StaticDatePicker"
