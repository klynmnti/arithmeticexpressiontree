#include "arithmeticExpression.h"

int main() {
    /* testing default constructor, buildtree, infix, prefix, postfix */
    // using three different test strings
    string expr1 = "a+b*c";
    arithmeticExpression ex1(expr1);
    ex1.buildTree();
    cout << "expression 1: " << expr1 << endl;
    cout << "infix: "; ex1.infix(); cout << endl;
    cout << "prefix: "; ex1.prefix(); cout << endl;
    cout << "postfix: "; ex1.postfix(); cout << endl;
    cout << endl;

    string expr2 = "(a+b)*(c-d)";
    arithmeticExpression ex2(expr2);
    ex2.buildTree();
    cout << "expression 2: " << expr2 << endl;
    cout << "infix: "; ex2.infix(); cout << endl;
    cout << "prefix: "; ex2.prefix(); cout << endl;
    cout << "postfix: "; ex2.postfix(); cout << endl;
    cout << endl;

    string expr3 = "a + b * c - ( d * e + f ) * g";
    arithmeticExpression ex3(expr3);
    ex3.buildTree();
    cout << "expression 3: " << expr3 << endl;
    cout << "infix: "; ex3.infix(); cout << endl;
    cout << "prefix: "; ex3.prefix(); cout << endl;
    cout << "postfix: "; ex3.postfix(); cout << endl;
    cout << endl;

    return 0;
}