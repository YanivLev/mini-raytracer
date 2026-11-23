#ifndef VEC3_H
#define VEC3_H

class vec3 {
    public:
        double e[3];

        vec3() : e{0, 0, 0} {};
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {};
        
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }
        
        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }
        
        // Adding vector v
        vec3& operator+=(const vec3& v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        // Multiplying by a scalar t
        vec3& operator*=(double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        // Dividing by a scalar t
        vec3& operator/=(double t) {
            return *this *= (1/t);
        }

        // Magnitude of the vector
        double length() const {
            return sqrt(length_squared());
        }
        
        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

// point3 is just an alias for vec3, but useful for geometric clarity in the code
using point3 = vec3;

// Vector Utility Functions

//
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Addition component wise
inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

// Subtraction component wise
inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

// Multiplies elements component wise, mainly for RGB color blending
inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

// Scalar multiplication u(vector) * t
inline vec3 operator*(const vec3& u, double t) {
    return vec3(u.e[0] * t, u.e[1] * t, u.e[2] * t);
}

// Scalar multiplication t * u(vector)
inline vec3 operator*(double t, const vec3& u) {
    return u * t;
}

// Division logic
inline vec3 operator/(const vec3& u, double t) {
    return u * (1/t);
}

// Dot product
inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1] 
         + u.e[2] * v.e[2];
}

// Cross product
inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3( (u.e[1] * v.e[2]) - (u.e[2] * v.e[1]),
                 (u.e[2] * v.e[0]) - (u.e[0] * v.e[2]),
                 (u.e[0] * v.e[1]) - (u.e[1] * v.e[0]));
}

// Unit vector convertion
inline vec3 unit_vector(const vec3& u) {
    return u / u.length();
}


#endif