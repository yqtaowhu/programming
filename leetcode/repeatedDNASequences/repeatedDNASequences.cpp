// Date   : 2016.10.06
// Author : yqtao
// https://github.com/yqtaowhu

/********************************************************************************** 
 * 
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
 *
 * For example: "ACGAATTCCG". 
 * When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 * 
 * Write a function to find all the 10-letter-long sequences (substrings) that 
 * occur more than once in a DNA molecule.
 * 
 * For example,
 * 
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 * 
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 * 
 *               
 **********************************************************************************/
class Solution {
public:
const int MAX_LEN = 10;
int ACGT2Int(char ch){
    switch(ch){
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
    }
    return -1;
}
int DNASeqs2Int(string &s, int begin){
    int result=0;
    for(int i=0; i<MAX_LEN; i++){
        result = result*4 + ACGT2Int(s[i+begin]);
    }
    return result;
}
vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<int, int> stat;
    vector<string> result;
    for( int i=0; i+MAX_LEN<=s.size(); i++ ){
        int hash_code = DNASeqs2Int(s, i);
        stat[hash_code]++;
        if (stat[hash_code]==2){
            result.push_back(s.substr(i, MAX_LEN));
        }
    }
    return result;        
}
};
