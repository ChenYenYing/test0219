#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("data1.txt","r",stdin);     //open file
    int epoch= 1,stop= 0,time= 0,k= 0,a[2], e[2];   //a=w*p+b, e=error
    double learn_rate=1;   //learning rate
    double w[2][2]={1,0,0,1},b[2]={1,1};   //w=weight, b=bias
    int p[8][2],t[8][2],tp[4][2];   //p=training pattern,t=target,
                                    //tp=testing pattern
    cout<<"(a)-1  Two-neuron perceptron, Dataset 1"<<endl<<endl;
    //print output of initial value
    cout<<"---initial data value---\n"<<endl;
    cout<<"Weight=\n";
        for(int i= 0;i< 2; i++){
            for(int j= 0;j< 2; j++){
                if(j==0){
                    cout<<"        ";
                }
            cout<<w[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"bias=\n";
        for(int i= 0;i< 2; i++){
            cout<<"      "<<b[i]<<endl;
        }
        cout<<endl;
    //training_data input
    cout<<"--training_data--\n"<<endl;
    for(int i= 0;i< 8; i++){
        for(int j= 0;j< 2; j++){
        //training pattern for i and neural inputs for j
            cin>>p[i][j];
        }
        for(int j= 0;j< 2; j++){
        //target value_j of pattern_i
            cin>>t[i][j];
        }
    }
    for(int i=0;i< 4; i++){
        for(int j= 0;j< 2; j++){
        //testing data pattern_i and neural inputs for j
            cin>>tp[i][j];
        }
    }

    //test
    while(time< 50000000){
        //hard limit(w*p+b)
        for(int i= 0;i< 2; i++){
            //a[i]=w * pattern_k + bias
            a[i]=0;
            for(int j= 0;j< 2; j++){
                a[i]+=w[i][j]*p[k][j];
            }
            a[i]+=b[i];
            //hard limit function of a[i]
            if(a[i]<0){
                a[i]=0;
            }else if(a[i]>=0){
                a[i]=1;
            }
        }

        int change=0;          //set change=0
        for(int i= 0;i< 2; i++){
            //error=target-a
            e[i]=t[k][i]-a[i];
            //if error=0, don't change w and b
            //else if error!=0, change w and b
            if(e[i]!=0){
                change=1;
            }
        }
        if(change==1){
            for(int i= 0;i< 2; i++){
                for(int j= 0;j< 2; j++){
                //update new weight
                //W_new=W_old+ learning_rate*(error * pattern)
                    w[i][j]=w[i][j]+learn_rate*(e[i]*p[k][j]);
                }
            }
            for(int i= 0;i< 2; i++){
                //update new bias
                //b_new = b_old + learning_rate * error
                b[i]+=learn_rate*e[i];
            }
            stop++; //count change_times
        }
        k++;    //count pattern
        if(k >= 8){     //there are 8 patterns in total
            k=0;        //k set 0
            if(stop==0){    //no change(end of epoch)
                break;
            }else{
                stop=0;     //set stop = 0
            }
            epoch++;    //count epoch
        }
        time++;
    }

    //if proper decision boundaries are not found,
    //display maximum epoch(50000)
    if(epoch>=50000){
        cout<<"not found,maximum is 50000(epoch)!!\n"<<endl;
        cout<<"Recurrent value:"<<endl;
        cout<<"Weight=\n";
        for(int i= 0;i< 2; i++){
            for(int j= 0;j< 2; j++){
                if(j==0){
                    cout<<"        ";
                }
            cout<<w[i][j]<<" ";
            }
             cout<<endl;
        }
        cout<<"bias=\n";
        for(int i= 0;i< 2; i++){
            cout<<"      "<<b[i]<<endl;
        }
        cout<<endl;
    }
    else{
        //print weight and bias after training
        cout<<"Weight=\n";
        for(int i= 0;i< 2; i++){
            for(int j= 0;j< 2; j++){
                if(j==0){
                    cout<<"        ";
                }
            cout<<w[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"bias=\n";
        for(int i= 0;i< 2; i++){
            cout<<"      "<<b[i]<<endl;
        }
        //print total epoch
        cout<<"epoch: "<<epoch<<endl<<endl;
    }

    //Predict the classes (target vectors) of testing examples
    cout<<"--testing_data--\n"<<endl;
    int cnt=9;
    for(int x= 0;x< 4; x++){
        for(int i= 0;i< 2; i++){
            //weight * testing_pattern + bias
            a[i]=0;     //set a = 0
            for(int j= 0;j< 2; j++){
                a[i]+=w[i][j]*tp[x][j];
            }
            a[i]+=b[i];
            //a in hard limit function
            if(a[i]<0){
                a[i]=0;
            }else if(a[i]>=0){
                a[i]=1;
            }
        }
        //print target vectors of patterns
        cout<<"-Target vector of p"<<cnt<<" = ["<<a[0]<<" "<<a[1]<<"]t"<<endl;
        cnt++;
    }
    return 0;
}


