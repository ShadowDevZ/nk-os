#include "include/isr.h"
#include "include/idt.h"
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
#include "include/idt.h"

void __attribute((cdecl)) X64_ISR0();
void __attribute((cdecl)) X64_ISR1();
void __attribute((cdecl)) X64_ISR2();
void __attribute((cdecl)) X64_ISR3();
void __attribute((cdecl)) X64_ISR4();
void __attribute((cdecl)) X64_ISR5();
void __attribute((cdecl)) X64_ISR6();
void __attribute((cdecl)) X64_ISR7();
void __attribute((cdecl)) X64_ISR8();
void __attribute((cdecl)) X64_ISR9();
void __attribute((cdecl)) X64_ISR10();
void __attribute((cdecl)) X64_ISR11();
void __attribute((cdecl)) X64_ISR12();
void __attribute((cdecl)) X64_ISR13();
void __attribute((cdecl)) X64_ISR14();
void __attribute((cdecl)) X64_ISR15();
void __attribute((cdecl)) X64_ISR16();
void __attribute((cdecl)) X64_ISR17();
void __attribute((cdecl)) X64_ISR18();
void __attribute((cdecl)) X64_ISR19();
void __attribute((cdecl)) X64_ISR20();
void __attribute((cdecl)) X64_ISR21();
void __attribute((cdecl)) X64_ISR22();
void __attribute((cdecl)) X64_ISR23();
void __attribute((cdecl)) X64_ISR24();
void __attribute((cdecl)) X64_ISR25();
void __attribute((cdecl)) X64_ISR26();
void __attribute((cdecl)) X64_ISR27();
void __attribute((cdecl)) X64_ISR28();
void __attribute((cdecl)) X64_ISR29();
void __attribute((cdecl)) X64_ISR30();
void __attribute((cdecl)) X64_ISR31();
void __attribute((cdecl)) X64_ISR32();
void __attribute((cdecl)) X64_ISR33();
void __attribute((cdecl)) X64_ISR34();
void __attribute((cdecl)) X64_ISR35();
void __attribute((cdecl)) X64_ISR36();
void __attribute((cdecl)) X64_ISR37();
void __attribute((cdecl)) X64_ISR38();
void __attribute((cdecl)) X64_ISR39();
void __attribute((cdecl)) X64_ISR40();
void __attribute((cdecl)) X64_ISR41();
void __attribute((cdecl)) X64_ISR42();
void __attribute((cdecl)) X64_ISR43();
void __attribute((cdecl)) X64_ISR44();
void __attribute((cdecl)) X64_ISR45();
void __attribute((cdecl)) X64_ISR46();
void __attribute((cdecl)) X64_ISR47();
void __attribute((cdecl)) X64_ISR48();
void __attribute((cdecl)) X64_ISR49();
void __attribute((cdecl)) X64_ISR50();
void __attribute((cdecl)) X64_ISR51();
void __attribute((cdecl)) X64_ISR52();
void __attribute((cdecl)) X64_ISR53();
void __attribute((cdecl)) X64_ISR54();
void __attribute((cdecl)) X64_ISR55();
void __attribute((cdecl)) X64_ISR56();
void __attribute((cdecl)) X64_ISR57();
void __attribute((cdecl)) X64_ISR58();
void __attribute((cdecl)) X64_ISR59();
void __attribute((cdecl)) X64_ISR60();
void __attribute((cdecl)) X64_ISR61();
void __attribute((cdecl)) X64_ISR62();
void __attribute((cdecl)) X64_ISR63();
void __attribute((cdecl)) X64_ISR64();
void __attribute((cdecl)) X64_ISR65();
void __attribute((cdecl)) X64_ISR66();
void __attribute((cdecl)) X64_ISR67();
void __attribute((cdecl)) X64_ISR68();
void __attribute((cdecl)) X64_ISR69();
void __attribute((cdecl)) X64_ISR70();
void __attribute((cdecl)) X64_ISR71();
void __attribute((cdecl)) X64_ISR72();
void __attribute((cdecl)) X64_ISR73();
void __attribute((cdecl)) X64_ISR74();
void __attribute((cdecl)) X64_ISR75();
void __attribute((cdecl)) X64_ISR76();
void __attribute((cdecl)) X64_ISR77();
void __attribute((cdecl)) X64_ISR78();
void __attribute((cdecl)) X64_ISR79();
void __attribute((cdecl)) X64_ISR80();
void __attribute((cdecl)) X64_ISR81();
void __attribute((cdecl)) X64_ISR82();
void __attribute((cdecl)) X64_ISR83();
void __attribute((cdecl)) X64_ISR84();
void __attribute((cdecl)) X64_ISR85();
void __attribute((cdecl)) X64_ISR86();
void __attribute((cdecl)) X64_ISR87();
void __attribute((cdecl)) X64_ISR88();
void __attribute((cdecl)) X64_ISR89();
void __attribute((cdecl)) X64_ISR90();
void __attribute((cdecl)) X64_ISR91();
void __attribute((cdecl)) X64_ISR92();
void __attribute((cdecl)) X64_ISR93();
void __attribute((cdecl)) X64_ISR94();
void __attribute((cdecl)) X64_ISR95();
void __attribute((cdecl)) X64_ISR96();
void __attribute((cdecl)) X64_ISR97();
void __attribute((cdecl)) X64_ISR98();
void __attribute((cdecl)) X64_ISR99();
void __attribute((cdecl)) X64_ISR100();
void __attribute((cdecl)) X64_ISR101();
void __attribute((cdecl)) X64_ISR102();
void __attribute((cdecl)) X64_ISR103();
void __attribute((cdecl)) X64_ISR104();
void __attribute((cdecl)) X64_ISR105();
void __attribute((cdecl)) X64_ISR106();
void __attribute((cdecl)) X64_ISR107();
void __attribute((cdecl)) X64_ISR108();
void __attribute((cdecl)) X64_ISR109();
void __attribute((cdecl)) X64_ISR110();
void __attribute((cdecl)) X64_ISR111();
void __attribute((cdecl)) X64_ISR112();
void __attribute((cdecl)) X64_ISR113();
void __attribute((cdecl)) X64_ISR114();
void __attribute((cdecl)) X64_ISR115();
void __attribute((cdecl)) X64_ISR116();
void __attribute((cdecl)) X64_ISR117();
void __attribute((cdecl)) X64_ISR118();
void __attribute((cdecl)) X64_ISR119();
void __attribute((cdecl)) X64_ISR120();
void __attribute((cdecl)) X64_ISR121();
void __attribute((cdecl)) X64_ISR122();
void __attribute((cdecl)) X64_ISR123();
void __attribute((cdecl)) X64_ISR124();
void __attribute((cdecl)) X64_ISR125();
void __attribute((cdecl)) X64_ISR126();
void __attribute((cdecl)) X64_ISR127();
void __attribute((cdecl)) X64_ISR128();
void __attribute((cdecl)) X64_ISR129();
void __attribute((cdecl)) X64_ISR130();
void __attribute((cdecl)) X64_ISR131();
void __attribute((cdecl)) X64_ISR132();
void __attribute((cdecl)) X64_ISR133();
void __attribute((cdecl)) X64_ISR134();
void __attribute((cdecl)) X64_ISR135();
void __attribute((cdecl)) X64_ISR136();
void __attribute((cdecl)) X64_ISR137();
void __attribute((cdecl)) X64_ISR138();
void __attribute((cdecl)) X64_ISR139();
void __attribute((cdecl)) X64_ISR140();
void __attribute((cdecl)) X64_ISR141();
void __attribute((cdecl)) X64_ISR142();
void __attribute((cdecl)) X64_ISR143();
void __attribute((cdecl)) X64_ISR144();
void __attribute((cdecl)) X64_ISR145();
void __attribute((cdecl)) X64_ISR146();
void __attribute((cdecl)) X64_ISR147();
void __attribute((cdecl)) X64_ISR148();
void __attribute((cdecl)) X64_ISR149();
void __attribute((cdecl)) X64_ISR150();
void __attribute((cdecl)) X64_ISR151();
void __attribute((cdecl)) X64_ISR152();
void __attribute((cdecl)) X64_ISR153();
void __attribute((cdecl)) X64_ISR154();
void __attribute((cdecl)) X64_ISR155();
void __attribute((cdecl)) X64_ISR156();
void __attribute((cdecl)) X64_ISR157();
void __attribute((cdecl)) X64_ISR158();
void __attribute((cdecl)) X64_ISR159();
void __attribute((cdecl)) X64_ISR160();
void __attribute((cdecl)) X64_ISR161();
void __attribute((cdecl)) X64_ISR162();
void __attribute((cdecl)) X64_ISR163();
void __attribute((cdecl)) X64_ISR164();
void __attribute((cdecl)) X64_ISR165();
void __attribute((cdecl)) X64_ISR166();
void __attribute((cdecl)) X64_ISR167();
void __attribute((cdecl)) X64_ISR168();
void __attribute((cdecl)) X64_ISR169();
void __attribute((cdecl)) X64_ISR170();
void __attribute((cdecl)) X64_ISR171();
void __attribute((cdecl)) X64_ISR172();
void __attribute((cdecl)) X64_ISR173();
void __attribute((cdecl)) X64_ISR174();
void __attribute((cdecl)) X64_ISR175();
void __attribute((cdecl)) X64_ISR176();
void __attribute((cdecl)) X64_ISR177();
void __attribute((cdecl)) X64_ISR178();
void __attribute((cdecl)) X64_ISR179();
void __attribute((cdecl)) X64_ISR180();
void __attribute((cdecl)) X64_ISR181();
void __attribute((cdecl)) X64_ISR182();
void __attribute((cdecl)) X64_ISR183();
void __attribute((cdecl)) X64_ISR184();
void __attribute((cdecl)) X64_ISR185();
void __attribute((cdecl)) X64_ISR186();
void __attribute((cdecl)) X64_ISR187();
void __attribute((cdecl)) X64_ISR188();
void __attribute((cdecl)) X64_ISR189();
void __attribute((cdecl)) X64_ISR190();
void __attribute((cdecl)) X64_ISR191();
void __attribute((cdecl)) X64_ISR192();
void __attribute((cdecl)) X64_ISR193();
void __attribute((cdecl)) X64_ISR194();
void __attribute((cdecl)) X64_ISR195();
void __attribute((cdecl)) X64_ISR196();
void __attribute((cdecl)) X64_ISR197();
void __attribute((cdecl)) X64_ISR198();
void __attribute((cdecl)) X64_ISR199();
void __attribute((cdecl)) X64_ISR200();
void __attribute((cdecl)) X64_ISR201();
void __attribute((cdecl)) X64_ISR202();
void __attribute((cdecl)) X64_ISR203();
void __attribute((cdecl)) X64_ISR204();
void __attribute((cdecl)) X64_ISR205();
void __attribute((cdecl)) X64_ISR206();
void __attribute((cdecl)) X64_ISR207();
void __attribute((cdecl)) X64_ISR208();
void __attribute((cdecl)) X64_ISR209();
void __attribute((cdecl)) X64_ISR210();
void __attribute((cdecl)) X64_ISR211();
void __attribute((cdecl)) X64_ISR212();
void __attribute((cdecl)) X64_ISR213();
void __attribute((cdecl)) X64_ISR214();
void __attribute((cdecl)) X64_ISR215();
void __attribute((cdecl)) X64_ISR216();
void __attribute((cdecl)) X64_ISR217();
void __attribute((cdecl)) X64_ISR218();
void __attribute((cdecl)) X64_ISR219();
void __attribute((cdecl)) X64_ISR220();
void __attribute((cdecl)) X64_ISR221();
void __attribute((cdecl)) X64_ISR222();
void __attribute((cdecl)) X64_ISR223();
void __attribute((cdecl)) X64_ISR224();
void __attribute((cdecl)) X64_ISR225();
void __attribute((cdecl)) X64_ISR226();
void __attribute((cdecl)) X64_ISR227();
void __attribute((cdecl)) X64_ISR228();
void __attribute((cdecl)) X64_ISR229();
void __attribute((cdecl)) X64_ISR230();
void __attribute((cdecl)) X64_ISR231();
void __attribute((cdecl)) X64_ISR232();
void __attribute((cdecl)) X64_ISR233();
void __attribute((cdecl)) X64_ISR234();
void __attribute((cdecl)) X64_ISR235();
void __attribute((cdecl)) X64_ISR236();
void __attribute((cdecl)) X64_ISR237();
void __attribute((cdecl)) X64_ISR238();
void __attribute((cdecl)) X64_ISR239();
void __attribute((cdecl)) X64_ISR240();
void __attribute((cdecl)) X64_ISR241();
void __attribute((cdecl)) X64_ISR242();
void __attribute((cdecl)) X64_ISR243();
void __attribute((cdecl)) X64_ISR244();
void __attribute((cdecl)) X64_ISR245();
void __attribute((cdecl)) X64_ISR246();
void __attribute((cdecl)) X64_ISR247();
void __attribute((cdecl)) X64_ISR248();
void __attribute((cdecl)) X64_ISR249();
void __attribute((cdecl)) X64_ISR250();
void __attribute((cdecl)) X64_ISR251();
void __attribute((cdecl)) X64_ISR252();
void __attribute((cdecl)) X64_ISR253();
void __attribute((cdecl)) X64_ISR254();
void __attribute((cdecl)) X64_ISR255();

#include "kstdio.h"
void IsrInstallGates() {
    printf("aa\n");
    IDT_SetGate(0, X64_ISR0,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(1, X64_ISR1,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(2, X64_ISR2,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(3, X64_ISR3,  IDT_FLAG_RING0);
    IDT_SetGate(4, X64_ISR4,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(5, X64_ISR5,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(6, X64_ISR6,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(7, X64_ISR7,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(8, X64_ISR8,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(9, X64_ISR9,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(10, X64_ISR10,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(11, X64_ISR11,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(12, X64_ISR12,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(13, X64_ISR13,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(14, X64_ISR14,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(15, X64_ISR15,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(16, X64_ISR16,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(17, X64_ISR17,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(18, X64_ISR18,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(19, X64_ISR19,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(20, X64_ISR20,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(21, X64_ISR21,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(22, X64_ISR22,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(23, X64_ISR23,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(24, X64_ISR24,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(25, X64_ISR25,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(26, X64_ISR26,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(27, X64_ISR27,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(28, X64_ISR28,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(29, X64_ISR29,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(30, X64_ISR30,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(31, X64_ISR31,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(32, X64_ISR32,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(33, X64_ISR33,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(34, X64_ISR34,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(35, X64_ISR35,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(36, X64_ISR36,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(37, X64_ISR37,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(38, X64_ISR38,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(39, X64_ISR39,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(40, X64_ISR40,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(41, X64_ISR41,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(42, X64_ISR42,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(43, X64_ISR43,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(44, X64_ISR44,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(45, X64_ISR45,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(46, X64_ISR46,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(47, X64_ISR47,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(48, X64_ISR48,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(49, X64_ISR49,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(50, X64_ISR50,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(51, X64_ISR51,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(52, X64_ISR52,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(53, X64_ISR53,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(54, X64_ISR54,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(55, X64_ISR55,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(56, X64_ISR56,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(57, X64_ISR57,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(58, X64_ISR58,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(59, X64_ISR59,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(60, X64_ISR60,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(61, X64_ISR61,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(62, X64_ISR62,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(63, X64_ISR63,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(64, X64_ISR64,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(65, X64_ISR65,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(66, X64_ISR66,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(67, X64_ISR67,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(68, X64_ISR68,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(69, X64_ISR69,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(70, X64_ISR70,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(71, X64_ISR71,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(72, X64_ISR72,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(73, X64_ISR73,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(74, X64_ISR74,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(75, X64_ISR75,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(76, X64_ISR76,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(77, X64_ISR77,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(78, X64_ISR78,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(79, X64_ISR79,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(80, X64_ISR80,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(81, X64_ISR81,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(82, X64_ISR82,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(83, X64_ISR83,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(84, X64_ISR84,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(85, X64_ISR85,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(86, X64_ISR86,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(87, X64_ISR87,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(88, X64_ISR88,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(89, X64_ISR89,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(90, X64_ISR90,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(91, X64_ISR91,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(92, X64_ISR92,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(93, X64_ISR93,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(94, X64_ISR94,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(95, X64_ISR95,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(96, X64_ISR96,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(97, X64_ISR97,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(98, X64_ISR98,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(99, X64_ISR99,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(100, X64_ISR100,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(101, X64_ISR101,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(102, X64_ISR102,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(103, X64_ISR103,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(104, X64_ISR104,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(105, X64_ISR105,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(106, X64_ISR106,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(107, X64_ISR107,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(108, X64_ISR108,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(109, X64_ISR109,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(110, X64_ISR110,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(111, X64_ISR111,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(112, X64_ISR112,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(113, X64_ISR113,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(114, X64_ISR114,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(115, X64_ISR115,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(116, X64_ISR116,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(117, X64_ISR117,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(118, X64_ISR118,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(119, X64_ISR119,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(120, X64_ISR120,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(121, X64_ISR121,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(122, X64_ISR122,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(123, X64_ISR123,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(124, X64_ISR124,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(125, X64_ISR125,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(126, X64_ISR126,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(127, X64_ISR127,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);


    //syscall 0x80
    IDT_SetGate(128, X64_ISR128,  IDT_FLAG_RING0| IDT_FLAG_RING3 | IDT_FLAG_GATE_32BIT_INT);
    
    
    
    
    IDT_SetGate(129, X64_ISR129,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(130, X64_ISR130,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(131, X64_ISR131,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(132, X64_ISR132,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(133, X64_ISR133,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(134, X64_ISR134,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(135, X64_ISR135,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(136, X64_ISR136,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(137, X64_ISR137,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(138, X64_ISR138,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(139, X64_ISR139,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(140, X64_ISR140,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(141, X64_ISR141,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(142, X64_ISR142,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(143, X64_ISR143,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(144, X64_ISR144,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(145, X64_ISR145,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(146, X64_ISR146,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(147, X64_ISR147,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(148, X64_ISR148,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(149, X64_ISR149,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(150, X64_ISR150,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(151, X64_ISR151,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(152, X64_ISR152,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(153, X64_ISR153,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(154, X64_ISR154,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(155, X64_ISR155,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(156, X64_ISR156,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(157, X64_ISR157,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(158, X64_ISR158,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(159, X64_ISR159,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(160, X64_ISR160,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(161, X64_ISR161,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(162, X64_ISR162,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(163, X64_ISR163,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(164, X64_ISR164,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(165, X64_ISR165,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(166, X64_ISR166,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(167, X64_ISR167,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(168, X64_ISR168,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(169, X64_ISR169,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(170, X64_ISR170,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(171, X64_ISR171,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(172, X64_ISR172,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(173, X64_ISR173,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(174, X64_ISR174,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(175, X64_ISR175,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(176, X64_ISR176,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(177, X64_ISR177,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(178, X64_ISR178,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(179, X64_ISR179,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(180, X64_ISR180,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(181, X64_ISR181,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(182, X64_ISR182,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(183, X64_ISR183,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(184, X64_ISR184,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(185, X64_ISR185,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(186, X64_ISR186,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(187, X64_ISR187,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(188, X64_ISR188,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(189, X64_ISR189,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(190, X64_ISR190,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(191, X64_ISR191,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(192, X64_ISR192,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(193, X64_ISR193,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(194, X64_ISR194,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(195, X64_ISR195,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(196, X64_ISR196,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(197, X64_ISR197,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(198, X64_ISR198,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(199, X64_ISR199,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(200, X64_ISR200,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(201, X64_ISR201,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(202, X64_ISR202,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(203, X64_ISR203,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(204, X64_ISR204,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(205, X64_ISR205,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(206, X64_ISR206,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(207, X64_ISR207,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(208, X64_ISR208,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(209, X64_ISR209,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(210, X64_ISR210,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(211, X64_ISR211,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(212, X64_ISR212,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(213, X64_ISR213,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(214, X64_ISR214,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(215, X64_ISR215,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(216, X64_ISR216,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(217, X64_ISR217,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(218, X64_ISR218,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(219, X64_ISR219,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(220, X64_ISR220,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(221, X64_ISR221,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(222, X64_ISR222,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(223, X64_ISR223,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(224, X64_ISR224,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(225, X64_ISR225,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(226, X64_ISR226,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(227, X64_ISR227,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(228, X64_ISR228,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(229, X64_ISR229,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(230, X64_ISR230,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(231, X64_ISR231,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(232, X64_ISR232,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(233, X64_ISR233,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(234, X64_ISR234,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(235, X64_ISR235,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(236, X64_ISR236,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(237, X64_ISR237,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(238, X64_ISR238,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(239, X64_ISR239,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(240, X64_ISR240,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(241, X64_ISR241,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(242, X64_ISR242,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(243, X64_ISR243,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(244, X64_ISR244,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(245, X64_ISR245,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(246, X64_ISR246,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(247, X64_ISR247,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(248, X64_ISR248,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(249, X64_ISR249,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(250, X64_ISR250,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(251, X64_ISR251,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(252, X64_ISR252,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(253, X64_ISR253,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(254, X64_ISR254,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    IDT_SetGate(255, X64_ISR255,  IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);

    void Initialize_IDT();

    __asm__ volatile("sti");




}
#include "kstdio.h"
void ISR_Handler(registers_t regs) {
    printf("ISR handler boysss\n");
    printf("INT[%d]%s\n", regs.int_no, exception_messages[regs.int_no]);
}