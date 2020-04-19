[@react.component]
let make = () => {
  MaterialUi_Lab.(
    <div>
      <Pagination count={`Int(10)} />
      <Pagination count={`Int(10)} color=`Primary />
      <Pagination count={`Int(10)} color=`Secondary />
      <Pagination count={`Int(10)} disabled=true />
    </div>
  );
};