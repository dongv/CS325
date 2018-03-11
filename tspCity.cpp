/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tspCity.cpp
 * Author: Sam
 * 
 * Created on March 10, 2018, 10:59 PM
 */

#include "tspCity.hpp"

tspCity::tspCity() {
    this->id = 0;
    this->x = 0;
    this->y = 0;
}

tspCity::tspCity(const tspCity& orig) {
    this->id = orig.id;
    this->x = orig.x;
    this->y = orig.y;
}

tspCity::~tspCity() {
    // empty for now
}

void tspCity::setId(int newId){
    this->id = newId;
}

void tspCity::setX(int newX){
    this->x = newX;
}

void tspCity::setY(int newY){
    this->y = newY;
}

int tspCity::getId(){
    return this->id;
}

int tspCity::getX(){
    return this->x;
}

int tspCity::getY(){
    return this->y;
}

int tspCity::distanceTo(tspCity* dest){
    int xDist = abs(this->getX() - dest->getX());
    int yDist = abs(this->getY() - dest->getY());
    float sqrtVal;
    int result;
    
    
    sqrtVal = sqrt((xDist * xDist) + (yDist * yDist));
    result = round(sqrtVal);
    printf("sqrt(%d^2 + %d^2) = %f\n",xDist, yDist, sqrtVal);
    
    return result;
}

std::string tspCity::cityInfo(){
    std::string info;
    
    info = std::to_string(this->id);
    info = info + " | ";
    info = info + std::to_string(this->x);
    info = info + ",";
    info = info + std::to_string(this->y);
    info = info + '\n';
    
    return info;
}
