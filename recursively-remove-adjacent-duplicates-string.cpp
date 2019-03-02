/*

https://www.tutorialcup.com/string/recursively-remove-adjacent-duplicates.htm

*/


#include <bits/stdc++.h>

using namespace std;
 
// This function recursively removes duplicates
// and returns modified string
char* removeAdjDup(char * s, int n)
{
    int i;
    int k = 0; // To store index of result
 
    // Start from second character
    for (i=1; i< n; i++)
    {
        // If the adjacent chars are different
        //then add to output string
        if (s[i-1] != s[i])
            s[k++] = s[i-1];
 
        else
            // Keep skipping (removing) characters
            // while they are same.
            while (s[i-1] == s[i])
                i++;
    }
 
    // Add last character and terminator
    s[k++] = s[i-1];
    s[k] =  '\0';
 
    // Recur for string if there were some removed
    // character
    if (k != n)
        removeAdjDup(s, k);// Shlemial Painter's Algorithm
 
    // If all characters were unique
    else return s;
}
 
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        char s[100];
        cin>>s;
        int n = strlen(s);
        cout<< removeAdjDup(s,strlen(s)) <<endl;
    }
    return 0;

    
}
    
