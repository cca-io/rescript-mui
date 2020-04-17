module TF = TextField;

[@react.component]
let make = () => {
  TF.SortDirection.(Js.log3(false_, asc, desc));

  MaterialUi.(
    <Box component={`String("span")} mb=1 fontSize="80px">
      "Testbox"->React.string
      TF.(
        <TF
          classes={Classes.make(~root="motha", ())}
          size=Size.small
          color=Color.secondary
          variant=Variant.outlined
          defaultValue={Value.int(3)}
          rows={Value.float(3.)}
          multiline=true
        />
      )
    </Box>
  );
};