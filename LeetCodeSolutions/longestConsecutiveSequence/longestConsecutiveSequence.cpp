// Date   : 2016.09.21
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
* 
* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
* 
* For example,
* Given [100, 4, 200, 1, 3, 2],
* The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
* 
* Your algorithm should run in O(n) complexity.
* 
*               
**********************************************************************************/
class Solution {
public:
    int longestConsecutive(vector<int> num) {
    unordered_map<int,int> m;
    int ret = 0;
    for(auto & n: num){

        //it is in the middle of some consecutive sequence OR we can say it is already visited earlier
        //therefore it does not contribute to a longer sequence
        if(m[n]) continue; 

        //we cannot find adjacent sequences to n, therefore it is a single element sequence by itself
        if(m.find(n-1) == m.end() && m.find(n+1) == m.end()){ // 
            ret = max(ret, m[n] = 1);
            continue;
        }

        //found a sequence at n+1
        //you may wonder what if the sequence at n+1 contains element n?
        //It it contains n, when we add the length by 1 using m[n+1]+1, it is wrong, right?
        //However it is not possible, because if sequence at n+1 contains n, m[n] must have been visited earlier
        //we checked that using if(m[n]) continue; here m[n] is not yet visited;
        //therefore sequence m[n+1] is always on right side, we can safely extend the length by 1
        if(m.find(n-1)==m.end()){ 
            
            //we want to maintain the TWO boundaries of the sequence
            //the new length of the sequence is the original length m[n+1] incremented by 1
            //left boundary m[n] = m[n+1] +1;
            //right boundary m[n+m[n+1]] = m[n+1]+1;
            //why n+m[n+1]? it is equal to m[n+1]+(n+1)-1 
            //meaning the old left boundary n+1 plus the old length m[n+1] minus 1
            //e.g. for sequence 3,4,5,6 m[3] = 4, and right boundary 6 = 3+m[3]-1 (here n+1 == 3);
            ret = max(ret, m[n] = m[n+m[n+1]] = m[n+1]+1);
            continue;
        }
        
        //this is similar to the above case just extend to the right
        if(m.find(n+1)==m.end()){
            ret = max(ret,m[n] = m[n-m[n-1]] = m[n-1]+1);
            continue;
        }
        
        //here, we found both sequences at n+1 and n-1, for reasons we explained,
        //the sequences have no overlap.
        //Now, we just need to add the length of current element n (which is 1) to both left and right boundaries
        //the new length will be :  
        //old length of left sequence (m[n-1]) + old length of right sequence (m[n+1]) + 1
        //We also need to mark m[n] as visited, here we can either mark it with 1 or the new length;
        m[n] = 1; //basically we just need to mark m[n] as any non-zero number
        // or we can write
        //int r = m[n] = m[n-m[n-1]] = m[n+m[n+1]] = 1+ m[n+1]+ m[n-1];
        ret = max(ret,m[n-m[n-1]] = m[n+m[n+1]] = 1+ m[n+1]+ m[n-1]);
    }
    return ret;
    }
};
