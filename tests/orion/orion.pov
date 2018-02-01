global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

#include "../../models/orion_POV_geom.inc"
#include "colors.inc"

camera {
    location <1, 1, -1> * 400
    right 16/9 * x
    look_at 0
}

light_source {
    <1, 1, -1> * 500
    color rgb <1, 1, 1>
}

object {
    orion_
    translate z * 100
}

background { White }
