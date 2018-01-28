#declare Walking_Human_Position = spline {
    natural_spline
    -0.2, <0, 1.45, 1.65>, // control start
     0.0, <0, 1.45, 1.65>,  // start
    14.0, <0, 1.45, 4.3>, // end
    17.0, <0, 1.45, 4.3
    17.2, <0, 1.45, 4.3>  // control end
}

// sitting human position: <-1, 0.5, 5.3>

// #local LEFT_ARM_ROT = z * -85;
// #local LEFT_LOWER_ARM_ROT = 0;
// #local LEFT_HAND_ROT = 0;
// #local RIGHT_ARM_ROT = z * -85;
// #local RIGHT_LOWER_ARM_ROT = 0;
// #local RIGHT_HAND_ROT = 0;

#declare Left_Arm_Rotation = spline {
    natural_spline
    -0.2, <0, 0, -85>, // control start
     0.0, <0, 0, -85>,  // start
    17.0, <0, 0, -85>, // end
    17.2, <0, 0, -85>  // control end
}

#declare Left_Lower_Arm_Rotation = spline {
    natural_spline
    -0.2, <0, 0, 0>, // control start
     0.0, <0, 0, 0>,  // start
    17.0, <0, 0, 0>, // end
    17.2, <0, 0, 0>  // control end
}

#declare Left_Hand_Rotation = spline {
    natural_spline
    -0.2, <0, 0, 0>, // control start
     0.0, <0, 0, 0>,  // start
    17.0, <0, 0, 0>, // end
    17.2, <0, 0, 0>  // control end
}

#declare Right_Arm_Rotation = spline {
    natural_spline
    -0.2, <0, 0, -85>, // control start
     0.0, <0, 0, -85>,  // start
    17.0, <0, 0, -85>, // end
    17.2, <0, 0, -85>  // control end
}
