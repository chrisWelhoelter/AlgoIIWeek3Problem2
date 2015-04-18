//
//  Knapsack.cpp
//  AlgoIIWeek3Problem2
//
//  Created by Chris Welhoelter on 4/14/15.
//  Copyright (c) 2015 Chris Welhoelter. All rights reserved.
//

#include "Knapsack.h"

Knapsack::Knapsack(int itemCount, std::vector<std::pair<int, int>> items){
    this->knapsack.resize(itemCount + 1);  // for base 1 indexing
    this->items = items;
}

int Knapsack::valueAt(int item, int residualWeight){
    
    // base case. we've run out of items
    if (item == 0){
        return 0;
    }
    
    // if value has already been computed, return it from the cache
    std::map<int,int>::iterator itemPointer = knapsack[item].find(residualWeight);
    if (itemPointer != knapsack[item].end()){
        return itemPointer->second;
    }
    
    // base case. the item cannot fit
    if (items[item].second > residualWeight){
        int edgeCaseValue = valueAt(item - 1, residualWeight);
        knapsack[item].insert(std::pair<int, int>(residualWeight, edgeCaseValue));
        return edgeCaseValue;
    }
    
    
    else {
        
        int case1Value = valueAt(item - 1, residualWeight);
        int case2Value = items[item].first + valueAt(item - 1, residualWeight - items[item].second);

        
        if (case1Value > case2Value){
            knapsack[item].insert(std::pair<int, int>(residualWeight, case1Value));
            return case1Value;
        }
        
        else {
            knapsack[item].insert(std::pair<int, int>(residualWeight, case2Value));
            return case2Value;
        }
    }
}