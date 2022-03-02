#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Profesor{
	
	int codigo;
	string nombre; //Esto puede ser char o tiene que ser string?
	int valorHora;
};


int menu(); //Para mostrar y escanear las opciones del menu  

void lectura();

int main(){
	
	int op;
	
	Profesor *archivo = new Profesor;
	
	op=menu();
	
	switch(op){
		
		case 1:
			
			break;
			
		case 2:
			
			break;
			
		case 3:
			
			break;
				
	}		
}


int menu(){
	
	int x;
	
	cout<<"***********************************************************************************************"<<endl;
	cout<<"Bienvenido al menu"<<endl<<endl;
	cout<<"Ingrese 1 para realizar la lectura de datos iniciales desde un archivo de tipo texto profesor"<<endl<<endl;
	cout<<"Ingrese 2 para calcular total a pagar semanal e imprimir los datos por cada profesor y el total de la suma de todos los sueldos pagados al final"<<endl<<endl;
	cout<<"Ingrese 3 para generar el archivo ordenado descendentemente e imprimirlo"<<endl<<endl;
	
	return x;
}

void lectura(){
	
	ifstream entradaArchivo;
	
	
	
}


