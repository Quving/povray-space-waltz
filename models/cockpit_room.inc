#include "colors.inc"
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

#macro Seat()
    #local VAR_SEATING_SURFACE_WIDTH = 0.7; // human torso is 0.6 wide
    #local VAR_SEATING_SURFACE_LENGTH = 0.4;
    #local VAR_ARMREST_HEIGHT = 0.3;
    #local VAR_ARMREST_LENGTH = 0.3;
    #local VAR_ARMREST_WIDTH = 0.1;
    #local VAR_BASE_HEIGHT = 0.3;
    #local VAR_BASE_WIDTH = 0.2;
    #local MAT_SEAT_TEXTURE = texture {
        pigment{color Grey}
    }

    union {
        union { // seating surface and back rest
            box { // seating surface
                z * -0.2, <VAR_SEATING_SURFACE_WIDTH, 0.1, VAR_SEATING_SURFACE_LENGTH>
            }

            box { // back rest
                0, <VAR_SEATING_SURFACE_WIDTH, 1, 0.1>
                translate z * VAR_SEATING_SURFACE_LENGTH
            }

            translate -x * VAR_SEATING_SURFACE_WIDTH / 2
        }

        union { // armrests
            box { // left armrest
                0, <VAR_ARMREST_WIDTH, VAR_ARMREST_HEIGHT, VAR_ARMREST_LENGTH>
                translate x * VAR_SEATING_SURFACE_WIDTH / 2
            }

            box { // right armrest
                0, <-0.1, VAR_ARMREST_HEIGHT, VAR_ARMREST_LENGTH>
                translate -x * VAR_SEATING_SURFACE_WIDTH / 2
            }

            translate z * (VAR_SEATING_SURFACE_LENGTH - VAR_ARMREST_LENGTH)
        }

        box { // base
            0, <VAR_BASE_WIDTH, -VAR_BASE_HEIGHT, VAR_SEATING_SURFACE_LENGTH>
            translate -x * VAR_BASE_WIDTH / 2
        }

        texture { MAT_SEAT_TEXTURE }

        translate y * VAR_BASE_HEIGHT // lift the model so that it sits on the ground plane
    }
#end // macro Seat

#declare COCKPIT = union {
    #local COCKPIT_x = 60;
    #local COCKPIT_y = 28;
    #local COCKPIT_z = 50;
    /* Wall left. */
    object { Wall(<1,COCKPIT_y,COCKPIT_z>) translate 0 }
    /* Wall right. */
    object { Wall(<1,COCKPIT_y,COCKPIT_z>)  translate <COCKPIT_x, 0, 0>}
    /* Wall front. */
    object { Wall(<COCKPIT_x, 15, 1>)  translate <0, 0, COCKPIT_z>}
    /* Wall front. */
    object { Wall(<COCKPIT_x, 2, 1>)  translate <0, COCKPIT_y-2, COCKPIT_z>}

    /* Floor bottom. */
    object { Wall(<COCKPIT_x, 1, COCKPIT_z>)  translate <0, 0, 0>}
    /* Ceiling. */
    object { Wall(<COCKPIT_x, 1, COCKPIT_z>)  translate <0, COCKPIT_y, 0>}

    /* Control desk. */
    object { CONTROL_DESK rotate <60, 0,0> translate <(COCKPIT_x-45)/2,12,45>}
    object { DISPLAY translate <20,6,40> }

    /* Seats left */
    object {
        Seat()
        scale 13
        rotate <0, 180, 0>
        translate <14,1, 35>
    }
    /* Seat right. */
    object {
        Seat()
        scale 13
        rotate <0, 180, 0>
        translate <45,1, 35>
    }

}



