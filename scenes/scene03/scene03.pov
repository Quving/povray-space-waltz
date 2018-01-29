#local Temp_version = version;
#version 3.7;
global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}


#include "colors.inc"
#include "planet.inc"
//---------------------------------------------------------------

#include "orion_POV_geom.inc" //Geometry
#include "space_wallpaper.inc"

#local Scene_Length=7;
#macro Time()
    Scene_Length * clock
#end // macro

#declare SUN =
sphere {
    0,400
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
                scale 120
            }
        }
    }
}

#declare SUN_GLOW =   sphere {<0,0,0>, 1000
    texture { pigment { color White }}
    finish { ambient 1 diffuse 1}
    pigment { rgbt 1 } hollow
    interior
    { media
        { emission 1
            density
            { spherical density_map
                { [0 rgb 0.0002]
                    [200 Orange]
                    [200 Red]
                    [200 Yellow]
                }
                scale 120
            }
        }

    }
    translate <0,0,20000>
}

light_source {
    /* <100, 0, 10000> */
    <20000, 6000,40000>
    color rgb 0.2
}

#declare CAMERA_SPLINE = spline {
    linear_spline
    0.0, <0,0,100>,
    7.0, <0,0,500>
}
#declare ORION_SPLINE = spline {
    linear_spline
    -0.20, <50, -50, -51>,
    0.0, <50, -50, -50>,
    7.0, <50, -25, 1000>,
    7.50, <50, -25, 1005>
}

#declare SUN_GLOW_MOVEMENT = spline {
    linear_spline
    0.0, <0,0,1000>
    7.0, CAMERA_SPLINE(Time())
}

camera {
    perspective
    location CAMERA_SPLINE(Time())
    look_at ORION_SPLINE(Time())
    right 16/9*x
}

object {
    orion_
    scale 0.25
    rotate <0,0, clock*45>
    translate ORION_SPLINE(Time())

}

object { SUN translate <0,0, 1000> }
object { SUN_GLOW translate <0,0,1000> }
object { PLANET translate <-4500,-2000,10000> }

