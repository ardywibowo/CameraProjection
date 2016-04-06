#ifndef GeometricObject_h
#define GeometricObject_h

class GeometricObject {
public:
  GeometricObject () { }
  virtual void rotate_x(double angle) = 0;
  virtual void rotate_y(double angle) = 0;
  virtual void rotate_z(double angle) = 0;

  virtual void translate(double x_translation, double y_translation, double z_translation) = 0;
};

#endif
