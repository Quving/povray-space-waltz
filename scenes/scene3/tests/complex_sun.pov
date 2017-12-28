// Persistence of Vision Ray Tracer Scene Description File
// File: SunChange.pov
// Vers: 3.1 or MegaPOV
// Desc: The Sun, with flares and corona.  Animatable to an extent.
// Date: 2000.8
// Auth: Bob Hughes
// Mail: persistenceofv@aol.com?subject=PoV-Scene&body=Concerning%20POV-Ray
// Note: This Sun is not meant to be accurate, just my interpretation.
//       Will look different in Official POV-Ray as opposed to MegaPOV.
//       Scale is initially 1 million miles to 1 POV unit.

#declare Use_MegaPOV=no;

#if (Use_MegaPOV=yes)
#version unofficial MegaPov 0.6;
#end

// 1000000 will make scale be 1 unit = 1 mile
#declare S=1000000;


// for show
camera  {
    location <0,0,-2*S>
    angle 50
    look_at  0
}

background {rgb 0}

// variable for Sun changes (can change this manually: use 0 to 1)
#declare TimeLapse=clock;

// variables for Sunlight fading or filtering
#declare EXT=TimeLapse; // extinction, smaller is brighter
#declare Sc=TimeLapse; // emission, smaller is brighter
#declare Si=TimeLapse/2.5; //intensity, smaller number is brighter

union {
    // may want to use other than the "4" below or something else altogether
    // be warned the light color changes the media appearance
    light_source {
        0, 3-(Si*4)
        // area_light <.432,0,0>, <0,.432,0>, 3, 3 jitter adaptive 1
        // orient circular
        media_interaction on
        media_attenuation off
    }

    // Sun
    #declare Space= density { rgb 0 }

    #declare Corona= density {
        radial
        turbulence .15
        frequency 15
        density_map {
            [0 rgb <.125,.5,1.33>*.025*(1/S)]
            [1 rgb <.25,.67,1.25>*(.033+(Si/15))*(1/S)]
        }
        sine_wave
        scale <.25,.125,.25>
        rotate <5,0,5>
    }

    #declare Flares = density {
        marble
        phase (.55+(TimeLapse/10))
        turbulence 5
        frequency 1.5
        density_map {
            [0 rgb .025*(1/S)]
            [.75 rgb .05*(1/S)]
            [.85 rgb <.5,.33,.25>*(.1+(Si/1.33))*(1/S)]
            [.925 rgb <.5,.33,.25>*(.1+(Si/2))*(1/S)]
            [1 rgb <.5,.33,.25>*(.1+(Si/.33))*(1/S)]
        }
        triangle_wave
        scale .67
        rotate <60,45,15>
    }

    #declare Photosphere = density {
        bozo
        phase (TimeLapse/100)
        turbulence <1,.5,.25>*1.3
        //warp {turbulence <1,.5,.25>*1.3 octaves 2 lambda 1.5 omega 0.5}
        density_map {
            [0 rgb 0]
            [.95 rgb <1.125,1,.9>*(1.3+(Si/3))*(1/S)]
            [1 rgb <1.125,1,.9>*(.9+(Si/6))*(1/S)]
        }
        ramp_wave
        scale .015
    }

    #declare Surface = density {
        crackle
        phase (TimeLapse/50)
        //warp {turbulence <1,.5,.25> octaves 2 lambda 1.25 omega 0.3}
        density_map {
            [.025*TimeLapse rgb .15*(1/S)]
            [.05*(.75+TimeLapse) rgb .3*(1/S)]
            [1 rgb <.75,.5,.33>*(2.5-(Si/1.25))*(1/S)]
        }
        scallop_wave
        scale .005
    }

    #declare Interior = density {
        bozo
        phase (TimeLapse/100)
        turbulence <1,.5,.25>*.3
        //warp {turbulence <1,.5,.25>*.3 octaves 2 lambda 1 omega 0.2}
        density_map {
            [0 rgb 0]
            [.09 rgb <1.125,1,.9>*(.3+(Si/3))*(1/S)]
            [1 rgb <1.125,1,.9>*(.9+(Si/6))*(1/S)]
        }
        ramp_wave
        scale .15
    }

    // Sun (diameter is .864 units at the surface, 1 unit = 1 million miles)
    sphere {
        0, 1
        pigment {rgbt 1}
        interior {
            media {
                #if (Use_MegaPOV=yes)
                    method 2
                    intervals 2
                    samples 2,2
                #else
                    intervals 8
                    samples 5,10
                #end
                emission <1,.75,.25>*((2-(Si/.25))+(1-Sc))
                absorption <.33,.5,.67>*(.1+(Si*10))
                scattering {4,<1,.67,.33>*1.33 extinction (EXT/20)}
                density {
                    spherical
                    turbulence <.000125,.00015,.0002>
                    density_map {
                        [.025 Space] // end of Sun atmosphere
                        [.25 Corona] // solar corona
                        [.45 Corona] // solar corona inner edge
                        [.5 Flares] // solar flares
                        [.515 Photosphere] // solar photosphere
                        [.5167+(TimeLapse/30) Photosphere] // solar photosphere
                        [.568+(TimeLapse/15) Surface] // solar surface
                        [.75+(TimeLapse/7.5) Surface] // solar subsurface
                        [1 Interior] // solar interior
                    }
                }
            }
        }
        rotate 5*TimeLapse*y // a little rotation for animation
        hollow
        no_shadow
    }
    scale S
}  // union


// omniVerse http://users.aol.com/persistenceofv/all.htm