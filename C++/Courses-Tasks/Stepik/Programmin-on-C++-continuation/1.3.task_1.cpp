#include <iostream>
#include <typeinfo>

int main(){
	std::cout << typeid(int).name() == typeid(float).name();
}