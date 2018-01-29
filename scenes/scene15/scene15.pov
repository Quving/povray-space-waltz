global_settings {
    assumed_gamma 1
}

#include "colors.inc"
#include "cockpit_room.inc"
#include "../../models/StationV_POV_geom.inc" //Geometry
#include "pilots.inc"
#include "space_wallpaper.inc"

camera {
    location <30, 18, 7>
    right 16/9 * x
    look_at <30,13 ,40>
}

#macro Station_Hangar_Light()
    light_source {
        <STATION_POSITION.x, STATION_POSITION.y, STATION_POSITION.z -1000>
        color rgb 0.5
    }
#end

/* Within cockpit. */
light_source {
    <30,22,10>
    color rgb 0.2
    fade_distance 50
    fade_power 1
}

union {
    #local STATION_POSITION = <7500, 5000, 50000>;
    object { COCKPIT translate <0, 0, 0> }
    object { WAVING_PILOTS }
    object { StationV_  rotate <0, 180, -20+clock*30> translate STATION_POSITION}
    Station_Hangar_Light()
}

