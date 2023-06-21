type props = {
  ...Mui.CommonProps.t_NoRef,
  /**
    * The content of the component.
    */
  children?: React.element,
  /**
    * The value of the currently selected `Tab`.
    */
  value: string,
}

@module("@mui/lab/TabContext")
external make: React.component<props> = "default"
