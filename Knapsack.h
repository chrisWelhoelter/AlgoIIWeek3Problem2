//
//  Knapsack.h
//  AlgoIIWeek3Problem2
//
//  Created by Chris Welhoelter on 4/14/15.
//  Copyright (c) 2015 Chris Welhoelter. All rights reserved.
//

#ifndef __AlgoIIWeek3Problem2__Knapsack__
#define __AlgoIIWeek3Problem2__Knapsack__

#include <stdio.h>
#include <vector>
#include <map>

class Knapsack {
private:
    std::vector<std::pair<int, int>> items;
    std::vector<std::map<int, int>> knapsack;
public:
    Knapsack(int itemCount, std::vector<std::pair<int, int>> items);
    int valueAt(int item, int residualWeight);
    // std::vector<int> maxValueItems();
};



#endif /* defined(__AlgoIIWeek3Problem2__Knapsack__) */
