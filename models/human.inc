#include "util.inc"

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
            #if (DEBUG_ALL_JOINTS)
                pigment { color rgbf <0.5, 0.5, 0.5, 0.9> }
            #else
                pigment { color White }
            #end
            finish {
                ambient 0.1
                diffuse 0.85
                phong 1
            }
        }
    #end // ifndef (TEXTURE)

    #macro If_Debug_Draw_Axis(Length)
        #if (DEBUG_ALL_JOINTS)
            Draw_Debug_Axis(Length)
        #else
            NULL
        #end
    #end // macro If_Debug_Draw_Axis

    #macro If_Left_Rotate_Else_Rotate(Left_Rotate, Right_Rotate)
        #if (side = LEFT)
            rotate Left_Rotate
        #else
            rotate Right_Rotate
        #end
    #end // macro If_Left_Rotate_Else_Rotate

    #macro Leg(side)
        #local UPPER_LEG_LENGTH = 0.65;
        #local LOWER_LEG_LENGTH = 0.55;
        #local FOOT_LENGTH = 0.3;

        union {
            union { // UpperLeg
                sphere { // hip joint
                    0, 0.1
                    texture { TEXTURE }
                }

                cone { // UpperLeg
                    0, 0.1 x * UPPER_LEG_LENGTH, 0.09
                    texture { TEXTURE }
                }

                union {
                    union { // LowerLeg
                        sphere { // knee
                            0, 0.09
                            texture { TEXTURE }
                        }

                        cone { // LowerLeg
                            0, 0.09, x * LOWER_LEG_LENGTH, 0.08
                            texture { TEXTURE }
                        }

                        union {
                            union { // Foot
                                sphere { // ankle
                                    0, 0.08
                                    texture { TEXTURE }
                                }

                                box { // foot
                                    0, <0.12, -FOOT_LENGTH, 0.2>
                                    texture { TEXTURE }
                                    translate <0, 0.08, -0.1>
                                }

                                // apply rotation of the joint to customize the pose
                                If_Left_Rotate_Else_Rotate(LEFT_FOOT_ROT, RIGHT_FOOT_ROT)
                            }

                            If_Debug_Draw_Axis(FOOT_LENGTH * 0.8)

                            translate x * LOWER_LEG_LENGTH
                        }

                        // apply rotation of the joint to customize the pose
                        If_Left_Rotate_Else_Rotate(LEFT_LOWER_LEG_ROT, RIGHT_LOWER_LEG_ROT)
                    }

                    If_Debug_Draw_Axis(LOWER_LEG_LENGTH * 0.8)

                    translate x * UPPER_LEG_LENGTH
                }

                // apply rotation of the joint to customize the pose
                If_Left_Rotate_Else_Rotate(LEFT_LEG_ROT, RIGHT_LEG_ROT)
            }

            If_Debug_Draw_Axis(UPPER_LEG_LENGTH * 0.8)

            // translation has to be done by caller
        }
    #end

    #macro Arm(side)
        #local UPPER_ARM_LENGTH = 0.45;
        #local LOWER_ARM_LENGTH = 0.4;
        #local HAND_LENGTH = 0.24;
        #local HAND_WIDTH = 0.18;
        #local HAND_HEIGHT = 0.08;

        union {
            union { // UpperArm, LowerArm and Hand
                sphere { // shoulder
                    0, 0.1
                    texture { TEXTURE }
                }

                cone { // UpperArm
                    0, 0.1, x * UPPER_ARM_LENGTH, 0.09
                    texture { TEXTURE }
                }

                union {
                    union { // LowerArm and Hand
                        sphere { // elbow
                            0, 0.09
                            texture { TEXTURE }
                        }

                        cone { // LowerArm
                            0, 0.09, x * LOWER_ARM_LENGTH, 0.08
                            texture { TEXTURE }
                        }

                        union {
                            union { // Hand
                                sphere { // wrist
                                    0, 0.08
                                    texture { TEXTURE }
                                }

                                box { // (simple) hand
                                    0, <HAND_LENGTH, HAND_HEIGHT, HAND_WIDTH>
                                    texture { TEXTURE }
                                    translate -<0, HAND_HEIGHT / 2, HAND_WIDTH / 2>
                                }

                                // TODO split into palm, fingers and thumb

                                // apply rotation of the joint at the wrist
                                If_Left_Rotate_Else_Rotate(LEFT_HAND_ROT, RIGHT_HAND_ROT)
                            }

                            If_Debug_Draw_Axis(HAND_LENGTH * 0.8)

                            translate x * LOWER_ARM_LENGTH
                        }

                        // apply rotation of the joint at the elbow
                        If_Left_Rotate_Else_Rotate(LEFT_LOWER_ARM_ROT, RIGHT_LOWER_ARM_ROT)
                    }

                    If_Debug_Draw_Axis(LOWER_ARM_LENGTH * 0.8)

                    translate x * UPPER_ARM_LENGTH
                }

                // apply rotation of the joint (and debug axis) at the shoulder
                If_Left_Rotate_Else_Rotate(LEFT_ARM_ROT, RIGHT_ARM_ROT + x * 180)
            }

            // add axis that move and rotate with the arm
            If_Debug_Draw_Axis(UPPER_ARM_LENGTH * 0.8)

            // translation has to be done by caller
        }
    #end

    #macro Head()
        #local NECK_HEIGHT = 0.1;
        #local HEAD_HEIGHT = 0.3;

        union {
            cylinder { // neck
                0, <0, NECK_HEIGHT, 0>, 0.1
                texture { TEXTURE }
            }

            union {
                cylinder { // head
                    0, <0, HEAD_HEIGHT, 0>, 0.2
                    texture { TEXTURE }
                    scale <1, 1, 1>
                }

                sphere { // right eye
                    -z * 0.2, 0.025
                    texture { TEXTURE }
                    translate y * HEAD_HEIGHT * 0.6
                    rotate y * 20
                }

                sphere { // left eye
                    -z * 0.2, 0.025
                    texture { TEXTURE }
                    translate y * HEAD_HEIGHT * 0.6
                    rotate y * -20
                }

                translate y * NECK_HEIGHT
            }

            rotate HEAD_ROT
        }
    #end

    #macro Torso()
        #local TORSO_HEIGHT = 0.7;
        #local TORSO_WIDTH = 0.6;

        object {
            union {
                cylinder { // the torso itself
                    0, <0, TORSO_HEIGHT, 0>, 0.5
                    texture { TEXTURE }
                    scale <TORSO_WIDTH, 1, 0.3>
                }

                object { // head
                    Head()
                    translate y * TORSO_HEIGHT
                }

                object { // left arm
                    Arm(LEFT)
                    translate x * TORSO_WIDTH * 0.5
                    translate y * TORSO_HEIGHT * 0.9
                }

                object { // right arm
                    Arm(RIGHT)
                    rotate z * 180
                    rotate x * 180
                    translate x * TORSO_WIDTH * -0.5
                    translate y * TORSO_HEIGHT * 0.9
                }

                object { // left leg
                    Leg(LEFT)
                    rotate y * -90
                    rotate x * 90
                    translate x * TORSO_WIDTH * 0.3
                }

                object { // right leg
                    Leg(RIGHT)
                    rotate y * -90
                    rotate x * 90
                    translate x * TORSO_WIDTH * -0.3
                }

                // If_Debug_Draw_Axis(TORSO_HEIGHT * 0.4)
            }
        }
    #end

    object {
        Torso()
        rotate TORSO_ROT
    }
#end
