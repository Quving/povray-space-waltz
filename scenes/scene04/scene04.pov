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

#declare orion_start_position = < 2500, 1400, 1500>;
#declare orion_end_position = < 1800, 1400, 1500>;

#declare camera_spline = spline {
    natural_spline
    -0.5 < 0,-100, orion_start_position.z >
    0.00 < 0, 0, orion_start_position.z >,
    0.4 < 0, 900, orion_start_position.z >
    1.00 orion_start_position
}

#declare orion_spline = spline {
    linear_spline
    0.00, orion_start_position, // control start
    1.00, orion_end_position  // control end
}


camera {
    perspective
    right 16/9*x
    location 0
    sky < 0, 1, 0>
    look_at camera_spline(clock)
}
//PoseRay default Light attached to the camera
light_source {
    <0,100,0>
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

object {
    orion_
    rotate < 180,90, 0>
    translate orion_spline(clock)
}

/* #declare Index = 0; */
/* #while(Index <= 1) */
/*     sphere{ */
/*         <Index* 1000 - 100, Index*-100 + 800, 500>, 12 */
/*         pigment { rgb <244/255, 128/255, 66/255> } */
/*     } */
/*     #declare Index = Index + 0.025; */
/* #end */


sphere {
    <0, -7*12000, 11*10000>, 130000
    /* rotate <clock*15, 0, 0> */
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
