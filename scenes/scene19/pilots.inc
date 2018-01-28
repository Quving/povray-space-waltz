#include "colors.inc"
#include "human.inc"

#macro Sitting_Human_Right()
    object { // sitting human
        #local DEBUG_ALL_JOINTS = false;
        #include "human_animation.inc"
        #local LEFT_ARM_ROT =  z* -75;
        #local LEFT_LOWER_ARM_ROT = <0, 105, 30>;
        #local LEFT_HAND_ROT = <90,-90, 0>;
        #local RIGHT_ARM_ROT = z * -75;
        #local RIGHT_LOWER_ARM_ROT = <0, 105, 30>;
        #local RIGHT_HAND_ROT = <90, -90, 0>;
        #local LEFT_LEG_ROT = z * -90;
        #local LEFT_LOWER_LEG_ROT = z * 75;
        #local RIGHT_LEG_ROT = z * -90;
        #local RIGHT_LOWER_LEG_ROT = z * 75;

        Human()
    }
#end

#macro Sitting_Human_Left()
    object { // sitting human
        #local DEBUG_ALL_JOINTS = false;
        #include "human_animation.inc"
        #local LEFT_ARM_ROT = z * -75;
        #local LEFT_LOWER_ARM_ROT = <0, 105, 30>;
        #local LEFT_HAND_ROT = <90,-90, 0>;
        #local RIGHT_ARM_ROT = z * -75;
        #local RIGHT_LOWER_ARM_ROT = <0, 105, 30>;
        #local RIGHT_HAND_ROT = <90, -90, 0>;
        #local LEFT_LEG_ROT = z * -90;
        #local LEFT_LOWER_LEG_ROT = z * 75;
        #local RIGHT_LEG_ROT = z * -90;
        #local RIGHT_LOWER_LEG_ROT = z * 75;

        Human()
    }
#end

#declare SITTING_PILOTS = union {
    /* Sitting Human. */
    object {
        #local Scene_Length = 10;
        Sitting_Human_Right()
        scale 13
        rotate <0, 180, 0>
        translate < 45,1+0.5*13, 35- 0.3*13 >
    }
    object {
        #local Scene_Length = 10;
        Sitting_Human_Left()
        scale 13
        rotate <0, 180, 0>
        translate < 14,1+0.5*13, 35- 0.3*13 >
    }
}


