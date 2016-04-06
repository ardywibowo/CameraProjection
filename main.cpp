// Standard Libraries
#include <iostream>
#include <time.h>
#include <locale.h>
#include <getopt.h>

// Camera Data Manager
#include "Camera.h"
#include "MathStructures/MathPoint.h"
#include "MathStructures/MathVector.h"
#include "MathStructures/MathLine.h"
#include "MathStructures/MathPlane.h"
#include "CameraProjectionKit.h"

int main(int argc, char const *argv[]) {
  // Request Camera Parameters
  // Put it in a camera data manager
  double HFOV;
  double VFOV;

  // Request User Input
  std::cout << "Separate values with spaces" << std::endl;
  std::cout << "Input Camera HFOV VFOV in degrees" << std::endl;
  std::cin >> HFOV;
  std::cin >> VFOV;
  // Convert to Radians
  HFOV = HFOV*M_PI/180;
  VFOV = VFOV*M_PI/180;

  int imageResolutionX;
  int imageResolutionY;
  std::cout << "Input image resolution X Y" << std::endl;
  std::cin >> imageResolutionX;
  std::cin >> imageResolutionY;

  while (true) {
    // Request Orientation Data
    double roll;
    double pitch;
    double yaw;

    std::cout << "Input Camera Rotation Data: Roll Pitch Yaw in degrees (Default: 0 90 Yaw)" << std::endl;
    std::cin >> roll;
    std::cin >> pitch;
    std::cin >> yaw;

    // Convert to Radians
    roll = roll*M_PI/180;
    pitch = pitch*M_PI/180;
    yaw = yaw*M_PI/180;

    // Request Camera Location Data
    double cameraX;
    double cameraY;
    double cameraZ;

    std::cout << "Input Current Camera Location in meters (X Y Z)" << std::endl;
    std::cin >> cameraX;
    std::cin >> cameraY;
    std::cin >> cameraZ;

    // Request Light Image Location Data
    int lightAmount;
    std::cout << "How many lights are in this image?" << std::endl;
    std::cin >> lightAmount;

    std::vector<int> lightPixelLocationVectorX;
    std::vector<int> lightPixelLocationVectorY;

    for (int i = 0; i < lightAmount; i++) {
      int lightPixelLocationX;
      int lightPixelLocationY;
      std::cout << "Input Light " << lightAmount << " Pixel Location in Image (X Y)"  << std::endl;
      std::cin >> lightPixelLocationX;
      std::cin >> lightPixelLocationY;
      lightPixelLocationVectorX.push_back(lightPixelLocationX);
      lightPixelLocationVectorY.push_back(lightPixelLocationY);
    }
  }

  return 0;
}
