#include<iostream>
#include<fstream>

using namespace std;

bool IsLoggedIn(){
    string userName, password, un, pw;
    cout<<"Enter Username: "; cin>>userName;
    cout<<"Enter Password: "; cin>>password;

    ifstream read("D:\\login_credentials\\" + userName + ".txt");
    getline(read, un);
    getline(read, pw);

    if(un == userName && pw == password)
        return true;
    else
        return false;
}

int main(){
    int choice;
    while(true){
        cout<<"1: Register\n2: Log-in\n3: Exit\nYour Choice:";
        cin>>choice;
        
        if(choice==1){
            string userName, password;
            cout<<"Select a Username: "; cin>>userName;
            cout<<"Select a Password: "; cin>>password;
            ofstream file;

            file.open("D:\\login_credentials\\" + userName + ".txt");
            file<<userName<<endl<<password;
            file.close();
        }
        
        else if(choice == 2){
            bool status = IsLoggedIn();

            if(status == false){
                cout<<"False Login! "<<endl;
                system("PAUSE");
                return 0;
            }
            else{
                cout<<"Successfully Logged in!"<<endl;
                system("PAUSE");
                return 1;
            }
        }

        else if(choice == 3){
            break;
        }

        else{
            cout<<"\nInvalid Choice! Choose Again!\n\n";
        }


    }
    return 0;
}
