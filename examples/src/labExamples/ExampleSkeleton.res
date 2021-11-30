open MuiLab

@react.component
let make = () => {
  <div>
    <Skeleton variant=#text />
    <Skeleton variant=#circle width={Skeleton.Width.int(40)} height={Skeleton.Height.int(40)} />
    <Skeleton variant=#rect width={Skeleton.Width.int(210)} height={Skeleton.Height.int(118)} />
  </div>
}
