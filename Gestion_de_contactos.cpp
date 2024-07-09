#include<iostream>

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
	cout<<"NOMBRE\t\t"<<"SEXO\t\t"<<"EDAD\t\t"<<"TELEFONO\t\t"<<"EMAIL\t\t"<<"NACIONALIDAD\t\t\n\n";
	for(int i=0;i<=n;i++){
		cout<<contacto[i].nombreCompleto<<"\t\t";
		cout<<contacto[i].sexo<<"\t\t";
		cout<<contacto[i].edad<<"\t\t";
		cout<<contacto[i].telefono<<"\t\t";
		cout<<contacto[i].email<<"\t\t";
		cout<<contacto[i].nacionalidad<<"\t\t\n";
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
		cout<<"NOMBRE\t\t"<<"SEXO\t\t"<<"EDAD\t\t"<<"TELEFONO\t\t"<<"EMAIL\t\t"<<"NACIONALIDAD\t\t\n\n";
		for(int i=0;i<=ng;i++){
			cout<<arr[gmail[i]].nombreCompleto<<"\t\t";
			cout<<arr[gmail[i]].sexo<<"\t\t";
			cout<<arr[gmail[i]].edad<<"\t\t";
			cout<<arr[gmail[i]].telefono<<"\t\t";
			cout<<arr[gmail[i]].email<<"\t\t";
			cout<<arr[gmail[i]].nacionalidad<<"\t\t\n";
		}
		cout<<endl;
	}else{
		cout<<"No existen contactos...\n\n";
	}
	
	cout<<"Outlook: "<<endl;
	if(nk>-1){
		cout<<"NOMBRE\t\t"<<"SEXO\t\t"<<"EDAD\t\t"<<"TELEFONO\t\t"<<"EMAIL\t\t"<<"NACIONALIDAD\t\t\n\n";
		for(int i=0;i<=nk;i++){
			cout<<arr[outlook[i]].nombreCompleto<<"\t\t";
			cout<<arr[outlook[i]].sexo<<"\t\t";
			cout<<arr[outlook[i]].edad<<"\t\t";
			cout<<arr[outlook[i]].telefono<<"\t\t";
			cout<<arr[outlook[i]].email<<"\t\t";
			cout<<arr[outlook[i]].nacionalidad<<"\t\t\n";
		}
		cout<<endl;
	}else{
		cout<<"No existen contactos...\n\n";
	}

	cout<<"Yahoo: "<<endl;
	if(ny>-1){
		cout<<"NOMBRE\t\t"<<"SEXO\t\t"<<"EDAD\t\t"<<"TELEFONO\t\t"<<"EMAIL\t\t"<<"NACIONALIDAD\t\t\n\n";
		for(int i=0;i<=ny;i++){
			cout<<arr[yahoo[i]].nombreCompleto<<"\t\t";
			cout<<arr[yahoo[i]].sexo<<"\t\t";
			cout<<arr[yahoo[i]].edad<<"\t\t";
			cout<<arr[yahoo[i]].telefono<<"\t\t";
			cout<<arr[yahoo[i]].email<<"\t\t";
			cout<<arr[yahoo[i]].nacionalidad<<"\t\t\n";
		}
		cout<<endl;
	}else{
		cout<<"No existen contactos...\n\n";
	}
	
	cout<<"Otros: "<<endl;
	if(otros>-1){
		cout<<"NOMBRE\t\t"<<"SEXO\t\t"<<"EDAD\t\t"<<"TELEFONO\t\t"<<"EMAIL\t\t"<<"NACIONALIDAD\t\t\n\n";
		for(int i=0;i<=otros;i++){
			cout<<arr[etc[i]].nombreCompleto<<"\t\t";
			cout<<arr[etc[i]].sexo<<"\t\t";
			cout<<arr[etc[i]].edad<<"\t\t";
			cout<<arr[etc[i]].telefono<<"\t\t";
			cout<<arr[etc[i]].email<<"\t\t";
			cout<<arr[etc[i]].nacionalidad<<"\t\t\n";
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
		cout<<" 3. Mostrar lista general de contactos registrados hasta el momento\n";
		cout<<" 4. Mostrar listado de contactos ya existentes, ordenados por servidor de correo de las cuentas (gmail.com, outlook.com, yahoo.com, etc.)\n";
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