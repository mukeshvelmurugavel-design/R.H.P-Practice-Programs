#include <iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cout<<"Enter your string"<<endl;
    cin>>str;
    int flag=0;
    for(char ch:str){
        flag=flag|(1<<(ch-'a'));
    }
    if(flag==(1<<26)-1){
        cout<<"True";
    }
    else{
        cout<<"False";
    }
}