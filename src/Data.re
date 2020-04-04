module Dataset = {
  module Datum = {
    type t;

    [@bs.obj] external make: (~x: Js.Date.t, ~y: float, unit) => t;
  };

  type t;

  [@bs.obj]
  external make:
    (
      ~label: string,
      ~data: array(Datum.t),
      ~_type: string=?,
      ~lineTension: float=?,
      ~backgroundColor: string=?,
      ~borderColor: string=?,
      ~borderDash: (int, int)=?,
      ~fill: bool=?,
      ~showLine: bool=?,
      unit
    ) =>
    t;
};

type t;

[@bs.obj] external make: (~datasets: array(Dataset.t), unit) => t;
