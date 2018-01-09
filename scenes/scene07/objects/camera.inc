#declare CAMERA_1 = camera {
    perspective
    location <1, 1, -1> * 15
    angle 15
    right 16/9*x
    look_at 0
}

#declare CAMERA_2 = camera {
    perspective
    location <0, 0, -1> * 15
    right 16/9*x
    look_at 0
}

camera { CAMERA_1 }
