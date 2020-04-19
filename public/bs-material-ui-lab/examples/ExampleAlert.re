[@react.component]
let make = () => {
  MaterialUi_Lab.(
    <div>
      <Alert severity=`Error>
        {j|This is an error alert — check it out!|j}->React.string
      </Alert>
      <Alert severity=`Warning>
        {j|This is a warning alert — check it out!|j}->React.string
      </Alert>
      <Alert severity=`Info>
        {j|This is an info alert — check it out!|j}->React.string
      </Alert>
      <Alert severity=`Success>
        {j|This is a success alert — check it out!|j}->React.string
      </Alert>
    </div>
  );
};