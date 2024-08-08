#include "arithmeticExpression.h"
/* Default constructor */
// assigns the infixexpression to the given parameter 
// sets root to null 
arithmeticExpression::arithmeticExpression(const string &expression) :
    infixExpression(expression), root(nullptr) {}
/* Destructor */
// deletes left subtree, right subtree, and root
arithmeticExpression::~arithmeticExpression() {
    delete root->left;
    delete root->right;
    delete root;
}
/* Postfix recursive helper function */
// outputs data in the order left subtree, right subtree, root
void arithmeticExpression::postfix(TreeNode *n) {
    if (n == nullptr) { return; }
    postfix(n->left);
    postfix(n->right);
    cout << n->data;
}
/* Prefix recursive helper function */
// outputs data in the order root, left subtree, right subtree
void arithmeticExpression::prefix(TreeNode *n) {
    if (n == nullptr) { return; }
    cout << n->data;
    prefix(n->left);
    prefix(n->right);
}
/* Infix recursive helper function */
// outputs data in the order left subtree, root, right subtree
// outputs parentheses to expressions as needed
void arithmeticExpression::infix(TreeNode* n) {
    if (n == nullptr) { return; }
    if (n->left != nullptr) { cout << "("; }
    infix(n->left);
    cout << n->data;
    infix(n->right);
    if (n->right != nullptr) { cout << ")"; }
}
/* Postfix, Prefix, and Infix functions */
// call the respective recursive helper functions with parameter root node
void arithmeticExpression::postfix() {
    postfix(root);
}
void arithmeticExpression::prefix() {
    prefix(root);
}
void arithmeticExpression::infix() {
    infix(root);
}
/* Build Tree function */
// creates and builds the stack using the Tree Nodes
// if the current character in string traversal is a letter, a new TreeNode is added to stack
// else, the node's left and right pointers are set, stack contents are adjusted and then the TreeNode is added to stack
void arithmeticExpression::buildTree() {
    stack<TreeNode*> s;
    string p = infix_to_postfix();
    for (unsigned i = 0; i < p.size(); i++) {
        if (isalpha(p.at(i))) { s.push(new TreeNode(p.at(i), 0)); }
        else {
            TreeNode* expr = new TreeNode(p.at(i), 0);
            TreeNode* r = s.top();
            s.pop();
            TreeNode* l = s.top();
            s.pop();
            expr->right = r;
            expr->left = l;
            s.push(expr);
            root = expr;
        }
    }
}
/* Priority function */
// assigns priority to the given character depending on the type of char
// letters have priority of 0, whereas operations are assigned priority depending on PEMDAS
int arithmeticExpression::priority(char op) {
    int priority = 0;
    if (op == '(') { priority =  3; }
    else if (op == '*' || op == '/') { priority = 2; }
    else if (op == '+' || op == '-') { priority = 1; }
    return priority;
}
/* Infix to Postfix function */
// converts the infix expression into postfix notation
// inputs through the infix expression until an operator is reached
// depending on the type of operator, either push onto or pop the stack
// finally output each char in the adjusted stack and delete values
string arithmeticExpression::infix_to_postfix() {
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if (c == ' ') { continue; }
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') { //c is an operator
            if ( c == '(') { s.push(c); }
            else if (c == ')') {
                while (s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else {
                while (!s.empty() && priority(c) <= priority(s.top())){
                    if (s.top() == '('){ break; }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else {  oss << c; } // c is an operand 
    }
    while (!s.empty()) {
        oss << s.top();
        s.pop();
    }
    return oss.str();
}
