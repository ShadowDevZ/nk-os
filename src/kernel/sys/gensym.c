//This file has been generated by symgen.py
#include "kstdio.h"
#include "ksyms.h"
#include <stddef.h>


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"
const KsymList symbols[] = {
{ 0xFFFFFFFF80000000,"GetBasicKernelVersion"},
{ 0xFFFFFFFF80000018,"GetKernelVersion"},
{ 0xFFFFFFFF8000017D,"NkkGetLastKernelError"},
{ 0xFFFFFFFF80000185,"NkkTranslateError"},
{ 0xFFFFFFFF8000019B,"NkkSetLastSystemError"},
{ 0xFFFFFFFF800001B3,"KsymCount"},
{ 0xFFFFFFFF800001F0,"KsymFind"},
{ 0xFFFFFFFF80000245,"KsymResolveAddress"},
{ 0xFFFFFFFF8000028D,"KsymEnumSymbol"},
{ 0xFFFFFFFF800002FC,"KsymGetSymbolIndex"},
{ 0xFFFFFFFF8000033C,"IsValidFlag"},
{ 0xFFFFFFFF8000034E,"strcmp"},
{ 0xFFFFFFFF80000371,"strncmp"},
{ 0xFFFFFFFF800003AE,"strncpy"},
{ 0xFFFFFFFF800003F4,"memcpy"},
{ 0xFFFFFFFF80000414,"memset"},
{ 0xFFFFFFFF8000042F,"memmove"},
{ 0xFFFFFFFF8000046B,"memcmp"},
{ 0xFFFFFFFF8000049E,"strlen"},
{ 0xFFFFFFFF800004B9,"strncat"},
{ 0xFFFFFFFF8000050E,"itoa"},
{ 0xFFFFFFFF8000058A,"debugf"},
{ 0xFFFFFFFF80000667,"BroadcastPrintf"},
{ 0xFFFFFFFF80000744,"BroadcastPuts"},
{ 0xFFFFFFFF8000077C,"BroadcastPutc"},
{ 0xFFFFFFFF800007B8,"debugs"},
{ 0xFFFFFFFF800007F0,"putchar"},
{ 0xFFFFFFFF8000082C,"toupper"},
{ 0xFFFFFFFF8000083B,"clrscr"},
{ 0xFFFFFFFF8000084B,"_out_buffer"},
{ 0xFFFFFFFF80000855,"_out_null"},
{ 0xFFFFFFFF80000856,"_out_fct"},
{ 0xFFFFFFFF8000086F,"_out_rev"},
{ 0xFFFFFFFF80000953,"_ntoa_format"},
{ 0xFFFFFFFF80000AF0,"_ntoa_long"},
{ 0xFFFFFFFF80000BBD,"_ntoa_long_long"},
{ 0xFFFFFFFF80000C8A,"_etoa"},
{ 0xFFFFFFFF80001040,"_ftoa"},
{ 0xFFFFFFFF800014C5,"_out_char"},
{ 0xFFFFFFFF800014DA,"_vsnprintf"},
{ 0xFFFFFFFF80002000,"printf_"},
{ 0xFFFFFFFF800020A5,"sprintf_"},
{ 0xFFFFFFFF8000213F,"snprintf_"},
{ 0xFFFFFFFF800021CE,"vprintf_"},
{ 0xFFFFFFFF800021F5,"vsnprintf_"},
{ 0xFFFFFFFF80002213,"fctprintf"},
{ 0xFFFFFFFF800022B8,"_start"},
{ 0xFFFFFFFF800025ED,"page_fault_handler"},
{ 0xFFFFFFFF800026BB,"_timercb_internal_"},
{ 0xFFFFFFFF800026E6,"PIT_SetFrequency"},
{ 0xFFFFFFFF8000272C,"PIT_Init"},
{ 0xFFFFFFFF8000274D,"GetSystemTicks"},
{ 0xFFFFFFFF80002755,"kusleep"},
{ 0xFFFFFFFF8000276E,"SetKbctlEvent"},
{ 0xFFFFFFFF800027A2,"GetKbctl"},
{ 0xFFFFFFFF800027AA,"GetKbctlEvent"},
{ 0xFFFFFFFF800027B7,"_keyboardcb_"},
{ 0xFFFFFFFF80002ABB,"KeyboardInit"},
{ 0xFFFFFFFF80002ADF,"GetRawKeyboardFlags"},
{ 0xFFFFFFFF80002AE6,"IRQ_RegisterHandler"},
{ 0xFFFFFFFF80002AF3,"IRQ_SendEOI"},
{ 0xFFFFFFFF80002B1F,"IRQ_Handler"},
{ 0xFFFFFFFF80002B73,"PrintRegs"},
{ 0xFFFFFFFF80002C1F,"_SystemRaiseHardError"},
{ 0xFFFFFFFF80002DA7,"InitializeIDT"},
{ 0xFFFFFFFF80002E79,"IDT_SetGate"},
{ 0xFFFFFFFF80002EC3,"IDT_EnableGate"},
{ 0xFFFFFFFF80002ED2,"IDT_DisableGate"},
{ 0xFFFFFFFF80002EE1,"create_slab"},
{ 0xFFFFFFFF80002F85,"slab_init"},
{ 0xFFFFFFFF80003035,"slab_alloc"},
{ 0xFFFFFFFF800030EF,"slab_free"},
{ 0xFFFFFFFF8000313B,"slab_realloc"},
{ 0xFFFFFFFF8000321F,"inner_alloc"},
{ 0xFFFFFFFF800032DA,"pmm_init"},
{ 0xFFFFFFFF800034F3,"pmm_alloc_nozero"},
{ 0xFFFFFFFF80003539,"pmm_alloc"},
{ 0xFFFFFFFF80003577,"pmm_free"},
{ 0xFFFFFFFF800035B9,"GetIsrExceptionList"},
{ 0xFFFFFFFF800035C1,"IsrInstallGates"},
{ 0xFFFFFFFF80004A8F,"ISR_Init"},
{ 0xFFFFFFFF80004AC9,"ISR_Handler"},
{ 0xFFFFFFFF80004B5D,"ISR_RegisterHandler"},
{ 0xFFFFFFFF80004B73,"Regs2ISRState"},
{ 0xFFFFFFFF80004CD8,"SetGDTEntry"},
{ 0xFFFFFFFF80004D25,"InitializeGDT"},
{ 0xFFFFFFFF80004E62,"bump_alloc"},
{ 0xFFFFFFFF80004E89,"flanterm_fb_save_state"},
{ 0xFFFFFFFF80004EBE,"flanterm_fb_restore_state"},
{ 0xFFFFFFFF80004EF3,"flanterm_fb_swap_palette"},
{ 0xFFFFFFFF80004F0C,"plot_char"},
{ 0xFFFFFFFF80005097,"push_to_queue"},
{ 0xFFFFFFFF80005139,"flanterm_fb_revscroll"},
{ 0xFFFFFFFF80005229,"flanterm_fb_scroll"},
{ 0xFFFFFFFF8000530B,"flanterm_fb_clear"},
{ 0xFFFFFFFF800053B2,"flanterm_fb_set_cursor_pos"},
{ 0xFFFFFFFF800053F7,"flanterm_fb_get_cursor_pos"},
{ 0xFFFFFFFF80005433,"flanterm_fb_move_character"},
{ 0xFFFFFFFF8000549F,"flanterm_fb_set_text_fg"},
{ 0xFFFFFFFF800054AD,"flanterm_fb_set_text_bg"},
{ 0xFFFFFFFF800054BB,"flanterm_fb_set_text_fg_bright"},
{ 0xFFFFFFFF800054C9,"flanterm_fb_set_text_bg_bright"},
{ 0xFFFFFFFF800054D7,"flanterm_fb_set_text_fg_rgb"},
{ 0xFFFFFFFF800054DE,"flanterm_fb_set_text_bg_rgb"},
{ 0xFFFFFFFF800054E5,"flanterm_fb_set_text_fg_default"},
{ 0xFFFFFFFF800054F2,"flanterm_fb_set_text_bg_default"},
{ 0xFFFFFFFF800054FD,"flanterm_fb_set_text_fg_default_bright"},
{ 0xFFFFFFFF8000550A,"flanterm_fb_set_text_bg_default_bright"},
{ 0xFFFFFFFF80005517,"draw_cursor"},
{ 0xFFFFFFFF800055F4,"flanterm_fb_double_buffer_flush"},
{ 0xFFFFFFFF80005907,"flanterm_fb_raw_putchar"},
{ 0xFFFFFFFF800059CA,"flanterm_fb_full_refresh"},
{ 0xFFFFFFFF80005ABD,"flanterm_fb_deinit"},
{ 0xFFFFFFFF80005B4A,"flanterm_fb_init"},
{ 0xFFFFFFFF800063A1,"flanterm_context_reinit"},
{ 0xFFFFFFFF8000644F,"mk_wcwidth"},
{ 0xFFFFFFFF80006585,"flanterm_write"},
{ 0xFFFFFFFF80008326,"Fb_GetStreamType"},
{ 0xFFFFFFFF8000832D,"Fb_SwitchStream"},
{ 0xFFFFFFFF8000834F,"_FbPutString"},
{ 0xFFFFFFFF80008378,"ClearFbScreen"},
{ 0xFFFFFFFF8000838A,"_FbPutChar"},
{ 0xFFFFFFFF800083E2,"_putchar"},
{ 0xFFFFFFFF800083F6,"InitializeFramebuffers"},
{ 0xFFFFFFFF80008400,"IRQ0"},
{ 0xFFFFFFFF80008410,"IRQ1"},
{ 0xFFFFFFFF80008420,"IRQ2"},
{ 0xFFFFFFFF80008430,"IRQ3"},
{ 0xFFFFFFFF80008440,"IRQ4"},
{ 0xFFFFFFFF80008450,"IRQ5"},
{ 0xFFFFFFFF80008460,"IRQ6"},
{ 0xFFFFFFFF80008470,"IRQ7"},
{ 0xFFFFFFFF80008480,"IRQ8"},
{ 0xFFFFFFFF80008490,"IRQ9"},
{ 0xFFFFFFFF800084A0,"IRQ10"},
{ 0xFFFFFFFF800084B0,"IRQ11"},
{ 0xFFFFFFFF800084C0,"IRQ12"},
{ 0xFFFFFFFF800084D0,"IRQ13"},
{ 0xFFFFFFFF800084E0,"IRQ14"},
{ 0xFFFFFFFF800084F0,"IRQ15"},
{ 0xFFFFFFFF80008500,"irqHandlers"},
{ 0xFFFFFFFF80008580,"isr_common"},
{ 0xFFFFFFFF800085C0,"X64_ISR0"},
{ 0xFFFFFFFF800085C6,"X64_ISR1"},
{ 0xFFFFFFFF800085CC,"X64_ISR2"},
{ 0xFFFFFFFF800085D2,"X64_ISR3"},
{ 0xFFFFFFFF800085D8,"X64_ISR4"},
{ 0xFFFFFFFF800085DE,"X64_ISR5"},
{ 0xFFFFFFFF800085E4,"X64_ISR6"},
{ 0xFFFFFFFF800085EA,"X64_ISR7"},
{ 0xFFFFFFFF800085F0,"X64_ISR8"},
{ 0xFFFFFFFF800085F4,"X64_ISR9"},
{ 0xFFFFFFFF800085FA,"X64_ISR10"},
{ 0xFFFFFFFF800085FE,"X64_ISR11"},
{ 0xFFFFFFFF80008605,"X64_ISR12"},
{ 0xFFFFFFFF8000860C,"X64_ISR13"},
{ 0xFFFFFFFF80008613,"X64_ISR14"},
{ 0xFFFFFFFF8000861A,"X64_ISR15"},
{ 0xFFFFFFFF80008623,"X64_ISR16"},
{ 0xFFFFFFFF8000862C,"X64_ISR17"},
{ 0xFFFFFFFF80008633,"X64_ISR18"},
{ 0xFFFFFFFF8000863C,"X64_ISR19"},
{ 0xFFFFFFFF80008645,"X64_ISR20"},
{ 0xFFFFFFFF8000864E,"X64_ISR21"},
{ 0xFFFFFFFF80008655,"X64_ISR22"},
{ 0xFFFFFFFF8000865E,"X64_ISR23"},
{ 0xFFFFFFFF80008667,"X64_ISR24"},
{ 0xFFFFFFFF80008670,"X64_ISR25"},
{ 0xFFFFFFFF80008679,"X64_ISR26"},
{ 0xFFFFFFFF80008682,"X64_ISR27"},
{ 0xFFFFFFFF8000868B,"X64_ISR28"},
{ 0xFFFFFFFF80008694,"X64_ISR29"},
{ 0xFFFFFFFF8000869D,"X64_ISR30"},
{ 0xFFFFFFFF800086A6,"X64_ISR31"},
{ 0xFFFFFFFF800086AF,"X64_ISR32"},
{ 0xFFFFFFFF800086B8,"X64_ISR33"},
{ 0xFFFFFFFF800086C1,"X64_ISR34"},
{ 0xFFFFFFFF800086CA,"X64_ISR35"},
{ 0xFFFFFFFF800086D3,"X64_ISR36"},
{ 0xFFFFFFFF800086DC,"X64_ISR37"},
{ 0xFFFFFFFF800086E5,"X64_ISR38"},
{ 0xFFFFFFFF800086EE,"X64_ISR39"},
{ 0xFFFFFFFF800086F7,"X64_ISR40"},
{ 0xFFFFFFFF80008700,"X64_ISR41"},
{ 0xFFFFFFFF80008709,"X64_ISR42"},
{ 0xFFFFFFFF80008712,"X64_ISR43"},
{ 0xFFFFFFFF8000871B,"X64_ISR44"},
{ 0xFFFFFFFF80008724,"X64_ISR45"},
{ 0xFFFFFFFF8000872D,"X64_ISR46"},
{ 0xFFFFFFFF80008736,"X64_ISR47"},
{ 0xFFFFFFFF8000873F,"X64_ISR48"},
{ 0xFFFFFFFF80008748,"X64_ISR49"},
{ 0xFFFFFFFF80008751,"X64_ISR50"},
{ 0xFFFFFFFF8000875A,"X64_ISR51"},
{ 0xFFFFFFFF80008763,"X64_ISR52"},
{ 0xFFFFFFFF8000876C,"X64_ISR53"},
{ 0xFFFFFFFF80008775,"X64_ISR54"},
{ 0xFFFFFFFF8000877E,"X64_ISR55"},
{ 0xFFFFFFFF80008787,"X64_ISR56"},
{ 0xFFFFFFFF80008790,"X64_ISR57"},
{ 0xFFFFFFFF80008799,"X64_ISR58"},
{ 0xFFFFFFFF800087A2,"X64_ISR59"},
{ 0xFFFFFFFF800087AB,"X64_ISR60"},
{ 0xFFFFFFFF800087B4,"X64_ISR61"},
{ 0xFFFFFFFF800087BD,"X64_ISR62"},
{ 0xFFFFFFFF800087C6,"X64_ISR63"},
{ 0xFFFFFFFF800087CF,"X64_ISR64"},
{ 0xFFFFFFFF800087D8,"X64_ISR65"},
{ 0xFFFFFFFF800087E1,"X64_ISR66"},
{ 0xFFFFFFFF800087EA,"X64_ISR67"},
{ 0xFFFFFFFF800087F3,"X64_ISR68"},
{ 0xFFFFFFFF800087FC,"X64_ISR69"},
{ 0xFFFFFFFF80008805,"X64_ISR70"},
{ 0xFFFFFFFF8000880E,"X64_ISR71"},
{ 0xFFFFFFFF80008817,"X64_ISR72"},
{ 0xFFFFFFFF80008820,"X64_ISR73"},
{ 0xFFFFFFFF80008829,"X64_ISR74"},
{ 0xFFFFFFFF80008832,"X64_ISR75"},
{ 0xFFFFFFFF8000883B,"X64_ISR76"},
{ 0xFFFFFFFF80008844,"X64_ISR77"},
{ 0xFFFFFFFF8000884D,"X64_ISR78"},
{ 0xFFFFFFFF80008856,"X64_ISR79"},
{ 0xFFFFFFFF8000885F,"X64_ISR80"},
{ 0xFFFFFFFF80008868,"X64_ISR81"},
{ 0xFFFFFFFF80008871,"X64_ISR82"},
{ 0xFFFFFFFF8000887A,"X64_ISR83"},
{ 0xFFFFFFFF80008883,"X64_ISR84"},
{ 0xFFFFFFFF8000888C,"X64_ISR85"},
{ 0xFFFFFFFF80008895,"X64_ISR86"},
{ 0xFFFFFFFF8000889E,"X64_ISR87"},
{ 0xFFFFFFFF800088A7,"X64_ISR88"},
{ 0xFFFFFFFF800088B0,"X64_ISR89"},
{ 0xFFFFFFFF800088B9,"X64_ISR90"},
{ 0xFFFFFFFF800088C2,"X64_ISR91"},
{ 0xFFFFFFFF800088CB,"X64_ISR92"},
{ 0xFFFFFFFF800088D4,"X64_ISR93"},
{ 0xFFFFFFFF800088DD,"X64_ISR94"},
{ 0xFFFFFFFF800088E6,"X64_ISR95"},
{ 0xFFFFFFFF800088EF,"X64_ISR96"},
{ 0xFFFFFFFF800088F8,"X64_ISR97"},
{ 0xFFFFFFFF80008901,"X64_ISR98"},
{ 0xFFFFFFFF8000890A,"X64_ISR99"},
{ 0xFFFFFFFF80008913,"X64_ISR100"},
{ 0xFFFFFFFF8000891C,"X64_ISR101"},
{ 0xFFFFFFFF80008925,"X64_ISR102"},
{ 0xFFFFFFFF8000892E,"X64_ISR103"},
{ 0xFFFFFFFF80008937,"X64_ISR104"},
{ 0xFFFFFFFF80008940,"X64_ISR105"},
{ 0xFFFFFFFF80008949,"X64_ISR106"},
{ 0xFFFFFFFF80008952,"X64_ISR107"},
{ 0xFFFFFFFF8000895B,"X64_ISR108"},
{ 0xFFFFFFFF80008964,"X64_ISR109"},
{ 0xFFFFFFFF8000896D,"X64_ISR110"},
{ 0xFFFFFFFF80008976,"X64_ISR111"},
{ 0xFFFFFFFF8000897F,"X64_ISR112"},
{ 0xFFFFFFFF80008988,"X64_ISR113"},
{ 0xFFFFFFFF80008991,"X64_ISR114"},
{ 0xFFFFFFFF8000899A,"X64_ISR115"},
{ 0xFFFFFFFF800089A3,"X64_ISR116"},
{ 0xFFFFFFFF800089AC,"X64_ISR117"},
{ 0xFFFFFFFF800089B5,"X64_ISR118"},
{ 0xFFFFFFFF800089BE,"X64_ISR119"},
{ 0xFFFFFFFF800089C7,"X64_ISR120"},
{ 0xFFFFFFFF800089D0,"X64_ISR121"},
{ 0xFFFFFFFF800089D9,"X64_ISR122"},
{ 0xFFFFFFFF800089E2,"X64_ISR123"},
{ 0xFFFFFFFF800089EB,"X64_ISR124"},
{ 0xFFFFFFFF800089F4,"X64_ISR125"},
{ 0xFFFFFFFF800089FD,"X64_ISR126"},
{ 0xFFFFFFFF80008A06,"X64_ISR127"},
{ 0xFFFFFFFF80008A0F,"X64_ISR128"},
{ 0xFFFFFFFF80008A1B,"X64_ISR129"},
{ 0xFFFFFFFF80008A27,"X64_ISR130"},
{ 0xFFFFFFFF80008A33,"X64_ISR131"},
{ 0xFFFFFFFF80008A3F,"X64_ISR132"},
{ 0xFFFFFFFF80008A4B,"X64_ISR133"},
{ 0xFFFFFFFF80008A57,"X64_ISR134"},
{ 0xFFFFFFFF80008A63,"X64_ISR135"},
{ 0xFFFFFFFF80008A6F,"X64_ISR136"},
{ 0xFFFFFFFF80008A7B,"X64_ISR137"},
{ 0xFFFFFFFF80008A87,"X64_ISR138"},
{ 0xFFFFFFFF80008A93,"X64_ISR139"},
{ 0xFFFFFFFF80008A9F,"X64_ISR140"},
{ 0xFFFFFFFF80008AAB,"X64_ISR141"},
{ 0xFFFFFFFF80008AB7,"X64_ISR142"},
{ 0xFFFFFFFF80008AC3,"X64_ISR143"},
{ 0xFFFFFFFF80008ACF,"X64_ISR144"},
{ 0xFFFFFFFF80008ADB,"X64_ISR145"},
{ 0xFFFFFFFF80008AE7,"X64_ISR146"},
{ 0xFFFFFFFF80008AF3,"X64_ISR147"},
{ 0xFFFFFFFF80008AFF,"X64_ISR148"},
{ 0xFFFFFFFF80008B0B,"X64_ISR149"},
{ 0xFFFFFFFF80008B17,"X64_ISR150"},
{ 0xFFFFFFFF80008B23,"X64_ISR151"},
{ 0xFFFFFFFF80008B2F,"X64_ISR152"},
{ 0xFFFFFFFF80008B3B,"X64_ISR153"},
{ 0xFFFFFFFF80008B47,"X64_ISR154"},
{ 0xFFFFFFFF80008B53,"X64_ISR155"},
{ 0xFFFFFFFF80008B5F,"X64_ISR156"},
{ 0xFFFFFFFF80008B6B,"X64_ISR157"},
{ 0xFFFFFFFF80008B77,"X64_ISR158"},
{ 0xFFFFFFFF80008B83,"X64_ISR159"},
{ 0xFFFFFFFF80008B8F,"X64_ISR160"},
{ 0xFFFFFFFF80008B9B,"X64_ISR161"},
{ 0xFFFFFFFF80008BA7,"X64_ISR162"},
{ 0xFFFFFFFF80008BB3,"X64_ISR163"},
{ 0xFFFFFFFF80008BBF,"X64_ISR164"},
{ 0xFFFFFFFF80008BCB,"X64_ISR165"},
{ 0xFFFFFFFF80008BD7,"X64_ISR166"},
{ 0xFFFFFFFF80008BE3,"X64_ISR167"},
{ 0xFFFFFFFF80008BEF,"X64_ISR168"},
{ 0xFFFFFFFF80008BFB,"X64_ISR169"},
{ 0xFFFFFFFF80008C07,"X64_ISR170"},
{ 0xFFFFFFFF80008C13,"X64_ISR171"},
{ 0xFFFFFFFF80008C1F,"X64_ISR172"},
{ 0xFFFFFFFF80008C2B,"X64_ISR173"},
{ 0xFFFFFFFF80008C37,"X64_ISR174"},
{ 0xFFFFFFFF80008C43,"X64_ISR175"},
{ 0xFFFFFFFF80008C4F,"X64_ISR176"},
{ 0xFFFFFFFF80008C5B,"X64_ISR177"},
{ 0xFFFFFFFF80008C67,"X64_ISR178"},
{ 0xFFFFFFFF80008C73,"X64_ISR179"},
{ 0xFFFFFFFF80008C7F,"X64_ISR180"},
{ 0xFFFFFFFF80008C8B,"X64_ISR181"},
{ 0xFFFFFFFF80008C97,"X64_ISR182"},
{ 0xFFFFFFFF80008CA3,"X64_ISR183"},
{ 0xFFFFFFFF80008CAF,"X64_ISR184"},
{ 0xFFFFFFFF80008CBB,"X64_ISR185"},
{ 0xFFFFFFFF80008CC7,"X64_ISR186"},
{ 0xFFFFFFFF80008CD3,"X64_ISR187"},
{ 0xFFFFFFFF80008CDF,"X64_ISR188"},
{ 0xFFFFFFFF80008CEB,"X64_ISR189"},
{ 0xFFFFFFFF80008CF7,"X64_ISR190"},
{ 0xFFFFFFFF80008D03,"X64_ISR191"},
{ 0xFFFFFFFF80008D0F,"X64_ISR192"},
{ 0xFFFFFFFF80008D1B,"X64_ISR193"},
{ 0xFFFFFFFF80008D27,"X64_ISR194"},
{ 0xFFFFFFFF80008D33,"X64_ISR195"},
{ 0xFFFFFFFF80008D3F,"X64_ISR196"},
{ 0xFFFFFFFF80008D4B,"X64_ISR197"},
{ 0xFFFFFFFF80008D57,"X64_ISR198"},
{ 0xFFFFFFFF80008D63,"X64_ISR199"},
{ 0xFFFFFFFF80008D6F,"X64_ISR200"},
{ 0xFFFFFFFF80008D7B,"X64_ISR201"},
{ 0xFFFFFFFF80008D87,"X64_ISR202"},
{ 0xFFFFFFFF80008D93,"X64_ISR203"},
{ 0xFFFFFFFF80008D9F,"X64_ISR204"},
{ 0xFFFFFFFF80008DAB,"X64_ISR205"},
{ 0xFFFFFFFF80008DB7,"X64_ISR206"},
{ 0xFFFFFFFF80008DC3,"X64_ISR207"},
{ 0xFFFFFFFF80008DCF,"X64_ISR208"},
{ 0xFFFFFFFF80008DDB,"X64_ISR209"},
{ 0xFFFFFFFF80008DE7,"X64_ISR210"},
{ 0xFFFFFFFF80008DF3,"X64_ISR211"},
{ 0xFFFFFFFF80008DFF,"X64_ISR212"},
{ 0xFFFFFFFF80008E0B,"X64_ISR213"},
{ 0xFFFFFFFF80008E17,"X64_ISR214"},
{ 0xFFFFFFFF80008E23,"X64_ISR215"},
{ 0xFFFFFFFF80008E2F,"X64_ISR216"},
{ 0xFFFFFFFF80008E3B,"X64_ISR217"},
{ 0xFFFFFFFF80008E47,"X64_ISR218"},
{ 0xFFFFFFFF80008E53,"X64_ISR219"},
{ 0xFFFFFFFF80008E5F,"X64_ISR220"},
{ 0xFFFFFFFF80008E6B,"X64_ISR221"},
{ 0xFFFFFFFF80008E77,"X64_ISR222"},
{ 0xFFFFFFFF80008E83,"X64_ISR223"},
{ 0xFFFFFFFF80008E8F,"X64_ISR224"},
{ 0xFFFFFFFF80008E9B,"X64_ISR225"},
{ 0xFFFFFFFF80008EA7,"X64_ISR226"},
{ 0xFFFFFFFF80008EB3,"X64_ISR227"},
{ 0xFFFFFFFF80008EBF,"X64_ISR228"},
{ 0xFFFFFFFF80008ECB,"X64_ISR229"},
{ 0xFFFFFFFF80008ED7,"X64_ISR230"},
{ 0xFFFFFFFF80008EE3,"X64_ISR231"},
{ 0xFFFFFFFF80008EEF,"X64_ISR232"},
{ 0xFFFFFFFF80008EFB,"X64_ISR233"},
{ 0xFFFFFFFF80008F07,"X64_ISR234"},
{ 0xFFFFFFFF80008F13,"X64_ISR235"},
{ 0xFFFFFFFF80008F1F,"X64_ISR236"},
{ 0xFFFFFFFF80008F2B,"X64_ISR237"},
{ 0xFFFFFFFF80008F37,"X64_ISR238"},
{ 0xFFFFFFFF80008F43,"X64_ISR239"},
{ 0xFFFFFFFF80008F4F,"X64_ISR240"},
{ 0xFFFFFFFF80008F5B,"X64_ISR241"},
{ 0xFFFFFFFF80008F67,"X64_ISR242"},
{ 0xFFFFFFFF80008F73,"X64_ISR243"},
{ 0xFFFFFFFF80008F7F,"X64_ISR244"},
{ 0xFFFFFFFF80008F8B,"X64_ISR245"},
{ 0xFFFFFFFF80008F97,"X64_ISR246"},
{ 0xFFFFFFFF80008FA3,"X64_ISR247"},
{ 0xFFFFFFFF80008FAF,"X64_ISR248"},
{ 0xFFFFFFFF80008FBB,"X64_ISR249"},
{ 0xFFFFFFFF80008FC7,"X64_ISR250"},
{ 0xFFFFFFFF80008FD3,"X64_ISR251"},
{ 0xFFFFFFFF80008FDF,"X64_ISR252"},
{ 0xFFFFFFFF80008FEB,"X64_ISR253"},
{ 0xFFFFFFFF80008FF7,"X64_ISR254"},
{ 0xFFFFFFFF80009003,"X64_ISR255"},
{ 0xFFFFFFFF80009010,"x64_enable_sse"},
{ 0xFFFFFFFF80009021,"x64_enable_fpu"},
{ 0xFFFFFFFF8000903F,"x64_enable_avx"},
{ 0xFFFFFFFF8000904B,"x64_cpu_stop"},
{ 0xFFFFFFFF8000904F,"x64_EnableInterrupts"},
{ 0xFFFFFFFF80009051,"x64_DisableInterrupts"},
{ 0xFFFFFFFF80009053,"x64_outb"},
{ 0xFFFFFFFF8000905B,"x64_inb"},
{ 0xFFFFFFFF80009060,"x64_insb"},
{ 0xFFFFFFFF8000906D,"x64_insw"},
{ 0xFFFFFFFF8000907B,"x64_outsb"},
{ 0xFFFFFFFF80009088,"x64_outsw"},
{ 0xFFFFFFFF80009096,"x64_load_idt"},
{ 0xFFFFFFFF800090A2,"x64_gdt_flush"},
{ 0xFFFFFFFF800090BD,"x64_tss_flush"},
{ 0xFFFFFFFF800090C5,"x64_rdump"},
{ 0xFFFFFFFF80009101,"x64_panic"},
{ 0xFFFFFFFF80009105,"kmain"},
{NULL, NULL}
};
#pragma GCC diagnostic pop
