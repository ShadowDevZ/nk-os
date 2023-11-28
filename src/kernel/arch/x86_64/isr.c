#include "include/isr.h"
#include "include/idt.h"
#include "include/panic.h"

char *exception_messages[] = {
    "Division by Zero",
    "Debug",
    "Non-Maskable Interrupt",
    "Breakpoint",
    "Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bat TSS",
    "Segment not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
};

char** GetIsrExceptionList() {
    return exception_messages;
}

#include "include/idt.h"

void  X64_ISR0();
void  X64_ISR1();
void  X64_ISR2();
void  X64_ISR3();
void  X64_ISR4();
void  X64_ISR5();
void  X64_ISR6();
void  X64_ISR7();
void  X64_ISR8();
void  X64_ISR9();
void  X64_ISR10();
void  X64_ISR11();
void  X64_ISR12();
void  X64_ISR13();
void  X64_ISR14();
void  X64_ISR15();
void  X64_ISR16();
void  X64_ISR17();
void  X64_ISR18();
void  X64_ISR19();
void  X64_ISR20();
void  X64_ISR21();
void  X64_ISR22();
void  X64_ISR23();
void  X64_ISR24();
void  X64_ISR25();
void  X64_ISR26();
void  X64_ISR27();
void  X64_ISR28();
void  X64_ISR29();
void  X64_ISR30();
void  X64_ISR31();
void  X64_ISR32();
void  X64_ISR33();
void  X64_ISR34();
void  X64_ISR35();
void  X64_ISR36();
void  X64_ISR37();
void  X64_ISR38();
void  X64_ISR39();
void  X64_ISR40();
void  X64_ISR41();
void  X64_ISR42();
void  X64_ISR43();
void  X64_ISR44();
void  X64_ISR45();
void  X64_ISR46();
void  X64_ISR47();
void  X64_ISR48();
void  X64_ISR49();
void  X64_ISR50();
void  X64_ISR51();
void  X64_ISR52();
void  X64_ISR53();
void  X64_ISR54();
void  X64_ISR55();
void  X64_ISR56();
void  X64_ISR57();
void  X64_ISR58();
void  X64_ISR59();
void  X64_ISR60();
void  X64_ISR61();
void  X64_ISR62();
void  X64_ISR63();
void  X64_ISR64();
void  X64_ISR65();
void  X64_ISR66();
void  X64_ISR67();
void  X64_ISR68();
void  X64_ISR69();
void  X64_ISR70();
void  X64_ISR71();
void  X64_ISR72();
void  X64_ISR73();
void  X64_ISR74();
void  X64_ISR75();
void  X64_ISR76();
void  X64_ISR77();
void  X64_ISR78();
void  X64_ISR79();
void  X64_ISR80();
void  X64_ISR81();
void  X64_ISR82();
void  X64_ISR83();
void  X64_ISR84();
void  X64_ISR85();
void  X64_ISR86();
void  X64_ISR87();
void  X64_ISR88();
void  X64_ISR89();
void  X64_ISR90();
void  X64_ISR91();
void  X64_ISR92();
void  X64_ISR93();
void  X64_ISR94();
void  X64_ISR95();
void  X64_ISR96();
void  X64_ISR97();
void  X64_ISR98();
void  X64_ISR99();
void  X64_ISR100();
void  X64_ISR101();
void  X64_ISR102();
void  X64_ISR103();
void  X64_ISR104();
void  X64_ISR105();
void  X64_ISR106();
void  X64_ISR107();
void  X64_ISR108();
void  X64_ISR109();
void  X64_ISR110();
void  X64_ISR111();
void  X64_ISR112();
void  X64_ISR113();
void  X64_ISR114();
void  X64_ISR115();
void  X64_ISR116();
void  X64_ISR117();
void  X64_ISR118();
void  X64_ISR119();
void  X64_ISR120();
void  X64_ISR121();
void  X64_ISR122();
void  X64_ISR123();
void  X64_ISR124();
void  X64_ISR125();
void  X64_ISR126();
void  X64_ISR127();
void  X64_ISR128();
void  X64_ISR129();
void  X64_ISR130();
void  X64_ISR131();
void  X64_ISR132();
void  X64_ISR133();
void  X64_ISR134();
void  X64_ISR135();
void  X64_ISR136();
void  X64_ISR137();
void  X64_ISR138();
void  X64_ISR139();
void  X64_ISR140();
void  X64_ISR141();
void  X64_ISR142();
void  X64_ISR143();
void  X64_ISR144();
void  X64_ISR145();
void  X64_ISR146();
void  X64_ISR147();
void  X64_ISR148();
void  X64_ISR149();
void  X64_ISR150();
void  X64_ISR151();
void  X64_ISR152();
void  X64_ISR153();
void  X64_ISR154();
void  X64_ISR155();
void  X64_ISR156();
void  X64_ISR157();
void  X64_ISR158();
void  X64_ISR159();
void  X64_ISR160();
void  X64_ISR161();
void  X64_ISR162();
void  X64_ISR163();
void  X64_ISR164();
void  X64_ISR165();
void  X64_ISR166();
void  X64_ISR167();
void  X64_ISR168();
void  X64_ISR169();
void  X64_ISR170();
void  X64_ISR171();
void  X64_ISR172();
void  X64_ISR173();
void  X64_ISR174();
void  X64_ISR175();
void  X64_ISR176();
void  X64_ISR177();
void  X64_ISR178();
void  X64_ISR179();
void  X64_ISR180();
void  X64_ISR181();
void  X64_ISR182();
void  X64_ISR183();
void  X64_ISR184();
void  X64_ISR185();
void  X64_ISR186();
void  X64_ISR187();
void  X64_ISR188();
void  X64_ISR189();
void  X64_ISR190();
void  X64_ISR191();
void  X64_ISR192();
void  X64_ISR193();
void  X64_ISR194();
void  X64_ISR195();
void  X64_ISR196();
void  X64_ISR197();
void  X64_ISR198();
void  X64_ISR199();
void  X64_ISR200();
void  X64_ISR201();
void  X64_ISR202();
void  X64_ISR203();
void  X64_ISR204();
void  X64_ISR205();
void  X64_ISR206();
void  X64_ISR207();
void  X64_ISR208();
void  X64_ISR209();
void  X64_ISR210();
void  X64_ISR211();
void  X64_ISR212();
void  X64_ISR213();
void  X64_ISR214();
void  X64_ISR215();
void  X64_ISR216();
void  X64_ISR217();
void  X64_ISR218();
void  X64_ISR219();
void  X64_ISR220();
void  X64_ISR221();
void  X64_ISR222();
void  X64_ISR223();
void  X64_ISR224();
void  X64_ISR225();
void  X64_ISR226();
void  X64_ISR227();
void  X64_ISR228();
void  X64_ISR229();
void  X64_ISR230();
void  X64_ISR231();
void  X64_ISR232();
void  X64_ISR233();
void  X64_ISR234();
void  X64_ISR235();
void  X64_ISR236();
void  X64_ISR237();
void  X64_ISR238();
void  X64_ISR239();
void  X64_ISR240();
void  X64_ISR241();
void  X64_ISR242();
void  X64_ISR243();
void  X64_ISR244();
void  X64_ISR245();
void  X64_ISR246();
void  X64_ISR247();
void  X64_ISR248();
void  X64_ISR249();
void  X64_ISR250();
void  X64_ISR251();
void  X64_ISR252();
void  X64_ISR253();
void  X64_ISR254();
void  X64_ISR255();

#include "kstdio.h"
void IsrInstallGates() {
    printf("aa\n");
    IDT_SetGate(0, X64_ISR0,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(1, X64_ISR1,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(2, X64_ISR2,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(3, X64_ISR3,  IDT_FLAG_RING0);
    IDT_SetGate(4, X64_ISR4,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(5, X64_ISR5,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(6, X64_ISR6,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(7, X64_ISR7,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(8, X64_ISR8,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(9, X64_ISR9,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(10, X64_ISR10,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(11, X64_ISR11,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(12, X64_ISR12,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(13, X64_ISR13,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(14, X64_ISR14,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(15, X64_ISR15,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(16, X64_ISR16,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(17, X64_ISR17,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(18, X64_ISR18,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(19, X64_ISR19,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(20, X64_ISR20,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(21, X64_ISR21,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(22, X64_ISR22,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(23, X64_ISR23,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(24, X64_ISR24,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(25, X64_ISR25,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(26, X64_ISR26,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(27, X64_ISR27,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(28, X64_ISR28,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(29, X64_ISR29,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(30, X64_ISR30,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(31, X64_ISR31,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);

    for (int i =0; i < 16; i++) {
        IDT_SetGate(i+32, irqHandlers[i], 0x8E);
    }
  /* 
    IDT_SetGate(32, X64_ISR32,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(33, X64_ISR33,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(34, X64_ISR34,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(35, X64_ISR35,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(36, X64_ISR36,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(37, X64_ISR37,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(38, X64_ISR38,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(39, X64_ISR39,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(40, X64_ISR40,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(41, X64_ISR41,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(42, X64_ISR42,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(43, X64_ISR43,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(44, X64_ISR44,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(45, X64_ISR45,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(46, X64_ISR46,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(47, X64_ISR47,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
  */
  
    IDT_SetGate(48, X64_ISR48,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(49, X64_ISR49,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(50, X64_ISR50,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(51, X64_ISR51,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(52, X64_ISR52,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(53, X64_ISR53,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(54, X64_ISR54,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(55, X64_ISR55,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(56, X64_ISR56,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(57, X64_ISR57,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(58, X64_ISR58,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(59, X64_ISR59,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(60, X64_ISR60,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(61, X64_ISR61,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(62, X64_ISR62,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(63, X64_ISR63,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(64, X64_ISR64,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(65, X64_ISR65,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(66, X64_ISR66,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(67, X64_ISR67,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(68, X64_ISR68,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(69, X64_ISR69,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(70, X64_ISR70,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(71, X64_ISR71,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(72, X64_ISR72,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(73, X64_ISR73,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(74, X64_ISR74,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(75, X64_ISR75,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(76, X64_ISR76,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(77, X64_ISR77,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(78, X64_ISR78,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(79, X64_ISR79,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(80, X64_ISR80,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(81, X64_ISR81,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(82, X64_ISR82,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(83, X64_ISR83,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(84, X64_ISR84,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(85, X64_ISR85,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(86, X64_ISR86,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(87, X64_ISR87,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(88, X64_ISR88,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(89, X64_ISR89,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(90, X64_ISR90,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(91, X64_ISR91,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(92, X64_ISR92,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(93, X64_ISR93,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(94, X64_ISR94,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(95, X64_ISR95,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(96, X64_ISR96,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(97, X64_ISR97,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(98, X64_ISR98,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(99, X64_ISR99,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(100, X64_ISR100,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(101, X64_ISR101,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(102, X64_ISR102,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(103, X64_ISR103,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(104, X64_ISR104,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(105, X64_ISR105,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(106, X64_ISR106,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(107, X64_ISR107,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(108, X64_ISR108,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(109, X64_ISR109,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(110, X64_ISR110,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(111, X64_ISR111,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(112, X64_ISR112,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(113, X64_ISR113,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(114, X64_ISR114,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(115, X64_ISR115,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(116, X64_ISR116,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(117, X64_ISR117,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(118, X64_ISR118,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(119, X64_ISR119,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(120, X64_ISR120,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(121, X64_ISR121,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(122, X64_ISR122,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(123, X64_ISR123,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(124, X64_ISR124,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(125, X64_ISR125,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(126, X64_ISR126,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(127, X64_ISR127,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);


    //syscall 0x80
    IDT_SetGate(128, X64_ISR128,  IDT_FLAG_RING0| IDT_FLAG_RING3 | IDT_FLAG_GATE_64BIT_INT);
    
    
    
    
    IDT_SetGate(129, X64_ISR129,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(130, X64_ISR130,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(131, X64_ISR131,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(132, X64_ISR132,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(133, X64_ISR133,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(134, X64_ISR134,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(135, X64_ISR135,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(136, X64_ISR136,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(137, X64_ISR137,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(138, X64_ISR138,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(139, X64_ISR139,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(140, X64_ISR140,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(141, X64_ISR141,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(142, X64_ISR142,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(143, X64_ISR143,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(144, X64_ISR144,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(145, X64_ISR145,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(146, X64_ISR146,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(147, X64_ISR147,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(148, X64_ISR148,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(149, X64_ISR149,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(150, X64_ISR150,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(151, X64_ISR151,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(152, X64_ISR152,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(153, X64_ISR153,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(154, X64_ISR154,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(155, X64_ISR155,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(156, X64_ISR156,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(157, X64_ISR157,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(158, X64_ISR158,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(159, X64_ISR159,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(160, X64_ISR160,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(161, X64_ISR161,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(162, X64_ISR162,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(163, X64_ISR163,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(164, X64_ISR164,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(165, X64_ISR165,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(166, X64_ISR166,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(167, X64_ISR167,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(168, X64_ISR168,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(170, X64_ISR170,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(171, X64_ISR171,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(172, X64_ISR172,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(173, X64_ISR173,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(174, X64_ISR174,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(175, X64_ISR175,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(176, X64_ISR176,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(177, X64_ISR177,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(178, X64_ISR178,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(179, X64_ISR179,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(180, X64_ISR180,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(181, X64_ISR181,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(182, X64_ISR182,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(183, X64_ISR183,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(184, X64_ISR184,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(185, X64_ISR185,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(186, X64_ISR186,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(187, X64_ISR187,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(188, X64_ISR188,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(189, X64_ISR189,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(190, X64_ISR190,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(191, X64_ISR191,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(192, X64_ISR192,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(193, X64_ISR193,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(194, X64_ISR194,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(195, X64_ISR195,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(196, X64_ISR196,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(197, X64_ISR197,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(198, X64_ISR198,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(199, X64_ISR199,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(200, X64_ISR200,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(201, X64_ISR201,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(202, X64_ISR202,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(203, X64_ISR203,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(204, X64_ISR204,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(205, X64_ISR205,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(206, X64_ISR206,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(207, X64_ISR207,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(208, X64_ISR208,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(209, X64_ISR209,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(210, X64_ISR210,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(211, X64_ISR211,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(212, X64_ISR212,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(213, X64_ISR213,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(214, X64_ISR214,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(215, X64_ISR215,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(216, X64_ISR216,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(217, X64_ISR217,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(218, X64_ISR218,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(219, X64_ISR219,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(220, X64_ISR220,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(221, X64_ISR221,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(222, X64_ISR222,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(223, X64_ISR223,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(224, X64_ISR224,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(225, X64_ISR225,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(226, X64_ISR226,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(227, X64_ISR227,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(228, X64_ISR228,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(229, X64_ISR229,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(230, X64_ISR230,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(231, X64_ISR231,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(232, X64_ISR232,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(233, X64_ISR233,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(234, X64_ISR234,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(235, X64_ISR235,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(236, X64_ISR236,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(237, X64_ISR237,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(238, X64_ISR238,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(239, X64_ISR239,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(240, X64_ISR240,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(241, X64_ISR241,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(242, X64_ISR242,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(243, X64_ISR243,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(244, X64_ISR244,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(245, X64_ISR245,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(246, X64_ISR246,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(247, X64_ISR247,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(248, X64_ISR248,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(249, X64_ISR249,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(250, X64_ISR250,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(251, X64_ISR251,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(252, X64_ISR252,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(253, X64_ISR253,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(254, X64_ISR254,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);
    IDT_SetGate(255, X64_ISR255,  IDT_FLAG_RING0 | IDT_FLAG_GATE_64BIT_INT);

   

   // __asm__ volatile("sti");




}
void ISR_Init() {
    IsrInstallGates();
    for (int i = 0; i < 256; i++) {
        IDT_EnableGate(i);
    }
    IDT_DisableGate(0x80);
    
}

ISR_HANDLER g_ISRHandlers[256];
#include "../arch/x86_64/include/panic.h"
#include "kstdio.h"
uint64_t ISR_Handler(uint64_t rsp) {
    isr_state_t* regs = (isr_state_t*)rsp;
   
   
    //PrintRegs(regs);
    printf("dd\n");
    


    if (g_ISRHandlers[regs->isr_number] != NULL) {
         g_ISRHandlers[regs->isr_number](regs);
    }
    else if (regs->isr_number >= 32) {
        printf("Unhandled interrupt %llu!\n", regs->isr_number);
        
    }
    else {
    ISR_SystemRaiseHardError("CPU exception has occured", regs);

   printf("INT[%lu] %s\n", regs->isr_number, exception_messages[regs->isr_number]);
   // PrintRegs(regs);
    }

    return rsp;
}
void ISR_RegisterHandler(int interrupt, ISR_HANDLER handler) {
    g_ISRHandlers[interrupt] = handler;
    IDT_EnableGate(interrupt);
}


isr_state_t Regs2ISRState(registers_t* regs) {
    if (regs == NULL) {
        isr_state_t t = {0};
        return t;
    }
    isr_state_t state;
    memset(&state, 0, sizeof(state));
    state.gp.rax = regs->rax;
    state.gp.rbx = regs->rbx;
    state.gp.rcx = regs->rcx;
    state.gp.rdx = regs->rdx;
    state.gp.rsi = regs->rsi;
    state.gp.rdi = regs->rdi;
    state.gp.r8 = regs->r8;
    state.gp.r9 = regs->r9;
    state.gp.r10 = regs->r10;
    state.gp.r11 = regs->r11;
    state.gp.r12 = regs->r12;
    state.gp.r13 = regs->r13;
    state.gp.r14 = regs->r14;
    state.gp.r15 = regs->r15;
    
    return state;
}


