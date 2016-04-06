#include "MathStructures/MathPoint.h"
#include "MathStructures/MathVector.h"
#include "MathStructures/MathLine.h"
#include "MathStructures/MathPlane.h"
#include "Camera.h"

#include <vector>
#include <cmath>

#ifndef CameraProjectionKit_h
#define CameraProjectionKit_h

using namespace std;

class CameraProjectionKit {
private:
  Camera camera_;
public:
  // Constructors
  CameraProjectionKit () { camera_ = Camera(); }

  // Setter and Getter Methods
  void set_camera (Camera& new_camera) { camera_ = new_camera; }
  Camera& camera() { return camera_; }

  // Rotation Transformations
  void rotate_object_to_camera_coordinate_system(GeometricObject& object);
  void rotate_object_to_normal_coordinate_system(GeometricObject& object);

  // Translation Transformations
  void translate_object_to_camera_coordinate_system(GeometricObject& object);
  void translate_object_to_normal_coordinate_system(GeometricObject& object);

  // Calculation Methods
  MathVector projection_vector_with_pixel_coordinates(int x, int y);
  MathLine projection_line_of_pixel_point(MathPoint pixel_point);
};

#endif
