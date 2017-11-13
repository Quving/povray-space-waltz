//wrap the file with the version
#local Temp_version = version;
#version 3.7;
//==================================================
//POV-Ray Geometry file
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
 
 
//Materials
#include "cube_POV_mat.inc"
 
//Geometry
#declare cube_Material_=mesh2{
vertex_vectors{
8,
<0.531566,-0.782125,-2.005078>,
<0.19673,0.509709,-0.51543>,
<2.123987,1.043381,-0.545036>,
<2.458822,-0.248453,-2.034684>,
<0.94818,-2.212635,-0.670884>,
<2.875437,-1.678963,-0.70049>,
<2.540602,-0.387129,0.789157>,
<0.613346,-0.920801,0.818764>
}
normal_vectors{
6,
<-0.208293189965479,0.715276614413381,-0.6670781902351>,
<0.208293189965479,-0.715276614413381,0.6670781902351>,
<-0.963635539534059,-0.266809840128359,0.0148005458541968>,
<-0.167405305995262,0.645920472773832,0.744823607558368>,
<0.963635539534059,0.266809840128359,-0.0148005458541968>,
<0.167405305995262,-0.645920472773832,-0.744823607558368>
}
face_indices{
12,
<0,1,2>,
<0,2,3>,
<4,5,6>,
<4,6,7>,
<0,4,7>,
<0,7,1>,
<1,7,6>,
<1,6,2>,
<2,6,5>,
<2,5,3>,
<4,0,3>,
<4,3,5>
}
normal_indices{
12,
<0,0,0>,
<0,0,0>,
<1,1,1>,
<1,1,1>,
<2,2,2>,
<2,2,2>,
<3,3,3>,
<3,3,3>,
<4,4,4>,
<4,4,4>,
<5,5,5>,
<5,5,5>
}
inside_vector <0,0,1> }
 
 
//Model assembly from the meshes
#declare cube_=
object{cube_Material_  material{Material_} hollow }
 
//restore the version used outside this file
#version Temp_version;
