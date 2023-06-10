type t_NoId = {
  className?: string,
  style?: ReactDOM.Style.t,
  ref?: ReactDOM.domRef,
}

type t = {
  ...t_NoId,
  id?: string,
}

type clickableProps = {
  ...t,
  onClick?: ReactEvent.Synthetic.t => unit,
}
