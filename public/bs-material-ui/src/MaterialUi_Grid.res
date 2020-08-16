
            
            type alignContent = [ | #stretch | #center | #\"flex-start" | #\"flex-end" | #\"space-between" | #\"space-around"];
          

            type alignItems = [ | #\"flex-start" | #center | #\"flex-end" | #stretch | #baseline];
          


          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "container":option<option<string>>
                ,
                "item":option<option<string>>
                ,
                "zeroMinWidth":option<option<string>>
                ,
                "direction-xs-column":option<option<string>>
                ,
                "direction-xs-column-reverse":option<option<string>>
                ,
                "direction-xs-row-reverse":option<option<string>>
                ,
                "wrap-xs-nowrap":option<option<string>>
                ,
                "wrap-xs-wrap-reverse":option<option<string>>
                ,
                "align-items-xs-center":option<option<string>>
                ,
                "align-items-xs-flex-start":option<option<string>>
                ,
                "align-items-xs-flex-end":option<option<string>>
                ,
                "align-items-xs-baseline":option<option<string>>
                ,
                "align-content-xs-center":option<option<string>>
                ,
                "align-content-xs-flex-start":option<option<string>>
                ,
                "align-content-xs-flex-end":option<option<string>>
                ,
                "align-content-xs-space-between":option<option<string>>
                ,
                "align-content-xs-space-around":option<option<string>>
                ,
                "justify-xs-center":option<option<string>>
                ,
                "justify-xs-flex-end":option<option<string>>
                ,
                "justify-xs-space-between":option<option<string>>
                ,
                "justify-xs-space-around":option<option<string>>
                ,
                "justify-xs-space-evenly":option<option<string>>
                ,
                "spacing-xs-1":option<option<string>>
                ,
                "spacing-xs-2":option<option<string>>
                ,
                "spacing-xs-3":option<option<string>>
                ,
                "spacing-xs-4":option<option<string>>
                ,
                "spacing-xs-5":option<option<string>>
                ,
                "spacing-xs-6":option<option<string>>
                ,
                "spacing-xs-7":option<option<string>>
                ,
                "spacing-xs-8":option<option<string>>
                ,
                "spacing-xs-9":option<option<string>>
                ,
                "spacing-xs-10":option<option<string>>
                ,
                "grid-xs-auto":option<option<string>>
                ,
                "grid-xs-true":option<option<string>>
                ,
                "grid-xs-1":option<option<string>>
                ,
                "grid-xs-2":option<option<string>>
                ,
                "grid-xs-3":option<option<string>>
                ,
                "grid-xs-4":option<option<string>>
                ,
                "grid-xs-5":option<option<string>>
                ,
                "grid-xs-6":option<option<string>>
                ,
                "grid-xs-7":option<option<string>>
                ,
                "grid-xs-8":option<option<string>>
                ,
                "grid-xs-9":option<option<string>>
                ,
                "grid-xs-10":option<option<string>>
                ,
                "grid-xs-11":option<option<string>>
                ,
                "grid-xs-12":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~container:
                  string=?
                  ,
                  ~item:
                  string=?
                  ,
                  ~zeroMinWidth:
                  string=?
                  ,
                  ~\"direction-xs-column":
                  string=?
                  ,
                  ~\"direction-xs-column-reverse":
                  string=?
                  ,
                  ~\"direction-xs-row-reverse":
                  string=?
                  ,
                  ~\"wrap-xs-nowrap":
                  string=?
                  ,
                  ~\"wrap-xs-wrap-reverse":
                  string=?
                  ,
                  ~\"align-items-xs-center":
                  string=?
                  ,
                  ~\"align-items-xs-flex-start":
                  string=?
                  ,
                  ~\"align-items-xs-flex-end":
                  string=?
                  ,
                  ~\"align-items-xs-baseline":
                  string=?
                  ,
                  ~\"align-content-xs-center":
                  string=?
                  ,
                  ~\"align-content-xs-flex-start":
                  string=?
                  ,
                  ~\"align-content-xs-flex-end":
                  string=?
                  ,
                  ~\"align-content-xs-space-between":
                  string=?
                  ,
                  ~\"align-content-xs-space-around":
                  string=?
                  ,
                  ~\"justify-xs-center":
                  string=?
                  ,
                  ~\"justify-xs-flex-end":
                  string=?
                  ,
                  ~\"justify-xs-space-between":
                  string=?
                  ,
                  ~\"justify-xs-space-around":
                  string=?
                  ,
                  ~\"justify-xs-space-evenly":
                  string=?
                  ,
                  ~\"spacing-xs-1":
                  string=?
                  ,
                  ~\"spacing-xs-2":
                  string=?
                  ,
                  ~\"spacing-xs-3":
                  string=?
                  ,
                  ~\"spacing-xs-4":
                  string=?
                  ,
                  ~\"spacing-xs-5":
                  string=?
                  ,
                  ~\"spacing-xs-6":
                  string=?
                  ,
                  ~\"spacing-xs-7":
                  string=?
                  ,
                  ~\"spacing-xs-8":
                  string=?
                  ,
                  ~\"spacing-xs-9":
                  string=?
                  ,
                  ~\"spacing-xs-10":
                  string=?
                  ,
                  ~\"grid-xs-auto":
                  string=?
                  ,
                  ~\"grid-xs-true":
                  string=?
                  ,
                  ~\"grid-xs-1":
                  string=?
                  ,
                  ~\"grid-xs-2":
                  string=?
                  ,
                  ~\"grid-xs-3":
                  string=?
                  ,
                  ~\"grid-xs-4":
                  string=?
                  ,
                  ~\"grid-xs-5":
                  string=?
                  ,
                  ~\"grid-xs-6":
                  string=?
                  ,
                  ~\"grid-xs-7":
                  string=?
                  ,
                  ~\"grid-xs-8":
                  string=?
                  ,
                  ~\"grid-xs-9":
                  string=?
                  ,
                  ~\"grid-xs-10":
                  string=?
                  ,
                  ~\"grid-xs-11":
                  string=?
                  ,
                  ~\"grid-xs-12":
                  string=?
                  
            , unit) => t = "";
          };
      

      module Component: {
        type t;
        let string: (string) => t;
let callback: (unit => React.element) => t;
let element: (React.element) => t;
      } = {
        @unboxed
        type rec t =
          | Any('a): t;
          let string = (v: string) => Any(v);
let callback = (v: unit => React.element) => Any(v);
let element = (v: React.element) => Any(v);
      };
      

            type direction = [ | #row | #\"row-reverse" | #column | #\"column-reverse"];
          

            type justify = [ | #\"flex-start" | #center | #\"flex-end" | #\"space-between" | #\"space-around" | #\"space-evenly"];
          

                module Lg: {
                    type t;
                    let \"false": t;
let auto: t;
let \"true": t;
let \"1": t;
let \"2": t;
let \"3": t;
let \"4": t;
let \"5": t;
let \"6": t;
let \"7": t;
let \"8": t;
let \"9": t;
let \"10": t;
let \"11": t;
let \"12": t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let \"false" = Any(false);
let auto = Any("auto");
let \"true" = Any(true);
let \"1" = Any(1);
let \"2" = Any(2);
let \"3" = Any(3);
let \"4" = Any(4);
let \"5" = Any(5);
let \"6" = Any(6);
let \"7" = Any(7);
let \"8" = Any(8);
let \"9" = Any(9);
let \"10" = Any(10);
let \"11" = Any(11);
let \"12" = Any(12);
                };
                

                module Md: {
                    type t;
                    let \"false": t;
let auto: t;
let \"true": t;
let \"1": t;
let \"2": t;
let \"3": t;
let \"4": t;
let \"5": t;
let \"6": t;
let \"7": t;
let \"8": t;
let \"9": t;
let \"10": t;
let \"11": t;
let \"12": t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let \"false" = Any(false);
let auto = Any("auto");
let \"true" = Any(true);
let \"1" = Any(1);
let \"2" = Any(2);
let \"3" = Any(3);
let \"4" = Any(4);
let \"5" = Any(5);
let \"6" = Any(6);
let \"7" = Any(7);
let \"8" = Any(8);
let \"9" = Any(9);
let \"10" = Any(10);
let \"11" = Any(11);
let \"12" = Any(12);
                };
                

                module Sm: {
                    type t;
                    let \"false": t;
let auto: t;
let \"true": t;
let \"1": t;
let \"2": t;
let \"3": t;
let \"4": t;
let \"5": t;
let \"6": t;
let \"7": t;
let \"8": t;
let \"9": t;
let \"10": t;
let \"11": t;
let \"12": t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let \"false" = Any(false);
let auto = Any("auto");
let \"true" = Any(true);
let \"1" = Any(1);
let \"2" = Any(2);
let \"3" = Any(3);
let \"4" = Any(4);
let \"5" = Any(5);
let \"6" = Any(6);
let \"7" = Any(7);
let \"8" = Any(8);
let \"9" = Any(9);
let \"10" = Any(10);
let \"11" = Any(11);
let \"12" = Any(12);
                };
                

            type spacing = [#\"0" | #\"1" | #\"2" | #\"3" | #\"4" | #\"5" | #\"6" | #\"7" | #\"8" | #\"9" | #\"10"];
          

            type wrap = [ | #nowrap | #wrap | #\"wrap-reverse"];
          

                module Xl: {
                    type t;
                    let \"false": t;
let auto: t;
let \"true": t;
let \"1": t;
let \"2": t;
let \"3": t;
let \"4": t;
let \"5": t;
let \"6": t;
let \"7": t;
let \"8": t;
let \"9": t;
let \"10": t;
let \"11": t;
let \"12": t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let \"false" = Any(false);
let auto = Any("auto");
let \"true" = Any(true);
let \"1" = Any(1);
let \"2" = Any(2);
let \"3" = Any(3);
let \"4" = Any(4);
let \"5" = Any(5);
let \"6" = Any(6);
let \"7" = Any(7);
let \"8" = Any(8);
let \"9" = Any(9);
let \"10" = Any(10);
let \"11" = Any(11);
let \"12" = Any(12);
                };
                

                module Xs: {
                    type t;
                    let \"false": t;
let auto: t;
let \"true": t;
let \"1": t;
let \"2": t;
let \"3": t;
let \"4": t;
let \"5": t;
let \"6": t;
let \"7": t;
let \"8": t;
let \"9": t;
let \"10": t;
let \"11": t;
let \"12": t;
                } = {
                    @unboxed
                    type rec t =
                        | Any('a): t;

                    let \"false" = Any(false);
let auto = Any("auto");
let \"true" = Any(true);
let \"1" = Any(1);
let \"2" = Any(2);
let \"3" = Any(3);
let \"4" = Any(4);
let \"5" = Any(5);
let \"6" = Any(6);
let \"7" = Any(7);
let \"8" = Any(8);
let \"9" = Any(9);
let \"10" = Any(10);
let \"11" = Any(11);
let \"12" = Any(12);
                };
                

            @react.component @bs.module("@material-ui/core") external make : (~alignContent: option<alignContent>=?,
~alignItems: option<alignItems>=?,
~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~component: option<Component.t>=?,
~container: option<bool>=?,
~direction: option<direction>=?,
~item: option<bool>=?,
~justify: option<justify>=?,
~lg: option<Lg.t>=?,
~md: option<Md.t>=?,
~sm: option<Sm.t>=?,
~spacing: option<@bs.int [@bs.as(0) #\"0" | @bs.as(1) #\"1" | @bs.as(2) #\"2" | @bs.as(3) #\"3" | @bs.as(4) #\"4" | @bs.as(5) #\"5" | @bs.as(6) #\"6" | @bs.as(7) #\"7" | @bs.as(8) #\"8" | @bs.as(9) #\"9" | @bs.as(10) #\"10"]>=?,
~wrap: option<wrap>=?,
~xl: option<Xl.t>=?,
~xs: option<Xs.t>=?,
~zeroMinWidth: option<bool>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "Grid";
        