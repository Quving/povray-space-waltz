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
    location <10000 - 13000 * clock,0 , 0>
    // rotate <-30 + 20 * clock, 0, -60 * clock>
    rotate <-40, 0, 0>
    translate y * -2200
    look_at <-2000, 1000, 0>
}

light_source {
    <0, 3000, -10000>
    color rgb <1, 1, 1>
    rotate <15, 0, 0>
}

// cylinder {
//     <10000, 0, 0>, <-10000, -5000, 1000>, 100
// }

// sphere {
//     0, 2200
// }

union {
    object {
        orion_
        rotate <0, 0, -90 * clock>
        translate <0, 0, -2200>
    }

    object {
        StationV_
        rotate <0, 180, 0>
    }

    rotate <0, 0, -400 * clock>
}
