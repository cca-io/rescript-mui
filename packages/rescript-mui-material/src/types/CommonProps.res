type t_NoId = {
  className?: string,
  style?: ReactDOM.Style.t,
  ref?: ReactDOM.domRef,
}

type classNameOnly = {className: string}

type t_NoRef = {
  className?: string,
  style?: ReactDOM.Style.t,
  id?: string,
}

type t = {
  ...t_NoId,
  id?: string,
}

type clickableProps = {
  ...t,
  onClick?: ReactEvent.Synthetic.t => unit,
}
