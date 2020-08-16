
            

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "multiline":option<option<string>>
                ,
                "dense":option<option<string>>
                ,
                "inset":option<option<string>>
                ,
                "primary":option<option<string>>
                ,
                "secondary":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~multiline:
                  string=?
                  ,
                  ~dense:
                  string=?
                  ,
                  ~inset:
                  string=?
                  ,
                  ~primary:
                  string=?
                  ,
                  ~secondary:
                  string=?
                  
            , unit) => t = "";
          };
      

            @react.component @bs.module("@material-ui/core") external make : (~children: option<'children>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~disableTypography: option<bool>=?,
~inset: option<bool>=?,
~primary: option<React.element>=?,
~primaryTypographyProps: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~secondary: option<React.element>=?,
~secondaryTypographyProps: option<Js.Dict.t<MaterialUi_Types.any>>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "ListItemText";
        