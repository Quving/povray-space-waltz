#local LEFT_LOWER_ARM_ROT = <0, 60, 45>;
#local LEFT_HAND_ROT = <90, 30, 0>;

#declare Left_Lower_Arm_Rotation = spline {
    natural_spline
    -0.20, <0, 60, 45>, // control start
     0.00, <0, 60, 45>,  // start
     3.00, <0, 45, 45>,
     6.00, <0, 60, 45>,
    10.00, <0, 45, 30>,
    14.00, <0, 60, 45>,
    17.00, <0, 45, 30>,
    20.00, <0, 50, 40>, // end
    20.20, <0, 50, 40>  // control end
}

#declare Left_Hand_Rotation = spline {
    natural_spline
    -0.2, <90, 30, 0>, // control start
     0.0, <90, 30, 0>,  // start
     3.5, <90, 45, 0>,
     6.5, <90, 15, 0>,
    10.5, <90, 45, 0>,
    14.5, <90, 15, 0>,
    17.5, <90, 45, 0>,
    20.0, <90, 30, 0>, // end
    20.2, <90, 30, 0>  // control end
}
