# include <iostream>
using namespace std;

//Ex-one 

int power (int b, int n){
    if (n==0) return 1;
    return b* power ( b, n-1);
}


//Ex-Two
int fibo(int x){
    if (x<=2) return 1;
     return fibo( x-1)+fibo (x-2);
}


//Ex-Three
int fibo(int x){
    if (x<=2) return 1;

            //this has different time complexity .
    for (int i=0;i<x;i++){
        cout<<"Hell0 World !";
    }


     return fibo( x-1)+fibo (x-2);
}




int main(){





    return 0;
}


