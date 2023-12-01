#include <iostream>
#include <vector>

using namespace std;

class TrieNode {
    public:
        char data;
        TrieNode* children[26];
        bool isTerminal;

        TrieNode(char ch){
            data = ch;
            for(int i=0 ; i < 26 ; i ++){
                children[i] = NULL;
            }
            isTerminal = false;
        }
};
class Trie{
    public:
        TrieNode* root;

        Trie(){
            root = new TrieNode('\0');
        }


        // INSERTING INTO THE TRIE CODE
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
            }

            // Recursion
            insertWordUtil(child , word.substr(1));

        }
        void insertWord(string word){
            insertWordUtil(root , word);
        }
        void printSuggestions(TrieNode * curr , string prefix , vector<string> & temp){
            if(curr -> isTerminal){
                temp.push_back(prefix);
            }

            for(char ch='a' ; ch <= 'z' ; ch ++){
                TrieNode * next = curr -> children[ch - 'a'];

                if(next != NULL){
                    prefix.push_back(ch);
                    printSuggestions(next, prefix, temp);
                    prefix.pop_back();
                }
            }
        }

        vector<vector<string>> getSuggestions(string str){

            vector <vector < string > > output;

            TrieNode* prev = root;

            string prefix = "";

            for(int i=0 ; i < str.length() ; i ++){
                char lastCh = str[i];

                prefix.push_back(lastCh);

                TrieNode* curr = prev -> children[lastCh - 'a'];
                // if curr == null
                if(curr == NULL){
                    break;
                }
                vector <string> temp;
                // else suggestions exist
                printSuggestions(curr , prefix , temp );
                output.push_back(temp);
                prev = curr;
                temp.clear();
            }

            return output;
        }
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie *t = new Trie();
    for(int i=0 ; i < contactList.size() ; i ++){
        t -> insertWord(contactList[i]);
    }

    return t->getSuggestions(queryStr);


}