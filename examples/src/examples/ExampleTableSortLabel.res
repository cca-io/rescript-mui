open Mui

type data = {
  id: int,
  name: string,
  calories: int,
  fat: float,
  carbs: int,
  protein: float,
}

let createData = (name, calories, fat, carbs, protein) => {
  {
    id: name->Js.String2.length,
    name: name,
    calories: calories,
    fat: fat,
    carbs: carbs,
    protein: protein,
  }
}

let rows = [
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
  createData("Oreo", 437, 18.0, 63, 4.0),
]

type order = Asc | Desc

@react.component
let make = () => {
  let (orderDirection, setOrderDirection) = React.useState(_ => Asc)
  let (orderBy, setOrderBy) = React.useState(_ => "calories")
  
  let handleRequestSort = (property) => {
    let isAsc = orderBy === property && orderDirection === Asc
    setOrderDirection(_ => isAsc ? Desc : Asc)
    setOrderBy(_ => property)
  }

  <div>
    <Typography variant=H6> {"TableSortLabel Examples:"->React.string} </Typography>
    <Box>
      <TableContainer component={{OverridableComponent.componentWithUnknownProps(Paper.make)}}>
        <Table  ariaLabel="sortable table">
          <TableHead>
            <TableRow>
              <TableCell>
                <TableSortLabel
                  id="table-sort-label-name"
                  active={orderBy === "name"}
                  onClick={_ => handleRequestSort("name")}>
                  {"Dessert (100g serving)"->React.string}
                </TableSortLabel>
              </TableCell>
              <TableCell align={Right}>
                <TableSortLabel
                  id="table-sort-label-calories"
                  active={orderBy === "calories"}
                  onClick={_ => handleRequestSort("calories")}>
                  {"Calories"->React.string}
                </TableSortLabel>
              </TableCell>
              <TableCell align=Right>
                <TableSortLabel
                  id="table-sort-label-fat"
                  active={orderBy === "fat"}
                  onClick={_ => handleRequestSort("fat")}>
                  {"Fat (g)"->React.string}
                </TableSortLabel>
              </TableCell>
              <TableCell align=Right>
                <TableSortLabel
                  id="table-sort-label-carbs"
                  active={orderBy === "carbs"}
                  onClick={_ => handleRequestSort("carbs")}>
                  {"Carbs (g)"->React.string}
                </TableSortLabel>
              </TableCell>
              <TableCell align=Right>
                <TableSortLabel
                  id="table-sort-label-protein"
                  active={orderBy === "protein"}
                  onClick={_ => handleRequestSort("protein")}>
                  {"Protein (g)"->React.string}
                </TableSortLabel>
              </TableCell>
            </TableRow>
          </TableHead>
          <TableBody>
            {rows
              ->Belt.Array.map(row => 
                <TableRow key={row.name}>
                  <TableCell scope="row"> {row.name->React.string} </TableCell>
                  <TableCell align=Right> {row.calories->Belt.Int.toString->React.string} </TableCell>
                  <TableCell align=Right> {row.fat->Js.Float.toString->React.string} </TableCell>
                  <TableCell align=Right> {row.carbs->Belt.Int.toString->React.string} </TableCell>
                  <TableCell align=Right> {row.protein->Js.Float.toString->React.string} </TableCell>
                </TableRow>
              )
              ->React.array}
          </TableBody>
        </Table>
      </TableContainer>
    </Box>
  </div>
}
