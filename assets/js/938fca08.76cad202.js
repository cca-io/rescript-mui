"use strict";(self.webpackChunkrescript_material_ui_documentation=self.webpackChunkrescript_material_ui_documentation||[]).push([[9],{3905:function(e,t,r){r.d(t,{Zo:function(){return u},kt:function(){return s}});var a=r(7294);function n(e,t,r){return t in e?Object.defineProperty(e,t,{value:r,enumerable:!0,configurable:!0,writable:!0}):e[t]=r,e}function l(e,t){var r=Object.keys(e);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);t&&(a=a.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),r.push.apply(r,a)}return r}function o(e){for(var t=1;t<arguments.length;t++){var r=null!=arguments[t]?arguments[t]:{};t%2?l(Object(r),!0).forEach((function(t){n(e,t,r[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(r)):l(Object(r)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(r,t))}))}return e}function i(e,t){if(null==e)return{};var r,a,n=function(e,t){if(null==e)return{};var r,a,n={},l=Object.keys(e);for(a=0;a<l.length;a++)r=l[a],t.indexOf(r)>=0||(n[r]=e[r]);return n}(e,t);if(Object.getOwnPropertySymbols){var l=Object.getOwnPropertySymbols(e);for(a=0;a<l.length;a++)r=l[a],t.indexOf(r)>=0||Object.prototype.propertyIsEnumerable.call(e,r)&&(n[r]=e[r])}return n}var p=a.createContext({}),d=function(e){var t=a.useContext(p),r=t;return e&&(r="function"==typeof e?e(t):o(o({},t),e)),r},u=function(e){var t=d(e.components);return a.createElement(p.Provider,{value:t},e.children)},c={inlineCode:"code",wrapper:function(e){var t=e.children;return a.createElement(a.Fragment,{},t)}},m=a.forwardRef((function(e,t){var r=e.components,n=e.mdxType,l=e.originalType,p=e.parentName,u=i(e,["components","mdxType","originalType","parentName"]),m=d(r),s=n,k=m["".concat(p,".").concat(s)]||m[s]||c[s]||l;return r?a.createElement(k,o(o({ref:t},u),{},{components:r})):a.createElement(k,o({ref:t},u))}));function s(e,t){var r=arguments,n=t&&t.mdxType;if("string"==typeof e||n){var l=r.length,o=new Array(l);o[0]=m;var i={};for(var p in t)hasOwnProperty.call(t,p)&&(i[p]=t[p]);i.originalType=e,i.mdxType="string"==typeof e?e:n,o[1]=i;for(var d=2;d<l;d++)o[d]=r[d];return a.createElement.apply(null,o)}return a.createElement.apply(null,r)}m.displayName="MDXCreateElement"},5055:function(e,t,r){r.r(t),r.d(t,{frontMatter:function(){return i},contentTitle:function(){return p},metadata:function(){return d},toc:function(){return u},default:function(){return m}});var a=r(3117),n=r(102),l=(r(7294),r(3905)),o=["components"],i={title:"Module - Colors"},p=void 0,d={unversionedId:"project-structure/module-colors",id:"project-structure/module-colors",isDocsHomePage:!1,title:"Module - Colors",description:"Concept",source:"@site/docs/project-structure/module-colors.md",sourceDirName:"project-structure",slug:"/project-structure/module-colors",permalink:"/docs/project-structure/module-colors",tags:[],version:"current",frontMatter:{title:"Module - Colors"},sidebar:"docs",previous:{title:"Number Type",permalink:"/docs/project-structure/number-type"},next:{title:"Module - Core",permalink:"/docs/project-structure/module-core"}},u=[{value:"Concept",id:"concept",children:[],level:2},{value:"Available Shades",id:"available-shades",children:[],level:2},{value:"Available colors",id:"available-colors",children:[],level:2}],c={toc:u};function m(e){var t=e.components,r=(0,n.Z)(e,o);return(0,l.kt)("wrapper",(0,a.Z)({},c,r,{components:t,mdxType:"MDXLayout"}),(0,l.kt)("h2",{id:"concept"},"Concept"),(0,l.kt)("p",null,"All colors are available in the special module ",(0,l.kt)("inlineCode",{parentName:"p"},"Mui.Colors"),"."),(0,l.kt)("p",null,"All colors are available as their corresponding name from the\n",(0,l.kt)("a",{parentName:"p",href:"https://material-ui.com/customization/color/#color-palette"},"MUI Color Palette"),".\nThey are typed as ",(0,l.kt)("a",{parentName:"p",href:"https://rescript-lang.org/docs/manual/latest/record"},"records"),"\nand you can access the shades by the following rules:"),(0,l.kt)("ul",null,(0,l.kt)("li",{parentName:"ul"},"Numeric keys are prefixed with a ",(0,l.kt)("inlineCode",{parentName:"li"},"c")),(0,l.kt)("li",{parentName:"ul"},"Keys that are prefixed by a char are lowercased")),(0,l.kt)("p",null,"Let's take the color\n",(0,l.kt)("a",{parentName:"p",href:"https://github.com/cca-io/rescript-material-ui/blob/4ceab30b4e63e6ca639c9cc5ad3a9a1adf52a970/public/rescript-material-ui/src/MaterialUi_Colors.re#L582-L612"},"red"),"\nas an example. The following table shows the equivalent keys for accessing its\nshades:"),(0,l.kt)("h2",{id:"available-shades"},"Available Shades"),(0,l.kt)("table",null,(0,l.kt)("thead",{parentName:"table"},(0,l.kt)("tr",{parentName:"thead"},(0,l.kt)("th",{parentName:"tr",align:null},"Javascript"),(0,l.kt)("th",{parentName:"tr",align:null},"ReScript"))),(0,l.kt)("tbody",{parentName:"table"},(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['50']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.c50"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['100']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.c100"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['200']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.c200"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['300']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.c300"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['400']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.c400"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['500']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.c500"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['600']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.c600"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['700']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.c700"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['800']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.c800"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['900']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.c900"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['A100']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.a100"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['A200']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.a200"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['A400']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.a400"))),(0,l.kt)("tr",{parentName:"tbody"},(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"red['A700']")),(0,l.kt)("td",{parentName:"tr",align:null},(0,l.kt)("inlineCode",{parentName:"td"},"Mui.Colors.red.a700"))))),(0,l.kt)("h2",{id:"available-colors"},"Available colors"),(0,l.kt)("p",null,"All colors from the\n",(0,l.kt)("a",{parentName:"p",href:"https://material-ui.com/customization/color/#color-palette"},"MUI Color Palette"),"\nare available:"),(0,l.kt)("ul",null,(0,l.kt)("li",{parentName:"ul"},"blueGrey"),(0,l.kt)("li",{parentName:"ul"},"grey"),(0,l.kt)("li",{parentName:"ul"},"brown"),(0,l.kt)("li",{parentName:"ul"},"deepOrange"),(0,l.kt)("li",{parentName:"ul"},"orange"),(0,l.kt)("li",{parentName:"ul"},"amber"),(0,l.kt)("li",{parentName:"ul"},"yellow"),(0,l.kt)("li",{parentName:"ul"},"lime"),(0,l.kt)("li",{parentName:"ul"},"lightGreen"),(0,l.kt)("li",{parentName:"ul"},"green"),(0,l.kt)("li",{parentName:"ul"},"teal"),(0,l.kt)("li",{parentName:"ul"},"cyan"),(0,l.kt)("li",{parentName:"ul"},"lightBlue"),(0,l.kt)("li",{parentName:"ul"},"blue"),(0,l.kt)("li",{parentName:"ul"},"indigo"),(0,l.kt)("li",{parentName:"ul"},"deepPurple"),(0,l.kt)("li",{parentName:"ul"},"purple"),(0,l.kt)("li",{parentName:"ul"},"pink"),(0,l.kt)("li",{parentName:"ul"},"red"),(0,l.kt)("li",{parentName:"ul"},"common")))}m.isMDXComponent=!0}}]);