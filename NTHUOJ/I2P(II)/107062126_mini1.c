#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLEN 256
typedef enum {UNKNOWN, END, INT, ID, ADDSUB, MULDIV, ASSIGN,
LPAREN, RPAREN, AND, OR, XOR} TokenSet;

extern int match (TokenSet token);
extern void advance(void);
extern char* getLexeme(void);
static TokenSet getToken(void);
static TokenSet lookahead = UNKNOWN;
static char lexeme[MAXLEN];

void end_evaluate(){
     for(int regId=0; regId<3; regId++){
        printf("MOV r%d [%d]\n", regId, regId*4);
    }
    printf("EXIT 0\n");
    exit(0);
}

TokenSet getToken(void)
{
    int i;
    char c;

    while ( (c = fgetc(stdin)) == ' ' || c== '\t' );  // ©¿²¤ªÅ¥Õ¦r¤¸

    if (isdigit(c)) {
        lexeme[0] = c;
        c = fgetc(stdin);
        i = 1;
        while (isdigit(c) && i<MAXLEN) {
            lexeme[i] = c;
            ++i;
            c = fgetc(stdin);
        }
        ungetc(c, stdin);
        lexeme[i] = '\0';
        return INT;
    } else if (c == '+' || c == '-') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return ADDSUB;
    } else if (c == '*' || c == '/') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return MULDIV;
    } else if (c == '\n') {
        lexeme[0] = '\0';
        return END;
    } else if (c == '=') {
        strcpy(lexeme, "=");
        return ASSIGN;
    } else if (c == '(') {
        strcpy(lexeme, "(");
        return LPAREN;
    } else if (c == ')') {
        strcpy(lexeme, ")");
        return RPAREN;
    } else if (c == '&') {
        strcpy(lexeme, "&");
        return AND;
    } else if (c == '|') {
        strcpy(lexeme, "|");
        return OR;
    } else if (c == '^') {
        strcpy(lexeme, "^");
        return XOR;
    } else if (isalpha(c) || c == '_') {
        lexeme[0] = c;
        c = fgetc(stdin);
        i = 1;
        while (isalpha(c) || isdigit(c) || c == '_') {
            lexeme[i] = c;
            ++i;
            c = fgetc(stdin);
        }
        ungetc(c, stdin);
        lexeme[i] = '\0';
        return ID;
    }else if (c == EOF) {
        end_evaluate();
    } else {
        return UNKNOWN;
    }
}

void advance(void)
{
    lookahead = getToken();
}

int match(TokenSet token)
{
    if (lookahead == UNKNOWN) advance();
    return token == lookahead;
}

char* getLexeme(void)
{
    return lexeme;
}

#define TBLSIZE 65535
typedef struct {
	char name[MAXLEN];
	int val;
	int site;
} Symbol;
Symbol table[TBLSIZE];
int sbcount = 0;

typedef struct _Node {
	char lexeme[MAXLEN];
	TokenSet token;
	int val;
	struct _Node *left, *right;
} BTNode;

void statement(void);
BTNode* expr(void);
BTNode* term(void);
BTNode* factor(void);
int getval(void);
int setval(char*, int);

typedef enum {MISPAREN, NOTNUMID, NOTFOUND, RUNOUT, NAN} ErrorType;
void error(ErrorType errorNum);

/* create a node without any child */
BTNode* makeNode(TokenSet tok, const char *lexe)
{
	BTNode *node = (BTNode*) malloc(sizeof(BTNode));
	strcpy(node->lexeme, lexe);
	node->token= tok;
	node->val = 0;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/* clean a tree */
void freeTree(BTNode *root)
{
	if (root!=NULL) {
		freeTree(root->left);
		freeTree(root->right);
		free(root);
	}
}

/* print a tree by pre-order */
void printPrefix(BTNode *root)
{
	if (root != NULL) {
		printf("%s ", root->lexeme);
		printPrefix(root->left);
		printPrefix(root->right);
	}
}

/* traverse the syntax tree by pre-order
   and evaluate the underlying expression */
int evaluateTree(BTNode *root)
{
	int retval = 0, lv, rv;
	if (root != NULL) {
		switch (root->token) {
		case ID:
		case INT:
			retval = root->val;
			break;
		case ASSIGN:
		case ADDSUB:
		case MULDIV:
			lv = evaluateTree(root->left);
			rv = evaluateTree(root->right);
			if (strcmp(root->lexeme, "+") == 0)
				retval = lv + rv;
			else if (strcmp(root->lexeme, "-") == 0)
				retval = lv - rv;
			else if (strcmp(root->lexeme, "*") == 0)
				retval = lv * rv;
			else if (strcmp(root->lexeme, "/") == 0) {
				if (rv==0)
					error(NAN);
				else
					retval = lv / rv;
			} else if (strcmp(root->lexeme, "=") == 0)
				retval = setval(root->left->lexeme, rv);
				break;
        case AND:
        case XOR:
        case OR:
            if (strcmp(root->lexeme, "&") == 0)
				retval = (lv && rv);
            else if (strcmp(root->lexeme, "^") == 0)
				retval = lv ^ rv;
            else if (strcmp(root->lexeme, "|") == 0)
				retval = lv || rv;
			break;
		default:
			retval = 0;
		}
	}
	return retval;
}
int site_count = 3;
int getval(void)
{
	int i, retval, found;

	if (match(INT)) {
		retval = atoi(getLexeme());
	} else if (match(ID)) {
		i = 0;
		found = 0;
		retval = 0;
		while (i<sbcount && !found) {
			if (strcmp(getLexeme(), table[i].name)==0) {
				retval = table[i].val;
				found = 1;
				break;
			} else {
				i++;
			}
		}
		if (!found) {
			if (sbcount < TBLSIZE) {
				strcpy(table[sbcount].name, getLexeme());
				table[sbcount].val = 0;
				if(strcmp(table[i].name, "x") == 0) table[sbcount].site = 0;
                else if(strcmp(table[i].name, "y") == 0) table[sbcount].site = 4;
                else if(strcmp(table[i].name, "z") == 0) table[sbcount].site = 8;
				else {table[sbcount].site = site_count*4;site_count++;}
				sbcount++;
			} else {
				error(RUNOUT);
			}
		}
	}
	return retval;
}

int setval(char *str, int val)
{
	int i, retval = 0;
	i = 0;
	while (i<sbcount) {
		if (strcmp(str, table[i].name)==0) {
			table[i].val = val;
			retval = val;
			break;
		} else {
			i++;
		}
	}
	return retval;
}
BTNode* op_xor(void);
BTNode* op_and(void);
BTNode* op_or(void)
{
	BTNode *retp, *left;
	retp = left = op_xor();
	while (match(OR)) { // tail recursion => while
		retp = makeNode(OR, getLexeme());
		advance();
		retp->right = op_xor();
		retp->left = left;
		left = retp;
	}
	return retp;
}
BTNode* op_xor(void)
{
	BTNode *retp, *left;
	retp = left = op_and();
	while (match(XOR)) { // tail recursion => while
		retp = makeNode(XOR, getLexeme());
		advance();
		retp->right = op_and();
		retp->left = left;
		left = retp;
	}
	return retp;
}
BTNode* op_and(void)
{
	BTNode *retp, *left;
	retp = left = expr();
	while (match(AND)) { // tail recursion => while
		retp = makeNode(AND, getLexeme());
		advance();
		retp->right = expr();
		retp->left = left;
		left = retp;
	}
	return retp;
}
//  expr        := term expr_tail
//  expr_tail   := ADDSUB term expr_tail | NIL
BTNode* expr(void)
{
	BTNode *retp, *left;
	retp = left = term();
	while (match(ADDSUB)) { // tail recursion => while
		retp = makeNode(ADDSUB, getLexeme());
		advance();
		retp->right = term();
		retp->left = left;
		left = retp;
	}
	return retp;
}

//  term        := factor term_tail
//  term_tail := MULDIV factor term_tail | NIL
BTNode* term(void)
{
	BTNode *retp, *left;
	retp = left = factor();
	while (match(MULDIV)) { // tail recursion => while
		retp = makeNode(MULDIV, getLexeme());
		advance();
		retp->right = factor();
		retp->left = left;
		left = retp;
	}
	return retp;
}

BTNode* factor(void)
{
	BTNode* retp = NULL;
	char tmpstr[MAXLEN];

	if (match(INT)) {
		retp =  makeNode(INT, getLexeme());
		retp->val = getval();
		advance();
	} else if (match(ID)) {
		BTNode* left = makeNode(ID, getLexeme());
		left->val = getval();
		strcpy(tmpstr, getLexeme());
		advance();
		if (match(ASSIGN)) {
			retp = makeNode(ASSIGN, getLexeme());
			advance();
			retp->right = op_or();
			retp->left = left;
		} else {
			retp = left;
		}
	} else if (match(ADDSUB)) {
		strcpy(tmpstr, getLexeme());
		advance();
		if (match(ID) || match(INT)) {
			retp = makeNode(ADDSUB, tmpstr);
			if (match(ID))
				retp->right = makeNode(ID, getLexeme());
			else
				retp->right = makeNode(INT, getLexeme());
			retp->right->val = getval();
			retp->left = makeNode(INT, "0");
			retp->left->val = 0;
			advance();
		} else {
			//error(NOTNUMID);
			printf("EXIT 1\n");
            exit(0);
		}
	} else if (match(AND)) {
		strcpy(tmpstr, getLexeme());
		advance();
		if (match(ID) || match(INT)) {
			retp = makeNode(AND, tmpstr);
			if (match(ID))
				retp->right = makeNode(ID, getLexeme());
			else
				retp->right = makeNode(INT, getLexeme());
			retp->right->val = getval();
			retp->left = makeNode(INT, "0");
			retp->left->val = 0;
			advance();
		} else {
			//error(NOTNUMID);
			printf("EXIT 1\n");
            exit(0);
		}
	}
	 else if (match(XOR)) {
		strcpy(tmpstr, getLexeme());
		advance();
		if (match(ID) || match(INT)) {
			retp = makeNode(XOR, tmpstr);
			if (match(ID))
				retp->right = makeNode(ID, getLexeme());
			else
				retp->right = makeNode(INT, getLexeme());
			retp->right->val = getval();
			retp->left = makeNode(INT, "0");
			retp->left->val = 0;
			advance();
		} else {
			//error(NOTNUMID);
			printf("EXIT 1\n");
            exit(0);
		}
	}else if (match(OR)) {
		strcpy(tmpstr, getLexeme());
		advance();
		if (match(ID) || match(INT)) {
			retp = makeNode(OR, tmpstr);
			if (match(ID))
				retp->right = makeNode(ID, getLexeme());
			else
				retp->right = makeNode(INT, getLexeme());
			retp->right->val = getval();
			retp->left = makeNode(INT, "0");
			retp->left->val = 0;
			advance();
		} else {
			//error(NOTNUMID);
			printf("EXIT 1\n");
            exit(0);
		}
	}else if (match(LPAREN)) {
		advance();
		retp = op_or();
		if (match(RPAREN)) {
			advance();
		} else {
			//error(MISPAREN);
			printf("EXIT 1\n");
            exit(0);
		}
	} else {
		//error(NOTNUMID);
		printf("EXIT 1\n");
        exit(0);
	}
	return retp;
}

void error(ErrorType errorNum)
{
	switch (errorNum) {
	case MISPAREN:
		fprintf(stderr, "Mismatched parenthesis\n");
		break;
	case NOTNUMID:
		fprintf(stderr, "Number or identifier expected\n");
		break;
	case NOTFOUND:
		fprintf(stderr, "%s not defined\n", getLexeme());
		break;
	case RUNOUT:
		fprintf(stderr, "Out of memory\n");
		break;
	case NAN:
		fprintf(stderr, "Not a number\n");
	}
	exit(0);
}


void statement(void)
{
	BTNode* retp;

	if (match(END)) {
		advance();
	} else {
		retp = op_xor();
		if (match(END)) {
			if(retp->token != ASSIGN){
                printf("EXIT 1\n");
            exit(0);
			}
			else ass(retp);

			freeTree(retp);

			advance();
		}
	}
}

int state[8] = {0};

int ass(BTNode* root){
	if(root != NULL){
		if(root->token == INT){
			for(int i = 0; i < 8; i++){
				if(state[i] == 0){
					printf("MOV r%d %d\n", i, root->val);
					state[i] = 1;
					return i;
				}
			}
		}
		else if(root->token == ID){
			int memory;
			for(int i = 0; i < sbcount; i++){
                if(strcmp(root->lexeme, table[i].name) == 0){
                    memory = table[i].site;
                }
			}
			for(int i = 0; i < 8; i++){
				if(state[i] == 0){
					printf("MOV r%d [%d]\n",i ,memory);
					state[i] = 1;
					return i;
				}
			}
		}
		else if(root->token == ADDSUB){
			int a, b;
			a = ass(root->left);
			b = ass(root->right);
			state[b] = 0;
			if (strcmp(root->lexeme, "+") == 0){
				printf("ADD r%d r%d\n",a ,b);
			}
			else if (strcmp(root->lexeme, "-") == 0){
				printf("SUB r%d r%d\n",a ,b);
			}
			return a;
		}
		else if(root->token == MULDIV){
			int a, b;
			a = ass(root->left);
			b = ass(root->right);
			state[b] = 0;
			if (strcmp(root->lexeme, "*") == 0){
				printf("MUL r%d r%d\n",a ,b);
			}
			else if (strcmp(root->lexeme, "/") == 0){
				printf("DIV r%d r%d\n",a ,b);
			}
			return a;
		}
		else if(root->token == AND){
			int a, b;
			a = ass(root->left);
			b = ass(root->right);
			state[b] = 0;
			printf("AND r%d r%d\n", a, b);
			return a;
		}
		else if(root->token == XOR){
			int a, b;
			a = ass(root->left);
			b = ass(root->right);
			state[b] = 0;
			printf("XOR r%d r%d\n", a, b);
			return a;
		}
		else if(root->token == OR){
			int a, b;
			a = ass(root->left);
			b = ass(root->right);
			state[b] = 0;
			printf("OR r%d r%d\n", a, b);
			return a;
		}
		else if(root->token == ASSIGN){
			int memory = 0;
			for(int i = 0; i < sbcount; i++){
                if(strcmp(root->left->lexeme, table[i].name) == 0){
                    memory = table[i].site;
                }
			}
			int a = ass(root->right);
			printf("MOV [%d] r%d\n", memory, a);
			state[a] = 0;
		}
		else{
			printf("EXIT 1\n");
            exit(0);
		}
	}else{	
		printf("EXIT 1\n");
        exit(0);
	}
}




int main()
{
	while (1) {
		statement();
	}
	return 0;
}



