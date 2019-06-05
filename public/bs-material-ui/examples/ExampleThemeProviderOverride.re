external styleToString: ReactDOMRe.Style.t => string = "%identity";

let theme =
  MaterialUi_Theme.create(
    MaterialUi_ThemeOptions.(
      make(
        ~typography=Typography.make(~useNextVariants=true, ()),
        ~overrides=
          Overrides.make(
            ~muiButton=
              ButtonClassKey.make(
                ~outlined=
                  ReactDOMRe.Style.make(
                    ~fontSize="12px",
                    ~fontWeight="300",
                    ~color="gray !important",
                    (),
                  )
                  ->ReactDOMRe.Style.unsafeAddProp(
                      "& svg",
                      ReactDOMRe.Style.make(
                        ~marginRight="15px",
                        ~fontSize="16px",
                        (),
                      )
                      ->styleToString,
                    ),
                (),
              ),
            (),
          ),
        (),
      )
    ),
  );

[@react.component]
let make = () =>
  MaterialUi.(
    <div>
      <MuiThemeProvider theme>
        <Button color=`Secondary variant=`Outlined>
          <ExampleIcons.SupervisedUserCircle.Filled />
          "Overriden Outline Styles"->React.string
        </Button>
      </MuiThemeProvider>
    </div>
  );