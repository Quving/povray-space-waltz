#include "colors.inc"

#macro Get_Wall(dimension, color_)

#end // macro

#macro Floor(position, dimension, color_)
    box {
        position, dimension
        texture{
            pigment{ color color_ }
            finish {diffuse 0.9}
        }
    }
#end // macro


#macro Wall(dimension)
    object {
        box{
            0, dimension
            texture{
                pigment{color Grey}
                finish {diffuse 0.9}
            }
        }
    }
#end

#declare COCKPIT = union {
    /* Wall left. */
    object { Wall(<1,25,50>) translate 0 }
    /* Wall right. */
    object { Wall(<1,25,50>)  translate <45, 0, 0>}
    /* Wall front. */
    object { Wall(<45,15,1>)  translate <0, 0, 50>}
    /* Floor */
    object { Wall(<45,1,50>)  translate <0, 0, 0>}
    /* Control desk. */
    object {
        CONTROL_DESK
        rotate <60, 0,0>
        translate <0,10,40>
    }
}
