/*  Ofront 1.2 -xtspkae */
#include "SYSTEM.h"

typedef
	SET EcoBigSets_CHARSET[7];




export void EcoBigSets_Difference (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len);
export void EcoBigSets_Empty (SET *set, LONGINT set__len);
export void EcoBigSets_Excl (SET *set, LONGINT set__len, INTEGER element);
export void EcoBigSets_ExclRange (SET *set, LONGINT set__len, INTEGER firstElement, INTEGER lastElement);
export BOOLEAN EcoBigSets_In (SET *set, LONGINT set__len, INTEGER element);
export void EcoBigSets_Incl (SET *set, LONGINT set__len, INTEGER element);
export void EcoBigSets_InclRange (SET *set, LONGINT set__len, INTEGER firstElement, INTEGER lastElement);
export void EcoBigSets_Intersection (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len);
export BOOLEAN EcoBigSets_IsEmpty (SET *set, LONGINT set__len);
export void EcoBigSets_SymmetricDiff (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len);
export void EcoBigSets_Union (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len);


/*============================================================================*/

void EcoBigSets_Empty (SET *set, LONGINT set__len)
{
	INTEGER index;
	index = 0;
	while ((LONGINT)index < set__len) {
		set[__X(index, set__len)] = 0x0;
		index += 1;
	}
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoBigSets_IsEmpty (SET *set, LONGINT set__len)
{
	INTEGER index;
	BOOLEAN empty;
	empty = 1;
	index = 0;
	while (empty && (LONGINT)index < set__len) {
		empty = set[__X(index, set__len)] == 0x0;
		index += 1;
	}
	return empty;
}

/*----------------------------------------------------------------------------*/
BOOLEAN EcoBigSets_In (SET *set, LONGINT set__len, INTEGER element)
{
	INTEGER index, bit;
	index = __ASHR(element, 5, INTEGER);
	bit = __MASK(element, -32);
	return __IN(bit, set[__X(index, set__len)]);
}

/*----------------------------------------------------------------------------*/
void EcoBigSets_Incl (SET *set, LONGINT set__len, INTEGER element)
{
	INTEGER index, bit;
	index = __ASHR(element, 5, INTEGER);
	bit = __MASK(element, -32);
	set[__X(index, set__len)] |= __SETOF(bit);
}

/*----------------------------------------------------------------------------*/
void EcoBigSets_Excl (SET *set, LONGINT set__len, INTEGER element)
{
	INTEGER index, bit;
	index = __ASHR(element, 5, INTEGER);
	bit = __MASK(element, -32);
	set[__X(index, set__len)] &= ~__SETOF(bit);
}

/*----------------------------------------------------------------------------*/
void EcoBigSets_InclRange (SET *set, LONGINT set__len, INTEGER firstElement, INTEGER lastElement)
{
	INTEGER index, bit, count;
	index = __ASHR(firstElement, 5, INTEGER);
	bit = __MASK(firstElement, -32);
	count = (lastElement - firstElement) + 1;
	while (count > 0) {
		set[__X(index, set__len)] |= __SETOF(bit);
		bit += 1;
		if (bit == 32) {
			bit = 0;
			index += 1;
		}
		count -= 1;
	}
}

/*----------------------------------------------------------------------------*/
void EcoBigSets_ExclRange (SET *set, LONGINT set__len, INTEGER firstElement, INTEGER lastElement)
{
	INTEGER index, bit, count;
	index = __ASHR(firstElement, 5, INTEGER);
	bit = __MASK(firstElement, -32);
	count = (lastElement - firstElement) + 1;
	while (count > 0) {
		set[__X(index, set__len)] &= ~__SETOF(bit);
		bit += 1;
		if (bit == 32) {
			bit = 0;
			index += 1;
		}
		count -= 1;
	}
}

/*----------------------------------------------------------------------------*/
void EcoBigSets_Union (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len)
{
	INTEGER index, maxIndex;
	index = 0;
	maxIndex = (INTEGER)firstSet__len;
	while (index < maxIndex) {
		destSet[__X(index, destSet__len)] = firstSet[__X(index, firstSet__len)] | secondSet[__X(index, secondSet__len)];
		index += 1;
	}
}

/*----------------------------------------------------------------------------*/
void EcoBigSets_Difference (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len)
{
	INTEGER index, maxIndex;
	index = 0;
	maxIndex = (INTEGER)firstSet__len;
	while (index < maxIndex) {
		destSet[__X(index, destSet__len)] = firstSet[__X(index, firstSet__len)] & ~secondSet[__X(index, secondSet__len)];
		index += 1;
	}
}

/*----------------------------------------------------------------------------*/
void EcoBigSets_Intersection (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len)
{
	INTEGER index, maxIndex;
	index = 0;
	maxIndex = (INTEGER)firstSet__len;
	while (index < maxIndex) {
		destSet[__X(index, destSet__len)] = firstSet[__X(index, firstSet__len)] & secondSet[__X(index, secondSet__len)];
		index += 1;
	}
}

/*----------------------------------------------------------------------------*/
void EcoBigSets_SymmetricDiff (SET *firstSet, LONGINT firstSet__len, SET *secondSet, LONGINT secondSet__len, SET *destSet, LONGINT destSet__len)
{
	INTEGER index, maxIndex;
	index = 0;
	maxIndex = (INTEGER)firstSet__len;
	while (index < maxIndex) {
		destSet[__X(index, destSet__len)] = firstSet[__X(index, firstSet__len)] ^ secondSet[__X(index, secondSet__len)];
		index += 1;
	}
}

/*----------------------------------------------------------------------------*/

export void *EcoBigSets__init(void)
{
	__DEFMOD;
	__REGMOD("EcoBigSets", 0);
/* BEGIN */
	__ENDMOD;
}
