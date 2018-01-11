#include "colors.inc"

// ground -----------------------------------------------------------------
//---------------------------------<<< settings of squered plane dimensions
#declare RasterScale = 1.0;
#declare RasterHalfLine  = 0.025;
#declare RasterHalfLineZ = 0.025;
//-------------------------------------------------------------------------
#macro Raster(RScale, HLine)
       pigment{ gradient x scale RScale
                color_map{[0.000   color rgbt<0,0,0,0>]
                          [0+HLine color rgbt<0,0,0,0>]
                          [0+HLine color rgbt<1,1,1,1>]
                          [1-HLine color rgbt<1,1,1,1>]
                          [1-HLine color rgbt<0,0,0,0>]
                          [1.000   color rgbt<0,0,0,0>]} }
       finish { ambient 0.15 diffuse 0.85}
 #end// of Raster(RScale, HLine)-macro
//-------------------------------------------------------------------------

#declare orion_start_position = < 2500, 1400, 1500>;
#declare orion_end_position = < 1500, 400, 1500>;

#declare camera_spline = spline {
    natural_spline
    -0.5 < 0,-100, orion_start_position.z >
    0.00 < 0, 0, orion_start_position.z >,
    0.7 < 0, 100, orion_start_position.z >
    1.00 orion_start_position.z
}

sphere {
    <10,0, 10>, 5
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
        #if (version = 3.7 )  finish {emission 1 diffuse 0}
        #else                 finish { ambient 1 diffuse 0}
        #end
    }
}
camera {
    perspective
    right 16/9*x
    location <15,5,-15>
    sky < 0, 1, 0>
    look_at camera_spline(clock)
}


plane { <0,1,0>, 0    // plane with layered textures
        texture { pigment{color White*1.1}
                  finish {ambient 0.45 diffuse 0.85}}
        texture { Raster(RasterScale,RasterHalfLine ) rotate<0,0,0> }
        texture { Raster(RasterScale,RasterHalfLineZ) rotate<0,90,0>}
        rotate<0,0,0>
      }
//------------------------------------------------ end of squered plane XZ
