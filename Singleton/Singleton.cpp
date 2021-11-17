#include <iostream>
#include <vector>
#include <cstring>
#include <memory>
using namespace std;

class singleton
{
public:
   static singleton& getSingleTon(){
      static singleton instance;
      return instance;
   }
   int num = 1;
};

int main()
{
   auto a = singleton::getSingleTon().num;
   cout<<1<<endl;
   return 0;
}