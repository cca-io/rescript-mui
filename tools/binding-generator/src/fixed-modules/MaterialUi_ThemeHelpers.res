open MaterialUi_Theme;

@bs.deriving(abstract)
type transitionCreateArgs = {
  easing: string,
  duration: float,
};

@bs.send
external transitionCreateRAW:
  (t_transitions, array<string>, transitionCreateArgs) => string =
  "create";

let checkAffect = (affect, value) => affect ? [value] : [];

let transitionCreate =
    (
      ~theme,
      ~affectWidth=false,
      ~affectMargin=false,
      ~easing: string,
      ~duration: float,
      (),
    ) => {
  let transitions = theme.transitions;

  let affects =
    Belt.Array.concat(
      checkAffect(affectWidth, "width"),
      checkAffect(affectMargin, "margin"),
    );

  let args = transitionCreateArgs(~easing, ~duration);

  transitionCreateRAW(transitions, affects, args);
};
