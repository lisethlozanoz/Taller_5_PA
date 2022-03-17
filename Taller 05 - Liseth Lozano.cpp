#include <iostream>
#include <fstream>
#include <string>

#include <string>
#include <iomanip>
#include <utility>
#include <iostream>
#include <stdexcept>

#include <cstdio>
#include <string>

using namespace std;



struct Profesor{
	int codigo;
	string nombre; 
	int valorHora;
	int horasDictadas;
	int sueldoSemanal;
};


int menu(); //Para mostrar y escanear las opciones del menu  

int lectura(Profesor profesores[50]);/*Para capturar e imprimir los registros 
del archivo*/

void sueldo(Profesor profesores[50], int num);

void ordenado(Profesor profesores[50], int num); //Para generar el archivo ordenado descendentemente e imprimirlo

int main(){
	
	int op, tamanoProfesor, tamanoClase, num;
	Profesor profesores[50];
	
	do{
	op=menu();
	
		switch(op){
		
		case 1:
			num = lectura(profesores);
			break;
			
		case 2:
			sueldo(profesores, num);
			break;
			
		case 3:
			ordenado(profesores, num);
			break;
			
		case 4:
			break;
	    }	
			}while(op!=4);
		
}


//////////////////////////////////////////////////////////////////////////////////////////////////
int menu(){
	
	int x;
	
	cout<<"***********************************************************************************************"<<endl;
	cout<<"Bienvenido al menu"<<endl<<endl;
	cout<<"Ingrese 1 para realizar la lectura de datos iniciales desde un archivo de tipo texto profesor"<<endl<<endl;
	cout<<"Ingrese 2 para calcular total a pagar semanal e imprimir los datos por cada profesor y el total de la suma de todos los sueldos pagados al final"<<endl<<endl;
	cout<<"Ingrese 3 para generar el archivo ordenado descendentemente e imprimirlo"<<endl<<endl;
	cout<<"Ingrese 4 para salir"<<endl<<endl;
	cin>>x;
	
	return x;
}

int horas(string h1, string h2 ){
	
	int hora1, hora2, horas1, horas2, minutos1, minutos2,difHoras, difMinutos, dif;
	string hh1="", hh2="", mm1="", mm2="";
	
	if (h1 == "0")
		return 0;
		
	if(h1 == "7")
		h1 = "0700";
		
	if(h1.length() == 3)
		h1 = "0" + h1;
	
	if(h2.length() == 3)
		h2 = "0" + h2;
	
	hh1 += h1[0];
	hh1 +=h1[1];
	hh2 += h2[0];
	hh2 +=h2[1];
	
	mm1 += h1[2];
	mm1 +=h1[3];
	mm2 += h2[2];
	mm2 += h2[3];
	
	sscanf(hh1.c_str(), "%d", &hora1);
	sscanf(hh2.c_str(), "%d", &hora2);
	
	sscanf(mm1.c_str(), "%d", &minutos1);
	sscanf(mm2.c_str(), "%d", &minutos2);
	
	minutos1 = hora1 * 60 + minutos1;
	minutos2 = hora2 * 60 + minutos2;
	
	dif = minutos2 - minutos1;
	
	dif /= 50;
	
	return dif;
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int lectura(Profesor profesores[50]){
	//Profesor profesor[100];
	ifstream entradaArchivo;
    entradaArchivo.open("profesores.txt");
    int i = 0;

    if (!entradaArchivo.is_open()){
        cout << "No se pudo abrir el archivo"<<endl;
    }

    else{
    	string buffer;
    	int bufferInt;
    	
    	while(!entradaArchivo.eof()){
    		
    		int acc=0, dif;
            string inicio, fin;
    		
            entradaArchivo >> profesores[i].codigo;
            entradaArchivo >> profesores[i].nombre;
            entradaArchivo >> buffer;
        
            while(buffer == "clase"){
            	entradaArchivo >> inicio;
            	entradaArchivo >> fin;
            	dif = horas(inicio, fin);
            	acc += dif;
            	
            	entradaArchivo >> buffer;
			}
			
			profesores[i].horasDictadas=acc;
			
			entradaArchivo >> profesores[i].valorHora;
			
            i++;
            acc=0;
        }
    }
    
    entradaArchivo.close();
    return i-1;
}

void sueldo(Profesor profesores[], int num){
	
	ofstream Esc;
	Esc.open("salida.txt", ios::app);
	int acc=0;
	
	for(int i=0; i<num; i++){
		profesores[i].sueldoSemanal = profesores[i].horasDictadas * profesores[i].valorHora;
		Esc<<profesores[i].codigo<<" ";
		Esc<<profesores[i].nombre<<" ";
		Esc<<profesores[i].sueldoSemanal<<" "<<endl;
		acc += profesores[i].sueldoSemanal;
	}
	Esc<<"Sueldo total: "<<acc<<endl;
		
	Esc.close();
}

void bubbleSort(Profesor profesores[50], int n) 
{

    int i, j; 
    for (i = 0; i < n-1; i++)     

    for (j = 0; j < n-i-1; j++){

    	if (profesores[j].sueldoSemanal < profesores[j+1].sueldoSemanal) {
    		Profesor aux = profesores[j];
    		profesores[j] = profesores[j+1];
    		profesores[j+1] = aux;
	}
   }
} 
        
	

void ordenado(Profesor profesores[50], int num){
	
	bubbleSort(profesores, num);
	
	ofstream Esc;
	Esc.open("salidaOrdenada.txt", ios::app);
	int acc=0;
	
	for(int i=0; i<num; i++){
		profesores[i].sueldoSemanal = profesores[i].horasDictadas * profesores[i].valorHora;
		Esc<<profesores[i].codigo<<" ";
		Esc<<profesores[i].nombre<<" ";
		Esc<<profesores[i].sueldoSemanal<<" "<<endl;
		acc += profesores[i].sueldoSemanal;
	}
		
	Esc.close();
}

