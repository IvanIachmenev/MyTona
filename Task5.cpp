#include <cstdlib> 
#include <iostream> 
#include <string>
#include <vector>
 
int main()
{
    std::vector<int> x(3); 
    std::vector<int> y(3);
    for(int i = 0; i < 3; ++i)
    {
        std::cin >> x[i] >> y[i];
    }
    double t,dt,nt,xb,yb; 
    nt = 10;  
    dt = 1 / nt;
    t = -dt;
    for(int i = 0;i <= nt; ++i)
    {
        t += dt;
        xb = (1 - t) * (1 - t) * x[0] + 2 * (1 - t) * t * x[1] + t * t * x[2];
        yb = (1 - t) * (1 - t) * y[0] + 2 * (1 - t) * t * y[1] + t * t * y[2];
        std::cout << xb <<"  "<< yb << std::endl;
    }
    return 0;
}