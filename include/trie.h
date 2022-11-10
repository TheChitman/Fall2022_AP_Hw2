#ifndef TRIE_H
#define TRIE_H
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
class Trie{
    public:
        Trie();
        ~Trie();
        void insert(std::string str);
        bool search(std::string query);
        class Node{
            public:
                Node(char data, bool is_finished);
                std::vector<Node*> children;
                char data;
                bool is_finished;
            private:
        };
        Node* root;
    private:
};

#endif // TRIE_H