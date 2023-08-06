#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono ;

//void run(int count){
//    while (count-- > 0) {
//        cout << "cppNuts" << endl;
//    }
//    std::this_thread::sleep_for(chrono::seconds(3)) ;
//}
//
//int main(){
//
//    std::thread t1(run,10) ;
//    cout << "main()" << endl;
//    t1.join() ;
//
//    if(t1.joinable())
//       t1.join() ;
//
//    cout << "main() after" << endl;
//    return 0 ;
//}
void run(int count){
    while (count-- > 0) {
        cout << count <<  " cppNuts" << endl;
    }
    std::this_thread::sleep_for(chrono::seconds(3)) ;
    cout << "thread finished" << endl;
}

int main(){

  std::thread t1(run,10) ;
    cout << "main()" << endl;
    t1.detach() ;

   //if(t1.joinable())
     // t1.detach() ;

    cout << "main() after" << endl;
    //std::this_thread::sleep_for(chrono::seconds(3)) ;

    return 0 ;
}
