//
//  Population.hpp
//
//  Created by Vinh on 3/10/18.
//

#ifndef Population_hpp
#define Population_hpp


#include "tour.hpp"

class Population {
private:
    int tourQty;
    
public:
    
    Population();
    
    virtual ~Population();
    
    // Construct a population
    Population(int popSize);
    
    // Construct a population
    Population(int popSize, vector<tspCity>* );
    
    // Holds population of tours
    Tour* tours;
    
    // Saves a tour
    void saveTour(int index, Tour tour);
    
    // Gets a tour from population
    Tour getTour(int index);
    
    // Gets the best tour in the population
    Tour getFittest();
    
    // Gets population size
    int populationSize();
};

#endif /* Population_hpp */
