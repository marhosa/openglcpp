#include <iostream>
using namespace std;

class Node {
  public:
    string data;
    Node* left;
    Node* right;
    
    Node(string d, Node* l, Node* r){
        data = d;
        left = l;
        right = r;
    }
    
    void printData(){
        cout<<"Data is: ["<<data<<"]. ";
    }
    
    Node* leftPoint(){
        return left;
    }
    
    Node* rightPoint(){
        return right;
    }
    
};


int main() {
    
    // Tree
    Node* lrabbit = new Node("rabbit", nullptr, nullptr);
    Node* rgorilla = new Node("hamster", lrabbit, nullptr);
    Node* lgorilla = new Node("fox", nullptr, nullptr);
    Node* rmonkey = new Node("cat", nullptr, nullptr);
    Node* lmonkey = new Node("dog", nullptr, nullptr);
    Node* rroot = new Node("gorilla", lgorilla, rgorilla);
    Node* lroot = new Node("monkey", lmonkey, rmonkey);
    Node* root = new Node("chinchilla", lroot, rroot);
    
    // Simple Printing Type shit
    root -> leftPoint() -> rightPoint() -> printData();


    return 0;
}