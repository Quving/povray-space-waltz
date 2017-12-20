//wrap the file with the version
#local Temp_version = version;
#version 3.7;
global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

#include "space_wallpaper.inc"
#include "orion_POV_geom.inc" //Geometry

camera {
    perspective
    right 16/9*x
    /* location <6*sin(2*pi*clock),0,-5*cos(2*pi*clock)> */
    location 0
    look_at <-1-(1-tanh(clock)),-1-(1-tanh(clock)),1>
    /* look_at <0, 0, 1> */
}
//PoseRay default Light attached to the camera
light_source {
    <-512,128,-8>
    color rgb <1,1,1>*1.6
    parallel
    point_at <3.33066907387547E-16,1.33226762955019E-15,0>
    rotate <0,0,1.26346700010074> //roll
    rotate <-45.2086195197426,0,0> //elevation
    rotate <0,42.8371672265632,0> //rotation
}

background {
    color srgb 0
}

#declare orion_spline =
spline {
    linear_spline
    0.00, <-500, -400, 100>, // control start
    1.00, < 1300, -1000, 100>  // control end
}

object {
    orion_
    /* location <0, 1000, 0> */
    rotate <1*sin(2*pi*clock),1*sin(2*pi*clock)+180,5*sin(2*pi*clock) + 0>
    translate orion_spline(clock)
}

/* #declare Index = 0; */
/* #while(Index <= 1) */
/*     sphere{ */
/*         <Index* 1000, Index*-1000 + 200, 1000>, 12 */
/*         pigment { rgb <244/255, 128/255, 66/255> } */

/*     } */
/*     #declare Index = Index + 0.025; */
/* #end */


sphere {
    <12*10000, -4*12000, 6*10000>, 130000
    rotate <clock*30, 0, 0>
    pigment { rgb <0,0.75,0.75> }
    texture{
        pigment{ bozo turbulence 1.75
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
