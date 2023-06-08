open Mui

@react.component
let make = () => {
  <div>
    <Skeleton variant=Text />
    <Skeleton variant=Circular width={Number(40.)} height={Number(40.)} />
    <Skeleton variant=Rectangular width={Number(210.)} height={Number(118.)} />
  </div>
}
