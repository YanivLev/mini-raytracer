#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record {
    public:
        point3 hit_point;
        vec3  surface_normal;
        double t;
};

class hittable {
    public:
        //Ensures that destroying a derived object through a base pointer calls the derived class's destructor first
        virtual ~hittable() = default;
        
        virtual bool hit(const ray& ray, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif