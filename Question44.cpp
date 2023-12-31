#include <iostream>
using namespace std;

template<typename T>
class Set
{
private:
  	T element[100]={0};
  	int count=0;

public:
    Set() {
        return;
    }
    Set(const Set &a) { //copy
        for(int i = 0; i < a.count; i++){
            element[i] = a.element[i];
        }
        count = a.count;
    }

    int add(const T num){
        int found=0;
        for(int i=0;i<count;++i){
            if(element[i]==num){
                found++;
                break;
            }
        }
        if(found==0){
            element[count]=num;
            count++;
            return 1;
        }
        else return 0;
    }

    int add(const Set s){
        int added=0;
        for(int i=0;i<s.count;++i){
            added+=add(s.element[i]);
        }
        return added;
    }

    Set operator +(const Set s)
    {
        Set Union= Set(*this);
        Union.add(s);//Discards the int "added"
        return Union;
    }

    Set operator -(const Set s)
    {
        Set Intersect;
        for(int i=0;i<count;++i){
            for(int j=0;j<s.count;++j){
                if(s.element[j]==element[i]){
                    Intersect.add(element[i]);
                }
            }
        }
        return Intersect;
    }

  	void display()
    {
      for(int j = 0; j < count; j ++)
        cout<<element[j]<<" ";
    }
};

int main(void)
{
    return 0;
}
