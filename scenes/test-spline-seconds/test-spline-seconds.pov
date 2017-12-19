/* A simple test with a spline, that is not directly bound to the clock value. */

global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

#include "colors.inc"

camera {
    location <0,0,-10>
    look_at <0,0,0>
}

light_source {
    <0,0,-10> //light position
    color rgb <1,1,1>
    parallel
    point_at <0,0,0>
}

// Background
#include "space_wallpaper.inc"

/* Begin Test */

// simple sphere for the simulation
#declare Simple_Sphere = sphere  { <0,0,0>, 1
    texture {
        pigment { color White }
        finish { ambient 0.1 diffuse 0.85  phong 1}
    }
}

#declare Scene_Length = 5; // in  e.g. seconds

// scale clock value to match the spline
#macro Time()
End_Time * clock
#end

#declare Test_Spline =
spline {
    natural_spline
    -0.20, <-5, 0, 0>, // control start
     0.00, <-5, 0, 0>, // start
     1.00, <-3, 0, 0>,
     1.50, <-3, 1, 0>,
     2.00, <-1, 0, 0>,
     3.00, < 1, 0, 0>,
     4.00, < 3, 0, 0>,
     4.50, < 2,-1, 0>,
     5.00, < 5, 0, 0>, // end
     5.20, < 5, 0, 0>  // control end
}

// have something to see the movement
object {
    Simple_Sphere
    translate Test_Spline(Time())
}
