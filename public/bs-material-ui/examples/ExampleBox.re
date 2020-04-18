[@react.component]
let make = () => {
  MaterialUi.(
    <Box component={Box.Component.string("span")} mb=1 fontSize="80px">
      "Testbox"->React.string
    </Box>
  );
};