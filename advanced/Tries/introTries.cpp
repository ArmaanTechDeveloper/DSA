#include <iostream>

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

            int index = word[0] - 'A';

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


        // SEARCHING INTO THE TRIE
        bool searchWordUtil(TrieNode* root , string word){
            if(word.length() == 0){
                return root -> isTerminal;
            }

            int index = word[0] - 'A';

            TrieNode * child;

            if(root -> children[index] != NULL){
                // present
                child = root -> children[index];
            }
            else{
                // absent
                return false;
            }


            // RECURSION
            return searchWordUtil(child , word.substr(1));
        }
        bool searchWord(string word){
            return searchWordUtil(root , word);
        }

};
int main (){

    Trie* t = new Trie();

    t -> insertWord("ARM");
    t -> insertWord("TIMER");
    t -> insertWord("DO");
    t -> insertWord("WIN");

    cout << "Word present or not -> " << t -> searchWord("TIMER") << endl;

    return 0;

}