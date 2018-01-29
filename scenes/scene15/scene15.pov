global_settings {
    assumed_gamma 1
}

#include "colors.inc"
#include "cockpit_room.inc"
#include "../../models/StationV_POV_geom.inc" //Geometry
#include "pilots.inc"
#include "space_wallpaper.inc"
#include "util.inc"

#local Scene_Length = 15;
#declare CAMERA_SPLINE = spline {
    natural_spline
    -0.20, <30, 18, 6.98>,
    0.00, <30, 18, 6.99>,
    2.00, <29.95, 18, 7>,
    8.00, <30.05, 18, 7>,
    9.00, <29.95, 18, 7>,
    10.00, <30.05, 18, 7>,
    13.0, <30, 18, 23>,
    15.0, <30, 18, 26.01>,
    18.0, <30, 18, 29.01>,
    20.0, <30, 18, 30.02>
    20.2, <30, 18, 31.04>
}
#declare LOOKAT_SPLINE = spline {
    natural_spline
    -0.2, <30, 16, 40>,
    0.00, <30, 16, 40>,
    /* 10.0, <30, 16, 40>, */
    15.0, <30, 12, 40>,
    16.0, <30, 11.22, 40>
    20.0, <30, 10.0, 40>
    21.1, <30, 9.8, 40>
}

#macro Time()
    Scene_Length * clock
#end // macro

camera {
    location CAMERA_SPLINE(Time())
    /* location <40,18, 0> */
    right 16/9 * x
    look_at  LOOKAT_SPLINE(Time())
    /* look_at <30,17, 10> */
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
    /* Trace_Position_Spline(CAMERA_SPLINE, 30, 0.5) */
    /* Trace_Position_Spline(LOOKAT_SPLINE, 30, 0.5) */
    #local STATION_POSITION = <7500, 5000, 50000>;
    object { COCKPIT translate <0, 0, 0> }
    object { WAVING_PILOTS }
    object { StationV_  rotate <0, 180, -20+clock*30> translate STATION_POSITION}
    Station_Hangar_Light()
}

