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
    return fabs(val - (float)app.val_) < app.eps_;
}

inline bool operator==(double val, const ApproxT<double> &app) {
    return fabs(val - app.val_) < app.eps_;
}

inline bool operator==(const math::vec2 &val, const ApproxT<math::dvec2> &app) {
    return fabs(val[0] - app.val_[0]) < app.eps_ &&
           fabs(val[1] - app.val_[1]) < app.eps_;
}

inline bool operator==(const math::dvec2 &val, const ApproxT<math::dvec2> &app) {
    return fabs(val[0] - app.val_[0]) < app.eps_ &&
           fabs(val[1] - app.val_[1]) < app.eps_;
}

inline bool operator==(const math::vec3 &val, const ApproxT<math::dvec3> &app) {
    return fabs(val[0] - app.val_[0]) < app.eps_ &&
           fabs(val[1] - app.val_[1]) < app.eps_ &&
           fabs(val[2] - app.val_[2]) < app.eps_;
}

inline bool operator==(const math::dvec3 &val, const ApproxT<math::dvec3> &app) {
    return fabs(val[0] - app.val_[0]) < app.eps_ &&
           fabs(val[1] - app.val_[1]) < app.eps_ &&
           fabs(val[2] - app.val_[2]) < app.eps_;
}
inline bool operator==(const math::vec4 &val, const ApproxT<math::dvec4> &app) {
    return fabs(val[0] - app.val_[0]) < app.eps_ &&
           fabs(val[1] - app.val_[1]) < app.eps_ &&
           fabs(val[2] - app.val_[2]) < app.eps_ &&
           fabs(val[3] - app.val_[3]) < app.eps_;
}

inline bool operator==(const math::dvec4 &val, const ApproxT<math::dvec4> &app) {
    return fabs(val[0] - app.val_[0]) < app.eps_ &&
           fabs(val[1] - app.val_[1]) < app.eps_ &&
           fabs(val[2] - app.val_[2]) < app.eps_ &&
           fabs(val[3] - app.val_[3]) < app.eps_;
}

inline ApproxT<double> Approx(double x) { return ApproxT<double>(x); }
inline ApproxT<math::dvec2> Approx(const math::vec2 &v) { return ApproxT<math::dvec2>(math::dvec2(v)); }
inline ApproxT<math::dvec3> Approx(const math::vec3 &v) { return ApproxT<math::dvec3>(math::dvec3(v)); }
inline ApproxT<math::dvec4> Approx(const math::vec4 &v) { return ApproxT<math::dvec4>(math::dvec4(v)); }
inline ApproxT<math::dvec2> Approx2(double x, double y) { return ApproxT<math::dvec2>({ x, y }); }
inline ApproxT<math::dvec3> Approx3(double x, double y, double z) { return ApproxT<math::dvec3>({ x, y, z }); }
inline ApproxT<math::dvec4> Approx4(double x, double y, double z, double w) { return ApproxT<math::dvec4>({ x, y, z, w }); }
