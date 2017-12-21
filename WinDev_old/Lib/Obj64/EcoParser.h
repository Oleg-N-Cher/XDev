/*  Ofront 1.2 -xtspkae */

#ifndef EcoParser__h
#define EcoParser__h

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
		char _prvt0[16];
		EcoParser_NodePtr nodFnd;
	} EcoParser_Parser;

import void EcoParser_Parser_Exec (EcoParser_Parser *prs, LONGINT *prs__typ);
import void EcoParser_Parser_Init (EcoParser_Parser *prs, LONGINT *prs__typ, EcoParser_StrPtr buf, INTEGER bufLen, INTEGER ctxDeep);
import void EcoParser_Parser_PopContext (EcoParser_Parser *prs, LONGINT *prs__typ);
import void EcoParser_Parser_PushContext (EcoParser_Parser *prs, LONGINT *prs__typ, EcoParser_CtxPtr ctx);
import void EcoParser_Parser_SetContextByPtr (EcoParser_Parser *prs, LONGINT *prs__typ, EcoParser_CtxPtr ctx);
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

import void EcoParser_CtxNode_AddContext (EcoParser_CtxNode *ctx, LONGINT *ctx__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound);
#define __EcoParser_CtxNode_AddContext(ctx, ctx__typ, cmp, name, name__len, notfound) __SEND(ctx__typ, EcoParser_CtxNode_AddContext, 0, void(*)(EcoParser_CtxNode*, LONGINT *, EcoParser_Comparer, CHAR*, LONGINT , EcoParser_Method), (ctx, ctx__typ, cmp, name, name__len, notfound))

typedef
	EcoParser_Parser *EcoParser_ParserPtr;

typedef
	struct EcoParser_Tree {
		char _prvt0[8];
		EcoParser_CtxPtr this, addTo;
	} EcoParser_Tree;

import void EcoParser_Tree_AddContext (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound);
import void EcoParser_Tree_AddMethod (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method meth);
import void EcoParser_Tree_AddPushContext (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound);
import void EcoParser_Tree_AddSetContext (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_CtxPtr setContext);
import void EcoParser_Tree_Init (EcoParser_Tree *tree, LONGINT *tree__typ);
import void EcoParser_Tree_To (EcoParser_Tree *tree, LONGINT *tree__typ, EcoParser_CtxPtr ctx);
#define __EcoParser_Tree_AddContext(tree, tree__typ, cmp, name, name__len, notfound) __SEND(tree__typ, EcoParser_Tree_AddContext, 0, void(*)(EcoParser_Tree*, LONGINT *, EcoParser_Comparer, CHAR*, LONGINT , EcoParser_Method), (tree, tree__typ, cmp, name, name__len, notfound))
#define __EcoParser_Tree_AddMethod(tree, tree__typ, cmp, name, name__len, meth) __SEND(tree__typ, EcoParser_Tree_AddMethod, 1, void(*)(EcoParser_Tree*, LONGINT *, EcoParser_Comparer, CHAR*, LONGINT , EcoParser_Method), (tree, tree__typ, cmp, name, name__len, meth))
#define __EcoParser_Tree_AddPushContext(tree, tree__typ, cmp, name, name__len, notfound) __SEND(tree__typ, EcoParser_Tree_AddPushContext, 2, void(*)(EcoParser_Tree*, LONGINT *, EcoParser_Comparer, CHAR*, LONGINT , EcoParser_Method), (tree, tree__typ, cmp, name, name__len, notfound))
#define __EcoParser_Tree_AddSetContext(tree, tree__typ, cmp, name, name__len, setContext) __SEND(tree__typ, EcoParser_Tree_AddSetContext, 3, void(*)(EcoParser_Tree*, LONGINT *, EcoParser_Comparer, CHAR*, LONGINT , EcoParser_CtxPtr), (tree, tree__typ, cmp, name, name__len, setContext))
#define __EcoParser_Tree_Init(tree, tree__typ) __SEND(tree__typ, EcoParser_Tree_Init, 4, void(*)(EcoParser_Tree*, LONGINT *), (tree, tree__typ))
#define __EcoParser_Tree_To(tree, tree__typ, ctx) __SEND(tree__typ, EcoParser_Tree_To, 5, void(*)(EcoParser_Tree*, LONGINT *, EcoParser_CtxPtr), (tree, tree__typ, ctx))



import LONGINT *EcoParser_Tree__typ;
import LONGINT *EcoParser_Parser__typ;
import LONGINT *EcoParser_Node__typ;
import LONGINT *EcoParser_CtxNode__typ;

import BOOLEAN EcoParser_Always (EcoParser_Parser *prs, LONGINT *prs__typ);
import CHAR EcoParser_Cap (CHAR c);
import BOOLEAN EcoParser_Contains (EcoParser_Parser *prs, LONGINT *prs__typ);
import BOOLEAN EcoParser_EquAbs (EcoParser_Parser *prs, LONGINT *prs__typ);
import BOOLEAN EcoParser_EquCap (EcoParser_Parser *prs, LONGINT *prs__typ);
import BOOLEAN EcoParser_IsData (EcoParser_Parser *prs, LONGINT *prs__typ);
import BOOLEAN EcoParser_IsNull (EcoParser_Parser *prs, LONGINT *prs__typ);
import INTEGER EcoParser_Length (CHAR *str, LONGINT str__len);
import BOOLEAN EcoParser_Never (EcoParser_Parser *prs, LONGINT *prs__typ);
import EcoParser_CtxPtr EcoParser_NewContext (EcoParser_Comparer cmp, CHAR *name, LONGINT name__len, EcoParser_Method notfound);
import EcoParser_ParserPtr EcoParser_NewParser (EcoParser_StrPtr buf, INTEGER bufLen, INTEGER ctxDeep);
import void EcoParser_None (EcoParser_Parser *prs, LONGINT *prs__typ);
import INTEGER EcoParser_Pos (CHAR *str, LONGINT str__len, CHAR *subStr, LONGINT subStr__len, INTEGER pos);
import void EcoParser_Push (EcoParser_Parser *prs, LONGINT *prs__typ);
import void *EcoParser__init(void);


#endif
