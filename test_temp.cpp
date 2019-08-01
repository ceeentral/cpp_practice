//

//

#include <iostream>
#include <time.h>
#include <functional>



void printN_travere( int N )
{
    for (int i = 0; i <N; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void printN_iteration(int N)
{
    if(N)
    {
        printN_iteration(N-1);
        std::cout << N << std::endl;
    }
}



double clock_cal(int x, const std::function<void(int)> &f)  //use std::function to pass function
{                                                           //actually i can use pointer to pass function
    clock_t start, stop;
    double duration;
    start = clock();
    f(x);
    stop = clock();
    duration = ((double)(stop - start))/CLK_TCK;
    return duration;

}

int main()
{
    //use clock function to calculate the time of the fucntion.

    auto duration = clock_cal(10000, printN_iteration);
    auto clk = CLK_TCK;
    std::cout << clk << std::endl; // 1 sec record 100 times
    std::cout << duration << std::endl; //times function used
    return 0;
}