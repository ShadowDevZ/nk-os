//This file has been generated by symgen.py
#include "kstdio.h"
#include "ksyms.h"
#include <stddef.h>


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Wmissing-braces"
const KsymList __symbols__[] = {
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
{ 0xFFFFFFFF8000033C,"DumpSymbolTable"},
{ 0xFFFFFFFF8000038E,"IsValidFlag"},
{ 0xFFFFFFFF800003A3,"strcmp"},
{ 0xFFFFFFFF800003C6,"strncmp"},
{ 0xFFFFFFFF800003F9,"strncpy"},
{ 0xFFFFFFFF8000043F,"memcpy"},
{ 0xFFFFFFFF8000045F,"memset"},
{ 0xFFFFFFFF8000047A,"memmove"},
{ 0xFFFFFFFF800004B6,"memcmp"},
{ 0xFFFFFFFF800004E9,"strlen"},
{ 0xFFFFFFFF80000504,"strncat"},
{ 0xFFFFFFFF80000559,"itoa"},
{ 0xFFFFFFFF800005D5,"debugf"},
{ 0xFFFFFFFF800006B2,"BroadcastPrintf"},
{ 0xFFFFFFFF8000078F,"BroadcastPuts"},
{ 0xFFFFFFFF800007C7,"BroadcastPutc"},
{ 0xFFFFFFFF80000803,"debugs"},
{ 0xFFFFFFFF8000083B,"putchar"},
{ 0xFFFFFFFF80000877,"toupper"},
{ 0xFFFFFFFF80000886,"clrscr"},
{ 0xFFFFFFFF80000896,"_out_buffer"},
{ 0xFFFFFFFF800008A0,"_out_null"},
{ 0xFFFFFFFF800008A1,"_out_fct"},
{ 0xFFFFFFFF800008BA,"_out_rev"},
{ 0xFFFFFFFF800009BE,"_ntoa_format"},
{ 0xFFFFFFFF80000B5B,"_ntoa_long"},
{ 0xFFFFFFFF80000C28,"_ntoa_long_long"},
{ 0xFFFFFFFF80000CF5,"_etoa"},
{ 0xFFFFFFFF800010AB,"_ftoa"},
{ 0xFFFFFFFF800014F1,"_out_char"},
{ 0xFFFFFFFF80001506,"_vsnprintf"},
{ 0xFFFFFFFF8000201F,"printf_"},
{ 0xFFFFFFFF800020C4,"sprintf_"},
{ 0xFFFFFFFF8000215E,"snprintf_"},
{ 0xFFFFFFFF800021ED,"vprintf_"},
{ 0xFFFFFFFF80002214,"vsnprintf_"},
{ 0xFFFFFFFF80002232,"fctprintf"},
{ 0xFFFFFFFF800022D7,"_start"},
{ 0xFFFFFFFF80002649,"page_fault_handler"},
{ 0xFFFFFFFF80002713,"gpf_handler"},
{ 0xFFFFFFFF800027C3,"kmain"},
{ 0xFFFFFFFF80002AF4,"_timercb_internal_"},
{ 0xFFFFFFFF80002B1F,"PIT_SetFrequency"},
{ 0xFFFFFFFF80002B65,"PIT_Init"},
{ 0xFFFFFFFF80002B86,"GetSystemTicks"},
{ 0xFFFFFFFF80002B8E,"kusleep"},
{ 0xFFFFFFFF80002BAB,"SetKbctlEvent"},
{ 0xFFFFFFFF80002BDF,"GetKbctl"},
{ 0xFFFFFFFF80002BE7,"GetKbctlEvent"},
{ 0xFFFFFFFF80002BF4,"_keyboardcb_"},
{ 0xFFFFFFFF80002EF8,"KeyboardInit"},
{ 0xFFFFFFFF80002F1C,"GetRawKeyboardFlags"},
{ 0xFFFFFFFF80002F23,"IRQ_RegisterHandler"},
{ 0xFFFFFFFF80002F30,"IRQ_SendEOI"},
{ 0xFFFFFFFF80002F5C,"IRQ_Handler"},
{ 0xFFFFFFFF80002FB0,"DebugPageFault"},
{ 0xFFFFFFFF80002FDB,"PrintRegs"},
{ 0xFFFFFFFF8000307C,"_SystemRaiseHardError"},
{ 0xFFFFFFFF8000320C,"InitializeIDT"},
{ 0xFFFFFFFF800032DE,"IDT_SetGate"},
{ 0xFFFFFFFF80003325,"IDT_EnableGate"},
{ 0xFFFFFFFF80003334,"IDT_DisableGate"},
{ 0xFFFFFFFF80003343,"kmalloc"},
{ 0xFFFFFFFF800036B1,"kfree"},
{ 0xFFFFFFFF8000395D,"kcalloc"},
{ 0xFFFFFFFF80003997,"krealloc"},
{ 0xFFFFFFFF80003A6E,"PmmIsInitialized"},
{ 0xFFFFFFFF80003A8E,"GetKernelPageSize"},
{ 0xFFFFFFFF80003A96,"PmmLock"},
{ 0xFFFFFFFF80003AC3,"PmmUnlock"},
{ 0xFFFFFFFF80003AF0,"SetKernelPageSize"},
{ 0xFFFFFFFF80003B2A,"PmmUnstash"},
{ 0xFFFFFFFF80003C40,"PmmInit"},
{ 0xFFFFFFFF80003E29,"_AllocPage"},
{ 0xFFFFFFFF80003F1F,"PmmAllocPage"},
{ 0xFFFFFFFF8000401C,"PageFromAddr"},
{ 0xFFFFFFFF80004039,"PmmFreePage"},
{ 0xFFFFFFFF800040C4,"liballoc_lock"},
{ 0xFFFFFFFF800040D9,"liballoc_unlock"},
{ 0xFFFFFFFF800040EE,"liballoc_alloc"},
{ 0xFFFFFFFF800040F9,"liballoc_free"},
{ 0xFFFFFFFF80004109,"GetIsrExceptionList"},
{ 0xFFFFFFFF80004111,"IsrsGateSetup"},
{ 0xFFFFFFFF800041C9,"ISR_Init"},
{ 0xFFFFFFFF800041F9,"ISR_Handler"},
{ 0xFFFFFFFF8000427F,"ISR_RegisterHandler"},
{ 0xFFFFFFFF80004295,"Regs2ISRState"},
{ 0xFFFFFFFF80004420,"CS2DPL"},
{ 0xFFFFFFFF8000443D,"SetGDTEntry"},
{ 0xFFFFFFFF8000448C,"InitializeGDT"},
{ 0xFFFFFFFF800045C9,"SmbiosChecksum"},
{ 0xFFFFFFFF800045F1,"InitSMBIOS"},
{ 0xFFFFFFFF800046FC,"GetSMBIOSTable"},
{ 0xFFFFFFFF80004773,"SmbiosGetStr"},
{ 0xFFFFFFFF8000479C,"bump_alloc"},
{ 0xFFFFFFFF800047C3,"flanterm_fb_save_state"},
{ 0xFFFFFFFF800047F8,"flanterm_fb_restore_state"},
{ 0xFFFFFFFF8000482D,"flanterm_fb_swap_palette"},
{ 0xFFFFFFFF80004846,"plot_char"},
{ 0xFFFFFFFF800049D1,"push_to_queue"},
{ 0xFFFFFFFF80004A72,"flanterm_fb_revscroll"},
{ 0xFFFFFFFF80004B62,"flanterm_fb_scroll"},
{ 0xFFFFFFFF80004C44,"flanterm_fb_clear"},
{ 0xFFFFFFFF80004CEB,"flanterm_fb_set_cursor_pos"},
{ 0xFFFFFFFF80004D30,"flanterm_fb_get_cursor_pos"},
{ 0xFFFFFFFF80004D6C,"flanterm_fb_move_character"},
{ 0xFFFFFFFF80004DD8,"flanterm_fb_set_text_fg"},
{ 0xFFFFFFFF80004DE6,"flanterm_fb_set_text_bg"},
{ 0xFFFFFFFF80004DF4,"flanterm_fb_set_text_fg_bright"},
{ 0xFFFFFFFF80004E02,"flanterm_fb_set_text_bg_bright"},
{ 0xFFFFFFFF80004E10,"flanterm_fb_set_text_fg_rgb"},
{ 0xFFFFFFFF80004E17,"flanterm_fb_set_text_bg_rgb"},
{ 0xFFFFFFFF80004E1E,"flanterm_fb_set_text_fg_default"},
{ 0xFFFFFFFF80004E2B,"flanterm_fb_set_text_bg_default"},
{ 0xFFFFFFFF80004E36,"flanterm_fb_set_text_fg_default_bright"},
{ 0xFFFFFFFF80004E43,"flanterm_fb_set_text_bg_default_bright"},
{ 0xFFFFFFFF80004E50,"draw_cursor"},
{ 0xFFFFFFFF80004F2D,"flanterm_fb_double_buffer_flush"},
{ 0xFFFFFFFF80005240,"flanterm_fb_raw_putchar"},
{ 0xFFFFFFFF80005303,"flanterm_fb_full_refresh"},
{ 0xFFFFFFFF800053F6,"flanterm_fb_deinit"},
{ 0xFFFFFFFF80005483,"flanterm_fb_init"},
{ 0xFFFFFFFF80005CDA,"flanterm_context_reinit"},
{ 0xFFFFFFFF80005D88,"mk_wcwidth"},
{ 0xFFFFFFFF80005EDE,"flanterm_write"},
{ 0xFFFFFFFF80007C86,"Fb_GetStreamType"},
{ 0xFFFFFFFF80007C8D,"Fb_SwitchStream"},
{ 0xFFFFFFFF80007CAF,"_FbPutString"},
{ 0xFFFFFFFF80007CD8,"ClearFbScreen"},
{ 0xFFFFFFFF80007CEA,"_FbPutChar"},
{ 0xFFFFFFFF80007D42,"_putchar"},
{ 0xFFFFFFFF80007D56,"InitializeFramebuffers"},
{ 0xFFFFFFFF80007D60,"X64_IRQ0"},
{ 0xFFFFFFFF80007D71,"X64_IRQ1"},
{ 0xFFFFFFFF80007D82,"X64_IRQ2"},
{ 0xFFFFFFFF80007D93,"X64_IRQ3"},
{ 0xFFFFFFFF80007DA4,"X64_IRQ4"},
{ 0xFFFFFFFF80007DB5,"X64_IRQ5"},
{ 0xFFFFFFFF80007DC6,"X64_IRQ6"},
{ 0xFFFFFFFF80007DD7,"X64_IRQ7"},
{ 0xFFFFFFFF80007DE8,"X64_IRQ8"},
{ 0xFFFFFFFF80007DF9,"X64_IRQ9"},
{ 0xFFFFFFFF80007E0A,"X64_IRQ10"},
{ 0xFFFFFFFF80007E1B,"X64_IRQ11"},
{ 0xFFFFFFFF80007E2C,"X64_IRQ12"},
{ 0xFFFFFFFF80007E3D,"X64_IRQ13"},
{ 0xFFFFFFFF80007E4E,"X64_IRQ14"},
{ 0xFFFFFFFF80007E5F,"X64_IRQ15"},
{ 0xFFFFFFFF80007E70,"irqHandlers"},
{ 0xFFFFFFFF80007EF0,"isr_common"},
{ 0xFFFFFFFF80007F32,"X64_ISR0"},
{ 0xFFFFFFFF80007F38,"X64_ISR1"},
{ 0xFFFFFFFF80007F3E,"X64_ISR2"},
{ 0xFFFFFFFF80007F44,"X64_ISR3"},
{ 0xFFFFFFFF80007F4A,"X64_ISR4"},
{ 0xFFFFFFFF80007F50,"X64_ISR5"},
{ 0xFFFFFFFF80007F56,"X64_ISR6"},
{ 0xFFFFFFFF80007F5C,"X64_ISR7"},
{ 0xFFFFFFFF80007F62,"X64_ISR8"},
{ 0xFFFFFFFF80007F66,"X64_ISR9"},
{ 0xFFFFFFFF80007F6C,"X64_ISR10"},
{ 0xFFFFFFFF80007F70,"X64_ISR11"},
{ 0xFFFFFFFF80007F77,"X64_ISR12"},
{ 0xFFFFFFFF80007F7E,"X64_ISR13"},
{ 0xFFFFFFFF80007F85,"X64_ISR14"},
{ 0xFFFFFFFF80007F8C,"X64_ISR15"},
{ 0xFFFFFFFF80007F95,"X64_ISR16"},
{ 0xFFFFFFFF80007F9E,"X64_ISR17"},
{ 0xFFFFFFFF80007FA5,"X64_ISR18"},
{ 0xFFFFFFFF80007FAE,"X64_ISR19"},
{ 0xFFFFFFFF80007FB7,"X64_ISR20"},
{ 0xFFFFFFFF80007FC0,"X64_ISR21"},
{ 0xFFFFFFFF80007FC7,"X64_ISR22"},
{ 0xFFFFFFFF80007FD0,"X64_ISR23"},
{ 0xFFFFFFFF80007FD9,"X64_ISR24"},
{ 0xFFFFFFFF80007FE2,"X64_ISR25"},
{ 0xFFFFFFFF80007FEB,"X64_ISR26"},
{ 0xFFFFFFFF80007FF4,"X64_ISR27"},
{ 0xFFFFFFFF80007FFD,"X64_ISR28"},
{ 0xFFFFFFFF80008006,"X64_ISR29"},
{ 0xFFFFFFFF8000800F,"X64_ISR30"},
{ 0xFFFFFFFF80008018,"X64_ISR31"},
{ 0xFFFFFFFF80008021,"X64_ISR32"},
{ 0xFFFFFFFF8000802A,"X64_ISR33"},
{ 0xFFFFFFFF80008033,"X64_ISR34"},
{ 0xFFFFFFFF8000803C,"X64_ISR35"},
{ 0xFFFFFFFF80008045,"X64_ISR36"},
{ 0xFFFFFFFF8000804E,"X64_ISR37"},
{ 0xFFFFFFFF80008057,"X64_ISR38"},
{ 0xFFFFFFFF80008060,"X64_ISR39"},
{ 0xFFFFFFFF80008069,"X64_ISR40"},
{ 0xFFFFFFFF80008072,"X64_ISR41"},
{ 0xFFFFFFFF8000807B,"X64_ISR42"},
{ 0xFFFFFFFF80008084,"X64_ISR43"},
{ 0xFFFFFFFF8000808D,"X64_ISR44"},
{ 0xFFFFFFFF80008096,"X64_ISR45"},
{ 0xFFFFFFFF8000809F,"X64_ISR46"},
{ 0xFFFFFFFF800080A8,"X64_ISR47"},
{ 0xFFFFFFFF800080B1,"X64_ISR48"},
{ 0xFFFFFFFF800080BA,"X64_ISR49"},
{ 0xFFFFFFFF800080C3,"X64_ISR50"},
{ 0xFFFFFFFF800080CC,"X64_ISR51"},
{ 0xFFFFFFFF800080D5,"X64_ISR52"},
{ 0xFFFFFFFF800080DE,"X64_ISR53"},
{ 0xFFFFFFFF800080E7,"X64_ISR54"},
{ 0xFFFFFFFF800080F0,"X64_ISR55"},
{ 0xFFFFFFFF800080F9,"X64_ISR56"},
{ 0xFFFFFFFF80008102,"X64_ISR57"},
{ 0xFFFFFFFF8000810B,"X64_ISR58"},
{ 0xFFFFFFFF80008114,"X64_ISR59"},
{ 0xFFFFFFFF8000811D,"X64_ISR60"},
{ 0xFFFFFFFF80008126,"X64_ISR61"},
{ 0xFFFFFFFF8000812F,"X64_ISR62"},
{ 0xFFFFFFFF80008138,"X64_ISR63"},
{ 0xFFFFFFFF80008141,"X64_ISR64"},
{ 0xFFFFFFFF8000814A,"X64_ISR65"},
{ 0xFFFFFFFF80008153,"X64_ISR66"},
{ 0xFFFFFFFF8000815C,"X64_ISR67"},
{ 0xFFFFFFFF80008165,"X64_ISR68"},
{ 0xFFFFFFFF8000816E,"X64_ISR69"},
{ 0xFFFFFFFF80008177,"X64_ISR70"},
{ 0xFFFFFFFF80008180,"X64_ISR71"},
{ 0xFFFFFFFF80008189,"X64_ISR72"},
{ 0xFFFFFFFF80008192,"X64_ISR73"},
{ 0xFFFFFFFF8000819B,"X64_ISR74"},
{ 0xFFFFFFFF800081A4,"X64_ISR75"},
{ 0xFFFFFFFF800081AD,"X64_ISR76"},
{ 0xFFFFFFFF800081B6,"X64_ISR77"},
{ 0xFFFFFFFF800081BF,"X64_ISR78"},
{ 0xFFFFFFFF800081C8,"X64_ISR79"},
{ 0xFFFFFFFF800081D1,"X64_ISR80"},
{ 0xFFFFFFFF800081DA,"X64_ISR81"},
{ 0xFFFFFFFF800081E3,"X64_ISR82"},
{ 0xFFFFFFFF800081EC,"X64_ISR83"},
{ 0xFFFFFFFF800081F5,"X64_ISR84"},
{ 0xFFFFFFFF800081FE,"X64_ISR85"},
{ 0xFFFFFFFF80008207,"X64_ISR86"},
{ 0xFFFFFFFF80008210,"X64_ISR87"},
{ 0xFFFFFFFF80008219,"X64_ISR88"},
{ 0xFFFFFFFF80008222,"X64_ISR89"},
{ 0xFFFFFFFF8000822B,"X64_ISR90"},
{ 0xFFFFFFFF80008234,"X64_ISR91"},
{ 0xFFFFFFFF8000823D,"X64_ISR92"},
{ 0xFFFFFFFF80008246,"X64_ISR93"},
{ 0xFFFFFFFF8000824F,"X64_ISR94"},
{ 0xFFFFFFFF80008258,"X64_ISR95"},
{ 0xFFFFFFFF80008261,"X64_ISR96"},
{ 0xFFFFFFFF8000826A,"X64_ISR97"},
{ 0xFFFFFFFF80008273,"X64_ISR98"},
{ 0xFFFFFFFF8000827C,"X64_ISR99"},
{ 0xFFFFFFFF80008285,"X64_ISR100"},
{ 0xFFFFFFFF8000828E,"X64_ISR101"},
{ 0xFFFFFFFF80008297,"X64_ISR102"},
{ 0xFFFFFFFF800082A0,"X64_ISR103"},
{ 0xFFFFFFFF800082A9,"X64_ISR104"},
{ 0xFFFFFFFF800082B2,"X64_ISR105"},
{ 0xFFFFFFFF800082BB,"X64_ISR106"},
{ 0xFFFFFFFF800082C4,"X64_ISR107"},
{ 0xFFFFFFFF800082CD,"X64_ISR108"},
{ 0xFFFFFFFF800082D6,"X64_ISR109"},
{ 0xFFFFFFFF800082DF,"X64_ISR110"},
{ 0xFFFFFFFF800082E8,"X64_ISR111"},
{ 0xFFFFFFFF800082F1,"X64_ISR112"},
{ 0xFFFFFFFF800082FA,"X64_ISR113"},
{ 0xFFFFFFFF80008303,"X64_ISR114"},
{ 0xFFFFFFFF8000830C,"X64_ISR115"},
{ 0xFFFFFFFF80008315,"X64_ISR116"},
{ 0xFFFFFFFF8000831E,"X64_ISR117"},
{ 0xFFFFFFFF80008327,"X64_ISR118"},
{ 0xFFFFFFFF80008330,"X64_ISR119"},
{ 0xFFFFFFFF80008339,"X64_ISR120"},
{ 0xFFFFFFFF80008342,"X64_ISR121"},
{ 0xFFFFFFFF8000834B,"X64_ISR122"},
{ 0xFFFFFFFF80008354,"X64_ISR123"},
{ 0xFFFFFFFF8000835D,"X64_ISR124"},
{ 0xFFFFFFFF80008366,"X64_ISR125"},
{ 0xFFFFFFFF8000836F,"X64_ISR126"},
{ 0xFFFFFFFF80008378,"X64_ISR127"},
{ 0xFFFFFFFF80008381,"X64_ISR128"},
{ 0xFFFFFFFF8000838D,"X64_ISR129"},
{ 0xFFFFFFFF80008399,"X64_ISR130"},
{ 0xFFFFFFFF800083A5,"X64_ISR131"},
{ 0xFFFFFFFF800083B1,"X64_ISR132"},
{ 0xFFFFFFFF800083BD,"X64_ISR133"},
{ 0xFFFFFFFF800083C9,"X64_ISR134"},
{ 0xFFFFFFFF800083D5,"X64_ISR135"},
{ 0xFFFFFFFF800083E1,"X64_ISR136"},
{ 0xFFFFFFFF800083ED,"X64_ISR137"},
{ 0xFFFFFFFF800083F9,"X64_ISR138"},
{ 0xFFFFFFFF80008405,"X64_ISR139"},
{ 0xFFFFFFFF80008411,"X64_ISR140"},
{ 0xFFFFFFFF8000841D,"X64_ISR141"},
{ 0xFFFFFFFF80008429,"X64_ISR142"},
{ 0xFFFFFFFF80008435,"X64_ISR143"},
{ 0xFFFFFFFF80008441,"X64_ISR144"},
{ 0xFFFFFFFF8000844D,"X64_ISR145"},
{ 0xFFFFFFFF80008459,"X64_ISR146"},
{ 0xFFFFFFFF80008465,"X64_ISR147"},
{ 0xFFFFFFFF80008471,"X64_ISR148"},
{ 0xFFFFFFFF8000847D,"X64_ISR149"},
{ 0xFFFFFFFF80008489,"X64_ISR150"},
{ 0xFFFFFFFF80008495,"X64_ISR151"},
{ 0xFFFFFFFF800084A1,"X64_ISR152"},
{ 0xFFFFFFFF800084AD,"X64_ISR153"},
{ 0xFFFFFFFF800084B9,"X64_ISR154"},
{ 0xFFFFFFFF800084C5,"X64_ISR155"},
{ 0xFFFFFFFF800084D1,"X64_ISR156"},
{ 0xFFFFFFFF800084DD,"X64_ISR157"},
{ 0xFFFFFFFF800084E9,"X64_ISR158"},
{ 0xFFFFFFFF800084F5,"X64_ISR159"},
{ 0xFFFFFFFF80008501,"X64_ISR160"},
{ 0xFFFFFFFF8000850D,"X64_ISR161"},
{ 0xFFFFFFFF80008519,"X64_ISR162"},
{ 0xFFFFFFFF80008525,"X64_ISR163"},
{ 0xFFFFFFFF80008531,"X64_ISR164"},
{ 0xFFFFFFFF8000853D,"X64_ISR165"},
{ 0xFFFFFFFF80008549,"X64_ISR166"},
{ 0xFFFFFFFF80008555,"X64_ISR167"},
{ 0xFFFFFFFF80008561,"X64_ISR168"},
{ 0xFFFFFFFF8000856D,"X64_ISR169"},
{ 0xFFFFFFFF80008579,"X64_ISR170"},
{ 0xFFFFFFFF80008585,"X64_ISR171"},
{ 0xFFFFFFFF80008591,"X64_ISR172"},
{ 0xFFFFFFFF8000859D,"X64_ISR173"},
{ 0xFFFFFFFF800085A9,"X64_ISR174"},
{ 0xFFFFFFFF800085B5,"X64_ISR175"},
{ 0xFFFFFFFF800085C1,"X64_ISR176"},
{ 0xFFFFFFFF800085CD,"X64_ISR177"},
{ 0xFFFFFFFF800085D9,"X64_ISR178"},
{ 0xFFFFFFFF800085E5,"X64_ISR179"},
{ 0xFFFFFFFF800085F1,"X64_ISR180"},
{ 0xFFFFFFFF800085FD,"X64_ISR181"},
{ 0xFFFFFFFF80008609,"X64_ISR182"},
{ 0xFFFFFFFF80008615,"X64_ISR183"},
{ 0xFFFFFFFF80008621,"X64_ISR184"},
{ 0xFFFFFFFF8000862D,"X64_ISR185"},
{ 0xFFFFFFFF80008639,"X64_ISR186"},
{ 0xFFFFFFFF80008645,"X64_ISR187"},
{ 0xFFFFFFFF80008651,"X64_ISR188"},
{ 0xFFFFFFFF8000865D,"X64_ISR189"},
{ 0xFFFFFFFF80008669,"X64_ISR190"},
{ 0xFFFFFFFF80008675,"X64_ISR191"},
{ 0xFFFFFFFF80008681,"X64_ISR192"},
{ 0xFFFFFFFF8000868D,"X64_ISR193"},
{ 0xFFFFFFFF80008699,"X64_ISR194"},
{ 0xFFFFFFFF800086A5,"X64_ISR195"},
{ 0xFFFFFFFF800086B1,"X64_ISR196"},
{ 0xFFFFFFFF800086BD,"X64_ISR197"},
{ 0xFFFFFFFF800086C9,"X64_ISR198"},
{ 0xFFFFFFFF800086D5,"X64_ISR199"},
{ 0xFFFFFFFF800086E1,"X64_ISR200"},
{ 0xFFFFFFFF800086ED,"X64_ISR201"},
{ 0xFFFFFFFF800086F9,"X64_ISR202"},
{ 0xFFFFFFFF80008705,"X64_ISR203"},
{ 0xFFFFFFFF80008711,"X64_ISR204"},
{ 0xFFFFFFFF8000871D,"X64_ISR205"},
{ 0xFFFFFFFF80008729,"X64_ISR206"},
{ 0xFFFFFFFF80008735,"X64_ISR207"},
{ 0xFFFFFFFF80008741,"X64_ISR208"},
{ 0xFFFFFFFF8000874D,"X64_ISR209"},
{ 0xFFFFFFFF80008759,"X64_ISR210"},
{ 0xFFFFFFFF80008765,"X64_ISR211"},
{ 0xFFFFFFFF80008771,"X64_ISR212"},
{ 0xFFFFFFFF8000877D,"X64_ISR213"},
{ 0xFFFFFFFF80008789,"X64_ISR214"},
{ 0xFFFFFFFF80008795,"X64_ISR215"},
{ 0xFFFFFFFF800087A1,"X64_ISR216"},
{ 0xFFFFFFFF800087AD,"X64_ISR217"},
{ 0xFFFFFFFF800087B9,"X64_ISR218"},
{ 0xFFFFFFFF800087C5,"X64_ISR219"},
{ 0xFFFFFFFF800087D1,"X64_ISR220"},
{ 0xFFFFFFFF800087DD,"X64_ISR221"},
{ 0xFFFFFFFF800087E9,"X64_ISR222"},
{ 0xFFFFFFFF800087F5,"X64_ISR223"},
{ 0xFFFFFFFF80008801,"X64_ISR224"},
{ 0xFFFFFFFF8000880D,"X64_ISR225"},
{ 0xFFFFFFFF80008819,"X64_ISR226"},
{ 0xFFFFFFFF80008825,"X64_ISR227"},
{ 0xFFFFFFFF80008831,"X64_ISR228"},
{ 0xFFFFFFFF8000883D,"X64_ISR229"},
{ 0xFFFFFFFF80008849,"X64_ISR230"},
{ 0xFFFFFFFF80008855,"X64_ISR231"},
{ 0xFFFFFFFF80008861,"X64_ISR232"},
{ 0xFFFFFFFF8000886D,"X64_ISR233"},
{ 0xFFFFFFFF80008879,"X64_ISR234"},
{ 0xFFFFFFFF80008885,"X64_ISR235"},
{ 0xFFFFFFFF80008891,"X64_ISR236"},
{ 0xFFFFFFFF8000889D,"X64_ISR237"},
{ 0xFFFFFFFF800088A9,"X64_ISR238"},
{ 0xFFFFFFFF800088B5,"X64_ISR239"},
{ 0xFFFFFFFF800088C1,"X64_ISR240"},
{ 0xFFFFFFFF800088CD,"X64_ISR241"},
{ 0xFFFFFFFF800088D9,"X64_ISR242"},
{ 0xFFFFFFFF800088E5,"X64_ISR243"},
{ 0xFFFFFFFF800088F1,"X64_ISR244"},
{ 0xFFFFFFFF800088FD,"X64_ISR245"},
{ 0xFFFFFFFF80008909,"X64_ISR246"},
{ 0xFFFFFFFF80008915,"X64_ISR247"},
{ 0xFFFFFFFF80008921,"X64_ISR248"},
{ 0xFFFFFFFF8000892D,"X64_ISR249"},
{ 0xFFFFFFFF80008939,"X64_ISR250"},
{ 0xFFFFFFFF80008945,"X64_ISR251"},
{ 0xFFFFFFFF80008951,"X64_ISR252"},
{ 0xFFFFFFFF8000895D,"X64_ISR253"},
{ 0xFFFFFFFF80008969,"X64_ISR254"},
{ 0xFFFFFFFF80008975,"X64_ISR255"},
{ 0xFFFFFFFF80008981,"X64_ISRHANDLERS"},
{ 0xFFFFFFFF80009190,"x64_enable_sse"},
{ 0xFFFFFFFF800091A9,"x64_enable_fpu"},
{ 0xFFFFFFFF800091CF,"x64_enable_avx"},
{ 0xFFFFFFFF800091E3,"x64_cpu_stop"},
{ 0xFFFFFFFF800091E7,"x64_EnableInterrupts"},
{ 0xFFFFFFFF800091E9,"x64_DisableInterrupts"},
{ 0xFFFFFFFF800091EB,"x64_outb"},
{ 0xFFFFFFFF800091FB,"x64_inb"},
{ 0xFFFFFFFF80009208,"x64_insb"},
{ 0xFFFFFFFF8000921D,"x64_insw"},
{ 0xFFFFFFFF80009233,"x64_outsb"},
{ 0xFFFFFFFF80009248,"x64_outsw"},
{ 0xFFFFFFFF8000925E,"x64_load_idt"},
{ 0xFFFFFFFF8000926A,"x64_gdt_flush"},
{ 0xFFFFFFFF80009285,"x64_tss_flush"},
{ 0xFFFFFFFF8000928D,"x64_rdump"},
{ 0xFFFFFFFF800092C9,"x64_panic"},
{ 0xFFFFFFFF800092CD,"x64_cli"},
{ 0xFFFFFFFF800092CF,"x64_sti"},
{ 0xFFFFFFFF800092D1,"x64_rdtsc"},
{ 0xFFFFFFFF800092E5,"x64_readcs"},
{ 0xFFFFFFFF800092F0,"x64_readds"},
{NULL, NULL}
};
#pragma GCC diagnostic pop
