(self.webpackChunkbs_material_ui_documentation=self.webpackChunkbs_material_ui_documentation||[]).push([[806],{3905:function(e,n,t){"use strict";t.d(n,{Zo:function(){return c},kt:function(){return m}});var r=t(7294);function o(e,n,t){return n in e?Object.defineProperty(e,n,{value:t,enumerable:!0,configurable:!0,writable:!0}):e[n]=t,e}function a(e,n){var t=Object.keys(e);if(Object.getOwnPropertySymbols){var r=Object.getOwnPropertySymbols(e);n&&(r=r.filter((function(n){return Object.getOwnPropertyDescriptor(e,n).enumerable}))),t.push.apply(t,r)}return t}function i(e){for(var n=1;n<arguments.length;n++){var t=null!=arguments[n]?arguments[n]:{};n%2?a(Object(t),!0).forEach((function(n){o(e,n,t[n])})):Object.getOwnPropertyDescriptors?Object.defineProperties(e,Object.getOwnPropertyDescriptors(t)):a(Object(t)).forEach((function(n){Object.defineProperty(e,n,Object.getOwnPropertyDescriptor(t,n))}))}return e}function p(e,n){if(null==e)return{};var t,r,o=function(e,n){if(null==e)return{};var t,r,o={},a=Object.keys(e);for(r=0;r<a.length;r++)t=a[r],n.indexOf(t)>=0||(o[t]=e[t]);return o}(e,n);if(Object.getOwnPropertySymbols){var a=Object.getOwnPropertySymbols(e);for(r=0;r<a.length;r++)t=a[r],n.indexOf(t)>=0||Object.prototype.propertyIsEnumerable.call(e,t)&&(o[t]=e[t])}return o}var l=r.createContext({}),s=function(e){var n=r.useContext(l),t=n;return e&&(t="function"==typeof e?e(n):i(i({},n),e)),t},c=function(e){var n=s(e.components);return r.createElement(l.Provider,{value:n},e.children)},u={inlineCode:"code",wrapper:function(e){var n=e.children;return r.createElement(r.Fragment,{},n)}},d=r.forwardRef((function(e,n){var t=e.components,o=e.mdxType,a=e.originalType,l=e.parentName,c=p(e,["components","mdxType","originalType","parentName"]),d=s(t),m=o,f=d["".concat(l,".").concat(m)]||d[m]||u[m]||a;return t?r.createElement(f,i(i({ref:n},c),{},{components:t})):r.createElement(f,i({ref:n},c))}));function m(e,n){var t=arguments,o=n&&n.mdxType;if("string"==typeof e||o){var a=t.length,i=new Array(a);i[0]=d;var p={};for(var l in n)hasOwnProperty.call(n,l)&&(p[l]=n[l]);p.originalType=e,p.mdxType="string"==typeof e?e:o,i[1]=p;for(var s=2;s<a;s++)i[s]=t[s];return r.createElement.apply(null,i)}return r.createElement.apply(null,t)}d.displayName="MDXCreateElement"},8121:function(e,n,t){"use strict";t.r(n),t.d(n,{frontMatter:function(){return p},metadata:function(){return l},toc:function(){return s},default:function(){return u}});var r=t(2122),o=t(9756),a=(t(7294),t(3905)),i=["components"],p={title:"Installation"},l={unversionedId:"styles-ppx/installation",id:"styles-ppx/installation",isDocsHomePage:!1,title:"Installation",description:"First, add it to you dependencies using npm or yarn:",source:"@site/docs/styles-ppx/installation.md",sourceDirName:"styles-ppx",slug:"/styles-ppx/installation",permalink:"/docs/styles-ppx/installation",version:"current",frontMatter:{title:"Installation"},sidebar:"docs",previous:{title:"Introduction",permalink:"/docs/styles-ppx/introduction"},next:{title:"Usage",permalink:"/docs/styles-ppx/usage"}},s=[],c={toc:s};function u(e){var n=e.components,t=(0,o.Z)(e,i);return(0,a.kt)("wrapper",(0,r.Z)({},c,t,{components:n,mdxType:"MDXLayout"}),(0,a.kt)("p",null,"First, add it to you dependencies using ",(0,a.kt)("inlineCode",{parentName:"p"},"npm")," or ",(0,a.kt)("inlineCode",{parentName:"p"},"yarn"),":"),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-bash"},"yarn add @jsiebern/bs-material-ui-ppx\n# or\nnpm install @jsiebern/bs-material-ui-ppx\n")),(0,a.kt)("p",null,"Second, add it to ",(0,a.kt)("inlineCode",{parentName:"p"},"ppx-flags")," in your ",(0,a.kt)("inlineCode",{parentName:"p"},"bsconfig.json"),":"),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-json"},'{\n  "ppx-flags": ["@jsiebern/bs-material-ui-ppx/ppx"]\n}\n')),(0,a.kt)("p",null,"In some cases, depending on your project structure and build process, you might\nhave to reference the path directly:"),(0,a.kt)("pre",null,(0,a.kt)("code",{parentName:"pre",className:"language-json"},'{\n  "ppx-flags": ["./node_modules/@jsiebern/bs-material-ui-ppx/ppx"]\n}\n')))}u.isMDXComponent=!0}}]);