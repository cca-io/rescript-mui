@react.component
let make = () => {
  <div>
    <Mui.Pagination count={10} />
    <Mui.Pagination count={10} color=Primary />
    <Mui.Pagination count={10} color=Secondary />
    <Mui.Pagination count={10} disabled=true />
  </div>
}
