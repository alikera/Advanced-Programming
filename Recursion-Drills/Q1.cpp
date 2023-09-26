#include <iostream>
using namespace std;

void reverse(string &cutted_txt, int i=0) 
{
    int len_txt = cutted_txt.length();
    if (i == len_txt / 2) 
        return;
    swap(cutted_txt[i], cutted_txt[len_txt - i - 1]);
    reverse(cutted_txt, i + 1);
} 

void encryption(string &text,int from,int to){
    if(from<to){
        string cutted_txt=text.substr(from,(to-from) + 1);
        reverse(cutted_txt);
        
        int j=0;
        for(int i=from;i<=to;i++,j++)
            text[i]=cutted_txt[j];
    }
    else
        return;

    encryption(text,from,(to+from)/2);
    encryption(text,((to+from)/2) + 1,to);
}

int main()
{
    string text;
    cin>>text;
    encryption(text,0,text.length() - 1);
    cout << text;
    return 0;
}



