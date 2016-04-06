#include "MathLine.h"
#include <stdlib.h>
#include <iostream>

#include <cmath>
#include <armadillo>

using namespace arma;

// Rotation Transformation
void MathLine::rotate_x(double angle) {
  tangent_.rotate_x(angle);
  origin_.rotate_x(angle);
}

void MathLine::rotate_y(double angle) {
  tangent_.rotate_y(angle);
  origin_.rotate_y(angle);
}

void MathLine::rotate_z(double angle) {
  tangent_.rotate_z(angle);
  origin_.rotate_z(angle);
}

// Translation Transformation
void MathLine::translate(double x_translation, double y_translation, double z_translation) {
  origin_.translate(x_translation, y_translation, z_translation);
}

void MathLine::translate_with_point(MathPoint point) {
  origin_.translate_with_point(point);
}

// Line Operations
double MathLine::distance_to_point(MathPoint point) {
  MathVector origin_to_point = MathVector::create_with_points(MathPoint::origin(), point);
  MathVector cross_product_with_tangent = origin_to_point.cross_product_with_vector(tangent());

  double cross_product_magnitude = abs(cross_product_with_tangent.magnitude());
  double tangent_vector_magnitude = abs(tangent().magnitude());

  double distance = cross_product_magnitude/tangent_vector_magnitude;
  return distance;
}

double MathLine::distance_to_line(MathLine otherLine) {
  MathVector origin_vector = MathVector::create_with_points(origin(), otherLine.origin());
  MathVector cross_product = tangent().cross_product_with_vector(otherLine.tangent());

  double numerator = origin_vector.dot_product_with_vector(cross_product);
  double denominator = cross_product.magnitude();

  double distance = abs(numerator)/abs(denominator);
  return distance;
}

MathPoint MathLine::midpoint_of_minimum_distance_to_line(MathLine other_line) {
  double A = pow(tangent().magnitude(), 2);
  double B = tangent().dot_product_with_vector(other_line.tangent());

  double C = pow(other_line.tangent().magnitude(), 2);

  MathVector vector_between_line_origins = MathVector::create_with_points(origin(), other_line.origin());
  double E = tangent().dot_product_with_vector(vector_between_line_origins);
  double F = other_line.tangent().dot_product_with_vector(vector_between_line_origins);

  mat B_matrix;
  B_matrix << E << endr
           << F << endr;

  mat A_matrix;
  A_matrix << A << -B << endr
           << B << -C << endr;

  mat X = solve(A_matrix, B_matrix);

  double s_param = X.at(0);
  double t_param = X.at(1);

  double x_point_1 = origin().x() + s_param*tangent().x_component();
  double y_point_1 = origin().y() + s_param*tangent().y_component();
  double z_point_1 = origin().z() + s_param*tangent().z_component();

  double x_point_2 = other_line.origin().x() + t_param*other_line.tangent().x_component();
  double y_point_2 = other_line.origin().y() + t_param*other_line.tangent().y_component();
  double z_point_2 = other_line.origin().z() + t_param*other_line.tangent().z_component();

  MathPoint closest_point_1 = MathPoint(x_point_1, y_point_1, z_point_1);
  MathPoint closest_point_2 = MathPoint(x_point_2, y_point_2, z_point_2);
  MathPoint closest_midpoint = closest_point_1.midpoint_with_point(closest_point_2);

  return closest_midpoint;

}

// Debugging Methods
void MathLine::describe() {
  std::cout << "MathLine: " << this << std::endl;
  std::cout << "Origin:" << std::endl;
  origin().describe();
  std::cout << "Tangent:" << std::endl;
  tangent().describe();
}
