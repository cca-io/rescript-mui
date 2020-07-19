---
title: Installation on Bucklescript
---

First, add it to you dependencies using `npm` or `yarn`:

```sh
yarn add @reasonml-community/graphql-ppx@next --dev
# or
npm install @reasonml-community/graphql-ppx@next  --saveDev
```

Second, add it to `ppx-flags` and `dependencies` in your `bsconfig.json`:

```json
"bs-dependencies": [
  "@reasonml-community/graphql-ppx"
],
"ppx-flags": ["@reasonml-community/graphql-ppx/ppx"]
```
