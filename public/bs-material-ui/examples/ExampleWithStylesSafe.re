module StyledExample = [%makeStyles
  {alignRight: ReactDOMRe.Style.make(~width="100%", ~textAlign="right", ())}
];

module Theme = MaterialUi_Theme;
module StyledExampleTheme = [%makeStyles
  theme => {
    background:
      ReactDOMRe.Style.make(
        ~color=theme.palette.common.white,
        ~backgroundColor=theme.palette.primary.main,
        (),
      ),
  }
];

[@react.component]
let make = () => {
  let classesExample = StyledExample.useStyles();
  let classesExampleTheme = StyledExampleTheme.useStyles();

  <div>
    <div className={classesExample.alignRight}>
      "Example text - aligned to the right"->React.string
    </div>
    <br />
    <br />
    <div className={classesExampleTheme.background}>
      "Example text on a background coming from the Mui Theme object"
      ->React.string
    </div>
  </div>;
};
