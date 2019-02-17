//
//  main.cpp
//  operatingSystemsProject
//
//  Created by Olivia Hess on 11/29/18.
//  Copyright © 2018 Olivia Hess. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
int main(int argc, const char * argv[]) {

    int sequential[100000]; // this array simulates sequential memory locations
    int random[100000]; //this array simulates randomly generated memory locations
    int holdIndices[10000]; //this array holds the randomly generated index values
    
    
    clock_t tread;
    clock_t twrite;
    
    /* Simulate writing to 10000 sequential memory locations */
    twrite = clock();
    for(int i = 0; i < 10000; i++) {
        sequential[i] = 0;
    }
    twrite = clock() - twrite;
    
    /* Simulate reading from 10000 sequential memory locations */
    tread = clock();
    for(int i = 0; i < 10000; i++) {
        sequential[i] = 0;
    }
    tread = clock() - tread;
    
    float secondsRead = ((float)tread)/CLOCKS_PER_SEC;
    float secondsWrite = ((float)twrite)/CLOCKS_PER_SEC;

    
    cout << "Sequentially writing to 10000 locations, It took " << twrite << " clock ticks and " << secondsWrite <<" seconds \n";
    cout << "Sequentially reading from 10000 locations, It took " << tread << " clock ticks and " << secondsRead <<" seconds \n";
    
    int randomIndex; //create a random index
    /* Create 10,000 random indices from 0-99,9999*/
    for(int i = 0; i< 10000; i++) {
        randomIndex = rand() % 100000;
        holdIndices[i] = randomIndex;
    }
    /* Simulate writing to 10000 random memory locations */
    twrite = clock();
    for(int i = 0; i<10000; i++){
        random[holdIndices[i]] = 0;
    }
    twrite = clock() - twrite;
    secondsWrite = ((float)twrite)/CLOCKS_PER_SEC;
    
    /* Simulate reading from 10000 sequential memory locations */
    tread = clock();
    for(int i = 0; i<10000; i++){
        random[holdIndices[i]];
    }
    tread = clock() - tread;
    secondsRead = ((float)tread)/CLOCKS_PER_SEC;
    
    
     cout << "Randomly writing to 10000 locations, It took " << twrite << " clock ticks and " << secondsWrite <<" seconds \n";
    cout << "Randomly reading from 10000 locations, It took " << tread << " clock ticks and " << secondsRead <<" seconds \n";

    return 0;
}
