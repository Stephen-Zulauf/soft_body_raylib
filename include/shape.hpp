
#ifndef SHAPE_H
#define SHAPE_H

#include "raylib.h"
#include "primitives.hpp"
#include "raymath.h"

//just lines for now to represent ground/walls
class Shape{
  private:
    Vector2 start_postion;
    Vector2 end_postion;
    float width;
    Color color;

  public:

    void set_start(Vector2 pos){
      start_postion = pos;
    }
    void set_end(Vector2 pos){
      end_postion = pos;
    }
    void set_width(float nwidth){
      width = nwidth;
    }
    void set_color(Color ncolor){
      color = ncolor;
    }

    void draw(){
      DrawLineEx(start_postion, end_postion, width, color);
    }

    bool find_collison(Point point){
      return CheckCollisionCircleLine(point.postion, point.radius, start_postion, end_postion);
    }

    //TODO normal only needs to be the opposite direction of point velocity vector
    Collision get_collision(Point point){
      Vector2 line_direction = Vector2Subtract(end_postion, start_postion);
      Vector2 delta = Vector2Subtract(point.postion, line_direction);
      float distance = Vector2Length(delta);
      Vector2 normal = delta/distance;
      float depth = distance;

      return collision{normal, depth};      
    }
    
};


#endif
