#include "colors.inc"
#include "util.inc"

global_settings {
    assumed_gamma 1
}

camera {
    location <1, 1, -1> * 5
    right 16/9 * x
    look_at <0,0,0>
}

light_source {
    <0.5, 0.8, -1> * 10
    color rgb 1
}

background { Grey }

#include "orion_cabin.inc"

object {
    OBJ_Orion_Cabin
}

Draw_YZ_Plane()
