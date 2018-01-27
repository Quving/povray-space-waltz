#include "colors.inc"
#include "control_desk.inc"
#include "dev_environment.inc"
#include "orion_cabin.inc"
#include "cockpit_room.inc"


#declare COCKPIT = union {
    object {
        CONTROL_DESK
        rotate <60, 0,0>
        translate <0,10,40>
    }
    object { ROOM }
}

object {
    COCKPIT
    translate <-10, 0,-10>
}
