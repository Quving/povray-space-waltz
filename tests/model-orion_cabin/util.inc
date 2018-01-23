#declare NULL = sphere {
    0, 0.0000001
    pigment {
        rgbft 1
    }
}

#macro Time()
    Scene_Length * clock
#end // macro

#macro Trace_Spline(Input_Spline, Input_Steps, Input_Size)
    #local Start = initial_clock * Scene_Length;
    #if (final_clock = 0)
        #local End = 1 * Scene_Length;
    #else
        #local End = final_clock * Scene_Length;
    #end // if
    #local Step_Size = ((End - Start) / Input_Steps);
    #local Current = Start;

    union {
        #while (Current < End)
            // create sphere
            sphere {
                Input_Spline(Current), Input_Size
                texture {
                    pigment { color Pink }
                    finish { ambient 0.15 diffuse 0.85 phong 1 }
                }
            }

            #local Next = Current + Step_Size;

            // create line between current and next sphere
            #if (VEq(Input_Spline(Current), Input_Spline(Next)))
                // VEq(v1, v2) checks if v1 = v2
            #else
                cylinder {
                    Input_Spline(Current), Input_Spline(Next), Input_Size * 0.5
                    pigment { color Pink }
                }
            #end // if

            #local Current = Next;
        #end // while

        // create last sphere
        sphere {
            Input_Spline(End), Input_Size
            texture {
                pigment { color Pink }
                finish { ambient 0.15 diffuse 0.85 phong 1 }
            }
        }
    }
#end // macro

#macro Arrow(Axis, Arrow_Shaft_Length, Arrow_Shaft_Radius, Arrow_Head_Length, Arrow_Head_Radius, Color)
    /* create an arrow along the x axis with length Axis_Len and color Color */

    #local TEXTURE = texture {
        pigment { color Color}
        finish {
            ambient 0.15
            diffuse 0.85
            phong 1
        }
    }

    union {
        cylinder {
            0, Axis * Arrow_Shaft_Length, Arrow_Shaft_Radius
            texture { TEXTURE }
        }

        cone {
            0, Arrow_Head_Radius, Axis * Arrow_Head_Length, 0
            texture { TEXTURE }
            translate Axis * Arrow_Shaft_Length
        }
    }
#end // macro

#macro Draw_Simple_Arrows_Along_Axis(Arrow_Shaft_Length, Arrow_Shaft_Radius, Arrow_Head_Length, Arrow_Head_Radius)
    union {
        Arrow(x, Arrow_Shaft_Length, Arrow_Shaft_Radius, Arrow_Head_Length, Arrow_Head_Radius, Red)
        Arrow(y, Arrow_Shaft_Length, Arrow_Shaft_Radius, Arrow_Head_Length, Arrow_Head_Radius, Green)
        Arrow(z, Arrow_Shaft_Length, Arrow_Shaft_Radius, Arrow_Head_Length, Arrow_Head_Radius, Blue)
    }
#end

#macro Mirror_X()
    scale <-1, 1, 1>
#end

#macro Mirror_Y()
    scale <1, -1, 1>
#end

#macro Mirror_Z()
    scale <1, 1, -1>
#end

// #macro Draw_Planes_Along_Axis()
//     union {
//         plane {
//             x, 0
//             texture {
//                 pigment { color rgbf <1, 0.9, 0.9, 0.9> }
//                 finish { ambient 0.1 diffuse 1 phong 0 }
//             }
//         }
//
//         // plane {
//             // y, 0
//             // texture {
//                 // pigment { color rgbf <0.8, 1, 0.8, 0.9> }
//                 // finish { ambient 0.1 diffuse 0.85 phong 0 }
//             // }
//         // }
//
//         // plane {
//             // z, 0
//             // texture {
//                 // pigment { color rgbf <0.8, 0.8, 1, 0.9> }
//                 // finish { ambient 0.1 diffuse 0.85 phong 0 }
//             // }
//         // }
//
//         NULL
//
//         no_shadow
//     }
// #end

#macro Draw_YZ_Plane()
plane {
    x, 0
    texture {
        pigment { color rgbf <1, 0.9, 0.9, 0.9> }
        finish { ambient 0.1 diffuse 1 phong 0 }
    }
    no_shadow
}
#end
