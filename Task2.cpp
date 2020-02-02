#include <random>
#include <stdlib.h>
#include <iostream>

int comp(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    int s = rand() % 10 + 5;
    int A[s];
    int s1 = rand() % 10 + 5;
    int B[s1];
    int C[s+s1], cnt = 0;
   
    for(int i = 0; i < s; ++i)
    {
        A[i] = rand() % 100;
        C[cnt] = A[i];
        cnt++;
        std::cout << A[i] << " ";
    }
    
    std::cout << std::endl;
    
    for(int i = 0; i < s1; ++i)
    {
        B[i] = rand() % 100;
        C[cnt] = B[i];
        cnt++;
        std::cout << B[i] << " ";
    }
    
    std::cout << std::endl;
    
    qsort(C, cnt, sizeof(int), comp);
    int g = 0;
    for(int i = 0; i < cnt; ++i)
    {
        g += C[i];
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Среднее геометрическое = " << g/cnt << std::endl;
    
    return 0;
}
