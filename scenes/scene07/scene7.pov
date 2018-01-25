// scene 7

#include "colors.inc"
#include "util.inc"

global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

// models
#include "space_wallpaper.inc" // background
#include "orion_cabin.inc"
#include "human.inc"

camera {
    perspective
    location <0, 0, -1> * 15
    right 16/9*x
    look_at 0
}

light_source {
    <0.5, 0.8, -1> * 5
    color rgb <1,1,1>
}

object {
    OBJ_Orion_Cabin
}

object {
    // #local LEFT_LOWER_ARM_ROT = x*90;
    #local DEBUG_ALL_JOINTS = false;
    // #local LEFT_ARM_ROT = z * 90;
    // #local RIGHT_ARM_ROT = z * 90;
    // #local LEFT_LOWER_ARM_ROT = y * 45;

    Human()
}
