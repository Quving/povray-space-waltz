#macro Arm()
    #local Arm_Seg_Red_Length = 6;
    #local Arm_Seg_Green_Length = 4;
    #local Arm_Seg_Blue_Length = 2;

    union {
        object {
            cylinder {
                0, y * Arm_Seg_Red_Length, 0.5
                pigment { color Red }
            }
        }

        #if (Debug_Joints)
            Draw_Debug_Axis(Arm_Seg_Red_Length)
        #end

        union {
            object {
                cylinder {
                    0, y * Arm_Seg_Green_Length, 0.4
                    pigment { color Green }
                }
            }

            #if (Debug_Joints)
                Draw_Debug_Axis(Arm_Seg_Green_Length)
            #end

            union {
                object {
                    cylinder {
                        0, y * Arm_Seg_Blue_Length, 0.3
                        pigment { color Blue }
                    }
                }

                #if (Debug_Joints)
                    Draw_Debug_Axis(Arm_Seg_Blue_Length)
                #end

                rotate Arm_Seg_Blue_Rotation
                translate y * Arm_Seg_Green_Length
            }

            rotate Arm_Seg_Green_Rotation
            translate y * Arm_Seg_Red_Length
        }

        rotate Arm_Seg_Red_Rotation
    }
#end
