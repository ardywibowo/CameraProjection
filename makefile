CPP_FILES = CameraProjectionKit.cpp Camera.cpp MathStructures/MathPoint.cpp MathStructures/MathVector.cpp MathStructures/MathLine.cpp MathStructures/MathPlane.cpp main.cpp
HPP_FILES = GeometricObject.h CameraProjectionKit.h Camera.h MathPoint.h MathVector.h MathPlane.h MathLine.h
OBJ_FILES = $(patsubst %.cpp,o/%.o,$(CPP_FILES))

OUT = test
CPP_FLAGS = -std=c++11

all: $(CXX) -o $(OUT) $(OBJ_FILES)
