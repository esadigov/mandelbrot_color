#include"color.h"
void C_print(color c){
    printf("(%d,%d,%d)",c.red,c.green,c.blue);
}
static int clamp(int n){
    if(n>255){
        return 255;
    }
    else if (n<0){
        return 0;
    }
    return n;
}
color C_new(int r, int g, int b){
    color c;
    c.red=clamp(r);
    c.green=clamp(g);
    c.blue=clamp(b);
    return c;
}