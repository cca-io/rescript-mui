---
title: Installation
---

First, add it to you dependencies using `npm` or `yarn`:

```bash
yarn add @jsiebern/bs-material-ui-ppx
# or
npm install @jsiebern/bs-material-ui-ppx
```

Second, add it to `ppx-flags` in your `bsconfig.json`:

```json
{
  "ppx-flags": ["@jsiebern/bs-material-ui-ppx/ppx"]
}
```

In some cases, depending on your project structure and build process, you might
have to reference the path directly:

```json
{
  "ppx-flags": ["./node_modules/@jsiebern/bs-material-ui-ppx/ppx"]
}
```
