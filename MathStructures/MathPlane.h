#include "MathPoint.h"
#include "MathVector.h"
#include "MathLine.h"

#ifndef MathPlane_h
#define MathPlane_h

class MathPlane : public GeometricObject {
private:
  // Data
  MathPoint point_;
  MathVector normal_vector_;

  // Coefficients Ax + By + Cz = D
  double A_;
  double B_;
  double C_;
  double D_;

public:
  // Constructors
  MathPlane () : A_(0), B_(0), C_(0), D_(0) {
    point_ = MathPoint();
    normal_vector_ = MathVector();
  }
  MathPlane(MathPoint p, MathVector nv);
  MathPlane (double A, double B, double C, double D);

  // Setters and Getters
  MathPoint point() { return point_; }
  MathVector normal_vector() { return normal_vector_; }
  double A() { return A_; }
  double B() { return B_; }
  double C() { return C_; }
  double D() { return D_; }

  // Class Methods
  bool is_parallel_with_vector (MathVector vector);
  double intersection_parameter_with_line (MathLine line);
  MathPoint point_of_intersection_with_line (MathLine line);

  // Rotation Transformations
  virtual void rotate_x (double angle);
  virtual void rotate_y (double angle);
  virtual void rotate_z (double angle);

  // Translation Transformation
  virtual void translate(double x_translation, double y_translation, double z_translation);
  void translate_with_point(MathPoint otherPoint);

  // Debugging Methods
  void describe();
};

#endif
