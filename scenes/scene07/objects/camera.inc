#declare camera1 = camera {
    perspective
    location <1, 1, -1> * 15
    look_at 0
    right 16/9*x
}

#declare camera2 = camera {
    perspective
    location <0, 0, -1> * 15
    look_at 0
    right 16/9*x
}
