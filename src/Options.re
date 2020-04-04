module Options = {
  module Scales = {
    module Axis = {
      module Time = {
        type t;

        [@bs.obj] external make: (~round: bool, ~_unit: string, unit) => t;
      };

      module Ticks = {
        type t;

        [@bs.obj]
        external make:
          (
            ~suggestedMin: int=?,
            ~suggestedMax: int=?,
            ~stepSize: int=?,
            ~source: [@bs.string] [ | `auto | `data | `labels]=?,
            unit
          ) =>
          t;
      };

      module ScaleLabel = {
        type t;

        [@bs.obj]
        external make: (~display: bool, ~labelString: string, unit) => t;
      };

      type t;

      [@bs.obj]
      external make:
        (
          ~_type: [@bs.string] [ | `linear | `logarithmic | `category | `time],
          ~distribution: [@bs.string] [ | `linear | `series]=?,
          ~bounds: [@bs.string] [ | `data | `ticks]=?,
          ~time: Time.t=?,
          ~ticks: Ticks.t=?,
          ~display: bool,
          ~scaleLabel: ScaleLabel.t=?,
          unit
        ) =>
        t;
    };

    type t;

    [@bs.obj]
    external make: (~yAxes: array(Axis.t), ~xAxes: array(Axis.t), unit) => t;
  };

  module Title = {
    type t;

    [@bs.obj] external make: (~display: bool, ~text: string, unit) => t;
  };

  module Hover = {
    type t;

    [@bs.obj]
    external make:
      (
        ~mode: [@bs.string] [ | `point | `nearest | `index | `dataset | `x | `y]
                 =?,
        ~intersect: bool=?,
        ~axis: string=?,
        ~animationDuration: int=?,
        unit
      ) =>
      t;
  };

  type t;

  [@bs.obj]
  external make:
    (
      ~events: [@bs.string] [
                 | `mousemove
                 | `mouseout
                 | `click
                 | `touchstart
                 | `touchmove
               ]
                 =?,
      ~responsive: bool=?,
      ~responsiveAnimationDuration: int=?,
      ~maintainAspectRatio: bool=?,
      ~aspectRatio: float=?,
      ~devicePixelRatio: float=?,
      ~scales: Scales.t=?,
      ~title: Title.t=?,
      unit
    ) =>
    t;
};

type t;

[@bs.obj]
external make:
  (
    ~_type: [@bs.string] [
              | `line
              | `bar
              | `radar
              | `doughnut
              | `pie
              | `polarArea
              | `bubble
              | `scatter
            ],
    ~data: Data.t,
    ~options: Options.t=?,
    unit
  ) =>
  t;
