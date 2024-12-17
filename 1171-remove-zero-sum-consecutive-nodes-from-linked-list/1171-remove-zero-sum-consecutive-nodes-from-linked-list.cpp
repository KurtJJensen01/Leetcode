/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//Correct Solution
#include <unordered_map>

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        // Create a dummy node to handle edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Hash map to store the first occurrence of the cumulative sum
        std::unordered_map<int, ListNode*> prefix_sum;
        prefix_sum[0] = dummy;
        
        int current_sum = 0;
        ListNode* current = head;
        
        while (current) {
            current_sum += current->val;
            
            if (prefix_sum.find(current_sum) != prefix_sum.end()) {
                // Remove all nodes between the previous occurrence and the current node
                ListNode* prev_node = prefix_sum[current_sum];
                ListNode* temp = prev_node->next;
                int sum_to_remove = current_sum;
                
                // Remove all the nodes between prev_node and current
                while (temp != current) {
                    sum_to_remove += temp->val;
                    prefix_sum.erase(sum_to_remove);
                    temp = temp->next;
                }
                // Connect the previous node to the current node
                prev_node->next = current->next;
            } else {
                // Store the current node for the given cumulative sum
                prefix_sum[current_sum] = current;
            }
            
            current = current->next;
        }
        
        return dummy->next;
    }
};



/*
My solution

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* current;
        ListNode* previous;
        
        for(int i=0; i<2; i++){
            current = head;
            previous = nullptr;
            while (current != nullptr && current->next != nullptr) {
                if (current->val + current->next->val == 0) {
                    removeNode(current, previous, head);
                    current = (previous == nullptr) ? head : previous->next;
                } else {
                    previous = current;
                    current = current->next;
                }
            }
        }

        return head;
    }

    void removeNode(ListNode* current, ListNode* previous, ListNode*& head) {
        if (previous == nullptr) {
            if (current->next != nullptr) {
                head = current->next->next; 
            } else {
                head = nullptr;  
            }
        } else {
            previous->next = current->next->next;
        }   
    }
};
*/