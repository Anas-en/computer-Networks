#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string encrypt(string text ,int key){
    int n  = text.size();
    vector<vector<char>> arr(key , vector<char>(n,'\0'));
    // char arr[key] [n] ;
    int i =0 ,  j = 0;
    int flag = 0; //down
    while(j< n && i<key) {
        arr[i][j] =text[j];
        j++;
        if(flag == 0) {
            i++;
            if(i == key) {
                flag = 1;
                i = key - 2;
            }
        }else if (flag == 1) {
            i--;
            if(i == 0) {
                flag = 0;
            }
        }
    }
    
    string msg ="";
    for(int i = 0;i<key;i++){
        for(int j = 0;j<n;j++){
            if(arr[i][j] != '\0'){
                msg += arr[i][j];
            }
        }
    }
    return msg;
}



string decrypt(string text, int key){
    int n = text.size();

    vector<vector<char>> arr (key , vector<char>(n , '\0'));
    int i =0 ,  j = 0;
    int flag = 0; //down
    while(j< n && i<key) {
        //make the matrix using the * as the down going , thing 
        arr[i][j] ='*';
        j++;
        if(flag == 0) {
            i++;
            if(i == key) {
                flag = 1;
                i = key - 2;
            }
        }else if (flag == 1) {
            i--;
            if(i == 0) {
                flag = 0;
            }
        }
    }

    //previously we have the matrix having null character values 
    //now we have the matrix knowing where to place the values , now read along
    //the row and place the values , where the star is there
    int k = 0;
    for(int i = 0;i<key;i++){
        for(int j =0 ; j<n;j++){
            if(arr[i][j] == '*'){
                arr[i][j] = text[k];
                k++;
                // cout<<text[j]<<" ";
            }
        }
    }

    string decrypt = "";
    i =0 ,  j = 0;
    flag = 0; //down
    while(j< n && i<key) {
        //make the matrix using the * as the down going , thing 
        decrypt += arr[i][j];
        j++;
        if(flag == 0) {
            i++;
            if(i == key) {
                flag = 1;
                i = key - 2;
            }
        }else if (flag == 1) {
            i--;
            if(i == 0) {
                flag = 0;
            }
        }
    }

    return decrypt;

}
int main(){
    cout<<encrypt("computer",3)<<endl;
    string encrypted = encrypt("computer" ,3);
    cout<< decrypt(encrypted , 3);
    return 0;
}