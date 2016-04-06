# CameraProjection
Camera Projection and Geometric Transformation Library

This library provides a simple and intuitive library for basic mathematical and geometric transformations in 3D space. 
The library includes simple geometric functions such as finding line-line intersections, line-plane intersections, 
midpoint finding, unit vectors, translation transformations, and rotation transformations.

The library also includes a camera projection kit which handles projection from images to 3D space.
These projections from 2D to 3D is made by projecting pixels into lines/rays in 3D space.
I intended this library to be a general purpose library. If you want to see some applications of this library,
please see my Unmanned Aerial Vehicle project [here].

[here]: https://github.com/ardywibowo/AerialAR

## Applications

The library can be used for numerous applications related to computer vision and spatial intelligence.

For example, in my project, [AerialAR], getting the position of Points of Interest from the Google Maps API
and the position and orientation of the camera, I am able to show visible Points of Interest in camera imagery.

[AerialAR]: https://github.com/ardywibowo/AerialAR

The test executable I have provided here shows another application. The executable I have currently is a test for
a private project which involves detecting lights in a building. Knowing the position and orientation of a camera at all 
times, a map of the lights in a building can be constructed by projecting pixels into rays. Because the camera is able to 
take pictures at a high rate while moving, two pictures at similar but not equal positions can be taken. This allows 
stereoscopic reconstruction of the 3D location of the light

## Future Work
Currently, the library doesn't support computationally intensive methods such as finding intersections of 3D objects.
Also, another useful implementation would be 3D location finding using stereoscopic methods.
As of right now, the library by itself requires additional information in order to determine an accurate 3D location of
an object in the image. This can be fixed by using two images to project into 3D space. However, that may require some form
of feature detection, as the camera would need to differentiate each object in the image to avoid errors related to
stereoscopic vision.

All of these are planned implementations in the future
