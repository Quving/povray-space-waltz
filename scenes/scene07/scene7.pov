// scene 7

#include "colors.inc"
#include "transforms.inc"
#include "util.inc" // our own macros

global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

// models
#include "space_wallpaper.inc" // background
#include "orion_cabin.inc"
#include "human.inc"

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

#declare CAMERA_TEST = camera {
    perspective
    location VAR_CAMERA_LOCATION
    right 16/9*x
    look_at VAR_SITTING_HUMAN_POSITION
    // Rotate_Around_Trans(y * 180 * clock, <0, 2, 5>)
}

camera { CAMERA_SCENE }

light_source {
    // <0, 2, 5>
    VAR_CAMERA_LOCATION
    color rgb <1,1,1>
}

object {
    OBJ_Orion_Cabin
}

object { // sitting human
    #local DEBUG_ALL_JOINTS = true;

    #local LEFT_ARM_ROT = z * -75;
    #local LEFT_LOWER_ARM_ROT = <0, 60, 45>;
    #local LEFT_HAND_ROT = <90, 30, 0>;
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
