global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

// #include "transforms.inc"

#include "../../models/orion_POV_geom.inc"
#include "../../models/StationV_POV_geom.inc"
#include "../../models/space_wallpaper.inc"

camera {
    location <-7000, -1500, -8000>
    right x * 1
    up y * 1.414213562
    look_at <0, 0, -1000>
    rotate <60, 0, 0>
}

light_source {
    <-7000,-1500,-8000>
    color rgb <1,1,1>*1.6
    rotate <90, 0, 0>
    rotate <0, -100, 0>
}

union {
    object {
        orion_

        rotate x * 90
        translate <0, 0, -6000>
        rotate <90, 250, 0>
        translate <0, -3500, 0>
        rotate <0, -190, 0>
    }

    object {
        StationV_

        rotate <90, 0, 0>
        rotate <0, -100, 0>
    }
}
