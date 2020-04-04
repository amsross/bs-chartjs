type t;
type ctx;

[@bs.send] external getContext: (Dom.element, string) => ctx = "getContext";

[@bs.new] [@bs.module] external chart': (ctx, Options.t) => t = "chart.js";
let make: (Dom.element, Options.t) => t =
  canvas => canvas->getContext("2d")->chart';

let options =
  Options.Options.(
    make(
      ~title=Title.make(~display=true, ~text="this is the title", ()),
      ~responsive=true,
      ~maintainAspectRatio=true,
      ~aspectRatio=100.,
      ~scales=
        Scales.(
          make(
            ~xAxes=[|
              Axis.(
                make(
                  ~_type=`time,
                  ~distribution=`linear,
                  ~time=Time.make(~round=true, ~_unit="day", ()),
                  ~display=true,
                  ~scaleLabel=
                    ScaleLabel.make(~display=true, ~labelString="Date", ()),
                  (),
                )
              ),
            |],
            ~yAxes=[|
              Axis.(
                make(
                  ~_type=`linear,
                  ~display=true,
                  ~ticks=
                    Ticks.make(
                      ~suggestedMax=105,
                      ~suggestedMin=70,
                      ~stepSize=5,
                      (),
                    ),
                  ~scaleLabel=
                    ScaleLabel.make(~display=true, ~labelString="Grade", ()),
                  (),
                )
              ),
            |],
            (),
          )
        ),
      (),
    )
  );

/* [@bs.val] */
/* external dir: ('a, [@bs.as {json|{"depth": null}|json}] _) => unit = */
/*   "console.dir"; */

/* Options.( */
/*   make(~_type=`line, ~data=Data.make(~datasets=[||], ()), ~options, ()) */
/* ) */
/* ->dir; */
