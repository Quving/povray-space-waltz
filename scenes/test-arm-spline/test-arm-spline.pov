// scene 3

#include "settings.inc"
#include "colors.inc"

//---------------------------------------------------------------

#include "space_wallpaper.inc" // background

camera {
    perspective
    location <0,0,-30>
    look_at <0,0,1>
    right x*(image_width/image_height)
}

light_source {
    <5,2,2>
    color rgb <1,1,1>
    parallel
    point_at <0,0,1>
}

#include "util.inc"
#include "arm_model.inc"

#declare Scene_Length = 6;

#declare Arm_Seg_Red_Rotation_Spline = spline {
    natural_spline
    0.0, 0, // control start
    0.0, 0, // start
    1.5, z*90
    3.0, z*180
    4.5, z*270
    6.0, 0, // end
    6.0, 0  // control end
}

#declare Arm_Seg_Green_Rotation_Spline = spline {
    natural_spline
    0, 0, // control start
    0, 0, // start
    1, <90, 0, -90>,
    2, <180, 0, 0>,
    3, <270, 0, 90>,
    4, <180, 0, 0>,
    5, <90, 0, -90>,
    6, 0, // end
    6, 0  // control end
}

#declare Arm_Seg_Blue_Rotation_Spline = spline {
    natural_spline
    0, 0, // control start
    0, 0, // start
    1, <180, 0, 0>,
    2, <270, 0, 0>,
    3, <315, 0, 0>,
    4, <345, 0, 0>,
    5, <360, 0, 0>,
    6, 0, // end
    6, 0  // control end
}

object {
    #local Arm_Seg_Red_Rotation = Arm_Seg_Red_Rotation_Spline(Time());
    #local Arm_Seg_Green_Rotation = Arm_Seg_Green_Rotation_Spline(Time());;
    #local Arm_Seg_Blue_Rotation = Arm_Seg_Blue_Rotation_Spline(Time());;

    Arm()
}
