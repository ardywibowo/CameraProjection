#include "MathPlane.h"
#include <iostream>

// Constructors
MathPlane::MathPlane(MathPoint p, MathVector nv) {
  normal_vector_ = nv;
  point_ = p;
  A_ = normal_vector().x_component();
  B_ = normal_vector().y_component();
  C_ = normal_vector().z_component();
  D_ = normal_vector().x_component()*point().x() + normal_vector().y_component()*point().y() + normal_vector().z_component()*point().z();
}

MathPlane::MathPlane (double A, double B, double C, double D) {
  normal_vector_ = MathVector(A, B, C);
  point_ = MathPoint(0, 0, D/normal_vector().z_component());
  A_ = A;
  B_ = B;
  C_ = C;
  D_ = D;
}

// Class Methods
bool MathPlane::is_parallel_with_vector (MathVector vector) {
  if (normal_vector().dot_product_with_vector(vector) == 0) {
    return true;
  }
  return false;
}

double MathPlane::intersection_parameter_with_line (MathLine line) {
  double numerator_of_parameter = D() - A()*line.origin().x() - B()*line.origin().y() - C()*line.origin().z();
  double denominator_of_parameter = A()*line.tangent().x_component() + B()*line.tangent().y_component() + C()*line.tangent().z_component();

  double parameter_of_intersection = numerator_of_parameter/denominator_of_parameter;
  return parameter_of_intersection;
}

MathPoint MathPlane::point_of_intersection_with_line (MathLine line) {
  double parameter_of_intersection = intersection_parameter_with_line(line);

  double x_intersection = line.origin().x() + parameter_of_intersection * line.tangent().x_component();
  double y_intersection = line.origin().y() + parameter_of_intersection * line.tangent().y_component();
  double z_intersection = line.origin().z() + parameter_of_intersection * line.tangent().z_component();

  MathPoint point_of_intersection = MathPoint(x_intersection, y_intersection, z_intersection);
  return point_of_intersection;
}

// Rotation Transformations
void MathPlane::rotate_x (double angle) {
  normal_vector_.rotate_x(angle);
  point_.rotate_x(angle);
}

void MathPlane::rotate_y (double angle) {
  normal_vector_.rotate_y(angle);
  point_.rotate_y(angle);

  MathPlane(point_, normal_vector_);
}

void MathPlane::rotate_z (double angle) {
  normal_vector_.rotate_z(angle);
  point_.rotate_z(angle);

  MathPlane(point_, normal_vector_);
}

// Translation Transformation
void MathPlane::translate(double x_translation, double y_translation, double z_translation) {
  point_.translate(x_translation, y_translation, z_translation);
}

void MathPlane::translate_with_point(MathPoint otherPoint) {
  point_.translate_with_point(otherPoint);
}

// Debugging Methods
void MathPlane::describe() {
  std::cout << "MathPlane: " << this << std::endl;
  std::cout << "Point on Plane:" << std::endl;
  point().describe();
  std::cout << "Normal Vector:" << std::endl;
  normal_vector().describe();
}
