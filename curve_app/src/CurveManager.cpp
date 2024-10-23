#include "CurveManager.h"

#include <iostream>
#include <cmath>
#include <algorithm>
#include <random>
#include <omp.h>


CurveManager::CurveManager() {}

void CurveManager::process_curves() {
  generate_random_curves();
  print_curves_info();
  filter_circles();
  sort_circles_by_radius();
  calculate_total_radius();
}

void CurveManager::generate_random_curves() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> dist(ini.min_value_gen, ini.max_value_gen);
  for (int i = 0; i < ini.number_of_curves; ++i) {
    const int type = i % 3;
    switch (type) {
      case 0:
        curves.push_back(std::make_shared<Circle>(dist(gen)));
        break;
      case 1:
        curves.push_back(std::make_shared<Ellipse>(dist(gen), dist(gen)));
        break;
      case 2:
        curves.push_back(std::make_shared<Helix>(dist(gen), dist(gen)));
        break;
    }
  }
}

void CurveManager::print_curves_info() const {
  for (const auto& curve : curves) {
    Point3D point = curve->get_point(ini.t);
    Point3D derivative = curve->get_derivative(ini.t);
    std::cout << "Type: " << curve->get_type() << "\n";
    std::cout << "Point: (" << point.x << ", " << point.y << ", " << point.z << ")\n";
    std::cout << "Derivative: (" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")\n";
    std::cout << "-----------------------------\n";
  }
}

void CurveManager::filter_circles() {
  for (const auto& curve : curves) {
    if (auto circle = std::dynamic_pointer_cast<Circle>(curve)) {
      circles.push_back(circle);
    }
  }
}

void CurveManager::sort_circles_by_radius() {
  std::sort(circles.begin(), circles.end(), [](const std::shared_ptr<Circle>& a, const std::shared_ptr<Circle>& b) {
    return a->get_radius() < b->get_radius();
  });
}

void CurveManager::calculate_total_radius() const {
  double total_radius = 0.0;
#pragma omp parallel for reduction(+:total_radius)
  for (int i = 0; i < circles.size(); ++i) {
    total_radius += circles[i]->get_radius();
  }
  std::cout << "Total radius of circles: " << total_radius << std::endl << std::endl;
}
