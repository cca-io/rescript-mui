open Mui

let getSpacing = (theme: Theme.t, num) => theme.spacing(num)->string_of_int ++ "px"

type state = {
  age: string,
  name: string,
}

@react.component
let make = () => {
  let (values, setValues) = React.useReducer((_, v) => v, {age: "", name: "hai"})

  let (inputLabelEl, setInputLabelEl) = React.useReducer((_, v) => v, None)
  let inputLabel = React.useCallback0((el: Js.Nullable.t<Dom.element>) =>
    setInputLabelEl(el->Js.toOption)
  )
  let (labelWidth, setLabelWidth) = React.useReducer((_, l) => l, 0)
  React.useEffect1(() => {
    switch inputLabelEl {
    | None => ()
    | Some(current) => setLabelWidth((current->Obj.magic)["offsetWidth"])
    }
    None
  }, [inputLabelEl])

  let handleChangeAge = (e, _) => setValues({...values, age: (e->ReactEvent.Form.target)["value"]})

  let handleChangeName = (e, _) =>
    setValues({...values, name: (e->ReactEvent.Form.target)["value"]})

  <form autoComplete="off">
    <div>
      <FormControl>
        <InputLabel htmlFor="age-simple"> {"Age"->React.string} </InputLabel>
        <Select
          value=values.age onChange=handleChangeAge inputProps={id: "age-simple", name: "age"}>
          <MenuItem value="">
            <em> {"None"->React.string} </em>
          </MenuItem>
          <MenuItem value="10"> {"Ten"->React.string} </MenuItem>
          <MenuItem value="20"> {"Twenty"->React.string} </MenuItem>
          <MenuItem value="30"> {"Thirty"->React.string} </MenuItem>
        </Select>
      </FormControl>
      <FormControl>
        <InputLabel htmlFor="age-helper"> {"Age"->React.string} </InputLabel>
        <Select
          value=values.age onChange=handleChangeAge input={<Input name="age" id="age-helper" />}>
          <MenuItem id="none" value={""}>
            <em> {"None"->React.string} </em>
          </MenuItem>
          <MenuItem value="10"> {"Ten"->React.string} </MenuItem>
          <MenuItem value="20"> {"Twenty"->React.string} </MenuItem>
          <MenuItem value="30"> {"Thirty"->React.string} </MenuItem>
        </Select>
        <FormHelperText> {"Some important helper text"->React.string} </FormHelperText>
      </FormControl>
      <FormControl>
        <Select value=values.age onChange=handleChangeAge displayEmpty=true name="age">
          <MenuItem value="">
            <em> {"None"->React.string} </em>
          </MenuItem>
          <MenuItem value="10"> {"Ten"->React.string} </MenuItem>
          <MenuItem value="20"> {"Twenty"->React.string} </MenuItem>
          <MenuItem value="30"> {"Thirty"->React.string} </MenuItem>
        </Select>
        <FormHelperText> {"Without label"->React.string} </FormHelperText>
      </FormControl>
      <FormControl>
        <InputLabel id="age-label-placeholder-label" shrink=true htmlFor="age-label-placeholder"> {"Age"->React.string} </InputLabel>
        <Select
          value=values.age
          onChange=handleChangeAge
          input={<Input name="age" id="age-label-placeholder" />}
          displayEmpty=true
          name="age">
          <MenuItem value="">
            <em> {"None"->React.string} </em>
          </MenuItem>
          <MenuItem value="10"> {"Ten"->React.string} </MenuItem>
          <MenuItem value="20"> {"Twenty"->React.string} </MenuItem>
          <MenuItem value="30"> {"Thirty"->React.string} </MenuItem>
        </Select>
        <FormHelperText> {"Label + placeholder"->React.string} </FormHelperText>
      </FormControl>
      <FormControl disabled=true>
        <InputLabel htmlFor="name-disabled"> {"Name"->React.string} </InputLabel>
        <Select
          value=values.name
          onChange=handleChangeName
          input={<Input name="name" id="name-disabled" />}>
          <MenuItem value="">
            <em> {"None"->React.string} </em>
          </MenuItem>
          <MenuItem value="hai"> {"Hai"->React.string} </MenuItem>
          <MenuItem value="olivier"> {"Olivier"->React.string} </MenuItem>
          <MenuItem value="kevin"> {"Kevin"->React.string} </MenuItem>
        </Select>
        <FormHelperText> {"Disabled"->React.string} </FormHelperText>
      </FormControl>
      <FormControl error=true>
        <InputLabel htmlFor="name-error"> {"Name"->React.string} </InputLabel>
        <Select
          value=values.name
          onChange=handleChangeName
          name="name"
          renderValue={value => `⚠️  - ${value}`->React.string}
          input={<Input id="name-error" />}>
          <MenuItem value={""}>
            <em> {"None"->React.string} </em>
          </MenuItem>
          <MenuItem value="hai"> {"Hai"->React.string} </MenuItem>
          <MenuItem value="olivier"> {"Olivier"->React.string} </MenuItem>
          <MenuItem value="kevin"> {"Kevin"->React.string} </MenuItem>
        </Select>
        <FormHelperText> {"Error"->React.string} </FormHelperText>
      </FormControl>
      <FormControl>
        <InputLabel htmlFor="name-readonly"> {"Name"->React.string} </InputLabel>
        <Select
          value=values.name
          onChange=handleChangeName
          input={<Input name="name" id="name-readonly" readOnly=true />}>
          <MenuItem value="">
            <em> {"None"->React.string} </em>
          </MenuItem>
          <MenuItem value="hai"> {"Hai"->React.string} </MenuItem>
          <MenuItem value="olivier"> {"Olivier"->React.string} </MenuItem>
          <MenuItem value="kevin"> {"Kevin"->React.string} </MenuItem>
        </Select>
        <FormHelperText> {"Read only"->React.string} </FormHelperText>
      </FormControl>
      <FormControl>
        <InputLabel htmlFor="age-auto-width"> {"Age"->React.string} </InputLabel>
        <Select
          value=values.age
          onChange=handleChangeAge
          input={<Input name="age" id="age-auto-width" />}
          autoWidth=true>
          <MenuItem value={""}>
            <em> {"None"->React.string} </em>
          </MenuItem>
          <MenuItem value="10"> {"Ten"->React.string} </MenuItem>
          <MenuItem value="20"> {"Twenty"->React.string} </MenuItem>
          <MenuItem value="30"> {"Thirty"->React.string} </MenuItem>
        </Select>
        <FormHelperText> {"Auto width"->React.string} </FormHelperText>
      </FormControl>
      <FormControl>
        <Select value=values.age onChange=handleChangeAge name="age" displayEmpty=true>
          <MenuItem value={""} disabled=true> {"Placeholder"->React.string} </MenuItem>
          <MenuItem value={"10"}> {"Ten"->React.string} </MenuItem>
          <MenuItem value={"20"}> {"Twenty"->React.string} </MenuItem>
          <MenuItem value={"30"}> {"Thirty"->React.string} </MenuItem>
        </Select>
        <FormHelperText> {"Placeholder"->React.string} </FormHelperText>
      </FormControl>
      <FormControl required=true>
        <InputLabel htmlFor="age-required"> {"Age"->React.string} </InputLabel>
        <Select
          value=values.age onChange=handleChangeAge name="age" inputProps={id: "age-required"}>
          <MenuItem value={""}>
            <em> {"None"->React.string} </em>
          </MenuItem>
          <MenuItem value={"10"}> {"Ten"->React.string} </MenuItem>
          <MenuItem value={"20"}> {"Twenty"->React.string} </MenuItem>
          <MenuItem value={"30"}> {"Thirty"->React.string} </MenuItem>
        </Select>
        <FormHelperText> {"Required"->React.string} </FormHelperText>
      </FormControl>
      <FormControl variant=Outlined>
        <InputLabel htmlFor="outlined-age-simple" ref={ReactDOM.Ref.callbackDomRef(inputLabel)}>
          {"Age"->React.string}
        </InputLabel>
        <Select
          value=values.age
          onChange=handleChangeAge
          input={<OutlinedInput
            name="age"
            id="outlined-age-simple"
            label={<div width={labelWidth->Belt.Int.toString} />}
          />}>
          <MenuItem value={""}>
            <em> {"None"->React.string} </em>
          </MenuItem>
          <MenuItem value={"10"}> {"Ten"->React.string} </MenuItem>
          <MenuItem value={"20"}> {"Twenty"->React.string} </MenuItem>
          <MenuItem value={"30"}> {"Thirty"->React.string} </MenuItem>
        </Select>
      </FormControl>
      <FormControl variant=Filled>
        <InputLabel htmlFor="filled-age-simple"> {"Age"->React.string} </InputLabel>
        <Select
          value=values.age
          onChange=handleChangeAge
          input={<FilledInput name="age" id="filled-age-simple" />}>
          <MenuItem value={""}>
            <em> {"None"->React.string} </em>
          </MenuItem>
          <MenuItem value="10"> {"Ten"->React.string} </MenuItem>
          <MenuItem value="20"> {"Twenty"->React.string} </MenuItem>
          <MenuItem value="30"> {"Thirty"->React.string} </MenuItem>
        </Select>
      </FormControl>
    </div>
  </form>
}
