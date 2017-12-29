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

#declare TEST_TEX = texture {
    pigment { color White }
    finish {
        ambient 0.1
        diffuse 0.85
        phong 1
    }
}

#macro Finger(Seg_Length, Seg_Rotation)
    union {
        object {
            cylinder {
                0, y * Seg_Length[0], 0.5
                texture { TEST_TEX }
            }
        }

        #ifdef (Debug_Joints)
            Draw_Debug_Axis(Seg_Length[0])
        #end

        union {
            object {
                cylinder {
                    0, y * Seg_Length[1], 0.4
                    texture { TEST_TEX }
                }
            }

            #ifdef (Debug_Joints)
                Draw_Debug_Axis(Seg_Length[1])
            #end

            union {
                object {
                    cylinder {
                        0, y * Seg_Length[2], 0.3
                        texture { TEST_TEX }
                    }
                }

                #ifdef (Debug_Joints)
                    Draw_Debug_Axis(Seg_Length[2])
                #end

                rotate Seg_Rotation[2]
                translate y * Seg_Length[1]
            }

            rotate Seg_Rotation[1]
            translate y * Seg_Length[0]
        }

        rotate Seg_Rotation[0]
    }
#end

#macro Thumb(Seg_Length, Seg_Rotation)
//
// Length and Rotation are specified using arrays with at least two elements eachs
    union {
        object {
            cylinder {
                0, y * Seg_Length[0], 0.5
                texture { TEST_TEX }
            }
        }

        #ifdef (Debug_Joints)
            Draw_Debug_Axis(Seg_Length[0])
        #end

        union {
            object {
                cylinder {
                    0, y * Seg_Length[1], 0.4
                    texture { TEST_TEX }
                }
            }

            #ifdef (Debug_Joints)
                Draw_Debug_Axis(Seg_Length[1])
            #end

            rotate Seg_Rotation[1]
            translate y * Seg_Length[0]
        }

        rotate Seg_Rotation[0]
    }
#end

#macro Hand()
    #local Finger_Lengths = array[5][3] {
        {5,4,0}, // thumb
        {5,4,3}, // index finger
        {5,4,3}, // middle finger
        {5,4,3}, // ring finger
        {5,4,3}  // pinky finger
    }

#end

// #declare Hand_Left = object {
//     Hand()
// }

// #declare LEN = array[3] {5, 4, 3}
#declare ROT = array[3] {0, 0, 0}
// Finger(LEN, ROT)


#for (i, 1, 4)
#end
Finger(array[3] {5, 4, 3}, ROT)
object {
    Finger(array[3] {4, 3, 2}, ROT)
    translate x
}
object {
    Finger(array[3] {3, 2, 1}, ROT)
    translate x * 2
}
object {
    Finger(array[3] {3, 2, 1}, ROT)
    translate x * 3
}
object {
    Thumb(array[2] {5, 4}, ROT)
    translate x * 4
}
