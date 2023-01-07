/*
Problem Title: 1410 - HTML Entity Parser
Lang: C++
Runtime: 1108 ms
Memory: 16.6 MB
Problem Url: https://leetcode.com/problems/html-entity-parser
Submission Url: https://leetcode.com/problems/html-entity-parser/submissions/323581460
*/

class Solution {
public:
    string entityParser(string text) {
        
        map<string, string> mp;
        mp.insert({"&quot;", "\""});
        mp.insert({"&apos;", "'"});
        mp.insert({"&amp;", "&"});
        mp.insert({"&gt;", ">"});
        mp.insert({"&lt;", "<"});
        mp.insert({"&frasl;", "/"});
        
        
        for(int i = 0; i < text.size(); i++){
            
            if(text[i] == '&'){
                
                
                size_t pos = text.find(";", i);
                
                if(pos != string::npos && (pos - i == 3 or pos - i == 4 or pos - i == 5 or pos - i == 6)){
                    
                    //cout<<pos-i<<" Hello "<<text.substr(i,4)<<endl;
                    
                    if(pos-i == 3 and text.substr(i,4)  == "&gt;"){
                        text.replace(i, 4, mp["&gt;"]);
                        // i -= 3;
                    }
                    else if(pos-i == 3 and text.substr(i,4)  == "&lt;"){
                        text.replace(i, 4, mp["&lt;"]);
                        // i -= 3;
                    }
                    else if(pos-i == 5 and text.substr(i,6)  == "&quot;"){
                        text.replace(i, 6, mp["&quot;"]);
                        // i -= 5;
                    }
                    else if(pos-i == 5 and text.substr(i,6)  == "&apos;"){
                        text.replace(i, 6, mp["&apos;"]);
                        // i -= 5;
                    }
                    else if(pos-i == 4 and text.substr(i,5)  == "&amp;"){
                        text.replace(i, 5, mp["&amp;"]);
                        // i -= 4;
                    }
                    else if(pos-i == 6 and text.substr(i,7)  == "&frasl;"){
                        text.replace(i, 7, mp["&frasl;"]);
                        // i -= 6;
                    }
                    
                    
                }
                
                
                
            }
            
            
        }
        
        return text;
    }
};