#include "MathVector.h"
#include <iostream>
#include <cmath>

// Constructors
MathVector MathVector::create_with_cartesian(double x, double y, double z) {
  return MathVector(x, y, z);
}

MathVector MathVector::create_with_points(MathPoint a, MathPoint b) {
  double x_comp = b.x() - a.x();
  double y_comp = b.y() - a.y();
  double z_comp = b.z() - a.z();

  return MathVector(x_comp, y_comp, z_comp);
}

MathVector MathVector::create_with_spherical_coordinates(double magnitude, double theta, double phi) {
  double x_comp = magnitude * sin(phi) * cos(theta);
  double y_comp = magnitude * sin(phi) * sin(theta);
  double z_comp = magnitude * cos(phi);

  return MathVector(x_comp, y_comp, z_comp);
}

// Vector Properties
double MathVector::magnitude() {
  double magnitude = sqrt(pow(x_component(), 2) + pow(y_component(), 2) + pow(z_component(), 2));
  return magnitude;
}

// Vector Operations
double MathVector::dot_product_with_vector(MathVector other_vector) {
  double dot_x = x_component() * other_vector.x_component();
  double dot_y = y_component() * other_vector.y_component();
  double dot_z = z_component() * other_vector.z_component();

  double dot_product = dot_x + dot_y + dot_z;
  return dot_product;
}

MathVector MathVector::cross_product_with_vector(MathVector other_vector) {
  double x_comp = y_component()*other_vector.z_component() - z_component()*other_vector.y_component();
  double y_comp = z_component()*other_vector.x_component() - x_component()*other_vector.z_component();
  double z_comp = x_component()*other_vector.y_component() - y_component()*other_vector.x_component();

  return MathVector(x_comp, y_comp, z_comp);
}

double MathVector::angle_with_vector(MathVector other_vector) {
  double angle = acos(dot_product_with_vector(other_vector)/(other_vector.magnitude() * magnitude()));
}

// Rotation Transformations
void MathVector::rotate_x (double angle) {
  double current_y = y_component();
  double current_z = z_component();

  y_component_ = current_y*cos(angle) - current_z*sin(angle);
  z_component_ = current_y*sin(angle) + current_z*cos(angle);
}

void MathVector::rotate_y (double angle) {
  double current_z = z_component();
  double current_x = x_component();

  z_component_ = current_z*cos(angle) - current_x*sin(angle);
  x_component_ = current_z*sin(angle) + current_x*cos(angle);
}

void MathVector::rotate_z (double angle) {
  double current_x = x_component();
  double current_y = y_component();

  x_component_ = current_x*cos(angle) - current_y*sin(angle);
  y_component_ = current_x*sin(angle) + current_y*cos(angle);
}

// Static Functions
MathVector MathVector::unit_vector_i() {
  return MathVector(1, 0, 0);
}

MathVector MathVector::unit_vector_j() {
  return MathVector(0, 1, 0);
}

MathVector MathVector::unit_vector_k() {
  return MathVector(0, 0, 1);
}

// Debugging Methods
void MathVector::describe() {
  std::cout << "MathVector: " << this << std::endl;
  std::cout << "X = " << x_component() << " Y = " << y_component() << " Z = " << z_component() << "\n" << std::endl;
}
