//This file has been generated by symgen.py
#include "kstdio.h"
#include "ksyms.h"
#include <stddef.h>


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"
const KsymList symbols[] = {
{ 0xFFFFFFFF80000000,"GetBasicKernelVersion"},
{ 0xFFFFFFFF800000B0,"GetKernelVersion"},
{ 0xFFFFFFFF800001C0,"KsymCount"},
{ 0xFFFFFFFF80000200,"KsymDebugDump"},
{ 0xFFFFFFFF80000260,"KsymFind"},
{ 0xFFFFFFFF800002E0,"KsymResolveAddress"},
{ 0xFFFFFFFF80000340,"KsymEnumSymbol"},
{ 0xFFFFFFFF800003B0,"KsymGetSymbolIndex"},
{ 0xFFFFFFFF80000400,"ulli2a"},
{ 0xFFFFFFFF800004E0,"uli2a"},
{ 0xFFFFFFFF800005C0,"ui2a"},
{ 0xFFFFFFFF80000690,"putchw"},
{ 0xFFFFFFFF80000850,"_vsnprintf_putcf"},
{ 0xFFFFFFFF80000870,"_vsprintf_putcf"},
{ 0xFFFFFFFF80000890,"tfp_format"},
{ 0xFFFFFFFF80000D60,"init_printf"},
{ 0xFFFFFFFF80000D70,"tfp_printf"},
{ 0xFFFFFFFF80000DC0,"tfp_vsnprintf"},
{ 0xFFFFFFFF80000E30,"tfp_snprintf"},
{ 0xFFFFFFFF80000EC0,"tfp_vsprintf"},
{ 0xFFFFFFFF80000F00,"tfp_sprintf"},
{ 0xFFFFFFFF80000F70,"strcmp"},
{ 0xFFFFFFFF80000FA0,"strncmp"},
{ 0xFFFFFFFF80000FE0,"strncpy"},
{ 0xFFFFFFFF80001030,"memcpy"},
{ 0xFFFFFFFF80001060,"memset"},
{ 0xFFFFFFFF80001080,"memmove"},
{ 0xFFFFFFFF800010D0,"memcmp"},
{ 0xFFFFFFFF80001110,"strlen"},
{ 0xFFFFFFFF80001140,"strncat"},
{ 0xFFFFFFFF800011A0,"itoa"},
{ 0xFFFFFFFF80001230,"debugf"},
{ 0xFFFFFFFF800012D0,"debugs"},
{ 0xFFFFFFFF80001310,"putchar"},
{ 0xFFFFFFFF80001350,"toupper"},
{ 0xFFFFFFFF80001360,"_start"},
{ 0xFFFFFFFF80001590,"kmain"},
{ 0xFFFFFFFF80001600,"PrintRegs"},
{ 0xFFFFFFFF800016A0,"_SystemRaiseHardError"},
{ 0xFFFFFFFF80001810,"Initialize_IDT"},
{ 0xFFFFFFFF80001850,"IDT_SetGate"},
{ 0xFFFFFFFF800018A0,"IDT_EnableGate"},
{ 0xFFFFFFFF800018B0,"IDT_DisableGate"},
{ 0xFFFFFFFF800018C0,"GetIsrExceptionList"},
{ 0xFFFFFFFF800018D0,"IsrInstallGates"},
{ 0xFFFFFFFF80002EE0,"ISR_Init"},
{ 0xFFFFFFFF80002F20,"ISR_Handler"},
{ 0xFFFFFFFF80002F40,"ISR_RegisterHandler"},
{ 0xFFFFFFFF80002F50,"SetGDTEntry"},
{ 0xFFFFFFFF80002FB0,"gdt_init"},
{ 0xFFFFFFFF80003070,"_FbPutChar"},
{ 0xFFFFFFFF800030F0,"Fb_GetStreamType"},
{ 0xFFFFFFFF80003100,"Fb_SwitchStream"},
{ 0xFFFFFFFF80003120,"_FbPutString"},
{ 0xFFFFFFFF80003160,"InitializeFramebuffers"},
{ 0xFFFFFFFF800032C0,"isr_common"},
{ 0xFFFFFFFF80003300,"X64_ISR0"},
{ 0xFFFFFFFF80003306,"X64_ISR1"},
{ 0xFFFFFFFF8000330C,"X64_ISR2"},
{ 0xFFFFFFFF80003312,"X64_ISR3"},
{ 0xFFFFFFFF80003318,"X64_ISR4"},
{ 0xFFFFFFFF8000331E,"X64_ISR5"},
{ 0xFFFFFFFF80003324,"X64_ISR6"},
{ 0xFFFFFFFF8000332A,"X64_ISR7"},
{ 0xFFFFFFFF80003330,"X64_ISR8"},
{ 0xFFFFFFFF80003334,"X64_ISR9"},
{ 0xFFFFFFFF8000333A,"X64_ISR10"},
{ 0xFFFFFFFF8000333E,"X64_ISR11"},
{ 0xFFFFFFFF80003345,"X64_ISR12"},
{ 0xFFFFFFFF8000334C,"X64_ISR13"},
{ 0xFFFFFFFF80003353,"X64_ISR14"},
{ 0xFFFFFFFF8000335A,"X64_ISR15"},
{ 0xFFFFFFFF80003363,"X64_ISR16"},
{ 0xFFFFFFFF8000336C,"X64_ISR17"},
{ 0xFFFFFFFF80003373,"X64_ISR18"},
{ 0xFFFFFFFF8000337C,"X64_ISR19"},
{ 0xFFFFFFFF80003385,"X64_ISR20"},
{ 0xFFFFFFFF8000338E,"X64_ISR21"},
{ 0xFFFFFFFF80003395,"X64_ISR22"},
{ 0xFFFFFFFF8000339E,"X64_ISR23"},
{ 0xFFFFFFFF800033A7,"X64_ISR24"},
{ 0xFFFFFFFF800033B0,"X64_ISR25"},
{ 0xFFFFFFFF800033B9,"X64_ISR26"},
{ 0xFFFFFFFF800033C2,"X64_ISR27"},
{ 0xFFFFFFFF800033CB,"X64_ISR28"},
{ 0xFFFFFFFF800033D4,"X64_ISR29"},
{ 0xFFFFFFFF800033DD,"X64_ISR30"},
{ 0xFFFFFFFF800033E6,"X64_ISR31"},
{ 0xFFFFFFFF800033EF,"X64_ISR32"},
{ 0xFFFFFFFF800033F8,"X64_ISR33"},
{ 0xFFFFFFFF80003401,"X64_ISR34"},
{ 0xFFFFFFFF8000340A,"X64_ISR35"},
{ 0xFFFFFFFF80003413,"X64_ISR36"},
{ 0xFFFFFFFF8000341C,"X64_ISR37"},
{ 0xFFFFFFFF80003425,"X64_ISR38"},
{ 0xFFFFFFFF8000342E,"X64_ISR39"},
{ 0xFFFFFFFF80003437,"X64_ISR40"},
{ 0xFFFFFFFF80003440,"X64_ISR41"},
{ 0xFFFFFFFF80003449,"X64_ISR42"},
{ 0xFFFFFFFF80003452,"X64_ISR43"},
{ 0xFFFFFFFF8000345B,"X64_ISR44"},
{ 0xFFFFFFFF80003464,"X64_ISR45"},
{ 0xFFFFFFFF8000346D,"X64_ISR46"},
{ 0xFFFFFFFF80003476,"X64_ISR47"},
{ 0xFFFFFFFF8000347F,"X64_ISR48"},
{ 0xFFFFFFFF80003488,"X64_ISR49"},
{ 0xFFFFFFFF80003491,"X64_ISR50"},
{ 0xFFFFFFFF8000349A,"X64_ISR51"},
{ 0xFFFFFFFF800034A3,"X64_ISR52"},
{ 0xFFFFFFFF800034AC,"X64_ISR53"},
{ 0xFFFFFFFF800034B5,"X64_ISR54"},
{ 0xFFFFFFFF800034BE,"X64_ISR55"},
{ 0xFFFFFFFF800034C7,"X64_ISR56"},
{ 0xFFFFFFFF800034D0,"X64_ISR57"},
{ 0xFFFFFFFF800034D9,"X64_ISR58"},
{ 0xFFFFFFFF800034E2,"X64_ISR59"},
{ 0xFFFFFFFF800034EB,"X64_ISR60"},
{ 0xFFFFFFFF800034F4,"X64_ISR61"},
{ 0xFFFFFFFF800034FD,"X64_ISR62"},
{ 0xFFFFFFFF80003506,"X64_ISR63"},
{ 0xFFFFFFFF8000350F,"X64_ISR64"},
{ 0xFFFFFFFF80003518,"X64_ISR65"},
{ 0xFFFFFFFF80003521,"X64_ISR66"},
{ 0xFFFFFFFF8000352A,"X64_ISR67"},
{ 0xFFFFFFFF80003533,"X64_ISR68"},
{ 0xFFFFFFFF8000353C,"X64_ISR69"},
{ 0xFFFFFFFF80003545,"X64_ISR70"},
{ 0xFFFFFFFF8000354E,"X64_ISR71"},
{ 0xFFFFFFFF80003557,"X64_ISR72"},
{ 0xFFFFFFFF80003560,"X64_ISR73"},
{ 0xFFFFFFFF80003569,"X64_ISR74"},
{ 0xFFFFFFFF80003572,"X64_ISR75"},
{ 0xFFFFFFFF8000357B,"X64_ISR76"},
{ 0xFFFFFFFF80003584,"X64_ISR77"},
{ 0xFFFFFFFF8000358D,"X64_ISR78"},
{ 0xFFFFFFFF80003596,"X64_ISR79"},
{ 0xFFFFFFFF8000359F,"X64_ISR80"},
{ 0xFFFFFFFF800035A8,"X64_ISR81"},
{ 0xFFFFFFFF800035B1,"X64_ISR82"},
{ 0xFFFFFFFF800035BA,"X64_ISR83"},
{ 0xFFFFFFFF800035C3,"X64_ISR84"},
{ 0xFFFFFFFF800035CC,"X64_ISR85"},
{ 0xFFFFFFFF800035D5,"X64_ISR86"},
{ 0xFFFFFFFF800035DE,"X64_ISR87"},
{ 0xFFFFFFFF800035E7,"X64_ISR88"},
{ 0xFFFFFFFF800035F0,"X64_ISR89"},
{ 0xFFFFFFFF800035F9,"X64_ISR90"},
{ 0xFFFFFFFF80003602,"X64_ISR91"},
{ 0xFFFFFFFF8000360B,"X64_ISR92"},
{ 0xFFFFFFFF80003614,"X64_ISR93"},
{ 0xFFFFFFFF8000361D,"X64_ISR94"},
{ 0xFFFFFFFF80003626,"X64_ISR95"},
{ 0xFFFFFFFF8000362F,"X64_ISR96"},
{ 0xFFFFFFFF80003638,"X64_ISR97"},
{ 0xFFFFFFFF80003641,"X64_ISR98"},
{ 0xFFFFFFFF8000364A,"X64_ISR99"},
{ 0xFFFFFFFF80003653,"X64_ISR100"},
{ 0xFFFFFFFF8000365C,"X64_ISR101"},
{ 0xFFFFFFFF80003665,"X64_ISR102"},
{ 0xFFFFFFFF8000366E,"X64_ISR103"},
{ 0xFFFFFFFF80003677,"X64_ISR104"},
{ 0xFFFFFFFF80003680,"X64_ISR105"},
{ 0xFFFFFFFF80003689,"X64_ISR106"},
{ 0xFFFFFFFF80003692,"X64_ISR107"},
{ 0xFFFFFFFF8000369B,"X64_ISR108"},
{ 0xFFFFFFFF800036A4,"X64_ISR109"},
{ 0xFFFFFFFF800036AD,"X64_ISR110"},
{ 0xFFFFFFFF800036B6,"X64_ISR111"},
{ 0xFFFFFFFF800036BF,"X64_ISR112"},
{ 0xFFFFFFFF800036C8,"X64_ISR113"},
{ 0xFFFFFFFF800036D1,"X64_ISR114"},
{ 0xFFFFFFFF800036DA,"X64_ISR115"},
{ 0xFFFFFFFF800036E3,"X64_ISR116"},
{ 0xFFFFFFFF800036EC,"X64_ISR117"},
{ 0xFFFFFFFF800036F5,"X64_ISR118"},
{ 0xFFFFFFFF800036FE,"X64_ISR119"},
{ 0xFFFFFFFF80003707,"X64_ISR120"},
{ 0xFFFFFFFF80003710,"X64_ISR121"},
{ 0xFFFFFFFF80003719,"X64_ISR122"},
{ 0xFFFFFFFF80003722,"X64_ISR123"},
{ 0xFFFFFFFF8000372B,"X64_ISR124"},
{ 0xFFFFFFFF80003734,"X64_ISR125"},
{ 0xFFFFFFFF8000373D,"X64_ISR126"},
{ 0xFFFFFFFF80003746,"X64_ISR127"},
{ 0xFFFFFFFF8000374F,"X64_ISR128"},
{ 0xFFFFFFFF8000375B,"X64_ISR129"},
{ 0xFFFFFFFF80003767,"X64_ISR130"},
{ 0xFFFFFFFF80003773,"X64_ISR131"},
{ 0xFFFFFFFF8000377F,"X64_ISR132"},
{ 0xFFFFFFFF8000378B,"X64_ISR133"},
{ 0xFFFFFFFF80003797,"X64_ISR134"},
{ 0xFFFFFFFF800037A3,"X64_ISR135"},
{ 0xFFFFFFFF800037AF,"X64_ISR136"},
{ 0xFFFFFFFF800037BB,"X64_ISR137"},
{ 0xFFFFFFFF800037C7,"X64_ISR138"},
{ 0xFFFFFFFF800037D3,"X64_ISR139"},
{ 0xFFFFFFFF800037DF,"X64_ISR140"},
{ 0xFFFFFFFF800037EB,"X64_ISR141"},
{ 0xFFFFFFFF800037F7,"X64_ISR142"},
{ 0xFFFFFFFF80003803,"X64_ISR143"},
{ 0xFFFFFFFF8000380F,"X64_ISR144"},
{ 0xFFFFFFFF8000381B,"X64_ISR145"},
{ 0xFFFFFFFF80003827,"X64_ISR146"},
{ 0xFFFFFFFF80003833,"X64_ISR147"},
{ 0xFFFFFFFF8000383F,"X64_ISR148"},
{ 0xFFFFFFFF8000384B,"X64_ISR149"},
{ 0xFFFFFFFF80003857,"X64_ISR150"},
{ 0xFFFFFFFF80003863,"X64_ISR151"},
{ 0xFFFFFFFF8000386F,"X64_ISR152"},
{ 0xFFFFFFFF8000387B,"X64_ISR153"},
{ 0xFFFFFFFF80003887,"X64_ISR154"},
{ 0xFFFFFFFF80003893,"X64_ISR155"},
{ 0xFFFFFFFF8000389F,"X64_ISR156"},
{ 0xFFFFFFFF800038AB,"X64_ISR157"},
{ 0xFFFFFFFF800038B7,"X64_ISR158"},
{ 0xFFFFFFFF800038C3,"X64_ISR159"},
{ 0xFFFFFFFF800038CF,"X64_ISR160"},
{ 0xFFFFFFFF800038DB,"X64_ISR161"},
{ 0xFFFFFFFF800038E7,"X64_ISR162"},
{ 0xFFFFFFFF800038F3,"X64_ISR163"},
{ 0xFFFFFFFF800038FF,"X64_ISR164"},
{ 0xFFFFFFFF8000390B,"X64_ISR165"},
{ 0xFFFFFFFF80003917,"X64_ISR166"},
{ 0xFFFFFFFF80003923,"X64_ISR167"},
{ 0xFFFFFFFF8000392F,"X64_ISR168"},
{ 0xFFFFFFFF8000393B,"X64_ISR169"},
{ 0xFFFFFFFF80003947,"X64_ISR170"},
{ 0xFFFFFFFF80003953,"X64_ISR171"},
{ 0xFFFFFFFF8000395F,"X64_ISR172"},
{ 0xFFFFFFFF8000396B,"X64_ISR173"},
{ 0xFFFFFFFF80003977,"X64_ISR174"},
{ 0xFFFFFFFF80003983,"X64_ISR175"},
{ 0xFFFFFFFF8000398F,"X64_ISR176"},
{ 0xFFFFFFFF8000399B,"X64_ISR177"},
{ 0xFFFFFFFF800039A7,"X64_ISR178"},
{ 0xFFFFFFFF800039B3,"X64_ISR179"},
{ 0xFFFFFFFF800039BF,"X64_ISR180"},
{ 0xFFFFFFFF800039CB,"X64_ISR181"},
{ 0xFFFFFFFF800039D7,"X64_ISR182"},
{ 0xFFFFFFFF800039E3,"X64_ISR183"},
{ 0xFFFFFFFF800039EF,"X64_ISR184"},
{ 0xFFFFFFFF800039FB,"X64_ISR185"},
{ 0xFFFFFFFF80003A07,"X64_ISR186"},
{ 0xFFFFFFFF80003A13,"X64_ISR187"},
{ 0xFFFFFFFF80003A1F,"X64_ISR188"},
{ 0xFFFFFFFF80003A2B,"X64_ISR189"},
{ 0xFFFFFFFF80003A37,"X64_ISR190"},
{ 0xFFFFFFFF80003A43,"X64_ISR191"},
{ 0xFFFFFFFF80003A4F,"X64_ISR192"},
{ 0xFFFFFFFF80003A5B,"X64_ISR193"},
{ 0xFFFFFFFF80003A67,"X64_ISR194"},
{ 0xFFFFFFFF80003A73,"X64_ISR195"},
{ 0xFFFFFFFF80003A7F,"X64_ISR196"},
{ 0xFFFFFFFF80003A8B,"X64_ISR197"},
{ 0xFFFFFFFF80003A97,"X64_ISR198"},
{ 0xFFFFFFFF80003AA3,"X64_ISR199"},
{ 0xFFFFFFFF80003AAF,"X64_ISR200"},
{ 0xFFFFFFFF80003ABB,"X64_ISR201"},
{ 0xFFFFFFFF80003AC7,"X64_ISR202"},
{ 0xFFFFFFFF80003AD3,"X64_ISR203"},
{ 0xFFFFFFFF80003ADF,"X64_ISR204"},
{ 0xFFFFFFFF80003AEB,"X64_ISR205"},
{ 0xFFFFFFFF80003AF7,"X64_ISR206"},
{ 0xFFFFFFFF80003B03,"X64_ISR207"},
{ 0xFFFFFFFF80003B0F,"X64_ISR208"},
{ 0xFFFFFFFF80003B1B,"X64_ISR209"},
{ 0xFFFFFFFF80003B27,"X64_ISR210"},
{ 0xFFFFFFFF80003B33,"X64_ISR211"},
{ 0xFFFFFFFF80003B3F,"X64_ISR212"},
{ 0xFFFFFFFF80003B4B,"X64_ISR213"},
{ 0xFFFFFFFF80003B57,"X64_ISR214"},
{ 0xFFFFFFFF80003B63,"X64_ISR215"},
{ 0xFFFFFFFF80003B6F,"X64_ISR216"},
{ 0xFFFFFFFF80003B7B,"X64_ISR217"},
{ 0xFFFFFFFF80003B87,"X64_ISR218"},
{ 0xFFFFFFFF80003B93,"X64_ISR219"},
{ 0xFFFFFFFF80003B9F,"X64_ISR220"},
{ 0xFFFFFFFF80003BAB,"X64_ISR221"},
{ 0xFFFFFFFF80003BB7,"X64_ISR222"},
{ 0xFFFFFFFF80003BC3,"X64_ISR223"},
{ 0xFFFFFFFF80003BCF,"X64_ISR224"},
{ 0xFFFFFFFF80003BDB,"X64_ISR225"},
{ 0xFFFFFFFF80003BE7,"X64_ISR226"},
{ 0xFFFFFFFF80003BF3,"X64_ISR227"},
{ 0xFFFFFFFF80003BFF,"X64_ISR228"},
{ 0xFFFFFFFF80003C0B,"X64_ISR229"},
{ 0xFFFFFFFF80003C17,"X64_ISR230"},
{ 0xFFFFFFFF80003C23,"X64_ISR231"},
{ 0xFFFFFFFF80003C2F,"X64_ISR232"},
{ 0xFFFFFFFF80003C3B,"X64_ISR233"},
{ 0xFFFFFFFF80003C47,"X64_ISR234"},
{ 0xFFFFFFFF80003C53,"X64_ISR235"},
{ 0xFFFFFFFF80003C5F,"X64_ISR236"},
{ 0xFFFFFFFF80003C6B,"X64_ISR237"},
{ 0xFFFFFFFF80003C77,"X64_ISR238"},
{ 0xFFFFFFFF80003C83,"X64_ISR239"},
{ 0xFFFFFFFF80003C8F,"X64_ISR240"},
{ 0xFFFFFFFF80003C9B,"X64_ISR241"},
{ 0xFFFFFFFF80003CA7,"X64_ISR242"},
{ 0xFFFFFFFF80003CB3,"X64_ISR243"},
{ 0xFFFFFFFF80003CBF,"X64_ISR244"},
{ 0xFFFFFFFF80003CCB,"X64_ISR245"},
{ 0xFFFFFFFF80003CD7,"X64_ISR246"},
{ 0xFFFFFFFF80003CE3,"X64_ISR247"},
{ 0xFFFFFFFF80003CEF,"X64_ISR248"},
{ 0xFFFFFFFF80003CFB,"X64_ISR249"},
{ 0xFFFFFFFF80003D07,"X64_ISR250"},
{ 0xFFFFFFFF80003D13,"X64_ISR251"},
{ 0xFFFFFFFF80003D1F,"X64_ISR252"},
{ 0xFFFFFFFF80003D2B,"X64_ISR253"},
{ 0xFFFFFFFF80003D37,"X64_ISR254"},
{ 0xFFFFFFFF80003D43,"X64_ISR255"},
{ 0xFFFFFFFF80003D50,"x64_cpu_stop"},
{ 0xFFFFFFFF80003D54,"x64_EnableInterrupts"},
{ 0xFFFFFFFF80003D56,"x64_DisableInterrupts"},
{ 0xFFFFFFFF80003D58,"x64_outb"},
{ 0xFFFFFFFF80003D60,"x64_inb"},
{ 0xFFFFFFFF80003D65,"x64_insb"},
{ 0xFFFFFFFF80003D72,"x64_insw"},
{ 0xFFFFFFFF80003D80,"x64_outsb"},
{ 0xFFFFFFFF80003D8D,"x64_outsw"},
{ 0xFFFFFFFF80003D9B,"load_idt"},
{ 0xFFFFFFFF80003DA7,"gdt_flush"},
{ 0xFFFFFFFF80003DC2,"tss_flush"},
{NULL, NULL}
};
#pragma GCC diagnostic pop
