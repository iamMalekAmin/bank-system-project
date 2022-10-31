
#include<cstdlib>

#include<string.h>

using namespace std;

struct bank{
    char name[10];
    char numadr[];
    char stadr[];
    char zyada[];
    char niadr[];
    char cityadr[10];
    char trant[10];
    int tran[10];
};

void balance (bank arr1[20],float arr2[20],int q1,int q2){
    if (arr1[q1].trant[q2]=='d')
        arr2[q1]+=arr1[q1].tran[q2];
    else if (arr1[q1].trant[q2]=='w')
        arr2[q1]-=arr1[q1].tran[q2];
}
int main()
{
    int n,choose,a,b,c,f,l,ch;
    int i=0,cityin=0,h=0,maxi=0;
    char name[10],want[4],r[10];
    cout << "es7aaa linaaaaaa... e7na ginaaaaaaaaa \n";
    cout<<"      -Enter number of customers..!!-      "<<endl;
    cin>>n;
    if(n<=20&&n>0){
        bank x[n];
        float balancey[n];
        for(int d=0;d<n;d++)
            balancey[d]=1000;
        while(i<n){
            int trann=0;
            cout<<"-Please enter name of "<<i+1<<" customer"<<endl;
            cin>>x[i].name;
            cout<<"-Please enter address"<<endl;
            cin>>x[i].numadr>>x[i].stadr>>x[i].zyada>>x[i].niadr>>x[i].cityadr;
            cout<<"how many transactions do you want to do :"<<endl;
            cin>>trann;
            cout<<"Please enter"<<x[i].name<<"’s account transactions"<<endl;
            for(int d=0;d<trann;d++){
                cin>>x[i].trant[d]>>x[i].tran[d];
                if(x[i].tran[d]<0){
                    cout<<"please enter valid transaction"<<endl;
                    cin>>x[i].trant[d]>>x[i].tran[d];
                }
                balance(x,balancey,i,d);
            }


            i++;
        }
        while(h<20){
            int trann=0;
            cout<<" -Hello in bank management system please enter your choice"<<endl;
            cout<<" -(1) To print all names and account balances"<<endl;
            cout<<" -(2) To print specific customer's account balance"<<endl;
            cout<<" -(3) To edit customer transactions"<<endl;
            cout<<" -(4) To show customer with highest balance"<<endl;
            cout<<" -(5) To change customer's name, transactions, balance, or address"<<endl;
            cout<<" -(6) To show how many customers in one city"<<endl;
            cin>>choose;
            if( choose == 1){
                for(int d=0;d<n;d++){
                    cout<<x[d].name<<"      "<<balancey[d]<<endl;
                }
            }
            else if( choose == 2){
                cout<<"please enter name of customer"<<endl;
                cin>>name;
                for(int d=0;d<n;d++){
                    //l=strcmp(x[d].name,name);
                    if(strcmp(x[d].name,name) == 0){
                        cout<<"this customer balance = "<<balancey[d]<<endl;
                    }
                }
            }
            else if( choose == 3){
                cout<<"Please enter name of customer you want to edit"<<endl;
                cin>>name;
                for(int d=0;d<n;d++){
                    f=strcmp(x[d].name,name);
                    if(f == 0){
                        cout<<"how many transactions do you want to do :"<<endl;
                        cin>>trann;
                        cout<<"Please enter "<<x[d].name<<"’s account transactions"<<endl;
                        for(int y=0;y<trann;y++){
                            cin>>x[d].trant[y]>>x[d].tran[y];
                            if(x[d].tran[y]<0){
                                cout<<"please enter valid transaction"<<endl;
                                cin>>x[d].trant[y]>>x[d].tran[y];
                            }
                            balance(x,balancey,d,y);
                        }
                    }
                }
              }
            else if( choose == 4){
                    for(int i=0;i<n;i++){
                        if(balancey[i]>maxi)
                            maxi=balancey[i];
                    }
                    for(int d=0;d<n;d++){
                        if(maxi == balancey[d])
                            cout<<"-The Customer who have highest balance is  "<<"    "<<x[d].name<<" with  "<<balancey[d]<<endl;
                    }
            }
            else if( choose == 5){
                cout<<"-please enter name the customer who want to change"<<endl;
                cin>>name;
                for(int d=0;d<n;d++){
                   b=strcmp(x[d].name,name);
                    if(b == 0){
                        cout<<" -chose 1 to change name "<<endl;
                        cout<<" -chose 2 to change transactions "<<endl;
                        cout<<" -chose 3 to change balance "<<endl;
                        cout<<" -chose 4 to change address "<<endl;
                        cin>>ch;
                        switch (ch)
                        {
                    case 1 :

                            cout<<"-please enter new customer name "<<endl;
                            cin>>x[d].name;
                            break;

                    case 2 :
                            cout<<"-How many transactions do you wanna do :"<<endl;
                            cin>>trann;
                            cout<<"-Please enter new "<<x[d].name<<"’s account transactions"<<endl;
                            for(int v=0;v<trann;v++){
                                   cin>>x[d].trant[v]>>x[d].tran[v];
                                   if(x[d].tran[v]<0){
                                        cout<<" -please enter valid transaction"<<endl;
                                        cin>>x[d].trant[v]>>x[d].tran[v];
                                   }
                                   balance(x,balancey,d,v);
                            }
                            break;

                    case 3 :

                            cout<<"-please enter new balance "<<endl;
                            cin>>balancey[d];
                            break;

                    case 4 :

                            cout<<"-please enter new customer's address "<<endl;
                            cin>>x[d].numadr>>x[d].stadr>>x[d].zyada>>x[d].niadr>>x[d].cityadr;
                            break;
                }
                         //5 omarn street, dokki, giza
                    }
                }
            }
            else if(choose == 6){
                cityin=0;
                cout<<"-please enter name of city which you need"<<endl;
                cin>>r;
                for(int d=0;d<n;d++){
                    c=strcmp(x[d].cityadr,r);
                    if(c == 0){
                        cityin+=1;
                }
                }
                cout<<"-number  of   customer who from "<<r<<"="<<" "<<cityin<<endl;
            }
            else{
                cout<<"-please choose from options"<<endl;
                continue;
            }
            cout<<"-do you want other option"<<endl;
            cin>>want;
            a=strcmp(want,"yes");
            if(a==0){
                h++;
            }
            else
                break;
        }

    }
    return 0;

}
