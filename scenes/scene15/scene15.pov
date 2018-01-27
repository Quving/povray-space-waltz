#include "colors.inc"
#include "control_desk.inc"
#include "dev_environment.inc"
#include "cockpit_room.inc"

#macro POI_3RD_PILOT()
    camera {
        location <30, 18, 7>
        right 16/9 * x
        look_at <30,13 ,40>
    }

    light_source {
        <30, 15, 10>
        color rgb 1
    }
#end
POI_3RD_PILOT()

object {
    COCKPIT
    translate <0, 0, 0>
}

