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

void imprimir (int x, int y, int** mat){
	int i, j;

	for (i = 0; i < x; i++){
		for (j = 0; j < y; j++){
			if(mat[i][j]!=9){std::cout << mat[i][j] << " ";}
			else{std::cout << "*" << " ";}
		}
		std::cout << "\n";
	}
	std::cout << "\n\n";
}

int main (){
	int x, y, i, j, a;
	char mina;
	int** mat;
	while (std::cin >> x){
		std::cin >> y;
		if (x==0 || y==0){
			continue;
		}

		mat = (int**)std::malloc(x * sizeof(int*));
		for (i = 0; i < x; i++) {
			mat[i] = (int*)std::malloc(y * sizeof(int));
		}
		
		std::cout << "\n->" << x << " " << y << "\n";
		for (i = 0; i < (y*2 -1); i++){std::cout << "_";}
		std::cout << "\n";
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

		imprimir(x, y, mat);

		// Modificamos la matriz
		for (i = 0; i < x; i++){
			for (j = 0; j < y; j++){
				if(mat[i][j] == 0){
					a = contar(mat, i, j, x, y);
					mat[i][j] = a;
				}
			}
		}
		imprimir(x, y, mat);
	}
}
