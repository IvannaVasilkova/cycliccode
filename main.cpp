//
//  main.cpp
//  CycleCode
//
//  Created by Ivanna Vasilkova on 25.11.2020.
//  Copyright © 2020 Ivanna Vasilkova. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <vector>
//std::vector<bool> generating = {1,0,0,1,1,0,0,0,1};
std::vector<bool> generating = {1,1,0,0,1};

using namespace::std;
vector <bool> allocateK (vector <bool> initial){
    size_t k_2 = generating.size() - 1;
    vector <bool> ini = initial;
    for ( int i = 0; i < k_2; i++)
        initial.push_back(0);
    return initial;
}


vector <bool> tocheck ( vector <bool> initial){
    
    initial = allocateK(initial);
    bool boolka = true;
    while ((initial.size() > generating.size() - 1) || (boolka != false)){
        transform(generating.begin(), generating.end(), initial.begin(), initial.begin(), std::bit_xor<>{});
        
        
        for (int i = 0; i < initial.size(); i++){
            if(initial[i] == 1){
                initial.erase(initial.begin(), initial.begin() + i);
                break; }
        }
        
        if  ( std::find(initial.begin(), initial.end(), 1) == initial.end() ){
            initial.erase(initial.begin(), initial.end());
            initial.push_back(0);
            break; }
        
        boolka = false;
    }
    return initial;
}


void encode(vector <bool> initial){
    
    vector <bool> result = tocheck(initial); //10
    vector <bool> allInitial = allocateK(initial);

    
    size_t sizeResult = result.size();
    
    for (int i = 0; i <  sizeResult; i++)
        allInitial.pop_back();
    
    allInitial.insert(allInitial.end(), result.begin(), result.end());
    for (auto i : allInitial)
        cout<<i;
    cout<<endl;
    
    cout << "Reminder is ";
       for (auto i : result)
           cout<<i;
    cout<<endl;
    
}


void decode(vector <bool> initial){
    vector <bool> result = tocheck(initial);
    if ( std::find(result.begin(), result.end(), 1) == result.end() ){
        cout << "Without mistakes." << endl;
        for (auto i: result)
            cout<< i;
        cout<< endl;
    }
    else {
        cout<< endl;
        cout<<  "The reminder is ";
        for (auto i: result)
            cout<< i;
        cout<< endl;
    }
}

int main(int argc, const char * argv[]) {
   // vector <bool> initial = {1,0,1,1,1,1,0,1,0,0,1,0,0,1,1,0};
   // vector <bool> initial1 = {1,0,1,1,1,1,0,1,0,0,1,0,0,1,1,0,0,0,0,0};
   //   encode(initial);
   //  decode(initial1);
    

    std::string initialSeq(argv[1]);


    std::vector<char> initial(initialSeq.begin(),initialSeq.end());
    std::vector<bool> boolka;
    for (auto i : initial)
        boolka.push_back(i-'0');


    if((std::string(argv[2]) == "-e") || (std::string(argv[2]) == "-E")){
        encode(boolka);
        return 0;
    }
    if((std::string(argv[2]) == "-d") || (std::string(argv[2]) == "-D")){
        decode(boolka);
        return 0;
    }
    
    return 0;
}
