global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

#include "colors.inc"

//---------------------------------------------------------------

camera {
    perspective
    location <1,1,-1> * 5
    look_at <0,0,0>
    right x*(image_width/image_height)
}

light_source {
    <0.5, 0.8, -1> * 10
    color rgb 1
}

background { Grey }

box { // window
    0, <1, 1, 0.001>
    texture {
        pigment { rgbf <0.98, 0.98, 0.98, 0.9> }
        finish {
            diffuse 0.1
            reflection 0.2
            specular 0.8
            roughness 0.0003
            phong 1
            phong_size 400
        }
    }
}

box {
    z * 0.05, <2, 2, 1>
    texture {
        pigment{ color Red}
        finish { phong 0.1}
    } // end of texture
}
