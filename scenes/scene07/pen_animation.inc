#declare Pen_Position = spline {
    #local Z_POS = 5.7;
    #local START = <-0.4, 1.5, Z_POS>;
    #local END = <0.1, 0.9, Z_POS>;

    natural_spline
    -2.00, <-0.39, 1.7, Z_POS>, // control start
     0.00, START,  // start
     2.00, <-0.37, 1.3, Z_POS>, // pen moves downward into view
    12.00, <-0.25, 0.95, Z_POS>,
    18.00, <0, 0.85, Z_POS>, // tiefpunkt der parabel
    20.00, END, // end
    20.20, END  // control end
}

#declare Pen_Rotation = spline {
    natural_spline
    -0.20, <-90, 180, -15>, // control start
     0.00, <-90, 180, -15>,  // start
     8.00, <-90, 180, 0>, // pen is horizontal
    20.00, <-90, 180, 75>, // end
    20.20, <-90, 180, 75>  // control end
}
