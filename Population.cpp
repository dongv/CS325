//
//  Population.cpp
//  GA
//
//  Created by Vinh on 3/10/18.
//  
//

#include "Population.hpp"

    
// Construct a population, where popSize is the number of tours
Population::Population(int popSize) {
    this->tourQty = popSize;
    tours = new Tour[popSize];
}

// Construct a population, where popSize is the number of tours
Population::Population(int popSize, vector<tspCity> &Cities) {
    this->tourQty = popSize;
    tours = new Tour[popSize];
    // Loop and create random order sets of tours
    for (int i = 0; i < popSize; i++) {
        Tour newTour = new Tour(Cities);
        newTour.generateIndividual();
        saveTour(i, newTour);
    }

}


Population::~Population() {
    // empty for now
}
    
// Saves a tour to the population
void Population::saveTour(int index, Tour tour) {
    tours[index] = tour;
}
    
// Gets a tour from population
Tour Population::getTour(int index) {
    return tours[index];
}
    
// Gets the best tour in the population
Tour Population::getFittest() {
    //set initial tour as the fittest
    Tour best = tours[0];
    int popSize = populationSize();
    // Loop through individuals to find fittest
    for (int i = 1; i < popSize; i++) {
        //compare each initial tour fitness with all the other tour's fitness
        if (best.getFitness() <= getTour(i).getFitness()) {
            //if new tour has higher fitness, set new tour as fittest
            best = getTour(i);
        }
    }
    return best;
}
    
// Gets population size
int Population::populationSize() {
    return this->tourQty;
}

