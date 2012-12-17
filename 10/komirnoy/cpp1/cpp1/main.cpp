#include <iostream>
#include <cstdlib>

int main(int argc, char *argv[]) {
    //1.
    std::cout << "the 1st method" << std::endl;
    float a, b, c, d, f, tmp, sum = 0;
    std::cout << "Input five any natural numbers: " << std::endl;
    std::cin >> a;
    if(a < 1 && a > 0) {
        sum += a * a;
    }
    std::cin >> b;
    if(b < 1 && b > 0) {
        sum += b * b;
    }
    std::cin >> c;
    if(c < 1 && c > 0) {
        sum += c * c;
    }
    std::cin >> d;
    if(d < 1 && d > 0) {
        sum += d * d;
    }
    std::cin >> f;
    if(f < 1 && f > 0) {
        sum += f * f;
    }
    std::cout << "Sum: " << sum << std::endl;

    std::cout << std::endl;

    //2
    sum = 0;
    std::cout << "the 2nd method" << std::endl;
    std::cout << "Input five any natural numbers: " << std::endl;
    for(int i = 0; i < 5; i++) {
        float t;
        std::cin >> t;
        if(t > 1 && t < 0) {
            sum += t * t;
        }
    }
    std::cout << "Sum: " << sum << std::endl;

    return EXIT_SUCCESS;
}