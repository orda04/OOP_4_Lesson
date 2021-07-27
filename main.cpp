/*
**********  Third task on  OOPcourse                                         ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date 24.07.2021                                                  ****
*/




//•••Done ● Добавить в контейнерный класс, который был написан в этом уроке, методы:
//•••Done ● для удаления последнего элемента массива (аналог функции pop_back() в векторах)
//•••Done ● для удаления первого элемента массива (аналог pop_front() в векторах)
//•••Done ● для сортировки массива
//•••Done ● для вывода на экран элементов.




#include <iostream>
#include "ArrayInt.h"
#include <vector>

using namespace std;

void check_vector_of_numbers(vector<int> v)
{
    int tmpsum=0;
    int counter=0;
    int tmpel=0;
    cout <<" size of vector"<<size(v)<<endl;

    for(int i=0;i<size(v);i++)
    {
     cout<<" "<<i<<" "<<v[i]<<endl;
    }


    for(int i=0;i<size(v);i++)   // подсчитываем сумму по модулю
    {
     tmpsum=tmpsum+abs(v[i]);
    }

    for(int i=0;i<size(v);i++)    // сразу проверяем есть ли нули в массиве
    {
     if(v[i]==0)
     {
         counter++;
     }
    }

    while (tmpsum)
    {
      for(int j=0;j<size(v);j++)
         {
            tmpel=v[j];
            if (tmpel==0)
              {
               continue;
              }
             else
               {
                counter++;
                for(int i=j;i<size(v);i++)
                    {
                     if(tmpel==v[i])
                        {
                         tmpsum=tmpsum-abs(v[i]);
                          v[i]=0;
                         }
                     }
                }
            cout<<"Position at part of massive #:"<<j<<endl;
            for(int i=0;i<size(v);i++)
            {
             cout<<" "<<i<<" "<<v[i]<<endl;
            }
      }
    }

    cout << "counter:"<<counter<<endl;

}
int main()
{
 ArrayInt Array(10);
cout<<"Что-то "<<Array.getLength()<<endl;

for(int i=0;i<Array.getLength();i++)
{
  Array[i]=i;
}
Array.print_all();
cout<<endl<<"сортируем"<<endl;
Array.sort_all(0);

cout<<"Popped  front element:"<<Array.pop_front()<<endl;
cout<<"Popped front element:"<<Array.pop_front()<<endl;
cout<<"Popped front element:"<<Array.pop_front()<<endl;


cout<<"Popped element:"<<Array.pop_back()<<endl;
cout<<"Popped element:"<<Array.pop_back()<<endl;
cout<<"Popped element:"<<Array.pop_back()<<endl;
Array.print_all();


vector<int> v = { 1, 2, 3, 4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,-8,-9 };

check_vector_of_numbers(v);
for(int i=0;i<size(v);i++)
{
 cout<<" "<<i<<" "<<v[i]<<endl;
}

    return 0;
}
