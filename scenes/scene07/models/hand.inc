#declare NULL = sphere {
    0, 0.0000001
    pigment {
        rgbft 1
    }
}

#declare TEST_TEX = texture {
    pigment { color White }
    finish {
        ambient 0.1
        diffuse 0.85
        phong 1
    }
}

#macro Finger(Seg_Lengths, Seg_Rotations)
    /* Create a finger made out of 3 segments.
    @Param Seg_Lengths is an array holding the lengths of the individual segments
    @Param Seg_Rotations is an array holding the rotation vectors of the individual segments (relative to the previous segment)

    counting starts at the palm
    */

    union {
        object { // segment 0
            cylinder {
                0, y * Seg_Lengths[0], 0.5
                texture { TEST_TEX }
            }
        }

        #ifdef (Debug_Joints)
            Draw_Debug_Axis(Seg_Lengths[0])
        #end

        union {
            object { // segment 1
                cylinder {
                    0, y * Seg_Lengths[1], 0.4
                    texture { TEST_TEX }
                }
            }

            #ifdef (Debug_Joints)
                Draw_Debug_Axis(Seg_Lengths[1])
            #end

            union {
                object { // segment 2
                    cylinder {
                        0, y * Seg_Lengths[2], 0.3
                        texture { TEST_TEX }
                    }
                }

                #ifdef (Debug_Joints)
                    Draw_Debug_Axis(Seg_Lengths[2])
                #end

                // small hack to mute warning regarding too few objects in csg.
                object { NULL }

                rotate Seg_Rotations[2]
                translate y * Seg_Lengths[1]
            }

            rotate Seg_Rotations[1]
            translate y * Seg_Lengths[0]
        }

        rotate Seg_Rotations[0]
    }
#end

#macro Thumb(Seg_Length, Seg_Rotation)
    /*
    Length and Rotation are specified using arrays with at least two elements eachs
    */
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

            // small hack to mute warning regarding too few objects in csg.
            object { NULL }

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
    #local Finger_Lengths = array[5] {
        array[2] {3,2}, // thumb
        array[3] {4,2,1}, // index finger
        array[3] {4,2,1}, // middle finger
        array[3] {4,2,1}, // ring finger
        array[3] {3,1,1}  // pinky finger
    }
    #local ROT = array[3] {0, 0, 0}

    object {
        Thumb(Finger_Lengths[0], ROT)
        translate x * 4
        translate y * -2
    }
    object {
        Finger(Finger_Lengths[1], ROT)
        translate x * 3
    }
    object {
        Finger(Finger_Lengths[2], ROT)
        translate x * 2
        translate y * 0.5
    }
    object {
        Finger(Finger_Lengths[3], ROT)
        translate x * 1
        translate y * 0.25
    }
    object {
        Finger(Finger_Lengths[4], ROT)
        translate x * 0
        translate y * -0.25
    }
#end

Hand()
