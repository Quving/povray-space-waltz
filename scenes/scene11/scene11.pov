// scene 11

#include "colors.inc"
#include "transforms.inc"
#include "util.inc" // our own macros

#declare Scene_Length = 17; // seconds

global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

// models
#include "space_wallpaper.inc" // background
#include "orion_cabin.inc"
#include "human.inc"
#include "pen.inc"

light_source {
    <0, 1.8, 4.8>
    color rgb <1,1,1>
}

// light_source {
//     <0, 1.8, 0.3>
//     color rgb <1,1,1>
// }

object {
    #local FRONT_DOOR_OPENESS = 0;
    Orion_Cabin()
}

object { // sitting human
    #local DEBUG_ALL_JOINTS = false;

    #include "sitting_human_animation.inc"

    #local LEFT_ARM_ROT = z * -75;
    #local LEFT_LOWER_ARM_ROT = <0, 60, 45>;
    #local LEFT_HAND_ROT = <90, 30, 0>;
    // #local LEFT_LOWER_ARM_ROT = Left_Lower_Arm_Rotation(Time());
    // #local LEFT_HAND_ROT = Left_Hand_Rotation(Time());
    #local RIGHT_ARM_ROT = z * -75;
    #local RIGHT_LOWER_ARM_ROT = <0, 105, 30>;
    #local RIGHT_HAND_ROT = <90, -90, 0>;
    #local LEFT_LEG_ROT = z * -90;
    #local LEFT_LOWER_LEG_ROT = z * 75;
    #local RIGHT_LEG_ROT = z * -90;
    #local RIGHT_LOWER_LEG_ROT = z * 75;

    Human()
    translate <-1, 0.5, 5.3>
}

object { // walking human
    #local DEBUG_ALL_JOINTS = false;

    #include "walking_human_animation.inc"

    #local LEFT_ARM_ROT = z * -85;
    #local LEFT_LOWER_ARM_ROT = 0;
    #local LEFT_HAND_ROT = 0;
    #local RIGHT_ARM_ROT = z * -85;
    #local RIGHT_LOWER_ARM_ROT = 0;
    #local RIGHT_HAND_ROT = 0;
    #local LEFT_LEG_ROT = 0;
    #local LEFT_LOWER_LEG_ROT = 0;
    #local RIGHT_LEG_ROT = 0;
    #local RIGHT_LOWER_LEG_ROT = 0;

    Human()

    no_shadow

    scale 0.8
    rotate y * 180
    translate Walking_Human_Position(Time())
}

object {
    Pen
    scale 0.02

    #include "pen_animation.inc"
    rotate Pen_Rotation(Time())
    translate Pen_Position(Time())
}

#declare CAMERA_SCENE = camera {
    perspective
    location <0, 1.4, 7>
    // location <0, 1.4, 6>
    right 16/9*x
    angle 70
    look_at Walking_Human_Position(Time())
}

camera { CAMERA_SCENE }

Trace_Position_And_Rotation_Spline(Pen_Position, Pen_Rotation, 11, 0.05)
