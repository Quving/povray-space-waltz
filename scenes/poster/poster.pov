global_settings {
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

// #include "transforms.inc"

#include "orion_POV_geom.inc"
#include "StationV_POV_geom.inc"
#include "space_wallpaper.inc"

/*
sky_sphere{
    pigment{
        image_map{ jpeg "../../models/space_textures/starmap_4k.jpg"
            map_type 1    // cylindrical
            interpolate 2 // bilinear
            once //
        }
    }
    rotate<0,30,0>
}
*/

camera {
    location <0, 0, -8000>
    right x * 1
    up y * 1.414213562
    look_at <0, 0, 0>
    rotate <30, 15, 0>
}

light_source {
    <-4000, 1500, -8000>
    color rgb <1, 1, 1>
}

union {
    object {
        orion_
        rotate z * 15
        translate <0, 0, -2200>
    }

    object {
        StationV_
    }

    rotate <0, -30, 15>
}
