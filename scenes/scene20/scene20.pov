global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

#include "../../models/space_wallpaper.inc"
#include "../../models/orion_POV_geom.inc"
#include "../../models/StationV_POV_geom.inc"
#include "transforms.inc"

camera {
    location 0
    look_at -x
    rotate <-45 - 5 * clock, 0, -15 - 45 * clock> // look up and tilt
    translate <10000 - 13000 * clock, -2200, 0> // move past the station
}

light_source {
    <3000, -3000, -10000>
    color rgb <1, 1, 1>
}

union {
    object {
        orion_
        scale 0.8
        rotate <0, 0, -90 - 90 * clock>
        translate <0, 0, -2700>
    }

    object {
        StationV_
        rotate <0, 180, 0>
    }

    rotate <0, 0, -400 * clock>
}
