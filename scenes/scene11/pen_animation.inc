#declare Pen_Position = spline {
    natural_spline
    -0.2, <-0.4, 1.4, 5.3>, // control start
     0.0, <-0.4, 1.4, 5.3>,  // start
     2.0, <-0.43, 1.39, 5.3>
     3.0, <-0.44, 1.38, 5.3>
     4.0, <-0.45, 1.35, 5.3>
     6.0, <-0.43, 1.25, 5.3>
    17.0, <-0.35, 1.2, 5.3>, // end
    17.2, <-0.35, 1.2, 5.3>  // control end
}

#declare Pen_Rotation = spline {
    natural_spline
    -0.2, <90, 0, 5>, // control start
     0.0, <90, 0, 5>,  // start
    17.0, <90, 0, 90>, // end
    17.2, <90, 0, 90>  // control end
}
