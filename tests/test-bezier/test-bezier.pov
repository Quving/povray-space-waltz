global_settings {
    //This setting is for alpha transparency to work properly.
    //Increase by a small amount if transparent areas appear dark.
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

#include "orion_POV_geom.inc" // Geometry

camera {
    location <0,500,-500>
    look_at <0,0,0>
}

light_source {
    <3.33066907387547E-16,1.33226762955019E-15,1787.85103658018> //light position
    color rgb <1,1,1>*1.6
    parallel
    point_at <3.33066907387547E-16,1.33226762955019E-15,0>
    rotate <0,0,1.26346700010074> // roll
    rotate <-45.2086195197426,0,0> // elevation
    rotate <0,42.8371672265632,0> // rotation
}

#include "space_wallpaper.inc"

#declare MySpline =
spline {
    natural_spline
    -0.20, < -2, 1.0,  0>,
    0.00, < -0, 1.0, -2>,
    0.20, <  2, 1.0, -2>,
    0.40, <  2, 1.0,  0>,
    0.60, <  0, 1.0,  0>,
    0.80, <  0, 1.0,  2>,
    1.00, <  2, 1.0,  2>,
    1.20, <  4, 1.0,  2>
}

object {
    orion_
    translate <0,0,200>
    translate 10*MySpline(clock)
}
