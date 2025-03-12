// Generated by ReScript, PLEASE EDIT WITH CARE

import * as React from "react";
import * as Belt_Array from "rescript/lib/es6/belt_Array.js";
import * as Caml_option from "rescript/lib/es6/caml_option.js";
import Box from "@mui/material/Box";
import * as JsxRuntime from "react/jsx-runtime";
import Paper from "@mui/material/Paper";
import Table from "@mui/material/Table";
import TableRow from "@mui/material/TableRow";
import TableBody from "@mui/material/TableBody";
import TableCell from "@mui/material/TableCell";
import TableHead from "@mui/material/TableHead";
import Typography from "@mui/material/Typography";
import TableContainer from "@mui/material/TableContainer";
import TableSortLabel from "@mui/material/TableSortLabel";

function createData(name, calories, fat, carbs, protein) {
  return {
          id: name.length,
          name: name,
          calories: calories,
          fat: fat,
          carbs: carbs,
          protein: protein
        };
}

var rows = [
  createData("Cupcake", 305, 3.7, 67, 4.3),
  createData("Donut", 452, 25.0, 51, 4.9),
  createData("Eclair", 262, 16.0, 24, 6.0),
  createData("Frozen yoghurt", 159, 6.0, 24, 4.0),
  createData("Gingerbread", 356, 16.0, 49, 3.9),
  createData("Honeycomb", 408, 3.2, 87, 6.5),
  createData("Ice cream sandwich", 237, 9.0, 37, 4.3),
  createData("Jelly Bean", 375, 0.0, 94, 0.0),
  createData("KitKat", 518, 26.0, 65, 7.0),
  createData("Lollipop", 392, 0.2, 98, 0.0),
  createData("Marshmallow", 318, 0.0, 81, 2.0),
  createData("Nougat", 360, 19.0, 9, 37.0),
  createData("Oreo", 437, 18.0, 63, 4.0)
];

function ExampleTableSortLabel(props) {
  var match = React.useState(function () {
        return "Asc";
      });
  var setOrderDirection = match[1];
  var orderDirection = match[0];
  var match$1 = React.useState(function () {
        return "calories";
      });
  var setOrderBy = match$1[1];
  var orderBy = match$1[0];
  var handleRequestSort = function (property) {
    var isAsc = orderBy === property && orderDirection === "Asc";
    setOrderDirection(function (param) {
          if (isAsc) {
            return "Desc";
          } else {
            return "Asc";
          }
        });
    setOrderBy(function (param) {
          return property;
        });
  };
  return JsxRuntime.jsxs("div", {
              children: [
                JsxRuntime.jsx(Typography, {
                      variant: "h6",
                      children: "TableSortLabel Examples:"
                    }),
                JsxRuntime.jsx(Box, {
                      children: Caml_option.some(JsxRuntime.jsx(TableContainer, {
                                children: Caml_option.some(JsxRuntime.jsxs(Table, {
                                          "aria-label": "sortable table",
                                          children: [
                                            JsxRuntime.jsx(TableHead, {
                                                  children: Caml_option.some(JsxRuntime.jsxs(TableRow, {
                                                            children: [
                                                              JsxRuntime.jsx(TableCell, {
                                                                    children: Caml_option.some(JsxRuntime.jsx(TableSortLabel, {
                                                                              id: "table-sort-label-name",
                                                                              children: "Dessert (100g serving)",
                                                                              onClick: (function (param) {
                                                                                  handleRequestSort("name");
                                                                                }),
                                                                              active: orderBy === "name"
                                                                            }))
                                                                  }),
                                                              JsxRuntime.jsx(TableCell, {
                                                                    align: "right",
                                                                    children: Caml_option.some(JsxRuntime.jsx(TableSortLabel, {
                                                                              id: "table-sort-label-calories",
                                                                              children: "Calories",
                                                                              onClick: (function (param) {
                                                                                  handleRequestSort("calories");
                                                                                }),
                                                                              active: orderBy === "calories"
                                                                            }))
                                                                  }),
                                                              JsxRuntime.jsx(TableCell, {
                                                                    align: "right",
                                                                    children: Caml_option.some(JsxRuntime.jsx(TableSortLabel, {
                                                                              id: "table-sort-label-fat",
                                                                              children: "Fat (g)",
                                                                              onClick: (function (param) {
                                                                                  handleRequestSort("fat");
                                                                                }),
                                                                              active: orderBy === "fat"
                                                                            }))
                                                                  }),
                                                              JsxRuntime.jsx(TableCell, {
                                                                    align: "right",
                                                                    children: Caml_option.some(JsxRuntime.jsx(TableSortLabel, {
                                                                              id: "table-sort-label-carbs",
                                                                              children: "Carbs (g)",
                                                                              onClick: (function (param) {
                                                                                  handleRequestSort("carbs");
                                                                                }),
                                                                              active: orderBy === "carbs"
                                                                            }))
                                                                  }),
                                                              JsxRuntime.jsx(TableCell, {
                                                                    align: "right",
                                                                    children: Caml_option.some(JsxRuntime.jsx(TableSortLabel, {
                                                                              id: "table-sort-label-protein",
                                                                              children: "Protein (g)",
                                                                              onClick: (function (param) {
                                                                                  handleRequestSort("protein");
                                                                                }),
                                                                              active: orderBy === "protein"
                                                                            }))
                                                                  })
                                                            ]
                                                          }))
                                                }),
                                            JsxRuntime.jsx(TableBody, {
                                                  children: Caml_option.some(Belt_Array.map(rows, (function (row) {
                                                              return JsxRuntime.jsxs(TableRow, {
                                                                          children: [
                                                                            JsxRuntime.jsx(TableCell, {
                                                                                  scope: "row",
                                                                                  children: Caml_option.some(row.name)
                                                                                }),
                                                                            JsxRuntime.jsx(TableCell, {
                                                                                  align: "right",
                                                                                  children: Caml_option.some(String(row.calories))
                                                                                }),
                                                                            JsxRuntime.jsx(TableCell, {
                                                                                  align: "right",
                                                                                  children: Caml_option.some(row.fat.toString())
                                                                                }),
                                                                            JsxRuntime.jsx(TableCell, {
                                                                                  align: "right",
                                                                                  children: Caml_option.some(String(row.carbs))
                                                                                }),
                                                                            JsxRuntime.jsx(TableCell, {
                                                                                  align: "right",
                                                                                  children: Caml_option.some(row.protein.toString())
                                                                                })
                                                                          ]
                                                                        }, row.name);
                                                            })))
                                                })
                                          ]
                                        })),
                                component: Caml_option.some(Paper)
                              }))
                    })
              ]
            });
}

var make = ExampleTableSortLabel;

export {
  createData ,
  rows ,
  make ,
}
/* rows Not a pure module */
