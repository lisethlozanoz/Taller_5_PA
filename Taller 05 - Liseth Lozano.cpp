
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Profesor{
	int codigo;
	string nombre; 
	int valorHora;
	int horasDictadas;
	int sueldoSemanal;
};

struct Clases{
	int *inicia;
	int *termina;
	int horasClase; 
};

int menu(); //Para mostrar y escanear las opciones del menu  

int cantidadProfesores();//Para calcular cantidad de profesores que hay en el archivo

int cantidadClases(Profesor *profesor,int cantidadProfesores);//Para calcular cantidad de clases que tiene cada profesor

void lectura(Profesor *profesor, int cantidadProfesores);/*Para capturar e imprimir los registros 
del archivo*/

void generarArchivo(Profesor *profesor, int cantidadProfesores); //Para generar el archivo ordenado descendentemente e imprimirlo

void imprimirArchivoNuevo (int cantidadProfesores);/*Para imprimir el archivo de los sueldos superiores
sueldos superiores*/

int main(){
	
	int op, tamanoProfesor, tamanoClase;
	
	op=menu();
	tamanoProfesor=cantidadProfesores();	
	Profesor *profesor = new Profesor[tamanoProfesor];//Arreglo que va a guardar los datos de los profesores
	tamanoClase=cantidadClases(profesor,tamanoProfesor);
	Clases *clases= new Clases[tamanoClase];
	
	//do{
		switch(op){
		
		case 1:
			lectura(profesor, tamanoProfesor);
			break;
			
		case 2:
			
			break;
			
		case 3:
			generarArchivo(profesor, tamanoProfesor);
			imprimirArchivoNuevo(tamanoProfesor);
			break;
			
		case 4:
			break;
	    }		
		
	//}while(op!=4);
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


////////////////////////////////////////////////////////////////////////////////////////////////////
int cantidadProfesores(){
	
	ifstream entradaArchivo;
    entradaArchivo.open("profesor.txt");
    
    int cantidadProfesores= 0;
    string line;


    if (!entradaArchivo.is_open()){
        cout << "No se pudo abrir el archivo"<<endl;
    }

    else{
        while (getline(entradaArchivo, line)){
            cantidadProfesores++;
        }
    }
    
    return cantidadProfesores/4;
}


//////////////////////////////////////////////////////////////////////////////////////////////////
int cantidadClases(Profesor *profesor,int cantidadProfesores){
	
	ifstream entradaArchivo;
    entradaArchivo.open("profesor.txt");
    
    int cantidadClases= 0;
    string line;


    if (!entradaArchivo.is_open()){
        cout << "No se pudo abrir el archivo"<<endl;
    }

    else{
        for(int i=0; i<cantidadProfesores;i++){
        	
			cantidadClases++;
		}
    }
    
	return cantidadClases;
}


////////////////////////////////////////////////////////////////////////////////////////////////////
void lectura(Profesor *profesor, int cantidadProfesores){
	
	ifstream entradaArchivo;
    entradaArchivo.open("profesor.txt");


    if (!entradaArchivo.is_open()){
        cout << "No se pudo abrir el archivo"<<endl;
    }


    else{
    	
    	for (int i = 0; i < cantidadProfesores; i++){
            entradaArchivo >> (profesor+i)->codigo;
            entradaArchivo >> (profesor+i)->nombre;
            entradaArchivo >> (profesor+i)->valorHora;
            
            cout<<endl<<"*******************************************************************"<<endl;
            cout<<(profesor+i)->codigo<<endl;
            cout<<(profesor+i)->nombre<<endl;
            cout<<(profesor+i)->valorHora<<endl;
        }
    }
    
    entradaArchivo.close();
}


//////////////////////////////////////////////////////////////////////////////////////////////////
void calculoSueldo(Profesor *profesor, int cantidadProfesores){
	
	int totalSueldosProfesores=0; //Esta variable es para los sueldos de todos los profesores
	
	
	for(int i=0; i<cantidadProfesores; i++){
	
		(profesor+i)->sueldoSemanal= (profesor+i)->horasDictadas * (profesor+i)->valorHora;
		
		cout<<endl<<"***************************************************************************"<<endl;
		cout<<"Codigo:"<<endl;
		cout<<(profesor+i)->codigo<<endl;
		cout<<"Nombre:"<<endl;
        cout<<"\t"<<(profesor+i)->nombre<<endl;
        cout<<"Sueldo Semanal:"<<endl;
        cout<<"\t"<<(profesor+i)->sueldoSemanal<<endl;
		
		totalSueldosProfesores+=profesor[i].sueldoSemanal;
		cout<<"El total del sueldo de todos los profesores es "<<totalSueldosProfesores<<endl;
	}
}


///////////////////////////////////////////////////////////////////////////////////////////////////
void generarArchivo(Profesor *profesor, int cantidadProfesores){
	
	int contador=0;
	
	Profesor *listadoNuevo= new Profesor[contador];
	
	for(int i=0; i<cantidadProfesores;i++){
		
		if(((profesor+i)->sueldoSemanal)>700000){
			*(listadoNuevo+contador)=*(profesor+i);
			contador++;
		}
	}
	
	
	int aux;
	Profesor profesorAux;
	
	for (int i = 0; i < contador; i++){
        for (int j = 0; j < contador; j++){
            
			if (((listadoNuevo+i)->sueldoSemanal) < ((listadoNuevo+j)->sueldoSemanal)){    
                profesorAux = listadoNuevo[i];
                *(listadoNuevo+i)=*(listadoNuevo+j);
                *(listadoNuevo+j)= profesorAux;
            }
        }
    }
    
    ofstream salidaArchivo;
    salidaArchivo.open("sueldosSuperiores.txt");
    
    
    for (int i = 0; i <contador; i++){
        salidaArchivo << (listadoNuevo+i)->codigo<< endl;
        salidaArchivo << (listadoNuevo+i)->nombre<< endl;
        salidaArchivo << (listadoNuevo+i)->sueldoSemanal << endl;
    }
    
    salidaArchivo.close();
}


//////////////////////////////////////////////////////////////////////////////////////////////////
void imprimirArchivoNuevo(int cantidadProfesores){
	
	ifstream entradaArchivo;
    entradaArchivo.open("sueldosSuperiores.txt");
    
    char *LineasDelArchivo = new char[cantidadProfesores];


    if (!entradaArchivo.is_open()){
        cout << "No se pudo abrir el archivo"<<endl;
    }
    
    else{
        while (!entradaArchivo.eof())
        {
            entradaArchivo.getline(LineasDelArchivo, cantidadProfesores*4);
            cout << LineasDelArchivo << endl;
        }
    }

    entradaArchivo.close();
}



