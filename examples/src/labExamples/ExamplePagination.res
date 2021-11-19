open MaterialUiLab

@react.component
let make = () => {
  <div>
    <Pagination count={MaterialUi.Number.int(10)} />
    <Pagination count={MaterialUi.Number.int(10)} color=#primary />
    <Pagination count={MaterialUi.Number.int(10)} color=#secondary />
    <Pagination count={MaterialUi.Number.int(10)} disabled=true />
  </div>
}
