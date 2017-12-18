//wrap the file with the version
#local Temp_version = version;
#version 3.7;
global_settings {
    //This setting is for alpha transparency to work properly.
    //Increase by a small amount if transparent areas appear dark.
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}


#include "space_wallpaper.inc"
#include "orion_POV_geom.inc" //Geometry

//CAMERA PoseRayCAMERA
camera {
    perspective
    right 16/9*x
    /* location <6*sin(2*pi*clock),0,-5*cos(2*pi*clock)> */
    location 0
    look_at <0,0,1>
}

//PoseRay default Light attached to the camera
light_source {
    <3.33066907387547E-16,1.33226762955019E-15,1787.85103658018> //light position
    color rgb <1,1,1>*1.6
    parallel
    point_at <3.33066907387547E-16,1.33226762955019E-15,0>
    rotate <0,0,1.26346700010074> //roll
    rotate <-45.2086195197426,0,0> //elevation
    rotate <0,42.8371672265632,0> //rotation
}

//Background
background { color srgb 0  }

//Assembled object that is contained in orion_POV_geom.inc with no SSLT components
object {
    orion_
    /* location <0, 1000, 0> */
    translate <0,0,1000>
    rotate< 12, 20, 45>
}

sphere
{
    <100, 2500, -200>, 1000
    pigment { rgb <0,0,1> }
    texture{
        pigment{ bozo turbulence 0.75
            octaves 6  omega 0.7 lambda 2
            color_map {
                [0.0  color rgb <0.95, 0.95, 0.95> ]
                [0.05  color rgb <1, 1, 1>*1.25 ]
                [0.15 color rgb <0.85, 0.85, 0.85> ]
                [0.55 color rgbt <1, 1, 1, 1>*1 ]
                [1.0 color rgbt <1, 1, 1, 1>*1 ]
            } // end color_map
            translate< 3, 0,-1>
            /* scale <0.3, 0.4, 0.2>*3 */

        }
        scale 750 // end pigment
        #if (version = 3.7 )  finish {emission 1 diffuse 0}
        #else                 finish { ambient 1 diffuse 0}
        #end
    }
}

//restore the version used outside this file
#version Temp_version;
//==================================================
