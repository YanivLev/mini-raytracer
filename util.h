#ifndef UTIL_H
#define UTIL_H

#include <cmath>
#include <memory>
#include <iostream>
#include <limits>
#include <cstdlib>

using std::shared_ptr;
using std::make_shared;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    //RAND_MAX is a constant number representing the max output of std::rand()
    //Adding +1 to RAND_MAX ensures that the return is [0, 1)
    return std::rand() / (RAND_MAX + 1);
}

inline double random_double(double min, double max) {
    //Let u = random_double() -> [0, 1)
    //f(u) = min + (min-max)*u
    //returns a double [min, max)
    return min + (max - min) * random_double();
}

#include "color.h"
#include "interval.h"
#include "ray.h"
#include "vec3.h"
#include "camera.h"

#endif
