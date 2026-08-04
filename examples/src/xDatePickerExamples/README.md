# MUI X date-picker example coverage

These examples were ported from the MUI X documentation tree at commit
[`77536d20`](https://github.com/mui/mui-x/tree/77536d20b37527cf4d0b72c15d592861c9ae8889/docs/data/date-pickers).

The gallery contains 47 runnable cards covering the Community component families bound by
`@rescript-mui/x-date-pickers`:

- responsive, desktop, mobile, and static date/time/date-time pickers;
- controlled values, views, opening views, formats, and form props;
- date, time, and date-time fields;
- date, month, and year calendars;
- analog, digital, and multi-section clocks;
- date, time, and date-time validation;
- typed field, action-bar, calendar-header, toolbar, and opening-button slots;
- Day.js localization and picker lifecycle callbacks.

The upstream tree also contains examples that are intentionally not represented as runnable
cards here:

- Pro range pickers from `@mui/x-date-pickers-pro`;
- headless/custom-field examples based on hooks that this package does not bind;
- calendar-system and timezone examples requiring additional optional adapters and plugins;
- documentation infrastructure, styling snapshots, and duplicate examples used on multiple
  upstream pages.

Each card displays the upstream demo family it corresponds to, so future ports can extend the
gallery without losing the source mapping.
