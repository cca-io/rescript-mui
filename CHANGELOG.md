# Changelog

> **Tags:**
> - :boom:       [Breaking Change]
> - :rocket:     [New Feature]
> - :bug:        [Bug Fix]
> - :memo:       [Documentation]
> - :house:      [Internal]
> - :nail_care:  [Polish]

(_Tags are copied from [babel](https://github.com/babel/babel/blob/master/CHANGELOG.md)_)

## 0.4.3
* :rocket: Updated to MaterialUi v3.2.2
* :rocket: Added `xsAuto` ,`smAuto` ,`mdAuto` ,`lgAuto` ,`xlAuto` properties to the `Grid` component (will override their respective set properties if defined)
* :rocket: `mui.withStyles` generated components now accept a single child **OR** a render prop (no `...` array spread when using as a `HOC`)


## 0.4.2
* :rocket: Updated to MaterialUi v3.2.0

## 0.4.1
* :rocket: Updated to MaterialUi v3.1.1
* :bug: Brought back the `Popper` component
* :bug: Fixed `WithStyles` component crashing when themed argument is not passed
* :house: Switched binding style to support both `es6` and `commonjs`

## 0.4.0
* :rocket: Updated to MaterialUI v1.5.1
* :boom: Updated to ReasonReact v5 (using `ReactEvent` instead of `ReactEventRe`)

## 0.3.3
* :rocket: Updated to MaterialUI v1.4.1
* :bug: Grid component sizes were converted to strings

## 0.3.2
* :rocket: Added `ppx_withStyles` for `linux` and `mac`
* :rocket: Updated to MaterialUI v1.3.1
* :rocket: Added a postinstall hook for a platform dependant install of the ppx_withStyles
* :boom: Updated to Bucklescript v4.0.0 (abstract shapes field access switched from `key` to `keyGet`)

## 0.3.1
* :rocket: Updated to MaterialUI v1.2.2

## 0.3.0
* :rocket: Updated to MaterialUI v1.1.0
* :boom: Switched to `[bs.deriving abstract]` to work with object shapes (see component `Popover` as an example)
* :boom: Switched to trailing underscores for reserved names as per `reason-react v0.4.2` practice

## 0.2.0
* :bug: Fixed the `Grid` component so it requires numbers instead of strings

## 0.1.9

* :rocket: Most of the `onChange` handlers should be accurate now
* :house: The modules are now split into several files (reduces resulting bundle size)
* :memo: Added a changelog file
