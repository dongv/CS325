/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tspCity.hpp
 * Author: Sam
 *
 * Created on March 10, 2018, 10:59 PM
 */

#ifndef TSPCITY_HPP
#define TSPCITY_HPP

#include <string>
#include <math.h>

class tspCity {
    
private:
    int id;
    int x;
    int y;
    
public:
    tspCity();
    tspCity(const tspCity& orig);
    virtual ~tspCity();
    void setId(int newId);
    void setX(int newX);
    void setY(int newY);
    int getId();
    int getX();
    int getY();
    int distanceTo(tspCity dest);
    std::string cityInfo();
    
};

#endif /* TSPCITY_HPP */

