#include "colors.inc"
sphere
{
    0,100
    pigment { rgbt 1 } hollow
    interior
    { media
        { emission 1
            density
            { spherical density_map
                { [0 rgb 0]
                    [60 Orange]
                    [80 Red]
                    [100 Yellow]
                }
                scale 100
            }
        }
    }
    translate <0,0,1000>
}


background { Black }

/* Within cockpit. */
light_source {
    <30,22,10>
    color rgb 0.2
}

camera {
    location 0
    right 16/9 * x
    look_at  < 0,0,1>
}



