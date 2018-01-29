global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

#include "space_wallpaper.inc"
#include "orion_POV_geom.inc"
#include "colors.inc"

camera {
    perspective
    right 16/9 * x
    location 0
    look_at z
    angle 93
    rotate x * -80 * clock
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

union {
    text {
        internal 2 " 2001: Space Waltz  "
        0.3, 0
        scale 2
    }

    text {
        internal 2 "2k18 POV-Ray Edition"
        0.3, 0
        translate <3.5, -1.5, 0>
    }

    texture {
        pigment { color White }
        finish {
            ambient 0.1
            diffuse 0.85
            phong 0.2
        }
    }

    translate <-8, -0.5, 0> // center it
    scale 100
    translate z * 1000
    rotate x * -75 // to be read from below
}
