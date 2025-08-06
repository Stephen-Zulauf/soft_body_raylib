
#ifndef SHAPE_H
#define SHAPE_H

#include "raylib.h"
#include "primitives.hpp"
#include "raymath.h"
#include <cstdlib>

//just lines for now to represent ground/walls
class Shape{
  private:
    Vector2 start_postion;
    Vector2 end_postion;
    //TODO: add current position to adjust positions in real time
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

    Collision get_collision(Point point){
      Vector2 normal;
      float depth;

      //negate the velocity of the point
      normal = Vector2Negate(point.velocity);

      //normalise
      normal = Vector2Normalize(normal);

      //TODO:need screen size to calc depth most likely
      int scrn_width = GetScreenWidth();
      int scrn_height = GetScreenHeight();
      
      if(std::abs(point.postion.x) >= this->end_postion.x){
        depth = point.postion.x - this->end_postion.x;
      }else if(std::abs(point.postion.x) <= this->start_postion.x){
        depth = scrn_width - this->start_postion.x;
      }else if(std::abs(point.postion.y) >= this->start_postion.y){
        depth = scrn_height - this->start_postion.y;
      }else{
        depth = 1;
      }

      return collision{normal, depth};      
    }
    
};


#endif
