// TODO
// https://reactcommunity.org/react-transition-group/transition#Transition-props
type props

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

external propsFromObject: {..} => props = "%identity"
