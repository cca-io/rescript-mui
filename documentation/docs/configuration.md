---
title: Configuration
---

## `bsconfig.json`

## configuration in extension point

If you want to use multiple schemas in your project it can be provided as a
secondary config argument in your `graphql-ppx` definition.

```reason
module MyQuery = [%graphql
  {|
    query pokemon($id: String, $name: String) {
      pokemon(name: $name, id: $id) {
        id
        name
      }
    }
  |};
  {schema: "pokedex_schema.json"}
];
```

This will use the `pokedex_schema.json` instead of using the default
`graphql_schema.json` file.

This opens up the possibility to use multiple different GraphQL APIs in the same
project.

**Note** the path to your file is based on where you run `bsb`. In this case
`pokedex_schema.json` is a sibling to `node_modules`.

## command line configuration

### -apollo-mode

By default `graphql-ppx` adds `__typename` only to fields on which we need those
informations (Unions and Interfaces). If you want to add `__typename` on every
object in a query you can specify it by using `-apollo-mode` in `ppx-flags`.
It's usefull in case of using `apollo-client` because of it's cache.

```json
"ppx-flags": [
  ["@reasonml-community/graphql-ppx/ppx", "-apollo-mode",]
],
```

### -schema

By default `graphql-ppx` uses `graphql_schema.json` file from your root
directory. You can override it by providing `-schema` argument in `ppx-flags` to
overriding it.

```json
"ppx-flags": [
  ["@baransu/graphql-ppx/ppx", "-schema ../graphql_schema.json"]
],
```
