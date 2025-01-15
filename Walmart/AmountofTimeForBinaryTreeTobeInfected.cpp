// #include<bits/stdc++.h>
// using namespace std;

// TreeNode* node = NULL;

// void findParent(TreeNode* root, TreeNode* p, vector<TreeNode*>& parent,
//                 int start) {
//     if (root == NULL)
//         return;

//     parent[root->val] = p;
//     if (root->val == start) {
//         node = root;
//     }

//     findParent(root->left, root, parent, start);
//     findParent(root->right, root, parent, start);
// }

// int amountOfTime(TreeNode* root, int start) {
//     vector<TreeNode*> parent(100005, NULL);
//     findParent(root, NULL, parent, start);

//     vector<bool> visited(100005, false);

//     queue<TreeNode*> q;
//     q.push(node);
//     visited[start] = true;

//     int result = -1;

//     while (q.size() > 0) {
//         int n = q.size();

//         for (int i = 0; i < n; i++) {
//             auto curr = q.front();
//             int currNode = curr->val;
//             q.pop();

//             if (parent[currNode] != NULL &&
//                 visited[parent[currNode]->val] == false) {
//                 visited[parent[currNode]->val] = true;
//                 q.push(parent[currNode]);
//             }

//             if (curr->left && visited[curr->left->val] == false) {
//                 visited[curr->left->val] = true;
//                 q.push(curr->left);
//             }

//             if (curr->right && visited[curr->right->val] == false) {
//                 visited[curr->right->val] = true;
//                 q.push(curr->right);
//             }
//         }

//         result++;
//     }

//     return result;
// }