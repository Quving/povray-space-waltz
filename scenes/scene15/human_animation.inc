#declare Left_Lower_Arm_Rotation = spline {
    natural_spline
    -0.2, <0, 105, 30>, // control start
    0.00, <0, 105, 30>, // control start
    3.75, <120, 45, 0>,
    4.75, <120, 90, 0>,
    5.75, <120, 45, 0>,
    6.75, <120, 90, 0>, // end
    7.75, <120, 60, 0>,
    9.50, <0, 105, 30>, // control start
    10.20, <120, 45, 0>  // control end
}

#declare Left_Arm_Rotation = spline {
    natural_spline
    -0.2, <0, 0, -75>,
    0.00, <0, 0, -75>,
    4.00, <90, 30, 40>,
    8.00, <90, 40, 40>,
    9.50, <0, 0, -75>, // control start
    10.00, <0, 0, -75>,
    10.20, <0, 0, -75>
}

#declare Left_Hand_Rotation = spline {
    natural_spline
    -0.2, <90, 30, 0>, // control start
    0.0, <90, 30, 0>,  // start
    3.5, <90, 45, 0>,
    6.5, <90, 35, 0>,
    7.5, <90, 50, 0>,
    8.5, <90, 45, 0>,
    9.5, <90, -90, 0>, // end
    10.2, <90, 30, 0>  // control end
}
