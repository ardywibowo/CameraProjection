#include "GeometricObject.h"
#include "MathPoint.h"

#ifndef MathVector_h
#define MathVector_h

class MathVector : public GeometricObject {
private:
  // Data
  double x_component_;
  double y_component_;
  double z_component_;

public:
  // Constructors
  MathVector () : x_component_(0), y_component_(0), z_component_(0) { }
  MathVector (double x, double y, double z) : x_component_(x), y_component_(y), z_component_(z) { }

  static MathVector create_with_cartesian(double x, double y, double z);
  static MathVector create_with_points(MathPoint a, MathPoint b);
  static MathVector create_with_spherical_coordinates(double magnitude, double theta, double phi);

  // Setters and Getters
  double x_component() { return x_component_; }
  double y_component() { return y_component_; }
  double z_component() { return z_component_; }

  // Vector Properties
  double magnitude();

  // Vector Operations
  double dot_product_with_vector(MathVector other_vector);
  MathVector cross_product_with_vector(MathVector other_vector);
  double angle_with_vector(MathVector other_vector);

  // Rotation Transformations
  virtual void rotate_x (double angle);
  virtual void rotate_y (double angle);
  virtual void rotate_z (double angle);

  // Translation Transformation
  virtual void translate(double x_translation, double y_translation, double z_translation) { };

  // Static Functions
  static MathVector unit_vector_i();
  static MathVector unit_vector_j();
  static MathVector unit_vector_k();

  // Debugging Methods
  void describe();
};

#endif
