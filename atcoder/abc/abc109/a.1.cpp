#include <iostream>

int main(){
    int a, b;
    std::cin >> a >> b;
    if(a%2 == 1 && b%2 == 1) std::cout << "Yes\n";
    else std::cout << "No\n";
    return 0;
}