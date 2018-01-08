#declare camera1 = camera {
    perspective
    location <1, 1, -1> * 15
    angle 10
    right 16/9*x
    look_at 0
}

#declare camera2 = camera {
    perspective
    location <0, 0, -1> * 15
    right 16/9*x
    look_at 0
}

camera { camera1 }
