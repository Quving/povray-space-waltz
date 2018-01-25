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


#include "../../models/space_wallpaper.inc"
#include "../../models/orion_POV_geom.inc" //Geometry
#include "../../models/StationV_POV_geom.inc" //Geometry
#include "transforms.inc" //cool
      
      
     
      
//CAMERA PoseRayCAMERA     scene 20.1
camera {
    look_at <1,1,-1000>  
    location <0,20000,-40000> 
    rotate<80,0,50>
    translate<-6000,4000,3000>    
    translate<0,0,-2300*clock>
         //  translate<-8000*clock,5000*clock,2000*clock>  
}
   
//Assembled object that is contained in orion_POV_geom.inc with no SSLT components
object {
    orion_
    translate <8000,14000,-47000>
    translate<-500*clock,-3000*clock,4000*clock>  
    rotate<90,0,60>  
    }
   
   
object {
    StationV_     
    
    rotate <90,-100*clock,0> //startzustand
    //rotate <0,-100*clock,0> // rotation um eigen achse    
   
}

light_source{ 
            <0,-6000,  0> 
            color rgb<2,2,2>
            translate<0,6900,0>}
 
light_source {
    <3.33066907387547E-16,1.33226762955019E-15,1787.85103658018> //light position
    color rgb <1,1,1>*1.6
    parallel
    point_at <3.33066907387547E-16,1.33226762955019E-15,0>
    rotate <0,0,1.26346700010074> //roll
    rotate <-45.2086195197426,0,0> //elevation
    rotate <0,42.8371672265632,0> //rotation
} 
  
sphere {  
    <35000, -15000,-15000>, 
    5000
    rotate <clock*1, 0, 0>  
    pigment { rgb <0,0.25,1.25> }
    texture{
        pigment{ bozo turbulence 1.75
            octaves 6  omega 0.7 lambda 2
            color_map {
                [0.0  color rgb <0.95, 0.95, 0.95> ]
                [0.05  color rgb <1, 1, 1>*1.25 ]
                [0.15 color rgb <0.85, 0.85, 0.85> ]
                [0.55 color rgbt <1, 1, 1, 1>*1 ]
                [1.0 color rgbt <1, 1, 1, 1>*1 ]
            }
        }
        scale 5000
        #if (version = 3.7 )  finish {emission 1 diffuse 0}
        #else                 finish { ambient 1 diffuse 0}
        #end
    } 
        
}  
  
  
//Background
background { color srgb 0  }




//restore the version used outside this file
#version Temp_version;
//==================================================

