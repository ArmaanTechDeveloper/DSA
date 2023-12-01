#include <iostream>
#include <vector>

using namespace std;


class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;
        int childNodes;
    
    TrieNode(char ch){
        data = ch;
        for(int i=0; i < 26 ; i ++){
            children[i] = NULL;
        }
        isTerminal = false;
        childNodes = 0;
    }
    
};

class Trie{
    
    public:
    TrieNode * root;
    
    Trie(){
        root = new TrieNode('\0');
    }
    

    void insertWordUtil(TrieNode * root , string word){

        // base case
        if(word.length() == 0){
            root -> isTerminal = true;
            return;
        }

        int index = word[0] - 'a';

        TrieNode * child;

        // present
        if(root -> children[index] != NULL){
            child = root -> children[index];
        }
        else {
            // absent
            child = new TrieNode(word[0]);
            root -> children[index] = child;
            root -> childNodes++;
        }

        // Recursion
        insertWordUtil(child , word.substr(1));

    }
    void insertWord(string word){
        insertWordUtil(root , word);
    }

    void lcp(string first , string& ans){
        
        for(int i=0 ; i < first.length() ; i ++){
            char ch = first[i];
            
            if(root -> childNodes == 1){
                ans.push_back(ch);
                
                int index = ch - 'a';
                root = root -> children[index];
            }
            else{
                break;
            }
        }
        
    }
    
      
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie();
    
    for(int i=0 ; i < arr.size() ; i ++){
        t -> insertWord(arr[i]);
    }
    
    string ans = "";
    string first = arr[0];
    
    t -> lcp(first , ans);
    


    return ans;
}