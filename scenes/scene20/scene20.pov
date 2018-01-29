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
   location <10000,0,-1000>
    rotate<-30,0,0>
    look_at <1,1,-1000>
    translate<-14000*clock,0,0>
    rotate<20*clock,0,0>
}

light_source {
    <0, 0, -4000>
    color rgb <1, 1, 1>
    rotate <0, 0, 15>
}

union {
    object {
        orion_
        rotate <0, -90 * clock, 15>
        translate <0, 0, -2200>
    }

    object {
        StationV_
    }

    rotate <0, -400*clock, 15>
}
