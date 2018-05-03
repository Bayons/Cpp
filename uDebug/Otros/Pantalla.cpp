#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cstdlib>

// Pantalla de Cristal Liquido
// IDs en PC/UVa: 110104/706

// Fallos:	recoge ceros, pero problemas con las longitudes de cadenas


// Transforma un numero en un vector de cifras
std::vector<int> split(std::string nums){
	std::vector<int> v;
	int a;

	for (a = 0; a < nums.size(); a++){
		v.push_back(nums.at(a) - '0');
	}

	return v;
}



int valorOf (std::string nums){
	int num = 0, a;
	for (a = 0; a < nums.size(); a++){
		if (nums.at(a)<48 || nums.at(a)>58){
			return -1;
		}
		num *= 10;
		num += nums.at(a) - '0';
	}

	return num;
}



void imprime(bool formato[10][2][4], std::vector<int> v, int altura){
	int a, b, c, cont;
	bool col; // True si va a trabajar con columnas
	for (a = 0; a < 5; a++){
		col = (a%2 != 0);

		if (col){
			for(c = 0; c < altura; c++){
				for (b = 0; b < v.size(); b++){
					if(formato[v.at(b)][1][a-1]) std::cout << "|";
					else std::cout << " ";
					for (cont = 0; cont < altura; cont++) std::cout << " ";
					if(formato[v.at(b)][1][a]) std::cout << "|";
					else std::cout << " ";
					std::cout << " ";
				}
				if (c < altura-1) std::cout << std::endl;
			}
		}else{
			for(b = 0; b < v.size(); b++){
				std::cout << " ";
				for(c = 0; c < altura; c++){
					if (a == 0) cont = 0;
					if (a == 2) cont = 1;
					if (a == 4) cont = 2;
					if(formato[v.at(b)][0][cont]) std::cout << "-";
					else std::cout << " ";
				}
				std::cout << "  ";
			}
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;
}



int main(){
	bool fin(false);
	char* nums;
	int altura, num;	//   Este es de relleno
	std::vector<int> v;	//	|
	bool formato[10][2][4] =//	v
	       {{{true,  false, true,  false},{true,  true, true,  true}},//0
		{{false, false, false, false},{false, true, false, true}},//1
		{{true,  true,  true,  false},{false, true, true,  false}},//2
		{{true,  true,  true,  false},{false, true, false, true}},//3
		{{false, true,  false, false},{true,  true, false, true}},//4
		{{true,  true,  true,  false},{true,  false,false, true}},//5
		{{true,  true,  true,  false},{true,  false,true,  true}},//6
		{{true,  false, false, false},{false, true, false, true}},//7
		{{true,  true,  true,  false},{true,  true, true,  true}},//8
		{{true,  true,  true,  false},{true,  true, false, true}}};//9

	do{
		nums = (char*)std::malloc(8 * sizeof(char));
		std::cin >> altura;
		std::cin >> nums;
		
		std::string str(nums);
		num = valorOf(str);

		// Si el valor es correcto procede
		if(altura>0 && altura<=10 && num>=0 && num<=99999999){
			v = split(nums);
			imprime(formato, v, altura);

		// Si el valor es 0 0 acaba
		}else if(altura==0 && num==0 && str.size()==1){
			fin = true;

		}

	}while(!fin);

	return 0;
}
