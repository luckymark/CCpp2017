#ifndef CL_STUDENT_H
#define CL_STUDENT_H

using namespace std;
class Student
{
    protected:
        struct node
        {
            char name[10]={0};
            char number[10]={0};
            int score=0;
            node* next=NULL;
        };
        node *head,*tail,*last;
        int len,n,count=0;
        string file;
    public:
        Student(string name)
        {
            head=new node;
            last=new node;
            head->next=last;
            tail=head;
            //read
            file=name;
            ifstream data(name);
            int n; data>>n;
            for(int i=0;i<n;i++)
            {
                node* add=new node;
                data>>add->number;
                data>>add->name;
                data>>add->score;
                tail->next=add;
                tail=add;
                tail->next=last;
                count++;
            }
            data.close();
        }
        ~Student()
        {
            ofstream data(file);
            data<<count<<endl;
            for(node* i=head->next;i!=last;i=i->next)
                data<<i->number<<" "<<i->name<<" "<<i->score<<endl;
            data.close();
            while(count!=0)
            {
                node* temp=head;
                head->next=head->next->next;
                delete temp;
                count--;
            }
            delete head;
            delete last;
        }
        void menu()
        {
            while(true)
            {
                //system("cls");
                cout<<"\npress 1 to show students list\n"
                    <<"      2 to add students\n"
                    <<"      3 to enter scores\n"
                    <<"      4 to delete student\n"
                    <<"      0 to quit\n";
                cin>>n;
                if(n==1) show();
                else if(n==2) add();
                else if(n==3) score();
                else if(n==4) remove();
                else return;
            }
        }
        void show()
        {
            begin:
            if(count==0)
            {
                cout<<"no student in this list\n";
                return;
            }
            for(node* i=head;i!=last;i=i->next)
            {
                cout<<i->number<<" "<<i->name;
                if(i->score!=0) cout<<" "<<i->score;
                cout<<endl;
            }
            cout<<"press 0 to finish.\n";
            cin>>n;
            return;
        }
        void add()
        {
            addAgain:
            node* add=new node;
            cout<<"enter student name:";
            cin>>add->name;
            cout<<"enter student number:";
            cin>>add->number;
            tail->next=add;
            tail=add;
            tail->next=last;
            count++;
            cout<<"press 1 to continue, 0 to finish.\n";
            cin>>n;
            if(n==1) goto addAgain;
            return;
        }
        node* find()
        {
            node *i, *bi;
            char find[10]={0};
            int findlen;
            cout<<"enter student name or student number:";
            cin>>find;
            findlen=strlen(find);
            int j=0;
            for(bi=head;bi->next!=last;bi=bi->next)
            {
                i=bi->next;
                while(find[j]==i->name[j] and j<findlen)
                    j++;
                if(j==findlen) break;
                j=0;
                while(find[j]==i->number[j] and j<findlen)
                    j++;
                if(j==findlen) break;
            }
            if(j==findlen)
            {
                cout<<i->number<<" "<<i->name;
                if(i->score!=0) cout<<" "<<i->score;
                cout<<endl;
                return bi;
            }
            cout<<"no result.\n"<<endl;
            return NULL;
        }
        void remove()
        {
            if(count==0)
            {
                cout<<"no student in this list\n";
                return;
            }
            begin:
            if(node *bi=find())
            {
                cout<<"press 1 to confirm, 0 to cancel.\n";
                cin>>n;
                if(n==1)
                {
                    node *i=bi->next;
                    bi->next=i->next;
                    if(i==tail) tail=bi;
                    delete i;
                    count--;
                    cout<<"deleted.\n";
                }
                else cout<<"canceled.\n";
            }
            cout<<"press 1 to continue, 0 to finish.\n";
            cin>>n;
            if(n==1) goto begin;
            return;
        }
        void score()
        {
            if(count==0)
            {
                cout<<"no student in this list\n";
                return;
            }
            begin:
            if(node* bi=find())
            {
                node* i=bi->next;
                cout<<"set this score:";
                cin>>i->score;
                cout<<"finished.\n";
            }
            cout<<"press 1 to continue, 0 to finish.\n";
            cin>>n;
            if(n==1) goto begin;
            return;
        }
};


#endif //CL_STUDENT_H
