sphere {
    <0, 0, 5>, 1
    pigment { rgbt 1 }
    interior {
        media {
            intervals 8
            samples 5,10
            emission 1
            density {
                spherical
                density_map {
                    [0 rgb 0]
                    [0.6 Orange]
                    [0.8 Red]
                    [1 Yellow]
                }
            }
        }
    }
    hollow
}

/*
sphere {
    <10000, -12000, 20000>, 16000
    pigment { rgb <0,0.75,0.75> }
    texture{
        pigment{ bozo turbulence 1.25
            octaves 6  omega 0.7 lambda 2
            color_map {
                [0.0  color rgb <0.95, 0.95, 0.95> ]
                [0.05  color rgb <1, 1, 1>*1.25 ]
                [0.15 color rgb <0.85, 0.85, 0.85> ]
                [0.55 color rgbt <1, 1, 1, 1>*1 ]
                [1.0 color rgbt <1, 1, 1, 1>*1 ]
            }

        }
        scale 5000
        #if (version = 3.7 )  finish {emission 1 diffuse 0}
        #else                 finish { ambient 1 diffuse 0}
        #end
    }
}
*/