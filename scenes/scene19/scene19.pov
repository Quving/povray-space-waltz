global_settings {
    assumed_gamma 1
}

#include "colors.inc"
#include "pilots.inc"
#include "cockpit_room.inc"
#include "../../models/StationV_POV_geom.inc" //Geometry

#include "space_wallpaper.inc"


#macro Time()
    Scene_Length * clock
#end // macro

#local Scene_Length = 10;


#macro Rotate_Cockpit()
    rotate <0,0, clock*10>
#end

camera {
    location <30, 18, 7>
    right 16/9 * x
    look_at <30,13 ,40>
    Rotate_Cockpit()
}

#declare LIGHTSOURCE_SPLINE = spline {
    natural_spline
    -0.20, <2000, 1000, 12000-1000>,
    0.00, <2000, 1000, 12000-1000>,
    10.00, <1000, 500, 9000-1000>,
    11.00, <1000, 500, 9000-1000>
}
light_source {
    <30,22,10>
    color rgb 0.2
    fade_distance 50
    fade_power 1
}

light_source {
    <-1000,750,2000>
    color rgb 0.5
}
light_source {
    LIGHTSOURCE_SPLINE(Time())
    color rgb 1
}
#declare STATION_SPLINE = spline {
    natural_spline
    -0.20, <2000, 1000, 12000>,
    0.00, <2000, 1000, 12000>,
    10.00, <1000, 500, 9000>,
    11.00, <1000, 500, 9000>
}

union {
    union {
        object { COCKPIT }
        object { SITTING_PILOTS }
        Rotate_Cockpit()
    }

    object { StationV_  rotate <0, 180, -40+clock*40> translate STATION_SPLINE(Time())}
    object { box {0 0}}
    translate <0, 0, 0>
}

