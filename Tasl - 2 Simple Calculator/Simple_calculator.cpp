#include <iostream>


using namespace std;
int main(){
    string eq,temp;
    int ans=0,temp1=1;
    cout << "WELCOME TO A SIMPLE CALCULATOR\n";
    cout << "This Calculator only supports basic operations like = (+,-,*,/)\n";
    cout << "YOUR equation : ";
    getline(cin,eq);
    for(int i =0 ; i < eq.size() ; i++){
        if(isdigit(eq[i])){
            temp += eq[i];
        }
        else if(eq[i]=='+'){
            ans += stoi(temp);
        }
        else if(eq[i]=='-'){
            ans = stoi(temp);
        }
        else if(eq[i]=='*'){
            if(!temp1) temp1++;
            ans *= stoi(temp);
        }
        else if(eq[i]=='/'){
            ans /= stoi(temp);
        }
    }
    cout << "YouCr Answer is = " << ans;
    return 0 ;
}