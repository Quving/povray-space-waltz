// scene 10

#include "colors.inc"
#include "transforms.inc"
#include "util.inc" // our own macros

#declare Scene_Length = 6; // seconds

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

#declare CAMERA_SCENE = camera {
    #local VAR_CAMERA_HEIGHT = 0.44;
    #local VAR_CAMERA_Z = 1.6 + 0.05 * clock;
    perspective
    location <0.7, VAR_CAMERA_HEIGHT, VAR_CAMERA_Z>
    right 16/9*x
    angle 70
    // look_at <0, 0.6, 1.6>
    look_at <0, VAR_CAMERA_HEIGHT + 0.1, VAR_CAMERA_Z>
}

camera { CAMERA_SCENE }

light_source {
    <0, 1.8, 4.8>
    color rgb <1,1,1>
}

object {
    #local FRONT_DOOR_OPENESS = 0;
    Orion_Cabin()
}

object { // walking human
    #local DEBUG_ALL_JOINTS = true;

    #include "walking_human_animation.inc"

    // #local LEFT_LEG_ROT = Walking_Human_Left_Leg_Rotation(Time());
    // #local LEFT_LOWER_LEG_ROT = Walking_Human_Left_Lower_Leg_Rotation(Time());
    // #local LEFT_FOOT_ROT = Walking_Human_Left_Foot_Rotation(Time());
    // #local RIGHT_LEG_ROT = Walking_Human_Right_Leg_Rotation(Time());
    // #local RIGHT_LOWER_LEG_ROT = Walking_Human_Right_Lower_Leg_Rotation(Time());
    // #local RIGHT_FOOT_ROT = Walking_Human_Right_Foot_Rotation(Time());

    Human()

    scale 0.8
    rotate y * 180
    // translate Walking_Human_Position(Time())
    translate <0, 1.45, 1.6 + 0.05 * clock>
}
