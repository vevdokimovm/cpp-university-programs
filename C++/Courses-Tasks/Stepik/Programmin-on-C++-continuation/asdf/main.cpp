#include <iostream>
void is_lucky(std::string n){
	std::cout << (n[0] + n[1] + n[2] == n[3] + n[4] + n[5] ? "YES" : "NO");
}

int main(){
	std::string n = "";
	std::cin >> n;
	is_lucky(n);
}
