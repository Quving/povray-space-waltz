global_settings {
    assumed_gamma 1
}

#include "colors.inc"
#include "control_desk.inc"
/* #include "dev_environment.inc" */
#include "cockpit_room.inc"
#include "../../models/StationV_POV_geom.inc" //Geometry


background { Black }

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

union {
    object { COCKPIT translate <0, 0, 0> }
    object { StationV_  rotate <0, 180, 0> translate <7500, 5000, 50000>}
}

