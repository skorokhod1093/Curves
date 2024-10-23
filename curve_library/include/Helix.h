#ifndef HELIX_H
#define HELIX_H

#include "Curve.h"


class Helix : public Curve {
public:
  Helix(const double radius, const double step);
  Point3D get_point(const double t) const override;
  Point3D get_derivative(const double t) const override;
  std::string get_type() const override;

private:
  double radius, step;
  const double PI = 3.14159265358979323846;
};

#endif // HELIX_H
