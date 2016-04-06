#include "MathStructures/MathPoint.h"
#include "MathStructures/MathVector.h"
#include "MathStructures/MathLine.h"
#include "MathStructures/MathPlane.h"

#ifndef Camera_h
#define Camera_h

class Camera {
private:
  // Field of View Data
  double VFOV_;
  double HFOV_;

  // Image Size Data
  int maximum_image_x_;
  int maximum_image_y_;

  // Orientation Data in Radians
  double roll_;
  double pitch_;
  double yaw_;

  // Location Data in Meters
  MathPoint position_;

public:
  // Constructors
  Camera () { };

  Camera (double vfov, double hfov, int maximum_image_x, int maximum_image_y)
  : VFOV_(vfov), HFOV_(hfov), maximum_image_x_(maximum_image_x), maximum_image_y_(maximum_image_y) {
    position_ = MathPoint();
  };

  // Setters and Getters
  void set_camera_orientation(double roll, double pitch, double yaw);
  void set_camera_position(MathPoint& point) { position_ = point; }

  double VFOV() { return VFOV_; }
  double HFOV() { return HFOV_; }

  int maximum_image_x () { return maximum_image_x_; }
  int maximum_image_y () { return maximum_image_y_; }

  double roll() { return roll_; }
  double pitch() { return pitch_; }
  double yaw() { return yaw_; }

  MathPoint position() { return position_; }
};

#endif
