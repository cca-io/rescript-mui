"use strict";(self.webpackChunkrescript_material_ui_documentation=self.webpackChunkrescript_material_ui_documentation||[]).push([[864],{3905:function(e,t,r){r.d(t,{Zo:function(){return u},kt:function(){return y}});var n=r(7294);function o(e,t,r){return t in e?Object.defineProperty(e,t,{value:r,enumerable:!0,configurable:!0,writable:!0}):e[t]=r,e}function i(e,t){var r=Object.keys(e);if(Object.getOwnPropertySymbols){var n=Object.getOwnPropertySymbols(e);t&&(n=n.filter((function(t){return Object.getOwnPropertyDescriptor(e,t).enumerable}))),r.push.apply(r,n)}return r}function s(e){for(var t=1;t<arguments.length;t++){var r=null!=arguments[t]?arguments[t]:{};t%2?i(Object(r),!0).forEach((function(t){o(e,t,r[t])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(r)):i(Object(r)).forEach((function(t){Object.defineProperty(e,t,Object.getOwnPropertyDescriptor(r,t))}))}return e}function c(e,t){if(null==e)return{};var r,n,o=function(e,t){if(null==e)return{};var r,n,o={},i=Object.keys(e);for(n=0;n<i.length;n++)r=i[n],t.indexOf(r)>=0||(o[r]=e[r]);return o}(e,t);if(Object.getOwnPropertySymbols){var i=Object.getOwnPropertySymbols(e);for(n=0;n<i.length;n++)r=i[n],t.indexOf(r)>=0||Object.prototype.propertyIsEnumerable.call(e,r)&&(o[r]=e[r])}return o}var a=n.createContext({}),l=function(e){var t=n.useContext(a),r=t;return e&&(r="function"==typeof e?e(t):s(s({},t),e)),r},u=function(e){var t=l(e.components);return n.createElement(a.Provider,{value:t},e.children)},p={inlineCode:"code",wrapper:function(e){var t=e.children;return n.createElement(n.Fragment,{},t)}},f=n.forwardRef((function(e,t){var r=e.components,o=e.mdxType,i=e.originalType,a=e.parentName,u=c(e,["components","mdxType","originalType","parentName"]),f=l(r),y=o,m=f["".concat(a,".").concat(y)]||f[y]||p[y]||i;return r?n.createElement(m,s(s({ref:t},u),{},{components:r})):n.createElement(m,s({ref:t},u))}));function y(e,t){var r=arguments,o=t&&t.mdxType;if("string"==typeof e||o){var i=r.length,s=new Array(i);s[0]=f;var c={};for(var a in t)hasOwnProperty.call(t,a)&&(c[a]=t[a]);c.originalType=e,c.mdxType="string"==typeof e?e:o,s[1]=c;for(var l=2;l<i;l++)s[l]=r[l];return n.createElement.apply(null,s)}return n.createElement.apply(null,r)}f.displayName="MDXCreateElement"},4222:function(e,t,r){r.r(t),r.d(t,{assets:function(){return u},contentTitle:function(){return a},default:function(){return y},frontMatter:function(){return c},metadata:function(){return l},toc:function(){return p}});var n=r(7462),o=r(3366),i=(r(7294),r(3905)),s=["components"],c={title:"bs-css"},a=void 0,l={unversionedId:"styling/bs-css",id:"styling/bs-css",title:"bs-css",description:"Usage with bs-css or other CSS-in-ReScript libraries",source:"@site/docs/styling/bs-css.md",sourceDirName:"styling",slug:"/styling/bs-css",permalink:"/docs/styling/bs-css",tags:[],version:"current",frontMatter:{title:"bs-css"},sidebar:"docs",previous:{title:"Tailwind CSS",permalink:"/docs/styling/tailwind"},next:{title:"Styles PPX (not recommended)",permalink:"/docs/styling/styles-ppx"}},u={},p=[{value:"Usage with bs-css or other CSS-in-ReScript libraries",id:"usage-with-bs-css-or-other-css-in-rescript-libraries",level:2},{value:"Example",id:"example",level:3}],f={toc:p};function y(e){var t=e.components,r=(0,o.Z)(e,s);return(0,i.kt)("wrapper",(0,n.Z)({},f,r,{components:t,mdxType:"MDXLayout"}),(0,i.kt)("h2",{id:"usage-with-bs-css-or-other-css-in-rescript-libraries"},"Usage with bs-css or other CSS-in-ReScript libraries"),(0,i.kt)("p",null,"It is important to change the style precedence order with the help of the\n",(0,i.kt)("inlineCode",{parentName:"p"},"StylesProvider")," component, otherwise the internal MUI classes will overwrite\nyour styles."),(0,i.kt)("h3",{id:"example"},"Example"),(0,i.kt)("pre",null,(0,i.kt)("code",{parentName:"pre",className:"language-rescript"},'module Styles = {\n  open CssJs\n\n  let categoryButton = style(. [textTransform(#none), justifyContent(#flexStart)])\n  let icon = style(. [fontSize(px(24)), width(px(50))])\n}\n\n@react.component\nlet make = () =>\n  <Mui.StylesProvider injectFirst=true>\n    <Mui.Button\n      color=#primary\n      classes={Mui.Button.Classes.make(~root=Styles.categoryButton, ())}\n      onClick=ignore>\n      {React.string("Hello, BS-CSS & MUI!")}\n    </Mui.Button>\n  </Mui.StylesProvider>\n')))}y.isMDXComponent=!0}}]);