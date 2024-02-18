#include <iostream>
#include <string>
using namespace std;
bool isNumericConstant(string input)
{
    for(int i=0; i<input.size(); i++)
    {
        if(input[i]<'0' || input[i]>'9')
        {
            return false;
        }
        return true;
    }
}

int main()
{
    string input;
    cout << "Enter input: ";
    cin >> input;
    bool flag=true;
    if(isNumericConstant(input))
    {
        cout<<"Numeric1"<<endl;
        return 0;
    }
    int dot=0;
    int mi=0;
    for(int i=0; i<input.size(); i++)
    {
        if(input[i]=='.')
        {
            dot++;
        }
        if(input[i]=='-')
        {
            mi++;
        }
    }
    if(dot >1 || mi > 1)
    {
        cout<<"Not Numeric";
        return 0;
    }
    else
    {
        if((input[0]=='-' && mi==1) || dot==1)
        {
            string st="";
            for(int i=0; i<input.size(); i++)
            {
                if(input[i]=='.' || input[i]=='-')
                {
                    continue;
                }
                else
                {
                    st+=input[i];
                }
            }
            if(isNumericConstant(st))
            {
                cout<<"Numeric2"<<endl;
                return 0;
            }
        }
        else
        {
            cout<<"Not Numeric";
        }
    }


    return 0;
}
