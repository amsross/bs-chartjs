type t;
type ctx;

[@bs.send] external getContext: (Dom.element, string) => ctx = "getContext";

[@bs.new] [@bs.module] external chart': (ctx, Options.t) => t = "chart.js";
let make: (Dom.element, Options.t) => t =
  canvas => canvas->getContext("2d")->chart';
