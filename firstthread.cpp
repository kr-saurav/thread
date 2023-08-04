// Your First C++ Program

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono ;

typedef unsigned long long ull;
ull  oddsum = 0, evensum = 0  ;

void findeven(ull start , ull end){
    for (ull i = start; i <= end; i++) {
        if((i&1)==0)
            evensum += i ;
    }
}

void findodd(ull start , ull end){
    for (ull i = start; i <= end; i++) {
        if((i&1)==1)
            oddsum += i ;
    }
}

int main() {
    
    ull start = 0 , end = 1900000000 ;
    
    auto starttime = high_resolution_clock::now() ;
    
    std::thread t1(findeven , start , end) ;
    std::thread t2(findodd  , start , end) ;
    
    t1.join() ;
    t2.join() ;
    
    //findodd(start , end) ;
    //findeven(start, end) ;
    
    auto stoptime = high_resolution_clock::now() ;
    auto duration = duration_cast<seconds>(stoptime - starttime) ;
    
    cout << "oddsum: " << oddsum << endl ;
    cout << "evensum: "<< evensum << endl;
    
    cout << duration.count() << endl;
    
    return 0;
}

