#include "colors.inc"
#include "util.inc"

global_settings {
    assumed_gamma 1
}

camera {
    #local VAR_CAMERA_HEIGHT = 0.4;

    orthographic
    location <0, VAR_CAMERA_HEIGHT, -5>
    right 16/9 * x
    look_at <0, VAR_CAMERA_HEIGHT, 0>
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
object {
    Centered_Box(<0.01, 10, 2>, 0, Red)
    no_shadow
}
object {
    Centered_Box(<10, 0.01, 2>, 0, Red)
    no_shadow
}
