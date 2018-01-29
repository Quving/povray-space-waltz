global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

#include "space_wallpaper.inc"
#include "orion_POV_geom.inc"

#declare ORION_START_POSITION = < 2500, 1400, 1500>;
#declare ORION_END_POSITION = < 1800, 1400, 1500>;

camera {
    perspective
    right 16/9 * x
    location 0
    look_at z
    rotate x * -90 * clock
}

light_source {
    <0, 100, 0>
    color rgb <1, 1, 1>
}

object {
    orion_ // nose points to z
    rotate <0, 0, 130> // rotation
    translate z * 4000 * (clock - 0.4)  // movement
    rotate <-75, -85, 0> // movement direction
    translate <1500, 2000, 1000> // startposition
}

sphere {
    <0, -7*12000, 11*10000>, 130000
    // rotate <clock*15, 0, 0>
    pigment { rgb <0,0.75,0.75> }
    texture{
        pigment{ bozo turbulence 1.75
            octaves 6  omega 0.7 lambda 2
            color_map {
                [0.0  color rgb <0.95, 0.95, 0.95> ]
                [0.05  color rgb <1, 1, 1>*1.25 ]
                [0.15 color rgb <0.85, 0.85, 0.85> ]
                [0.55 color rgbt <1, 1, 1, 1>*1 ]
                [1.0 color rgbt <1, 1, 1, 1>*1 ]
            }
        }
        scale 5000
        #if (version = 3.7 )  finish {emission 1 diffuse 0}
        #else                 finish { ambient 1 diffuse 0}
        #end
    }
}
