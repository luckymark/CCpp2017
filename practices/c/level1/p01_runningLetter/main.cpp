#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
int main()
{
    //char word[] = "♂";
    char word[] = "hahahahah";
    int word_length = strlen(word);
    for(int i = 0; i < 50; ++i)
    {

        for(int j = 0; j < 10000000; ++j);
        for(int j = 0; j < word_length; ++j)
            cout<<"\b";
        cout<<" "<<word;
    }
    return 0;
}