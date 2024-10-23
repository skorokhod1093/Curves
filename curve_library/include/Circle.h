#ifndef CIRCLE_H
#define CIRCLE_H

#include "Curve.h"


class Circle : public Curve {
public:
    Circle(const double radius);
    Point3D get_point(const double t) const override;
    Point3D get_derivative(const double t) const override;
    std::string get_type() const override;
    double get_radius() const;

private:
    double radius;
};

#endif // CIRCLE_H
