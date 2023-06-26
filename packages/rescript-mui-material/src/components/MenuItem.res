type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** State class applied to the root element if keyboard focused. */
  focusVisible?: string,
  /** Styles applied to the root element if dense. */
  dense?: string,
  /** State class applied to the root element if `disabled={true}`. */
  disabled?: string,
  /** Styles applied to the root element if `divider={true}`. */
  divider?: string,
  /** Styles applied to the inner `component` element unless `disableGutters={true}`. */
  gutters?: string,
  /** State class applied to the root element if `selected={true}`. */
  selected?: string,
}

type props<'value> = {
  ...ButtonBase.publicPropsWithOnClick,
  /**
    * If `true`, the list item is focused during the first mount.
    * Focus will also be triggered if the value changes from false to true.
    * @default false
    */
  autoFocus?: bool,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * If `true`, compact vertical padding designed for keyboard and mouse input is used.
    * The prop defaults to the value inherited from the parent Menu component.
    * @default false
    */
  dense?: bool,
  /**
    * If `true`, the component is disabled.
    * @default false
    */
  disabled?: bool,
  /**
    * If `true`, the left and right padding is removed.
    * @default false
    */
  disableGutters?: bool,
  /**
    * If `true`, a 1px light border is added to the bottom of the menu item.
    * @default false
    */
  divider?: bool,
  /**
    * If `true`, the component is selected.
    * @default false
    */
  selected?: bool,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  value?: 'value,
}

@module("@mui/material/MenuItem")
external make: React.component<props<'value>> = "default"
