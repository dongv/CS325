/*
* File:   population.hpp
* Author: orcutts
*/

#include "tour.hpp"
#include "population.hpp"
#include "tspCity.hpp"
#include <vector>
#include <algorithm>
using std::vector;

bool compareTour (Tour left, Tour right){
    return (left.getDistance() < right.getDistance() );
}


// Creates a new population
Population::Population(int popSize, vector<tspCity>* Cities){
    
    int qtyCities = (int) Cities->size();
    
    for(int c = 0; c < qtyCities; c++){
        cl.addCity(Cities->at(c));
    }
    
    for (int i = 0; i < popSize; i++) {
        this->tours.push_back(cl.getCityList());
	}
    
    
	size = tours.size();
}

// Default constructor
Population::Population(){
	size = 0;
}

//Destructor
Population::~Population() {

}

//Saves a tour
void Population::saveTour(Tour thisTour){
	tours.push_back(thisTour);
	size++;
}

// Adds a tour to a specific index
/*** CLEANUP void Population::addTour(Tour t, int i){
	tours.at(i) = t;
}*/

// Gets tour at i
Tour Population::getTour(int i){
	return tours.at(i);
}

//Returns the shortest tour
Tour Population::getFittest(){
	Tour fittest = tours.at(0);
	for (int i = 1; i < size; i++)
	{
		if (fittest.getFitness() < tours.at(i).getFitness())
		{
			fittest = tours.at(i);
		}
	}
	return fittest;
}


void Population::sortMe(){
    sort(this->tours.begin(),this->tours.end(),compareTour);
}


//Returns an integer for the population size
int Population::populationSize(){
	return size;
}
