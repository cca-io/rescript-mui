---
title: Icons
---

The MaterialUi icons **do not** have separate bindings. There is a good reason
for this: Bindings result in thousands of files (or one extremely large one),
which take a good while to recompile (easily upwards of one minute, this is
unacceptable performance for a ReScript project).

It is therefore recommended to bind to the icons you need manually. See the
following example for how this could look like:

```reason
module SupervisedUserCircleOutlined = {
    @react.component @bs.module("@material-ui/icons/SupervisedUserCircle")
    external make: (
        ~color: string=?,
        ~className: string=?,
        ~fontSize: string=?,
    ) => React.element = "default"
};

<SupervisedUserCircleOutlined color={MaterialUi.Colors.red.c400} fontSize="26px" />
```
