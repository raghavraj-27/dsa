class Solution {
public:
    // My solution using prefix sum
    /*
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i=0, n=gas.size(); 
        bool flag = true;
        
        while(i<n)
        {
            if(gas[i]>=cost[i])
            {
                int fuel = gas[i];
                int j=(i+1)%n, k=i;
                
                while(i!=j)
                {
                    fuel = fuel - cost[k] + gas[j];
                    k = (k+1)%n;
                    j = (j+1)%n;
                    if(fuel < cost[k])
                    {
                        flag = false;
                        break;
                    }   
                }
                
                if(flag) return i;
                else flag = true;
            }
            i++;
        }
        return -1;
    }
    */
    
    // Efficeint approach O(n)
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int tank=0, index=0, total=0;
        for(int i=0; i<gas.size(); i++) 
        {
            int consume = gas[i] - cost[i];
            tank += consume;
            if(tank < 0)
            {
                index=i+1; 
                tank=0; 
            }
            total += consume;
        }
        
        return total < 0 ? -1 : index;
    }
    
};