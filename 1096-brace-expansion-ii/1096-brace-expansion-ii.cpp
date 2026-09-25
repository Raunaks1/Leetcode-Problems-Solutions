class Solution {
public:
	unordered_set<string> combine(unordered_set<string>& set1, unordered_set<string>& set2)
	{
		unordered_set<string> res;
		for(auto& x:set1)
		{
			res.insert(x);
		}
		for(auto& x:set2)
		{
			res.insert(x);
		}

		return res;
	}

	unordered_set<string> crossProduct(unordered_set<string>& set1, unordered_set<string>& set2)
	{
		unordered_set<string> res;
		if(set1.empty())
		{
			set1.insert("");
		}

		for(auto& a:set1)
		{
			for(auto& b:set2)
			{
				res.insert(a+b);
			}
		}

		return res;
	}
	vector<string> braceExpansionII(string expression) {
		stack<unordered_set<string>> StackStr;
		stack<int> StackOp;
		unordered_set<string> cur;
		string S="";
		for(int i=0;i<expression.size();i++)
		{
			if(expression[i]>='a' && expression[i]<='z')
			{
				S+='{';
				S+=expression[i];
				S+='}';
			}
			else
			{
				S+=expression[i];
			}
		}

		for(int i=0;i<S.size();i++)
		{
			if(S[i]=='{')
			{
				StackStr.push(cur);
				StackOp.push(0);
				cur={};
			}
			else if(S[i]==',')
			{
				StackStr.push(cur);
				StackOp.push(1);
				cur={};
			}
			else if(S[i]=='}')
			{
				while(StackOp.top()==1)
				{
					StackOp.pop();
					cur=combine(StackStr.top(),cur);
					StackStr.pop();
				}

				if(StackOp.top()==0)
				{
					StackOp.pop();
					cur=crossProduct(StackStr.top(),cur);
					StackStr.pop();
				}
			}
			else
			{
				string temp;
				temp.push_back(S[i]);
				cur.insert(temp);

			}
		}

		vector<string> ans(cur.begin(),cur.end());
		sort(ans.begin(),ans.end());
		return ans;

	}
};