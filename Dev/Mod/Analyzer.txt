MODULE DevAnalyzer;
(**
	project	= "BlackBox"
	organization	= "www.oberon.ch"
	contributors	= "Oberon microsystems"
	version	= "System/Rsrc/About"
	copyright	= "System/Rsrc/About"
	license	= "Docu/BB-License"
	changes	= ""
	issues	= ""

**)

	IMPORT
		TextMappers, TextModels, TextViews, DevMarkers, Stores, Models, Kernel, Dialog, StdLog, Files,
		CPT := DevCPT, CPS := DevCPS, CPM := DevCPM, CPB := DevCPB, HostRegistry;
		
	CONST
		(* numtyp values *)
		char = 1; integer = 2; real = 4; int64 = 5; real32 = 6; real64 = 7;

		(*symbol values*)
		null = 0; times = 1;
		and = 5; plus = 6; minus = 7; or = 8; eql = 9;
		leq = 12; geq = 14;
		in = 15; is = 16; arrow = 17; dollar = 18; period = 19;
		comma = 20; colon = 21; upto = 22; rparen = 23; rbrak = 24;
		rbrace = 25; of = 26; then = 27; do = 28; to = 29;
		by = 30; not = 33;
		lparen = 40; lbrak = 41; lbrace = 42; becomes = 44;
		number = 45; nil = 46; string = 47; ident = 48; semicolon = 49;
		bar = 50; end = 51; else = 52; elsif = 53; until = 54;
		if = 55; case = 56; while = 57; repeat = 58; for = 59;
		loop = 60; with = 61; exit = 62; return = 63; array = 64;
		record = 65; pointer = 66; begin = 67; const = 68; type = 69;
		var = 70; out = 71; procedure = 72; close = 73; import = 74;
		module = 75; eof = 76;

		(* object modes *)
		Var = 1; VarPar = 2; Con = 3; Fld = 4; Typ = 5; LProc = 6; XProc = 7;
		SProc = 8; CProc = 9; IProc = 10; Mod = 11; TProc = 13; Attr = 20;

		(* Structure forms *)
		Undef = 0; Byte = 1; Bool = 2; Char8 = 3; Int8 = 4; Int16 = 5; Int32 = 6;
		Set = 9;
		Pointer = 13; ProcTyp = 14; Comp = 15;
		Char16 = 16; Int64 = 18;
		intSet = {Int8..Int32, Int64}; charSet = {Char8, Char16};
		
		(* composite structure forms *)
		Basic = 1; Array = 2; DynArr = 3; Record = 4;

		(*function number*)
		newfn = 1; incfn = 13; sysnewfn = 30;
		(*<< function number*)
		ordfn = 4;
		minfn = 7; maxfn = 8; chrfn = 9;
		sizefn = 12; decfn = 14;
		inclfn = 15; exclfn = 16; lenfn = 17; bitsfn = 37;
		(*<< SYSTEM function number*)
		adrfn = 20;
		getfn = 24; getrfn = 26;
		valfn = 29;

		(* nodes classes *)
		Nvar = 0; Nvarpar = 1; Nfield = 2; Nderef = 3; Nindex = 4;
		Nconst = 7; Ntype = 8; Nproc = 9; Ncall = 13;
		Nif = 15; Ncaselse = 16; Ncasedo = 17;
		Nifelse = 20; Ncase = 21; Nwhile = 22; Nrepeat = 23; Nloop = 24; Nexit = 25;
		Nwith = 27; Ncomp = 30;

		(* node subclasses *)
		super = 1;
		
		(* module visibility of objects *)
		internal = 0; external = 1; externalR = 2; inPar = 3; outPar = 4;

		(* procedure flags (conval.setval) *)
		hasBody = 1; isRedef = 2;
		
		(* attribute flags (attr.adr, struct.attribute, proc.conval.setval)*)
		newAttr = 16; absAttr = 17; limAttr = 18; empAttr = 19; extAttr = 20;
		
		(* case statement flags (conval.setval) *)
		useTable = 1; useTree = 2;
		
		(* sysflags *)
		inBit = 2; outBit = 4; newBit = 8; iidBit = 16; interface = 10;
		
		clean = CPM.ConstNotAlloc;	(*<< values for obj.linkadr: untouched *)
		used = clean+1; usedSet = clean+2; set = clean+3;	(*<< used, used then set, set *)
		setUsed = clean+4; setUsedP = clean+5;	(*<< set then used, possibly set and used (var par) *)
		noChange = (setUsedP+15) DIV 16 * 16;	(*<< for loop variables shouldn't be changed *)

		(*<< error messages *)
		neverUsed = 900; neverSet = 901; usedBSet = 902; setBNUsed = 903; usedVarPar = 904;
		outerScope = 905; interAcc = 906; (*redefinition = 907; newdefinition = 908;*)
		statAfterRetEx = 909; loopVarSet = 910; (*impliedTypeGuard = 911;*)
		superfluousTypeGuard = 912; evaluationSeq = 913; superfluousShort = 914;

		semicolons = 930;	(*<< special stuff *)
		
		(*<< selector flags for Selector *)
		SelAssign = TRUE; SelNoAssign = FALSE;
		SelVarPar = TRUE; SelNoVarPar = FALSE;
		SelUseBSet = TRUE; SelNoUseBSet = FALSE;

		Version = "DevAnalyzer for Component Pascal  (c) SHML  24 Mar 1998";
		OptionsFile = "AnaOpt"; OptionsType = "opt"; OptionsPath = "Dev/Rsrc";	(*<<O/F*)
		
		regKey = "Dev\Analyzer\";
		
	TYPE
		Elem = POINTER TO RECORD
			next: Elem;
			struct: CPT.Struct;
			obj, base: CPT.Object;
			pos: INTEGER;
			name: CPT.String
		END;
		
		
		Warning = POINTER TO RECORD	(*<< list of warning positions *)
			next: Warning;
			n: SHORTINT;
			pos: INTEGER
		END;

	VAR
		options*: RECORD	(*<<O/F*)
			varpar*, exported*, intermediate*, levels*, tbProcs*,
			sideEffects*, semicolons*: BOOLEAN;
			statements-: INTEGER; fileName-: TextMappers.String
		END;
		errHead: Warning;	(*<< root for warning position list *)
		nofStats: INTEGER;	(*<< number of statements in module *)
		sourceR: TextModels.Reader;
		str: Dialog.String;

		sym, level: BYTE;
		LoopLevel: SHORTINT;
		TDinit, lastTDinit: CPT.Node;
		userList: Elem;
		recList: Elem;
		hasReturn: BOOLEAN;
		
	PROCEDURE^ Type(VAR typ: CPT.Struct; VAR name: CPT.String);
	PROCEDURE^ Expression(VAR x: CPT.Node);
	PROCEDURE^ Block(VAR procdec, statseq: CPT.Node);
	
	(* forward type handling *)
	
	PROCEDURE IncompleteType (typ: CPT.Struct): BOOLEAN;
	BEGIN
		IF typ.form = Pointer THEN typ := typ.BaseTyp END;
		RETURN (typ = CPT.undftyp) OR (typ.comp = Record) & (typ.BaseTyp = CPT.undftyp)
	END IncompleteType;
	
	PROCEDURE SetType (struct: CPT.Struct; obj: CPT.Object; typ: CPT.Struct; name: CPT.String);
		VAR u: Elem;
	BEGIN
		IF obj # NIL THEN obj.typ := typ ELSE struct.BaseTyp := typ END;
		IF name # NIL THEN
			NEW(u); u.struct := struct; u.obj := obj; u.pos := CPM.errpos; u.name := name;
			u.next := userList; userList := u
		END
	END SetType;

	PROCEDURE CheckAlloc (VAR typ: CPT.Struct; dynAllowed: BOOLEAN; pos: INTEGER);
	BEGIN
		typ.pvused := TRUE;
		IF typ.comp = DynArr THEN
			IF ~dynAllowed THEN CPM.Mark(88, pos); typ := CPT.undftyp END
		ELSIF typ.comp = Record THEN
			IF (typ.attribute = absAttr) OR (typ.attribute = limAttr) & (typ.mno # 0) THEN
				CPM.Mark(193, pos); typ := CPT.undftyp
			END
		END
	END CheckAlloc;

	PROCEDURE CheckRecursiveType (outer, inner: CPT.Struct; pos: INTEGER);
		VAR fld: CPT.Object;
	BEGIN
		IF outer = inner THEN CPM.Mark(58, pos)
		ELSIF inner.comp IN {Array, DynArr} THEN CheckRecursiveType(outer, inner.BaseTyp, pos)
		ELSIF inner.comp = Record THEN
			fld := inner.link;
			WHILE (fld # NIL) & (fld.mode = Fld) DO
				CheckRecursiveType(outer, fld.typ, pos);
				fld := fld.link
			END;
			IF inner.BaseTyp # NIL THEN CheckRecursiveType(outer, inner.BaseTyp, pos) END
		END
	END CheckRecursiveType;
	
	PROCEDURE FixType (struct: CPT.Struct; obj: CPT.Object; typ: CPT.Struct; pos: INTEGER);	(* fix forward reference *)
		VAR t: CPT.Struct; f, bf: CPT.Object; i: SHORTINT;
	BEGIN
		IF obj # NIL THEN
			IF obj.mode = Var THEN	(* variable type *)
				IF struct # NIL THEN	(* receiver type *)
					IF (typ.form # Pointer) OR (typ.BaseTyp # struct) THEN CPM.Mark(180, pos) END
				ELSE CheckAlloc(typ, obj.mnolev > level, pos)	(* TRUE for parameters *)
				END
			ELSIF obj.mode = VarPar THEN	(* varpar type *)
				IF struct # NIL THEN	(* varpar receiver type *)
					IF typ # struct THEN CPM.Mark(180, pos) END
				END
			ELSIF obj.mode = Fld THEN	(* field type *)
				CheckAlloc(typ, FALSE, pos);
				CheckRecursiveType(struct, typ, pos)
			ELSIF obj.mode = TProc THEN	(* proc return type *)
				IF typ.form = Comp THEN typ := CPT.undftyp; CPM.Mark(54, pos) END
			ELSIF obj.mode = Typ THEN	(* alias type *)
				IF typ.form IN {Byte..Set, Char16, Int64} THEN	(* make alias structure *)
					t := CPT.NewStr(typ.form, Basic); i := t.ref;
					t^ := typ^; t.ref := i; t.strobj := obj; t.mno := 0;
					t.BaseTyp := typ; typ := t
				END;
				IF obj.vis # internal THEN
					IF typ.comp = Record THEN typ.exp := TRUE
					ELSIF typ.form = Pointer THEN typ.BaseTyp.exp := TRUE
					END
				END
			ELSE HALT(100)
			END;
			obj.typ := typ
		ELSE
			IF struct.form = Pointer THEN	(* pointer base type *)
				IF typ.comp = Record THEN CPM.PropagateRecPtrSysFlag(typ.sysflag, struct.sysflag)
				ELSIF typ.comp IN {Array, DynArr} THEN CPM.PropagateArrPtrSysFlag(typ.sysflag, struct.sysflag)
				ELSE typ := CPT.undftyp; CPM.Mark(57, pos)
				END;
				struct.untagged := struct.sysflag # 0;
				IF (struct.strobj # NIL) & (struct.strobj.vis # internal) THEN typ.exp := TRUE END
			ELSIF struct.comp = Array THEN	(* array base type *)
				CheckAlloc(typ, FALSE, pos);
				CheckRecursiveType(struct, typ, pos)
			ELSIF struct.comp = DynArr THEN	(* array base type *)
				CheckAlloc(typ, TRUE, pos);
				CheckRecursiveType(struct, typ, pos)
			ELSIF struct.comp = Record THEN	(* record base type *)
				IF typ.form = Pointer THEN typ := typ.BaseTyp END;
				typ.pvused := TRUE; struct.extlev := SHORT(SHORT(typ.extlev + 1));
				CPM.PropagateRecordSysFlag(typ.sysflag, struct.sysflag);
				IF (typ.attribute = 0) OR (typ.attribute = limAttr) & (typ.mno # 0) THEN CPM.Mark(181, pos)
				ELSIF (struct.attribute = absAttr) & (typ.attribute # absAttr) THEN CPM.Mark(191, pos)
				ELSIF (typ.attribute = limAttr) & (struct.attribute # limAttr) THEN CPM.Mark(197, pos)
				END;
				f := struct.link;
				WHILE f # NIL DO	(* check for field name conflicts *)
					CPT.FindField(f.name, typ, bf);
					IF bf # NIL THEN CPM.Mark(1, pos) END;
					f := f.link
				END;
				CheckRecursiveType(struct, typ, pos);
				struct.untagged := struct.sysflag # 0
			ELSIF struct.form = ProcTyp THEN	(* proc type return type *)
				IF typ.form = Comp THEN typ := CPT.undftyp; CPM.Mark(54, pos) END;
			ELSE HALT(100)
			END;
			struct.BaseTyp := typ
		END
	END FixType;

	PROCEDURE CheckForwardTypes;
		VAR u, next: Elem; progress: BOOLEAN;
	BEGIN
		u := userList; userList := NIL;
		WHILE u # NIL DO
			next := u.next; CPS.name := u.name^$; CPT.Find(CPS.name, u.base);
			IF u.base = NIL THEN CPM.Mark(0, u.pos)
			ELSIF u.base.mode # Typ THEN CPM.Mark(72, u.pos)
			ELSE u.next := userList; userList := u;	(* reinsert *)
				IF u.base.num < set THEN (* BJ: If already also used, don't reset *)
					u.base.num := set	(*<< forward types are set by default *)
				END
			END;
			u := next
		END;
		REPEAT	(* iteration for multy level alias *)
			u := userList; userList := NIL; progress := FALSE;
			WHILE u # NIL DO
				next := u.next;
				IF IncompleteType(u.base.typ) THEN
					u.next := userList; userList := u	(* reinsert *)
				ELSE
					progress := TRUE;
					FixType(u.struct, u.obj, u.base.typ, u.pos)
				END;
				u := next
			END
		UNTIL (userList = NIL) OR ~progress;
		u := userList;	(* remaining type relations are cyclic *)
		WHILE u # NIL DO
			IF (u.obj = NIL) OR (u.obj.mode = Typ) THEN CPM.Mark(58, u.pos) END;
			u := u.next
		END
	END CheckForwardTypes;
	
	PROCEDURE CheckUnimpl (m: CPT.Object; typ: CPT.Struct; pos: INTEGER);
		VAR obj: CPT.Object;
	BEGIN
		IF m # NIL THEN
			IF (m.mode = TProc) & (absAttr IN m.conval.setval) THEN
				CPT.FindField(m.name^, typ, obj);
				IF (obj = NIL) OR (obj.mode # TProc) OR (absAttr IN obj.conval.setval) THEN
					CPM.Mark(192, pos);
					CPM.LogWLn; CPM.LogWStr("  "); CPM.LogWStr(m.name^);
					CPM.LogWStr(" not implemented in "); CPM.LogWStr(typ.strobj.name^)
				END
			END;
			CheckUnimpl(m.left, typ, pos);
			CheckUnimpl(m.right, typ, pos)
		END
	END CheckUnimpl;
	
	PROCEDURE CheckRecords (rec: Elem);
		VAR b: CPT.Struct;
	BEGIN
		WHILE rec # NIL DO	(* check for unimplemented methods in base type *)
			b := rec.struct.BaseTyp;
			WHILE (b # NIL) & (b # CPT.undftyp) DO
				CheckUnimpl(b.link, rec.struct, rec.pos);
				b := b.BaseTyp
			END;
			rec := rec.next
		END
	END CheckRecords;


	PROCEDURE err(n: SHORTINT);
	BEGIN CPM.err(n)
	END err;

	PROCEDURE CheckSym(s: SHORTINT);
	BEGIN
		IF sym = s THEN CPS.Get(sym) ELSE CPM.err(s) END
	END CheckSym;

	PROCEDURE err2(n: SHORTINT; pos: INTEGER);	(*<<*)
		VAR e, h: Warning;
	BEGIN
		e := errHead;
		WHILE (e.next # NIL) & (e.next.pos < pos) DO e := e.next END;
		IF e.next = NIL THEN 
			NEW(e.next); h := e.next	(* end of list *)
		ELSIF (e.next.pos = pos) & (e.next.n = n) THEN 
			RETURN	(* don't allow duplicates *)
		ELSE 
			NEW(h); h.next := e.next; e.next := h
		END;
		h.n := n; h.pos := pos
	END err2;


	PROCEDURE DumpObj(obj: CPT.Object);							
(*	BEGIN
		CPM.LogWStr("message for object: "); CPM.LogWStr(obj.name); CPM.LogWLn
*)	END DumpObj;


	PROCEDURE CheckScope(scope: CPT.Object);	(*<<*)

		PROCEDURE^ Check(obj: CPT.Object);

		PROCEDURE CheckTyp(typ: CPT.Struct);
		BEGIN
			IF (typ.form = Pointer) & (typ.BaseTyp.strobj = NIL) THEN	(* only if PTR TO RECORD END *)
				typ := typ.BaseTyp
			END;
			IF (typ.form = Comp) & (typ.comp = Record) THEN Check(typ.link) END
		END CheckTyp;

		PROCEDURE Check(obj: CPT.Object);
		BEGIN
			IF obj # NIL THEN
				Check(obj.left);
				IF (obj.num # setUsed) & (options.exported OR (obj.vis = internal) OR (obj.mode = Mod)) THEN
					CASE obj.mode OF
					| Var, VarPar, Fld:
						CASE obj.num OF
						| clean: DumpObj(obj); err2(neverUsed, obj.adr) 
						(* | used: DumpObj(obj); err2(neverSet, obj.adr) *)
						| used: IF obj.name[0] # "@" THEN DumpObj(obj); err2(neverSet, obj.adr) END
						| usedSet: IF obj.mode # Fld THEN DumpObj(obj); err2(usedBSet, obj.adr) END
						| set: DumpObj(obj); err2(setBNUsed, obj.adr);
						| setUsedP: IF options.varpar & (obj.mode # Fld) THEN DumpObj(obj); err2(usedVarPar, obj.adr); END
						END;
						IF obj.typ.strobj = NIL THEN CheckTyp(obj.typ) END	(*x: RECORD ... END*)
					| Con, Typ: CASE obj.num OF set: DumpObj(obj); err2(neverUsed, obj.adr) END
					| LProc, XProc, CProc, IProc: CASE obj.num OF set: DumpObj(obj); err2(neverUsed, obj.adr) END
					| TProc:	(* neverUsed not determinable for redefined methods because of dynamic binding *)
						(* IF ((obj.link.typ.form = Pointer) & (obj.link.typ.BaseTyp.BaseTyp = NIL) OR
								(* (obj.link.typ.comp = Record) & *) (obj.link.typ.BaseTyp = NIL)) & (obj.num = set) THEN*)
						(* BJ: Changed this IF to correct ABSTRACT and EMPTY procedures*)
						IF ~(absAttr IN obj.conval.setval) & ~(empAttr IN obj.conval.setval) &
							((obj.link.typ.form = Pointer) & (obj.link.typ.BaseTyp.BaseTyp = NIL) OR 
							 (obj.link.typ.BaseTyp = NIL)) & (obj.num = set) THEN 
							DumpObj(obj); err2(neverUsed, obj.adr)
						END
					| Mod: DumpObj(obj); err2(neverUsed, obj.adr)
					ELSE
					END
				END;	(*IF*)
				CASE obj.mode OF
				| LProc, XProc, IProc, TProc: CheckScope(obj.scope)
				| Typ:
					IF obj.typ.mno = 0 THEN
						CheckTyp(obj.typ)	(* checking of fields and type bound procedures, only if not imported type! *)
					END
				ELSE
				END;
				Check(obj.right)
			END
		END Check;

	BEGIN Check(scope.right)
	END CheckScope;

	PROCEDURE CheckOuter;	(*<< check outer scopes for obj with OPS.name*)
		VAR o: CPT.Object;
	BEGIN
		IF options.intermediate THEN
			CPT.Find(CPS.name, o);
			IF o # NIL THEN DumpObj(o); err2(outerScope, CPM.curpos) END
		END
	END CheckOuter;

	PROCEDURE UseType(obj: CPT.Object; pos: INTEGER);	(*<< type obj gets used*)
	BEGIN
		IF (obj # NIL) & ((obj.vis = internal) OR options.exported) THEN
			IF options.intermediate & (obj.mnolev # level) & (obj.mnolev > 0) THEN	(*mnolev > 0 -> intermediate*)
				DumpObj(obj); err2(interAcc, pos)
			END;
			CASE obj.num OF clean, set: obj.num := setUsed
			| used, setUsed:	(* used only for non-declarded type *)
			END
		END
	END UseType;

	PROCEDURE UseObj(obj: CPT.Object; markUseBSet: BOOLEAN; pos: INTEGER);	(*<< obj gets used *)
	BEGIN
		IF (obj # NIL) & (obj.mnolev >= 0) THEN
			IF options.intermediate & (obj.mnolev # level) & (obj.mnolev > 0) & (obj.mode < LProc) THEN
				DumpObj(obj); err2(interAcc, pos)
			END;
			CASE obj.num OF
			| clean:
				IF (obj.mode = Con) OR (obj.mode # Fld) & (obj.mnolev # level) & ~options.levels THEN
					obj.num := setUsed
				ELSE
					obj.num := used;
					IF markUseBSet & (obj.mode # SProc) & (obj.mode # Fld) & (obj.typ.form # Comp) THEN
						DumpObj(obj); err2(usedBSet, pos)
					END
				END
			| set: obj.num := setUsed
			| used, usedSet, setUsed, setUsedP, setUsed+noChange, setUsedP+noChange:
			END
		END
	END UseObj;

	PROCEDURE SetObj(obj: CPT.Object; varPar: BOOLEAN; pos: INTEGER);	(*<< var/proc/const/field obj gets set*)
	BEGIN
		IF (obj # NIL) & (obj.mnolev >= 0) THEN
			CASE obj.num OF
			| clean: IF varPar THEN obj.num := setUsedP ELSE obj.num := set END
			| used:
				IF varPar THEN obj.num := setUsedP
				ELSIF (obj.mnolev = level) OR options.levels THEN obj.num := usedSet
				ELSIF ~options.levels THEN obj.num := setUsed
				END
			| usedSet, setUsed, setUsedP:
			| set: IF varPar THEN obj.num := setUsed END
			| setUsed+noChange, setUsedP+noChange: DumpObj(obj); err2(loopVarSet, pos) (* for loop variable gets set!*)
			END
		END
	END SetObj;

	PROCEDURE Selector(x: CPT.Node; assignment, varPar, markUseBSet: BOOLEAN; pos: INTEGER);	(*<<*)
	BEGIN		
		IF assignment THEN
			CASE x.class OF
			| Nvar, Nvarpar, Nfield:
				IF (x.class # Nfield) & options.intermediate & (x.obj.mnolev # level) & (x.obj.mnolev > 0) THEN
					DumpObj(x.obj); err2(interAcc, pos)	(* assignment to intermediate *)
				END;
				SetObj(x.obj, varPar, pos); x := x.left;	(* assignment to b in {a.}b := ... *)
			| Nindex:	(* assignment to b in {a.}b{[i]} := ... *)
				REPEAT x := x.left UNTIL x.class # Nindex;
				IF x.class IN {Nvar, Nvarpar, Nfield} THEN SetObj(x.obj, varPar, pos); x := x.left END
			ELSE
			END;
			WHILE (x # NIL) & (x.class IN {Nvar, Nvarpar, Nfield}) DO SetObj(x.obj, varPar, pos); x := x.left END 
		END;
		WHILE x # NIL DO
			IF x.class IN {Nvar, Nvarpar, Nfield, Nconst, Nproc} THEN UseObj(x.obj, markUseBSet, pos); END; 
			x := x.left
		END
	END Selector;

	PROCEDURE qualident(VAR id: CPT.Object);
		VAR obj: CPT.Object; lev: BYTE; m: BOOLEAN;
	BEGIN (*sym = ident*)
		CPT.Find(CPS.name, obj); CPS.Get(sym);
		m := FALSE;	(*<<*)
		IF (sym = period) & (obj # NIL) & (obj.mode = Mod) THEN
			obj.num := setUsed;	(*<< module gets used (set by default) *)
			m := TRUE;	(*<< it's a module! *)
			CPS.Get(sym);
			IF sym = ident THEN
				CPT.FindImport(CPS.name, obj, obj); CPS.Get(sym)
			ELSE err(ident); obj := NIL
			END
		END ;
		IF obj = NIL THEN err(0);
			obj := CPT.NewObj(); obj.mode := Var; obj.typ := CPT.undftyp; obj.adr := 0
		ELSE lev := obj.mnolev;
			IF (obj.mode IN {Var, VarPar}) & (lev # level) THEN
				obj.leaf := FALSE;
				IF lev > 0 THEN CPB.StaticLink(SHORT(SHORT(level-lev)), TRUE) END	(* !!! *)
			END
		END ;
		IF m & (obj # NIL) THEN obj.num := setUsed END;	(*<< imported obj get used always! *)
		id := obj
	END qualident;

	PROCEDURE ConstExpression(VAR x: CPT.Node);
	BEGIN Expression(x);
		IF x.class # Nconst THEN
			err(50); x := CPB.NewIntConst(1) 
		END
	END ConstExpression;

	PROCEDURE CheckMark(obj: CPT.Object);	(* !!! *)
	BEGIN 
		CPS.Get(sym);
		IF (sym = times) OR (sym = minus) THEN
			IF (level > 0) OR ~(obj.mode IN {Var, Fld, TProc}) & (sym = minus) THEN err(41) END ;
			IF sym = times THEN obj.vis := external ELSE obj.vis := externalR END ;
			CPS.Get(sym)
		ELSE obj.vis := internal
		END;
		IF (obj.mode IN {LProc, XProc, Var, Typ}) & (sym = lbrak) THEN
			CPS.Get(sym);
			IF sym = string THEN
				IF obj.conval = NIL THEN obj.conval := CPT.NewConst() END;
				IF CPS.str^ # "" THEN obj.conval.ext := CPS.str END;
				CPS.Get(sym);
				IF sym = comma THEN
					CPS.Get(sym);
					IF sym = string THEN
						IF obj.conval.ext # NIL THEN
							obj.conval.link := CPT.NewConst(); obj.conval.link.ext := obj.conval.ext
						END;
						obj.conval.ext := NIL;
						IF CPS.str^ # "" THEN obj.conval.ext := CPS.str END;
						CPS.Get(sym)
					ELSE err(string)
					END
				END
			ELSE err(string)
			END;
			CheckSym(rbrak);
			IF ~(CPM.interface IN CPM.options) THEN err(225) END
		END
	END CheckMark;

	PROCEDURE CheckSysFlag (VAR sysflag: SHORTINT;
										GetSF: PROCEDURE(id: ARRAY OF SHORTCHAR; num: SHORTINT; VAR flag: SHORTINT));
		VAR x: CPT.Object; i: SHORTINT;
	BEGIN
		sysflag := 0;
		IF sym = lbrak THEN
			CPS.Get(sym);
			WHILE (sym = number) OR (sym = ident) OR (sym = string) DO
				IF sym = number THEN
					IF CPS.numtyp = integer THEN
						i := SHORT(CPS.intval); GetSF("", i, sysflag)
					ELSE err(225)
					END
				ELSIF sym = ident THEN
					CPT.Find(CPS.name, x);
					IF (x # NIL) & (x.mode = Con) & (x.typ.form IN {Int8, Int16, Int32}) THEN 
						i := SHORT(x.conval.intval); GetSF("", i, sysflag)
					ELSE
						GetSF(CPS.name, 0, sysflag)
					END
				ELSE
					GetSF(CPS.str^, 0, sysflag)
				END;
				CPS.Get(sym);
				IF (sym = comma) OR (sym = plus) THEN CPS.Get(sym) END
			END;
			CheckSym(rbrak)
		END
	END CheckSysFlag;
	
	PROCEDURE Receiver(VAR mode, vis: BYTE; VAR name: CPT.Name; VAR typ, rec: CPT.Struct);
		VAR obj: CPT.Object;tname: CPT.String;
	BEGIN 
		typ := CPT.undftyp; rec := NIL; vis := 0;
		IF sym = var THEN CPS.Get(sym); mode := VarPar
		ELSIF sym = in THEN CPS.Get(sym); mode := VarPar; vis := inPar	(* ??? *)
		ELSE mode := Var
		END ;
		name := CPS.name; CheckSym(ident); CheckSym(colon);
		IF sym # ident THEN err(ident) END;
		Type(typ, tname);
		IF tname = NIL THEN
			IF typ.form = Pointer THEN  rec := typ.BaseTyp ELSE rec := typ END;
			IF ~((mode = Var) & (typ.form = Pointer) & (rec.comp = Record) OR
				(mode = VarPar) & (typ.comp = Record)) THEN err(70); rec := NIL END;
			IF (rec # NIL) & (rec.mno # level) THEN err(72); rec := NIL END
		ELSE err(0)
		END;
		CheckSym(rparen);
		IF rec = NIL THEN rec := CPT.NewStr(Comp, Record); rec.BaseTyp := NIL END
	END Receiver;
	
	PROCEDURE FormalParameters(VAR firstPar: CPT.Object; VAR resTyp: CPT.Struct; VAR name: CPT.String);
		VAR mode, vis: BYTE; sys: SHORTINT;
				par, first, last, newPar, iidPar: CPT.Object; typ: CPT.Struct;
	BEGIN
		first := NIL; last := firstPar;
		newPar := NIL; iidPar := NIL;
		IF (sym = ident) OR (sym = var) OR (sym = in) OR (sym = out) THEN
			LOOP
				sys := 0; vis := 0;
				IF sym = var THEN CPS.Get(sym); mode := VarPar
				ELSIF sym = in THEN CPS.Get(sym); mode := VarPar; vis := inPar
				ELSIF sym = out THEN CPS.Get(sym); mode := VarPar; vis := outPar
				ELSE mode := Var
				END ;
				IF mode = VarPar THEN CheckSysFlag(sys, CPM.GetVarParSysFlag) END;
				IF ODD(sys DIV inBit) THEN vis := inPar
				ELSIF ODD(sys DIV outBit) THEN vis := outPar
				END;
				IF ODD(sys DIV newBit) & (vis # outPar) THEN err(225)
				ELSIF ODD(sys DIV iidBit) & (vis # inPar) THEN err(225)
				END;
				LOOP
					IF sym = ident THEN
						CheckOuter;	(*<<*)
						CPT.Insert(CPS.name, par); CPS.Get(sym);
						par.adr := CPM.errpos;	(*<<*)
						par.mode := mode; par.link := NIL; par.vis := vis; par.sysflag := SHORT(sys);
						IF mode = VarPar THEN	(*<< parameters are set, except for out parameters *)
							IF vis = inPar THEN par.num := setUsedP
							ELSIF vis = outPar THEN
								(* out parameters are not initialized, except for pointers and procedure variables *)
								par.num := clean	
							ELSE par.num := setUsed 
							END
						ELSE 
							par.num := set
						END;
						IF first = NIL THEN first := par END ;
						IF firstPar = NIL THEN firstPar := par ELSE last.link := par END ;
						last := par;
					ELSE err(ident)
					END;
					IF sym = comma THEN CPS.Get(sym)
					ELSIF sym = ident THEN err(comma)
					ELSIF sym = var THEN err(comma); CPS.Get(sym)
					ELSE EXIT
					END
				END ;
				CheckSym(colon); Type(typ, name);
				IF mode # VarPar THEN CheckAlloc(typ, TRUE, CPM.errpos) END;
				IF (mode = VarPar) & (vis = inPar) & (typ.form # Undef) & (typ.form # Comp) & (typ.sysflag = 0) THEN
					err(177)
				END;
				(* typ.pbused is set when parameter type name is parsed *)
				WHILE first # NIL DO
					SetType (NIL, first, typ, name);
					IF ODD(sys DIV newBit) THEN
						IF (newPar # NIL) OR (typ.form # Pointer) OR (typ.sysflag # interface) THEN err(168) END;
						newPar := first
					ELSIF ODD(sys DIV iidBit) THEN
						IF (iidPar # NIL) OR (typ # CPT.guidtyp) THEN err(168) END;
						iidPar := first
					END;
					first := first.link
				END;
				IF sym = semicolon THEN CPS.Get(sym)
				ELSIF sym = ident THEN err(semicolon)
				ELSE EXIT
				END
			END
		END;
		CheckSym(rparen);
		IF (newPar = NIL) # (iidPar = NIL) THEN err(168) END;
		name := NIL;
		IF sym = colon THEN
			CPS.Get(sym);
			Type(resTyp, name);
			IF resTyp.form = Comp THEN resTyp := CPT.undftyp; err(54) END
		ELSE resTyp := CPT.notyp
		END
	END FormalParameters;
	
	PROCEDURE CheckOverwrite (proc, base: CPT.Object; rec: CPT.Struct);
		VAR o, bo: CPT.Object;
	BEGIN
		IF base # NIL THEN
			IF base.conval.setval * {absAttr, empAttr, extAttr} = {} THEN err(182) END;
			IF (proc.link.mode # base.link.mode) OR (proc.link.vis # base.link.vis)
				OR ~CPT.Extends(proc.link.typ, base.link.typ) THEN err(115) END;
			o := proc.link; bo := base.link;
			WHILE (o # NIL) & (bo # NIL) DO
				IF (bo.sysflag # 0) & (o.sysflag = 0) THEN	(* propagate sysflags *)
					o.sysflag := bo.sysflag
				END;
				o := o.link; bo := bo.link
			END;
			CPB.CheckParameters(proc.link.link, base.link.link, FALSE);
			IF ~CPT.Extends(proc.typ, base.typ) THEN err(117) END;
			IF (base.vis # proc.vis) & ((proc.vis # internal) OR rec.exp) THEN err(183) END;
			INCL(proc.conval.setval, isRedef)
		END
	END CheckOverwrite;

	PROCEDURE GetAttributes (proc, base: CPT.Object; owner: CPT.Struct);	(* read method attributes *)
		VAR attr, battr: SET; o: CPT.Object;
	BEGIN
		attr := {};
		IF sym = comma THEN	(* read attributes *)
			CPS.Get(sym);
			IF sym = ident THEN
				CPT.Find(CPS.name, o);
				IF (o # NIL) & (o.mode = SProc) & (o.adr = newfn) THEN
					IF ~(CPM.oberon IN CPM.options) THEN INCL(attr, newAttr) ELSE err(178) END;
					CPS.Get(sym);
					IF sym = comma THEN
						CPS.Get(sym);
						IF sym = ident THEN CPT.Find(CPS.name, o) ELSE o := NIL; err(ident) END
					ELSE o := NIL
					END
				END;
				IF o # NIL THEN
					IF (o.mode # Attr) OR (o.adr = limAttr) OR (CPM.oberon IN CPM.options) THEN err(178)
					ELSE INCL(attr, o.adr)
					END;
					CPS.Get(sym)
				END
			ELSE err(ident)
			END
		END;
		IF (base = NIL) & ~(newAttr IN attr) THEN err(185); INCL(attr, newAttr)
		ELSIF (base # NIL) & (newAttr IN attr) THEN err(186)
		END;
		IF (owner.attribute # absAttr) & (absAttr IN attr) THEN err(190) END;
		IF (owner.attribute = 0) OR (owner.attribute = limAttr) THEN
			IF (empAttr IN attr) & (newAttr IN attr) THEN err(187)
			ELSIF extAttr IN attr THEN err(188)
			END
		END;
		IF base # NIL THEN
			battr := base.conval.setval;
			IF empAttr IN battr THEN
				IF absAttr IN attr THEN err(189) END
			ELSIF ~(absAttr IN battr) THEN
				IF (absAttr IN attr) OR (empAttr IN attr) THEN err(189) END
			END
		END;
		IF empAttr IN attr THEN
			IF proc.typ # CPT.notyp THEN err(195)
			ELSE
				o := proc.link; WHILE (o # NIL) & (o.vis # outPar) DO o := o.link END;
				IF o # NIL THEN err(195) END
			END
		END;
		IF (owner.sysflag = interface) & ~(absAttr IN attr) THEN err(162) END;
		proc.conval.setval := attr
	END GetAttributes;
	
	PROCEDURE RecordType(VAR typ: CPT.Struct; attr: CPT.Object);
		VAR fld, first, last: CPT.Object; r: Elem; ftyp: CPT.Struct; name: CPT.String;
	BEGIN typ := CPT.NewStr(Comp, Record); typ.BaseTyp := NIL;
		CheckSysFlag(typ.sysflag, CPM.GetRecordSysFlag);
		IF attr # NIL THEN
			IF ~(CPM.oberon IN CPM.options) & (attr.adr # empAttr) THEN typ.attribute := SHORT(SHORT(attr.adr))
			ELSE err(178)
			END
		END;
		IF typ.sysflag = interface THEN
			IF (CPS.str # NIL) & (CPS.str[0] = "{") THEN typ.ext := CPS.str END;
			IF typ.attribute # absAttr THEN err(163) END;
			IF sym # lparen THEN err(160) END
		END;
		IF sym = lparen THEN
			CPS.Get(sym); (*record extension*)
			IF sym = ident THEN
				Type(ftyp, name);
				IF ftyp.form = Pointer THEN ftyp := ftyp.BaseTyp END;
				SetType(typ, NIL, ftyp, name);
				IF (ftyp.comp = Record) & (ftyp # CPT.anytyp) THEN
					ftyp.pvused := TRUE; typ.extlev := SHORT(SHORT(ftyp.extlev + 1));
					CPM.PropagateRecordSysFlag(ftyp.sysflag, typ.sysflag);
					IF (ftyp.attribute = 0) OR (ftyp.attribute = limAttr) & (ftyp.mno # 0) THEN err(181)
					ELSIF (typ.attribute = absAttr) & (ftyp.attribute # absAttr) THEN err(191)
					ELSIF (ftyp.attribute = limAttr) & (typ.attribute # limAttr) THEN err(197)
					END
				ELSIF ftyp # CPT.undftyp THEN err(53)
				END
			ELSE err(ident)
			END ;
			IF typ.attribute # absAttr THEN	(* save typ for unimplemented method check *)
				NEW(r); r.struct := typ; r.pos := CPM.errpos; r.next := recList; recList := r
			END;
			CheckSym(rparen)
		END;
(*
		CPT.OpenScope(0, NIL);
*)
		first := NIL; last := NIL;
		LOOP
			IF sym = ident THEN
				LOOP
					IF sym = ident THEN
						IF (typ.BaseTyp # NIL) & (typ.BaseTyp # CPT.undftyp) THEN
							CPT.FindBaseField(CPS.name, typ, fld);
							IF fld # NIL THEN err(1) END
						END ;
						CPT.FindField(CPS.name, typ, fld);	(* not needed with actual CPT *)
						IF fld # NIL THEN err(1) END;
						CPT.InsertField(CPS.name, typ, fld);
						fld.mode := Fld; fld.link := NIL; fld.typ := CPT.undftyp;
						CheckMark(fld);
						fld.adr := CPM.errpos; fld.num := clean;	(*<<*)
						IF first = NIL THEN first := fld END ;
						IF last = NIL THEN typ.link := fld ELSE last.link := fld END ;
						last := fld
					ELSE err(ident)
					END ;
					IF sym = comma THEN CPS.Get(sym)
					ELSIF sym = ident THEN err(comma)
					ELSE EXIT
					END
				END ;
				CheckSym(colon); Type(ftyp, name);
				CheckAlloc(ftyp, FALSE, CPM.errpos);
				WHILE first # NIL DO
					SetType(typ, first, ftyp, name); first := first.link
				END;
				IF typ.sysflag = interface THEN err(161) END
			END;
			IF sym = semicolon THEN CPS.Get(sym);
				IF ((sym = end) OR (sym = semicolon)) & options.semicolons THEN	(*<< superfluous semicolon *)
					err2(semicolons, CPM.errpos)
				END
			ELSIF sym = ident THEN err(semicolon)
			ELSE EXIT
			END
		END;
(*
		IF typ.link # NIL THEN ASSERT(typ.link = CPT.topScope.right) END;
		typ.link := CPT.topScope.right; CPT.CloseScope;
*)
		typ.untagged := typ.sysflag # 0;
		CPB.Inittd(TDinit, lastTDinit, typ); CheckSym(end)
	END RecordType;

	PROCEDURE ArrayType(VAR typ: CPT.Struct);
		VAR x: CPT.Node; n: INTEGER; sysflag: SHORTINT; name: CPT.String;
	BEGIN CheckSysFlag(sysflag, CPM.GetArraySysFlag);
		IF sym = of THEN	(*dynamic array*)
			typ := CPT.NewStr(Comp, DynArr); typ.mno := 0; typ.sysflag := sysflag;
			CPS.Get(sym); Type(typ.BaseTyp, name); SetType(typ, NIL, typ.BaseTyp, name);
			CheckAlloc(typ.BaseTyp, TRUE, CPM.errpos);
			IF typ.BaseTyp.comp = DynArr THEN typ.n := typ.BaseTyp.n + 1 ELSE typ.n := 0 END
		ELSE
			typ := CPT.NewStr(Comp, Array); typ.sysflag := sysflag; ConstExpression(x);
			IF x.typ.form IN {Int8, Int16, Int32} THEN n := x.conval.intval;
				IF (n <= 0) OR (n > CPM.MaxIndex) THEN err(63); n := 1 END
			ELSE err(42); n := 1
			END ;
			typ.n := n;
			IF sym = of THEN
				CPS.Get(sym); Type(typ.BaseTyp, name); SetType(typ, NIL, typ.BaseTyp, name);
				CheckAlloc(typ.BaseTyp, FALSE, CPM.errpos)
			ELSIF sym = comma THEN
				CPS.Get(sym);
				IF sym # of THEN ArrayType(typ.BaseTyp) END
			ELSE err(35)
			END
		END;
		typ.untagged := typ.sysflag # 0
	END ArrayType;

	PROCEDURE PointerType(VAR typ: CPT.Struct);
		VAR name: CPT.String;
	BEGIN typ := CPT.NewStr(Pointer, Basic); CheckSysFlag(typ.sysflag, CPM.GetPointerSysFlag);
		CheckSym(to);
		Type(typ.BaseTyp, name);
		SetType(typ, NIL, typ.BaseTyp, name);
		IF (typ.BaseTyp # CPT.undftyp) & (typ.BaseTyp.comp = Basic) THEN
			typ.BaseTyp := CPT.undftyp; err(57)
		END;
		IF typ.BaseTyp.comp = Record THEN CPM.PropagateRecPtrSysFlag(typ.BaseTyp.sysflag, typ.sysflag)
		ELSIF typ.BaseTyp.comp IN {Array, DynArr} THEN CPM.PropagateArrPtrSysFlag(typ.BaseTyp.sysflag, typ.sysflag)
		END;
		typ.untagged := typ.sysflag # 0
	END PointerType;
	
	PROCEDURE Type (VAR typ: CPT.Struct; VAR name: CPT.String);	(* name # NIL => forward reference *)
		VAR id: CPT.Object; tname: CPT.String;
	BEGIN
		typ := CPT.undftyp; name := NIL;
		IF sym < lparen THEN err(12);
			REPEAT CPS.Get(sym) UNTIL sym >= lparen
		END ;
		IF sym = ident THEN
			CPT.Find(CPS.name, id);
			IF (id = NIL) OR (id.mode = -1) OR (id.mode = Typ) & IncompleteType(id.typ) THEN	(* forward type definition *)
				name := CPT.NewName(CPS.name); CPS.Get(sym);
				IF (id = NIL) & (sym = period) THEN	(* missing module *)
					err(0); CPS.Get(sym); name := NIL;
					IF sym = ident THEN CPS.Get(sym) END
				ELSIF sym = record THEN	(* wrong attribute *)
					err(178); CPS.Get(sym); name := NIL; RecordType(typ, NIL)
				END
			ELSE
				qualident(id);
				UseType(id, CPM.errpos);	(*<< type gets used*)
				IF id.mode = Typ THEN
					IF ~(CPM.oberon IN CPM.options)
						& ((id.typ = CPT.lreal64typ) OR (id.typ = CPT.lint64typ) OR (id.typ = CPT.lchar16typ)) THEN err(198) END;
					typ := id.typ
				ELSIF id.mode = Attr THEN
					IF sym = record THEN
						CPS.Get(sym); RecordType(typ, id)
					ELSE err(12)
					END
				ELSE err(52)
				END
			END
		ELSIF sym = array THEN
			CPS.Get(sym); ArrayType(typ)
		ELSIF sym = record THEN
			CPS.Get(sym); RecordType(typ, NIL)
		ELSIF sym = pointer THEN
			CPS.Get(sym); PointerType(typ)
		ELSIF sym = procedure THEN
			CPS.Get(sym); typ := CPT.NewStr(ProcTyp, Basic);
(*
			CheckSysFlag(typ.sysflag, CPM.GetProcTypSysFlag);
			typ.untagged := typ.sysflag # 0;
*)
			IF sym = lparen THEN
				CPS.Get(sym); CPT.OpenScope(level, NIL);
				FormalParameters(typ.link, typ.BaseTyp, tname); SetType(typ, NIL, typ.BaseTyp, tname); CPT.CloseScope
			ELSE typ.BaseTyp := CPT.notyp; typ.link := NIL
			END
		ELSE err(12)
		END ;
		LOOP
			IF (sym >= semicolon) & (sym <= else) OR (sym = rparen) OR (sym = eof)
				OR (sym = number) OR (sym = comma) THEN EXIT END;
			err(15); IF sym = ident THEN EXIT END;
			CPS.Get(sym)
		END
	END Type;
	
	PROCEDURE ^ selector(VAR x: CPT.Node);
	PROCEDURE ^ StandProcCall(VAR x: CPT.Node);
	
	PROCEDURE ActualParameters(VAR aparlist: CPT.Node; fpar: CPT.Object; VAR pre, lastp: CPT.Node);
		VAR apar, last, newPar, iidPar, n: CPT.Node; id: CPT.Object; moreThan1: BOOLEAN;	(*<< id, moreThan1 *)
	BEGIN
		aparlist := NIL; last := NIL;
		IF sym # rparen THEN
			moreThan1 := (fpar # NIL) & (fpar.link # NIL);	(*<<*)
			newPar := NIL; iidPar := NIL;
			LOOP
				(*<< Expression(apar)	old code *)
				IF sym # nil THEN
					IF (fpar # NIL) & (fpar.mode = VarPar) & (fpar.vis # inPar) THEN	(*<<*)
						qualident(id); apar := CPB.NewLeaf(id); selector(apar);
						IF (apar.class = Nproc) & (apar.obj.mode = SProc) & (apar.obj.adr = valfn) THEN
							StandProcCall(apar)
						END;
						Selector(apar, SelAssign, SelVarPar, SelUseBSet, CPM.errpos)
					ELSE	(*<<*)
						Expression(apar);
						IF options.sideEffects & moreThan1 & (apar.class = Ncall) THEN
							(*<< proc-calls in param-list: code might depend on evaluation sequence (if more than one param.) *)
							err2(evaluationSeq, CPM.errpos)
						END
					END;
					IF fpar # NIL THEN
						IF (apar.typ.form = Pointer) & (fpar.typ.form = Comp) THEN CPB.DeRef(apar) END;
						CPB.Param(apar, fpar);
						IF fpar.mode = Var THEN CPB.CheckBuffering(apar, NIL, fpar, pre, lastp) END;
						CPB.Link(aparlist, last, apar);
						IF ODD(fpar.sysflag DIV newBit) THEN newPar := apar
						ELSIF ODD(fpar.sysflag DIV iidBit) THEN iidPar := apar
						END;
						IF (newPar # NIL) & (iidPar # NIL) THEN CPB.CheckNewParamPair(newPar, iidPar) END;
						fpar := fpar.link
					ELSE err(64)
					END;
				ELSE
					 fpar := fpar.link; CPS.Get(sym) 
				END;
				IF sym = comma THEN CPS.Get(sym)
				ELSIF (lparen <= sym) & (sym <= ident) THEN err(comma)
				ELSE EXIT
				END
			END
		END;
		IF fpar # NIL THEN err(65) END
	END ActualParameters;

	PROCEDURE selector(VAR x: CPT.Node);
		VAR obj, proc, fpar: CPT.Object; y, apar, pre, lastp: CPT.Node; typ: CPT.Struct; name: CPT.Name;
	BEGIN
		LOOP
			IF sym = lbrak THEN CPS.Get(sym);
				LOOP
					IF (x.typ # NIL) & (x.typ.form = Pointer) THEN CPB.DeRef(x) END ;
					Expression(y); CPB.Index(x, y);
					IF sym = comma THEN CPS.Get(sym) ELSE EXIT END
				END ;
				CheckSym(rbrak)
			ELSIF sym = period THEN 
				CPS.Get(sym);
				IF sym = ident THEN name := CPS.name; CPS.Get(sym);
					IF x.typ # NIL THEN
						IF x.typ.form = Pointer THEN 
								IF x.obj # NIL THEN UseObj(x.obj, TRUE, x.obj.adr) END;
								CPB.DeRef(x) 
						END ;
						IF x.typ.comp = Record THEN
							typ := x.typ; CPT.FindField(name, typ, obj); CPB.Field(x, obj);
							IF (obj # NIL) & (obj.mode = TProc) THEN
								IF sym = arrow THEN  (* super call *) CPS.Get(sym);
									y := x.left;
									IF y.class = Nderef THEN y := y.left END ;	(* y = record variable *)
									IF y.obj # NIL THEN
										proc := CPT.topScope;	(* find innermost scope which owner is a TProc *)
										WHILE (proc.link # NIL) & (proc.link.mode # TProc) DO proc := proc.left END ;
										IF (proc.link = NIL) OR (proc.link.link # y.obj) THEN err(75) END ;
										typ := y.obj.typ;
										IF typ.form = Pointer THEN typ := typ.BaseTyp END ;
										CPT.FindBaseField(x.obj.name^, typ, proc);
										IF proc # NIL THEN x.subcl := super;
											UseObj(proc, TRUE, proc.adr);	(*<< touch super proc*)
											IF proc.conval.setval * {absAttr, empAttr} # {} THEN err(194) END
										ELSE err(74)
										END
									ELSE err(75)
									END
								ELSE
									UseObj(obj, TRUE, obj.adr);	(*<< touch obj only if not super call! *)
									proc := obj;
									WHILE (proc.mnolev >= 0) & ~(newAttr IN proc.conval.setval) & (typ.BaseTyp # NIL) DO
										(* find base method *)
										typ := typ.BaseTyp; CPT.FindField(name, typ, proc);
									END;
									IF (proc.vis = externalR) & (proc.mnolev < 0) THEN err(196) END;
								END ;
								IF (obj.typ # CPT.notyp) & (sym # lparen) THEN err(lparen) END
							END
						ELSE err(53)
						END
					ELSE err(52)
					END
				ELSE err(ident)
				END
			ELSIF sym = arrow THEN CPS.Get(sym); CPB.DeRef(x)
			ELSIF sym = dollar THEN
				IF x.typ.form = Pointer THEN CPB.DeRef(x) END;
				CPS.Get(sym); CPB.StrDeref(x)
			ELSIF sym = lparen THEN
				IF (x.obj # NIL) & (x.obj.mode IN {XProc, LProc, CProc, TProc}) THEN typ := x.obj.typ
				ELSIF x.typ.form = ProcTyp THEN typ := x.typ.BaseTyp
				ELSIF x.class = Nproc THEN EXIT	(* standard procedure *)
				ELSE typ := NIL
				END;
				IF typ # CPT.notyp THEN
					CPS.Get(sym);
					IF typ = NIL THEN	(* type guard *)
						IF sym = ident THEN
							qualident(obj);
							IF obj.mode = Typ THEN CPB.TypTest(x, obj, TRUE);
								UseType(obj, CPM.errpos)	(*<< type gets used*)
							ELSE err(52)
							END
						ELSE err(ident)
						END
					ELSE	(* function call *)
						pre := NIL; lastp := NIL;
						CPB.PrepCall(x, fpar);
						IF (x.obj # NIL) & (x.obj.mode = TProc) THEN CPB.CheckBuffering(x.left, NIL, x.obj.link, pre, lastp) END;
						ActualParameters(apar, fpar, pre, lastp);
						CPB.Call(x, apar, fpar);
						IF pre # NIL THEN CPB.Construct(Ncomp, pre, x); pre.typ := x.typ; x := pre END;
						IF level > 0 THEN CPT.topScope.link.leaf := FALSE END
					END;
					CheckSym(rparen)
				ELSE EXIT
				END
(*
			ELSIF (sym = lparen) & (x.class # Nproc) & (x.typ.form # ProcTyp) &
					((x.obj = NIL) OR (x.obj.mode # TProc)) THEN
				CPS.Get(sym);
				IF sym = ident THEN
					qualident(obj);
					IF obj.mode = Typ THEN CPB.TypTest(x, obj, TRUE)
					ELSE err(52)
					END
				ELSE err(ident)
				END ;
				CheckSym(rparen)
*)
			ELSE EXIT
			END
		END
	END selector;

	PROCEDURE StandProcCall(VAR x: CPT.Node);
		VAR y: CPT.Node; m: BYTE; n: SHORTINT; id: CPT.Object;	(*<< id *)
	BEGIN 
		m := SHORT(SHORT(x.obj.adr)); n := 0;
		IF sym = lparen THEN CPS.Get(sym);
			IF sym # rparen THEN
				LOOP
					IF n = 0 THEN
						(*<< Expression(x);	old code *)
						CASE m OF	(*<<*)
						| newfn, sysnewfn:	(* id will be set by NEW => varPar = FALSE *)
							qualident(id); x := CPB.NewLeaf(id); selector(x);
							IF (x.class = Nproc) & (x.obj.mode = SProc) & (x.obj.adr = valfn) THEN StandProcCall(x) END;
							Selector(x, SelAssign, SelNoVarPar, SelUseBSet, CPM.errpos)
						| incfn, decfn, inclfn, exclfn:	(* id will be used and then set *)
							qualident(id); x := CPB.NewLeaf(id); selector(x);
							IF (x.class = Nproc) & (x.obj.mode = SProc) & (x.obj.adr = valfn) THEN StandProcCall(x) END;
							Selector(x, SelNoAssign, SelNoVarPar, SelUseBSet, CPM.errpos);	(* use *)
							Selector(x, SelAssign, SelNoVarPar, SelUseBSet, CPM.errpos)	(* set *)
						| adrfn:
							IF sym = ident THEN	(* no usedBSet message if ADR(id) *)
								qualident(id); x := CPB.NewLeaf(id); selector(x);
								Selector(x, SelNoAssign, SelNoVarPar, SelNoUseBSet, CPM.errpos)
							ELSE 
								Expression(x);
							END
						| lenfn:
							qualident(id); x := CPB.NewLeaf(id); selector(x);
							(* no usedBSet message if LEN(id) *)
							Selector(x, SelNoAssign, SelNoVarPar, SelNoUseBSet, CPM.errpos)	
						ELSE Expression(x)
						END;
						CPB.StPar0(x, m); n := 1
					ELSIF n = 1 THEN
						(*<< Expression(y);	old code *)
						IF m IN {getfn, getrfn} THEN	(*<< id will be set by GET, GETREG => varPar = FALSE *)
							qualident(id); y := CPB.NewLeaf(id); selector(y);
							IF (y.class = Nproc) & (y.obj.mode = SProc) & (y.obj.adr = valfn) THEN StandProcCall(y) END;
							Selector(y, SelAssign, SelNoVarPar, SelUseBSet, CPM.errpos)
						ELSE Expression(y)
						END;
						CPB.StPar1(x, y, m); n := 2
					ELSE Expression(y); CPB.StParN(x, y, m, n); INC(n)
					END ;
					IF sym = comma THEN CPS.Get(sym)
					ELSIF (lparen <= sym) & (sym <= ident) THEN err(comma)
					ELSE EXIT
					END
				END ;
				CheckSym(rparen)
			ELSE CPS.Get(sym)
			END ;
			CPB.StFct(x, m, n)
		ELSE err(lparen)
		END ;
		IF (level > 0) & ((m = newfn) OR (m = sysnewfn)) THEN CPT.topScope.link.leaf := FALSE END
	END StandProcCall;
	
	PROCEDURE Element(VAR x: CPT.Node);
		VAR y: CPT.Node;
	BEGIN Expression(x);
		IF sym = upto THEN
			CPS.Get(sym); Expression(y); CPB.SetRange(x, y)
		ELSE CPB.SetElem(x)
		END
	END Element;

	PROCEDURE Sets(VAR x: CPT.Node);
		VAR y: CPT.Node;
	BEGIN
		IF sym # rbrace THEN
			Element(x);
			LOOP
				IF sym = comma THEN CPS.Get(sym)
				ELSIF (lparen <= sym) & (sym <= ident) THEN err(comma)
				ELSE EXIT
				END ;
				Element(y); CPB.Op(plus, x, y)
			END
		ELSE x := CPB.EmptySet()
		END ;
		CheckSym(rbrace)
	END Sets;
	
	PROCEDURE Factor(VAR x: CPT.Node);
		VAR id: CPT.Object; pos: INTEGER;	(*<< pos *)
	BEGIN
		IF sym < not THEN err(13);
			REPEAT CPS.Get(sym) UNTIL sym >= lparen
		END ;
		IF sym = ident THEN
			qualident(id);
			pos := CPM.curpos;	(*<<*)
			x := CPB.NewLeaf(id); 
			UseObj(x.obj, SelUseBSet, pos);
			selector(x);
			IF (x.class = Nfield) & (x.obj.mode = TProc) & (x.obj.link.mode = VarPar) & (x.obj.link.typ.comp = Record) THEN	
				(*<< receiver is var parameter and record *)
				Selector(x.left, SelAssign, SelVarPar, SelUseBSet, pos)
			END;
			Selector(x, SelNoAssign, SelNoVarPar, SelUseBSet, pos);	(*<<*)
			IF (x.class = Nproc) & (x.obj.mode = SProc) THEN
				IF ~((x.obj.adr IN {ordfn, minfn, maxfn, chrfn, sizefn, adrfn, valfn}) OR (x.obj.adr = bitsfn)) THEN
					INC(nofStats)	(*<<*)
				END;
				StandProcCall(x)	(* x may be NIL *)
(*
			ELSIF sym = lparen THEN
				CPS.Get(sym); CPB.PrepCall(x, fpar);
				ActualParameters(apar, fpar);
				INC(nofStats);	(*<<*)
				CPB.Call(x, apar, fpar);
				CheckSym(rparen);
				IF level > 0 THEN CPT.topScope.link.leaf := FALSE END
			ELSIF id.mode = Typ THEN UseType(id, CPM.errpos)	(*<< type gets used, e.g. SIZE(Node) *)
*)
			END;
		ELSIF sym = number THEN
			CASE CPS.numtyp OF
			   char:
				x := CPB.NewIntConst(CPS.intval); x.typ := CPT.char8typ;
				IF CPS.intval > 255 THEN x.typ := CPT.char16typ END
			| integer: x := CPB.NewIntConst(CPS.intval)
			| int64: x := CPB.NewLargeIntConst(CPS.intval, CPS.realval)
			| real: x := CPB.NewRealConst(CPS.realval, NIL)
			| real32: x := CPB.NewRealConst(CPS.realval, CPT.real32typ)
			| real64: x := CPB.NewRealConst(CPS.realval, CPT.real64typ)
			END ;
			CPS.Get(sym)
		ELSIF sym = string THEN
			x := CPB.NewString(CPS.str, CPS.lstr, CPS.intval);
			CPS.Get(sym)
		ELSIF sym = nil THEN
			x := CPB.Nil(); CPS.Get(sym)
		ELSIF sym = lparen THEN
			CPS.Get(sym); Expression(x); CheckSym(rparen)
		ELSIF sym = lbrak THEN
			CPS.Get(sym); err(lparen); Expression(x); CheckSym(rparen)
		ELSIF sym = lbrace THEN CPS.Get(sym); Sets(x)
		ELSIF sym = not THEN
			CPS.Get(sym); Factor(x); CPB.MOp(not, x)
		ELSE err(13); CPS.Get(sym); x := NIL
		END ;
		IF x = NIL THEN x := CPB.NewIntConst(1); x.typ := CPT.undftyp END
	END Factor;

	PROCEDURE Term(VAR x: CPT.Node);
		VAR y: CPT.Node; mulop: BYTE;
	BEGIN Factor(x);
		WHILE (times <= sym) & (sym <= and) DO
			mulop := sym; CPS.Get(sym);
			Factor(y); CPB.Op(mulop, x, y)
		END
	END Term;

	PROCEDURE SimpleExpression(VAR x: CPT.Node);
		VAR y: CPT.Node; addop: BYTE;
	BEGIN
		IF sym = minus THEN CPS.Get(sym); Term(x); CPB.MOp(minus, x)
		ELSIF sym = plus THEN CPS.Get(sym); Term(x); CPB.MOp(plus, x)
		ELSE Term(x)
		END ;
		WHILE (plus <= sym) & (sym <= or) DO
			addop := sym; CPS.Get(sym); Term(y); 
			IF x.typ.form = Pointer THEN CPB.DeRef(x) END;
			IF (x.typ.comp IN {Array, DynArr}) & (x.typ.BaseTyp.form IN charSet) THEN CPB.StrDeref(x) END;
			IF y.typ.form = Pointer THEN CPB.DeRef(y) END;
			IF (y.typ.comp IN {Array, DynArr}) & (y.typ.BaseTyp.form IN charSet) THEN CPB.StrDeref(y) END;
			CPB.Op(addop, x, y)
		END
	END SimpleExpression;

	PROCEDURE Expression(VAR x: CPT.Node);
		VAR y, pre, last: CPT.Node; obj: CPT.Object; relation: BYTE;
	BEGIN SimpleExpression(x);
		IF (eql <= sym) & (sym <= geq) THEN
			relation := sym; CPS.Get(sym); SimpleExpression(y);
			pre := NIL; last := NIL;
			IF (x.typ.comp IN {Array, DynArr}) & (x.typ.BaseTyp.form IN charSet) THEN CPB.StrDeref(x) END;
			IF (y.typ.comp IN {Array, DynArr}) & (y.typ.BaseTyp.form IN charSet) THEN CPB.StrDeref(y) END;
			CPB.CheckBuffering(x, NIL, NIL, pre, last);
			CPB.CheckBuffering(y, NIL, NIL, pre, last);
			CPB.Op(relation, x, y);
			IF pre # NIL THEN CPB.Construct(Ncomp, pre, x); pre.typ := x.typ; x := pre END;
		ELSIF sym = in THEN
			CPS.Get(sym); SimpleExpression(y); CPB.In(x, y)
		ELSIF sym = is THEN
			CPS.Get(sym);
			IF sym = ident THEN
				qualident(obj);
				UseType(obj, CPM.errpos);	(*<< type gets used*)
				IF obj.mode = Typ THEN CPB.TypTest(x, obj, FALSE)
				ELSE err(52)
				END
			ELSE err(ident)
			END
		END
	END Expression;

	PROCEDURE ProcedureDeclaration(VAR x: CPT.Node);
		VAR proc, fwd: CPT.Object;
			name: CPT.Name;
			mode: BYTE;
			forward: BOOLEAN;
			sys: SHORTINT;
			pos: INTEGER;	(*<< *)

		PROCEDURE GetCode;
			VAR ext: CPT.ConstExt; i, n, c: INTEGER; s: ARRAY 256 OF SHORTCHAR;
		BEGIN
			n := 0;
			LOOP
				IF sym = number THEN c := CPS.intval; INC(n);
					IF (c < 0) OR (c > 255) OR (n = 255) THEN
						err(64); c := 1; n := 1
					END ;
					CPS.Get(sym); s[n] := SHORT(CHR(c))
				END ;
				IF sym = comma THEN CPS.Get(sym)
				ELSIF sym = number THEN err(comma)
				ELSE s[0] := SHORT(CHR(n)); EXIT
				END
			END;
			NEW(ext, n + 1); proc.conval.ext := ext; i := 0;
			WHILE i <= n DO ext[i] := s[i]; INC(i) END;
			INCL(proc.conval.setval, hasBody)
		END GetCode;

		PROCEDURE GetParams;
			VAR name: CPT.String;
		BEGIN
			proc.mode := mode; proc.typ := CPT.notyp;
			proc.sysflag := SHORT(sys);
			proc.conval.setval := {};
			IF sym = lparen THEN
				CPS.Get(sym); FormalParameters(proc.link, proc.typ, name);
				IF name # NIL THEN err(0) END
			END;
			CheckForwardTypes; userList := NIL;
			IF fwd # NIL THEN
				CPB.CheckParameters(proc.link, fwd.link, TRUE);
				IF ~CPT.EqualType(proc.typ, fwd.typ) THEN err(117) END ;
				proc := fwd; CPT.topScope := proc.scope;
				IF mode = IProc THEN proc.mode := IProc END
			END
		END GetParams;

		PROCEDURE Body;
			VAR procdec, statseq: CPT.Node; c: INTEGER;
		BEGIN
			c := CPM.errpos;
			INCL(proc.conval.setval, hasBody);
			CheckSym(semicolon); Block(procdec, statseq);
			CPB.Enter(procdec, statseq, proc); x := procdec;
			x.conval := CPT.NewConst(); x.conval.intval := c; x.conval.intval2 := CPM.startpos;
			CheckSym(end);
			IF sym = ident THEN
				IF CPS.name # proc.name^ THEN err(4) END ;
				CPS.Get(sym)
			ELSE err(ident)
			END
		END Body;

		PROCEDURE TProcDecl;
			VAR baseProc, o: CPT.Object;
				objTyp, recTyp: CPT.Struct;
				objMode, objVis: BYTE;
				objName: CPT.Name;
				pnode: CPT.Node;
				pos1, pos2: INTEGER;	(*<<*)
		BEGIN
			CPS.Get(sym); mode := TProc;
			IF level > 0 THEN err(73) END;
			pos1 := CPM.errpos;	(*<<*)
			Receiver(objMode, objVis, objName, objTyp, recTyp);
			IF sym = ident THEN
				name := CPS.name;
				CPT.FindField(name, recTyp, fwd);
				CPT.FindBaseField(name, recTyp, baseProc);
				IF (baseProc # NIL) & (baseProc.mode # TProc) THEN baseProc := NIL END ;
				IF fwd = baseProc THEN fwd := NIL END ;
				IF (fwd # NIL) & (fwd.mnolev # level) THEN fwd := NIL END ;
				IF (fwd # NIL) & (fwd.mode = TProc) & (fwd.conval.setval * {hasBody, absAttr, empAttr} = {}) THEN
					(* there exists a corresponding forward declaration *)
					proc := CPT.NewObj(); proc.leaf := TRUE;
					proc.mode := TProc; proc.conval := CPT.NewConst();
					CheckMark(proc);
					IF fwd.vis # proc.vis THEN err(118) END
				ELSE
					IF fwd # NIL THEN err(1); fwd := NIL END ;
					CPT.InsertField(name, recTyp, proc);
					proc.mode := TProc; proc.conval := CPT.NewConst();
					CheckMark(proc);
					IF recTyp.strobj # NIL THEN	(* preserve declaration order *)
						o := recTyp.strobj.link;
						IF o = NIL THEN recTyp.strobj.link := proc
						ELSE
							WHILE o.nlink # NIL DO o := o.nlink END;
							o.nlink := proc
						END
					END
				END;
				pos2 := CPM.errpos; proc.num := set;	(*<< methods are set*)
				INC(level); CPT.OpenScope(level, proc);
				CPT.Insert(objName, proc.link); proc.link.mode := objMode; proc.link.vis := objVis; proc.link.typ := objTyp;
				proc^.link.adr := pos1;	(*<< *)
				(*
				(*<< receiver is set/setUsed *)
				IF objMode = VarPar THEN proc^.link.num := setUsed ELSE proc^.link.num := set END;	
				*)
				proc.link.num := setUsed; (* BJ: No point in warning about recievers. (commented out the line above...)*)
				ASSERT(CPT.topScope # NIL);
				GetParams; 
				ASSERT(CPT.topScope # NIL);
				GetAttributes(proc, baseProc, recTyp);
				
				IF ((absAttr IN proc.conval.setval) OR (empAttr IN proc.conval.setval)) & (proc.link.link # NIL) THEN
					o := proc.link.link;
					WHILE o # NIL DO o.num := setUsed; o := o.link END;
				END;
				
				IF (fwd # NIL) & (fwd.conval.setval / proc.conval.setval * {absAttr, empAttr, extAttr} # {}) THEN err(184) END;
				CheckOverwrite(proc, baseProc, recTyp);
				IF ~forward THEN
					IF empAttr IN proc.conval.setval THEN	(* insert empty procedure *)
						pnode := NIL; CPB.Enter(pnode, NIL, proc);
						pnode.conval := CPT.NewConst();
						pnode.conval.intval := CPM.errpos;
						pnode.conval.intval2 := CPM.errpos;
						x := pnode
					ELSIF ~(absAttr IN proc.conval.setval) THEN Body
					END;
					proc.adr := 0
				ELSE proc.adr := CPM.errpos
				END;
				proc.adr := pos2;	(*<< *)
				DEC(level); CPT.CloseScope
			ELSE err(ident)
			END
		END TProcDecl;
	
	BEGIN proc := NIL; forward := FALSE; x := NIL; mode := LProc; sys := 0;
		IF (sym # ident) & (sym # lparen) THEN
			CheckSysFlag(sys, CPM.GetProcSysFlag);
			IF sys # 0 THEN
(*
				IF ~CPT.SYSimported THEN err(135) END;
*)
				IF sys = CPM.CProcFlag THEN mode := CProc END
			ELSE
				IF sym = times THEN	(* mode set later in CPB.CheckAssign *)
				ELSIF sym = arrow THEN forward := TRUE
				ELSE err(ident)
				END;
				CPS.Get(sym)
			END
		END ;
		IF sym = lparen THEN TProcDecl
		ELSIF sym = ident THEN CPT.Find(CPS.name, fwd);
			name := CPS.name;
			IF (fwd # NIL) & ((fwd.mnolev # level) OR (fwd.mode = SProc)) THEN fwd := NIL END ;
			IF (fwd # NIL) & (fwd.mode IN {LProc, XProc}) & ~(hasBody IN fwd.conval.setval) THEN
				(* there exists a corresponding forward declaration *)
				proc := CPT.NewObj(); proc.leaf := TRUE;
				proc.mode := mode; proc.conval := CPT.NewConst();
				CheckMark(proc);
				IF fwd.vis # proc.vis THEN err(118) END
			ELSE
				IF fwd # NIL THEN err(1); fwd := NIL END ;
				CheckOuter;	(*<<*)
				CPT.Insert(name, proc);
				proc.mode := mode; proc.conval := CPT.NewConst();
				CheckMark(proc)
			END ;
			pos := CPM.errpos; proc.num := set;	(*<< procedures are set *)
			IF (proc.vis # internal) & (mode = LProc) THEN mode := XProc END ;
			IF (mode # LProc) & (level > 0) THEN err(73) END ;
			INC(level); CPT.OpenScope(level, proc);
			proc.link := NIL; GetParams;
			IF mode = CProc THEN GetCode
			ELSIF CPM.interface IN CPM.options THEN INCL(proc.conval.setval, hasBody)
			ELSIF ~forward THEN Body; proc.adr := 0
			ELSE proc.adr := CPM.errpos
			END ;
			proc.adr := pos;	(*<< *)
			DEC(level); CPT.CloseScope
		ELSE err(ident)
		END
	END ProcedureDeclaration;

	PROCEDURE CaseLabelList(VAR lab, root: CPT.Node; LabelForm: SHORTINT; VAR min, max: INTEGER);
		VAR x, y: CPT.Node; f: SHORTINT; xval, yval: INTEGER;
		
		PROCEDURE Insert(VAR n: CPT.Node);	(* build binary tree of label ranges *)	(* !!! *)
		BEGIN
			IF n = NIL THEN
				IF x.hint # 1 THEN n := x END
			ELSIF yval < n.conval.intval THEN Insert(n.left)
			ELSIF xval > n.conval.intval2 THEN Insert(n.right)
			ELSE err(63)
			END
		END Insert;
		
	BEGIN lab := NIL;
		LOOP ConstExpression(x); f := x.typ.form;
			IF f IN intSet + charSet THEN  xval := x.conval.intval
			ELSE err(61); xval := 1
			END ;
			IF (f IN intSet) # (LabelForm IN intSet) THEN err(60) END;
			IF sym = upto THEN
				CPS.Get(sym); ConstExpression(y); yval := y.conval.intval;
				IF (y.typ.form IN intSet) # (LabelForm IN intSet) THEN err(60) END;
				IF yval < xval THEN err(63); yval := xval END
			ELSE yval := xval
			END ;
			x.conval.intval2 := yval;
			IF xval < min THEN min := xval END;
			IF yval > max THEN max := yval END;
			IF lab = NIL THEN lab := x; Insert(root)
			ELSIF yval < lab.conval.intval - 1 THEN x.link := lab; lab := x; Insert(root)
			ELSIF yval = lab.conval.intval - 1 THEN x.hint := 1; Insert(root); lab.conval.intval := xval
			ELSIF xval = lab.conval.intval2 + 1 THEN x.hint := 1; Insert(root); lab.conval.intval2 := yval
			ELSE
				y := lab;
				WHILE (y.link # NIL) & (xval > y.link.conval.intval2 + 1) DO y := y.link END;
				IF y.link = NIL THEN y.link := x; Insert(root)
				ELSIF yval < y.link.conval.intval - 1 THEN x.link := y.link; y.link := x; Insert(root)
				ELSIF yval = y.link.conval.intval - 1 THEN x.hint := 1; Insert(root); y.link.conval.intval := xval
				ELSIF xval = y.link.conval.intval2 + 1 THEN x.hint := 1; Insert(root); y.link.conval.intval2 := yval
				END
			END;
			IF sym = comma THEN CPS.Get(sym)
			ELSIF (sym = number) OR (sym = ident) THEN err(comma)
			ELSE EXIT
			END
		END
	END CaseLabelList;
	
	PROCEDURE Evaluate (n: CPT.Node; VAR min, max, num, dist: INTEGER; VAR head: CPT.Node);
		VAR a: INTEGER;
	BEGIN
		a := MIN(INTEGER);
		IF n.left # NIL THEN
			a := MIN(INTEGER); Evaluate(n.left, min, a, num, dist, head);
			IF n.conval.intval - a > dist THEN dist := n.conval.intval - a; head := n END
		ELSIF n.conval.intval < min THEN
			min := n.conval.intval
		END;
		IF n.right # NIL THEN
			a := MAX(INTEGER); Evaluate(n.right, a, max, num, dist, head);
			IF a - n.conval.intval2 > dist THEN dist := a - n.conval.intval2; head := n END
		ELSIF n.conval.intval2 > max THEN
			max := n.conval.intval2
		END;
		INC(num);
		IF n.conval.intval < n.conval.intval2 THEN
			INC(num);
			IF n.conval.intval2 - n.conval.intval > dist THEN dist := n.conval.intval2 - n.conval.intval; head := n END
		END
	END Evaluate;
	
	PROCEDURE Rebuild (VAR root: CPT.Node; head: CPT.Node);
		VAR n: CPT.Node;
	BEGIN
		IF root # head THEN
			IF head.conval.intval2 < root.conval.intval THEN
				Rebuild(root.left, head);
				n := head; WHILE n.right # NIL DO n := n.right END;
				n.right := root; root.left := NIL; root := head
			ELSE
				Rebuild(root.right, head);
				n := head; WHILE n.left # NIL DO n := n.left END;
				n.left := root; root.right := NIL; root := head
			END
		END
	END Rebuild;
	
	PROCEDURE Optimize (VAR n: CPT.Node);
		VAR min, max, num, dist, limit: INTEGER; head: CPT.Node;
	BEGIN
		IF n # NIL THEN
			min := MAX(INTEGER); max := MIN(INTEGER); num := 0; dist := 0; head := n;
			Evaluate(n, min, max, num, dist, head);
			limit := 6 * num;
			IF limit < 100 THEN limit := 100 END;
			IF (num > 4) & ((min > MAX(INTEGER) - limit) OR (max < min + limit)) THEN
				INCL(n.conval.setval, useTable)
			ELSE
				IF num > 4 THEN Rebuild(n, head) END;
				INCL(n.conval.setval, useTree);
				Optimize(n.left);
				Optimize(n.right)
			END
		END
	END Optimize;
(*	
	PROCEDURE ShowTree (n: CPT.Node; opts: SET);
	BEGIN
		IF n # NIL THEN
			IF opts = {} THEN opts := n.conval.setval END;
			IF useTable IN opts THEN
				IF n.left # NIL THEN ShowTree(n.left, opts); CPM.LogW(",") END;
				CPM.LogWNum(n.conval.intval, 1);
				IF n.conval.intval2 > n.conval.intval THEN CPM.LogW("-"); CPM.LogWNum(n.conval.intval2, 1) END;
				IF n.right # NIL THEN CPM.LogW(","); ShowTree(n.right, opts) END
			ELSIF useTree IN opts THEN
				CPM.LogW("("); ShowTree(n.left, {}); CPM.LogW("|"); CPM.LogWNum(n.conval.intval, 1);
				IF n.conval.intval2 > n.conval.intval THEN CPM.LogW("-"); CPM.LogWNum(n.conval.intval2, 1) END;
				CPM.LogW("|"); ShowTree(n.right, {}); CPM.LogW(")")
			ELSE
				ShowTree(n.left, opts); CPM.LogW(" "); CPM.LogWNum(n.conval.intval, 1);
				IF n.conval.intval2 > n.conval.intval THEN CPM.LogW("-"); CPM.LogWNum(n.conval.intval2, 1) END;
				CPM.LogW(" "); ShowTree(n.right, opts)
			END
		END
	END ShowTree;
*)
	PROCEDURE StatSeq(VAR stat: CPT.Node);
		VAR fpar, id, t: CPT.Object; idtyp: CPT.Struct; e: BOOLEAN; oldSym: BYTE;	(*<< oldSym*)
				s, x, y, z, apar, last, lastif, pre, lastp: CPT.Node; pos, p: INTEGER; pos1, lastSemiPos: INTEGER;
					(*<< pos1, pos2, oldPos *)
				lastSemi: BOOLEAN;	(*<<*)
		PROCEDURE CasePart(VAR x: CPT.Node);
			VAR low, high: INTEGER; e: BOOLEAN; cases, lab, y, lastcase, root: CPT.Node; 
		BEGIN
			Expression(x);
			IF (x.class = Ntype) OR (x.class = Nproc) THEN err(126)
			ELSIF x.typ.form = Int64 THEN err(260)
			ELSIF ~(x.typ.form IN intSet + charSet) THEN err(125)
			END ;
			CheckSym(of); cases := NIL; lastcase := NIL; root := NIL;
			low := MAX(INTEGER); high := MIN(INTEGER);
			LOOP
				IF sym < bar THEN
					CaseLabelList(lab, root, x.typ.form, low, high);
					CheckSym(colon); StatSeq(y);
					CPB.Construct(Ncasedo, lab, y); CPB.Link(cases, lastcase, lab)
				END ;
				IF sym = bar THEN CPS.Get(sym) ELSE EXIT END
			END;
			e := sym = else;
			IF e THEN CPS.Get(sym); StatSeq(y) ELSE y := NIL END ;
			CPB.Construct(Ncaselse, cases, y); CPB.Construct(Ncase, x, cases);
			cases.conval := CPT.NewConst();
			cases.conval.intval := low; cases.conval.intval2 := high;
			IF e THEN cases.conval.setval := {1} ELSE cases.conval.setval := {} END;
			Optimize(root); cases.link := root	(* !!! *)
		END CasePart;
		
		PROCEDURE SetPos(x: CPT.Node);
		BEGIN
			x.conval := CPT.NewConst(); x.conval.intval := pos
		END SetPos;

		PROCEDURE CheckBool(VAR x: CPT.Node);
		BEGIN
			IF (x.class = Ntype) OR (x.class = Nproc) THEN err(126); x := CPB.NewBoolConst(FALSE)
			ELSIF x.typ.form # Bool THEN err(120); x := CPB.NewBoolConst(FALSE)
			END
		END CheckBool;

	BEGIN stat := NIL; last := NIL;
		lastSemi := FALSE; lastSemiPos := 0;	(*<<*)
		LOOP x := NIL;
			IF sym < ident THEN err(14);
				REPEAT CPS.Get(sym) UNTIL sym >= ident
			END ;
			INC(nofStats); oldSym := null;	(*<<*)
			pos := CPM.startpos;
			IF sym = ident THEN
				pos1 := CPM.curpos;	(*<<*)
				qualident(id); x := CPB.NewLeaf(id); selector(x);
				IF sym = becomes THEN
					(*<<
					pos2 := CPM.curpos;	(*<<*)
					*)
					CPS.Get(sym); Expression(y);
					Selector(x, SelAssign, SelNoVarPar, SelUseBSet, pos1);	(*<< id gets set for the first time *)
					IF (y.typ.form = Pointer) & (x.typ.form = Comp) THEN CPB.DeRef(y) END;
					pre := NIL; lastp := NIL;
					CPB.CheckBuffering(y, x, NIL, pre, lastp);
					CPB.Assign(x, y);
					(*<< fixed in CP
					IF (x.left.class = Neguard) & (x.right.typ.comp = Record) THEN	(*<< record assignment to varpar *)
						err2(impliedTypeGuard, pos2)
					END;
					*)
					IF pre # NIL THEN SetPos(x); CPB.Construct(Ncomp, pre, x); x := pre END
				ELSIF sym = eql THEN
					err(becomes); CPS.Get(sym); Expression(y); CPB.Assign(x, y)
				ELSIF (x.class = Nproc) & (x.obj.mode = SProc) THEN
					StandProcCall(x);
					IF (x # NIL) & (x.typ # CPT.notyp) THEN err(55) END;
					IF (x # NIL) & (x.class = Nifelse) THEN	(* error pos for ASSERT *)
						SetPos(x.left); SetPos(x.left.right)
					END;
				ELSIF x.class = Ncall THEN err(55)
				ELSE
					pre := NIL; lastp := NIL;
					IF (x.class = Nfield) & (x.obj.mode = TProc)
							& (x.obj.link.mode = VarPar) & (x.obj.link.typ.comp = Record) THEN
						Selector(x.left, SelAssign, SelVarPar, SelUseBSet, pos1)	(*<< receiver is var parameter and record *)
					END;
					Selector(x, SelNoAssign, SelNoVarPar, SelUseBSet, pos1);	(*<< proc in node x gets called *)
					CPB.PrepCall(x, fpar);
					IF (x.obj # NIL) & (x.obj.mode = TProc) THEN CPB.CheckBuffering(x.left, NIL, x.obj.link, pre, lastp) END;
					IF sym = lparen THEN
						CPS.Get(sym); ActualParameters(apar, fpar, pre, lastp); CheckSym(rparen)
					ELSE apar := NIL;
						IF fpar # NIL THEN err(65) END
					END ;
					CPB.Call(x, apar, fpar);
					IF x.typ # CPT.notyp THEN err(55) END;
					IF pre # NIL THEN SetPos(x); CPB.Construct(Ncomp, pre, x); x := pre END;
					IF level > 0 THEN CPT.topScope.link.leaf := FALSE END
				END
			ELSIF sym = if THEN
				CPS.Get(sym); pos := CPM.startpos; Expression(x); CheckBool(x); CheckSym(then); StatSeq(y);
				CPB.Construct(Nif, x, y); SetPos(x); lastif := x;
				WHILE sym = elsif DO
					CPS.Get(sym); pos := CPM.startpos; Expression(y); CheckBool(y); CheckSym(then); StatSeq(z);
					CPB.Construct(Nif, y, z); SetPos(y); CPB.Link(x, lastif, y)
				END ;
				pos := CPM.startpos;
				IF sym = else THEN CPS.Get(sym); StatSeq(y) ELSE y := NIL END ;
				CPB.Construct(Nifelse, x, y); CheckSym(end); CPB.OptIf(x)
			ELSIF sym = case THEN
				CPS.Get(sym); pos := CPM.startpos; CasePart(x); CheckSym(end)
			ELSIF sym = while THEN
				CPS.Get(sym); pos := CPM.startpos; Expression(x); CheckBool(x); CheckSym(do); StatSeq(y);
				CPB.Construct(Nwhile, x, y); CheckSym(end)
			ELSIF sym = repeat THEN
				CPS.Get(sym); StatSeq(x);
				IF sym = until THEN CPS.Get(sym); pos := CPM.startpos; Expression(y); CheckBool(y)
				ELSE err(43)
				END ;
				CPB.Construct(Nrepeat, x, y)
			ELSIF sym = for THEN
				CPS.Get(sym); pos := CPM.startpos;
				IF sym = ident THEN qualident(id);
					SetObj(id, FALSE, CPM.errpos); UseObj(id, TRUE, CPM.errpos);	(*<< for variable gets set & used*)
					INC(id.num, noChange);	(*<< loop variable shouldn't be changed!*)
					IF ~(id.typ.form IN intSet) THEN err(68) END ;
					CheckSym(becomes); Expression(y);
					x := CPB.NewLeaf(id); CPB.Assign(x, y); SetPos(x);
					CheckSym(to); pos := CPM.startpos; Expression(y);
					IF y.class # Nconst THEN
						CPB.GetTempVar("@for", x.left.typ, t);
						t.num := setUsed;	(*<< temporary var gets set and used*)
						z := CPB.NewLeaf(t); CPB.Assign(z, y); SetPos(z); CPB.Link(stat, last, z);
						y := CPB.NewLeaf(t)
					ELSE
						CPB.CheckAssign(x.left.typ, y)
					END ;
					CPB.Link(stat, last, x);
					p := CPM.startpos;
					IF sym = by THEN CPS.Get(sym); ConstExpression(z) ELSE z := CPB.NewIntConst(1) END ;
					x := CPB.NewLeaf(id);
					IF z.conval.intval > 0 THEN CPB.Op(leq, x, y)
					ELSIF z.conval.intval < 0 THEN CPB.Op(geq, x, y)
					ELSE err(63); CPB.Op(geq, x, y)
					END ;
					CheckSym(do); StatSeq(s);
					y := CPB.NewLeaf(id); CPB.StPar1(y, z, incfn); pos := CPM.startpos; SetPos(y);
					IF s = NIL THEN s := y
					ELSE z := s;
						WHILE z.link # NIL DO z := z.link END ;
						z.link := y
					END ;
					CheckSym(end); CPB.Construct(Nwhile, x, s); pos := p;
					DEC(id.num, noChange)	(*<< reset noChange attribute for loopvariable*)
				ELSE err(ident)
				END
			ELSIF sym = loop THEN
				CPS.Get(sym); INC(LoopLevel); StatSeq(x); DEC(LoopLevel);
				CPB.Construct(Nloop, x, NIL); CheckSym(end)
			ELSIF sym = with THEN
				CPS.Get(sym); idtyp := NIL; x := NIL;
				LOOP
					IF sym < bar THEN (* bj: added to be compliant with DevCPP.StatSeq *)
						pos := CPM.startpos;
						IF sym = ident THEN
							qualident(id);
							UseObj(id, TRUE, CPM.errpos);	(*<<*)
							y := CPB.NewLeaf(id);
							IF (id # NIL) & (id.typ.form = Pointer) & ((id.mode = VarPar) OR ~id.leaf) THEN
								err(-302)	(* warning 302 *)
							END ;
							CheckSym(colon);
							IF sym = ident THEN qualident(t);
								UseType(t, CPM.errpos);	(*<< type gets used*)
								IF t.mode = Typ THEN
									IF id # NIL THEN
										idtyp := id.typ; CPB.TypTest(y, t, FALSE); id.typ := t.typ;
										IF id.ptyp = NIL THEN id.ptyp := idtyp END
									ELSE err(130)
									END
								ELSE err(52)
								END
							ELSE err(ident)
							END
						ELSE err(ident)
						END ;
						pos1 := CPM.errpos;	(* << *)
						CheckSym(do); StatSeq(s); CPB.Construct(Nif, y, s); SetPos(y);
						IF idtyp # NIL THEN
							IF id.ptyp = idtyp THEN id.ptyp := NIL END;
							id.typ := idtyp; idtyp := NIL
						END ;
						IF x = NIL THEN x := y; lastif := x ELSE CPB.Link(x, lastif, y) END 
					END;
					IF sym = bar THEN CPS.Get(sym) ELSE EXIT END
				END;
				e := sym = else; pos := CPM.startpos;
				IF e THEN CPS.Get(sym); StatSeq(s) ELSE s := NIL END ;
				CPB.Construct(Nwith, x, s); CheckSym(end);
				IF e THEN x.subcl := 1 END
			ELSIF sym = exit THEN
				CPS.Get(sym);
				IF LoopLevel = 0 THEN err(46) END ;
				CPB.Construct(Nexit, x, NIL);
				oldSym := exit	(*<<*)
			ELSIF sym = return THEN CPS.Get(sym);
				IF sym < semicolon THEN Expression(x) END ;
				IF level > 0 THEN CPB.Return(x, CPT.topScope.link)
				ELSE (* not standard Oberon *) CPB.Return(x, NIL)
				END;
				hasReturn := TRUE;
				oldSym := return	(*<<*)
			ELSE	(*<< empty statement*)
				IF options.semicolons THEN
					IF sym = semicolon THEN err2(semicolons, CPM.errpos)
					ELSIF lastSemi THEN err2(semicolons, lastSemiPos)
					END
				END;
				DEC(nofStats)
			END ;
			IF x # NIL THEN SetPos(x); CPB.Link(stat, last, x) END ;
			IF sym = semicolon THEN 	(*<<*)
				lastSemi := TRUE; lastSemiPos := CPM.errpos
			ELSE lastSemi := FALSE	(*<<*)
			END;
			IF sym = semicolon THEN CPS.Get(sym)
			ELSIF (sym <= ident) OR (if <= sym) & (sym <= return) THEN err(semicolon)
			ELSE EXIT
			END;
			IF (exit <= oldSym) & (oldSym <= return) & ((sym < bar) OR (until < sym)) THEN	(*<< statement after return/exit*)
				err2(statAfterRetEx, CPM.errpos)
			END
		END
	END StatSeq;

	PROCEDURE Block(VAR procdec, statseq: CPT.Node);
		VAR typ: CPT.Struct;
			obj, first, last, o: CPT.Object;
			x, lastdec: CPT.Node;
			i: SHORTINT;
			rname: CPT.Name;
			name: CPT.String;
			rec: Elem;
			pos, save: INTEGER;	(*<<*)

	BEGIN
		first := NIL; last := NIL; userList := NIL; recList := NIL;
		save := nofStats;	(*<<*)
		LOOP
			IF sym = const THEN
				CPS.Get(sym);
				WHILE sym = ident DO
					CheckOuter;	(*<<*)
					CPT.Insert(CPS.name, obj);
					obj.mode := Con; CheckMark(obj);
					obj.typ := CPT.int8typ; obj.mode := Var;	(* Var to avoid recursive definition *)
					pos := CPM.errpos;	(*<<*)
					IF sym = eql THEN
						CPS.Get(sym); ConstExpression(x)
					ELSIF sym = becomes THEN
						err(eql); CPS.Get(sym); ConstExpression(x)
					ELSE err(eql); x := CPB.NewIntConst(1)
					END ;
					obj.mode := Con; obj.typ := x.typ; obj.conval := x.conval; (* ConstDesc ist not copied *)
					obj.adr := pos; obj.num := set;	(*<< constants are set by default*)
					CheckSym(semicolon)
				END
			END ;
			IF sym = type THEN
				CPS.Get(sym);
				WHILE sym = ident DO
					CheckOuter;	(*<<*)
					CPT.Find(CPS.name, obj); (* could have been used as a forward type definition *)
					IF obj = NIL THEN CPT.Insert(CPS.name, obj) END;
					obj.mode := -1; obj.typ := CPT.undftyp;
					CheckMark(obj);
					obj.adr := CPM.errpos;
					IF obj.num > clean THEN obj.num := setUsed ELSE  obj.num := set END;	(*<< types are set by default*)
					IF sym # eql THEN err(eql) END;
					IF (sym = eql) OR (sym = becomes) OR (sym = colon) THEN
						CPS.Get(sym); Type(obj.typ, name); SetType(NIL, obj, obj.typ, name)
					END;
					obj.mode := Typ;
					IF obj.typ.form IN {Byte..Set, Char16, Int64} THEN	(* make alias structure *)
						typ := CPT.NewStr(obj.typ.form, Basic); i := typ.ref;
						typ^ := obj.typ^; typ.ref := i; typ.strobj := NIL; typ.mno := 0;
						typ.BaseTyp := obj.typ; obj.typ := typ
					END;
					IF obj.typ.strobj = NIL THEN obj.typ.strobj := obj END ;
					IF obj.typ.form = Pointer THEN	(* !!! *)
						typ := obj.typ.BaseTyp;
						IF (typ # NIL) & (typ.comp = Record) & (typ.strobj = NIL) THEN
							(* pointer to unnamed record: name record as "pointerName^" *)
							rname := obj.name^$; i := 0;
							WHILE rname[i] # 0X DO INC(i) END;
							rname[i] := "^"; rname[i+1] := 0X;
							CPT.Insert(rname, o); o.mode := Typ; o.typ := typ; typ.strobj := o;
							o.adr := CPM.errpos; o.num := setUsed	(*<< anonymous record types are set and used by default*)
						END
					END;
					IF obj.vis # internal THEN
						typ := obj.typ;
						IF typ.form = Pointer THEN typ := typ.BaseTyp END;
						IF typ.comp = Record THEN typ.exp := TRUE END
					END;
					CheckSym(semicolon)
				END
			END ;
			IF sym = var THEN
				CPS.Get(sym);
				WHILE sym = ident DO
					LOOP
						IF sym = ident THEN
							CheckOuter;	(*<<*)
							CPT.Insert(CPS.name, obj);
							obj.mode := Var; obj.link := NIL; obj.leaf := obj.vis = internal; obj.typ := CPT.undftyp;
							CheckMark(obj);
							obj.adr := CPM.errpos; obj.num := clean;	(*<<*)
							IF first = NIL THEN first := obj END ;
							IF last = NIL THEN CPT.topScope.scope := obj ELSE last.link := obj END;
							last := obj
						ELSE err(ident)
						END;
						IF sym = comma THEN CPS.Get(sym)
						ELSIF sym = ident THEN err(comma); 
						ELSE EXIT
						END
					END ;
					CheckSym(colon); Type(typ, name);
					CheckAlloc(typ, FALSE, CPM.errpos);
					WHILE first # NIL DO SetType(NIL, first, typ, name); first := first.link END ;
					CheckSym(semicolon)
				END
			END ;
			IF (sym < const) OR (sym > var) THEN EXIT END
		END ;
		nofStats := save;	(*<<*)
		CheckForwardTypes; 
		userList := NIL; rec := recList; recList := NIL;
		CPT.topScope.adr := CPM.errpos;
		procdec := NIL; lastdec := NIL;
		WHILE sym = procedure DO
			CPS.Get(sym); ProcedureDeclaration(x);
			IF x # NIL THEN
				IF lastdec = NIL THEN procdec := x ELSE lastdec.link := x END ;
				lastdec := x
			END ;
			CheckSym(semicolon)
		END ;
		IF CPM.noerr & ~(CPM.oberon IN CPM.options) THEN CheckRecords(rec) END;
		hasReturn := FALSE;
		IF sym = begin THEN CPS.Get(sym); StatSeq(statseq)
		ELSE statseq := NIL
		END ;
		IF (CPT.topScope.link # NIL) & (CPT.topScope.link.typ # CPT.notyp)
			& ~hasReturn & (CPT.topScope.link.sysflag = 0) THEN err(133) END;
		IF (level = 0) & (TDinit # NIL) THEN
			lastTDinit.link := statseq; statseq := TDinit
		END
	END Block;

	PROCEDURE Module*(VAR prog: CPT.Node);
		VAR impName, aliasName: CPT.Name; obj: CPT.Object;	(*<< obj *)
				procdec, statseq: CPT.Node;
				c: INTEGER; done: BOOLEAN;
	BEGIN
		CPS.Init; LoopLevel := 0; level := 0; CPS.Get(sym);
		NEW(errHead); nofStats := 0;	(*<<*)
		IF sym = module THEN CPS.Get(sym) ELSE err(16) END ;
		IF sym = ident THEN
			CPT.Open(CPS.name); CPS.Get(sym);
			CPT.libName := "";
			IF sym = lbrak THEN
				INCL(CPM.options, CPM.interface); CPS.Get(sym);
				IF sym = string THEN CPT.libName := CPS.str^$; CPS.Get(sym)
				ELSE err(string)
				END;
				CheckSym(rbrak)
			END;
			CheckSym(semicolon);
			IF sym = import THEN CPS.Get(sym);
				INCL(CPM.options, CPM.comAware); (* BJ: to avoid error when importing COM *)
				LOOP
					IF sym = ident THEN
						aliasName := CPS.name$; impName := aliasName$; CPS.Get(sym);
						IF sym = becomes THEN CPS.Get(sym);
							IF sym = ident THEN impName := CPS.name$; CPS.Get(sym) ELSE err(ident) END
						END ;
						CPT.Import(aliasName, impName, done);
						CPS.name := aliasName$;	(*<<*)
						CPT.Find(CPS.name, obj);
						IF obj # NIL THEN obj.adr := CPM.errpos; obj.num := set END (*<< modules are set by default *)
					ELSE err(ident)
					END ;
					IF sym = comma THEN CPS.Get(sym)
					ELSIF sym = ident THEN err(comma)
					ELSE EXIT
					END
				END ;
				CheckSym(semicolon)
			END ;
			IF CPM.noerr THEN 
				TDinit := NIL; lastTDinit := NIL; c := CPM.errpos;
				Block(procdec, statseq); CPB.Enter(procdec, statseq, NIL); prog := procdec;
				prog.conval := CPT.NewConst(); prog.conval.intval := c; prog.conval.intval2 := CPM.startpos;
				IF sym = close THEN CPS.Get(sym); StatSeq(prog.link) END;
				prog.conval.realval := CPM.startpos;
				CheckSym(end);
				IF sym = ident THEN
					IF CPS.name # CPT.SelfName THEN err(4) END ;
					CPS.Get(sym)
				ELSE err(ident)
				END;
				IF sym # period THEN err(period) END;
				CheckScope(CPT.topScope)	(*<<*)
			END
		ELSE err(ident)
		END ;
		TDinit := NIL; lastTDinit := NIL
	END Module;

	PROCEDURE WriteWarnings(text: TextModels.Model; VAR warning: BOOLEAN);	(*<<O/F*)
		VAR e: Warning; inserted: SHORTINT;
	BEGIN
		IF errHead.next = NIL THEN warning := FALSE; CPM.LogWStr(" done")
		ELSE
			warning := TRUE;
			e := errHead.next; inserted := 0;
			WHILE e # NIL DO
				DevMarkers.Insert(text, e.pos+inserted, DevMarkers.dir.New(e.n));	(*<<*)
				e := e.next; INC(inserted)
			END
		END;
		errHead := NIL
	END WriteWarnings;

(*<<OP2 procedures *)
	PROCEDURE TypeSize(typ: CPT.Struct);
	END TypeSize;

	PROCEDURE ProcessModule (source: TextModels.Reader; log: TextModels.Model; VAR error, warning: BOOLEAN);
		VAR p: CPT.Node; script: Stores.Operation; text: TextModels.Model;
	BEGIN
		text := source.Base();
		Models.BeginModification(Models.clean, text);
		Models.BeginScript(text, "#Dev:InsertMarkers", script);
		CPM.Init(source, log);
		CPT.Init({});
		CPB.typSize := (*<<OPV.*)TypeSize;
		(*<<CPT.processor := OPL.processor;*)
		Module(p);
	(*<<
		IF CPM.noerr THEN
			OPV.Init(opt, DevDebug.breakPos); OPV.Allocate; CPT.Export(ext, new);
			IF CPM.noerr THEN
				OPV.Module(p);
				IF CPM.noerr THEN
					IF new OR ext THEN CPM.RegisterNewSym END ;
					CPM.LogWStr("	"); CPM.LogWNum(OPL.pc, 8);
					CPM.LogWStr("	"); CPM.LogWNum(OPL.dsize, 8)
				ELSE CPM.DeleteNewSym
				END
			END ;
			OPL.Close
		END ;
	*)
		CPT.Close;
		error := ~CPM.noerr;
		CPM.Close;
		p := NIL;
		Kernel.FastCollect;
		IF error THEN
			CPM.InsertMarks(source.Base());
			CPM.LogWLn; CPM.LogWStr(" ");
			IF CPM.errors = 1 THEN
				Dialog.MapString("#Dev:OneErrorDetected", str)
			ELSE
				CPM.LogWNum(CPM.errors, 0); Dialog.MapString("#Dev:ErrorsDetected", str)
			END;
			StdLog.String(str)
		ELSE	(*<<*)
			options.statements := nofStats;
			WriteWarnings(text, warning);
			CPM.LogWLn; CPM.LogWNum(nofStats, 0); CPM.LogWStr(" statements")
		END;
		CPM.LogWLn; CPM.Close;
		Models.EndScript(source.Base(), script);
		Models.EndModification(Models.clean, text)
	END ProcessModule;


	PROCEDURE Do (source, log: TextModels.Model; beg: INTEGER; VAR error, warning: BOOLEAN);
		VAR r: TextMappers.Scanner;
	BEGIN
		Dialog.MapString("#Dev:Analyzing", str);
		StdLog.String(str); StdLog.Char(" ");
		options.fileName := "";
		r.ConnectTo(source); r.SetPos(beg); r.Scan;
		IF (r.type = TextMappers.string) & (r.string = "MODULE") THEN
			r.Scan;
			IF r.type = TextMappers.string THEN
				StdLog.Char('"'); StdLog.String(r.string); StdLog.Char('"');
				options.fileName := r.string
			END
		END;
		sourceR := source.NewReader(NIL); sourceR.SetPos(beg);
		ProcessModule(sourceR, log, error, warning); Dialog.Update(options)
	END Do;

	PROCEDURE Open;
	BEGIN
		Dialog.ShowStatus("#Dev:Analyzing");
		StdLog.buf.Delete(0, StdLog.buf.Length())
	END Open;
	
	PROCEDURE Close (noerr: BOOLEAN);
	BEGIN
		StdLog.text.Append(StdLog.buf);
		IF noerr & CPM.noerr THEN Dialog.ShowStatus("#Dev:Ok")
		END;
		sourceR := NIL;
		Kernel.Cleanup
	END Close;

	PROCEDURE Analyze*;
		VAR t: TextModels.Model; error, warning: BOOLEAN;
	BEGIN
		Open;
		t := TextViews.FocusText();
		IF t # NIL THEN
			Do(t, StdLog.text, 0, error, warning);
			IF error OR warning THEN DevMarkers.ShowFirstError(t, TextViews.focusOnly) END
		ELSE Dialog.ShowMsg("#Dev:NoTextViewFound")
		END;
		Close(~error & ~warning)
	END Analyze;

	PROCEDURE ResetOptions*;
	BEGIN
		options.varpar := FALSE; options.exported := FALSE;
		options.intermediate := FALSE; options.levels := FALSE;
		options.tbProcs := FALSE; options.semicolons := FALSE;
		options.sideEffects := FALSE;
		options.statements := 0; options.fileName := "";
		Dialog.Update(options)
	END ResetOptions;

	PROCEDURE SaveOptions*;
	BEGIN
		HostRegistry.WriteBool(regKey + 'varPar', options.varpar);
		HostRegistry.WriteBool(regKey + 'exported', options.exported);
		HostRegistry.WriteBool(regKey + 'intermediate', options.intermediate);
		HostRegistry.WriteBool(regKey + 'levels', options.levels);		
		HostRegistry.WriteBool(regKey + 'tbProcs', options.tbProcs);		
		HostRegistry.WriteBool(regKey + 'semicolons', options.semicolons);	
		HostRegistry.WriteBool(regKey + 'sideEffects', options.sideEffects);
	END SaveOptions;

	PROCEDURE LoadOptions*;
		VAR res: INTEGER;
	BEGIN
		HostRegistry.ReadBool(regKey + 'varPar', options.varpar, res);
		IF res # 0 THEN options.varpar := FALSE END;
		HostRegistry.ReadBool(regKey + 'exported', options.exported, res);
		IF res # 0 THEN options.exported := FALSE END;
		HostRegistry.ReadBool(regKey + 'intermediate', options.intermediate,res);
		IF res # 0 THEN options.intermediate := FALSE END;
		HostRegistry.ReadBool(regKey + 'levels', options.levels, res);
		IF res # 0 THEN options.levels := FALSE END;
		HostRegistry.ReadBool(regKey + 'tbProcs', options.tbProcs, res);
		IF res # 0 THEN options.tbProcs := FALSE END;
		HostRegistry.ReadBool(regKey + 'semicolons', options.semicolons, res);
		IF res # 0 THEN options.semicolons := FALSE END;
		HostRegistry.ReadBool(regKey + 'sideEffects', options.sideEffects, res);
		IF res # 0 THEN options.sideEffects := FALSE END;
		Dialog.Update(options)
	END LoadOptions;

BEGIN ResetOptions; LoadOptions
END DevAnalyzer.

Warnings:
900	never used
901	never set
902	used before set
903	set but never used
904	used as varpar, possibly not set
905	also declared in outer scope
906	access/assignment to intermediate
907	redefinition
908	new definition
909	statement after RETURN/EXIT
910	for loop variable set
911	implied type guard
912	superfluous type guard
913	call might depend on evaluation sequence of params.
930	superfluous semicolon

Menu entry:
SEPARATOR
	"Analyze"	"="	"DevAnalyzer.Analyze"	"TextCmds.FocusGuard"
	"Analyze Selection"	""	"DevAnalyzer.AnalyzeSelection"	"TextCmds.SelectionGuard"
	"Analyze..."	""	"StdCmds.OpenToolDialog('Dev/Rsrc/Analyzer', 'Analyze')"	""

