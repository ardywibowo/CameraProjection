#include "MathPoint.h"
#include <iostream>
#include <cmath>

// Class Methods
double MathPoint::distance_to_point (MathPoint other_point) {
  double x_difference = x() - other_point.x();
  double y_difference = y() - other_point.y();
  double z_difference = z() - other_point.z();

  double distance = sqrt(pow(x_difference, 2) + pow(y_difference, 2) + pow(z_difference, 2));
  return distance;
}

MathPoint MathPoint::midpoint_with_point (MathPoint other_point) {
  double midpoint_x = (x() + other_point.x())/2;
  double midpoint_y = (y() + other_point.y())/2;
  double midpoint_z = (z() + other_point.z())/2;

  MathPoint midpoint = MathPoint(midpoint_x, midpoint_y, midpoint_z);
  return midpoint;
}

// Rotation Transformations
void MathPoint::rotate_x (double angle) {
  double current_y = y();
  double current_z = z();

  y_ = current_y*cos(angle) - current_z*sin(angle);
  z_ = current_y*sin(angle) + current_z*cos(angle);
}

void MathPoint::rotate_y (double angle) {
  double current_z = z();
  double current_x = x();

  z_ = current_z*cos(angle) - current_x*sin(angle);
  x_ = current_z*sin(angle) + current_x*cos(angle);
}

void MathPoint::rotate_z (double angle) {
  double current_x = x();
  double current_y = y();

  x_ = current_x*cos(angle) - current_y*sin(angle);
  y_ = current_x*sin(angle) + current_y*cos(angle);
}

// Translation Transformation
void MathPoint::translate(double x_translation, double y_translation, double z_translation) {
  x_ += x_translation;
  y_ += y_translation;
  z_ += z_translation;
}

void MathPoint::translate_with_point(MathPoint other_point) {
  x_ -= other_point.x();
  y_ -= other_point.y();
  z_ -= other_point.z();
}

// Static Functions
MathPoint MathPoint::origin() {
  return MathPoint(0, 0, 0);
}

// Debugging Methods
void MathPoint::describe() {
  std::cout << "MathPoint: " << this << std::endl;
  std::cout << "X = " << x() << " Y = " << y() << " Z = " << z() << "\n" << std::endl;
}
