#include "colors.inc"

global_settings {
    assumed_gamma 1
}

camera {
    location <1, 1, -1> * 20
    right 16/9 * x
    look_at <0,0,0>
}

light_source {
    <0.5, 0.8, -1> * 50
    color rgb 1
}

background { Grey }

plane{ y, -1.5
    pigment{ checker Gray White }
}


