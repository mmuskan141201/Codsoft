#include<iostream>
 #include<cstdlib>
 #include<ctime>
 using namespace std;
 int main() 
 {
    int num=0;
    int guess=0;
    int t=0;
    srand(time(0));
    num=rand() % 100+1;
    cout<<"--------------NUMBER GUESSING GAME---------------"<<endl;
    cout<<"       --------------WELCOME----------------"<<endl;
    do
    {
     cout<<"guess a random number between 1 and 100:";
     cin>>guess;
     t++;

    if (guess > num)
     cout<<"too high!!\n try again \n";
     else if (guess < num)
     cout<<"too low!!\n try again \n";
     else
     cout<<"\n correct!! \n you got it!!"<< t <<"guesses!\n";
    } 
    while (guess != num);
    return 0;
   
 }
