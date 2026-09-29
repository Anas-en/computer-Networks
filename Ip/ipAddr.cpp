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


vector<int> ipParser(string ip){

    int cntO = 0;    
    vector<int> ipOctects = {};
    string octect = "";
    int cntDot = 0 , n = ip.size();

    for(int i = 0;i<n;i++){
        if(ip[i] != '.'){
            octect += ip[i];
        }else if (cntDot != 3 && ip[i] == '.'){
            cntDot++;
            int n = stoi(octect);
            ipOctects.push_back(n);
            octect = "";
        }

        if(i == n-1){
            int n = stoi(octect);
            ipOctects.push_back(n);
        }
    }

    return ipOctects;
} 


vector<int> maskOctects (string mask){
    
    vector<int>result; 
    for(int i = 0;i<32 ; i+=8){
        string part = mask.substr(i,8);
        bitset<8> b(part);
        unsigned long num = b.to_ulong();
        result.push_back(num);
    }
    
    return result;
}


vector<int> calcFirstAddr(vector<int> maskOct ,vector<int> ipAddr ){
    vector<int> result;
    for(int i = 0;i<4;i++){
        int a = maskOct[i];
        int b = ipAddr[i];
        
        int r = (a&b);
        
        result.push_back(r);
    }
    
    return result;
}

vector<int> calcLastAddr(vector<int> maskOct , vector<int> ipAddr){
    vector<int> network = calcFirstAddr(maskOct , ipAddr);
    vector<int> result;
    
    for(int i= 0;i<4;i++){
        uint8_t a = maskOct[i];
        uint8_t b = network[i];
        
        uint8_t r = b | (~a);
        
        result.push_back(r);
    }
    
    return result;
    
}


int main() {
	// your code goes here
	
	string ip ="122.15.16.159";
    
    string mask = "11111111111111111111111111110000";


    int NetId,hostId;
    NetId = netIdCalculate(mask);
    hostId = 32-NetId;
    
    
    int nAddr = pow(2,hostId);  

    
    vector<int> ipAddr = ipParser(ip);
    vector<int> maskAddr = maskOctects(mask);
    
    
    
    vector<int> faddr = calcFirstAddr(maskAddr , ipAddr);
    vector<int> laddr = calcLastAddr(maskAddr , ipAddr);
    
    cout<<"No. of Addr: 2^"<<hostId<<" = "<<nAddr<<endl;
    
    cout << "faddr: "<<endl;
    for(auto it: faddr){
        cout<<it<<".";
    }
    cout<<endl;
    
    
    cout<<"Last addr: "<<endl;
    for(auto it:laddr){
        cout<<it<<".";
    }
    
   
    
}
