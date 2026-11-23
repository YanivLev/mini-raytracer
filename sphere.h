#ifndef SPHERE_H
#define SPHERE_H

class sphere : public hittable {
    private:
        point3 center;
        double radius;

    public:
        //Sphere constructor, ensures that no negative radius is received
        sphere(const point3& center, double radius) : center(center), radius(fmax(0, radius)) {}

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            vec3 oc = center - r.origin();
            auto a = r.direction().length_squared();
            //auto b = dot(r.direction(), oc); h = -1/2 * b, fewer multiplications
            auto h = dot(r.direction(), oc);
            auto c = oc.length_squared() - (radius * radius);

            auto discriminant = (h * h) - (a * c);
            if (discriminant < 0) {
                return false;
            }

            auto sqrtd = sqrt(discriminant);
            
            //Finding the closes root closest to the camera, evaluating min and max out of result
            auto root = (h - sqrtd) / a;
            //If the first root is out of bound try the second one, if both are out of bound return false
            if (!ray_t.surrounds(root)) {
                root = (h + sqrtd) / a;
                if (!ray_t.surrounds(root))
                    return false;
                }

            //Value assigning to hit_record object
            rec.t = root;
            rec.hit_point = r.at(rec.t);
            vec3 outward_normal = (rec.hit_point - center) / radius;
            //Checks what does the dot product of the vectors returns and sets normal accordingly
            rec.set_face_normal(r, outward_normal);

            return true;
        }
};
#endif