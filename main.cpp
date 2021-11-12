#include <iostream>
#include <string>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int menu();
int** matrizBinaria();
void printMatriz(int**);
void freeMatrizRef(int**&);
void printArray(int*);
void freeArrayRef(int*&);
int* recursivo(int,int*);
string ejercicio3(string);
int sumaBinaria(int**);
int** matrizMax(int**);
int** tansCol(int,int**);
int** tansFila(int,int**);

int main(int argc, char** argv) {
	int opcionMenu=0;
	while(opcionMenu != 4){
		switch(opcionMenu = menu()){
			case 1:{
				int** matriz = matrizBinaria();
				printMatriz(matriz);
				cout<<sumaBinaria(matriz)<<endl;
				freeMatrizRef(matriz);
				break;
			}
			
			case 2:{
				int* arreglo = new int[20];
				for(int i =0; i<20; i++){
					arreglo[i]= rand() % 100;
				}
				printArray(recursivo(0,arreglo));
				freeArrayRef(arreglo);
				break;
			}
			
			case 3:{
				string cadena=" ";
				cout<<"Ingrese cadena: ";
				cin>>cadena;
				cout<<"La longitud maxima es de: "<<ejercicio3(cadena).length()-2<<". "<<ejercicio3(cadena)<<endl;
				break;
			}
			
		}
	}
	
	return 0;
}

int menu(){
	int opcion = 0;
	cout<< "Menu" << endl
	<< "1) Ejercicio 1" << endl
	<< "2) Ejercicio 2" << endl
	<< "3) Ejercicio 3" << endl
	<< "4) Salir" << endl
	<< "Ingrese su opcion: ";
	cin >> opcion;
	return opcion;
}

int** matrizBinaria(){
	int** matriz = new int*[4];
	for(int i=0; i<4; i++){
		matriz[i]=new int[5];
	}
	for(int i =0; i<4; i++){
		for(int j = 0; j<5; j++){
			matriz[i][j]= rand() % 2;
		}
	}
	
	return matriz;
}

int sumaBinaria(int** matriz){
	int suma=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<5;j++){
			if(matriz[i][4-j]==1){
				suma+=pow(2,j);
			}
		}
	}
	return suma;
}

int** matrizMax(int** matriz){
		for(int i=0;i<4;i++){
			int ceros=0;
			for(int j=0;j<5;j++){
				if(i==0  && matriz[i][j]==0){
					matriz=transFila(j ,matriz);
				}
				else if(matriz[i][j]==0){
					ceros++;
				}
			}
			if(i==1 && ceros>1){
				matriz=tansCol(i, matriz);
			}else if(i==2 && ceros>2){
				matriz=transCol(i,matriz);
			}else if(i==3 && ceros>3){
				matriz=transCol(i,matriz);
			}
		}
	
	for(int i=0;i<5;i++){
		int ceros=0;
		for(int j=0;j<4;j++){
			if(ceros)
		}
	}//filas
	

}

int** transCol(int col, int** matriz){
	for(int i=0; i<5; i++){
		if(matriz[i][col]==0){
			matriz[i][col]=1;
		}else{
			matriz[i][col]=0;
		}
	}
	return matriz;
}

int** transFila(int fila, int** matriz){
	for(int i=0; i<4; i++){
		if(matriz[fila][i]==0){
			matriz[fila][i]=1;
		}else{
			matriz[fila][i]=0;
		}
	}
	return matriz;
}

int* recursivo(int posicion, int* arreglo){
	printArray(arreglo);
	if(posicion == 19){
		return arreglo;
	}else{
		int menor = arreglo[posicion], mayor=0, posicion2=posicion, original=arreglo[posicion];
		for(int i=posicion; i<20; i++){
			if(arreglo[i]<menor){
				mayor=menor;
				menor=arreglo[i];				
				posicion2=i;
			}
		}
		if(menor < mayor){
			arreglo[posicion]=menor;
			arreglo[posicion2]= original;
		}
		return recursivo(posicion+1,arreglo);
	}
}

void freeMatrizRef(int**& matriz) {
	if (matriz != NULL) {
 		delete[] matriz;
 		matriz = NULL;
	}
}

void printMatriz(int** matriz){
	for(int i=0; i <4; i++){
		for(int j =0; j<5; j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
}

void freeArrayRef(int*& array){
	if(array != NULL){
		delete[] array;
		array = NULL;
	}
}

void printArray(int* array){
	for(int i=0; i<20; i++){
		cout<<array[i]<<" ";
	}
	cout<<endl;
}

string ejercicio3(string cadena){
	int mayorImpar=0;
	char charImpar = ' ';
	string palindrome="", mitad=" ";
	for(int i=0; i<cadena.length(); i++){
		int cantidad=0;
		for(int j=0; j<cadena.length(); j++){
			if(cadena.at(i)==cadena.at(j)){
				cantidad++;
			}
		}
		if(cantidad%2==0){
			int aux=0;
			for(int x=0;x<mitad.length();x++){
					if(mitad.at(x)==cadena.at(i)){
						aux++;
					}
				}
				if(aux==0){
					for(int k=0; k<cantidad/2; k++){
						mitad+=cadena.at(i);
					}
				}
		}else{
			mayorImpar=cantidad;
			charImpar=cadena.at(i);
		}
		
		
	}
	palindrome+=mitad;
	for(int k=0; k<mayorImpar;k++){
		palindrome+=charImpar;
	}
	for(int l=mitad.length()-1; l>=0;l--){
		palindrome+=mitad.at(l);
	}
	return palindrome;
}

