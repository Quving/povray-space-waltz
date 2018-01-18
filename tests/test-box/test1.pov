#version 3.7;

global_settings {
    //This setting is for alpha transparency to work properly.
    //Increase by a small amount if transparent areas appear dark.
    assumed_gamma 1
}

camera {
    location <1, 1, -1> * 3
    right 16/9 * x
    look_at <0,0,0>
}

light_source {
    <0.5, 0.8, -1>
    color rgb 1
    //point_at <0, 0, 0>
}

#include "colors.inc"

box {
    0, 1
    texture {
        pigment { color White }
        finish {
            ambient 0.1
            diffuse 0.85
            phong 1
        }
    }
    translate -0.5
}
