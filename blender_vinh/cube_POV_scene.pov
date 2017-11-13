//wrap the file with the version
#local Temp_version = version;
#version 3.7;

 
global_settings {
  //This setting is for alpha transparency to work properly.
  //Increase by a small amount if transparent areas appear dark.
   max_trace_level 15
   adc_bailout 0.01
   assumed_gamma 1
 
}
#include "cube_POV_geom.inc" //Geometry
 
//CAMERA PoseRayCAMERA
camera {
        perspective
        up <0,1,0>
        right -x*image_width/image_height
        location <0,1.11022302462516E-16,10.1821956125011>
        look_at <0,1.11022302462516E-16,9.18219561250107>
        angle 32.9346087425027 // horizontal FOV angle
        rotate <0,0,0> //roll
        rotate <-25,0,0> //pitch
        rotate <0,45,0> //yaw
        translate <1.5360835,-0.584627,-0.60796>
        }
 
//PoseRay default Light attached to the camera
light_source {
              <0,1.11022302462516E-16,10.1821956125011> //light position
              color rgb <1,1,1>*1.6
              parallel
              point_at <0,1.11022302462516E-16,0>
              rotate <0,0,0> //roll
              rotate <-25,0,0> //elevation
              rotate <0,45,0> //rotation
             }
 
//Background
background { color srgb <1,1,1>  }
 
//Assembled object that is contained in cube_POV_geom.inc with no SSLT components
object{
      cube_
        texture { pigment{ rgb<1,110,0>}
                  finish { diffuse 0.9
                           phong 1}
                } // end of texture
        translate< 1.0, 0, 0>
        rotate < 0,360*clock,0>//  <-!!!!
 
      }
 
//restore the version used outside this file
#version Temp_version;
//==================================================
