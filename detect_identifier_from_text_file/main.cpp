#include <iostream>
#include <fstream>
using namespace std;
string dataTypes[] = {"function","int", "short", "long", "long long", "float", "double", "long double", "char", "wchar_t", "char16_t", "char32_t", "bool", "void"};
int sizeOfDataTypesArray = sizeof(dataTypes) / sizeof(dataTypes[0]);
void removeEqualSign(string &st)
{
    string newUpdateString1="";
    int index_number_of_equal=0;
    for(int i=0; i<st.size(); i++)
    {
        if(st[i]=='=')
        {
            index_number_of_equal=i;
            continue;
        }
        else
        {
            newUpdateString1+=st[i];
        }
    }
    string newUpdateString2="";
    if(newUpdateString1[newUpdateString1.size()-1==';'] && index_number_of_equal!=0)
    {
        for(int i=0; i<newUpdateString1.size()-1; i++)
        {
            if(i>=index_number_of_equal)
            {
                continue;
            }
            newUpdateString2+=newUpdateString1[i];
        }
        newUpdateString1=newUpdateString2;
    }
    else if(newUpdateString1[newUpdateString1.size()-1==';'])
    {
        for(int i=0; i<newUpdateString1.size(); i++)
        {
            newUpdateString2+=newUpdateString1[i];
        }
        newUpdateString1=newUpdateString2;
    }
    st=newUpdateString1;
}
bool validIdentifier(string &st)
{
    if (st.empty())
    {
        return false;
    }
    if (!((st[0] >= 'a' && st[0] <= 'z') || (st[0] >= 'A' && st[0] <= 'Z') || st[0] == '_'))
    {
        return false;
    }
    for (char c : st)
    {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || c == '_'))
        {
            return false;
        }
    }

    return true;
}
string removeDataType(string &st,int sizeOfDataTypesArray)
{
    int value=0;
    string newArray="";
    for(int i=0; i<st.size(); i++)
    {
        newArray+=st[i];
        for(int j=0; j<sizeOfDataTypesArray; j++)
        {
            if(dataTypes[j]==newArray)
            {
                value=i;
                break;
            }
        }
    }
    string finalString="";
    if(value!=0)
    {
        for(int i=0; i<st.size(); i++)
        {
            if(st[i]==' ')
            {
                continue;
            }
            if(i>value)
            {
                finalString+=st[i];
            }

        }
        st=finalString;
    }
    cout<<"identifier is : "<<st<<endl;
    return st;
}
bool isMatchDataType(string st)
{
    for(int j=0; j<st.size(); j++)
    {
        if(st==dataTypes[j]){
            return false;
        }
    }
    return true;
}

int main()
{
    ifstream MyReadFile("file.txt");
    string st;
    while(getline(MyReadFile,st)){}
    const int MAX_SUBSTRINGS = 100;
    string stringArray[MAX_SUBSTRINGS];
    string temp = "";

    int arrayIndex = 0;

    for (int i = 0; i < st.size(); i++)
    {
        if (st[i] != ';')
        {
            temp += st[i];
        }
        else
        {
            stringArray[arrayIndex++] = temp;
            temp="";
        }

        if (arrayIndex >= MAX_SUBSTRINGS)
        {
            break;
        }
    }
    if (!temp.empty() && arrayIndex < MAX_SUBSTRINGS)
    {
        stringArray[arrayIndex++] = temp;
    }

    for (int i = 0; i < arrayIndex; i++)
    {
        removeEqualSign(stringArray[i]);
        removeDataType(stringArray[i],sizeOfDataTypesArray);
        if(validIdentifier(stringArray[i])&& isMatchDataType(stringArray[i]))
        {
            cout<<1<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}
