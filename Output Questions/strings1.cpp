#include<iostream>
using namespace std;
int main() {
     char str1[] = "CodingChapter";
     char str2[] = {'C','o','d','i','n','g','C','h','a','p','t','e','r'};
     cout<<str1[0]<<" "<<str2[0]<<endl; // C C
     int n1 = sizeof(str1)/sizeof(str1[0]);
     int n2 = sizeof(str2)/sizeof(str2[0]);
     cout<<"n1= "<<n1<<" n2= "<<n2<<endl; // 14 13
     return 0;

 }