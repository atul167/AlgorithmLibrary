#include <bits/stdc++.h>
using namespace std;

class ash {
private:
    ash(){}
    
public:
    int id = 5;
    ash* initFun() {
        ash* temp_instance = new ash;
        return temp_instance;
    }    
};
 
int main() {
   ash *as;
   as = as->initFun();
   cout << as->id << endl;
}
