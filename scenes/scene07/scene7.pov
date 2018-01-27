// scene 7

#include "colors.inc"
#include "transforms.inc"
#include "util.inc" // our own macros

#declare Scene_Length = 20; // seconds

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

#declare VAR_SITTING_HUMAN_POSITION = <-1, 0.5, 5.3>;
// #declare VAR_CAMERA_LOCATION = <-1.5, 1.8, 4.8>;
#declare VAR_CAMERA_LOCATION = <0, 1.8, 4.8>;

#declare CAMERA_SCENE = camera {
    perspective
    location <0.2, 0.8, 6.3>
    right 16/9*x
    angle 100
    look_at <-1.2, 1.4, 0>
}

#declare CAMERA_TEST_1 = camera {
    perspective
    location VAR_CAMERA_LOCATION
    right 16/9*x
    look_at VAR_SITTING_HUMAN_POSITION
    // Rotate_Around_Trans(y * 180 * clock, <0, 2, 5>)
}

#declare CAMERA_TEST_2 = camera {
    perspective
    location <0, 2, 7>
    right 16/9*x
    look_at <-0.5, 1.5, 6>
}

camera { CAMERA_SCENE }
// camera { CAMERA_TEST_2 }

light_source {
    // <0, 2, 5>
    VAR_CAMERA_LOCATION
    color rgb <1,1,1>
}

object {
    #local FRONT_DOOR_OPENESS = 0;
    Orion_Cabin()
}

object { // sitting human
    #local DEBUG_ALL_JOINTS = true;

    #include "human_animation.inc"

    #local LEFT_ARM_ROT = z * -75;
    #local LEFT_LOWER_ARM_ROT = Left_Lower_Arm_Rotation(Time());
    #local LEFT_HAND_ROT = Left_Hand_Rotation(Time());
    #local RIGHT_ARM_ROT = z * -75;
    #local RIGHT_LOWER_ARM_ROT = <0, 105, 30>;
    #local RIGHT_HAND_ROT = <90, -90, 0>;
    #local LEFT_LEG_ROT = z * -90;
    #local LEFT_LOWER_LEG_ROT = z * 75;
    #local RIGHT_LEG_ROT = z * -90;
    #local RIGHT_LOWER_LEG_ROT = z * 75;

    Human()
    translate VAR_SITTING_HUMAN_POSITION
}

object {
    Pen
    scale 0.02

    #include "pen_animation"
    rotate Pen_Rotation(Time())
    translate Pen_Position(Time())
}

Trace_Position_And_Rotation_Spline(Pen_Position, Pen_Rotation, 21, 0.05)
