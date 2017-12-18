
sky_sphere{
    //---------------------- gamma correction
    pigment{
        image_map{ jpeg "space_textures/starmap_4k.jpg"
            map_type 1    // cylindrical
            interpolate 2 // bilinear
            once //
        } //  end of image_map
        // scale<1,1.02,1>
    } // end of pigment
    //-------------------------
    rotate<0,30,0>
} // end of sky_sphere

