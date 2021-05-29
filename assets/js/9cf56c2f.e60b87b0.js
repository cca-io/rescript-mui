(self.webpackChunkbs_material_ui_documentation=self.webpackChunkbs_material_ui_documentation||[]).push([[355],{3905:function(e,t,r){"use strict";r.d(t,{Zo:function(){return l},kt:function(){return f}});var n=r(7294);function o(e,t,r){return t in e?Object.defineProperty(e,t,{value:r,enumerable:!0,configurable:!0,writable:!0}):e[t]=r,e}function a(e,t){var r=Object.keys(e);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(e);t&&(n=n.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),r.push.apply(r,n)}return r}function i(e){for(var t=1;t<arguments.length;t++){var r=null!=arguments[t]?arguments[t]:{};t%2?a(Object(r),!0).forEach((function(t){o(e,t,r[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(r)):a(Object(r)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(r,t))}))}return e}function u(e,t){if(null==e)return{};var r,n,o=function(e,t){if(null==e)return{};var r,n,o={},a=Object.keys(e);for(n=0;n<a.length;n++)r=a[n],t.indexOf(r)>=0||(o[r]=e[r]);return o}(e,t);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);for(n=0;n<a.length;n++)r=a[n],t.indexOf(r)>=0||Object.prototype.propertyIsEnumerable.call(e,r)&&(o[r]=e[r])}return o}var p=n.createContext({}),c=function(e){var t=n.useContext(p),r=t;return e&&(r="function"==typeof e?e(t):i(i({},t),e)),r},l=function(e){var t=c(e.components);return n.createElement(p.Provider,{value:t},e.children)},s={inlineCode:"code",wrapper:function(e){var t=e.children;return n.createElement(n.Fragment,{},t)}},m=n.forwardRef((function(e,t){var r=e.components,o=e.mdxType,a=e.originalType,p=e.parentName,l=u(e,["components","mdxType","originalType","parentName"]),m=c(r),f=o,d=m["".concat(p,".").concat(f)]||m[f]||s[f]||a;return r?n.createElement(d,i(i({ref:t},l),{},{components:r})):n.createElement(d,i({ref:t},l))}));function f(e,t){var r=arguments,o=t&&t.mdxType;if("string"==typeof e||o){var a=r.length,i=new Array(a);i[0]=m;var u={};for(var p in t)hasOwnProperty.call(t,p)&&(u[p]=t[p]);u.originalType=e,u.mdxType="string"==typeof e?e:o,i[1]=u;for(var c=2;c<a;c++)i[c]=r[c];return n.createElement.apply(null,i)}return n.createElement.apply(null,r)}m.displayName="MDXCreateElement"},7116:function(e,t,r){"use strict";r.r(t),r.d(t,{frontMatter:function(){return u},metadata:function(){return p},toc:function(){return c},default:function(){return s}});var n=r(2122),o=r(9756),a=(r(7294),r(3905)),i=["components"],u={title:"Number Type"},p={unversionedId:"project-structure/number-type",id:"project-structure/number-type",isDocsHomePage:!1,title:"Number Type",description:"The bindings will provide both float and int types as numbers. Generally the",source:"@site/docs/project-structure/number-type.md",sourceDirName:"project-structure",slug:"/project-structure/number-type",permalink:"/docs/project-structure/number-type",version:"current",frontMatter:{title:"Number Type"},sidebar:"docs",previous:{title:"Any Type",permalink:"/docs/project-structure/any-type"},next:{title:"Module - Colors",permalink:"/docs/project-structure/module-colors"}},c=[],l={toc:c};function s(e){var t=e.components,r=(0,o.Z)(e,i);return(0,a.kt)("wrapper",(0,n.Z)({},l,r,{components:t,mdxType:"MDXLayout"}),(0,a.kt)("p",null,"The bindings will provide both ",(0,a.kt)("inlineCode",{parentName:"p"},"float")," and ",(0,a.kt)("inlineCode",{parentName:"p"},"int")," types as numbers. Generally the\nthe type of ",(0,a.kt)("inlineCode",{parentName:"p"},"MaterialUi_Types.Number.t")," will be re-used whereever possible (The\n",(0,a.kt)("inlineCode",{parentName:"p"},"Number")," module is also accessible via ",(0,a.kt)("inlineCode",{parentName:"p"},"MaterialUi.Number"),")."),(0,a.kt)("p",null,"An example of this would be:"),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-reason"},"@react.component\nlet make = () => {\n  open MaterialUi;\n\n  <AppBar elevation=Number.int(3) />\n}\n")),(0,a.kt)("p",null,"In some cases where you would expect this type, the bindings might require\nanother one that originates inside the component. This is the case when a number\nis part of a broader union type."),(0,a.kt)("p",null,"An example of this would be:"),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-reason"},"@react.component\nlet make = () => {\n  <MaterialUi_Backdrop\n    _open=true\n    timeout=MaterialUi_Backdrop.Timeout.int(3000)\n  />\n}\n")))}s.isMDXComponent=!0}}]);