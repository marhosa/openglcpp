#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    string data;
    Node *left;
    Node *right;

    Node(string d, Node *l, Node *r) {
        data = d;
        left = l;
        right = r;
    }

    void printData() { cout << "Data is: [" << data << "]. "; }

    string getData() {
        return data;
    }

    Node *leftPoint() { return left; }

    Node *rightPoint() { return right; }
};

int main() {
    cout << endl << endl;

    //frontier (change this to stack for BFS instead of DFS) ALSO check line 60
    queue<Node*> frontier;


    // Tree
    Node *lrabbit = new Node("rabbit", nullptr, nullptr);
    Node *rgorilla = new Node("hamster", lrabbit, nullptr);
    Node *lgorilla = new Node("fox", nullptr, nullptr);
    Node *rmonkey = new Node("cat", nullptr, nullptr);
    Node *lmonkey = new Node("dog", nullptr, nullptr);
    Node *rroot = new Node("gorilla", lgorilla, rgorilla);
    Node *lroot = new Node("monkey", lmonkey, rmonkey);
    Node* root = new Node("chinchilla", lroot, rroot);

    string valueToLookFor = "cat";


    Node* initialPointer = root;
    frontier.push(initialPointer);
    int traverseCounter = 0;
    while (frontier.size() > 0) {
        traverseCounter++;
        //traverse current element
        initialPointer = frontier.front(); //change this to frontier.pop() if using BFS
        frontier.pop();

        //check if contains value
        if (initialPointer->getData() == valueToLookFor) {
            cout<<"FOUND ON STEP "<<traverseCounter<<" value: "<<initialPointer -> getData()<<endl;
            break;
        }
        cout << "NOT ON STEP   " << traverseCounter << " value: " << initialPointer->getData()<<endl;

        //add elements to stack (left side first)
        if (initialPointer->rightPoint() != nullptr) {
            frontier.push(initialPointer->rightPoint());
        }

        if (initialPointer->leftPoint() != nullptr) {
            frontier.push(initialPointer->leftPoint());    
        }
    }


    cout << endl << endl;
    return 0;
}