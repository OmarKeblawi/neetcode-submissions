#include <vector>
#include <list>
#include <unordered_map>
class LRUCache {
public:
    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if(!hash.count(key)) return -1;
        if(tail == hash[key]) return hash[key]->val;
        Node *current = hash[key];
        if(head == current){
            head = head->next;
            head->prev = nullptr;
        } 
        else{
            (current->prev)->next = current->next;
            (current->next)->prev = current->prev; 
        }
        tail->next = current;
        current->prev = tail;
        tail = current;
        current->next = nullptr;
        return hash[key]->val;
    }
    
    void put(int key, int value) {
        if(hash.count(key)){
            hash[key]->val = value;
            if(tail == hash[key]) return;
            Node *current = hash[key];
            if(head == current){
                head = head->next;
                head->prev = nullptr;
            } 
            else{
                (current->prev)->next = current->next;
                (current->next)->prev = current->prev; 
            }
            tail->next = current;
            current->prev = tail;
            tail = current;
            current->next = nullptr;
        }
        else{
            Node* temp = new Node(value,key,nullptr,nullptr);
            hash[key] = temp;
            if(size < cap){
                if(size == 0){
                    this->head = this->tail =temp;
                }
                else{
                    tail->next = temp;
                    temp->prev = tail;
                    tail = temp;
                }
                size++;
            }
            else{
                Node* toDelete = this->head;
                hash.erase(toDelete->key);
                if(cap == 1){
                    head = tail = temp;
                    delete toDelete;
                    return;
                }
                head = head->next;
                head->prev = nullptr;
                delete toDelete;
                tail->next = temp;
                temp->prev = tail;
                tail = temp;
            } 

        }
    }
private:
    int cap;
    int size = 0;
    class Node{
    public:
        Node* next;
        Node* prev;
        int val;
        int key;
        Node(int value,int key ,Node* next, Node* prev){
            this->next = next;
            this->prev = prev;
            this->val = value;
            this->key = key;
        }
    };
    unordered_map<int,Node*> hash;
    Node* head = nullptr;
    Node* tail = nullptr;

};
