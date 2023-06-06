type t = {
  id?: string,
  className?: string,
  style?: ReactDOM.Style.t,
  ref?: ReactDOM.domRef,
}

type clickableProps = {onClick?: ReactEvent.Synthetic.t => unit}
