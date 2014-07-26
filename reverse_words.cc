#include<iostream>
#include<string>
#include<cctype>

using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		string str;
		bool sh = false;
		
		string::iterator it = s.begin();
		while(isspace(*it) && it != s.end()) {
            		++it;
			continue;
        	}
        	
		for(; it != s.end(); ++it) {
			if(isspace(*it)) {
				sh = true;
				continue;
			}
			
			if(sh && (it != s.end()-1)) {
				sh = false;
				str.push_back(' ');
			}
			
			sh = false;
			str.push_back(*it);
		}
		rsvw(str);
		s = str;
	}
	
    void rsvw(string &s) {
     int begin = -1;
     int end = -1;
     
     int length = s.size();
     for(int i = 0; i < length; ++i) {
        if(-1 == begin && ' ' == s.at(i)) {
            continue;
        }
        if(-1 == begin) {
            begin = i;
            continue;
        }
        
        if(' ' == s.at(i))
            end = i - 1;
        else if(i == length - 1)
            end = i;
        else
            continue;
        Swap(s, begin, end);
        begin = -1;
        end = -1;
     }
     Swap(s, 0, length-1);
    }
    
    void Swap(string& str, int b, int e) {
        while(b < e) {
            char t = str[b];
            str[b] = str[e];
            str[e] = t;
            ++b;
            --e;
        }
    }
};

int main() {
    string a("  2  1   3  jfie  fie 3 3fji j98f3   jie jfij 983jr983fjdioejoi cvijjfij eiofjioef  f   ");
    Solution sl;
    sl.reverseWords(a);
    cout << "sl: $" << a.c_str() << "$" << endl;
    return 0;
}
