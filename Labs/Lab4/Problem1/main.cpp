#define _CRT_SECURE_DEBUG_NO_WARNINGS
#include <iostream>
using namespace std;
#include<iomanip>

#include "complex_test.h"


#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"


void display_mandelbrot(int width, int height, int max_its)
{

    const float x_start = -3.0f;
    const float x_fin = 1.0f;
    const float y_start = -1.0f;
    const float y_fin = 1.0f;

    double dx = (x_fin - x_start) / (width - 1);
    double dy = (y_fin - y_start) / (height - 1);

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            // TODO your code here
            // create complex number z = 0 + 0i
            Complex z;
            z = Complex(0, 0);
            // create complex number c =  x_start+ x*dx + (y_start+y*dy)i
            Complex c;
            c = Complex(x_start + x * dx, y_start + y * dy);

            int iteration = 0;
            // while |z| < 2 and we haven't reach max_its
            while (z.magnitude() < 2 && ++iteration < max_its) {
                // apply the rule:  z =  z*z + c
                z = z * z + c;
            }

            // TODO: your code here (modify the code to display the mandelbrot fractal
            if (iteration == max_its) {
                printf("%s*", AC_MAGENTA);
            }
            else {
                printf("%s-", AC_YELLOW);
            }

        }
        printf("\n");
    }

}


int main(int argc, char** argv) {
    cout << "Complex numbers defined on stack" << endl;
    Complex c1{};
    cout << "Please enter the real and imaginary parts of the complex number:" << endl;
    cin >> c1;
    cout << "You entered c1: " << c1 <<endl;
    cout <<"Real part: " << c1.getReal() <<" Imaginary part: " << c1.getImag() <<"*i"<< endl;
    Complex c2{ 10,20 };
    cout << "c2: " << c2 << endl;
    Complex c3{ c1 + c2 };
    cout << "Sum of c1 + c2: " << c3 << endl;
    Complex c4{ c1 - c2 };
    cout << "The difference of c1 - c2: " << c4 << endl;
    Complex c5{ c1 * c2 };
    cout <<"The product of c1 * c2: "<< c5 << endl;
    cout << "Enter a scalar to multiply c1 with: " << endl;
    int c;
    cin >> c;
    Complex c6;
    c1.multiply(c);
    cout << "The product of c1 * " << c << " is: "<< c1 <<endl;
    cout << "The phase of c1 is: " << c1.phase() << " and the magnitude is: " << c1.magnitude() << endl;
    if (c1.equals(c2))
        cout << "c1 = c2" << endl;
    else
        cout << "c1 != c2" << endl;
    c1.setDisplayType(DisplayType::RECTANGULAR_FORM);
    cout << "c1 in rectangular form" << c1 << endl;
    c1.setDisplayType(DisplayType::POLAR_FORM);
    cout << "c1 in polar form" << c1 << endl;
    cout << endl;
    //mandelbrot
    
#if ENABLE_TESTS < 0
	run_complex_tests(false);
#endif
    display_mandelbrot(100, 25, 100);
    getchar();
	return 0;
}