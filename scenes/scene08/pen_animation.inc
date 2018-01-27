#declare Pen_Position = spline {
    natural_spline
    -0.2, <0.1, 0.9, 5.7>, // control start
     0.0, <0.1, 0.9, 5.7>,  // start
     7.0, <0.15, 1, 5.7>, // end
     7.2, <0.15, 1, 5.7>  // control end
}

#declare Pen_Rotation = spline {
    natural_spline
    -0.2, <-90, 180, 75>, // control start
     0.0, <-90, 180, 75>,  // start
     7.0, <-90, 180, 85> // end
     7.2, <-90, 180, 85>  // control end
}
