[@react.component]
let make = () => {
  MaterialUi_Lab.(
    <div>
      <Skeleton variant=`Text />
      <Skeleton variant=`Circle width={`Int(40)} height={`Int(40)} />
      <Skeleton variant=`Rect width={`Int(210)} height={`Int(118)} />
    </div>
  );
};