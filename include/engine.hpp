#ifndef ENGINE_H
#define ENGINE_H

#include "primitives.hpp"
#include "raylib.h"
#include "shape.hpp"
#include <vector>

class Engine{
  private:
    std::vector<Point> points;
    std::vector<Shape> environment;
    
    Vector2 gravity{0.f, 9.8f};
    float elasticity = 0.5;
    float friction = 100;

  public:
    //set
    void add_point(Point point){
      this->points.push_back(point);
    }

    //TODO
    void remove_point(){
      this->points.pop_back();
    }

    void add_environment(Shape shape){
      environment.push_back(shape);
    }


    //get
    std::vector<Point>* get_points(){
      return &this->points;
    }
    
    //members
    void update(float dt);
    Collision find_collsion(Vector2 const &postion);
    void draw();
};

#endif
