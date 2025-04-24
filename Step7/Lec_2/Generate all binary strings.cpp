#include<iostream>
using namespace std;

void generateStartingFrom(string s, int n){
    if(s.length() == n){
        cout<<s<<endl;
        return;
    }

    if(s[s.length()-1] == '1') generateStartingFrom(s + '0',n);
    else{
        generateStartingFrom(s+'0',n);
        generateStartingFrom(s+'1',n);
    }
}
void generate(int &num){
    string s;
    s[0] = '0';
    generateStartingFrom(s,num);
    s[0] = '1';
    generateStartingFrom(s,num);
}

int main(){
    int n = 4;
    generate(n);
    return 0;
}