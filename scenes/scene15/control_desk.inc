#include "colors.inc"
#include "dev_environment.inc"

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

union {
    /* Control desk parameter. */
    #local CONTROL_DESK_x = 15.0; // half width in x
    #local CONTROL_DESK_y = 2.0; // total height
    #local CONTROL_DESK_z = 0.25; // length in z

    /* Control desk object. */
    object {
        Control_Desk(0, rgb<39/255, 37/255, 40/255>)
        scale 3
    }

    object {
        Button_Set_Left()
        translate <0, 0, 0>
    }

    object {
        Button_Set_Middle()
        translate <15, 0, 0>
    }
    translate <-30, 0 ,0>
}


