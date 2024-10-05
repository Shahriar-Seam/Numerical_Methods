#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1,s2,s3;
    cout << "Enter 1st equation : ";
    cin >> s1;
    cout << "Enter 2nd equation : ";
    cin >> s2;
    cout << "Enter 3rd equation : ";
    cin >> s3;
    int a1=0,b1=0,c1=0,d1=0;
    for(int i=0;i<s1.length(); )
    {
        int num=0;
        int sign=1;
        if(s1[i]=='-')
        {
            sign=-1;
            i++;
        }
        while(isdigit(s1[i])&& i < s1.length())
        {
            num=num*10;
            num=num+(s1[i]-'0');
            i++;
        }
        num=num*sign;
        if(a1==0){
            a1=num;
        }
        else if(b1==0){
            b1=num;
        }
        else if(c1==0){
            c1=num;
        }
        else{
            d1=num;
        }

        while (!isdigit(s1[i]) && i < s1.length()) {
            i++;
        }
    }


    int a2=0,b2=0,c2=0,d2=0;
    for(int i=0;i<s2.length();i++)
    {
        int num=0;
        int sign=1;
        if(s2[i]=='-')
        {
            sign=-1;
        }
        while(isdigit(s2[i])&&s2[i]<s2.length())
        {
            num=num*10;
            num=num+(s2[i]-'0');
            i++;
        }
        num=num*sign;
        if(a2==0){
            a2=num;
        }
        else if(b2==0){
            b2=num;
        }
        else if(c2==0){
            c2=num;
        }
        else{
            d2=num;
        }
    }

    int a3=0,b3=0,c3=0,d3=0;
    for(int i=0;i<s3.length();i++)
    {
        int num=0;
        int sign=1;
        if(s3[i]=='-')
        {
            sign=-1;
        }
        while(isdigit(s3[i])&&s1[i]<s3.length())
        {
            num=num*10;
            num=num+(s3[i]-'0');
            i++;
        }
        num=num*sign;
        if(a3==0){
            a3=num;
        }
        else if(b3==0){
            b3=num;
        }
        else if(c3==0){
            c3=num;
        }
        else{
            d3=num;
        }
    }

    cout << a1 << " " << b1 << " " << c1 << " " << d1 << "\n";
    cout << a2 << " " << b2 << " " << c2 << " " << d2 << "\n";
    cout << a3 << " " << b3 << " " << c3 << " " << d3 << "\n";


    // Row 2 = Row 2 - (a2/a1) * Row 1
    double factor = a2 / (double)a1;
    a2 -= factor * a1;
    b2 -= factor * b1;
    c2 -= factor * c1;
    d2 -= factor * d1;

    // Row 3 = Row 3 - (a3/a1) * Row 1
    factor = a3 / (double)a1;
    a3 -= factor * a1;
    b3 -= factor * b1;
    c3 -= factor * c1;
    d3 -= factor * d1;

    // Row 3 = Row 3 - (b3/b2) * Row 2 (to eliminate y from Row 3)
    factor = b3 / (double)b2;
    b3 -= factor * b2;
    c3 -= factor * c2;
    d3 -= factor * d2;

    // Back Substitution
    double z = d3 / (double)c3;  // Solve for z
    double y = (d2 - c2 * z) / (double)b2;  // Solve for y
    double x = (d1 - b1 * y - c1 * z) / (double)a1;  // Solve for x


    cout << "Solution: x = " << x << ", y = " << y << ", z = " << z << endl;

    return 0;
}