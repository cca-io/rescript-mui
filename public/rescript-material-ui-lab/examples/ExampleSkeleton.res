open MaterialUi_Lab;

@react.component
let make = () => {
  <div>
    <Skeleton variant=#Text />
    <Skeleton
      variant=#Circle
      width={Skeleton.Width.int(40)}
      height={Skeleton.Height.int(40)}
    />
    <Skeleton
      variant=#Rect
      width={Skeleton.Width.int(210)}
      height={Skeleton.Height.int(118)}
    />
  </div>
};