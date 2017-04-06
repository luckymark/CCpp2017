#include<iostream>
#include<fstream>
using namespace std;
fstream data("data.txt");
int amount,n;
struct item
{
    char name[20]={0};
    int amount=0;
};
void show(item list[]);
void add(item list[]);
void delet(item list[]);
int main()
{
    data>>amount;
    item list[amount];
    while(true)
    {
        cout<<"\npress \"1\" to show list\n      \"2\" to add items\n      \"3\" to delete items\n      \"4\" to exit\n";
        int choice; cin>>choice;
        if(choice==1) show(list);
        else if(choice==2) add(list);
        else if(choice==3) delet(list);
        else if(choice==4) break;
    }
    data.close();
    return 0;
}
void show(item list[])
{
    for(int i=0;i<amount;i++)
    {
        //data.getline(old[i].name,20); //TROUBLE HERE
        data>>list[i].name>>list[i].amount;
        cout<<i+1<<"."<<list[i].name<<":"<<list[i].amount<<endl;
    }
    cout<<"\npress \"0\" to back to menu\n";
    cin.get(); cin.get();
}
void add(item list[])
{
    for(int i=0;i<amount;i++) data>>list[i].name>>list[i].amount;
    while(true)
    {
        item newone;
        cout<<"item name:";
        cin>>newone.name;
        cout<<"item amount:";
        cin>>newone.amount;
        amount++;
        data<<amount;
        for(int i;i<amount-1;i++) data<<list[i].name<<" "<<list[i].amount<<endl;
        data<<newone.name<<" "<<newone.amount<<endl;
        cout<<"press \"1\" to continue adding\n, \"0\" to back to menu";
        cin>>n;
        if(n==0) break;
    }
    
}
void delet(item list[])
{
    while(true)
    {
        for(int i=0;i<amount;i++) data>>list[i].name>>list[i].amount;
        cout<<"input the index of the item u want to delete:";
        int n;
        cin>>n;
        for(int i=n-1;i<amount-1;i++) list[i]=list[i+1];
        amount--;
        cout<<"press \"1\" to con®tinue deleting\n, \"0\" to back to menu";
        cin>>n;
        if(n==0) break;
    }
}
