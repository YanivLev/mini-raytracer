#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "vec3.h"

using namespace std;

class sphere : public hittable {
    private:
        point3 center;
        double radius;

    public:
        //Sphere constructor, ensures that no negative radius is received
        sphere(const point3& center, double radius) : center(center), radius(fmax(0, radius)) {}

        bool hit(const ray& ray, double ray_tmin, double ray_tmax, hit_record& hit_record) const override {
            vec3 oc = center - ray.origin();
            auto a = ray.direction().length_squared();
            //auto b = dot(ray.direction(), oc); h = -1/2 * b, fewer multiplications
            auto h = dot(ray.direction(), oc);
            auto c = oc.length_squared() - (radius * radius);

            auto discriminant = (h * h) - (a * c);
            if (discriminant < 0) {
                return false;
            }

            auto sqrtd = sqrt(discriminant);
            
            //Finding the closes root closest to the camera, evaluating min and max out of result
            auto root = (h - sqrtd) / a;
            //If the first root is out of bound try the second one, if both are out of bound return false
            if (root <= ray_tmin || root >= ray_tmax) {
                root = (h + sqrtd) / a;
                if (root <= ray_tmin || root >= ray_tmax) {
                    return false;
                }
            }

            //Value assigning to hit_record object
            hit_record.t = root;
            hit_record.hit_point = ray.at(hit_record.t);
            vec3 outward_normal = (hit_record.hit_point - center) / radius;
            //Checks what does the dot product of the vectors returns and sets normal accordingly
            hit_record.set_face_normal(ray, outward_normal);

            return true;
        }
};
#endif