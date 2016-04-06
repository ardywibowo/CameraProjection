#include "MathPoint.h"
#include "MathVector.h"

#ifndef MathLine_h
#define MathLine_h

class MathLine : public GeometricObject {
private:
  // Data
  MathPoint origin_;
  MathVector tangent_;

public:
  // Constructor
  MathLine () {
    origin_ = MathPoint();
    tangent_ = MathVector();
  };
  MathLine (MathPoint o, MathVector t) : origin_(o), tangent_(t) { }

  // Getters and Setters
  MathPoint origin() { return origin_; }
  MathVector tangent() { return tangent_; }

  // Rotation Transformation
  virtual void rotate_x(double angle);
  virtual void rotate_y(double angle);
  virtual void rotate_z(double angle);

  // Translation Transformation
  virtual void translate(double x_translation, double y_translation, double z_translation);
  void translate_with_point(MathPoint point);

  // Line Operations
  double distance_to_point(MathPoint point);
  double distance_to_line(MathLine line);
  MathPoint midpoint_of_minimum_distance_to_line(MathLine other_line);

  // Debugging Methods
  void describe();
};

#endif
