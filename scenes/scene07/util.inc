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

#macro Axis(Axis_Len, Color)
// create an arrow along the x axis with length Axis_Len and color Color
#local Finish = finish {
    ambient 0.15
    diffuse 0.85
    phong 1
}

// union {
    cylinder {
        0, x * Axis_Len, 0.05 * Axis_Len
        texture {
            checker
            texture {
                pigment { color Color }
                finish { Finish }
            }
            texture {
                pigment { color White }
                finish { Finish }
            }
        }
    }

    // cone {
    //     <0, AxisLen, 0>, 0.2
    //     <0, AxisLen + 0.7, 0>, 0
    //     texture { Texture_Dark }
    // }
// }
#end // macro

#macro AxisXYZ( AxisLenX, AxisLenY, AxisLenZ)
// draw arrows along all three axis
union {
    #if (AxisLenX != 0)
        object { // x axis
            Axis(AxisLenX, Red)
        }
        // text   { ttf "arial.ttf",  "x",  0.15,  0  texture{Tex_Dark} scale 0.5 translate <AxisLenX+0.05,0.4,-0.10>}
    #end

    #if (AxisLenY != 0)
        object { // y axis
            Axis(AxisLenY, Green)
            rotate z * 90
        }
        // text   { ttf "arial.ttf",  "y",  0.15,  0  texture{Tex_Dark} scale 0.5 translate <-0.3,AxisLenY+0.50,-0.10>}
    #end

    #if (AxisLenZ != 0)
        object { // z axis
            Axis(AxisLenZ, Blue)
            rotate y * -90
        }
        // text   { ttf "arial.ttf",  "z",  0.15,  0  texture{Tex_Dark} scale 0.5 translate <-0.35,0.2,AxisLenZ+0.10>}
    #end
}
#end // macro

#macro Draw_Debug_Axis(Axis_Len)
AxisXYZ(Axis_Len, Axis_Len, Axis_Len)
#end // macro
