open MaterialUi_Lab;

@react.component
let make = () => {
  <div>
    <Pagination count={MaterialUi.Number.int(10)} />
    <Pagination count={MaterialUi.Number.int(10)} color=#Primary />
    <Pagination count={MaterialUi.Number.int(10)} color=#Secondary />
    <Pagination count={MaterialUi.Number.int(10)} disabled=true />
  </div>
};