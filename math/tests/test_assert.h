#pragma once

#undef NDEBUG
#include <cassert>
#include <cmath>

#include <string>

#define assert_throws(expr) {           \
            bool _ = false;             \
            try {                       \
                expr;                   \
            } catch (...) {             \
                _ = true;               \
            }                           \
            assert(_);                  \
        }

#define assert_nothrow(expr) {          \
            bool _ = false;             \
            try {                       \
                expr;                   \
            } catch (...) {             \
                _ = true;               \
            }                           \
            assert(!_);                 \
        }

#include "../math.hpp"

template <typename T>
class ApproxT {
public:
    ApproxT(const T &val) : val_(val), eps_(0.0001) {}

    const ApproxT &epsilon(double eps) {
        eps_ = eps;
        return *this;
    }

    T val_;
    double eps_;
};

inline bool operator==(float val, const ApproxT<double> &app) {
    return math::distance(val, (float)app.val_) < app.eps_;
}

inline bool operator==(const math::vec2 &val, const ApproxT<math::vec2> &app) {
    return math::distance(val, app.val_) < app.eps_;
}

inline bool operator==(const math::vec3 &val, const ApproxT<math::vec3> &app) {
    return math::distance(val, app.val_) < app.eps_;
}

inline bool operator==(const math::vec4 &val, const ApproxT<math::vec4> &app) {
    return math::distance(val, app.val_) < app.eps_;
}

inline ApproxT<double> Approx(double x) { return ApproxT<double>(x); }
inline ApproxT<math::vec2> Approx(const math::vec2 &v) { return ApproxT<math::vec2>(v); }
inline ApproxT<math::vec3> Approx(const math::vec3 &v) { return ApproxT<math::vec3>(v); }
inline ApproxT<math::vec4> Approx(const math::vec4 &v) { return ApproxT<math::vec4>(v); }
inline ApproxT<math::vec2> Approx2(double x, double y) { return ApproxT<math::vec2>(math::vec2((float)x, (float)y)); }
inline ApproxT<math::vec3> Approx3(double x, double y, double z) { return ApproxT<math::vec3>(math::vec3((float)x, (float)y, (float)z)); }
inline ApproxT<math::vec4> Approx4(double x, double y, double z, double w) { return ApproxT<math::vec4>(math::vec4((float)x, (float)y, (float)z, (float)w)); }
