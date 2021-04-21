#include "image.h"
#include <math.h>
#define length 0.0033343333333333335
#define width 0.0049586776859504135
#define iterations 300
typedef struct complex
{
    double real;
    double imag;
} complex;

complex CN_newempty()
{
    complex newone;
    newone.imag = 0.0;
    newone.real = 0.0;
    return newone;
}

complex CN_new(double real, double imag)
{
    complex newone;
    newone.imag = imag;
    newone.real = real;
    return newone;
}
complex CN_add(complex n1, complex n2)
{
    complex temp;
    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;
    return (temp);
}
complex CN_mult(complex x, complex y)
{
    complex z = CN_newempty();
    z.real = x.real * y.real - x.imag * y.imag;
    z.imag = x.real * y.imag + x.imag * y.real;
    return z;
}

int mandelbort(double Re, double Im, int iteration)
{
    complex z = CN_newempty();
    complex c = CN_new(Re, Im);
    for (int i = 0; i < iteration; i++)
    {
        z = CN_add(CN_mult(z, z), c);
        if ((z.real * z.real + z.imag * z.imag) >= 8)
        {
            return i;
        }
    }
    return iteration;
}

int julia(double Re, double Im, int iteration, float coef1, float coef2)
{
    complex z = CN_new(Re, Im);
    complex c = CN_new(coef1, coef2);
    for (int i = 0; i < iteration; i++)
    {
        z = CN_add(CN_mult(z, z), c);
        if ((z.real * z.real + z.imag * z.imag) >= 8)
        {
            return i;
        }
    }
    return iteration;
}

void I_Mand(color *img, int nbpixels)
{
    int count = 0;
    for (double i = -1; i < 1.; i = i + length)
    {
        for (double j = -2.; j < 1; j = j + width)
        {
            int m = mandelbort(j, i, iterations); // comment this line and uncomment line with julia function to see julia set
            // change coefficients to see different mathematical figures
            // int m = julia(j, i, iterations,0.25,0.6);
            if (m == iterations)
            {
                img[count] = C_new(0, 0, 0);
            }
            else
            {
                // you can play with percentages
                img[count] = C_new(m % 255, (m * 10) % 255, (m * 35) % 150);
            }
            count++;
        }
    }
}