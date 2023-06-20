type fieldSectionType =
  | @as("year") Year
  | @as("month") Month
  | @as("day") Day
  | @as("weekDay") WeekDay
  | @as("hours") Hours
  | @as("minutes") Minutes
  | @as("seconds") Seconds
  | @as("meridiem") Meridiem

type fieldSectionContentType =
  | @as("digit") Digit
  | @as("digit-with-letter") DigitWithLetter
  | @as("letter") Letter

type fieldValueType =
  | @as("date") Date
  | @as("time") Time
  | @as("date-time") DateTime

@unboxed
type maxLength =
  | Number(int)
  | @as(null) Null

type fieldSection = {
  /**
   * Value of the section, as rendered inside the input.
   * For example, in the date `May 25, 1995`, the value of the month section is "May".
   */
  value: string,
  /**
   * Format token used to parse the value of this section from the date object.
   * For example, in the format `MMMM D, YYYY`, the format of the month section is "MMMM".
   */
  format: string,
  /**
   * Maximum length of the value, only defined for "digit" sections.
   * Will be used to determine how many leading zeros should be added to the value.
   */
  maxLength: maxLength,
  /**
   * Placeholder rendered when the value of this section is empty.
   */
  placeholder: string,
  /**
   * Type of the section.
   */
  @as("type")
  type_: fieldSectionType,
  /**
   * Type of content of the section.
   * Will determine if we should apply a digit-based editing or a letter-based editing.
   */
  contentType: fieldSectionContentType,
  /**
   * If `true`, the value of this section is supposed to have leading zeroes when parsed by the date library.
   * For example, the value `1` should be rendered as "01" instead of "1".
   * @deprecated Will be removed in v7, use `hasLeadingZerosInFormat` instead.
   */
  hasLeadingZeros: bool,
  /**
   * If `true`, the value of this section is supposed to have leading zeroes when parsed by the date library.
   * For example, the value `1` should be rendered as "01" instead of "1".
   */
  hasLeadingZerosInFormat: bool,
  /**
   * If `true`, the value of this section is supposed to have leading zeroes when rendered in the input.
   * For example, the value `1` should be rendered as "01" instead of "1".
   */
  hasLeadingZerosInInput: bool,
  /**
   * If `true`, the section value has been modified since the last time the sections were generated from a valid date.
   * When we can generate a valid date from the section, we don't directly pass it to `onChange`,
   * Otherwise, we would lose all the information contained in the original date, things like:
   * - time if the format does not contain it
   * - timezone / UTC
   *
   * To avoid losing that information, we transfer the values of the modified sections from the newly generated date to the original date.
   */
  modified: bool,
  /**
   * Start index of the section in the format
   */
  start: int,
  /**
   * End index of the section in the format
   */
  end: int,
  /**
   * Start index of the section value in the input.
   * Takes into account invisible unicode characters such as \u2069 but does not include them
   */
  startInInput: int,
  /**
   * End index of the section value in the input.
   * Takes into account invisible unicode characters such as \u2069 but does not include them
   */
  endInInput: int,
  /**
   * Separator displayed before the value of the section in the input.
   * If it contains escaped characters, then it must not have the escaping characters.
   * For example, on Day.js, the `year` section of the format `YYYY [year]` has an end separator equal to `year` not `[year]`
   */
  startSeparator: string,
  /**
   * Separator displayed after the value of the section in the input.
   * If it contains escaped characters, then it must not have the escaping characters.
   * For example, on Day.js, the `year` section of the format `[year] YYYY` has a start separator equal to `[year]`
   */
  endSeparator: string,
}
