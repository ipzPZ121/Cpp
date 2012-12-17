//Найти количество различных элементов массива.

#include <iostream>

int main(){
	int vals[] = {1, 2, 2, 3, 3, 4, 5, 5};
	int difValues=0;

	for(int i=0; i<8; i++) {
		int count=0;

		for(int j=0; j<8; j++){
			if(vals[i]==vals[j]) {
				count++;
			}
		}

		if(count<=1) {
			difValues++;
		}
	}
	std::cout<<difValues;

	char c;
	std::cin>>c;

	return 0;
}
