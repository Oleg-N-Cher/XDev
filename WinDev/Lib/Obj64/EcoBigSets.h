/*  Ofront 1.2 -xtspkae */

#ifndef EcoBigSets__h
#define EcoBigSets__h

#include "SYSTEM.h"

typedef
	SET EcoBigSets_CHARSET[7];




import void EcoBigSets_Difference (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len);
import void EcoBigSets_Empty (SET *set, LONGINT set__len);
import void EcoBigSets_Excl (SET *set, LONGINT set__len, INTEGER element);
import void EcoBigSets_ExclRange (SET *set, LONGINT set__len, INTEGER firstElement, INTEGER lastElement);
import BOOLEAN EcoBigSets_In (SET *set, LONGINT set__len, INTEGER element);
import void EcoBigSets_Incl (SET *set, LONGINT set__len, INTEGER element);
import void EcoBigSets_InclRange (SET *set, LONGINT set__len, INTEGER firstElement, INTEGER lastElement);
import void EcoBigSets_Intersection (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len);
import BOOLEAN EcoBigSets_IsEmpty (SET *set, LONGINT set__len);
import void EcoBigSets_SymmetricDiff (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len);
import void EcoBigSets_Union (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len);
import void *EcoBigSets__init(void);


#endif
