#include<iostream>
#include <bits/stdc++.h>

using namespace std;


int netIdCalculate(string mask){
    int netId = 0;
    for(int i = 0;i<mask.size();i++){
        if(mask[i] == '1'){
            netId++;
            // cout<<"1";
        }
        else{
            break;
        }
    }
    return netId;
}

string firstaddr(int netId , vector<string> ipOctects){
    
    string faddr = "";
    int fullOctets = netId / 8;

    int leftOctect = 4 - fullOctets;
    int extraLeftBits  = netId % 8;
    
    int n = ipOctects.size();
    
    for(int i= 0;i<fullOctets;i++){
        faddr += ipOctects[i];
        if( i != n-1 ){
            faddr +=".";
        }
    }
    
    
    return faddr;
 
}

vector<string> ipParser(string ip){

    int cntO = 0;    
    vector<string> ipOctects = {};
    string octect = "";
    int cntDot = 0 , n = ip.size();

    for(int i = 0;i<n;i++){
        if(ip[i] != '.'){
            octect += ip[i];
        }else if (cntDot != 3 && ip[i] == '.'){
            cntDot++;
            ipOctects.push_back(octect);
            octect = "";
        }

        if(i == n-1){
            ipOctects.push_back(octect);
        }
    }

    return ipOctects;
} 


int main(){


    string ip ="122.15.16.159";
    
    string mask = "11111111111111111111111111110000";

    int NetId,hostId;
    NetId = netIdCalculate(mask);
    hostId = 32-NetId;



    int nAddr = pow(2,hostId);  

    cout<<"Total allocated Addr = ";
    cout<<"2^"<<hostId<<"="<<nAddr <<endl;
    cout<<"hostId = "<<hostId<<endl;



    return  0;
}