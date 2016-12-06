/*Program to test if a word is a palindrome
using stack and queue
Nov. 2016
By Christopher Muench
C++ (MinGW G++ compiler)
*/
#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main(void){
    //variables necessary
    char word[45];
    int iterate = 0;
    int charCount = 0;
    char charStack;
    char charQueue;
    int sizeQ = 0;
    int sizeS = 0;

    stack <char> palStack;  //initialize stack to hold characters
    queue <char> palQueue;  //initialize queue to hold characters

    cout <<"Enter characters of the word you would like to test,"<<endl
    <<"Enter '!' when finished: ";

    while (word[iterate - 1] != '!') //get word and fill stack and queue with word
    {
        cin >>word[iterate];
        word[iterate] = tolower(word[iterate]);
        if (word[iterate] != '!')
        {
            palStack.push(word[iterate]); //push char to stack
            palQueue.push(word[iterate]); //push char to queue
            charCount++;
        }
        iterate++;
    }

    sizeQ = palQueue.size(); //assign size of containers to variables
    sizeS = palStack.size();

    charStack = palStack.top(); //assign top values of containers to variables
    charQueue = palQueue.front();


    while (charStack == charQueue && sizeQ != 0) //enter loop to pop equivalent characters
    {
        palQueue.pop();
        palStack.pop();
        sizeQ = palQueue.size();
        sizeS = palStack.size();
    }

    if (sizeQ == 0 && sizeS == 0) //if all chars are popped word = palindrome
    {
        cout <<"Word is Palindrome."<<endl;
    }

    else
    {
        cout <<"Word is not Palindrome."<<endl;
    }



return 0;
}
