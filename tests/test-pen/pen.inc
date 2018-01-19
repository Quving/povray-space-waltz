#declare Pen = union {
    #macro Simple_Color(Color)
        pigment { color Color }
        finish {
            ambient 0.1
            diffuse 0.85
            phong 0.2
        }
    #end // macro Simple_Color

    #local CYLINDER_LENGTH = 10;
    #local CONE_LENGTH = 2;

    cylinder {
        0, x * CYLINDER_LENGTH, 0.5
        texture { Simple_Color(Black) }
    }

    cone {
        x * CYLINDER_LENGTH, 0.5, x * (CYLINDER_LENGTH + CONE_LENGTH), 0.1
        texture { Simple_Color(Gold) }
    }

    #for (i, 0, 2)
        cylinder {
            0, y * 0.51, 0.35
            texture { Simple_Color(Silver) }
            translate x * (CYLINDER_LENGTH - 4 + i)
        }
    #end // for loop
}
