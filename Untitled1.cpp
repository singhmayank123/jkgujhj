#include<iostream>


int main()
{
    int i = 10;
    
    i = ++i + i++ + ++i + i++ + i;
    std::cout <<i;

    return 0;
}
