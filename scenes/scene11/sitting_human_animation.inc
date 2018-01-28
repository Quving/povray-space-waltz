#declare Left_Lower_Arm_Rotation = spline {
    natural_spline
    -0.2, <0, 60, 45>, // control start
     0.0, <0, 60, 45>,  // start
    17.0, <0, 60, 45>, // end
    17.2, <0, 60, 45>  // control end
}

#declare Left_Hand_Rotation = spline {
    natural_spline
    -0.2, <90, 30, 0>, // control start
     0.0, <90, 30, 0>,  // start
    17.0, <90, 30, 0>, // end
    17.2, <90, 30, 0>  // control end
}
