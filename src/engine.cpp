
#include "../include/engine.hpp"
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <ostream>
#include <stdio.h>

void Engine::update(float dt){

  //implement Euler integration method
  for (auto &p: points){
    p.velocity += Vector2Scale(gravity, dt);
  }

  for(auto &p: points){
    p.postion += Vector2Scale(p.velocity, dt);
  }

  //resolve collisions
  // //for each point in simulation
  // //// for each shape in environment

  for(auto &p : points){
    for(auto &s : environment){
      //check if point is colliding
      if(s.find_collison(p)){

        DrawText("collision", 190, 0, 20, LIGHTGRAY);
        Collision c = s.get_collision(p);
        
        // resolve the constraint
        std::cout << p.postion.x << "," << p.postion.y << std::endl;
        p.postion += Vector2Scale(c.normal, c.depth);
        std::cout << p.postion.x << "," << p.postion.y << std::endl;


        // compute the normal & tangential velocity
        Vector2 vn = c.normal * Vector2DotProduct(c.normal, p.velocity);
        Vector2 vt = p.velocity - vn;

        // apply bouncing
        vn = Vector2Scale(vn, elasticity);
        vn = Vector2Scale(vn, -1.0);

        // apply friction
        vt = Vector2Scale(vt, std::exp(- friction * dt));        

        // add up the new velocity
        p.velocity = vn + vt;

      }
    }
  }
  
}

void Engine::draw(){
  //Draw the environment
  for (auto &s : environment){
    s.draw();
  }

  // Draw the points
  for (auto &p : points){
    DrawCircleLinesV(p.postion, p.radius, p.color);
  }
  
}
