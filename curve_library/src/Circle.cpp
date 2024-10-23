#include "Circle.h"

#include <cmath>
#include <stdexcept>


Circle::Circle(const double radius) {
  if (radius <= 0) {
    throw std::invalid_argument("Radius must be positive.");
  }
  this->radius = radius;
}

Point3D Circle::get_point(const double t) const {
  return {radius * cos(t), radius * sin(t), 0};
}

Point3D Circle::get_derivative(const double t) const {
  return {-radius * sin(t), radius * cos(t), 0};
}

std::string Circle::get_type() const {
  return "Circle";
}

double Circle::get_radius() const {
  return radius;
}
