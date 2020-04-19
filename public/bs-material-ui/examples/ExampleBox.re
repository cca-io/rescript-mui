[@react.component]
let make = () => {
  MaterialUi.(
    <Box component={`String("span")} mb="1" fontSize="80px">
      "Testbox"->React.string
    </Box>
  );
};