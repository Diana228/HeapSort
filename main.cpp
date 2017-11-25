#include <iostream>

using namespace std;

class heap
{
int k[30],size;
public:
void getdata(void);
friend void sort_heap(heap &);
friend void create_heap(heap &);
void showdata(void);
};

void heap :: getdata(void)
{
cout<<"Ingrese el numero de datos a organizar: ";
cin>>size;
cout<<"\nDigite los "<<size<<" elementos: \n";
 for(int i=1;i<=size;i++) 
   cin>>k[i];
}

void heap :: showdata(void)
{
  cout<<"\n\nDatos organizados: \n\n";
  for(int i=1;i<=size;i++)
    cout<<k[i]<<endl;
}


void create_heap(heap &datos)
{
int z,i,j,key;

  for(z=2;z<=datos.size;z++)// Evaluar elemento por elemento los elementos del vector
  {
    i = z;
    key = datos.k[i];
    j = i/2;
    while(i>1 && key>datos.k[j])
      {
         datos.k[i] = datos.k[j];
         i = j;
         j = i/2;
         if(j<1)
            j = 1;
      }
    datos.k[i] = key;
    }
}

void sort_heap(heap &datos)
{
int z,i,j,key,temp;
  for(z=datos.size;z>=1;z--)
  {
     temp = datos.k[1];
     datos.k[1] = datos.k[z];
     datos.k[z] = temp;
     i = 1;
     key = datos.k[i];
     j = 2*i;
     if(j+1 < z)
     {
         if(datos.k[j+1] > datos.k[j])
            j++;
        }
     while(j<=z-1 && key<datos.k[j])
     {
       datos.k[i]=datos.k[j];
       i=j;
       j=2*i;
       if(j+1 < z)
       {
          if(datos.k[j+1] > datos.k[j])
             j++;
       }
       break;
     }
     datos.k[i]=key;
    }
}

int main()
{
heap example;
example.getdata();
create_heap(example);
sort_heap(example);
example.showdata();
}
