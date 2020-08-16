---
title: Contributing
---

The generator code is usually adapted to the current MUI version and prone to
breaking on each new release (MaterialUi changes implementation details of their
docs generation quite frequently.). It would be a lot of work to simply keep the
code in a state where people could run it safely, so I won't do it. Thank you
for understanding.

## Component X is missing a prop

### Please read this first

In the header of this page you will find the currently supported MaterialUi
Version (`Currently on MUI version xxx`). Please make sure that the prop you're
missing wasn't added in a recent version which the bindings aren't updated to
yet. If you have confirmed that it's simply missing, you can refer to the next
paragraph.

### Contributing a missing prop

You can send a PR for
[this file](https://github.com/jsiebern/bs-material-ui/blob/master/tools/binding-generator/src/custom-props.ts)
with the according information. The object format is roughly as follows:

```ts
{
  ComponentName: {
    propName: {
      // ... refer to existing props as examples
    }
  },
}
```

## Documentation

Contributions to the documentation page are more than welcome. It lives in the
`documentation` folder in this repo. Simply run `yarn install` and after
`yarn start` inside the folder to get it going locally.

I'd be looking for some more / cleaner examples and maybe some clearer
explanations (better tailored towards beginners for example).
