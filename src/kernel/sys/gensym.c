//This file has been generated by symgen.py
#include "kstdio.h"
#include "ksyms.h"
#include <stddef.h>


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Wmissing-braces"
const KsymList symbols[] = {
{ 0xFFFFFFFF80000000,"GetBasicKernelVersion"},
{ 0xFFFFFFFF80000018,"GetKernelVersion"},
{ 0xFFFFFFFF8000017D,"NkkGetLastKernelError"},
{ 0xFFFFFFFF80000185,"NkkTranslateError"},
{ 0xFFFFFFFF8000019B,"NkkSetLastSystemError"},
{ 0xFFFFFFFF800001B3,"IsValidFlag"},
{ 0xFFFFFFFF800001C8,"strcmp"},
{ 0xFFFFFFFF800001EB,"strncmp"},
{ 0xFFFFFFFF80000228,"strncpy"},
{ 0xFFFFFFFF8000026E,"memcpy"},
{ 0xFFFFFFFF8000028E,"memset"},
{ 0xFFFFFFFF800002A9,"memmove"},
{ 0xFFFFFFFF800002E5,"memcmp"},
{ 0xFFFFFFFF80000318,"strlen"},
{ 0xFFFFFFFF80000333,"strncat"},
{ 0xFFFFFFFF80000388,"itoa"},
{ 0xFFFFFFFF80000404,"debugf"},
{ 0xFFFFFFFF800004E1,"BroadcastPrintf"},
{ 0xFFFFFFFF800005BE,"BroadcastPuts"},
{ 0xFFFFFFFF800005F6,"BroadcastPutc"},
{ 0xFFFFFFFF80000632,"debugs"},
{ 0xFFFFFFFF8000066A,"putchar"},
{ 0xFFFFFFFF800006A6,"toupper"},
{ 0xFFFFFFFF800006B5,"clrscr"},
{ 0xFFFFFFFF800006C5,"_out_buffer"},
{ 0xFFFFFFFF800006CF,"_out_null"},
{ 0xFFFFFFFF800006D0,"_out_fct"},
{ 0xFFFFFFFF800006E9,"_out_rev"},
{ 0xFFFFFFFF800007CD,"_ntoa_format"},
{ 0xFFFFFFFF8000096A,"_ntoa_long"},
{ 0xFFFFFFFF80000A37,"_ntoa_long_long"},
{ 0xFFFFFFFF80000B04,"_etoa"},
{ 0xFFFFFFFF80000EBA,"_ftoa"},
{ 0xFFFFFFFF8000133F,"_out_char"},
{ 0xFFFFFFFF80001354,"_vsnprintf"},
{ 0xFFFFFFFF80001E7A,"printf_"},
{ 0xFFFFFFFF80001F1F,"sprintf_"},
{ 0xFFFFFFFF80001FB9,"snprintf_"},
{ 0xFFFFFFFF80002048,"vprintf_"},
{ 0xFFFFFFFF8000206F,"vsnprintf_"},
{ 0xFFFFFFFF8000208D,"fctprintf"},
{ 0xFFFFFFFF80002132,"_start"},
{ 0xFFFFFFFF800024A4,"page_fault_handler"},
{ 0xFFFFFFFF8000256E,"gpf_handler"},
{ 0xFFFFFFFF80002634,"kmain"},
{ 0xFFFFFFFF8000289F,"_timercb_internal_"},
{ 0xFFFFFFFF800028CA,"PIT_SetFrequency"},
{ 0xFFFFFFFF80002910,"PIT_Init"},
{ 0xFFFFFFFF80002931,"GetSystemTicks"},
{ 0xFFFFFFFF80002939,"kusleep"},
{ 0xFFFFFFFF80002956,"SetKbctlEvent"},
{ 0xFFFFFFFF8000298A,"GetKbctl"},
{ 0xFFFFFFFF80002992,"GetKbctlEvent"},
{ 0xFFFFFFFF8000299F,"_keyboardcb_"},
{ 0xFFFFFFFF80002CA3,"KeyboardInit"},
{ 0xFFFFFFFF80002CC7,"GetRawKeyboardFlags"},
{ 0xFFFFFFFF80002CCE,"IRQ_RegisterHandler"},
{ 0xFFFFFFFF80002CDB,"IRQ_SendEOI"},
{ 0xFFFFFFFF80002D07,"IRQ_Handler"},
{ 0xFFFFFFFF80002D5B,"DebugPageFault"},
{ 0xFFFFFFFF80002D86,"PrintRegs"},
{ 0xFFFFFFFF80002E32,"_SystemRaiseHardError"},
{ 0xFFFFFFFF80002FBD,"InitializeIDT"},
{ 0xFFFFFFFF8000308F,"IDT_SetGate"},
{ 0xFFFFFFFF800030D6,"IDT_EnableGate"},
{ 0xFFFFFFFF800030E5,"IDT_DisableGate"},
{ 0xFFFFFFFF800030F4,"kmalloc"},
{ 0xFFFFFFFF8000346F,"kfree"},
{ 0xFFFFFFFF8000371B,"kcalloc"},
{ 0xFFFFFFFF80003755,"krealloc"},
{ 0xFFFFFFFF8000382C,"PmmIsInitialized"},
{ 0xFFFFFFFF8000384C,"GetKernelPageSize"},
{ 0xFFFFFFFF80003854,"PmmLock"},
{ 0xFFFFFFFF80003881,"PmmUnlock"},
{ 0xFFFFFFFF800038AE,"SetKernelPageSize"},
{ 0xFFFFFFFF800038E8,"PmmUnstash"},
{ 0xFFFFFFFF800039FE,"PmmInit"},
{ 0xFFFFFFFF80003BE7,"_AllocPage"},
{ 0xFFFFFFFF80003CDD,"PmmAllocPage"},
{ 0xFFFFFFFF80003DDA,"PageFromAddr"},
{ 0xFFFFFFFF80003DF7,"PmmFreePage"},
{ 0xFFFFFFFF80003E82,"liballoc_lock"},
{ 0xFFFFFFFF80003E97,"liballoc_unlock"},
{ 0xFFFFFFFF80003EAC,"liballoc_alloc"},
{ 0xFFFFFFFF80003EB7,"liballoc_free"},
{ 0xFFFFFFFF80003EC7,"IsrsGateSetup"},
{ 0xFFFFFFFF80005384,"GetIsrExceptionList"},
{ 0xFFFFFFFF8000538C,"ISR_Init"},
{ 0xFFFFFFFF800053BC,"ISR_Handler"},
{ 0xFFFFFFFF8000543C,"ISR_RegisterHandler"},
{ 0xFFFFFFFF80005452,"Regs2ISRState"},
{ 0xFFFFFFFF800055B7,"CS2DPL"},
{ 0xFFFFFFFF800055D4,"SetGDTEntry"},
{ 0xFFFFFFFF80005623,"InitializeGDT"},
{ 0xFFFFFFFF80005760,"bump_alloc"},
{ 0xFFFFFFFF80005787,"flanterm_fb_save_state"},
{ 0xFFFFFFFF800057BC,"flanterm_fb_restore_state"},
{ 0xFFFFFFFF800057F1,"flanterm_fb_swap_palette"},
{ 0xFFFFFFFF8000580A,"plot_char"},
{ 0xFFFFFFFF80005995,"push_to_queue"},
{ 0xFFFFFFFF80005A37,"flanterm_fb_revscroll"},
{ 0xFFFFFFFF80005B27,"flanterm_fb_scroll"},
{ 0xFFFFFFFF80005C09,"flanterm_fb_clear"},
{ 0xFFFFFFFF80005CB0,"flanterm_fb_set_cursor_pos"},
{ 0xFFFFFFFF80005CF5,"flanterm_fb_get_cursor_pos"},
{ 0xFFFFFFFF80005D31,"flanterm_fb_move_character"},
{ 0xFFFFFFFF80005D9D,"flanterm_fb_set_text_fg"},
{ 0xFFFFFFFF80005DAB,"flanterm_fb_set_text_bg"},
{ 0xFFFFFFFF80005DB9,"flanterm_fb_set_text_fg_bright"},
{ 0xFFFFFFFF80005DC7,"flanterm_fb_set_text_bg_bright"},
{ 0xFFFFFFFF80005DD5,"flanterm_fb_set_text_fg_rgb"},
{ 0xFFFFFFFF80005DDC,"flanterm_fb_set_text_bg_rgb"},
{ 0xFFFFFFFF80005DE3,"flanterm_fb_set_text_fg_default"},
{ 0xFFFFFFFF80005DF0,"flanterm_fb_set_text_bg_default"},
{ 0xFFFFFFFF80005DFB,"flanterm_fb_set_text_fg_default_bright"},
{ 0xFFFFFFFF80005E08,"flanterm_fb_set_text_bg_default_bright"},
{ 0xFFFFFFFF80005E15,"draw_cursor"},
{ 0xFFFFFFFF80005EF2,"flanterm_fb_double_buffer_flush"},
{ 0xFFFFFFFF80006205,"flanterm_fb_raw_putchar"},
{ 0xFFFFFFFF800062C8,"flanterm_fb_full_refresh"},
{ 0xFFFFFFFF800063BB,"flanterm_fb_deinit"},
{ 0xFFFFFFFF80006448,"flanterm_fb_init"},
{ 0xFFFFFFFF80006C9F,"flanterm_context_reinit"},
{ 0xFFFFFFFF80006D4D,"mk_wcwidth"},
{ 0xFFFFFFFF80006E83,"flanterm_write"},
{ 0xFFFFFFFF80008C24,"Fb_GetStreamType"},
{ 0xFFFFFFFF80008C2B,"Fb_SwitchStream"},
{ 0xFFFFFFFF80008C4D,"_FbPutString"},
{ 0xFFFFFFFF80008C76,"ClearFbScreen"},
{ 0xFFFFFFFF80008C88,"_FbPutChar"},
{ 0xFFFFFFFF80008CE0,"_putchar"},
{ 0xFFFFFFFF80008CF4,"InitializeFramebuffers"},
{ 0xFFFFFFFF80008D00,"X64_IRQ0"},
{ 0xFFFFFFFF80008D11,"X64_IRQ1"},
{ 0xFFFFFFFF80008D22,"X64_IRQ2"},
{ 0xFFFFFFFF80008D33,"X64_IRQ3"},
{ 0xFFFFFFFF80008D44,"X64_IRQ4"},
{ 0xFFFFFFFF80008D55,"X64_IRQ5"},
{ 0xFFFFFFFF80008D66,"X64_IRQ6"},
{ 0xFFFFFFFF80008D77,"X64_IRQ7"},
{ 0xFFFFFFFF80008D88,"X64_IRQ8"},
{ 0xFFFFFFFF80008D99,"X64_IRQ9"},
{ 0xFFFFFFFF80008DAA,"X64_IRQ10"},
{ 0xFFFFFFFF80008DBB,"X64_IRQ11"},
{ 0xFFFFFFFF80008DCC,"X64_IRQ12"},
{ 0xFFFFFFFF80008DDD,"X64_IRQ13"},
{ 0xFFFFFFFF80008DEE,"X64_IRQ14"},
{ 0xFFFFFFFF80008DFF,"X64_IRQ15"},
{ 0xFFFFFFFF80008E10,"irqHandlers"},
{ 0xFFFFFFFF80008E90,"isr_common"},
{ 0xFFFFFFFF80008ED0,"X64_ISR0"},
{ 0xFFFFFFFF80008ED6,"X64_ISR1"},
{ 0xFFFFFFFF80008EDC,"X64_ISR2"},
{ 0xFFFFFFFF80008EE2,"X64_ISR3"},
{ 0xFFFFFFFF80008EE8,"X64_ISR4"},
{ 0xFFFFFFFF80008EEE,"X64_ISR5"},
{ 0xFFFFFFFF80008EF4,"X64_ISR6"},
{ 0xFFFFFFFF80008EFA,"X64_ISR7"},
{ 0xFFFFFFFF80008F00,"X64_ISR8"},
{ 0xFFFFFFFF80008F04,"X64_ISR9"},
{ 0xFFFFFFFF80008F0A,"X64_ISR10"},
{ 0xFFFFFFFF80008F0E,"X64_ISR11"},
{ 0xFFFFFFFF80008F15,"X64_ISR12"},
{ 0xFFFFFFFF80008F1C,"X64_ISR13"},
{ 0xFFFFFFFF80008F23,"X64_ISR14"},
{ 0xFFFFFFFF80008F2A,"X64_ISR15"},
{ 0xFFFFFFFF80008F33,"X64_ISR16"},
{ 0xFFFFFFFF80008F3C,"X64_ISR17"},
{ 0xFFFFFFFF80008F43,"X64_ISR18"},
{ 0xFFFFFFFF80008F4C,"X64_ISR19"},
{ 0xFFFFFFFF80008F55,"X64_ISR20"},
{ 0xFFFFFFFF80008F5E,"X64_ISR21"},
{ 0xFFFFFFFF80008F65,"X64_ISR22"},
{ 0xFFFFFFFF80008F6E,"X64_ISR23"},
{ 0xFFFFFFFF80008F77,"X64_ISR24"},
{ 0xFFFFFFFF80008F80,"X64_ISR25"},
{ 0xFFFFFFFF80008F89,"X64_ISR26"},
{ 0xFFFFFFFF80008F92,"X64_ISR27"},
{ 0xFFFFFFFF80008F9B,"X64_ISR28"},
{ 0xFFFFFFFF80008FA4,"X64_ISR29"},
{ 0xFFFFFFFF80008FAD,"X64_ISR30"},
{ 0xFFFFFFFF80008FB6,"X64_ISR31"},
{ 0xFFFFFFFF80008FBF,"X64_ISR32"},
{ 0xFFFFFFFF80008FC8,"X64_ISR33"},
{ 0xFFFFFFFF80008FD1,"X64_ISR34"},
{ 0xFFFFFFFF80008FDA,"X64_ISR35"},
{ 0xFFFFFFFF80008FE3,"X64_ISR36"},
{ 0xFFFFFFFF80008FEC,"X64_ISR37"},
{ 0xFFFFFFFF80008FF5,"X64_ISR38"},
{ 0xFFFFFFFF80008FFE,"X64_ISR39"},
{ 0xFFFFFFFF80009007,"X64_ISR40"},
{ 0xFFFFFFFF80009010,"X64_ISR41"},
{ 0xFFFFFFFF80009019,"X64_ISR42"},
{ 0xFFFFFFFF80009022,"X64_ISR43"},
{ 0xFFFFFFFF8000902B,"X64_ISR44"},
{ 0xFFFFFFFF80009034,"X64_ISR45"},
{ 0xFFFFFFFF8000903D,"X64_ISR46"},
{ 0xFFFFFFFF80009046,"X64_ISR47"},
{ 0xFFFFFFFF8000904F,"X64_ISR48"},
{ 0xFFFFFFFF80009058,"X64_ISR49"},
{ 0xFFFFFFFF80009061,"X64_ISR50"},
{ 0xFFFFFFFF8000906A,"X64_ISR51"},
{ 0xFFFFFFFF80009073,"X64_ISR52"},
{ 0xFFFFFFFF8000907C,"X64_ISR53"},
{ 0xFFFFFFFF80009085,"X64_ISR54"},
{ 0xFFFFFFFF8000908E,"X64_ISR55"},
{ 0xFFFFFFFF80009097,"X64_ISR56"},
{ 0xFFFFFFFF800090A0,"X64_ISR57"},
{ 0xFFFFFFFF800090A9,"X64_ISR58"},
{ 0xFFFFFFFF800090B2,"X64_ISR59"},
{ 0xFFFFFFFF800090BB,"X64_ISR60"},
{ 0xFFFFFFFF800090C4,"X64_ISR61"},
{ 0xFFFFFFFF800090CD,"X64_ISR62"},
{ 0xFFFFFFFF800090D6,"X64_ISR63"},
{ 0xFFFFFFFF800090DF,"X64_ISR64"},
{ 0xFFFFFFFF800090E8,"X64_ISR65"},
{ 0xFFFFFFFF800090F1,"X64_ISR66"},
{ 0xFFFFFFFF800090FA,"X64_ISR67"},
{ 0xFFFFFFFF80009103,"X64_ISR68"},
{ 0xFFFFFFFF8000910C,"X64_ISR69"},
{ 0xFFFFFFFF80009115,"X64_ISR70"},
{ 0xFFFFFFFF8000911E,"X64_ISR71"},
{ 0xFFFFFFFF80009127,"X64_ISR72"},
{ 0xFFFFFFFF80009130,"X64_ISR73"},
{ 0xFFFFFFFF80009139,"X64_ISR74"},
{ 0xFFFFFFFF80009142,"X64_ISR75"},
{ 0xFFFFFFFF8000914B,"X64_ISR76"},
{ 0xFFFFFFFF80009154,"X64_ISR77"},
{ 0xFFFFFFFF8000915D,"X64_ISR78"},
{ 0xFFFFFFFF80009166,"X64_ISR79"},
{ 0xFFFFFFFF8000916F,"X64_ISR80"},
{ 0xFFFFFFFF80009178,"X64_ISR81"},
{ 0xFFFFFFFF80009181,"X64_ISR82"},
{ 0xFFFFFFFF8000918A,"X64_ISR83"},
{ 0xFFFFFFFF80009193,"X64_ISR84"},
{ 0xFFFFFFFF8000919C,"X64_ISR85"},
{ 0xFFFFFFFF800091A5,"X64_ISR86"},
{ 0xFFFFFFFF800091AE,"X64_ISR87"},
{ 0xFFFFFFFF800091B7,"X64_ISR88"},
{ 0xFFFFFFFF800091C0,"X64_ISR89"},
{ 0xFFFFFFFF800091C9,"X64_ISR90"},
{ 0xFFFFFFFF800091D2,"X64_ISR91"},
{ 0xFFFFFFFF800091DB,"X64_ISR92"},
{ 0xFFFFFFFF800091E4,"X64_ISR93"},
{ 0xFFFFFFFF800091ED,"X64_ISR94"},
{ 0xFFFFFFFF800091F6,"X64_ISR95"},
{ 0xFFFFFFFF800091FF,"X64_ISR96"},
{ 0xFFFFFFFF80009208,"X64_ISR97"},
{ 0xFFFFFFFF80009211,"X64_ISR98"},
{ 0xFFFFFFFF8000921A,"X64_ISR99"},
{ 0xFFFFFFFF80009223,"X64_ISR100"},
{ 0xFFFFFFFF8000922C,"X64_ISR101"},
{ 0xFFFFFFFF80009235,"X64_ISR102"},
{ 0xFFFFFFFF8000923E,"X64_ISR103"},
{ 0xFFFFFFFF80009247,"X64_ISR104"},
{ 0xFFFFFFFF80009250,"X64_ISR105"},
{ 0xFFFFFFFF80009259,"X64_ISR106"},
{ 0xFFFFFFFF80009262,"X64_ISR107"},
{ 0xFFFFFFFF8000926B,"X64_ISR108"},
{ 0xFFFFFFFF80009274,"X64_ISR109"},
{ 0xFFFFFFFF8000927D,"X64_ISR110"},
{ 0xFFFFFFFF80009286,"X64_ISR111"},
{ 0xFFFFFFFF8000928F,"X64_ISR112"},
{ 0xFFFFFFFF80009298,"X64_ISR113"},
{ 0xFFFFFFFF800092A1,"X64_ISR114"},
{ 0xFFFFFFFF800092AA,"X64_ISR115"},
{ 0xFFFFFFFF800092B3,"X64_ISR116"},
{ 0xFFFFFFFF800092BC,"X64_ISR117"},
{ 0xFFFFFFFF800092C5,"X64_ISR118"},
{ 0xFFFFFFFF800092CE,"X64_ISR119"},
{ 0xFFFFFFFF800092D7,"X64_ISR120"},
{ 0xFFFFFFFF800092E0,"X64_ISR121"},
{ 0xFFFFFFFF800092E9,"X64_ISR122"},
{ 0xFFFFFFFF800092F2,"X64_ISR123"},
{ 0xFFFFFFFF800092FB,"X64_ISR124"},
{ 0xFFFFFFFF80009304,"X64_ISR125"},
{ 0xFFFFFFFF8000930D,"X64_ISR126"},
{ 0xFFFFFFFF80009316,"X64_ISR127"},
{ 0xFFFFFFFF8000931F,"X64_ISR128"},
{ 0xFFFFFFFF8000932B,"X64_ISR129"},
{ 0xFFFFFFFF80009337,"X64_ISR130"},
{ 0xFFFFFFFF80009343,"X64_ISR131"},
{ 0xFFFFFFFF8000934F,"X64_ISR132"},
{ 0xFFFFFFFF8000935B,"X64_ISR133"},
{ 0xFFFFFFFF80009367,"X64_ISR134"},
{ 0xFFFFFFFF80009373,"X64_ISR135"},
{ 0xFFFFFFFF8000937F,"X64_ISR136"},
{ 0xFFFFFFFF8000938B,"X64_ISR137"},
{ 0xFFFFFFFF80009397,"X64_ISR138"},
{ 0xFFFFFFFF800093A3,"X64_ISR139"},
{ 0xFFFFFFFF800093AF,"X64_ISR140"},
{ 0xFFFFFFFF800093BB,"X64_ISR141"},
{ 0xFFFFFFFF800093C7,"X64_ISR142"},
{ 0xFFFFFFFF800093D3,"X64_ISR143"},
{ 0xFFFFFFFF800093DF,"X64_ISR144"},
{ 0xFFFFFFFF800093EB,"X64_ISR145"},
{ 0xFFFFFFFF800093F7,"X64_ISR146"},
{ 0xFFFFFFFF80009403,"X64_ISR147"},
{ 0xFFFFFFFF8000940F,"X64_ISR148"},
{ 0xFFFFFFFF8000941B,"X64_ISR149"},
{ 0xFFFFFFFF80009427,"X64_ISR150"},
{ 0xFFFFFFFF80009433,"X64_ISR151"},
{ 0xFFFFFFFF8000943F,"X64_ISR152"},
{ 0xFFFFFFFF8000944B,"X64_ISR153"},
{ 0xFFFFFFFF80009457,"X64_ISR154"},
{ 0xFFFFFFFF80009463,"X64_ISR155"},
{ 0xFFFFFFFF8000946F,"X64_ISR156"},
{ 0xFFFFFFFF8000947B,"X64_ISR157"},
{ 0xFFFFFFFF80009487,"X64_ISR158"},
{ 0xFFFFFFFF80009493,"X64_ISR159"},
{ 0xFFFFFFFF8000949F,"X64_ISR160"},
{ 0xFFFFFFFF800094AB,"X64_ISR161"},
{ 0xFFFFFFFF800094B7,"X64_ISR162"},
{ 0xFFFFFFFF800094C3,"X64_ISR163"},
{ 0xFFFFFFFF800094CF,"X64_ISR164"},
{ 0xFFFFFFFF800094DB,"X64_ISR165"},
{ 0xFFFFFFFF800094E7,"X64_ISR166"},
{ 0xFFFFFFFF800094F3,"X64_ISR167"},
{ 0xFFFFFFFF800094FF,"X64_ISR168"},
{ 0xFFFFFFFF8000950B,"X64_ISR169"},
{ 0xFFFFFFFF80009517,"X64_ISR170"},
{ 0xFFFFFFFF80009523,"X64_ISR171"},
{ 0xFFFFFFFF8000952F,"X64_ISR172"},
{ 0xFFFFFFFF8000953B,"X64_ISR173"},
{ 0xFFFFFFFF80009547,"X64_ISR174"},
{ 0xFFFFFFFF80009553,"X64_ISR175"},
{ 0xFFFFFFFF8000955F,"X64_ISR176"},
{ 0xFFFFFFFF8000956B,"X64_ISR177"},
{ 0xFFFFFFFF80009577,"X64_ISR178"},
{ 0xFFFFFFFF80009583,"X64_ISR179"},
{ 0xFFFFFFFF8000958F,"X64_ISR180"},
{ 0xFFFFFFFF8000959B,"X64_ISR181"},
{ 0xFFFFFFFF800095A7,"X64_ISR182"},
{ 0xFFFFFFFF800095B3,"X64_ISR183"},
{ 0xFFFFFFFF800095BF,"X64_ISR184"},
{ 0xFFFFFFFF800095CB,"X64_ISR185"},
{ 0xFFFFFFFF800095D7,"X64_ISR186"},
{ 0xFFFFFFFF800095E3,"X64_ISR187"},
{ 0xFFFFFFFF800095EF,"X64_ISR188"},
{ 0xFFFFFFFF800095FB,"X64_ISR189"},
{ 0xFFFFFFFF80009607,"X64_ISR190"},
{ 0xFFFFFFFF80009613,"X64_ISR191"},
{ 0xFFFFFFFF8000961F,"X64_ISR192"},
{ 0xFFFFFFFF8000962B,"X64_ISR193"},
{ 0xFFFFFFFF80009637,"X64_ISR194"},
{ 0xFFFFFFFF80009643,"X64_ISR195"},
{ 0xFFFFFFFF8000964F,"X64_ISR196"},
{ 0xFFFFFFFF8000965B,"X64_ISR197"},
{ 0xFFFFFFFF80009667,"X64_ISR198"},
{ 0xFFFFFFFF80009673,"X64_ISR199"},
{ 0xFFFFFFFF8000967F,"X64_ISR200"},
{ 0xFFFFFFFF8000968B,"X64_ISR201"},
{ 0xFFFFFFFF80009697,"X64_ISR202"},
{ 0xFFFFFFFF800096A3,"X64_ISR203"},
{ 0xFFFFFFFF800096AF,"X64_ISR204"},
{ 0xFFFFFFFF800096BB,"X64_ISR205"},
{ 0xFFFFFFFF800096C7,"X64_ISR206"},
{ 0xFFFFFFFF800096D3,"X64_ISR207"},
{ 0xFFFFFFFF800096DF,"X64_ISR208"},
{ 0xFFFFFFFF800096EB,"X64_ISR209"},
{ 0xFFFFFFFF800096F7,"X64_ISR210"},
{ 0xFFFFFFFF80009703,"X64_ISR211"},
{ 0xFFFFFFFF8000970F,"X64_ISR212"},
{ 0xFFFFFFFF8000971B,"X64_ISR213"},
{ 0xFFFFFFFF80009727,"X64_ISR214"},
{ 0xFFFFFFFF80009733,"X64_ISR215"},
{ 0xFFFFFFFF8000973F,"X64_ISR216"},
{ 0xFFFFFFFF8000974B,"X64_ISR217"},
{ 0xFFFFFFFF80009757,"X64_ISR218"},
{ 0xFFFFFFFF80009763,"X64_ISR219"},
{ 0xFFFFFFFF8000976F,"X64_ISR220"},
{ 0xFFFFFFFF8000977B,"X64_ISR221"},
{ 0xFFFFFFFF80009787,"X64_ISR222"},
{ 0xFFFFFFFF80009793,"X64_ISR223"},
{ 0xFFFFFFFF8000979F,"X64_ISR224"},
{ 0xFFFFFFFF800097AB,"X64_ISR225"},
{ 0xFFFFFFFF800097B7,"X64_ISR226"},
{ 0xFFFFFFFF800097C3,"X64_ISR227"},
{ 0xFFFFFFFF800097CF,"X64_ISR228"},
{ 0xFFFFFFFF800097DB,"X64_ISR229"},
{ 0xFFFFFFFF800097E7,"X64_ISR230"},
{ 0xFFFFFFFF800097F3,"X64_ISR231"},
{ 0xFFFFFFFF800097FF,"X64_ISR232"},
{ 0xFFFFFFFF8000980B,"X64_ISR233"},
{ 0xFFFFFFFF80009817,"X64_ISR234"},
{ 0xFFFFFFFF80009823,"X64_ISR235"},
{ 0xFFFFFFFF8000982F,"X64_ISR236"},
{ 0xFFFFFFFF8000983B,"X64_ISR237"},
{ 0xFFFFFFFF80009847,"X64_ISR238"},
{ 0xFFFFFFFF80009853,"X64_ISR239"},
{ 0xFFFFFFFF8000985F,"X64_ISR240"},
{ 0xFFFFFFFF8000986B,"X64_ISR241"},
{ 0xFFFFFFFF80009877,"X64_ISR242"},
{ 0xFFFFFFFF80009883,"X64_ISR243"},
{ 0xFFFFFFFF8000988F,"X64_ISR244"},
{ 0xFFFFFFFF8000989B,"X64_ISR245"},
{ 0xFFFFFFFF800098A7,"X64_ISR246"},
{ 0xFFFFFFFF800098B3,"X64_ISR247"},
{ 0xFFFFFFFF800098BF,"X64_ISR248"},
{ 0xFFFFFFFF800098CB,"X64_ISR249"},
{ 0xFFFFFFFF800098D7,"X64_ISR250"},
{ 0xFFFFFFFF800098E3,"X64_ISR251"},
{ 0xFFFFFFFF800098EF,"X64_ISR252"},
{ 0xFFFFFFFF800098FB,"X64_ISR253"},
{ 0xFFFFFFFF80009907,"X64_ISR254"},
{ 0xFFFFFFFF80009913,"X64_ISR255"},
{ 0xFFFFFFFF80009920,"x64_enable_sse"},
{ 0xFFFFFFFF80009939,"x64_enable_fpu"},
{ 0xFFFFFFFF8000995F,"x64_enable_avx"},
{ 0xFFFFFFFF80009973,"x64_cpu_stop"},
{ 0xFFFFFFFF80009977,"x64_EnableInterrupts"},
{ 0xFFFFFFFF80009979,"x64_DisableInterrupts"},
{ 0xFFFFFFFF8000997B,"x64_outb"},
{ 0xFFFFFFFF8000998B,"x64_inb"},
{ 0xFFFFFFFF80009998,"x64_insb"},
{ 0xFFFFFFFF800099AD,"x64_insw"},
{ 0xFFFFFFFF800099C3,"x64_outsb"},
{ 0xFFFFFFFF800099D8,"x64_outsw"},
{ 0xFFFFFFFF800099EE,"x64_load_idt"},
{ 0xFFFFFFFF800099FA,"x64_gdt_flush"},
{ 0xFFFFFFFF80009A15,"x64_tss_flush"},
{ 0xFFFFFFFF80009A1D,"x64_rdump"},
{ 0xFFFFFFFF80009A59,"x64_panic"},
{ 0xFFFFFFFF80009A5D,"x64_cli"},
{ 0xFFFFFFFF80009A5F,"x64_sti"},
{ 0xFFFFFFFF80009A61,"x64_rdtsc"},
{ 0xFFFFFFFF80009A75,"x64_readcs"},
{ 0xFFFFFFFF80009A80,"x64_readds"},
{NULL, NULL}
};
#pragma GCC diagnostic pop
