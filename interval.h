#ifndef INTERVAL_H
#define INTERVAL_H

#include "util.h"

class interval {
    public:
        double min, max;

        //Default to an empty range (min > max) so no value is inside until bounds are set
        interval() : min(+infinity) , max(-infinity) {};

        interval(double min, double max) : min(min), max(max) {};

        double size() const {
            return max - min;
        }

        //Inclusive check: true if x lies within [min, max]
        bool contains(double t) const {
            return min <= t && t <= max;
        }

        //Exclusive check: true if x lies within (min, max)
        bool surrounds(double t) const {
            return min < t && t < max;
        }
        
        //Shared preset intervals for "no valid range" and "all real numbers"
        static const interval empty, universe;
};

//Out of bound definitions for the static class constants
const interval interval::empty = interval(+infinity, -infinity);
const interval interval::universe = interval(-infinity, +infinity);

#endif