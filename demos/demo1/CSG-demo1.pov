// -----------------------------------------------------------------------
// Uebungen zur Constructive Solid Geometry (CSG)
// Beispiel: eine individuelle Kugel (rechts angeordnet)
#version 3.7;
global_settings { assumed_gamma 2.2 }
#include "colors.inc"
background { Cyan }
camera {
  location <0, 100, -10>
  look_at <0, 0, 0>
  angle 36
}
light_source { <500, 500, -1000> White }

sphere { 0, 1
  pigment { Red }
  translate +1.5*x
}

sphere { 1, 1
  pigment { Blue }
  translate +1.5*x
}
