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
//orion_POV_main.ini (initialization file - open this to render)
//orion_POV_scene.pov (scene setup of cameras, lights and geometry)
//orion_POV_geom.inc (geometry)
//orion_POV_mat.inc (materials)
//Aft.bmp
//AftBump.bmp
//Logo.bmp
//LogoBump.bmp
//Ribs.bmp
//RibsBump.bmp
//HullS.BMP
//HullSBump.bmp
//OCowlS.bmp
//OCowlSBump.bmp
//OCowlT.bmp
//OCowlTBump.bmp
//HullT.bmp
//HullTBump.bmp
//Hatch.bmp
//HatchBump.bmp
//Window.bmp
//WindBump.bmp
//Cock.bmp
//CockBump.bmp
//WingMap.bmp
//WingBump.bmp
// 
//==================================================
//Model Statistics:
//Number of triangular faces..... 13830
//Number of vertices............. 7831
//Number of normals.............. 7356
//Number of UV coordinates....... 6085
//Number of lines................ 0
//Number of materials............ 13
//Number of groups/meshes........ 15
//Number of subdivision faces.... 0
//UV boundaries........ from u,v=(-0.1908,-0.0217)
//                        to u,v=(3.3479,1.025)
//Bounding Box....... from x,y,z=(-190.8018,-38.3496,-440.4709)
//                      to x,y,z=(191.3866,45.6571,363.2565)
//                 size dx,dy,dz=(382.1884,84.0067,803.7274)
//                  center x,y,z=(0.292400000000001,3.65375,-38.6072)
//                       diagonal 893.925518290092
//Surface area................... 232467.725389693
//             Smallest face area 6.44204936372271E-8
//              Largest face area 10996.0362737668
//Memory allocated for geometry: 1 MByte
// 
//==================================================
//IMPORTANT:
//This file was designed to run with the following command line options: 
// +W320 +H203 +FN +AM1 +A0.3 +r3 +Q9 +C -UA +MV3.7
//if you are not using an INI file copy and paste the text above to the command line box before rendering
 
 
global_settings {
    //This setting is for alpha transparency to work properly.
    //Increase by a small amount if transparent areas appear dark.
    max_trace_level 15
    adc_bailout 0.01
    assumed_gamma 1
}

#include "orion_POV_geom.inc" //Geometry
#include "StationV_POV_geom.inc" //Geometry
 
//CAMERA PoseRayCAMERA
camera {
    location 0
    look_at <1,0,0>
}
 
//PoseRay default Light attached to the camera
light_source {
    <3.33066907387547E-16,1.33226762955019E-15,1787.85103658018> //light position
    color rgb <1,1,1>*1.6
    parallel
    point_at <3.33066907387547E-16,1.33226762955019E-15,0>
    rotate <0,0,1.26346700010074> //roll
    rotate <-45.2086195197426,0,0> //elevation
    rotate <0,42.8371672265632,0> //rotation
}
 
//Background
background { color srgb 0  }
 
//Assembled object that is contained in orion_POV_geom.inc with no SSLT components
object {
    orion_
    translate <1000,0,0>
}

object {
    StationV_
    translate <2500,0,0>
}
 
//restore the version used outside this file
#version Temp_version;
//==================================================
