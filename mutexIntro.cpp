// Your First C++ Program

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>


using namespace std;
int myAmount = 0 ;
std::mutex m;

void addmoney(){
    m.lock() ;
    ++myAmount ; // critical section
    m.unlock();
}


int main() {
        
    std::thread t1(addmoney) ;
    std::thread t2(addmoney) ;
    
    t1.join() ;
    t2.join() ;
    
    cout << myAmount << endl;
    return 0;
}


