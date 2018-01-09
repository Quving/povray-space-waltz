#macro Human()
    /* comment */

    // set default rotation vectors, if they are not defined in
    // the scope in which this macro is being called
    #ifndef (TORSO_ROT) #local TORSO_ROT = 0; #end
    #ifndef (HEAD_ROT) #local HEAD_ROT = 0; #end
    #ifndef (LEFT_ARM_ROT) #local LEFT_ARM_ROT = 0; #end
    #ifndef (LEFT_LOWER_ARM_ROT) #local LEFT_LOWER_ARM_ROT = 0; #end
    #ifndef (LEFT_HAND_ROT) #local LEFT_HAND_ROT = 0; #end
    #ifndef (RIGHT_ARM_ROT) #local RIGHT_ARM_ROT = 0; #end
    #ifndef (RIGHT_LOWER_ARM_ROT) #local RIGHT_LOWER_ARM_ROT = 0; #end
    #ifndef (RIGHT_HAND_ROT) #local RIGHT_HAND_ROT = 0; #end
    #ifndef (LEFT_LEG_ROT) #local LEFT_LEG_ROT = 0; #end
    #ifndef (LEFT_LOWER_LEG_ROT) #local LEFT_LOWER_LEG_ROT = 0; #end
    #ifndef (LEFT_FOOT_ROT) #local LEFT_FOOT_ROT = 0; #end
    #ifndef (RIGHT_LEG_ROT) #local RIGHT_LEG_ROT = 0; #end
    #ifndef (RIGHT_LOWER_LEG_ROT) #local RIGHT_LOWER_LEG_ROT = 0; #end
    #ifndef (RIGHT_FOOT_ROT) #local RIGHT_FOOT_ROT = 0; #end

    // helper variables to make the code more readable
    #local LEFT = true;
    #local RIGHT = false;

    // helper object to prevent warnings regarding to few objects in CSGs
    #local NULL = sphere {
        0, 0.0000001
        pigment {
            rgbft 1
        }
    }

    // define default texture, if it is not specified in the scope
    // in which this macro is being called
    #ifndef (TEXTURE)
        #local TEXTURE = texture {
            pigment { color White }
            finish {
                ambient 0.1
                diffuse 0.85
                phong 1
            }
        }
    #end

    #macro Leg(side)
        #local UPPER_LEG_LENGTH = 0.4;
        #local LOWER_LEG_LENGTH = 0.4;

        union {
            cylinder { // UpperLeg
                0, x * UPPER_LEG_LENGTH, 0.1
                texture { TEXTURE }
            }

            union {
                cylinder { // LowerLeg
                    0, x * LOWER_LEG_LENGTH, 0.08
                    texture { TEXTURE }
                }

                union { // Foot
                    box {
                        0, <0.24, 0.12, 0.2>
                        texture { TEXTURE }
                        translate -<0, 0.06, 0.1>
                    }

                    NULL

                    #if (side = LEFT)
                        rotate LEFT_FOOT_ROT
                    #else
                        rotate RIGHT_FOOT_ROT
                    #end

                    translate x * LOWER_LEG_LENGTH
                }

                #if (side = LEFT)
                    rotate LEFT_LOWER_LEG_ROT
                #else
                    rotate RIGHT_LOWER_LEG_ROT
                #end

                translate x * UPPER_LEG_LENGTH
            }

            #if (side = LEFT)
                rotate LEFT_LEG_ROT
            #else
                rotate RIGHT_LEG_ROT
            #end
        }
    #end

    #macro Arm(side)
        #local UPPER_ARM_LENGTH = 0.4;
        #local LOWER_ARM_LENGTH = 0.4;

        union {
            cylinder { // UpperArm
                0, x * UPPER_ARM_LENGTH, 0.1
                texture { TEXTURE }
            }

            union {
                cylinder { // LowerArm
                    0, x * LOWER_ARM_LENGTH, 0.08
                    texture { TEXTURE }
                }

                union { // Hand
                    box {
                        0, <0.24, 0.12, 0.2>
                        texture { TEXTURE }
                        translate -<0, 0.06, 0.1>
                    }

                    NULL

                    /*
                    box {
                        0, <0.09, 0.12, 0.04>
                        texture { TEXTURE }
                        translate <0, 0.06, 0.1>*3
                    }
                    */

                    #if (side = LEFT)
                        rotate LEFT_HAND_ROT
                    #else
                        rotate RIGHT_HAND_ROT
                    #end

                    translate x * LOWER_ARM_LENGTH
                }

                #if (side = LEFT)
                    rotate LEFT_LOWER_ARM_ROT
                #else
                    rotate RIGHT_LOWER_ARM_ROT
                #end

                translate x * UPPER_ARM_LENGTH
            }

            #if (side = LEFT)
                rotate LEFT_ARM_ROT
            #else
                rotate RIGHT_ARM_ROT
            #end
        }
    #end

    #macro Head()
        #local NECK_HEIGHT = 0.1;

        union {
            cylinder {
                0, <0, NECK_HEIGHT, 0>, 0.1
                texture { TEXTURE }
            }

            cylinder {
                0, <0, 0.3, 0>, 0.2
                texture { TEXTURE }
                scale <1, 1, 1>
                translate y * NECK_HEIGHT
            }

            rotate HEAD_ROT
        }
    #end

    #macro Torso()
        #local TORSO_HEIGHT = 1;
        #local TORSO_WIDTH = 1;

        object {
            union {
                cylinder { // the torso itself
                    0, <0, TORSO_HEIGHT, 0>, 0.5
                    texture { TEXTURE }
                    scale <1, 1, 0.45>
                }

                object {
                    Head()
                    translate y * TORSO_HEIGHT
                }

                object { // left arm
                    Arm(LEFT)
                    //...
                    translate x * TORSO_WIDTH * 0.5
                    translate y * TORSO_HEIGHT * 0.9
                }

                object { // right arm
                    Arm(RIGHT)
                    //...
                    rotate z * 180
                    translate x * TORSO_WIDTH * -0.5
                    translate y * TORSO_HEIGHT * 0.9
                }

                object { // left leg
                    Leg(LEFT)
                    //...
                    rotate y * -90
                    rotate x * 90
                    translate x * TORSO_WIDTH * 0.3
                }

                object { // right leg
                    Leg(RIGHT)
                    //...
                    rotate y * -90
                    rotate x * 90
                    translate x * TORSO_WIDTH * -0.3
                }
            }
        }
    #end

    object {
        Torso()
        rotate TORSO_ROT
    }
#end
