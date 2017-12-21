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
