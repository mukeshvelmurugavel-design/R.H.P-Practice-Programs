#include <iostream>
using namespace std;
int main() {
    string S;
    cin>>S;
    int L=S.length();
    for(int ctr=1;ctr<(1<<L);ctr++){
        string combi="";
        for(int sh=0;sh<L;sh++){
            if((ctr&(1<<sh))>0){
                combi+=S[sh];
            }
        }
        cout<<combi<<endl;
    }
}
