class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head){
            return nullptr;
        }
        Node* curr=head;
        unordered_map<Node*,Node*> map;
        while(curr!=NULL){
            map[curr]=new Node(curr->val); //creating nodes
            curr=curr->next;
        }
        curr=head;
        while(curr!=NULL){
            map[curr]->next=map[curr->next];
            map[curr]->random=map[curr->random];
            curr=curr->next;
        }
        return map[head];
    }
};
