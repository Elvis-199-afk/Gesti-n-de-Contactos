#include<iostream>
#include<iomanip>
using namespace std;

struct contactoEmail {
	char nombreCompleto[50];
	char sexo;
	int edad;
	char telefono[15];
	char email[35];
	char nacionalidad[15];
};
void agregarContacto(contactoEmail contacto[], int &n){
	n++;
	cin.ignore();
	cout<<"Ingrese el nombre completo: ";
	cin.getline(contacto[n].nombreCompleto,50);
	do{
		cout<<"Ingrese el sexo, masculino o femenino ('m' o 'f'): ";
		cin>>contacto[n].sexo;
		if(contacto[n].sexo!='m' && contacto[n].sexo!='f'){
			cout<<"Ingrese un sexo valido\n";
		}
	}while(contacto[n].sexo!='m' && contacto[n].sexo!='f');
	do{
		cout<<"Ingrese la edad: ";
		cin>>contacto[n].edad;
		if(contacto[n].edad<1){
			cout<<"Ingrese una edad valida\n";
		}
	}while(contacto[n].edad<1);
	cin.ignore();
	cout<<"Ingrese el telefono: ";
	cin.getline(contacto[n].telefono,15);
	cout<<"Ingrese el email: ";
	cin>>contacto[n].email;
	cin.ignore();
	cout<<"Ingrese la nacionalidad: ";
	cin.getline(contacto[n].nacionalidad,15);
}
void eliminarContacto(contactoEmail *contacto, int &n){
	int indice;
	cout<<"Ingrese la posicion del contacto que desea eliminar: ";
	cin>>indice;
	for(int i=indice-1;i<n;i++){
		contacto[i]=contacto[i+1];
	}
	n--;
}
void mostrarLista(contactoEmail *contacto, int n){
	cout<<left<<setw(50)<<"NOMBRE"<<setw(10)<<"SEXO"<<setw(10)<<"EDAD"<<setw(30)<<"TELEFONO"<<setw(50)<<"EMAIL"<<setw(20)<<"NACIONALIDAD"<<endl<<endl;
	for(int i=0;i<=n;i++){
		cout<<setw(50)<<contacto[i].nombreCompleto;
		cout<<setw(10)<<contacto[i].sexo;
		cout<<setw(10)<<contacto[i].edad;
		cout<<setw(30)<<contacto[i].telefono;
		cout<<setw(50)<<contacto[i].email;
		cout<<setw(20)<<contacto[i].nacionalidad<<endl;
	}
}
int tamArreglo(contactoEmail contacto[], int x){
	int n=-1;
	for(int i=0; contacto[x].email[i]!='\0'; i++){
		n++;
	}
	return n;
}
void mostrarListaOrdenada(contactoEmail arr[], int n){
	int gmail[10], outlook[10], yahoo[10], etc[10], otros=-1, ng=-1, nk=-1, ny=-1;
	for(int i=0;i<=n;i++){
		int tam;
		tam=tamArreglo(arr, i);
		if(arr[i].email[tam-4]=='l'){	
			ng++;
			gmail[ng]=i;
		}else if(arr[i].email[tam-4]=='k'){
			nk++;
			outlook[nk]=i;
		}else if(arr[i].email[tam-4]=='o'){
			ny++;
			yahoo[ny]=i;
		}else {
			otros++;
			etc[otros]=i;
		}
	}
	
	cout<<"Gmail: "<<endl;
	if(ng>-1){
		cout<<left<<setw(50)<<"NOMBRE"<<setw(10)<<"SEXO"<<setw(10)<<"EDAD"<<setw(30)<<"TELEFONO"<<setw(50)<<"EMAIL"<<setw(20)<<"NACIONALIDAD"<<endl<<endl;
		for(int i=0;i<=ng;i++){
			cout<<setw(50)<<arr[gmail[i]].nombreCompleto;
			cout<<setw(10)<<arr[gmail[i]].sexo;
			cout<<setw(10)<<arr[gmail[i]].edad;
			cout<<setw(30)<<arr[gmail[i]].telefono;
			cout<<setw(50)<<arr[gmail[i]].email;
			cout<<setw(20)<<arr[gmail[i]].nacionalidad<<endl;
		}
		cout<<endl;
	}else{
		cout<<"No existen contactos...\n\n";
	}
	
	cout<<"Outlook: "<<endl;
	if(nk>-1){
		cout<<left<<setw(50)<<"NOMBRE"<<setw(10)<<"SEXO"<<setw(10)<<"EDAD"<<setw(30)<<"TELEFONO"<<setw(50)<<"EMAIL"<<setw(20)<<"NACIONALIDAD"<<endl<<endl;
		for(int i=0;i<=nk;i++){
			cout<<setw(50)<<arr[outlook[i]].nombreCompleto;
			cout<<setw(10)<<arr[outlook[i]].sexo;
			cout<<setw(10)<<arr[outlook[i]].edad;
			cout<<setw(30)<<arr[outlook[i]].telefono;
			cout<<setw(50)<<arr[outlook[i]].email;
			cout<<setw(20)<<arr[outlook[i]].nacionalidad<<endl;
		}
		cout<<endl;
	}else{
		cout<<"No existen contactos...\n\n";
	}

	cout<<"Yahoo: "<<endl;
	if(ny>-1){
		cout<<left<<setw(50)<<"NOMBRE"<<setw(10)<<"SEXO"<<setw(10)<<"EDAD"<<setw(30)<<"TELEFONO"<<setw(50)<<"EMAIL"<<setw(30)<<"NACIONALIDAD"<<endl<<endl;
		for(int i=0;i<=ny;i++){
			cout<<setw(50)<<arr[yahoo[i]].nombreCompleto;
			cout<<setw(10)<<arr[yahoo[i]].sexo;
			cout<<setw(10)<<arr[yahoo[i]].edad;
			cout<<setw(30)<<arr[yahoo[i]].telefono;
			cout<<setw(50)<<arr[yahoo[i]].email;
			cout<<setw(30)<<arr[yahoo[i]].nacionalidad<<endl;
		}
		cout<<endl;
	}else{
		cout<<"No existen contactos...\n\n";
	}
	
	cout<<"Otros: "<<endl;
	if(otros>-1){
		cout<<left<<setw(50)<<"NOMBRE"<<setw(10)<<"SEXO"<<setw(10)<<"EDAD"<<setw(30)<<"TELEFONO"<<setw(50)<<"EMAIL"<<setw(30)<<"NACIONALIDAD"<<endl<<endl;
		for(int i=0;i<=otros;i++){
			cout<<setw(50)<<arr[etc[i]].nombreCompleto;
			cout<<setw(10)<<arr[etc[i]].sexo;
			cout<<setw(10)<<arr[etc[i]].edad;
			cout<<setw(30)<<arr[etc[i]].telefono;
			cout<<setw(50)<<arr[etc[i]].email;
			cout<<setw(30)<<arr[etc[i]].nacionalidad<<endl;
		}
		cout<<endl;
	}else{
		cout<<"No existen contactos...\n\n";
	}
}

int main(){
	contactoEmail conE[30];
	int n=-1;
	int op;
	do{
		system("cls");
		cout<<"=== GESTION DE CONTACTOS ===\n\n";
		cout<<" 1. Agregar contacto\n";
		cout<<" 2. Eliminar contacto\n";
		cout<<" 3. Mostrar lista general de contactos registrados hasta el momento (preferiblemente ponga pantalla completa)\n";
		cout<<" 4. Mostrar listado de contactos ya existentes, ordenados por servidor de correo de las cuentas (gmail.com, outlook.com, yahoo.com, etc.) (preferiblemente ponga pantalla completa)\n";
		cout<<" 5. Salir del programa\n\n";
		cout<<"== SELECCIONA UNA DE LAS OPCIONES ==\n";
		cin>>op;
		
		switch (op){
			case 1:
				system("cls");
				if(n==30){
					cout<<"Se ha llegado al limite de contactos\n";
				}else{
					agregarContacto(conE,n);
				}
				break;
			case 2:
				system("cls");
				eliminarContacto(conE,n);
				cout<<"La lista seria esta: \n";
				mostrarLista(conE,n);
				system("pause");
				break;
			case 3:
				if(n==-1){
					cout<<"No hay contactos existen...\n ";	
				}else{
					mostrarLista(conE,n);
					cout<<endl;
				}
				system("pause");
				break;
			case 4:
				if(n==-1){
					cout<<"No hay contactos existen...\n ";
				}else{
					cout<<"El listado de contactos existentes, ordenado por servidor de correo de las cuentas (gmail.com, outlook.com, yahoo.com, etc.) es: \n\n";
					mostrarListaOrdenada(conE,n);
				}
				system("pause");
				break;
			case 5:
				cout<<"\nFIN . . .\n";
				break;
			default :
				cout<<"\n\nINGRESE UNA OPCION VALIDA\n";
				system("pause");
				break;
		}
	}while(op!=5);
	return 0;
}
