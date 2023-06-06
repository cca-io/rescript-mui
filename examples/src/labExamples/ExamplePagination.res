@react.component
let make = () => {
  <div>
    <Mui.Pagination count={Mui.Number.int(10)} />
    <Mui.Pagination count={Mui.Number.int(10)} color=#primary />
    <Mui.Pagination count={Mui.Number.int(10)} color=#secondary />
    <Mui.Pagination count={Mui.Number.int(10)} disabled=true />
  </div>
}
