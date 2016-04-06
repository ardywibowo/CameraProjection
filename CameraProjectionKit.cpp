#include "CameraProjectionKit.h"
#include <iostream>
#include <float.h>

using namespace std;

// Rotation Transformations
void CameraProjectionKit::rotate_object_to_camera_coordinate_system(GeometricObject& object) {

  object.rotate_z(-camera_.yaw());
  object.rotate_y(-camera_.pitch());
  object.rotate_x(-camera_.roll());

}

void CameraProjectionKit::rotate_object_to_normal_coordinate_system(GeometricObject& object) {
  object.rotate_x(camera_.roll());
  object.rotate_y(camera_.pitch());
  object.rotate_z(camera_.yaw());
}

// Translation Transformations
void CameraProjectionKit::translate_object_to_camera_coordinate_system(GeometricObject& object) {
  object.translate(camera_.position().x(), camera_.position().y(), camera_.position().z());
}

void CameraProjectionKit::translate_object_to_normal_coordinate_system(GeometricObject& object) {
  object.translate(-camera_.position().x(), -camera_.position().y(), -camera_.position().z());
}


// Calculation Methods
MathVector CameraProjectionKit::projection_vector_with_pixel_coordinates(int x, int y) {
  double axis_x = camera_.maximum_image_x()/2.0 - x;
  double axis_y = camera_.maximum_image_y()/2.0 - y;

  double horizontal_offset_angle = atan2( axis_x * tan(camera_.HFOV()/2.0), camera_.maximum_image_x()/2.0 );
  double vertical_offset_angle   = atan2( axis_y * tan(camera_.VFOV()/2.0), camera_.maximum_image_y()/2.0 );

  double y_angle = horizontal_offset_angle;
  double z_angle = vertical_offset_angle;

  MathVector projection_vector = MathVector(1.0, tan(y_angle), tan(z_angle));

  return projection_vector;
}

MathLine CameraProjectionKit::projection_line_of_pixel_point(MathPoint pixel_point) {
  MathVector projection_vector = projection_vector_with_pixel_coordinates(pixel_point.x(), pixel_point.y());
  MathLine projection_line = MathLine(MathPoint::origin(), projection_vector);

  // Line is in camera coordinate system. Transform to regular coordinate system
  projection_line = rotate_line_to_normal_coordinate_system(projection_line);
  projection_line = translate_line_to_normal_coordinate_system(projection_line);

  return projection_line;
}
