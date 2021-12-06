"use strict";(self.webpackChunkrescript_material_ui_documentation=self.webpackChunkrescript_material_ui_documentation||[]).push([[128],{3905:function(e,t,n){n.d(t,{Zo:function(){return s},kt:function(){return m}});var r=n(7294);function i(e,t,n){return t in e?Object.defineProperty(e,t,{value:n,enumerable:!0,configurable:!0,writable:!0}):e[t]=n,e}function o(e,t){var n=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);t&&(r=r.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),n.push.apply(n,r)}return n}function a(e){for(var t=1;t<arguments.length;t++){var n=null!=arguments[t]?arguments[t]:{};t%2?o(Object(n),!0).forEach((function(t){i(e,t,n[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(n)):o(Object(n)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(n,t))}))}return e}function c(e,t){if(null==e)return{};var n,r,i=function(e,t){if(null==e)return{};var n,r,i={},o=Object.keys(e);for(r=0;r<o.length;r++)n=o[r],t.indexOf(n)>=0||(i[n]=e[n]);return i}(e,t);if(Object.getOwnPropertySymbols){var o=Object.getOwnPropertySymbols(e);for(r=0;r<o.length;r++)n=o[r],t.indexOf(n)>=0||Object.prototype.propertyIsEnumerable.call(e,n)&&(i[n]=e[n])}return i}var u=r.createContext({}),l=function(e){var t=r.useContext(u),n=t;return e&&(n="function"==typeof e?e(t):a(a({},t),e)),n},s=function(e){var t=l(e.components);return r.createElement(u.Provider,{value:t},e.children)},p={inlineCode:"code",wrapper:function(e){var t=e.children;return r.createElement(r.Fragment,{},t)}},f=r.forwardRef((function(e,t){var n=e.components,i=e.mdxType,o=e.originalType,u=e.parentName,s=c(e,["components","mdxType","originalType","parentName"]),f=l(n),m=i,d=f["".concat(u,".").concat(m)]||f[m]||p[m]||o;return n?r.createElement(d,a(a({ref:t},s),{},{components:n})):r.createElement(d,a({ref:t},s))}));function m(e,t){var n=arguments,i=t&&t.mdxType;if("string"==typeof e||i){var o=n.length,a=new Array(o);a[0]=f;var c={};for(var u in t)hasOwnProperty.call(t,u)&&(c[u]=t[u]);c.originalType=e,c.mdxType="string"==typeof e?e:i,a[1]=c;for(var l=2;l<o;l++)a[l]=n[l];return r.createElement.apply(null,a)}return r.createElement.apply(null,n)}f.displayName="MDXCreateElement"},8495:function(e,t,n){n.r(t),n.d(t,{frontMatter:function(){return c},contentTitle:function(){return u},metadata:function(){return l},toc:function(){return s},default:function(){return f}});var r=n(3117),i=n(102),o=(n(7294),n(3905)),a=["components"],c={title:"Introduction"},u=void 0,l={unversionedId:"introduction",id:"introduction",isDocsHomePage:!1,title:"Introduction",description:"rescript-material-ui provides ReScript bindings",source:"@site/docs/introduction.md",sourceDirName:".",slug:"/introduction",permalink:"/docs/introduction",tags:[],version:"current",frontMatter:{title:"Introduction"},sidebar:"docs",next:{title:"Installation",permalink:"/docs/installation"}},s=[{value:"Binding format",id:"binding-format",children:[],level:2}],p={toc:s};function f(e){var t=e.components,n=(0,i.Z)(e,a);return(0,o.kt)("wrapper",(0,r.Z)({},p,n,{components:t,mdxType:"MDXLayout"}),(0,o.kt)("p",null,(0,o.kt)("inlineCode",{parentName:"p"},"rescript-material-ui")," provides ",(0,o.kt)("a",{parentName:"p",href:"https://rescript-lang.org/"},"ReScript")," bindings\nfor the Javascript based UI library ",(0,o.kt)("a",{parentName:"p",href:"https://mui.com/"},"MUI")," (formerly\n",(0,o.kt)("a",{parentName:"p",href:"https://material-ui.com/"},"MaterialUi"),")."),(0,o.kt)("p",null,"The bindings are automatically generated by utilizing the documentation\ngeneration scripts of the original package. These rely on a mix of code & code\nannotations and are not always 100% accurate."),(0,o.kt)("p",null,"This will directly translate into the bindings. If you come across a missing\nprop on a component or a misbehaving component, please feel free to open an\n",(0,o.kt)("a",{parentName:"p",href:"https://github.com/cca-io/rescript-material-ui/issues"},"issue"),"."),(0,o.kt)("h2",{id:"binding-format"},"Binding format"),(0,o.kt)("p",null,"The automatic nature of the bindings make some parts of it seem a little clunky.\nThis cannot be avoided, as some things just need to be generalized. Please refer\nto the individual sections in ",(0,o.kt)("inlineCode",{parentName:"p"},"Project Structure")," to to see what patterns are\nused."))}f.isMDXComponent=!0}}]);