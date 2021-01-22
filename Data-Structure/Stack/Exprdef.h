#pragma once
#include "LinkedListStack.h"

class ExpressionToken
{
public:
	ExpressionToken(ExprToken* pExprTokens);
	~ExpressionToken();
	void calExpr(int tokenCount);
	void pushExprToken(ExprToken data);
	void convertInfixToPostfix(int tokenCount);
	int inStackPrecedence(Precedence oper);
	int outStackPrecedence(Precedence oper);
	void printToken(ExprToken element);

private:
	LinkedListStack* stack;
	ExprToken* pExprTokens;
};
