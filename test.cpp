#include <iostream>

int main(){
    int num = 456;
    int temp = 0;
    int x = 1000;
    while(x != 0){
        temp = num / x * x;
        num %= x;
        x /= 10;
        std::cout << temp << std::endl;
    }


}