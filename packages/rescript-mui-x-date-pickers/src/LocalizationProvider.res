type dateAdapter

type pickersInputLocaleText<'date>

type props<'date, 'locale> = {
  children?: React.element,
  /**
   * Date library adapter class function.
   * @see See the localization provider {@link https://mui.com/x/react-date-pickers/getting-started/#setup-your-date-library-adapter date adapter setup section} for more details.
   */
  dateAdapter?: dateAdapter,
  /** Formats that are used for any child pickers */
  dateFormats?: Adapters.adapterFormats,
  /**
   * Date library instance you are using, if it has some global overrides
   * ```jsx
   * dateLibInstance={momentTimeZone}
   * ```
   */
  dateLibInstance?: 'date,
  /**
   * Locale for the date library you are using
   */
  adapterLocale?: 'locale,
  /**
   * Locale for components texts
   */
  localeText?: pickersInputLocaleText<'date>,
}

@module("@mui/x-date-pickers")
external make: React.component<props<'date, 'locale>> = "LocalizationProvider"
