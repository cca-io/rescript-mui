type t_NoId = {
  className?: string,
  style?: ReactDOM.Style.t,
  ref?: ReactDOM.domRef,
}

type t = {
  id?: string,
  ...t_NoId,
}

type clickableProps = {onClick?: ReactEvent.Synthetic.t => unit}
