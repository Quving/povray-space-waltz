#include "colors.inc"

global_settings {
    assumed_gamma 1
}

camera {
    location <1, 0.5, -1> * 3
    right 16/9 * x
    look_at <0,0,0>
}

light_source {
    <0.5, 0.8, -1> * 10
    color rgb 1
}

background { Grey }

#include "human.inc"

object {
    #local DEBUG_ALL_JOINTS = false;

    Human()
}
