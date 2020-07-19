---
title: Installation
---

## Schema

`graphql-ppx` needs your graphql schema to be available in the form of a
`graphql_schema.json` file.

The easiest way to add this to your project is using an
[introspection query](https://github.com/graphql/graphql-js/blob/master/src/utilities/introspectionQuery.js)
to your backend. You can do this using `get-graphql-schema`:

```sh
npx get-graphql-schema ENDPOINT_URL -j > graphql_schema.json
```

With `ENDPOINT_URL` being the URL of your GraphQL endpoint.

## Cache

`graphql-ppx` will generate a `.graphql_ppx_cache` folder alongside your JSON
schema to optimize parsing performance. If you're using a version control
system, you don't need to check it in.

The next pages will provide further installation instructions whether you are
using `graphql-ppx` with Bucklescript or using Reason Native.
