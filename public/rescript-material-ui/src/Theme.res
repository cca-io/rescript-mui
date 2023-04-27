
        
        type t_{xs:number;sm:number;md:number;lg:number;xl:number;} = {
            
                    lg: float,
                

                    md: float,
                

                    sm: float,
                

                    xl: float,
                

                    xs: float,
                
        }
    

        type t_breakpoints = {
            
                    between: Any.t,
                

                    down: Any.t,
                

                    keys: array<string>,
                

                    not: Any.t,
                

                    only: Any.t,
                

                    unit: string,
                

                    up: Any.t,
                

                    values: t_{xs:number;sm:number;md:number;lg:number;xl:number;},
                
        }
    

        type t_palette = {
            
                    mode: string,
                
        }
    

        type t_shape = {
            
                    borderRadius: float,
                
        }
    

        type t_theme = {
            
                    breakpoints: t_breakpoints,
                

                    components: Any.t,
                

                    direction: string,
                

                    palette: t_palette,
                

                    shape: t_shape,
                

                    spacing: int => int,
                

                    unstable_sx: Any.t,
                

                    unstable_sxConfig: Any.t,
                
        }
    type t = t_theme;

        @module("@mui/material/styles") external create: ThemeOptions.t => t = "createTheme";
    