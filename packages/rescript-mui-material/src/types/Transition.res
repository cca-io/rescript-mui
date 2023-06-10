// TODO
// https://reactcommunity.org/react-transition-group/transition#Transition-props
type props

type durationObject = {
  appear?: int,
  enter?: int,
  exit?: int,
}

type easingObject = {
  enter?: string,
  exit?: string,
}

external propsFromObject: {..} => props = "%identity"
