#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"

class hit_record {
    public:
        point3 hit_point;
        vec3 surface_normal;
        double t;
        bool front_face;

        void set_face_normal(const ray& ray, const vec3& outward_normal) {
            //Sets the hit record normal vector
            //outward_normal is assumed to have unit length

            front_face = dot(ray.direction(), outward_normal) < 0;        
            surface_normal = front_face ? outward_normal : -outward_normal;
        }
};

class hittable {
    public:
        //Ensures that destroying a derived object through a base pointer calls the derived class's destructor first
        virtual ~hittable() = default;
        
        virtual bool hit(const ray& ray, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif