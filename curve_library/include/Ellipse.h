#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "Curve.h"


class Ellipse : public Curve {
public:
  Ellipse(const double radiusX, const double radiusY);
  Point3D get_point(const double t) const override;
  Point3D get_derivative(const double t) const override;
  std::string get_type() const override;

private:
  double radiusX, radiusY;
};

#endif // ELLIPSE_H
