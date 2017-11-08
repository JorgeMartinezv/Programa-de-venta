#include <iostream>
using namespace std;
int agregarVenta(int tabla[][6], int t);
void SiVentas(int tabla[][6], int t);
void mostrarTabla(int tabla[][6],int t);
void sumadeVentas(int tabla[][6], int t);
void sumaTotal(int tabla[][6], int t);
int menu();
int main() {
    int tabla [6][6]={{0}};
    int t = 6;
    int opc;
    do {
        opc = menu();
        if (opc==1)
            mostrarTabla(tabla, t);
        else if(opc==2)
            agregarVenta(tabla,t);
        
        else if(opc==3)
            cout<<"3";
        else if(opc==0)
            cout<<"Salir";
    } while (opc!=0);
    
    return 0;
}
int menu(){
    int opc;
    cout<<"1.-Ver tabla\n";
    cout<<"2.-Agregar una venta\n";
    cout<<"3.-Modificar una venta\n";
    cout<<"4.-Eliminar una venta\n";
    cout<<"0.-Salir\n";
    cin>>opc;
    
    return opc;
}
void mostrarTabla(int tabla[][6], int t)
{
    sumadeVentas(tabla, t);
    sumaTotal(tabla, t);
    for(int i=0;i<6;i++){
        for (int j=0; j<t; j++) {
           
            if(j==5){
                cout<<"=";
                cout<<"\t"<<tabla[i][j];
                cout<<" ";
            }
            else if(i==4)
                cout<<"\t-";
            else
            cout<<"\t"<<tabla[i][j];
  
            cout<<" ";
        }
    cout<<"\n";
    }
    
    SiVentas(tabla, t);
}
int agregarVenta(int tabla[][6], int t)
{ int vendedor, producto, precio;
    char opc;
    cout<<"Agregar una venta\n";
    do {
        cout<<"Agrega el numero del vendedor:\n";
        cin>>vendedor;
        cout<<"Agrega el numero del producto:\n";
        cin>>producto;
        if (vendedor>4 || producto >5) {
            cout<<"Este numero no es valido \n";
            return 0;
        }
        else
            cout<<"Agregar el precio del producto:\n";
            cin>>precio;
        if (tabla[vendedor-1][producto-1]!=0)
            tabla[vendedor-1][producto-1]+=precio;
        else
            tabla[vendedor-1][producto-1]=precio;
        cout<<"Quieres realizar otra operacion? S/N \n";
        cin>>opc;
        
    } while (opc!='n'&& opc!='N');
    
    return 0;
}

void sumadeVentas(int tabla[][6], int t)
{ 
    for (int i = 0; i<t; i++)
        for (int j=0; j<t-1; j++)
            tabla[i][t-1] += tabla[i][j];
}
void sumaTotal(int tabla[][6], int t)
{
    for (int i=0; i<t; i++)
        for (int j=0; j<t-1; j++)
            tabla[t-1][i] += tabla[j][i];
}
void SiVentas(int tabla[][6], int t)
{
    for (int i=0; i<4; i++)
    {
            if (tabla[i][t-1]==0)
                cout<<"Las Ventas"<<i+1<< "No hubo ventas\n";
            else
                cout<<"Las Ventas"<<i+1<< "Hubo Ventas:"<<tabla[i][t-1]<<"\n";
        }
}
