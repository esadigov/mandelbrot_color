#ifndef COLOR_H
#define COLOR_H
#include<stdio.h>
typedef struct color
{
    int red;
    int green;
    int blue;
}color;

void C_print(color c);
color C_new(int red, int green, int blue);
#endif