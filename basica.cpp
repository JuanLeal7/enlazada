#include <iostream>
#include <conio.h>
using namespace std;
struct nodo{
    int nro;
    struct nodo *sig;  
};

void insertar(nodo *&,int);
void mostrar(nodo*);
void buscar(nodo *,int);
void borrar(nodo *&,int);

void actualizar(nodo*lista,int b){
    bool band = false;
	nodo *act =new nodo();
    act = lista;
    
    while((act!=NULL)&&(act->nro <=b)){

     if(act->nro==b){
     	band=true;
	   }
	   act = act->sig;
    } 
    if(band= true){
    cout<<"El valor:"<<b<<" esta en la lista\n";
    cout<<"ingrese el nuevo valor\n";
    cin>> act->nro;
    }
    else{
	cout<<"El valor:"<<b<<" no esta en la lista\n";
    }
	
}

int main(){
    nodo *lista= NULL;
    int nro,m,nuevo;
    cout<<"cantidad de la lista\n";
    cin>>m;

for (int i=0 ; i < m ; i++)
{
    cout<<"ingrese el valor\n";
    cin>>nro;
    insertar(lista,nro); 	
}

int opc;
do{	

cout<<"OPCIONES\n";
cout<<"1.Mostrar lista\n";
cout<<"2.Buscar valor en la lista\n";
cout<<"3.Borrar valor de la lista\n";
cout<<"4.Actualizar valor\n";
cout<<"5.EXIT\n";
cin>>opc;


	switch(opc){
		case 1: 
		mostrar(lista);
		system("pause");
		break;
		case 2:
		cout<<"digite el valor que desea buscar\n";
		cin>>nro;
		buscar(lista,nro);
		system("pause");	
		break;
		case 3:cout <<"digite el valor que desea eliminar\n";
		cin>>nro;
		borrar(lista,nro);
		system("pause");
		break;
		case 4:
		cout<<"digite el valor que desea actualizar\n";
		cin>>nro;
		actualizar(lista,nro);
		cout<<"lista actualizada\n";
		system("pause");
			
		break;
	}
	system("cls");	

   }while(opc !=5);

}

 void insertar(nodo *&lista,int n){
 
    nodo *Nlista = new nodo();
    Nlista -> nro =n;
    
    nodo *aux1 = lista;
    nodo *aux2;
   
    
    while((aux1 != NULL ) && (aux1->nro < n)){
        aux2 = aux1;
        aux1 = aux1->sig;
    }
    if(lista== aux1){
        lista=Nlista;

    }
    else{
        aux2->sig =Nlista;
    }
Nlista ->sig=aux1;
}

void mostrar(nodo *lista){
	nodo *act =new nodo(); 
	act =lista;
	
	while(act !=NULL ){
		cout<<act->nro<<" -> ";
		act = act->sig;	
	}
}

void buscar(nodo*lista,int b){
    bool band = false;
	nodo *act =new nodo();
    act = lista;
    
    while((act!=NULL)&&(act->nro <=b)){

     if(act->nro==b){
     	band=true;
	   }
	   act = act->sig;
    } 
    if(band= true){
    cout<<"El valor:"<<b<<" esta en la lista\n";
    }
    else{
	cout<<"El valor:"<<b<<" no esta en la lista\n";
    }
	
}

void borrar (nodo *&lista,int n){
	if(lista !=NULL){
		nodo *borrar;
		nodo *ant = NULL;
		borrar =lista;
	
	while((borrar !=NULL) && (borrar->nro !=n)){
		ant= borrar;
		borrar= borrar->sig;
	}	
	if (borrar == NULL){
		cout<<"el valor no se encuentra\n";
	}
	else if (ant == NULL){
		lista =lista->sig;
		delete borrar;
	}
	else{
		ant->sig=borrar->sig;
		delete borrar;
	}

  }
}

