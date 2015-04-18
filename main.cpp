//
//  main.cpp
//  AlgoIIWeek3Problem2
//
//  Created by Chris Welhoelter on 4/14/15.
//  Copyright (c) 2015 Chris Welhoelter. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include "Knapsack.h"

int main(int argc, const char * argv[]) {
    
    
    std::string fileName;
    
    std::cout << "enter the file name: ";
    std::cin >>fileName;
    std::cout << std::endl;
    
    std::fstream fsIn;
    
    fsIn.open(fileName);
    if (!fsIn.is_open()){
        std::cout << "could not open " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }
    
    int knapsackSize;
    int itemCount;
    
    fsIn >> knapsackSize;
    fsIn >> itemCount;
    
    std::vector<std::pair<int, int>> items; // <value, weight>
    std::pair<int, int> nullPair;
    items.push_back(nullPair);
    
    for (size_t i = 1; i <= itemCount; i++){
        
        int value;
        int weight;
        
        fsIn >> value;
        fsIn >> weight;
        
        std::pair<int, int> item;
        item.first = value;
        item.second = weight;
        
        items.push_back(item);
    }
    
    std::cout << "itemCount: " << itemCount << std::endl;
    std::cout << "knapsackSize: " << knapsackSize << std::endl;

    std::cout << std::endl;
    
    Knapsack knapsack(itemCount, items);
    int maxValue = knapsack.valueAt(itemCount, knapsackSize);
    std::cout << "max value: " << maxValue << std::endl;
    

    
    return 0;
}
