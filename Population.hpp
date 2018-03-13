//
//  Population.hpp
//
//  Created by Vinh on 3/10/18.
//

#ifndef Population_hpp
#define Population_hpp

class Population {
public:
    // Holds population of tours
    Tour[] tours;
    
    // Construct a population
    Population(int popSize);
    
    // Saves a tour
    void saveTour(int index, Tour tour);
    
    // Gets a tour from population
    Tour getTour(int index);
    
    // Gets the best tour in the population
    Tour getFittest();
    
    // Gets population size
    int populationSize();

#endif /* Population_hpp */
