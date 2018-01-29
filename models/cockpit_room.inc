#include "colors.inc"
#include "human.inc"

#macro Control_Desk(dimension, color_)
    box{ 0, <CONTROL_DESK_x, CONTROL_DESK_y, CONTROL_DESK_z>
        texture{
            pigment{color color_}
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
#macro Button_Matrix (rows, columns, padding, color_)
    union {
        #for (idx_x, 0, columns-1, 1)
        #for(idx_y, 0, rows-1, 1)
        object {
            Button1 (0, <BUTTON_x, BUTTON_y, BUTTON_z>, color_)
            translate <(BUTTON_x + padding)*idx_x, (BUTTON_y + padding ) * idx_y, -BUTTON_z>
        }
        object {
            box { 0, 0 }
        }
    #end // for
#end // for
translate <X,Y,Z>
}
#end // macro

#macro Button_Set_Middle()
    union{
        /* Last button row */
        #local BUTTON_x = 1;
        #local BUTTON_y = 1;
        #local BUTTON_z = 0.25;
        #local BUTTON_PADDING = 0.4;
        #local X = 0;
        #local Y = 0;
        #local Z = 0;

        object {
            Button_Matrix(1,4, BUTTON_PADDING, MandarinOrange)
        }

        /* Before last button row */
        #local Y = 1 *(BUTTON_PADDING + BUTTON_y); // Update X because BUTTON_x changed.
        object {
            Button_Matrix(3,4, BUTTON_PADDING, DarkTurquoise)
        }

        /* Little rectable button. */
        #local BUTTON_x = 1.5;
        #local BUTTON_y = 0.5;
        #local X = 3*(BUTTON_PADDING+BUTTON_x);
        #local Y = 0;
        object {
            Button_Matrix(1,1, BUTTON_PADDING, MandarinOrange)
        }

        /* Last button row */
        #local X = 4*(BUTTON_PADDING+BUTTON_x);
        object {
            Button_Matrix(1,4, BUTTON_PADDING, DarkTan)
        }

        /* Before last button row */
        #local Y = BUTTON_PADDING + (1 * BUTTON_y); // Update X because BUTTON_x changed.
        object {
            Button_Matrix(1,4, BUTTON_PADDING, Grey)
        }

        /* DarkBlue button matrix. */
        #local Y = 2 *(BUTTON_PADDING + BUTTON_y); // Update X because BUTTON_x changed.
        object {
            Button_Matrix(2,4, BUTTON_PADDING, NewMidnightBlue)
        }

        /* DarkBlue button matrix. */
        #local X = 9*(BUTTON_PADDING+ BUTTON_x);
        object {
            Button_Matrix(1,1, BUTTON_PADDING, White)
        }

        #local Y = 2 *(BUTTON_PADDING + BUTTON_y); // Update X because BUTTON_x changed.
        #local X = 10*(BUTTON_PADDING+ BUTTON_x);

        object {
            Button_Matrix(4,1, BUTTON_PADDING, Orange)
        }

        #local Y = 0;
        #local X = 11*(BUTTON_PADDING+ BUTTON_x);

        #local BUTTON_x = 1.3;
        #local BUTTON_y = 0.8;
        object {
            Button_Matrix(1,4, BUTTON_PADDING, OrangeRed)
        }

        /* Before last button row */
        #local Y = 1 *(BUTTON_PADDING + BUTTON_y); // Update X because BUTTON_x changed.
        object {
            Button_Matrix(3,4, BUTTON_PADDING, Navy)
        }
    }
#end

#macro Button_Set_Left()
    union{
        /* Last button row */
        #local BUTTON_x = 2;
        #local BUTTON_y = 0.75;
        #local BUTTON_z = 0.25;
        #local BUTTON_PADDING = 0.2;
        #local X = 0;
        #local Y = 0;
        #local Z = 0;
        object {
            Button_Matrix(1,1, BUTTON_PADDING, VeryDarkBrown)
        }

        #local X = 1*(BUTTON_PADDING+BUTTON_x);
        #local Y = 0;

        object {
            Button_Matrix(3,4, BUTTON_PADDING, Gold)
        }

        /* Little rectable button. */
        #local X = 5*(BUTTON_PADDING+BUTTON_x);
        #local Y = 0;
        #local BUTTON_x = 1.5;
        #local BUTTON_y = 0.5;
        object {
            Button_Matrix(1,1, BUTTON_PADDING, MandarinOrange)
        }
    }
#end

#macro Box(dimension, color_)
    object {
        box{
            0, dimension
            texture{
                pigment{color color_}
                finish {diffuse 0.9}
            }
        }
    }
#end

#declare CONTROL_DESK= union {
    /* Control desk parameter. */
    #local CONTROL_DESK_x = 45; // half width in x
    #local CONTROL_DESK_y = 6; // total height
    #local CONTROL_DESK_z = 0.75; // length in z

    /* Control desk object. */
    object {
        Control_Desk(0, rgb<39/255, 37/255, 40/255>)
    }

    object {
        Button_Set_Left()
        translate <0, 0, 0>
    }

    object {
        Button_Set_Middle()
        translate <15, 0, 0>
    }

    translate <0, 0 ,0>
}

#declare DISPLAY= union {
    object { Box(<18,6,1>, rgb<10/255, 10/255, 10/255>) }
    object { Box(<4.5, 4.5, 1>, CadetBlue*((sin(clock*2000)+1.5))) translate <0.5, 1, -0.1>}
    object { Box(<4.5, 4.5, 1>, CadetBlue*((sin(clock*2000+8)+1.5))) translate <13, 1, -0.1>}
}

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
    object { CONTROL_DESK rotate <-65, 0,0> scale <-1,1,1> translate <(COCKPIT_x+45)/2,25,43>}
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




