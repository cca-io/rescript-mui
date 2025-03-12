open Mui

@react.component
let make = () => {
  let (expanded, setExpanded) = React.useState(_ => "")

  let handleChange = (_event, isExpanded, panel) => {
    setExpanded(_ => isExpanded ? panel : "")
  }

  <div>
    <Typography variant=H6> {"AccordionSummary Examples:"->React.string} </Typography>
    <Box >
      <Accordion expanded={expanded === "panel1"} onChange={(e, exp) => handleChange(e, exp, "panel1")}>
        <AccordionSummary
          id="accordion-summary-1"
          expandIcon={<span> {"⌄"->React.string} </span>}
          ariaControls="panel1a-content">
          <Typography> {"Accordion 1"->React.string} </Typography>
        </AccordionSummary>
        <AccordionDetails>
          <Typography>
            {"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse malesuada lacus ex, sit amet blandit leo lobortis eget."->React.string}
          </Typography>
        </AccordionDetails>
      </Accordion>
      <Accordion expanded={expanded === "panel2"} onChange={(e, exp) => handleChange(e, exp, "panel2")}>
        <AccordionSummary
          id="accordion-summary-2"
          expandIcon={<span> {"⌄"->React.string} </span>}
          ariaControls="panel2a-content">
          <Typography> {"Accordion 2"->React.string} </Typography>
        </AccordionSummary>
        <AccordionDetails>
          <Typography>
            {"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Suspendisse malesuada lacus ex, sit amet blandit leo lobortis eget."->React.string}
          </Typography>
        </AccordionDetails>
      </Accordion>
      <Accordion disabled=true>
        <AccordionSummary
          id="accordion-summary-disabled"
          expandIcon={<span> {"⌄"->React.string} </span>}
          ariaControls="panel3a-content">
          <Typography> {"Disabled Accordion"->React.string} </Typography>
        </AccordionSummary>
      </Accordion>
    </Box>
  </div>
}
