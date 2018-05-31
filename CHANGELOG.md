# Changelog

> **Tags:**
> - :boom:       [Breaking Change]
> - :rocket:     [New Feature]
> - :bug:        [Bug Fix]
> - :memo:       [Documentation]
> - :house:      [Internal]
> - :nail_care:  [Polish]

(_Tags are copied from [babel](https://github.com/babel/babel/blob/master/CHANGELOG.md)_)

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