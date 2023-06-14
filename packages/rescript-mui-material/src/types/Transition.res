// https://reactcommunity.org/react-transition-group/transition#Transition-props
type props = {
  ...CommonProps.t,
  addEndListener?: Any.t,
  onEnter?: ReactEvent.Synthetic.t => unit,
  onEntered?: ReactEvent.Synthetic.t => unit,
  onEntering?: ReactEvent.Synthetic.t => unit,
  onExit?: ReactEvent.Synthetic.t => unit,
  onExited?: ReactEvent.Synthetic.t => unit,
  onExiting?: ReactEvent.Synthetic.t => unit,
}

type durationObject = {
  appear?: int,
  enter?: int,
  exit?: int,
}

@unboxed
type duration =
  | Time(int)
  | Object(durationObject)

@unboxed
type durationWithAuto =
  | @as("auto") Auto
  | Duration(int)
  | Object(durationObject)

type easingObject = {
  enter?: string,
  exit?: string,
}

@unboxed
type easing =
  | Easing(string)
  | Object(easingObject)

external propsFromObject: {..} => props = "%identity"
