#include "math.inc"
#macro Time()
    Scene_Length * clock
#end // macro

#macro Trace_Position_Spline(Position_Spline, Steps, Indicator_Radius)
    #local Start = initial_clock * Scene_Length;
    #if (final_clock = 0)
        #local End = 1 * Scene_Length;
    #else
        #local End = final_clock * Scene_Length;
    #end // if
    #local Step_Size = ((End - Start) / Steps);
    #local Current = Start;

    union {
        #while (Current < End)
            // create sphere
            sphere {
                Position_Spline(Current), Indicator_Radius
                texture {
                    pigment { color Pink * Current/Scene_Length }
                    finish { ambient 0.15 diffuse 0.85 phong 1 }
                }
            }

            #local Next = Current + Step_Size;

            // create line between current and next sphere
            #if (VEq(Position_Spline(Current), Position_Spline(Next)))
                // VEq(v1, v2) checks if v1 = v2
            #else
                cylinder {
                    Position_Spline(Current), Position_Spline(Next), Indicator_Radius * 0.5
                    pigment { color Pink }
                }
            #end // if

            #local Current = Next;
        #end // while

        // create last sphere
        sphere {
            Position_Spline(End), Indicator_Radius
            texture {
                pigment { color Pink }
                finish { ambient 0.15 diffuse 0.85 phong 1 }
            }
        }
    }
#end

#macro Trace_Spline(Spline, Steps, Indicator_Radius)
    // simple wrapper for backwards compatibility reasons
    Trace_Position_Spline(Spline, Steps, Indicator_Radius)
#end

#macro Simple_Color(Color)
    pigment {
        color Color * 0.5
        filter 0.9
    }
    finish {
        ambient 0.1
        diffuse 0.85
        phong 0.2
    }
#end // macro Simple_Color

#macro Simple_Transparent_Color(Color)
    pigment {
        color Color * 0.5
        filter 0.9
    }
    finish {
        ambient 0.1
        diffuse 0.85
        phong 0.2
    }
#end // macro Simple_Transparent_Color

#macro Axis(Axis_Len, Color)
    /* create an arrow along the x axis with length Axis_Len and color Color */

    cylinder {
        0, x * Axis_Len, 0.05 * Axis_Len
        texture {
            pigment {
                color Color * 0.5
                filter 0.2
            }
            finish {
                ambient 0.5
                diffuse 0.85
                phong 1
            }
        }
    }
#end // macro Axis

#macro AxisXYZ( AxisLenX, AxisLenY, AxisLenZ)
    /*
    draw arrows along all three axis
    */

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

#macro Trace_Position_And_Rotation_Spline(Position_Spline, Rotation_Spline, Steps, Axis_Len)
    #local Indicator_Radius = Axis_Len / 5;
    #local Start = initial_clock * Scene_Length;
    #if (final_clock = 0)
        #local End = 1 * Scene_Length;
    #else
        #local End = final_clock * Scene_Length;
    #end // if
    #local Step_Size = ((End - Start) / Steps);
    #local Current = Start;

    union {
        #while (Current < End)
            // create sphere
            sphere {
                Position_Spline(Current), Indicator_Radius
                texture { Simple_Transparent_Color(Pink) }
            }

            object {
                Draw_Debug_Axis(Axis_Len)

                rotate Rotation_Spline(Current)
                translate Position_Spline(Current)
            }

            #local Next = Current + Step_Size;

            // create line between current and next sphere
            #if (VEq(Position_Spline(Current), Position_Spline(Next)))
                // VEq(v1, v2) checks if v1 = v2
            #else
                cylinder {
                    Position_Spline(Current), Position_Spline(Next), Indicator_Radius * 0.5
                    texture { Simple_Transparent_Color(Pink) }
                }
            #end // if

            #local Current = Next;
        #end // while

        // create last sphere
        sphere {
            Position_Spline(End), Indicator_Radius
            Simple_Transparent_Color(Pink)
        }

        no_shadow
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
