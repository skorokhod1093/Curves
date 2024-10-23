#include "Ellipse.h"

#include <cmath>
#include <stdexcept>


Ellipse::Ellipse(const double radiusX, const double radiusY) {
  if (radiusX <= 0 || radiusY <= 0) {
    throw std::invalid_argument("Radii must be positive.");
  }
  this->radiusX = radiusX;
  this->radiusY = radiusY;
}

Point3D Ellipse::get_point(const double t) const {
  return {radiusX * cos(t), radiusY * sin(t), 0};
}

Point3D Ellipse::get_derivative(const double t) const {
  return {-radiusX * sin(t), radiusY * cos(t), 0};
}

std::string Ellipse::get_type() const {
  return "Ellipse";
}
