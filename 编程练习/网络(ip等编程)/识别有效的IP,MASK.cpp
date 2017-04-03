#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std; 
vector<string> split(string str, char del){ 
	stringstream ss(str); string tok;    
    vector<string> ret;  
 	while(getline(ss, tok, del))
    	 ret.push_back(tok);  
	return ret;
}
bool IPisvalid(vector<string> svec){  
    if(svec.size() != 4)  
        return false;   
    return true;
}
bool Maskisvalid(vector<string> svec){ 
    bool zero = false;  
    if(svec.size() != 4)
        return false;   
    for(int i = 0; i < 4; i++){ 
        if(zero == false){    
            if(atoi(svec[i].c_str()) != 255){  
                if(atoi(svec[i].c_str()) != 0 &&     
                   atoi(svec[i].c_str()) != 128 &&      
                   atoi(svec[i].c_str()) != 192 &&      
                   atoi(svec[i].c_str()) != 224 &&       
                   atoi(svec[i].c_str()) != 240 &&       
                   atoi(svec[i].c_str()) != 248 &&       
                   atoi(svec[i].c_str()) != 252 &&       
                   atoi(svec[i].c_str()) != 254){       
                    return false;             
                }
                else{               
                    zero = true;    
                }         
            }      
        }
        else{     
            if(atoi(svec[i].c_str()) != 0){     
                return false;          
            }      
        }   
    }    
    if(atoi(svec[3].c_str()) == 255){   //即255.255.255.255位错误掩码
        return false; 
    } 
    return true;
}
int main(){ 
    vector<int> ret(7, 0);  
    string str;  
    vector<string> svec,ip,mask;
    while(getline(cin, str)){  
        svec = split(str, '~');       //分成ip,mask
        ip = split(svec[0], '.');     //分成4个字段
        mask = split(svec[1], '.'); 
        if(Maskisvalid(mask) && IPisvalid(ip)){    
            if (atoi(ip[0].c_str()) >= 1 && atoi(ip[0].c_str()) <= 126){  
                ++ret[0];              
                if (atoi(ip[0].c_str()) == 10)   
                    ++ret[6];        
            }
            else if (atoi(ip[0].c_str()) >= 128 && atoi(ip[0].c_str()) <= 191){  
                ++ret[1];               
                if (atoi(ip[0].c_str()) == 172){        
                    if (atoi(ip[1].c_str()) >= 16 && atoi(ip[1].c_str()) <= 31)   
                        ++ret[6];              
                }         
            }          
            else if (atoi(ip[0].c_str()) >= 192 && atoi(ip[0].c_str()) <= 223){   
                ++ret[2];              
                if (atoi(ip[0].c_str()) == 168)      
                    ++ret[6];          
            }        
            else if (atoi(ip[0].c_str()) >= 224 && atoi(ip[0].c_str()) <= 239){  
                ++ret[3];           
            }          
            else if (atoi(ip[0].c_str()) >= 240 && atoi(ip[0].c_str()) <= 255){     
                ++ret[4];         
            }       
        }else{      
            ret[5]++;    
        }   
    }    
    cout << ret[0] << " " << ret[1] << " " << ret[2] << " " << ret[3] << " " << ret[4] << " " << ret[5] << " "<< ret[6] << endl;  
    return 0;
}