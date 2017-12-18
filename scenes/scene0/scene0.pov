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
    <100,150,-10>
    color rgb <1,1,1>*1.6
    parallel
    point_at <3.33066907387547E-16,1.33226762955019E-15,0>
    rotate <0,0,1.26346700010074> //roll
    rotate <-45.2086195197426,0,0> //elevation
    rotate <0,42.8371672265632,0> //rotation
}

background { color srgb 0  }

object {
    orion_
    /* location <0, 1000, 0> */
    rotate <16*sin(2*pi*clock),32*sin(2*pi*clock),32*sin(2*pi*clock) + 45>
    translate <(1-clock)*250,-(1-clock)*500,(1-clock)*1000>
}

sphere
{
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

//restore the version used outside this file
#version Temp_version;
//==================================================
