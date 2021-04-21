#include<stdio.h>
#include"color.h"
#include "image.h"
#include "ppm.h"

int main() {
    struct color *img;
    int nbpixels;
    struct ppm p;
    p = PPM_new("input.ppm");
    nbpixels = PPM_nbPixels(p);
    img = PPM_pixels(p);
    I_Mand(img,nbpixels);
    PPM_save(p,img,"output.ppm");
    return 0;
}