#include<iostream>
#include<cstdlib>

int contar (int** campo, int i, int j, int x, int y){
	int cont = 0;
	if (i!=0 && campo[i-1][j] == 9){cont++;}
	if (i!=0 && j!=0 && campo[i-1][j-1] == 9){cont++;}
	if (j!=0 && campo[i][j-1] == 9){cont++;}
	if (i!=x-1 && j!=0 && campo[i+1][j-1] == 9){cont++;}
	if (i!=x-1 && campo[i+1][j] == 9){cont++;}
	if (i!=x-1 && j!=y-1 && campo[i+1][j+1] == 9){cont++;}
	if (j!=y-1 && campo[i][j+1] == 9){cont++;}
	if (i!=0 && j!=y-1 && campo[i-1][j+1] == 9){cont++;}

	return cont;
}

void imprimir (int x, int y, int** mat, int a){
	int i, j;

	if (a!=1){std::cout << "\n";}

	std::cout << "Field #" << a << ":\n";
	for (i = 0; i < x; i++){
		for (j = 0; j < y; j++){
			if(mat[i][j]!=9){std::cout << mat[i][j];}
			else{std::cout << "*";}
		}
		std::cout << "\n";
	}
}

int main (){
	int x, y, i, j, a;
	char mina;
	int** mat;
	while (std::cin >> x){
		std::cin >> y;
		a++;
		if (x==0 || y==0){
			continue;
		}

		mat = (int**)std::malloc(x * sizeof(int*));
		for (i = 0; i < x; i++) {
			mat[i] = (int*)std::malloc(y * sizeof(int));
		}
		
		// Creamos la matriz con las minas
		for (i = 0; i < x; i++){
			for (j = 0; j < y; j++){
				std::cin >> mina;
				if (mina == '*'){
					mat[i][j] = 9;
				} else {
					mat[i][j] = 0;
				}
			}
		}

		// Modificamos la matriz
		for (i = 0; i < x; i++){
			for (j = 0; j < y; j++){
				if(mat[i][j] == 0){
				mat[i][j] = contar(mat, i, j, x, y);
				}
			}
		}
		imprimir(x, y, mat, a);
	}
}
