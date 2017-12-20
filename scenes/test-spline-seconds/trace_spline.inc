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
