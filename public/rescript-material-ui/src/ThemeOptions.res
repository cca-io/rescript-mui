
        module {Xs:Number;Sm:Number;Md:Number;Lg:Number;Xl:Number;} = {
            
type t = {
    .
    
            "lg": option<float>
          ,
            "md": option<float>
          ,
            "sm": option<float>
          ,
            "xl": option<float>
          ,
            "xs": option<float>
          
};
@obj external make: (
    
                ~lg:
                float=?
            ,
                ~md:
                float=?
            ,
                ~sm:
                float=?
            ,
                ~xl:
                float=?
            ,
                ~xs:
                float=?
            
, unit) => t = ""
        };
    

        module BreakpointsOptions = {
            
type t = {
    .
    
            "between": option<Any.t>
          ,
            "down": option<Any.t>
          ,
            "keys": option<array<string>>
          ,
            "not": option<Any.t>
          ,
            "only": option<Any.t>
          ,
            "step": option<float>
          ,
            "unit": option<string>
          ,
            "up": option<Any.t>
          ,
            "values": option<{Xs:Number;Sm:Number;Md:Number;Lg:Number;Xl:Number;}.t>
          
};
@obj external make: (
    
                ~between:
                Any.t=?
            ,
                ~down:
                Any.t=?
            ,
                ~keys:
                array<string>=?
            ,
                ~not:
                Any.t=?
            ,
                ~only:
                Any.t=?
            ,
                ~step:
                float=?
            ,
                ~unit:
                string=?
            ,
                ~up:
                Any.t=?
            ,
                ~values:
                {Xs:Number;Sm:Number;Md:Number;Lg:Number;Xl:Number;}.t=?
            
, unit) => t = ""
        };
    

        module Shape = {
            
type t = {
    .
    
            "borderRadius": option<float>
          
};
@obj external make: (
    
                ~borderRadius:
                float=?
            
, unit) => t = ""
        };
    

type t = {
    .
    
            "breakpoints": option<BreakpointsOptions.t>
          ,
            "components": option<Any.t>
          ,
            "direction": option<string>
          ,
            "palette": option<Any.t>
          ,
            "shape": option<Shape.t>
          ,
            "spacing": option<Any.t>
          ,
            "unstable_sxConfig": option<Any.t>
          ,
            "zIndex": option<Any.t>
          
};
@obj external make: (
    
                ~breakpoints:
                BreakpointsOptions.t=?
            ,
                ~components:
                Any.t=?
            ,
                ~direction:
                string=?
            ,
                ~palette:
                Any.t=?
            ,
                ~shape:
                Shape.t=?
            ,
                ~spacing:
                Any.t=?
            ,
                ~unstable_sxConfig:
                Any.t=?
            ,
                ~zIndex:
                Any.t=?
            
, unit) => t = ""