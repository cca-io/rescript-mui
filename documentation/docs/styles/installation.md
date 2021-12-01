---
title: Styles PPX Installation
---

First, add it to your dependencies using `npm` or `yarn`:

```bash
yarn add rescript-material-ui-ppx
# or
npm install rescript-material-ui-ppx
```

Second, add it to `ppx-flags` in your `bsconfig.json`:

```json
{
  "ppx-flags": ["rescript-material-ui-ppx/ppx"]
}
```

In some cases, depending on your project structure and build process, you might
have to reference the path directly:

```json
{
  "ppx-flags": ["./node_modules/rescript-material-ui-ppx/ppx"]
}
```
