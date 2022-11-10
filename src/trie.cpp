#include "trie.h"

Trie::Trie()
{
    // std::cout << "Trie contructor !" << std::endl;
    root = new Node('\0', false);
}

Trie::~Trie(){
    // std::cout << "Trie Destructor !" << std::endl;
}

Trie::Node::Node(char _data, bool _is_finished): 
    data{_data}, is_finished{_is_finished}
{
    // std::cout << "Node Constructor" << std::endl;
}


void Trie::insert(std::string str){
    Node* current_node = root;
    char data;
    bool is_finished;

    size_t i = 0;
    int flag = 1;
    while (true) {
        flag = 1;
        for (size_t itr{0}; itr < current_node->children.size(); itr++) {
            if (current_node->children[itr]->data == str[i]) {
                current_node = current_node->children[itr];
                i++;
                flag = 0;
            }
        }
        if (flag) break;
    }

    for (size_t itr{i}; itr < str.size(); itr++) {
        data = str[itr];
        is_finished = itr == str.size()-1 ? true : false;
        Node* child = new Node(data, is_finished);
        current_node->children.push_back(child);
        current_node = child;
    }
}

bool Trie::search(std::string query){
    Node* current_node = root;
    char data;
    bool is_finished;
    int flag = 0;

    for (size_t itr{0}; itr < current_node->children.size(); itr++) {
        if (current_node->children[itr]->data == query[itr]) {
            current_node = current_node->children[itr];
            flag += 1;
        }
    }
    if (flag == query.size())
       return true;
    else
        return false;
}