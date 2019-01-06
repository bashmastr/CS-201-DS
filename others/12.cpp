#include <iostream>
using namespace std;

class remove_list {
private:
  int *ptr, size;
public:
  remove_list(){
    ptr = NULL;
    ptr = new int [10];
  }
  void add_values(int *ptr1,int var){
    size = var;
    for(int i = 0; i < var; i++){
    *(ptr+i) = *(ptr1+i);
    }
  }
  void show(){
    for (int i = 0; i < 10; i++){
      cout<<*(ptr+i)<<" ";
      if(i == size-1)
        break;
    }
  }
  void remove(int var){
    for(int i = 0; i < size;i++){
      if(*(ptr+i) == var){
        for(int j = i;j < size;j++ ){
          *(ptr+j) = *(ptr+(j+1));
        }
        size -= 1;
      }
    }
  }
};


int main (){
  int ptr[8] = {1,2,3,4,5,6,7,8};
  remove_list r;
  r.add_values(ptr,8);
  r.show();
  cout<<endl;
  r.remove(3);
  r.remove(5);

  r.show();


  return 0;
}
