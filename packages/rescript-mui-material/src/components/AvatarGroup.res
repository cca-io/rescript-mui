type classes = {
  /** Styles applied to the root element. */
  root?: string,
  /** Styles applied to the avatar elements. */
  avatar?: string,
}

@unboxed
type spacing =
  | @as("medium") Medium
  | @as("small") Small
  | Number(float)

@unboxed
type variant =
  | @as("circular") Circular
  | @as("rounded") Rounded
  | @as("square") Square
  | String(string)

type slotProps = {additionalAvatar: Avatar.props}

type props = {
  ...CommonProps.t,
  /**
    * The avatars to stack.
    */
  children?: React.element,
  /**
    * Override or extend the styles applied to the component.
    */
  classes?: classes,
  /**
    * The component used for the root node.
    * Either a string to use a HTML element or a component.
    */
  component?: OverridableComponent.t<unknown>,
  /**
    * Max avatars to show before +x.
    * @default 5
    */
  max?: int,
  /**
    * The extra props for the slot components.
    * You can override the existing props or add new ones.
    *
    * This prop is an alias for the `componentsProps` prop, which will be deprecated in the future.
    *
    * @default {}
    */
  slotProps?: slotProps,
  /**
    * Spacing between avatars.
    * @default 'medium'
    */
  spacing?: spacing,
  /**
    * The system prop that allows defining system overrides as well as additional CSS styles.
    */
  sx?: Sx.props,
  /**
    * The total number of avatars. Used for calculating the number of extra avatars.
    * @default children.length
    */
  total?: int,
  /**
    * The variant to use.
    * @default 'circular'
    */
  variant?: variant,
}

@module("@mui/material/AvatarGroup")
external make: React.component<props> = "default"
