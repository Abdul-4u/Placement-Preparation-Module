class Solution {
public:
    bool isValid(string s) {
        	stack<char> stk;
	bool ans = true;
	
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(' or s[i]== '{' or s[i]== '[')
		{
			stk.push(s[i]);
		}
		else 
		{
				if (!stk.empty() and s[i] == ')')
				{
					if (stk.top() == '(') { stk.pop(); }
					else { ans = false; break; }
				}
				
				else if (!stk.empty() and s[i] == '}')
				{
					if (stk.top() == '{') { stk.pop(); }
					else { ans = false; break;}
				}
				else if (!stk.empty() and s[i] == ']')
				{
					if (stk.top() == '[') { stk.pop(); }
					else { ans = false; break; }
				}
				else {
					cout << "Stack is empty\n";
					ans = false;
				}

		}
	}
	if (!stk.empty()) {return false;}
	else { return ans; }

    }
};