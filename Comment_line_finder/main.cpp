#include <iostream>
using namespace std;
bool isCommentLineExitsFunction1(string st){
    for(int i=0;i<st.size()-1;i++){
        if(st[i]=='/' && st[i+1]=='/'){
            return true;
        }
    }
    return false;
}
bool isCommentLineExitsFunction2(string st){
    int slash=0,star=0;
    for(int i=0;i<st.size()-1;i++){
        if(st[i]=='/' && st[i+1]=='*'){
            slash++;
        }
        if(slash==1 && (st[i]=='*' && st[i+1]=='/')){
            star++;
        }
        if(slash==1 && star==1){
            return true;
        }
    }
    return false;
}

int main()
{
    string st;
    cin>>st;
    if((isCommentLineExitsFunction1(st) || isCommentLineExitsFunction2(st))){
        cout<<"Comment line Exits";
    }
    else{
        cout<<"No Comment line Exits";
    }
    return 0;
}
