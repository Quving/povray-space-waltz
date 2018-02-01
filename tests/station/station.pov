global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

#include "../../models/StationV_POV_geom.inc"
#include "colors.inc"

#declare CAMERA_AND_LIGHT_LOCATION = <1, 1, -1> * 4000;

camera {
    location CAMERA_AND_LIGHT_LOCATION
    right 16/9 * x
    look_at 0
}

light_source {
    CAMERA_AND_LIGHT_LOCATION
    color rgb <1, 1, 1>
}

object {
    StationV_
}

background { White }
