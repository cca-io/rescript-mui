---
title: Introduction
---

## What is a PPX?

PPX stands for **Pre Processor eXtension**. There is a fairly detailed article
by [@dylanirlbeck](https://twitter.com/dylanirlbeck) that I'd recommed if you're
interested in the nuts and bolts of these extensions:
[Link to the article](https://dev.to/dylanirlbeck/intro-to-ppxs-for-reason-newcomers-2829).

## Why do we need one for rescript-material-ui?

When you create some
[styles in MaterialUi](https://material-ui.com/guides/typescript/#usage-of-withstyles),
you pass an object to the `withStyles` function that returns another object with
the same keys that contains the class names as values.

While this is easily representable in Typescript for example, there is no
straight forward way to do this in `ReScript`. This is where the PPX comes in.

You pass an object in and it automatically generates all needed types and
function applications for you. This keeps the tedious and quite verbose work
from you while staying completely type safe when accessing the generated class
names.

See [Usage](usage.md) for more details.
