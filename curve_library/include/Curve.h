#ifndef CURVE_H
#define CURVE_H

#include <string>


struct Point3D {
  double x, y, z;
};

class Curve {
public:
  virtual ~Curve() = default;
  virtual Point3D get_point(const double t) const = 0;
  virtual Point3D get_derivative(const double t) const = 0;
  virtual std::string get_type() const = 0;
};

#endif // CURVE_H
