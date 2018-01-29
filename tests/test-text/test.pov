#include "colors.inc"

global_settings {
    assumed_gamma 1
}

camera {
    location z * -20
    right 16/9 * x
    look_at <0,0,0>
}

light_source {
    <0.5, 0.8, -1> * 10
    color rgb 1
}

background { Grey }

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

    translate <-8, -0.5, 0>
}
