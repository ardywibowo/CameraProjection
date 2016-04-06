#include "GeometricObject.h"

#ifndef MathPoint_h
#define MathPoint_h

class MathPoint : public GeometricObject {
private:
  // Data
  double x_;
  double y_;
  double z_;

public:
  // Initialization
  MathPoint () : x_(0), y_(0), z_(0) { };
  MathPoint (double x, double y, double z) : x_(x), y_(y), z_(z) { }
  MathPoint (double x, double y) : x_(x), y_(y), z_(0) { }

  // Setters and Getters
  double x() { return x_; }
  double y() { return y_; }
  double z() { return z_; }

  // Class Methods
  double distance_to_point (MathPoint other_point);
  MathPoint midpoint_with_point (MathPoint other_point);

  // Rotation Transformations
  virtual void rotate_x (double angle);
  virtual void rotate_y (double angle);
  virtual void rotate_z (double angle);

  // Translation Transformation
  virtual void translate(double x_translation, double y_translation, double z_translation);
  void translate_with_point(MathPoint other_point);

  // Static Functions
  static MathPoint origin();

  // Debugging Methods
  void describe();
};

#endif
