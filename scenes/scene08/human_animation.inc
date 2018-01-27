#declare Left_Lower_Arm_Rotation = spline {
    natural_spline
    -0.2, <0, 50, 40>, // control start
     0.0, <0, 50, 40>,  // start
     3.5, <0, 40, 30>,
     7.0, <0, 50, 40>, // end
     7.2, <0, 50, 40>  // control end
}

#declare Left_Hand_Rotation = spline {
    natural_spline
    -0.2, <90, 30, 0>, // control start
     0.0, <90, 30, 0>,  // start
     4.0, <90, 45, 0>,
     7.0, <90, 30, 0>, // end
     7.2, <90, 30, 0>  // control end
}
