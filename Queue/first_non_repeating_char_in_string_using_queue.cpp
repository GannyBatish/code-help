string FirstNonRepeating(string A){
		    // Code here
		    unordered_map<char,int> count;
		    queue<char> q;
		    string ans;
		    for(int i=0;i<A.length();i++)
		    {
		        char ch=A[i];
		        count[ch]++;
		        
		        q.push(ch);
		        
		        while(!q.empty())
		        {
		            if(count[q.front()]>1)
		            {
		                //repeating
		                q.pop();
		            }
		            else
		            {
		                //non-repeating
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty())
		        {
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}