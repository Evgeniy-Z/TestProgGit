#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
 
class Product
{
private:
    char name[80];
    int price;
    float weight;
public:
     Product()
     {
         strcpy(name, '');
         price = 0;
         weight = 0;
     }
     Product(char*str, int pr, float wgh)
     {
         strcpy(name, str);
         price = pr;
         weight = wgh;
     }
     int getPrice()  const
     {
         return price;
     }
     float getWeight()  const
     {
         return weight;
     }
    void showData()   const
    {
        cout<<left<<setw(18)<<"\nТовар:"<<name;
        cout<<setw(18)<<"\nЦена:" <<setw(8)<<price<<" руб";
        cout<<setw(18)<<"\nВес:"  <<setw(8)<<weight<<" кг"<<endl;
    }
};
 
class Buy:public Product
{
private:
    int col;
    int total_price;
    float total_weight;
public:
     Buy():Product()
     {
         col = 0;
         total_price = 0;
         total_weight = 0;
     }
     Buy(int c)
    {
       col = c;
       int temp1 = getPrice();
       float temp2 = getWeight();
       total_price = temp1*c;
       total_weight = temp2*c;
    }
     Buy(char*n, int p, float w, int c):  Product(n, p, w)
     {
         col = c;
       total_price = c* getPrice();;
       total_weight = c* getWeight();
     }
 
};
 
class Check:private Buy
{
  public:
      Check(): Buy()
      {
      }
      Check(char*n, int p, float w, int cl):  Buy(n, p, w, cl)
      {
      }
      void showData()  const
     {
        Product::showData();
     }
};
 
int main()
{
    setlocale(LC_CTYPE, "rus");
    Check s1("Вареники", 235, 3.5, 5);
    Check s2("Ковбаса", 1, 50, 1);
    return 0;
}
