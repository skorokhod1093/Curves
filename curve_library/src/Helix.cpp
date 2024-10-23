#include "Helix.h"

#include <cmath>
#include <stdexcept>


Helix::Helix(const double radius, const double step) {
  if (radius <= 0 || step <= 0) {
    throw std::invalid_argument("Radius and step must be positive.");
  }
  this->radius = radius;
  this->step = step;
}

Point3D Helix::get_point(const double t) const {
  return {radius * cos(t), radius * sin(t), step * t / (2 * PI)};
}

Point3D Helix::get_derivative(const double t) const {
  return {-radius * sin(t), radius * cos(t), step / (2 * PI)};
}

std::string Helix::get_type() const {
  return "Helix";
}
