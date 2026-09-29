#include <bits/stdc++.h>
using namespace std;


string encrypt(string msg , int n){
    string result = "";
    
    for(int i = 0;i<msg.size();i++){
        char ch = msg[i];
        char nCh;
        if(isalpha(ch)){
            if(isupper(ch)){
                nCh = (msg[i] - 'A' + n)%26 + 'A';
            }else{
                nCh = (msg[i] - 'a' + n)%26 + 'a';
            }
            
            result += nCh;

        }else{
            result += ch;
        }
    }
    return result;
    
}


string decrypt(string msg , int n){
    string result = "";
    
    for(int i = 0;i<msg.size();i++){
        char ch = msg[i];
        char nCh;
        if(isalpha(ch)){
            if(isupper(ch)){
                nCh = (msg[i] - 'A' - n + 26)%26 + 'A';
            }else{
                nCh = (msg[i] - 'a' - n + 26)%26 + 'a';
            }
            
            result += nCh;

        }else{
            result += ch;
        }
    }
    return result;
    
}

int main() {
    string msg = "HELLO WORLD";
    
    string encrypted = encrypt(msg , 4);
    cout<<encrypted<<endl;
    
    string decrypted = decrypt(encrypted,4);
    cout<<decrypted;
	// your code goes here

}
