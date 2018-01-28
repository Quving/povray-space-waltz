#declare Walking_Human_Position = spline {
    natural_spline
    // <0, 1.45, 1.6> standing
    -0.2, <0, 1.42, 1.6>, // control start
     0.0, <0, 1.42, 1.6>,  // start
     6.0, <0, 1.42, 1.6>, // end
     6.2, <0, 1.42, 1.6>  // control end
}

#declare Walking_Human_Left_Leg_Rotation = spline {
    natural_spline
    -0.2, z * 15, // control start
     0.0, z * 15, // start
     6.0, 0 // end
     6.2, 0 // control end
}
#declare Walking_Human_Left_Lower_Leg_Rotation = spline {
    natural_spline
    -0.2, 0, // control start
     0.0, 0, // start
     6.0, 0 // end
     6.2, 0 // control end
}
#declare Walking_Human_Left_Foot_Rotation = spline {
    natural_spline
    -0.2, z * -15, // control start
     0.0, z * -15, // start
     6.0, 0 // end
     6.2, 0 // control end
}
#declare Walking_Human_Right_Leg_Rotation = spline {
    natural_spline
    -0.2, z * -10, // control start
     0.0, z * -10, // start
     6.0, 0 // end
     6.2, 0 // control end
}
#declare Walking_Human_Right_Lower_Leg_Rotation = spline {
    natural_spline
    -0.2, z * 25, // control start
     0.0, z * 25, // start
     6.0, 0 // end
     6.2, 0 // control end
}
#declare Walking_Human_Right_Foot_Rotation = spline {
    natural_spline
    -0.2, 0, // control start
     0.0, 0, // start
     6.0, 0 // end
     6.2, 0 // control end
}
