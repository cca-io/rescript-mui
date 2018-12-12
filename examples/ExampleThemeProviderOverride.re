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

let component = ReasonReact.statelessComponent(__MODULE__);

let make = _ => {
  ...component,
  render: _ =>
    MaterialUi.(
      <div>
        <MuiThemeProvider theme>
          <Button color=`Secondary variant=`Outlined>
            <MaterialUi_Icons icon=`SupervisedUserCircle />
            "Overriden Outline Styles"->ReasonReact.string
          </Button>
        </MuiThemeProvider>
      </div>
    ),
};