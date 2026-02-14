//wanted to implement score system but got out of time
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;
bool login(bool loginin);
void signup();
void removeTrailingSpaces(string& s);
int random_number(int choice,int &diff,int &chance);
int main(){
    srand(time(nullptr));
    int signin=0;
    bool loginin=false;
    while(true){
    cout << "DO WANNA SIGN-UP or LOGIN (1\\2) :";
    cin >> signin;
    cin.ignore();
    if(signin==1){
        signup();
        while(!loginin){
        loginin=login(loginin);
        }
        break;
    }else if(signin==2){
        while(!loginin){
        loginin=login(loginin);
        }
        break;
    }
    else{
        cout << "RETRY CHOOSE ONLY 1 OR 2";
    }
    }
    bool run = true;
    int once =0,choice;
    std::string agree="";
    
    while(run){
        while(true){
            std::cout << "DO YOU WANNA PLAY (YES/NO) :";
            std::transform(agree.begin(), agree.end(), agree.begin(), ::tolower);
            std::cin >> agree;
        if(agree=="no"){
            run = false;
            break;
        }
        else if(agree=="yes") break;
        else std::cout << "TYPE SOMETHING VALID !!\n";
        }
        if(run==false) break;
        if(once!=1){
        while(true){
            std::cout << "CHOOSE THE DIFFICULTY\n1). EASY\n2). MEDIUM\n3). HARD\nIN NUMBER : ";
            std::cin >> choice;
            if(choice == 1 || choice == 2 || choice == 3){
                once =1;
                break;
            }
            else{
                std::cout << "TYPE SOMETHING VALID\n";
            }
        }
    }
    int diff=0,chance=0;
    int guess = random_number(choice,diff,chance);
    int userguess=0;

    while(chance){

        std::cout << "GUSSE THE NUMBER BETWEEN 1 - " << diff << " YOUR HAVE "<< chance <<" left"<<  " : ";
        std::cin >> userguess;
        chance--;
    
        if(userguess == guess){
            cout << "YEA !! YOU GUSSED THE CORRECT NUMBER\n";
            break;
        }else{
            cout << "WRONG ANS RETRY !\n";
        }
    }
    if(chance==0){
        cout << "YOU RAN OUT OF CAHNCES\n";
    }


    }

    
}
bool login(bool loginin){
    string line,username,pass;
    ifstream file("userinfo.txt");
        cout << "USERNAME : ";
        getline(cin,username);
        cout << "PASSWORD : ";
        getline(cin,pass);
        removeTrailingSpaces(username); 
        removeTrailingSpaces(pass);
    while(getline(file, line)){
        size_t pos1 = line.find("||");
        if(pos1 == string::npos) continue;
        size_t pos2 = line.find("||", pos1 + 2);
        if(pos2 == string::npos) continue;

        string fusername = line.substr(0,pos1);
        string fpassword = line.substr(pos1+2,pos2 - pos1 -2 );

        if(fusername == username && fpassword == pass){
            cout << "SUCCESFULYY LOGINED !!\n";
            loginin = true;
            return loginin;
        }
        
        
        
    }
    file.close();
    cout << "LOGINED FAILED !!\n";
    return loginin;

}
void signup(){
    string name;
    string pass;
    cout << "USERNAME = ";
    getline(cin,name);
    removeTrailingSpaces(name);
    cout << "PASSWORD = ";
    getline(cin, pass);
    removeTrailingSpaces(pass);
    fstream myFile;
    myFile.open("userinfo.txt",ios::app);
    if(myFile.is_open()){
        myFile << name << "||" << pass << "||" << '0' << endl;
    }
    myFile.close();
    cout << "SUCCESFULL CREATED ACCOUNT !!\n";
    cout << "NOW RELOGIN\n";

}
int random_number(int choice,int &diff,int &chance){
    if(choice==1){
        diff=10;
        chance = 3;
    }else if(choice==2){
        diff =30;
        chance=8;
    }else{
        diff=100;
        chance = 15;
    }
    

    int num = rand() % diff + 1 ;
    return num;
}
void removeTrailingSpaces(string& s) {
    while (!s.empty() && s.back() == ' ') {
        s.pop_back();
    }
}