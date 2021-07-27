#include "ArrayInt.h"


void ArrayInt::erase()
{
delete[] m_data;
// Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не
//было висячего указателя
m_data = nullptr;
m_length = 0;
}
int ArrayInt::getLength() { return m_length; }

int& ArrayInt::operator[](int index)
{
assert(index >= 0 && index < m_length);
return m_data[index];
}
// Функция resize изменяет размер массива. Все существующие элементы
//сохраняются. Процесс медленный
void ArrayInt::resize(int newLength)
{
// Если массив уже нужной длины — return
if (newLength == m_length)
return;
// Если нужно сделать массив пустым — делаем это и затем return
if (newLength <= 0)
{
erase();
return;
}
// Теперь знаем, что newLength >0
// Выделяем новый массив
int *data = new int[newLength];
// Затем нужно разобраться с количеством копируемых элементов в новый
//массив
// Нужно скопировать столько элементов, сколько их есть в меньшем из
//массивов
if (m_length > 0)
{
int elementsToCopy = (newLength > m_length) ? m_length : newLength;
// Поочередно копируем элементы
for (int index=0; index < elementsToCopy ; ++index)
data[index] = m_data[index];
}
// Удаляем старый массив, так как он нам уже не нужен
delete[] m_data;
// И используем вместо старого массива новый! Обратите внимание,m_data указывает
// на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
// данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
m_data = data;
m_length = newLength;
}

void ArrayInt::insertBefore(int value, int index)
{
// Проверка корректности передаваемого индекса
assert(index >= 0 && index <= m_length);
// Создаем новый массив на один элемент больше старого массива
int *data = new int[m_length+1];
// Копируем все элементы до index-а
for (int before=0; before < index; ++before)
data[before] = m_data[before];
// Вставляем новый элемент в новый массив
data [index] = value;
// Копируем все значения после вставляемого элемента
for (int after=index; after < m_length; ++after)
data[after+1] = m_data[after];
// Удаляем старый массив и используем вместо него новый
delete[] m_data;
m_data = data;
++m_length;
}
void ArrayInt::push_back(int value) { insertBefore(value, m_length); }

int ArrayInt::pop_back()
{
  assert(m_length>0);
  int tmp=m_data[m_length-1];
  int *data = new int[m_length-1];
  for (int before=0; before < m_length-1; ++before)
     {
      data[before] = m_data[before];
     }

  m_length--;
  delete[] m_data;
  m_data = data;
  return tmp;


//  Либо вариант для ленивых но зато намного быстрее
//   assert(m_length>0);
//   int tmp=m_data[m_length-1];
//    m_length--;
//   return tmp;
}
int ArrayInt::pop_front()
{
   assert(m_length>0);
   int tmp=m_data[0];
   int *data = new int[m_length-1];
   for (int before=0; before < m_length-1; ++before)
      {
       data[before] = m_data[before+1];
      }
   m_length--;
   delete[] m_data;
   m_data = data;

return tmp;

//  Либо вариант для ленивых но зато намного быстрее
//   assert(m_length>0);
//   int tmp=m_data[0];
//   for (int before=0; before < m_length-1; ++before)
//      {
//       m_data[before] = m_data[before+1];
//      }

//m_length--;
//return tmp;
}
void ArrayInt::print_all()
{
   for(int i=0;i<m_length;i++)
      {
       std::cout<<" "<<i<<": "<<m_data[i]<<std::endl;
      }
}

void ArrayInt::sort_all(bool flag)
    {
      int temp;
      if(flag)
         {
           for (int i = 0; i < m_length - 1; i++)
            {
              for (int j = 0; j < m_length - i - 1; j++)
              {
                 if (m_data[j] > m_data[j + 1])
                 {
                   // меняем элементы местами
                   temp = m_data[j];
                   m_data[j] = m_data[j + 1];
                   m_data[j + 1] = temp;
                 }
              }
            }
          }
       else
      {
          for (int i = 0; i < m_length - 1; i++)
           {
             for (int j = 0; j < m_length - i - 1; j++)
             {
                if (m_data[j] < m_data[j + 1])
                {
                  // меняем элементы местами
                  temp = m_data[j];
                  m_data[j] = m_data[j + 1];
                  m_data[j + 1] = temp;
                }
             }
           }
      }
    }
