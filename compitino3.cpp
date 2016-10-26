#include<iostream>
#include<fstream>
using namespace std;

int MaxM(int M[][2], int dimM)
{
int max=M[0][1];
for(int i=1;i<dimM;i++)
 if(max<M[i][1])
   max=M[i][1];
 return max;
}

//incremento contatore dell'elemento già presente oppure aggiungo una nuova riga.
void cambiaM(int y, int M[][2], int& dimM){
    if(dimM==0){
        M[dimM][0]=y;
        M[dimM][1]=1;
        dimM++;
    }
    else{
        
        for(int i=0; i<dimM; i++){
            if(y==M[i][0]){
                M[i][1]+=1;
            }
            else{
                M[dimM][0]=y;
                M[dimM][1]+=1;
                dimM++;
                i=dimM;
            }
        }
    }
}

int FH(int *X, int lim1, int lim2, int n_el, int rig, int col, int L, int H, int f, int i){

    if(((lim2*rig)+col)+((lim2*f)+i)>(n_el-1)){         //se el supera il n_el throw
        cout<<"Throw: false"<<endl;
        throw(false);
    }else{
        return X[((lim2*rig)+col)+((lim2*f)+i)];
    }

}

int F(int*X, int n_el, int lim1, int lim2, int rig, int col, int L, int H, int f)
{
 int M[L][2], dimM=0;
 bool continua=true;
 for(int i=0; i<L && continua; i++)
  {
     try
        {
         int y=FH(X,lim1,lim2,n_el,rig,col,L,H,f,i);//da fare

         cambiaM(y,M,dimM);//da fare
        }
     catch(bool x)
     {continua=x;}
  }
 if(dimM==0)
  return -1;
 else

  return MaxM(M,dimM);//fatta
}


main()
{
 int X[400], lim1, lim2, n_el, rig, col, L, H;
 cin>>lim1>>lim2>>n_el;
 for(int i=0; i<n_el; i++)
  cin>>X[i];
 if(n_el > lim1*lim2)
   n_el=lim1*lim2;
  cin>>rig>>col>>L>>H; //si assume che questi valori siano ok

  //abbiamo la sottomatrice
 int bestrep=-1, indexb=-1;
 for(int i=0; i<H; i++)
   {
     int a= F(X,n_el,lim1,lim2,rig,col,L,H,i);//fatta

     if(bestrep<a)
      {indexb=i; bestrep=a;}


   }
 cout<<"Miglior riga="<<indexb<<" con "<<bestrep<<" ripetizioni"<<endl;
 cout<<"end";

}
