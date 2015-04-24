/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	CHAR *EcoParser_String;

typedef
	struct {
		LONGINT len[1];
		CHAR data[1];
	} *EcoParser_StrPtr;

typedef
	struct EcoParser_CtxNode *EcoParser_CtxPtr;

typedef
	struct EcoParser_Node *EcoParser_NodePtr;

typedef
	struct EcoParser_Parser {
		EcoParser_StrPtr inpBuf;
		INTEGER inpIdx, inpAvl;
		EcoParser_CtxPtr ctxNow;
		struct {
			LONGINT len[1];
			EcoParser_CtxPtr data[1];
		} *ctxStk;
		INTEGER ctxIdx;
		EcoParser_NodePtr nodFnd;
	} EcoParser_Parser;

export void EcoParser_Parser_Exec (EcoParser_Parser *prs, LONGINT *prs__typ);
export void EcoParser_Parser_Init (EcoParser_Parser *prs, LONGINT *prs__typ, EcoParser_StrPtr buf, INTEGER bufLen, INTEGER ctxDeep);
export void EcoParser_Parser_PopContext (EcoParser_Parser *prs, LONGINT *prs__typ);
export void EcoParser_Parser_PushContext (EcoParser_Parser *prs, LONGINT *prs__typ, EcoParser_CtxPtr ctx);
export void EcoParser_Parser_SetContextByPtr (EcoParser_Parser *prs, LONGINT *prs__typ, EcoParser_CtxPtr ctx);
#define __EcoParser_Parser_Exec(prs, prs__typ) __SEND(prs__typ, EcoParser_Parser_Exec, 0, void(*)(EcoParser_Parser*, LONGINT *), (prs, prs__typ))
#define __EcoParser_Parser_Init(prs, prs__typ, buf, bufLen, ctxDeep) __SEND(prs__typ, EcoParser_Parser_Init, 1, void(*)(EcoParser_Parser*, LONGINT *, EcoParser_StrPtr, INTEGER, INTEGER), (prs, prs__typ, buf, bufLen, ctxDeep))
#define __EcoParser_Parser_PopContext(prs, prs__typ) __SEND(prs__typ, EcoParser_Parser_PopContext, 2, void(*)(EcoParser_Parser*, LONGINT *), (prs, prs__typ))
#define __EcoParser_Parser_PushContext(prs, prs__typ, ctx) __SEND(prs__typ, EcoParser_Parser_PushContext, 3, void(*)(EcoParser_Parser*, LONGINT *, EcoParser_CtxPtr), (prs, prs__typ, ctx))
#define __EcoParser_Parser_SetContextByPtr(prs, prs__typ, ctx) __SEND(prs__typ, EcoParser_Parser_SetContextByPtr, 4, void(*)(EcoParser_Parser*, LONGINT *, EcoParser_CtxPtr), (prs, prs__typ, ctx))

typedef
	BOOLEAN (*EcoParser_Comparer)(EcoParser_Parser*, LONGINT *);

typedef
	void (*EcoParser_Method)(EcoParser_Parser*, LONGINT *);

typedef
	struct EcoParser_Node {
		EcoParser_NodePtr nextNode;
		EcoParser_Comparer comparer;
		INTEGER nameLen;
		EcoParser_StrPtr name;
		EcoParser_Method method;
	} EcoParser_Node;

typedef
	struct EcoParser_CtxNode { /* EcoParser_Node */
		EcoParser_NodePtr nextNode;
		EcoParser_Comparer comparer;
		INTEGER nameLen;
		EcoParser_StrPtr name;
		EcoParser_Method method;
		EcoParser_NodePtr chldNode;
		EcoParser_Method NotFound;
	} EcoParser_CtxNode;

export void EcoParser_CtxNode_AddContext (EcoParser_CtxNode *ctx, LONGINT *ctx__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound);
#define __EcoParser_CtxNode_AddContext(ctx, ctx__typ, cmp, name, name__len, notfound) __SEND(ctx__typ, EcoParser_CtxNode_AddContext, 0, void(*)(EcoParser_CtxNode*, LONGINT *, EcoParser_Comparer, CHAR*, LONGINT , EcoParser_Method), (ctx, ctx__typ, cmp, name, name__len, notfound))

typedef
	struct EcoParser_MethodNode { /* EcoParser_Node */
		EcoParser_NodePtr nextNode;
		EcoParser_Comparer comparer;
		INTEGER nameLen;
		EcoParser_StrPtr name;
		EcoParser_Method method;
	} EcoParser_MethodNode;

typedef
	EcoParser_Parser *EcoParser_ParserPtr;

typedef
	struct EcoParser_SetCtxNode { /* EcoParser_Node */
		EcoParser_NodePtr nextNode;
		EcoParser_Comparer comparer;
		INTEGER nameLen;
		EcoParser_StrPtr name;
		EcoParser_Method method;
		EcoParser_CtxPtr setCtx;
	} EcoParser_SetCtxNode;

typedef
	struct EcoParser_Tree {
		EcoParser_CtxPtr root, this, addTo;
	} EcoParser_Tree;

export void EcoParser_Tree_AddContext (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound);
export void EcoParser_Tree_AddMethod (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method meth);
export void EcoParser_Tree_AddPushContext (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound);
export void EcoParser_Tree_AddSetContext (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_CtxPtr setContext);
export void EcoParser_Tree_Init (EcoParser_Tree *tree, LONGINT *tree__typ);
export void EcoParser_Tree_To (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_CtxPtr ctx);
#define __EcoParser_Tree_AddContext(tree, tree__typ, cmp, name, name__len, notfound) __SEND(tree__typ, EcoParser_Tree_AddContext, 0, void(*)(EcoParser_Tree*, LONGINT *, EcoParser_Comparer, CHAR*, LONGINT , EcoParser_Method), (tree, tree__typ, cmp, name, name__len, notfound))
#define __EcoParser_Tree_AddMethod(tree, tree__typ, cmp, name, name__len, meth) __SEND(tree__typ, EcoParser_Tree_AddMethod, 1, void(*)(EcoParser_Tree*, LONGINT *, EcoParser_Comparer, CHAR*, LONGINT , EcoParser_Method), (tree, tree__typ, cmp, name, name__len, meth))
#define __EcoParser_Tree_AddPushContext(tree, tree__typ, cmp, name, name__len, notfound) __SEND(tree__typ, EcoParser_Tree_AddPushContext, 2, void(*)(EcoParser_Tree*, LONGINT *, EcoParser_Comparer, CHAR*, LONGINT , EcoParser_Method), (tree, tree__typ, cmp, name, name__len, notfound))
#define __EcoParser_Tree_AddSetContext(tree, tree__typ, cmp, name, name__len, setContext) __SEND(tree__typ, EcoParser_Tree_AddSetContext, 3, void(*)(EcoParser_Tree*, LONGINT *, EcoParser_Comparer, CHAR*, LONGINT , EcoParser_CtxPtr), (tree, tree__typ, cmp, name, name__len, setContext))
#define __EcoParser_Tree_Init(tree, tree__typ) __SEND(tree__typ, EcoParser_Tree_Init, 4, void(*)(EcoParser_Tree*, LONGINT *), (tree, tree__typ))
#define __EcoParser_Tree_To(tree, tree__typ, ctx) __SEND(tree__typ, EcoParser_Tree_To, 5, void(*)(EcoParser_Tree*, LONGINT *, EcoParser_CtxPtr), (tree, tree__typ, ctx))



export LONGINT *EcoParser_Tree__typ;
export LONGINT *EcoParser_Parser__typ;
export LONGINT *EcoParser_Node__typ;
export LONGINT *EcoParser_CtxNode__typ;
export LONGINT *EcoParser_MethodNode__typ;
export LONGINT *EcoParser_SetCtxNode__typ;

export BOOLEAN EcoParser_Always (EcoParser_Parser *prs, LONGINT *prs__typ);
export CHAR EcoParser_Cap (CHAR c);
export BOOLEAN EcoParser_Contains (EcoParser_Parser *prs, LONGINT *prs__typ);
static void EcoParser_Ctxt (EcoParser_Parser *prs, LONGINT *prs__typ);
export BOOLEAN EcoParser_EquAbs (EcoParser_Parser *prs, LONGINT *prs__typ);
export BOOLEAN EcoParser_EquCap (EcoParser_Parser *prs, LONGINT *prs__typ);
export BOOLEAN EcoParser_IsData (EcoParser_Parser *prs, LONGINT *prs__typ);
export BOOLEAN EcoParser_IsNull (EcoParser_Parser *prs, LONGINT *prs__typ);
export INTEGER EcoParser_Length (CHAR *str, LONGINT str__len);
export BOOLEAN EcoParser_Never (EcoParser_Parser *prs, LONGINT *prs__typ);
export EcoParser_CtxPtr EcoParser_NewContext (EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound);
export EcoParser_ParserPtr EcoParser_NewParser (EcoParser_StrPtr buf, INTEGER bufLen, INTEGER ctxDeep);
export void EcoParser_None (EcoParser_Parser *prs, LONGINT *prs__typ);
export INTEGER EcoParser_Pos (CHAR *str, LONGINT str__len, CHAR *subStr, LONGINT subStr__len, INTEGER pos);
export void EcoParser_Push (EcoParser_Parser *prs, LONGINT *prs__typ);
static void EcoParser_SetCtx (EcoParser_Parser *prs, LONGINT *prs__typ);


/*============================================================================*/

void EcoParser_Parser_SetContextByPtr (EcoParser_Parser *prs, LONGINT *prs__typ, EcoParser_CtxPtr ctx)
{
	(*prs).ctxNow = ctx;
}

/*----------------------------------------------------------------------------*/
void EcoParser_Parser_PushContext (EcoParser_Parser *prs, LONGINT *prs__typ, EcoParser_CtxPtr ctx)
{
	__ASSERT((LONGINT)(*prs).ctxIdx < (*prs).ctxStk->len[0], 0);
	((*prs).ctxStk->data)[__X((*prs).ctxIdx, (*prs).ctxStk->len[0])] = (*prs).ctxNow;
	(*prs).ctxIdx += 1;
	(*prs).ctxNow = ctx;
}

/*----------------------------------------------------------------------------*/
void EcoParser_Parser_PopContext (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	__ASSERT((*prs).ctxIdx != 0, 0);
	(*prs).ctxIdx -= 1;
	(*prs).ctxNow = ((*prs).ctxStk->data)[__X((*prs).ctxIdx, (*prs).ctxStk->len[0])];
}

/*----------------------------------------------------------------------------*/
INTEGER EcoParser_Length (CHAR *str, LONGINT str__len)
{
	INTEGER len, maxLen;
	maxLen = (int)str__len;
	len = 0;
	while (len < maxLen && str[__X(len, str__len)] != 0x00) {
		len += 1;
	}
	return len;
}

/*----------------------------------------------------------------------------*/
CHAR EcoParser_Cap (CHAR c)
{
	return __CAP(c);
}

/*----------------------------------------------------------------------------*/
INTEGER EcoParser_Pos (CHAR *str, LONGINT str__len, CHAR *subStr, LONGINT subStr__len, INTEGER pos)
{
	INTEGER i;
	if (pos == 0 || pos <= EcoParser_Length(str, str__len) - EcoParser_Length(subStr, subStr__len)) {
		while (str[__X(pos, str__len)] != 0x00) {
			i = 0;
			while (str[__X(pos + i, str__len)] == subStr[__X(i, subStr__len)] && subStr[__X(i, subStr__len)] != 0x00) {
				i += 1;
			}
			if (subStr[__X(i, subStr__len)] == 0x00) {
				return pos;
			}
			pos += 1;
		}
	}
	return -1;
}

/*----------------------------------------------------------------------------*/
void EcoParser_None (EcoParser_Parser *prs, LONGINT *prs__typ)
{
}

/*----------------------------------------------------------------------------*/
static void EcoParser_Ctxt (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	(*prs).ctxNow = __GUARDP((*prs).nodFnd, EcoParser_CtxNode, 1);
}

typedef
	EcoParser_SetCtxNode *SetCtxNodePtr__29;

static void EcoParser_SetCtx (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	(*prs).ctxNow = __GUARDP((*prs).nodFnd, EcoParser_SetCtxNode, 1)->setCtx;
}

void EcoParser_Push (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	__EcoParser_Parser_PushContext(&*prs, prs__typ, (*prs).ctxNow);
	(*prs).ctxNow = __GUARDP((*prs).nodFnd, EcoParser_CtxNode, 1);
}

/*----------------------------------------------------------------------------*/
void EcoParser_Tree_Init (EcoParser_Tree *tree, LONGINT *tree__typ)
{
	(*tree).root = NIL;
	(*tree).this = NIL;
	(*tree).addTo = NIL;
}

/*----------------------------------------------------------------------------*/
void EcoParser_Tree_To (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_CtxPtr ctx)
{
	(*tree).addTo = ctx;
}

/*----------------------------------------------------------------------------*/
void EcoParser_Tree_AddContext (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound)
{
	EcoParser_CtxPtr newCtx = NIL;
	__NEW(newCtx, EcoParser_CtxNode);
	if ((*tree).addTo != NIL) {
		newCtx->nextNode = (*tree).addTo->chldNode;
		(*tree).addTo->chldNode = (EcoParser_NodePtr)newCtx;
	} else {
		newCtx->nextNode = NIL;
	}
	newCtx->comparer = cmp;
	newCtx->nameLen = EcoParser_Length(name, name__len);
	newCtx->name = __NEWARR(NIL, 1, 1, 1, 1, (LONGINT)(name__len));
	__COPY(name, newCtx->name->data, newCtx->name->len[0]);
	newCtx->method = EcoParser_Ctxt;
	newCtx->chldNode = NIL;
	newCtx->NotFound = notfound;
	if ((*tree).this == NIL) {
		(*tree).root = newCtx;
	}
	(*tree).this = newCtx;
}

/*----------------------------------------------------------------------------*/
void EcoParser_CtxNode_AddContext (EcoParser_CtxNode *ctx, LONGINT *ctx__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound)
{
	EcoParser_CtxPtr newCtx = NIL;
	__NEW(newCtx, EcoParser_CtxNode);
	newCtx->nextNode = (*ctx).chldNode;
	(*ctx).chldNode = (EcoParser_NodePtr)newCtx;
	newCtx->comparer = cmp;
	newCtx->nameLen = EcoParser_Length(name, name__len);
	newCtx->name = __NEWARR(NIL, 1, 1, 1, 1, (LONGINT)(name__len));
	__COPY(name, newCtx->name->data, newCtx->name->len[0]);
	newCtx->method = EcoParser_Ctxt;
	newCtx->chldNode = NIL;
	newCtx->NotFound = notfound;
}

/*----------------------------------------------------------------------------*/
EcoParser_CtxPtr EcoParser_NewContext (EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound)
{
	EcoParser_CtxPtr newCtx = NIL;
	__NEW(newCtx, EcoParser_CtxNode);
	newCtx->comparer = cmp;
	newCtx->nameLen = EcoParser_Length(name, name__len);
	newCtx->name = __NEWARR(NIL, 1, 1, 1, 1, (LONGINT)(name__len));
	__COPY(name, newCtx->name->data, newCtx->name->len[0]);
	newCtx->method = EcoParser_Ctxt;
	newCtx->chldNode = NIL;
	newCtx->NotFound = notfound;
	return newCtx;
}

/*----------------------------------------------------------------------------*/
void EcoParser_Tree_AddPushContext (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound)
{
	__EcoParser_Tree_AddContext(&*tree, tree__typ, cmp, name, name__len, notfound);
	(*tree).this->method = EcoParser_Push;
}

/*----------------------------------------------------------------------------*/
void EcoParser_Tree_AddMethod (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method meth)
{
	EcoParser_MethodNode *newMeth = NIL;
	__NEW(newMeth, EcoParser_MethodNode);
	newMeth->nextNode = (*tree).addTo->chldNode;
	(*tree).addTo->chldNode = (EcoParser_NodePtr)newMeth;
	newMeth->comparer = cmp;
	newMeth->nameLen = EcoParser_Length(name, name__len);
	newMeth->name = __NEWARR(NIL, 1, 1, 1, 1, (LONGINT)(name__len));
	__COPY(name, newMeth->name->data, newMeth->name->len[0]);
	newMeth->method = meth;
}

/*----------------------------------------------------------------------------*/
void EcoParser_Tree_AddSetContext (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_CtxPtr setContext)
{
	EcoParser_SetCtxNode *newSetCtx = NIL;
	__NEW(newSetCtx, EcoParser_SetCtxNode);
	newSetCtx->nextNode = (*tree).addTo->chldNode;
	(*tree).addTo->chldNode = (EcoParser_NodePtr)newSetCtx;
	newSetCtx->comparer = cmp;
	newSetCtx->nameLen = EcoParser_Length(name, name__len);
	newSetCtx->name = __NEWARR(NIL, 1, 1, 1, 1, (LONGINT)(name__len));
	__COPY(name, newSetCtx->name->data, newSetCtx->name->len[0]);
	newSetCtx->method = EcoParser_SetCtx;
	newSetCtx->setCtx = setContext;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoParser_Never (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	return 0;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoParser_Always (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	return 1;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoParser_IsNull (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	if ((*prs).inpAvl > 0 && ((*prs).inpBuf->data)[__X((*prs).inpIdx, (*prs).inpBuf->len[0])] == 0x00) {
		(*prs).inpIdx += 1;
		(*prs).inpAvl -= 1;
		return 1;
	}
	return 0;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoParser_IsData (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	return (*prs).inpAvl > 0;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoParser_Contains (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	INTEGER pos;
	if ((*prs).nodFnd->nameLen > (*prs).inpAvl) {
		return 0;
	}
	return EcoParser_Pos((*prs).inpBuf->data, (*prs).inpBuf->len[0], (*prs).nodFnd->name->data, (*prs).nodFnd->name->len[0], 0) != -1;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoParser_EquAbs (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	INTEGER wrdLength, tmpInpIdx, tmpNodeIdx;
	if ((*prs).nodFnd->nameLen > (*prs).inpAvl) {
		return 0;
	}
	wrdLength = (*prs).nodFnd->nameLen;
	tmpInpIdx = (*prs).inpIdx;
	tmpNodeIdx = 0;
	while (wrdLength > 0) {
		if (((*prs).inpBuf->data)[__X(tmpInpIdx, (*prs).inpBuf->len[0])] != ((*prs).nodFnd->name->data)[__X(tmpNodeIdx, (*prs).nodFnd->name->len[0])]) {
			return 0;
		}
		tmpInpIdx += 1;
		tmpNodeIdx += 1;
		wrdLength -= 1;
	}
	(*prs).inpIdx = tmpInpIdx;
	(*prs).inpAvl -= (*prs).nodFnd->nameLen;
	return 1;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoParser_EquCap (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	INTEGER wrdLength, tmpInpIdx, tmpNodeIdx;
	if ((*prs).nodFnd->nameLen > (*prs).inpAvl) {
		return 0;
	}
	wrdLength = (*prs).nodFnd->nameLen;
	tmpInpIdx = (*prs).inpIdx;
	tmpNodeIdx = 0;
	while (wrdLength > 0) {
		if (EcoParser_Cap(((*prs).inpBuf->data)[__X(tmpInpIdx, (*prs).inpBuf->len[0])]) != ((*prs).nodFnd->name->data)[__X(tmpNodeIdx, (*prs).nodFnd->name->len[0])]) {
			return 0;
		}
		tmpInpIdx += 1;
		tmpNodeIdx += 1;
		wrdLength -= 1;
	}
	(*prs).inpIdx = tmpInpIdx;
	(*prs).inpAvl -= (*prs).nodFnd->nameLen;
	return 1;
}

/*----------------------------------------------------------------------------*/
void EcoParser_Parser_Init (EcoParser_Parser *prs, LONGINT *prs__typ, EcoParser_StrPtr buf, INTEGER bufLen, INTEGER ctxDeep)
{
	(*prs).inpBuf = buf;
	(*prs).inpIdx = 0;
	if (buf == NIL) {
		(*prs).inpAvl = 0;
	} else if ((LONGINT)bufLen <= buf->len[0]) {
		(*prs).inpAvl = bufLen;
	} else {
		(*prs).inpAvl = (int)buf->len[0];
	}
	if (ctxDeep != 0) {
		(*prs).ctxStk = __NEWARR(POINTER__typ, 8, 8, 1, 1, (LONGINT)ctxDeep);
		(*prs).ctxIdx = 0;
	}
}

/*----------------------------------------------------------------------------*/
void EcoParser_Parser_Exec (EcoParser_Parser *prs, LONGINT *prs__typ)
{
	(*prs).nodFnd = (*prs).ctxNow->chldNode;
	while ((*prs).nodFnd != NIL && !(*(*prs).nodFnd->comparer)(&*prs, prs__typ)) {
		(*prs).nodFnd = (*prs).nodFnd->nextNode;
	}
	if ((*prs).nodFnd != NIL) {
		(*(*prs).nodFnd->method)(&*prs, prs__typ);
	} else {
		(*(*prs).ctxNow->NotFound)(&*prs, prs__typ);
	}
}

/*----------------------------------------------------------------------------*/
EcoParser_ParserPtr EcoParser_NewParser (EcoParser_StrPtr buf, INTEGER bufLen, INTEGER ctxDeep)
{
	EcoParser_ParserPtr prsPtr = NIL;
	__NEW(prsPtr, EcoParser_Parser);
	__EcoParser_Parser_Init(&*prsPtr, __TYPEOF(prsPtr), buf, bufLen, ctxDeep);
	return prsPtr;
}

/*----------------------------------------------------------------------------*/
__TDESC(EcoParser_Tree__desc, 7, 3) = {__TDFLDS("Tree", 24), {0, 8, 16, -32}};
__TDESC(EcoParser_Parser__desc, 6, 4) = {__TDFLDS("Parser", 48), {0, 16, 24, 40, -40}};
__TDESC(EcoParser_Node__desc, 1, 2) = {__TDFLDS("Node", 40), {0, 24, -24}};
__TDESC(EcoParser_CtxNode__desc, 2, 3) = {__TDFLDS("CtxNode", 56), {0, 24, 40, -32}};
__TDESC(EcoParser_MethodNode__desc, 1, 2) = {__TDFLDS("MethodNode", 40), {0, 24, -24}};
__TDESC(EcoParser_SetCtxNode__desc, 1, 3) = {__TDFLDS("SetCtxNode", 48), {0, 24, 40, -32}};

export void *EcoParser__init(void)
{
	__DEFMOD;
	__REGMOD("EcoParser", 0);
	__INITYP(EcoParser_Tree, EcoParser_Tree, 0);
	__INITBP(EcoParser_Tree, EcoParser_Tree_AddContext, 0);
	__INITBP(EcoParser_Tree, EcoParser_Tree_AddMethod, 1);
	__INITBP(EcoParser_Tree, EcoParser_Tree_AddPushContext, 2);
	__INITBP(EcoParser_Tree, EcoParser_Tree_AddSetContext, 3);
	__INITBP(EcoParser_Tree, EcoParser_Tree_Init, 4);
	__INITBP(EcoParser_Tree, EcoParser_Tree_To, 5);
	__INITYP(EcoParser_Parser, EcoParser_Parser, 0);
	__INITBP(EcoParser_Parser, EcoParser_Parser_Exec, 0);
	__INITBP(EcoParser_Parser, EcoParser_Parser_Init, 1);
	__INITBP(EcoParser_Parser, EcoParser_Parser_PopContext, 2);
	__INITBP(EcoParser_Parser, EcoParser_Parser_PushContext, 3);
	__INITBP(EcoParser_Parser, EcoParser_Parser_SetContextByPtr, 4);
	__INITYP(EcoParser_Node, EcoParser_Node, 0);
	__INITYP(EcoParser_CtxNode, EcoParser_Node, 1);
	__INITBP(EcoParser_CtxNode, EcoParser_CtxNode_AddContext, 0);
	__INITYP(EcoParser_MethodNode, EcoParser_Node, 1);
	__INITYP(EcoParser_SetCtxNode, EcoParser_Node, 1);
/* BEGIN */
	__ENDMOD;
}
