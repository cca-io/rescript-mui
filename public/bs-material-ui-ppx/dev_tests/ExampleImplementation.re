type crs = {alignCenter: string};

module CrsTest:
  MaterialUi_WithStyles.WithStylesSafeTemplate with
    type classRecordStrings = crs = {
  type classRecord = {alignCenter: ReactDOMRe.Style.t};
  type classRecordJs = {. "alignCenter": ReactDOMRe.Style.t};
  let classes =
    MaterialUi_WithStyles.Record({
      alignCenter:
        ReactDOMRe.Style.make(~width="100%", ~textAlign="center", ()),
    });
  type classRecordStrings = crs;
  type classRecordStringsJs = {. "alignCenter": string};
  let classRecordStringsFromJs = crJs: classRecordStrings => {
    alignCenter: crJs##alignCenter,
  };
  let classRecordToJs = cr => {"alignCenter": cr.alignCenter};
};

module ST = MaterialUi_WithStyles.WithStylesSafe(CrsTest);