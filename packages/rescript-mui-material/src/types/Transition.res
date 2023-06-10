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
