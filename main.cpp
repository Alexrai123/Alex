#include<iostream>
#include<cstring>
#include<fstream>
#include<stdlib.h>

using namespace std;

void login();
void registr();
void forgot();

int main()
{
    int ch;
    system("cls");
    cout<<"*********** MENU ***********\n";
    cout<<"1.LOG IN\n";
    cout<<"2.REGISTER\n";
    cout<<"3.FORGOT USERNAME/PASSWORD \n";
    cout<<"4.EXIT\n";
    cout<<"Enter a your choice : ";
    cin>>ch;
    switch(ch)
    {
    case 1:
        login();
        break;
    case 2:
        registr();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout<<"This program was realised by Alexandru Hudita on 28/02/2022";
        break;
    default:
        cout<<"Invalid choice\n";
        main();
    }
    return 0;
}

void login()
{
    bool ok=0;
    string user,pass,usr,pss;
    system("cls");
    cout<<"PLEASE ENTER THE FOLLLOWING\n";
    cout<<"USERNAME: ";
    cin>>user;
    cout<<"PASSWORD: ";
    cin>>pass;

    ifstream in("database.txt");
    while(in>>usr>>pss)
    {
        if(usr==user && pss==pass)
        {
            ok=1;
            system("cls");
        }
    }
    in.close();
    if(ok==1)
    {
        cout<<"LOGIN SUCCESSFUL!\nHello "<<user<<" glad you made it!\n\n";
        cin.get();
        cin.get();
        main();
    }
    else
    {
        cout<<"\nLOGIN ERROR!\nPlease check if your username and password are correct and try again!\n";
        cin.get();
        main();
    }
}

void registr()
{
    string user,pass;
    system("cls");

    cout<<"Enter an username: ";
    cin>>user;
    cout<<"\nEnter a password: ";
    cin>>pass;

    ofstream out("database.txt",ios::app);
    out<<user<<" "<<pass<<"\n";
    system("cls");
    cout<<"\nRegistration succesfull\n";
    main();
}

void forgot()
{
    int ch;
    system("cls");
    cout<<"\nWelcome to your personal assistant!";
    cout<<"\n1.Search your ID by USERNAME";
    cout<<"\n2.Search your ID by PASSWORD";
    cout<<"\n3.Main menu"<<endl;
    cout<<"Enter your choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        {
            bool ok=0;
            string look_for,user,pass;
            cout<<"Enter your username so we can look for your password: ";
            cin>>look_for;

            ifstream in("database.txt");
            while(in>>user>>pass)
            {
                if(user==look_for)
                    ok=1;
            }
            in.close();
            if(ok==1)
            {
                cout<<"We found your account :)\nYour password is: "<<pass;
                cin.get();
                cin.get();

                system("cls");
                main();
            }
            else
            {
                cout<<"Sorry about that, but we couldn't find your account :(";
                cin.get();
                main();
            }
            break;
        }
        case 2:
        {
            bool ok=0;
            string look_for,user,pass;
            cout<<"Enter your password so we can find your username: ";
            cin>>look_for;

            ifstream in("database.txt");
            while(in>>user>>pass)
            {
                if(pass==look_for)
                    ok=1;
            }
            in.close();
            if(ok==1)
            {
                cout<<"We found your account :)\nYour username is: "<<user;
                cin.get();
                cin.get();
                system("cls");
                main();
            }
            else
            {
                cout<<"Sorry about that, but we couldn't find your account :(";
                cin.get();
                main();
            }
            break;
        }
        case 3:
        {
            cout<<"Going back to main menu!";
            cin.get();
            main();
        }
        default:
        {
            cout<<"Please enter a valid choice!";
            forgot();
        }
    }
}
