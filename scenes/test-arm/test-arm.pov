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

#macro Arm()
    union {
        #local Arm_Seg_Red_Length = <0, 6, 0>;
        #local Arm_Seg_Green_Length = <0, 4, 0>;
        #local Arm_Seg_Blue_Length = <0, 2, 0>;

        object {
            cylinder {
                0, Arm_Seg_Red_Length, 1*0.5
                pigment { color Red }
            }
        }

        union {
            object {
                cylinder {
                    0, Arm_Seg_Green_Length, 0.8*0.5
                    pigment { color Green }
                }
            }

            union {
                object {
                    cylinder {
                        0, Arm_Seg_Blue_Length, 0.6*0.5
                        pigment { color Blue }
                    }
                }

                rotate Arm_Seg_Blue_Rotation
                translate Arm_Seg_Green_Length
            }

            rotate Arm_Seg_Green_Rotation
            translate Arm_Seg_Red_Length
        }

        rotate Arm_Seg_Red_Rotation
    }
#end

object {
    #local Arm_Seg_Red_Rotation = z*15;
    #local Arm_Seg_Green_Rotation = z*30;
    #local Arm_Seg_Blue_Rotation = z*45;

    Arm()
}

object {
    #local Arm_Seg_Red_Rotation = z*-30;
    #local Arm_Seg_Green_Rotation = z*-45;
    #local Arm_Seg_Blue_Rotation = z*15;

    Arm()
}
