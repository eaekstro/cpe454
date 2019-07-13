/***************************************************************
 * Eric Ekstrom
 * CPE454
 * Last Update: 2019-05-05 16:56:22.615832
 *
 * ISR C Interface
 ***************************************************************/

#ifndef ISR_H
#define ISR_H

#include "interrupt.h"

extern void ISR0();
extern void ISR1();
extern void ISR2();
extern void ISR3();
extern void ISR4();
extern void ISR5();
extern void ISR6();
extern void ISR7();
extern void ISR8();
extern void ISR9();
extern void ISR10();
extern void ISR11();
extern void ISR12();
extern void ISR13();
extern void ISR14();
extern void ISR15();
extern void ISR16();
extern void ISR17();
extern void ISR18();
extern void ISR19();
extern void ISR20();
extern void ISR21();
extern void ISR22();
extern void ISR23();
extern void ISR24();
extern void ISR25();
extern void ISR26();
extern void ISR27();
extern void ISR28();
extern void ISR29();
extern void ISR30();
extern void ISR31();
extern void ISR32();
extern void ISR33();
extern void ISR34();
extern void ISR35();
extern void ISR36();
extern void ISR37();
extern void ISR38();
extern void ISR39();
extern void ISR40();
extern void ISR41();
extern void ISR42();
extern void ISR43();
extern void ISR44();
extern void ISR45();
extern void ISR46();
extern void ISR47();
extern void ISR48();
extern void ISR49();
extern void ISR50();
extern void ISR51();
extern void ISR52();
extern void ISR53();
extern void ISR54();
extern void ISR55();
extern void ISR56();
extern void ISR57();
extern void ISR58();
extern void ISR59();
extern void ISR60();
extern void ISR61();
extern void ISR62();
extern void ISR63();
extern void ISR64();
extern void ISR65();
extern void ISR66();
extern void ISR67();
extern void ISR68();
extern void ISR69();
extern void ISR70();
extern void ISR71();
extern void ISR72();
extern void ISR73();
extern void ISR74();
extern void ISR75();
extern void ISR76();
extern void ISR77();
extern void ISR78();
extern void ISR79();
extern void ISR80();
extern void ISR81();
extern void ISR82();
extern void ISR83();
extern void ISR84();
extern void ISR85();
extern void ISR86();
extern void ISR87();
extern void ISR88();
extern void ISR89();
extern void ISR90();
extern void ISR91();
extern void ISR92();
extern void ISR93();
extern void ISR94();
extern void ISR95();
extern void ISR96();
extern void ISR97();
extern void ISR98();
extern void ISR99();
extern void ISR100();
extern void ISR101();
extern void ISR102();
extern void ISR103();
extern void ISR104();
extern void ISR105();
extern void ISR106();
extern void ISR107();
extern void ISR108();
extern void ISR109();
extern void ISR110();
extern void ISR111();
extern void ISR112();
extern void ISR113();
extern void ISR114();
extern void ISR115();
extern void ISR116();
extern void ISR117();
extern void ISR118();
extern void ISR119();
extern void ISR120();
extern void ISR121();
extern void ISR122();
extern void ISR123();
extern void ISR124();
extern void ISR125();
extern void ISR126();
extern void ISR127();
extern void ISR128();
extern void ISR129();
extern void ISR130();
extern void ISR131();
extern void ISR132();
extern void ISR133();
extern void ISR134();
extern void ISR135();
extern void ISR136();
extern void ISR137();
extern void ISR138();
extern void ISR139();
extern void ISR140();
extern void ISR141();
extern void ISR142();
extern void ISR143();
extern void ISR144();
extern void ISR145();
extern void ISR146();
extern void ISR147();
extern void ISR148();
extern void ISR149();
extern void ISR150();
extern void ISR151();
extern void ISR152();
extern void ISR153();
extern void ISR154();
extern void ISR155();
extern void ISR156();
extern void ISR157();
extern void ISR158();
extern void ISR159();
extern void ISR160();
extern void ISR161();
extern void ISR162();
extern void ISR163();
extern void ISR164();
extern void ISR165();
extern void ISR166();
extern void ISR167();
extern void ISR168();
extern void ISR169();
extern void ISR170();
extern void ISR171();
extern void ISR172();
extern void ISR173();
extern void ISR174();
extern void ISR175();
extern void ISR176();
extern void ISR177();
extern void ISR178();
extern void ISR179();
extern void ISR180();
extern void ISR181();
extern void ISR182();
extern void ISR183();
extern void ISR184();
extern void ISR185();
extern void ISR186();
extern void ISR187();
extern void ISR188();
extern void ISR189();
extern void ISR190();
extern void ISR191();
extern void ISR192();
extern void ISR193();
extern void ISR194();
extern void ISR195();
extern void ISR196();
extern void ISR197();
extern void ISR198();
extern void ISR199();
extern void ISR200();
extern void ISR201();
extern void ISR202();
extern void ISR203();
extern void ISR204();
extern void ISR205();
extern void ISR206();
extern void ISR207();
extern void ISR208();
extern void ISR209();
extern void ISR210();
extern void ISR211();
extern void ISR212();
extern void ISR213();
extern void ISR214();
extern void ISR215();
extern void ISR216();
extern void ISR217();
extern void ISR218();
extern void ISR219();
extern void ISR220();
extern void ISR221();
extern void ISR222();
extern void ISR223();
extern void ISR224();
extern void ISR225();
extern void ISR226();
extern void ISR227();
extern void ISR228();
extern void ISR229();
extern void ISR230();
extern void ISR231();
extern void ISR232();
extern void ISR233();
extern void ISR234();
extern void ISR235();
extern void ISR236();
extern void ISR237();
extern void ISR238();
extern void ISR239();
extern void ISR240();
extern void ISR241();
extern void ISR242();
extern void ISR243();
extern void ISR244();
extern void ISR245();
extern void ISR246();
extern void ISR247();
extern void ISR248();
extern void ISR249();
extern void ISR250();
extern void ISR251();
extern void ISR252();
extern void ISR253();
extern void ISR254();
extern void ISR255();

void (*isr_table[256]) = {
	ISR0,
	ISR1,
	ISR2,
	ISR3,
	ISR4,
	ISR5,
	ISR6,
	ISR7,
	ISR8,
	ISR9,
	ISR10,
	ISR11,
	ISR12,
	ISR13,
	ISR14,
	ISR15,
	ISR16,
	ISR17,
	ISR18,
	ISR19,
	ISR20,
	ISR21,
	ISR22,
	ISR23,
	ISR24,
	ISR25,
	ISR26,
	ISR27,
	ISR28,
	ISR29,
	ISR30,
	ISR31,
	ISR32,
	ISR33,
	ISR34,
	ISR35,
	ISR36,
	ISR37,
	ISR38,
	ISR39,
	ISR40,
	ISR41,
	ISR42,
	ISR43,
	ISR44,
	ISR45,
	ISR46,
	ISR47,
	ISR48,
	ISR49,
	ISR50,
	ISR51,
	ISR52,
	ISR53,
	ISR54,
	ISR55,
	ISR56,
	ISR57,
	ISR58,
	ISR59,
	ISR60,
	ISR61,
	ISR62,
	ISR63,
	ISR64,
	ISR65,
	ISR66,
	ISR67,
	ISR68,
	ISR69,
	ISR70,
	ISR71,
	ISR72,
	ISR73,
	ISR74,
	ISR75,
	ISR76,
	ISR77,
	ISR78,
	ISR79,
	ISR80,
	ISR81,
	ISR82,
	ISR83,
	ISR84,
	ISR85,
	ISR86,
	ISR87,
	ISR88,
	ISR89,
	ISR90,
	ISR91,
	ISR92,
	ISR93,
	ISR94,
	ISR95,
	ISR96,
	ISR97,
	ISR98,
	ISR99,
	ISR100,
	ISR101,
	ISR102,
	ISR103,
	ISR104,
	ISR105,
	ISR106,
	ISR107,
	ISR108,
	ISR109,
	ISR110,
	ISR111,
	ISR112,
	ISR113,
	ISR114,
	ISR115,
	ISR116,
	ISR117,
	ISR118,
	ISR119,
	ISR120,
	ISR121,
	ISR122,
	ISR123,
	ISR124,
	ISR125,
	ISR126,
	ISR127,
	ISR128,
	ISR129,
	ISR130,
	ISR131,
	ISR132,
	ISR133,
	ISR134,
	ISR135,
	ISR136,
	ISR137,
	ISR138,
	ISR139,
	ISR140,
	ISR141,
	ISR142,
	ISR143,
	ISR144,
	ISR145,
	ISR146,
	ISR147,
	ISR148,
	ISR149,
	ISR150,
	ISR151,
	ISR152,
	ISR153,
	ISR154,
	ISR155,
	ISR156,
	ISR157,
	ISR158,
	ISR159,
	ISR160,
	ISR161,
	ISR162,
	ISR163,
	ISR164,
	ISR165,
	ISR166,
	ISR167,
	ISR168,
	ISR169,
	ISR170,
	ISR171,
	ISR172,
	ISR173,
	ISR174,
	ISR175,
	ISR176,
	ISR177,
	ISR178,
	ISR179,
	ISR180,
	ISR181,
	ISR182,
	ISR183,
	ISR184,
	ISR185,
	ISR186,
	ISR187,
	ISR188,
	ISR189,
	ISR190,
	ISR191,
	ISR192,
	ISR193,
	ISR194,
	ISR195,
	ISR196,
	ISR197,
	ISR198,
	ISR199,
	ISR200,
	ISR201,
	ISR202,
	ISR203,
	ISR204,
	ISR205,
	ISR206,
	ISR207,
	ISR208,
	ISR209,
	ISR210,
	ISR211,
	ISR212,
	ISR213,
	ISR214,
	ISR215,
	ISR216,
	ISR217,
	ISR218,
	ISR219,
	ISR220,
	ISR221,
	ISR222,
	ISR223,
	ISR224,
	ISR225,
	ISR226,
	ISR227,
	ISR228,
	ISR229,
	ISR230,
	ISR231,
	ISR232,
	ISR233,
	ISR234,
	ISR235,
	ISR236,
	ISR237,
	ISR238,
	ISR239,
	ISR240,
	ISR241,
	ISR242,
	ISR243,
	ISR244,
	ISR245,
	ISR246,
	ISR247,
	ISR248,
	ISR249,
	ISR250,
	ISR251,
	ISR252,
	ISR253,
	ISR254,
	ISR255
};

#endif