#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "raylib.h"
#include <limits>

typedef struct point_mass{
  Vector2 postion;
  Vector2 velocity;
  float radius;
  Color color;
  float start_time;
}Point;

typedef struct collision{
  Vector2 normal{0.f, 0.f};
  float depth = - std::numeric_limits<float>::infinity();  
}Collision;

#endif
