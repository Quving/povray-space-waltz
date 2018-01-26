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

#macro Control_Desk(position, dimension)
    box{ position, dimension
        texture{
            pigment{color rgb<1,1,1>}
            finish {diffuse 0.9}
        }
    }
#end // macro

#macro Button1(position, dimension, color_)
    box {
        position, dimension
        texture{
            pigment{ color color_ }
            finish {diffuse 0.9}
        }
    }
#end // macro


/* Returns a union with a m x n button arrangement. */
#macro Button1_Set (rows, columns, color_)
    #local PADDING = 0.2;
    union {
        #for (idx_x, 1, columns, 1)
            #for(idx_y, 1, rows, 1)
                object {
                Button1 (0, <BUTTON_x, BUTTON_y, BUTTON_z>, color_)
                translate <(BUTTON_x + PADDING)*idx_x, (BUTTON_x + PADDING ) * idx_y, -BUTTON_z>
            }
            #end // for
        #end // for
    }
#end // macro

union {
    /* Button parameter. */
    #local BUTTON_x = 1; // half width in x
    #local BUTTON_y = 1; // total height
    #local BUTTON_z = 0.25; // length in z

    /* Control desk parameter. */
    #local CONTROL_DESK_x = 7.5; // half width in x
    #local CONTROL_DESK_y = 2.5; // total height
    #local CONTROL_DESK_z = 0.25; // length in z

    /* Control desk object. */
    object {
        Control_Desk(0, <CONTROL_DESK_x, CONTROL_DESK_y, CONTROL_DESK_z>)
        scale 3
    }

    /* Button1 Set 1 */
    object {
        Button1_Set(4,4, Red)
    }
}


