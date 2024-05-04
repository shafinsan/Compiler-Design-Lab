#include <iostream>
#include <string>
#include <fstream>
using namespace std;
ofstream outputFile;
bool isPunctuator(char ch)
{
    string punctuators = " +-*/,;><=()[]{}&|";
    for (char p : punctuators)
    {
        if (ch == p)
            return true;
    }
    return false;
}

bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

bool validIdentifier(const string& str)
{
    if (str.empty() || isDigit(str[0]) || isPunctuator(str[0]))
    {
        return false;
    }
    //modern compiler support auto forloop,if you want,you can use regular for or while loop;
    for (char c : str)
    {
        if (isPunctuator(c))
        {
            return false;
        }

    }
    return true;
}

bool isOperator(char ch)
{
    string operators = "+-*/><=&|";
    for (char op : operators)
    {
        if (ch == op)
            return true;
    }
    return false;
}

bool compareStrings(const string str1, const string str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }

    for (size_t i = 0; i < str1.size(); ++i)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }

    }
    return true;
}

bool isKeyword(const string& str)
{
    string keywords[] = {"if", "else", "while", "do", "break", "continue", "int", "double",
                         "float", "return", "char", "case", "long", "short", "typedef", "switch",
                         "unsigned", "void", "static", "struct", "sizeof", "volatile", "typedef",
                         "enum", "const", "union", "extern", "bool"
                        };
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++)
    {
        if (compareStrings(str, keywords[i]))
            return true;
    }
    return false;
}

bool isNumber(const string& str)
{
    if (str.empty())
    {
        return false;
    }
    bool hasDecimal = false;
    for (char c : str)
    {
        if (!isDigit(c))
        {
            if (c == '.')
            {
                if (hasDecimal)
                {
                    return false;
                }

                hasDecimal = true;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}

void mainLogic(const string& str)
{
    string sub;
    for (char c : str)
    {
        if (isPunctuator(c))
        {
            if (!sub.empty())
            {
                if (isKeyword(sub))
                {
                    outputFile << sub << "\n";
                }

                else if (isNumber(sub))
                {
                    outputFile << sub << "\n";
                }

                else if (validIdentifier(sub))
                {
                    outputFile << sub << "\n";
                }

                else
                {
                    outputFile << sub << "\n";
                }

                sub.clear();
            }
            if (isOperator(c))
                outputFile << c << "\n";
        }
        else
        {
            if (c != ' ' && c != '\t')   // Skip adding spaces and tabs
            {
                sub += c;
            }
        }
    }
    if (!sub.empty())
    {
        if (isKeyword(sub))
        {
            outputFile << sub << "\n";
        }

        else if (isNumber(sub))
        {
            outputFile << sub << "\n";
        }

        else if (validIdentifier(sub))
        {
            outputFile << sub << "\n";
        }

        else
        {
            outputFile << sub << "\n";
        }

    }
}
string readFileToString(const string& filename)
{
    ifstream file(filename);
    string content;
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            content += line;
        }
        file.close();
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
    }
    return content;
}

int main()
{
    outputFile.open("store.txt");
    string filename = "lex_input.txt";
    string fileContent = readFileToString(filename);
    if (fileContent.empty())
    {
        cerr << "Error: Failed to read input file." << endl;
        return 1;
    }
    mainLogic(fileContent);
    outputFile.close();
    cout << "Analysis results saved in store.txt" << endl;
    return 0;
}
