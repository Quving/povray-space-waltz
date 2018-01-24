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

    #local VAR_CABIN_HEIGHT = 2.5; // height of human model is 2.32 units

    // external declaration
    #local VAR_WALKWAY_WIDTH = 1;
    #local VAR_WALKWAY_LENGTH = 10;
    #local VAR_WALKWAY_HEIGHT = 0.4;

    #macro Walkway()
        box {
            0, <VAR_WALKWAY_WIDTH, VAR_WALKWAY_HEIGHT, VAR_WALKWAY_LENGTH>
            texture { Simple_Color(Grey) }
            translate -x * VAR_WALKWAY_WIDTH / 2 // center on the x axis
        }
    #end // macro Walkway

    #macro Floor()
        plane {
            y, 0
            texture { Simple_Color(Grey) }
        }
    #end // macro Floor

    #macro Seat()
        #local VAR_SEATING_SURFACE_WIDTH = 0.7; // human torso is 0.6 wide
        #local VAR_SEATING_SURFACE_LENGTH = 0.4;
        #local VAR_ARMREST_HEIGHT = 0.3;
        #local VAR_ARMREST_LENGTH = 0.3;
        #local VAR_ARMREST_WIDTH = 0.1;
        #local VAR_BASE_HEIGHT = 0.3;
        #local VAR_BASE_WIDTH = 0.2;

        union {
            union { // seating surface and back rest
                box { // seating surface
                    0, <VAR_SEATING_SURFACE_WIDTH, 0.1, VAR_SEATING_SURFACE_LENGTH>
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

            texture { Simple_Color(Grey) }

            translate y * VAR_BASE_HEIGHT // lift the model so that it sits on the ground plane
        }
    #end // macro Seat

    #macro Seat_Row_One_Side()
        union {
            #for (i, 1, 2)
                object {
                    Seat()
                    translate x * i
                }
            #end
        }
    #end // macro Seat_Row_One_Side

    #macro Ceiling_Above_Walkway() // with lights
        box {
            0, <VAR_WALKWAY_WIDTH, VAR_WALKWAY_HEIGHT, VAR_WALKWAY_LENGTH>
            texture { Simple_Color(Grey) }
            translate -x * VAR_WALKWAY_WIDTH / 2 // center on the x axis
            translate y * (VAR_CABIN_HEIGHT + VAR_WALKWAY_HEIGHT)
        }

        // TODO lights
    #end // macro Ceiling_Above_Walkway

    #macro Tilted_Ceiling_Above_Seats() // with lights (right side)
        box {
            0, <2.5, VAR_WALKWAY_HEIGHT, VAR_WALKWAY_LENGTH>
            texture { Simple_Color(Grey) }
            rotate z * -15
            translate y * VAR_CABIN_HEIGHT
            translate x * VAR_WALKWAY_WIDTH / 2 // center on the x axis
        }
        // TODO lights
    #end // macro Tilted_Ceiling_Above_Seats

    // wall with windows
    // tilted wall beside seats
    // front and back wall
    // door

    /* centered parts */
    Floor()
    Walkway()
    Ceiling_Above_Walkway()

    /* right side of the cabin */
    Seat_Row_One_Side()

    Tilted_Ceiling_Above_Seats()
}
