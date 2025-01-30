#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* Merge(ListNode* list1, ListNode* list2){

  ListNode* temp = new ListNode(-1);
  ListNode* curr = temp;

  while(list1!= NULL && list2!=NULL){
      if(list1->val > list2->val){
          curr->next = list2;
          list2 = list2->next;
      }else{
          curr->next = list1;
          list1 = list1->next;
      }
      curr = curr->next;
  }

  if(list1!= NULL){
      curr->next = list1;
  }else{
      curr->next = list2;
  }

  return temp->next;
}

ListNode* mergeKLists(vector<ListNode*>& lists) {
  int n = lists.size();
  if(n==0){return NULL;}
  if(n==1){return lists[0];}

  ListNode *list = lists[0];
  for(int i=1;i<lists.size();i++){
      list = Merge(list,lists[i]);
  }

  return list;
}
