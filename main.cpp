//1. Створити функцію, яка на вхід одержує текст (тип char*) і перетворює його: відкидає повторні пробіли. Функція повинна повертати кількість відкинутих пробілів. Текст передавати у функцію по посиланню. Перезавантажити операцію "<<" виведення перетвореного рядка, в якій викликати створену функцію.//
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int cnt(char *text,int n){
  int q=0,count=0;
  for(int i=0;i<n;i++){
    if(text[i]==' ' && q==0){
      q=1;
      cout<<text[i];
    }
    else if(text[i]==' ' && q==1){
      count++;
    }
    else if(text[i]!=' '&& q==1){
      q=0;
      cout<<text[i];
    }
    else cout<<text[i];
  }
  return count;
}

ostream& operator <<(ostream& out, char* string){
    cnt(string, strlen(string));
    
    out << string << endl;
    return out;
}


int main()
{
  cout<<"Введіть текст: "<<endl;
  char* t = new char[255];
  
    cin >> t;
    
    cout << t;
    
    
    delete [] t;
//cout<<t1;
}
