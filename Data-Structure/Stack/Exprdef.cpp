#include "Exprdef.h"
#include <iostream>

ExpressionToken::ExpressionToken(ExprToken* pExprTokens)
{
	stack = new LinkedListStack();
	this->pExprTokens = new ExprToken;
	this->pExprTokens = pExprTokens;
}

ExpressionToken::~ExpressionToken()
{
	stack->deleteStack();
	delete stack;
	delete pExprTokens;
}

void ExpressionToken::calExpr(int tokenCount)
{
	if (!pExprTokens)
		return;
	if (stack)
	{
		Precedence tokenType;
		StackNode* pNode1 = nullptr;
		StackNode* pNode2 = nullptr;
		for (int i = 0; i < tokenCount; i++) 
		{
			tokenType = pExprTokens[i].type;

			if (tokenType == operand)
			{
				pushExprToken(pExprTokens[i]);
			}
			else
			{
				pNode2 = stack->pop();
				if (pNode2)
				{
					pNode1 = stack->pop();
					if (pNode1)
					{
						float op1 = pNode1->data.value;
						float op2 = pNode2->data.value;

						ExprToken newToken;
						newToken.type = operand;

						switch (tokenType)
						{
						case plus:
							newToken.value = op1 + op2;
							break;
						case minus:
							newToken.value = op1 - op2;
							break;
						case times:
							newToken.value = op1 * op2;
							break;
						case divide:
							newToken.value = op1 / op2;
							break;
						default:
							break;
						}

						pushExprToken(newToken);

						delete pNode1;
					}
					delete pNode2;
				}
			}
		}
		pNode1 = stack->pop();
		if (pNode1)
		{
			std::cout << "결과: " << pNode1->data.value << std::endl;
			delete pNode1;
		}
		else
			std::cout << "수식 오류." << std::endl;
	}
	stack->deleteStack();
}

void ExpressionToken::pushExprToken(ExprToken data)
{
	StackNode node = { 0, };
	node.data = data;
	stack->push(node);
}

void ExpressionToken::convertInfixToPostfix(int tokenCount)
{
	if (!pExprTokens)
		return;
	if (stack)
	{
		Precedence tokenType;
		StackNode* pNode = nullptr;
		Precedence inStackTokenType;
		for (int i = 0; i < tokenCount; i++)
		{
			tokenType = pExprTokens[i].type;
			switch (tokenType)
			{
			case operand:
				std::cout << pExprTokens[i].value << std::endl;
				break;
			case rparen:
				pNode = stack->pop();
				while (pNode && pNode->data.type != lparen)
				{
					printToken(pNode->data);
					pNode = stack->pop();
				}
				break;
			default:
				while (!stack->isEmpty())
				{
					inStackTokenType = stack->peek()->data.type;
					if (outStackPrecedence(tokenType) <= inStackPrecedence(inStackTokenType))
					{
						pNode = stack->pop();
						if (pNode)
						{
							printToken(pNode->data);
						}
					}
					else
						break;
				}
				pushExprToken(pExprTokens[i]);
				break;
			}
		}

		while (!stack->isEmpty())
		{
			pNode = stack->pop();
			if (pNode)
			{
				printToken(pNode->data);
			}
		}
		delete pNode;
	}
	stack->deleteStack();
}

int ExpressionToken::inStackPrecedence(Precedence oper)
{
	switch (oper)
	{
	case lparen:
		return 0;
	case rparen:
		return 4;
	case times:
	case divide:
		return 2;
	case plus:
	case minus:
		return 1;
	default:
		return -1;
		break;
	}
}

int ExpressionToken::outStackPrecedence(Precedence oper)
{
	switch (oper)
	{
	case lparen:
		return 5;
	case rparen:
		return 4;
	case times:
	case divide:
		return 2;
	case plus:
	case minus:
		return 1;
	default:
		return -1;
		break;
	}
}

void ExpressionToken::printToken(ExprToken element)
{
	switch (element.type)
	{
	case lparen:
		std::cout << "(" << std::endl;
		break;
	case rparen:
		std::cout << ")" << std::endl;
		break;
	case plus:
		std::cout << "+" << std::endl;
		break;
	case minus:
		std::cout << "-" << std::endl;
		break;
	case times:
		std::cout << "*" << std::endl;
		break;
	case divide:
		std::cout << "/" << std::endl;
		break;
	case operand:
		std::cout << element.value << std::endl;
		break;
	default:
		break;
	}
}
