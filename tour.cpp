/*
* File:   tour.cpp
* Author: orcutts
*/

#include <vector>
#include <algorithm>
#include "tour.hpp"
#include "GA.hpp"
using std::vector;

// Constructor
Tour::Tour(vector<tspCity> cities){
	createIndividual(cities);
}

// Default constructor
Tour::Tour(){
	size = 0;
}

// Default Destructor
Tour::~Tour(){
    //Empty for now
}

// Generates a random tour of all cities
void Tour::createIndividual(vector<tspCity> cities){
	cityList = cities;								// Copies vector of cities
	random_shuffle(cityList.begin(), cityList.end());	// Shuffles tour vector
}

// Shuffle Me
void Tour::shuffleMe(){
    random_shuffle(this->cityList.begin(), this->cityList.end());
}

//Returns a tspCity, for city at given tour position
tspCity Tour::getCity(int tourPosition){
	return cityList.at(tourPosition);
}

// Pushes city onto tour
void Tour::setCity(tspCity thisCity){
	cityList.push_back(thisCity);
	size++;
}

// Sets city at a given tour position
void Tour::setCity(int tourPosition, tspCity thisCity){
	cityList.at(tourPosition) = thisCity;
}

// Gets distance between two cities
double Tour::distanceTwoCities(tspCity fromCity, tspCity destinationCity){
	int xDist = abs(fromCity.getX() - destinationCity.getX());
	int yDist = abs(fromCity.getY() - destinationCity.getY());
	return round(sqrt((xDist * xDist) + (yDist * yDist)));
}

//Returns a double, for tour distance
double Tour::getDistance(){
	if (distance == 0)
	{
		int size = cityList.size();
		for (int i = 0; i < size - 1; i++)
		{
			distance += distanceTwoCities(cityList.at(i), cityList.at(i + 1));
            //distance += cityList.at(i).distanceTo(cityList.at(i+1));
		}
		distance += distanceTwoCities(cityList.at(0), cityList.at(size - 1));
        //distance += cityList.at(0).distanceTo(cityList.at(size - 1));
	}
	return distance;
}

//Returns a double, for tour fitness
double Tour::getFitness(){
	return 1 / getDistance();
}

// Returns an integer, for size of tour
int Tour::getTourSize(){
	return cityList.size();
}
