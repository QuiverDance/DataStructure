#include "Exprdef.h"

int main(void)
{
	ExprToken* pExprTokens = new ExprToken[7];
	pExprTokens[0].type = operand;
	pExprTokens[0].value = 2;
	pExprTokens[1].type = operand;
	pExprTokens[1].value = 3;
	pExprTokens[2].type = operand;
	pExprTokens[2].value = 4;
	pExprTokens[3].type = plus;
	pExprTokens[3].value = 0;
	pExprTokens[4].type = operand;
	pExprTokens[4].value = 5;
	pExprTokens[5].type = times;
	pExprTokens[5].value = 0;
	pExprTokens[6].type = minus;
	pExprTokens[6].value = 0;
	
	ExpressionToken exp = ExpressionToken(pExprTokens);
	exp.calExpr(7);

	ExprToken* pExprTokens2 = new ExprToken[9];
	pExprTokens2[0].type = operand;
	pExprTokens2[0].value = 2;
	pExprTokens2[1].type = minus;
	pExprTokens2[1].value = 0;
	pExprTokens2[2].type = lparen;
	pExprTokens2[2].value = 0;
	pExprTokens2[3].type = operand;
	pExprTokens2[3].value = 3;
	pExprTokens2[4].type = plus;
	pExprTokens2[4].value = 0;
	pExprTokens2[5].type = operand;
	pExprTokens2[5].value = 4;
	pExprTokens2[6].type = rparen;
	pExprTokens2[6].value = 0;
	pExprTokens2[7].type = times;
	pExprTokens2[7].value = 0;
	pExprTokens2[8].type = operand;
	pExprTokens2[8].value = 5;

	ExpressionToken exp2 = ExpressionToken(pExprTokens2);
	exp2.convertInfixToPostfix(9);
}
