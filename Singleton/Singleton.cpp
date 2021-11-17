#include <iostream>
#include <vector>
#include <cstring>
#include <memory>
using namespace std;

//most simple static way to bulid a instance
class singleton
{
public:
   static singleton& getSingleTon(){
      static singleton instance;//only call the construct function once
      return instance;
   }
   singleton(){
      cout<<"only bulid once"<<endl;
   }
   int num = 1;
};

//hungry
class singleton1
{
public:
   static singleton1* getSingleTon1(){
      //lock
      //关于lock代价高的问题可以用双检查来进行lock，即如果instance1为null，则加锁，判断instance1为null，做new操作
      //但会出现问题：instance1 = new singleton1()这句话可以分成三个步骤来执行：

      //1.分配了一个singleton1类型对象所需要的内存。
      //2.在分配的内存处构造singleton1类型的对象。
      //3.把分配的内存的地址赋给指针instance1。
      //但编译器会对上述步骤进行优化，即2、3步会乱序执行，出现问题
      if(instance1==nullptr){
         instance1 = new singleton1();
      }
      return instance1;
   }
   static void show(){
      cout<<num1<<endl;
   }
   static int num1;
private:
   static singleton1 *instance1;
   singleton1(){};//将构造函数私有化，不允许生成自己的对象
   //singleton1(const singleton1& instance);
};
int singleton1::num1 = 2;
singleton1* singleton1::instance1=nullptr;
int main()
{
   auto a = singleton::getSingleTon().num;
   auto b = singleton1::getSingleTon1()->num1;
   auto c = singleton::getSingleTon().num;
   cout<<a<<endl;
   cout<<b<<endl;
   return 0;
}