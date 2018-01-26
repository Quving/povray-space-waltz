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

/* Button parameter. */
#declare BUTTON_x = 0.5; // half width in x
#declare BUTTON_y = 1; // total height
#declare BUTTON_z = 1; // length in z

/* Control desk parameter. */
#declare CONTROL_DESK_scale = 2;
#declare CONTROL_DESK_x = 5 * CONTROL_DESK_scale; // half width in x
#declare CONTROL_DESK_y = 3 * CONTROL_DESK_scale; // total height
#declare CONTROL_DESK_z = 1 * CONTROL_DESK_scale; // length in z

#declare CONTROL_DESK = box{ <-CONTROL_DESK_x,0,0>, <CONTROL_DESK_x,CONTROL_DESK_y,CONTROL_DESK_z>
    texture{ pigment{color rgb<1,1,1>}
        finish {diffuse 0.9}
    }
}

#declare BUTTON = box{ <-BUTTON_x,0,0>,< BUTTON_x,BUTTON_y,BUTTON_z>
    texture{ pigment{color Red}
        finish {diffuse 0.9}
    }
}

object { CONTROL_DESK }
object { BUTTON translate <0,0,-5>}



