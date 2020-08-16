
            

            type actionPosition = [ | #left | #right];
          

          module Classes = {
            type t = {
              .
              
                "root":option<option<string>>
                ,
                "titlePositionBottom":option<option<string>>
                ,
                "titlePositionTop":option<option<string>>
                ,
                "rootSubtitle":option<option<string>>
                ,
                "titleWrap":option<option<string>>
                ,
                "titleWrapActionPosLeft":option<option<string>>
                ,
                "titleWrapActionPosRight":option<option<string>>
                ,
                "title":option<option<string>>
                ,
                "subtitle":option<option<string>>
                ,
                "actionIcon":option<option<string>>
                ,
                "actionIconActionPosLeft":option<option<string>>
                
            };
            @bs.obj external make: (
              
                  ~root:
                  string=?
                  ,
                  ~titlePositionBottom:
                  string=?
                  ,
                  ~titlePositionTop:
                  string=?
                  ,
                  ~rootSubtitle:
                  string=?
                  ,
                  ~titleWrap:
                  string=?
                  ,
                  ~titleWrapActionPosLeft:
                  string=?
                  ,
                  ~titleWrapActionPosRight:
                  string=?
                  ,
                  ~title:
                  string=?
                  ,
                  ~subtitle:
                  string=?
                  ,
                  ~actionIcon:
                  string=?
                  ,
                  ~actionIconActionPosLeft:
                  string=?
                  
            , unit) => t = "";
          };
      

            type titlePosition = [ | #bottom | #top];
          

            @react.component @bs.module("@material-ui/core") external make : (~actionIcon: option<React.element>=?,
~actionPosition: option<actionPosition>=?,
~classes: option<Classes.t>=?,
~className: option<string>=?,
~subtitle: option<React.element>=?,
~title: option<React.element>=?,
~titlePosition: option<titlePosition>=?,
~id: option<string>=?,
~style: option<ReactDOMRe.Style.t>=?,
~key: option<string>=?,
~ref: option<ReactDOMRe.domRef>=?,) => React.element = "GridListTileBar";
        