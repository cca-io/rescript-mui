open Mui
open MuiLab

@react.component
let make = () => {
  <div>
    <Typography variant=H6> {"Timeline Examples:"->React.string} </Typography>

    // Basic Timeline
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("16px"), marginBottom: String("8px")})}>
      {"Basic Timeline:"->React.string}
    </Typography>
    <Timeline id="timeline-basic">
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Eat"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Code"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot />
        </TimelineSeparator>
        <TimelineContent> {"Sleep"->React.string} </TimelineContent>
      </TimelineItem>
    </Timeline>

    // Timeline with colors
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("16px"), marginBottom: String("8px")})}>
      {"Timeline with Colored Dots:"->React.string}
    </Typography>
    <Timeline id="timeline-colors">
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot color=Primary />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Primary"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot color=Secondary />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Secondary"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot color=Success />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Success"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot color=Error />
        </TimelineSeparator>
        <TimelineContent> {"Error"->React.string} </TimelineContent>
      </TimelineItem>
    </Timeline>

    // Timeline with outlined variant
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("16px"), marginBottom: String("8px")})}>
      {"Timeline with Outlined Dots:"->React.string}
    </Typography>
    <Timeline id="timeline-outlined">
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot variant=Outlined color=Primary />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Outlined Primary"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot variant=Outlined color=Secondary />
        </TimelineSeparator>
        <TimelineContent> {"Outlined Secondary"->React.string} </TimelineContent>
      </TimelineItem>
    </Timeline>

    // Timeline with opposite content
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("16px"), marginBottom: String("8px")})}>
      {"Timeline with Opposite Content:"->React.string}
    </Typography>
    <Timeline id="timeline-opposite" position=Right>
      <TimelineItem>
        <TimelineOppositeContent color=TextSecondary>
          {"09:30 am"->React.string}
        </TimelineOppositeContent>
        <TimelineSeparator>
          <TimelineDot color=Primary />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Wake up"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineOppositeContent color=TextSecondary>
          {"10:00 am"->React.string}
        </TimelineOppositeContent>
        <TimelineSeparator>
          <TimelineDot color=Success />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Breakfast"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineOppositeContent color=TextSecondary>
          {"12:00 pm"->React.string}
        </TimelineOppositeContent>
        <TimelineSeparator>
          <TimelineDot color=Info />
        </TimelineSeparator>
        <TimelineContent> {"Lunch"->React.string} </TimelineContent>
      </TimelineItem>
    </Timeline>

    // Alternating Timeline
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("16px"), marginBottom: String("8px")})}>
      {"Alternating Timeline:"->React.string}
    </Typography>
    <Timeline id="timeline-alternate" position=Alternate>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot color=Primary />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Step 1"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot color=Secondary />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Step 2"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot color=Success />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Step 3"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot color=Warning />
        </TimelineSeparator>
        <TimelineContent> {"Step 4"->React.string} </TimelineContent>
      </TimelineItem>
    </Timeline>

    // Left-positioned Timeline
    <Typography variant=Subtitle2 sx={Sx.obj({marginTop: String("16px"), marginBottom: String("8px")})}>
      {"Left-positioned Timeline:"->React.string}
    </Typography>
    <Timeline id="timeline-left" position=Left>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot />
          <TimelineConnector />
        </TimelineSeparator>
        <TimelineContent> {"Left item 1"->React.string} </TimelineContent>
      </TimelineItem>
      <TimelineItem>
        <TimelineSeparator>
          <TimelineDot />
        </TimelineSeparator>
        <TimelineContent> {"Left item 2"->React.string} </TimelineContent>
      </TimelineItem>
    </Timeline>
  </div>
}
