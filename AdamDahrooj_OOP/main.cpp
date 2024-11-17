#include <iostream>

void square(int x, int& result) 
{
    result = x * x;
}

int main() 
{
    int y = 0;
    square(3, y);
    // Now, y will contain the value 9
    return 0;
}