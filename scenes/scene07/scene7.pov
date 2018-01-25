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

camera {
    perspective
    location <0, 2, 5>
    right 16/9*x
    look_at VAR_SITTING_HUMAN_POSITION
    // Rotate_Around_Trans(y * 180 * clock, <0, 2, 5>)
}

light_source {
    <0, 2, 5>
    color rgb <1,1,1>
}

object {
    OBJ_Orion_Cabin
}

object { // sitting human
    #local DEBUG_ALL_JOINTS = true;

    #local LEFT_LEG_ROT = z * -90;
    #local LEFT_LOWER_LEG_ROT = z * 75;
    #local RIGHT_LEG_ROT = z * -90;
    #local RIGHT_LOWER_LEG_ROT = z * 75;

    Human()
    translate VAR_SITTING_HUMAN_POSITION
}
