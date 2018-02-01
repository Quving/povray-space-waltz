#declare PLANET = sphere {
    0, 5000
    rotate <clock*15, 0, 0>
    pigment { color rgb <0,0.75,0.75> }
    finish { ambient 0.00 diffuse 1}
    texture{
        pigment{
            bozo turbulence 0.075
            octaves 6  omega 0.7 lambda 2
            color_map {
                [0.0  color rgb <0.95, 0.95, 0.95> ]
                [0.05  color rgb <1, 1, 1>*1.25 ]
                [0.15 color rgb <0.85, 0.85, 0.85> ]
                [0.55 color rgbt <1, 1, 1, 1>*1 ]
                [1.0 color rgbt <1, 1, 1, 1>*1 ]
            }
        }
        finish { ambient 0 diffuse 1}
    }
}


