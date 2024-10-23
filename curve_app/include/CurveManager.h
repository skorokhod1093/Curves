#ifndef CURVEMANAGER_H
#define CURVEMANAGER_H

#include "Circle.h"
#include "Ellipse.h"
#include "Helix.h"

#include <vector>
#include <memory>


class CurveManager {
  struct Ini {
    const double PI = 3.14159265358979323846;
    const double t = PI / 4;
    const int number_of_curves = 10;
    double min_value_gen = 1.0;
    double max_value_gen = 10.0;
  } ini;

public:
    CurveManager();
    void process_curves();
    void generate_random_curves();
    void print_curves_info() const;
    void filter_circles();
    void sort_circles_by_radius();
    void calculate_total_radius() const;

private:
    std::vector<std::shared_ptr<Curve>> curves;
    std::vector<std::shared_ptr<Circle>> circles;
};

#endif // CURVEMANAGER_H
