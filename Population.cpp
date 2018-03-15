//
//  Population.cpp
//  GA
//
//  Created by Vinh on 3/10/18.
//  
//

#include "Population.hpp"


Population::Population() {
    this->tourQty = 0;
    this->tours = nullptr;
}
    
// Construct a population, where popSize is the number of tours
Population::Population(int popSize) {
    this->tourQty = popSize;
    this->tours = new Tour[popSize];
}

// Construct a population, where popSize is the number of tours
Population::Population(int popSize, vector<tspCity>* Cities) {
    this->tourQty = popSize;
    this->tours = new Tour[popSize];
    // Loop and create random order sets of tours
    // Create qty.popSize of randomized tours
    for (int i = 0; i < popSize; i++) {
        this->tours[i].createInitialTour(Cities);
        this->tours[i].generateIndividual();
//        Tour newTour;
//        newTour.generateIndividual();
//        saveTour(i, newTour);
    }

}


Population::~Population() {
    // empty for now
}
    
// Saves a tour to the population
void Population::saveTour(int index, Tour tour) {
    this->tours[index] = tour;
    
//	this->cityArray = nullptr;
//	this->cityIndex = 0;
//	this->fitness = 0;
//	this->distance = 0;
}
    
// Gets a tour from population
Tour Population::getTour(int index) {
    return tours[index];
}
    
// Gets the best tour in the population
Tour Population::getFittest() {
    //set initial tour as the fittest
    Tour* best = &tours[0];
    int popSize = populationSize();
    // Loop through individuals to find fittest
    for (int i = 1; i < popSize; i++) {
        //compare each initial tour fitness with all the other tour's fitness
        if (best->getFitness() < this->tours[i].getFitness()) {
            //if new tour has higher fitness, set new tour as fittest
            best = &this->tours[i];
//            best = getTour(i);
        }
    }
    return *best;
}
    
// Gets population size
int Population::populationSize() {
    return this->tourQty;
}

