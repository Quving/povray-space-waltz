#include "util.inc"

#declare OBJ_Orion_Cabin = union {
    #macro Simple_Color(Color)
        pigment { color Color }
        finish {
            ambient 0.1
            diffuse 0.85
            phong 0.2
        }
    #end // macro Simple_Color

    #local VAR_WALKWAY_WIDTH = 1;
    #local VAR_WALKWAY_LENGTH = 10;
    #local VAR_WALKWAY_HEIGHT = 0.4;

    #local WALKWAY = box {
        0, <VAR_WALKWAY_WIDTH, VAR_WALKWAY_HEIGHT, VAR_WALKWAY_LENGTH>
        texture { Simple_Color(White) }
        translate -x * VAR_WALKWAY_WIDTH / 2 // center on the x axis
    }

    #local FLOOR = plane {
        y, 0
        texture { Simple_Color(White) }
    }

    #local SEAT = union {
        #local VAR_SEATING_SURFACE_WIDTH = 0.7; // human torso is 0.6 wide
        #local VAR_SEATING_SURFACE_LENGTH = 0.4;
        #local VAR_ARMREST_HEIGHT = 0.3;
        #local VAR_ARMREST_LENGTH = 0.3;

        box { // seating surface
            0, <VAR_SEATING_SURFACE_WIDTH, 0.1, VAR_SEATING_SURFACE_LENGTH>
            translate -x * VAR_SEATING_SURFACE_WIDTH
        }

        box { // back rest
            0, <VAR_SEATING_SURFACE_WIDTH, 1, 0.1>
            translate -x * VAR_SEATING_SURFACE_WIDTH
            translate z * VAR_SEATING_SURFACE_LENGTH
        }

        box { // armrest
            0, <0.1, VAR_ARMREST_HEIGHT, VAR_ARMREST_LENGTH>
            translate -x * VAR_SEATING_SURFACE_WIDTH
            translate z * 0.1
        }

        texture { Simple_Color(White) }

        // translate x * VAR_SEATING_SURFACE_WIDTH
        // translate y * VAR_WALKWAY_HEIGHT

        translate x * -1
    }

    // ceiling above walkway (with lights)
    // tilted ceiling above seats (with lights)
    // wall with windows
    // tilted wall beside seats
    // front and back wall
    // door

    NULL
    NULL
    NULL

    WALKWAY
    // FLOOR
    // SEAT
}
