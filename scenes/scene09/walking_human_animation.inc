#declare Walking_Human_Position = spline {
    natural_spline
    -0.2, <0, 1.45, -0.5>, // control start
     0.0, <0, 1.45, -0.5>,  // start
     3.0, <0, 1.45, -0.2>,
     5.0, <0, 1.45, 0>,
     5.5, <0, 1.45, 0.15>,
     7.0, <0, 1.45, 0.15>,
     7.5, <0, 1.45, 0.25>,
    10.0, <0, 1.45, 0.5>, // end
    10.2, <0, 1.45, 0.5>  // control end
}

#declare Walking_Human_Left_Leg_Rotation = spline {
    natural_spline
    -0.2, 0, // control start
     0.0, 0, // start
     3.5, z * 5,
     5.5, z * 45,
     7.5, z * 5,
    10.0, 0, // end
    10.2, 0 // control end
}

#declare Walking_Human_Left_Lower_Leg_Rotation = spline {
    natural_spline
    -0.2, 0, // control start
     0.0, 0, // start
    10.0, 0, // end
    10.2, 0 // control end
}

#declare Walking_Human_Right_Leg_Rotation = spline {
    natural_spline
    -0.2, 0, // control start
     0.0, 0, // start
     3.5, z * -5,
     5.5, z * -45,
     7.5, z * -5,
    10.0, 0, // end
    10.2, 0 // control end
}

#declare Walking_Human_Right_Lower_Leg_Rotation = spline {
    natural_spline
    -0.2, 0, // control start
     0.0, 0, // start
    10.0, 0, // end
    10.2, 0 // control end
}
