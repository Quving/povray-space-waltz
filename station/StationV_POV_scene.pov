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
//StationV_POV_main.ini (initialization file - open this to render)
//StationV_POV_scene.pov (scene setup of cameras, lights and geometry)
//StationV_POV_geom.inc (geometry)
//StationV_POV_mat.inc (materials)
//Block.bmp
//BayS.bmp
//BaySBump.bmp
//BayT.bmp
//BayTBump.bmp
//Hub.bmp
//HubBump.bmp
//Spindle.bmp
//SpindleBump.bmp
//Spoke.bmp
//Rim.bmp
// 
//==================================================
//Model Statistics:
//Number of triangular faces..... 29269
//Number of vertices............. 17811
//Number of normals.............. 7593
//Number of UV coordinates....... 4607
//Number of lines................ 0
//Number of materials............ 12
//Number of groups/meshes........ 19
//Number of subdivision faces.... 0
//UV boundaries........ from u,v=(-0.625,-0.0249)
//                        to u,v=(15.75,1.3599)
//Bounding Box....... from x,y,z=(-2490.7546,-2495.2534,-1022.1861)
//                      to x,y,z=(2487.769,2490.4644,1279.2721)
//                 size dx,dy,dz=(4978.5236,4985.7178,2301.4582)
//                  center x,y,z=(-1.49280000000022,-2.39450000000011,128.543)
//                       diagonal 7412.13795495882
//Surface area................... 78744310.2224982
//             Smallest face area 6.71302949999974
//              Largest face area 207406.07261402
//Memory allocated for geometry: 2 MBytes
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
#include "StationV_POV_geom.inc" //Geometry
 
//CAMERA PoseRayCAMERA
camera {
        perspective
        up <0,1,0>
        right -x*image_width/image_height
        location <-4.21884749357559E-15,-2.66453525910038E-15,14824.2759099176>
        look_at <-4.21884749357559E-15,-2.66453525910038E-15,14823.2759099176>
        angle 32.9346087425027 // horizontal FOV angle
        rotate <0,0,0> //roll
        rotate <-25,0,0> //pitch
        rotate <0,45,0> //yaw
        translate <-1.49280000000022,-2.39450000000011,128.543>
        }
 
//PoseRay default Light attached to the camera
light_source {
              <-4.21884749357559E-15,-2.66453525910038E-15,14824.2759099176> //light position
              color rgb <1,1,1>*1.6
              parallel
              point_at <-4.21884749357559E-15,-2.66453525910038E-15,0>
              rotate <0,0,0> //roll
              rotate <-25,0,0> //elevation
              rotate <0,45,0> //rotation
             }
 
//Background
background { color srgb <1,1,1>  }
 
//Assembled object that is contained in StationV_POV_geom.inc with no SSLT components
object{
      StationV_
      }
 
//restore the version used outside this file
#version Temp_version;
//==================================================
