//wrap the file with the version
#local Temp_version = version;
#version 3.7;
//==================================================
//POV-Ray Main scene file
//==================================================
//This file has been created by PoseRay v3.13.29.645
//3D model to POV-Ray/Moray Converter.
//Author: FlyerX
//Email: flyerx_2000@yahoo.com
//Web: https://sites.google.com/site/poseray/
//==================================================
//Files needed to run the POV-Ray scene:
//cube_POV_main.ini (initialization file - open this to render)
//cube_POV_scene.pov (scene setup of cameras, lights and geometry)
//cube_POV_geom.inc (geometry)
//cube_POV_mat.inc (materials)
// 
//==================================================
//Model Statistics:
//Number of triangular faces..... 12
//Number of vertices............. 8
//Number of normals.............. 6
//Number of UV coordinates....... 0
//Number of lines................ 0
//Number of materials............ 1
//Number of groups/meshes........ 1
//Number of subdivision faces.... 0
//Bounding Box....... from x,y,z=(0.19673,-2.212635,-2.034684)
//                      to x,y,z=(2.875437,1.043381,0.818764)
//                 size dx,dy,dz=(2.678707,3.256016,2.853448)
//                  center x,y,z=(1.5360835,-0.584627,-0.60796)
//                       diagonal 5.09109780625053
//Surface area................... 23.9999996222825
//             Smallest face area 1.99999890624071
//              Largest face area 2.00000081430602
//Memory allocated for geometry: 4 KBytes
// 
//==================================================
//IMPORTANT:
//This file was designed to run with the following command line options: 
// +W320 +H240 +FN +AM1 +A0.3 +r3 +Q9 +C -UA +MV3.7
//if you are not using an INI file copy and paste the text above to the command line box before rendering
 
 
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
      }
 
//restore the version used outside this file
#version Temp_version;
//==================================================
