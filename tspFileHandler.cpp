/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "tspFileHandler.hpp"



void loadInput(string* filename, vector<tspCity> *cities){
    //Attempt to open input file
    std::ifstream inputFile;
    string readValue;
    inputFile.open(*filename);
    int ival;
    tspCity tempCity;
    
    if (inputFile)
    {
        //Read each value from the data file
        ival = 0;
        while (inputFile >> readValue) {
            if (ival == 0){
//                //DEBUG_MODE: Print City Summary Line, city id
//                if (DEBUG)
//                    cout << readValue << " | ";
                
                tempCity.setId(std::stoi(readValue));
                ival++;
            } else if (ival == 1) {
//                //DEBUG_MODE: Print City Summary Line, x value
//                if (DEBUG)
//                    cout << "(" << readValue << ",";
                
                tempCity.setX(std::stoi(readValue));
                ival++;
            } else {
//               //DEBUG_MODE: Print City Summary Line, y value
//               if (DEBUG)
//                   cout << readValue << ")\n";
                
                tempCity.setY(std::stoi(readValue));
                
                //DEBUG_MODE: Print City Summary Line
                if (DEBUG)
                    cout << tempCity.cityInfo();
                
                ival = 0;
                cities->push_back(tempCity);
            }
        }
        
        //Close open file object
        inputFile.close();
    }
    
}

void printOutput(string* filename, int tourValue, Tour finalTour){
    
    //Attempt to create&open output file
    std::ofstream outputFile;
    outputFile.open("./" + *filename);
	
    //for the tourValue
    // in DEBUG_MODE: print the tour value as a line to stdout
    if (DEBUG)
        cout << tourValue << "!\n";
    //print the tour value as the 1st line in the output file
    outputFile << tourValue << "\n";
    
    
	//for each element of the tour
    for (int i = 0; i < (int) finalTour.getTourSize(); i++) {
        //in DEBUG_MODE: print each value as a line to stdout
        if (DEBUG)
            cout << finalTour.getCity(i).getId() << "\n";
        //print each value as a line in output file
        outputFile << finalTour.getCity(i).getId() << "\n";
    }
    
    outputFile.close();
    
}


