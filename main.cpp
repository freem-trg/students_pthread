#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib>
#include <unistd.h>

using namespace std;

condition_variable cv;
mutex cv_m;
int i = 0;
long int sec[12];

const short COUNT = 12;

void waits(short id)
{
    unique_lock<mutex> lk(cv_m);
    cv.wait(lk, [](){return i < 4;});
    i++;
    cv_m.unlock();


    cout << id << " Wait for " << sec[id] << endl;
    std::this_thread::sleep_for( std::chrono::seconds(sec[id]) );
//    sleep( sec );
    cv_m.lock();
    i--;
    cv_m.unlock();
    cv.notify_all();
}

int main()
{
    srand((unsigned)time(NULL));
    vector<thread> th;
    for ( short j = 0; j < COUNT; j++ ){
        th.push_back( thread( waits, j ) );
        long int secs = rand()%5 + 1;
        sec[j] =secs;
    }
    for ( short j = 0; j < COUNT; j++){
        th[j].join();
    }
    th.clear();
}

