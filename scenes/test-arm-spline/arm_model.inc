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

#macro Arm()
    #local Arm_Seg_Red_Length = 6;
    #local Arm_Seg_Green_Length = 4;
    #local Arm_Seg_Blue_Length = 2;

    union {
        object {
            cylinder {
                0, y * Arm_Seg_Red_Length, 0.5
                pigment { color Red }
            }
        }

        #if (Debug_Joints)
            Draw_Debug_Axis(Arm_Seg_Red_Length)
        #end

        union {
            object {
                cylinder {
                    0, y * Arm_Seg_Green_Length, 0.4
                    pigment { color Green }
                }
            }

            #if (Debug_Joints)
                Draw_Debug_Axis(Arm_Seg_Green_Length)
            #end

            union {
                object {
                    cylinder {
                        0, y * Arm_Seg_Blue_Length, 0.3
                        pigment { color Blue }
                    }
                }

                #if (Debug_Joints)
                    Draw_Debug_Axis(Arm_Seg_Blue_Length)
                #end

                rotate Arm_Seg_Blue_Rotation
                translate y * Arm_Seg_Green_Length
            }

            rotate Arm_Seg_Green_Rotation
            translate y * Arm_Seg_Red_Length
        }

        rotate Arm_Seg_Red_Rotation
    }
#end
