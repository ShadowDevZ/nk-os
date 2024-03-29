//This file has been generated by symgen.py
#include "kstdio.h"
#include "ksyms.h"
#include <stddef.h>


#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Wmissing-braces"
const KsymList __symbols__[] = {
{ 0xFFFFFFFF80000000,"GetBasicKernelVersion"},
{ 0xFFFFFFFF80000000,"__text_start__"},
{ 0xFFFFFFFF8000008F,"GetKernelVersion"},
{ 0xFFFFFFFF8000022D,"NkkGetLastKernelError"},
{ 0xFFFFFFFF8000023A,"NkkTranslateError"},
{ 0xFFFFFFFF8000026F,"NkkSetLastSystemError"},
{ 0xFFFFFFFF800002A6,"KsymCount"},
{ 0xFFFFFFFF800002E3,"KsymFind"},
{ 0xFFFFFFFF80000376,"KsymResolveAddress"},
{ 0xFFFFFFFF800003F7,"KsymEnumSymbol"},
{ 0xFFFFFFFF800004B2,"KsymGetSymbolIndex"},
{ 0xFFFFFFFF8000051B,"DumpSymbolTable"},
{ 0xFFFFFFFF8000057C,"IsValidFlag"},
{ 0xFFFFFFFF800005B5,"strcmp"},
{ 0xFFFFFFFF80000608,"strncmp"},
{ 0xFFFFFFFF80000679,"strncpy"},
{ 0xFFFFFFFF800006E5,"memcpy"},
{ 0xFFFFFFFF80000743,"memset"},
{ 0xFFFFFFFF8000078D,"memmove"},
{ 0xFFFFFFFF8000083A,"memcmp"},
{ 0xFFFFFFFF800008CC,"strlen"},
{ 0xFFFFFFFF80000900,"strstr"},
{ 0xFFFFFFFF80000961,"strncat"},
{ 0xFFFFFFFF800009D4,"itoa"},
{ 0xFFFFFFFF80000AB6,"debugf"},
{ 0xFFFFFFFF80000B9A,"BroadcastPrintf"},
{ 0xFFFFFFFF80000C7E,"BroadcastPuts"},
{ 0xFFFFFFFF80000CB7,"BroadcastPutc"},
{ 0xFFFFFFFF80000CF5,"debugs"},
{ 0xFFFFFFFF80000D2E,"putchar"},
{ 0xFFFFFFFF80000D6C,"toupper"},
{ 0xFFFFFFFF80000D90,"clrscr"},
{ 0xFFFFFFFF80000DA1,"_out_buffer"},
{ 0xFFFFFFFF80000DD8,"_out_null"},
{ 0xFFFFFFFF80000DF4,"_out_char"},
{ 0xFFFFFFFF80000E21,"_out_fct"},
{ 0xFFFFFFFF80000E5D,"_strnlen_s"},
{ 0xFFFFFFFF80000EA2,"_is_digit"},
{ 0xFFFFFFFF80000ECC,"_atoi"},
{ 0xFFFFFFFF80000F2C,"_out_rev"},
{ 0xFFFFFFFF80001035,"_ntoa_format"},
{ 0xFFFFFFFF80001260,"_ntoa_long"},
{ 0xFFFFFFFF80001369,"_ntoa_long_long"},
{ 0xFFFFFFFF80001472,"_ftoa"},
{ 0xFFFFFFFF80001A92,"_etoa"},
{ 0xFFFFFFFF80001F2E,"_vsnprintf"},
{ 0xFFFFFFFF80002EC7,"printf_"},
{ 0xFFFFFFFF80002F8C,"sprintf_"},
{ 0xFFFFFFFF80003051,"snprintf_"},
{ 0xFFFFFFFF80003113,"vprintf_"},
{ 0xFFFFFFFF8000314D,"vsnprintf_"},
{ 0xFFFFFFFF80003189,"fctprintf"},
{ 0xFFFFFFFF8000326A,"flanterm_fb_simple_init"},
{ 0xFFFFFFFF80003329,"SystemRaiseHardError"},
{ 0xFFFFFFFF80003364,"_start"},
{ 0xFFFFFFFF80003680,"page_fault_handler"},
{ 0xFFFFFFFF8000385E,"gpf_handler"},
{ 0xFFFFFFFF80003A15,"InitFaultHandlers"},
{ 0xFFFFFFFF80003A3E,"PmmPhys2Virt"},
{ 0xFFFFFFFF80003A74,"PrintSysRegs"},
{ 0xFFFFFFFF80003AF9,"kmain"},
{ 0xFFFFFFFF80003FCB,"PIT_Init"},
{ 0xFFFFFFFF80003FF4,"PIT_SetFrequency"},
{ 0xFFFFFFFF80004044,"_timercb_internal_"},
{ 0xFFFFFFFF80004065,"GetSystemTicks"},
{ 0xFFFFFFFF80004072,"kusleep"},
{ 0xFFFFFFFF800040BC,"SetKbctlEvent"},
{ 0xFFFFFFFF80004119,"GetKbctl"},
{ 0xFFFFFFFF80004126,"GetKbctlEvent"},
{ 0xFFFFFFFF80004150,"KeyboardInit"},
{ 0xFFFFFFFF80004175,"GetRawKeyboardFlags"},
{ 0xFFFFFFFF80004181,"_keyboardcb_"},
{ 0xFFFFFFFF80004485,"SystemRaiseHardError"},
{ 0xFFFFFFFF800044C0,"IRQ_RegisterHandler"},
{ 0xFFFFFFFF800044E6,"IRQ_SendEOI"},
{ 0xFFFFFFFF80004501,"IRQ_Handler"},
{ 0xFFFFFFFF8000458F,"PIC_SendEOI"},
{ 0xFFFFFFFF800045C3,"pic_write"},
{ 0xFFFFFFFF800045F9,"PIC_Initialize"},
{ 0xFFFFFFFF8000468C,"PIC_DisableIRQ"},
{ 0xFFFFFFFF80004707,"PIC_EnableIRQ"},
{ 0xFFFFFFFF80004786,"PIC_IRQAvailable"},
{ 0xFFFFFFFF800047EA,"PIC_SetMask"},
{ 0xFFFFFFFF8000481A,"Pic_GetMask"},
{ 0xFFFFFFFF80004855,"PIC_Disable"},
{ 0xFFFFFFFF8000487A,"DebugPageFault"},
{ 0xFFFFFFFF800048C3,"_SystemRaiseHardError"},
{ 0xFFFFFFFF80004A91,"PrintRegs"},
{ 0xFFFFFFFF80004C0E,"InitializeIDT"},
{ 0xFFFFFFFF80004C95,"IDT_SetGate"},
{ 0xFFFFFFFF80004D1D,"IDT_SetIST"},
{ 0xFFFFFFFF80004D46,"IDT_DisableIST"},
{ 0xFFFFFFFF80004D66,"IDT_EnableGate"},
{ 0xFFFFFFFF80004D9C,"IDT_DisableGate"},
{ 0xFFFFFFFF80004DD2,"getexp"},
{ 0xFFFFFFFF80004E2B,"liballoc_memset"},
{ 0xFFFFFFFF80004E78,"liballoc_memcpy"},
{ 0xFFFFFFFF80004F0A,"insert_tag"},
{ 0xFFFFFFFF80004FAA,"remove_tag"},
{ 0xFFFFFFFF8000504D,"melt_left"},
{ 0xFFFFFFFF800050B3,"absorb_right"},
{ 0xFFFFFFFF80005125,"split_tag"},
{ 0xFFFFFFFF8000520C,"allocate_new_tag"},
{ 0xFFFFFFFF80005314,"kmalloc"},
{ 0xFFFFFFFF800054D9,"kfree"},
{ 0xFFFFFFFF800056BD,"kcalloc"},
{ 0xFFFFFFFF80005705,"krealloc"},
{ 0xFFFFFFFF800057BE,"bitmap_isset"},
{ 0xFFFFFFFF80005801,"bitmap_setbit"},
{ 0xFFFFFFFF80005849,"bitmap_clearbit"},
{ 0xFFFFFFFF80005893,"SystemRaiseHardError"},
{ 0xFFFFFFFF800058CE,"PmmIsInitialized"},
{ 0xFFFFFFFF80005902,"GetKernelPageSize"},
{ 0xFFFFFFFF8000590F,"PmmLock"},
{ 0xFFFFFFFF80005942,"PmmUnlock"},
{ 0xFFFFFFFF80005975,"SetKernelPageSize"},
{ 0xFFFFFFFF800059BB,"PmmUnstash"},
{ 0xFFFFFFFF80005B93,"PmmInit"},
{ 0xFFFFFFFF80005E44,"_AllocPage"},
{ 0xFFFFFFFF80005F2B,"PmmAllocPageNotEmpty"},
{ 0xFFFFFFFF80006002,"PmmAllocPage"},
{ 0xFFFFFFFF80006055,"PageFromAddr"},
{ 0xFFFFFFFF8000609A,"PmmFreePage"},
{ 0xFFFFFFFF80006135,"liballoc_lock"},
{ 0xFFFFFFFF8000614A,"liballoc_unlock"},
{ 0xFFFFFFFF8000615F,"liballoc_alloc"},
{ 0xFFFFFFFF80006181,"liballoc_free"},
{ 0xFFFFFFFF800061AB,"GetIsrExceptionList"},
{ 0xFFFFFFFF800061B8,"ISRErrorToMessage"},
{ 0xFFFFFFFF800061E6,"ISR_Init"},
{ 0xFFFFFFFF8000621C,"SetGates"},
{ 0xFFFFFFFF80006264,"IsrsGateSetup"},
{ 0xFFFFFFFF80006301,"ISR_Handler"},
{ 0xFFFFFFFF800063DC,"ISR_RegisterHandler"},
{ 0xFFFFFFFF80006409,"CS2DPL"},
{ 0xFFFFFFFF80006434,"SetGDTEntry"},
{ 0xFFFFFFFF800064E9,"InitializeGDT"},
{ 0xFFFFFFFF800066AB,"InitSMBIOS"},
{ 0xFFFFFFFF80006827,"SmbiosChecksum"},
{ 0xFFFFFFFF80006876,"GetSMBIOSTable"},
{ 0xFFFFFFFF80006991,"SmbiosGetStr"},
{ 0xFFFFFFFF800069EF,"bump_alloc"},
{ 0xFFFFFFFF80006A40,"flanterm_fb_save_state"},
{ 0xFFFFFFFF80006AAB,"flanterm_fb_restore_state"},
{ 0xFFFFFFFF80006B16,"flanterm_fb_swap_palette"},
{ 0xFFFFFFFF80006B5B,"plot_char"},
{ 0xFFFFFFFF80006DE9,"compare_char"},
{ 0xFFFFFFFF80006E3E,"push_to_queue"},
{ 0xFFFFFFFF80006F82,"flanterm_fb_revscroll"},
{ 0xFFFFFFFF80007116,"flanterm_fb_scroll"},
{ 0xFFFFFFFF800072A0,"flanterm_fb_clear"},
{ 0xFFFFFFFF8000737A,"flanterm_fb_set_cursor_pos"},
{ 0xFFFFFFFF80007423,"flanterm_fb_get_cursor_pos"},
{ 0xFFFFFFFF800074BE,"flanterm_fb_move_character"},
{ 0xFFFFFFFF800075C6,"flanterm_fb_set_text_fg"},
{ 0xFFFFFFFF800075FE,"flanterm_fb_set_text_bg"},
{ 0xFFFFFFFF80007636,"flanterm_fb_set_text_fg_bright"},
{ 0xFFFFFFFF8000766E,"flanterm_fb_set_text_bg_bright"},
{ 0xFFFFFFFF800076A6,"flanterm_fb_set_text_fg_rgb"},
{ 0xFFFFFFFF800076CD,"flanterm_fb_set_text_bg_rgb"},
{ 0xFFFFFFFF800076F4,"flanterm_fb_set_text_fg_default"},
{ 0xFFFFFFFF8000771F,"flanterm_fb_set_text_bg_default"},
{ 0xFFFFFFFF80007744,"flanterm_fb_set_text_fg_default_bright"},
{ 0xFFFFFFFF8000776F,"flanterm_fb_set_text_bg_default_bright"},
{ 0xFFFFFFFF8000779A,"draw_cursor"},
{ 0xFFFFFFFF8000790E,"flanterm_fb_double_buffer_flush"},
{ 0xFFFFFFFF80007B5A,"flanterm_fb_raw_putchar"},
{ 0xFFFFFFFF80007CB6,"flanterm_fb_full_refresh"},
{ 0xFFFFFFFF80007E2A,"flanterm_fb_deinit"},
{ 0xFFFFFFFF80007F30,"flanterm_fb_init"},
{ 0xFFFFFFFF80008D8C,"flanterm_context_reinit"},
{ 0xFFFFFFFF80008EC4,"flanterm_write"},
{ 0xFFFFFFFF80008F33,"sgr"},
{ 0xFFFFFFFF80009A74,"dec_private_parse"},
{ 0xFFFFFFFF80009B2B,"linux_private_parse"},
{ 0xFFFFFFFF80009B8C,"mode_toggle"},
{ 0xFFFFFFFF80009C2A,"osc_parse"},
{ 0xFFFFFFFF80009C8F,"control_sequence_parse"},
{ 0xFFFFFFFF8000AEAD,"restore_state"},
{ 0xFFFFFFFF8000AF3F,"save_state"},
{ 0xFFFFFFFF8000AFD1,"escape_parse"},
{ 0xFFFFFFFF8000B2E0,"dec_special_print"},
{ 0xFFFFFFFF8000B6DC,"bisearch"},
{ 0xFFFFFFFF8000B79A,"mk_wcwidth"},
{ 0xFFFFFFFF8000B8EC,"unicode_to_cp437"},
{ 0xFFFFFFFF8000C15B,"flanterm_putchar"},
{ 0xFFFFFFFF8000C786,"Fb_GetStreamType"},
{ 0xFFFFFFFF8000C799,"Fb_SwitchStream"},
{ 0xFFFFFFFF8000C7E7,"_FbPutString"},
{ 0xFFFFFFFF8000C81B,"ClearFbScreen"},
{ 0xFFFFFFFF8000C835,"_putchar"},
{ 0xFFFFFFFF8000C855,"_FbPutChar"},
{ 0xFFFFFFFF8000C8D1,"InitializeFramebuffers"},
{ 0xFFFFFFFF8000C8F0,"X64_IRQ0"},
{ 0xFFFFFFFF8000C936,"X64_IRQ1"},
{ 0xFFFFFFFF8000C97C,"X64_IRQ2"},
{ 0xFFFFFFFF8000C9C2,"X64_IRQ3"},
{ 0xFFFFFFFF8000CA08,"X64_IRQ4"},
{ 0xFFFFFFFF8000CA4E,"X64_IRQ5"},
{ 0xFFFFFFFF8000CA94,"X64_IRQ6"},
{ 0xFFFFFFFF8000CADA,"X64_IRQ7"},
{ 0xFFFFFFFF8000CB20,"X64_IRQ8"},
{ 0xFFFFFFFF8000CB66,"X64_IRQ9"},
{ 0xFFFFFFFF8000CBAC,"X64_IRQ10"},
{ 0xFFFFFFFF8000CBF2,"X64_IRQ11"},
{ 0xFFFFFFFF8000CC38,"X64_IRQ12"},
{ 0xFFFFFFFF8000CC7E,"X64_IRQ13"},
{ 0xFFFFFFFF8000CCC4,"X64_IRQ14"},
{ 0xFFFFFFFF8000CD0A,"X64_IRQ15"},
{ 0xFFFFFFFF8000CD50,"irqHandlers"},
{ 0xFFFFFFFF8000CDD0,"isr_common"},
{ 0xFFFFFFFF8000CE12,"X64_ISR0"},
{ 0xFFFFFFFF8000CE18,"X64_ISR1"},
{ 0xFFFFFFFF8000CE1E,"X64_ISR2"},
{ 0xFFFFFFFF8000CE24,"X64_ISR3"},
{ 0xFFFFFFFF8000CE2A,"X64_ISR4"},
{ 0xFFFFFFFF8000CE30,"X64_ISR5"},
{ 0xFFFFFFFF8000CE36,"X64_ISR6"},
{ 0xFFFFFFFF8000CE3C,"X64_ISR7"},
{ 0xFFFFFFFF8000CE42,"X64_ISR8"},
{ 0xFFFFFFFF8000CE46,"X64_ISR9"},
{ 0xFFFFFFFF8000CE4C,"X64_ISR10"},
{ 0xFFFFFFFF8000CE50,"X64_ISR11"},
{ 0xFFFFFFFF8000CE57,"X64_ISR12"},
{ 0xFFFFFFFF8000CE5E,"X64_ISR13"},
{ 0xFFFFFFFF8000CE65,"X64_ISR14"},
{ 0xFFFFFFFF8000CE6C,"X64_ISR15"},
{ 0xFFFFFFFF8000CE75,"X64_ISR16"},
{ 0xFFFFFFFF8000CE7E,"X64_ISR17"},
{ 0xFFFFFFFF8000CE85,"X64_ISR18"},
{ 0xFFFFFFFF8000CE8E,"X64_ISR19"},
{ 0xFFFFFFFF8000CE97,"X64_ISR20"},
{ 0xFFFFFFFF8000CEA0,"X64_ISR21"},
{ 0xFFFFFFFF8000CEA7,"X64_ISR22"},
{ 0xFFFFFFFF8000CEB0,"X64_ISR23"},
{ 0xFFFFFFFF8000CEB9,"X64_ISR24"},
{ 0xFFFFFFFF8000CEC2,"X64_ISR25"},
{ 0xFFFFFFFF8000CECB,"X64_ISR26"},
{ 0xFFFFFFFF8000CED4,"X64_ISR27"},
{ 0xFFFFFFFF8000CEDD,"X64_ISR28"},
{ 0xFFFFFFFF8000CEE6,"X64_ISR29"},
{ 0xFFFFFFFF8000CEEF,"X64_ISR30"},
{ 0xFFFFFFFF8000CEF8,"X64_ISR31"},
{ 0xFFFFFFFF8000CF01,"X64_ISR32"},
{ 0xFFFFFFFF8000CF0A,"X64_ISR33"},
{ 0xFFFFFFFF8000CF13,"X64_ISR34"},
{ 0xFFFFFFFF8000CF1C,"X64_ISR35"},
{ 0xFFFFFFFF8000CF25,"X64_ISR36"},
{ 0xFFFFFFFF8000CF2E,"X64_ISR37"},
{ 0xFFFFFFFF8000CF37,"X64_ISR38"},
{ 0xFFFFFFFF8000CF40,"X64_ISR39"},
{ 0xFFFFFFFF8000CF49,"X64_ISR40"},
{ 0xFFFFFFFF8000CF52,"X64_ISR41"},
{ 0xFFFFFFFF8000CF5B,"X64_ISR42"},
{ 0xFFFFFFFF8000CF64,"X64_ISR43"},
{ 0xFFFFFFFF8000CF6D,"X64_ISR44"},
{ 0xFFFFFFFF8000CF76,"X64_ISR45"},
{ 0xFFFFFFFF8000CF7F,"X64_ISR46"},
{ 0xFFFFFFFF8000CF88,"X64_ISR47"},
{ 0xFFFFFFFF8000CF91,"X64_ISR48"},
{ 0xFFFFFFFF8000CF9A,"X64_ISR49"},
{ 0xFFFFFFFF8000CFA3,"X64_ISR50"},
{ 0xFFFFFFFF8000CFAC,"X64_ISR51"},
{ 0xFFFFFFFF8000CFB5,"X64_ISR52"},
{ 0xFFFFFFFF8000CFBE,"X64_ISR53"},
{ 0xFFFFFFFF8000CFC7,"X64_ISR54"},
{ 0xFFFFFFFF8000CFD0,"X64_ISR55"},
{ 0xFFFFFFFF8000CFD9,"X64_ISR56"},
{ 0xFFFFFFFF8000CFE2,"X64_ISR57"},
{ 0xFFFFFFFF8000CFEB,"X64_ISR58"},
{ 0xFFFFFFFF8000CFF4,"X64_ISR59"},
{ 0xFFFFFFFF8000CFFD,"X64_ISR60"},
{ 0xFFFFFFFF8000D006,"X64_ISR61"},
{ 0xFFFFFFFF8000D00F,"X64_ISR62"},
{ 0xFFFFFFFF8000D018,"X64_ISR63"},
{ 0xFFFFFFFF8000D021,"X64_ISR64"},
{ 0xFFFFFFFF8000D02A,"X64_ISR65"},
{ 0xFFFFFFFF8000D033,"X64_ISR66"},
{ 0xFFFFFFFF8000D03C,"X64_ISR67"},
{ 0xFFFFFFFF8000D045,"X64_ISR68"},
{ 0xFFFFFFFF8000D04E,"X64_ISR69"},
{ 0xFFFFFFFF8000D057,"X64_ISR70"},
{ 0xFFFFFFFF8000D060,"X64_ISR71"},
{ 0xFFFFFFFF8000D069,"X64_ISR72"},
{ 0xFFFFFFFF8000D072,"X64_ISR73"},
{ 0xFFFFFFFF8000D07B,"X64_ISR74"},
{ 0xFFFFFFFF8000D084,"X64_ISR75"},
{ 0xFFFFFFFF8000D08D,"X64_ISR76"},
{ 0xFFFFFFFF8000D096,"X64_ISR77"},
{ 0xFFFFFFFF8000D09F,"X64_ISR78"},
{ 0xFFFFFFFF8000D0A8,"X64_ISR79"},
{ 0xFFFFFFFF8000D0B1,"X64_ISR80"},
{ 0xFFFFFFFF8000D0BA,"X64_ISR81"},
{ 0xFFFFFFFF8000D0C3,"X64_ISR82"},
{ 0xFFFFFFFF8000D0CC,"X64_ISR83"},
{ 0xFFFFFFFF8000D0D5,"X64_ISR84"},
{ 0xFFFFFFFF8000D0DE,"X64_ISR85"},
{ 0xFFFFFFFF8000D0E7,"X64_ISR86"},
{ 0xFFFFFFFF8000D0F0,"X64_ISR87"},
{ 0xFFFFFFFF8000D0F9,"X64_ISR88"},
{ 0xFFFFFFFF8000D102,"X64_ISR89"},
{ 0xFFFFFFFF8000D10B,"X64_ISR90"},
{ 0xFFFFFFFF8000D114,"X64_ISR91"},
{ 0xFFFFFFFF8000D11D,"X64_ISR92"},
{ 0xFFFFFFFF8000D126,"X64_ISR93"},
{ 0xFFFFFFFF8000D12F,"X64_ISR94"},
{ 0xFFFFFFFF8000D138,"X64_ISR95"},
{ 0xFFFFFFFF8000D141,"X64_ISR96"},
{ 0xFFFFFFFF8000D14A,"X64_ISR97"},
{ 0xFFFFFFFF8000D153,"X64_ISR98"},
{ 0xFFFFFFFF8000D15C,"X64_ISR99"},
{ 0xFFFFFFFF8000D165,"X64_ISR100"},
{ 0xFFFFFFFF8000D16E,"X64_ISR101"},
{ 0xFFFFFFFF8000D177,"X64_ISR102"},
{ 0xFFFFFFFF8000D180,"X64_ISR103"},
{ 0xFFFFFFFF8000D189,"X64_ISR104"},
{ 0xFFFFFFFF8000D192,"X64_ISR105"},
{ 0xFFFFFFFF8000D19B,"X64_ISR106"},
{ 0xFFFFFFFF8000D1A4,"X64_ISR107"},
{ 0xFFFFFFFF8000D1AD,"X64_ISR108"},
{ 0xFFFFFFFF8000D1B6,"X64_ISR109"},
{ 0xFFFFFFFF8000D1BF,"X64_ISR110"},
{ 0xFFFFFFFF8000D1C8,"X64_ISR111"},
{ 0xFFFFFFFF8000D1D1,"X64_ISR112"},
{ 0xFFFFFFFF8000D1DA,"X64_ISR113"},
{ 0xFFFFFFFF8000D1E3,"X64_ISR114"},
{ 0xFFFFFFFF8000D1EC,"X64_ISR115"},
{ 0xFFFFFFFF8000D1F5,"X64_ISR116"},
{ 0xFFFFFFFF8000D1FE,"X64_ISR117"},
{ 0xFFFFFFFF8000D207,"X64_ISR118"},
{ 0xFFFFFFFF8000D210,"X64_ISR119"},
{ 0xFFFFFFFF8000D219,"X64_ISR120"},
{ 0xFFFFFFFF8000D222,"X64_ISR121"},
{ 0xFFFFFFFF8000D22B,"X64_ISR122"},
{ 0xFFFFFFFF8000D234,"X64_ISR123"},
{ 0xFFFFFFFF8000D23D,"X64_ISR124"},
{ 0xFFFFFFFF8000D246,"X64_ISR125"},
{ 0xFFFFFFFF8000D24F,"X64_ISR126"},
{ 0xFFFFFFFF8000D258,"X64_ISR127"},
{ 0xFFFFFFFF8000D261,"X64_ISR128"},
{ 0xFFFFFFFF8000D26D,"X64_ISR129"},
{ 0xFFFFFFFF8000D279,"X64_ISR130"},
{ 0xFFFFFFFF8000D285,"X64_ISR131"},
{ 0xFFFFFFFF8000D291,"X64_ISR132"},
{ 0xFFFFFFFF8000D29D,"X64_ISR133"},
{ 0xFFFFFFFF8000D2A9,"X64_ISR134"},
{ 0xFFFFFFFF8000D2B5,"X64_ISR135"},
{ 0xFFFFFFFF8000D2C1,"X64_ISR136"},
{ 0xFFFFFFFF8000D2CD,"X64_ISR137"},
{ 0xFFFFFFFF8000D2D9,"X64_ISR138"},
{ 0xFFFFFFFF8000D2E5,"X64_ISR139"},
{ 0xFFFFFFFF8000D2F1,"X64_ISR140"},
{ 0xFFFFFFFF8000D2FD,"X64_ISR141"},
{ 0xFFFFFFFF8000D309,"X64_ISR142"},
{ 0xFFFFFFFF8000D315,"X64_ISR143"},
{ 0xFFFFFFFF8000D321,"X64_ISR144"},
{ 0xFFFFFFFF8000D32D,"X64_ISR145"},
{ 0xFFFFFFFF8000D339,"X64_ISR146"},
{ 0xFFFFFFFF8000D345,"X64_ISR147"},
{ 0xFFFFFFFF8000D351,"X64_ISR148"},
{ 0xFFFFFFFF8000D35D,"X64_ISR149"},
{ 0xFFFFFFFF8000D369,"X64_ISR150"},
{ 0xFFFFFFFF8000D375,"X64_ISR151"},
{ 0xFFFFFFFF8000D381,"X64_ISR152"},
{ 0xFFFFFFFF8000D38D,"X64_ISR153"},
{ 0xFFFFFFFF8000D399,"X64_ISR154"},
{ 0xFFFFFFFF8000D3A5,"X64_ISR155"},
{ 0xFFFFFFFF8000D3B1,"X64_ISR156"},
{ 0xFFFFFFFF8000D3BD,"X64_ISR157"},
{ 0xFFFFFFFF8000D3C9,"X64_ISR158"},
{ 0xFFFFFFFF8000D3D5,"X64_ISR159"},
{ 0xFFFFFFFF8000D3E1,"X64_ISR160"},
{ 0xFFFFFFFF8000D3ED,"X64_ISR161"},
{ 0xFFFFFFFF8000D3F9,"X64_ISR162"},
{ 0xFFFFFFFF8000D405,"X64_ISR163"},
{ 0xFFFFFFFF8000D411,"X64_ISR164"},
{ 0xFFFFFFFF8000D41D,"X64_ISR165"},
{ 0xFFFFFFFF8000D429,"X64_ISR166"},
{ 0xFFFFFFFF8000D435,"X64_ISR167"},
{ 0xFFFFFFFF8000D441,"X64_ISR168"},
{ 0xFFFFFFFF8000D44D,"X64_ISR169"},
{ 0xFFFFFFFF8000D459,"X64_ISR170"},
{ 0xFFFFFFFF8000D465,"X64_ISR171"},
{ 0xFFFFFFFF8000D471,"X64_ISR172"},
{ 0xFFFFFFFF8000D47D,"X64_ISR173"},
{ 0xFFFFFFFF8000D489,"X64_ISR174"},
{ 0xFFFFFFFF8000D495,"X64_ISR175"},
{ 0xFFFFFFFF8000D4A1,"X64_ISR176"},
{ 0xFFFFFFFF8000D4AD,"X64_ISR177"},
{ 0xFFFFFFFF8000D4B9,"X64_ISR178"},
{ 0xFFFFFFFF8000D4C5,"X64_ISR179"},
{ 0xFFFFFFFF8000D4D1,"X64_ISR180"},
{ 0xFFFFFFFF8000D4DD,"X64_ISR181"},
{ 0xFFFFFFFF8000D4E9,"X64_ISR182"},
{ 0xFFFFFFFF8000D4F5,"X64_ISR183"},
{ 0xFFFFFFFF8000D501,"X64_ISR184"},
{ 0xFFFFFFFF8000D50D,"X64_ISR185"},
{ 0xFFFFFFFF8000D519,"X64_ISR186"},
{ 0xFFFFFFFF8000D525,"X64_ISR187"},
{ 0xFFFFFFFF8000D531,"X64_ISR188"},
{ 0xFFFFFFFF8000D53D,"X64_ISR189"},
{ 0xFFFFFFFF8000D549,"X64_ISR190"},
{ 0xFFFFFFFF8000D555,"X64_ISR191"},
{ 0xFFFFFFFF8000D561,"X64_ISR192"},
{ 0xFFFFFFFF8000D56D,"X64_ISR193"},
{ 0xFFFFFFFF8000D579,"X64_ISR194"},
{ 0xFFFFFFFF8000D585,"X64_ISR195"},
{ 0xFFFFFFFF8000D591,"X64_ISR196"},
{ 0xFFFFFFFF8000D59D,"X64_ISR197"},
{ 0xFFFFFFFF8000D5A9,"X64_ISR198"},
{ 0xFFFFFFFF8000D5B5,"X64_ISR199"},
{ 0xFFFFFFFF8000D5C1,"X64_ISR200"},
{ 0xFFFFFFFF8000D5CD,"X64_ISR201"},
{ 0xFFFFFFFF8000D5D9,"X64_ISR202"},
{ 0xFFFFFFFF8000D5E5,"X64_ISR203"},
{ 0xFFFFFFFF8000D5F1,"X64_ISR204"},
{ 0xFFFFFFFF8000D5FD,"X64_ISR205"},
{ 0xFFFFFFFF8000D609,"X64_ISR206"},
{ 0xFFFFFFFF8000D615,"X64_ISR207"},
{ 0xFFFFFFFF8000D621,"X64_ISR208"},
{ 0xFFFFFFFF8000D62D,"X64_ISR209"},
{ 0xFFFFFFFF8000D639,"X64_ISR210"},
{ 0xFFFFFFFF8000D645,"X64_ISR211"},
{ 0xFFFFFFFF8000D651,"X64_ISR212"},
{ 0xFFFFFFFF8000D65D,"X64_ISR213"},
{ 0xFFFFFFFF8000D669,"X64_ISR214"},
{ 0xFFFFFFFF8000D675,"X64_ISR215"},
{ 0xFFFFFFFF8000D681,"X64_ISR216"},
{ 0xFFFFFFFF8000D68D,"X64_ISR217"},
{ 0xFFFFFFFF8000D699,"X64_ISR218"},
{ 0xFFFFFFFF8000D6A5,"X64_ISR219"},
{ 0xFFFFFFFF8000D6B1,"X64_ISR220"},
{ 0xFFFFFFFF8000D6BD,"X64_ISR221"},
{ 0xFFFFFFFF8000D6C9,"X64_ISR222"},
{ 0xFFFFFFFF8000D6D5,"X64_ISR223"},
{ 0xFFFFFFFF8000D6E1,"X64_ISR224"},
{ 0xFFFFFFFF8000D6ED,"X64_ISR225"},
{ 0xFFFFFFFF8000D6F9,"X64_ISR226"},
{ 0xFFFFFFFF8000D705,"X64_ISR227"},
{ 0xFFFFFFFF8000D711,"X64_ISR228"},
{ 0xFFFFFFFF8000D71D,"X64_ISR229"},
{ 0xFFFFFFFF8000D729,"X64_ISR230"},
{ 0xFFFFFFFF8000D735,"X64_ISR231"},
{ 0xFFFFFFFF8000D741,"X64_ISR232"},
{ 0xFFFFFFFF8000D74D,"X64_ISR233"},
{ 0xFFFFFFFF8000D759,"X64_ISR234"},
{ 0xFFFFFFFF8000D765,"X64_ISR235"},
{ 0xFFFFFFFF8000D771,"X64_ISR236"},
{ 0xFFFFFFFF8000D77D,"X64_ISR237"},
{ 0xFFFFFFFF8000D789,"X64_ISR238"},
{ 0xFFFFFFFF8000D795,"X64_ISR239"},
{ 0xFFFFFFFF8000D7A1,"X64_ISR240"},
{ 0xFFFFFFFF8000D7AD,"X64_ISR241"},
{ 0xFFFFFFFF8000D7B9,"X64_ISR242"},
{ 0xFFFFFFFF8000D7C5,"X64_ISR243"},
{ 0xFFFFFFFF8000D7D1,"X64_ISR244"},
{ 0xFFFFFFFF8000D7DD,"X64_ISR245"},
{ 0xFFFFFFFF8000D7E9,"X64_ISR246"},
{ 0xFFFFFFFF8000D7F5,"X64_ISR247"},
{ 0xFFFFFFFF8000D801,"X64_ISR248"},
{ 0xFFFFFFFF8000D80D,"X64_ISR249"},
{ 0xFFFFFFFF8000D819,"X64_ISR250"},
{ 0xFFFFFFFF8000D825,"X64_ISR251"},
{ 0xFFFFFFFF8000D831,"X64_ISR252"},
{ 0xFFFFFFFF8000D83D,"X64_ISR253"},
{ 0xFFFFFFFF8000D849,"X64_ISR254"},
{ 0xFFFFFFFF8000D855,"X64_ISR255"},
{ 0xFFFFFFFF8000D861,"X64_ISRHANDLERS"},
{ 0xFFFFFFFF8000E070,"x64_enable_sse"},
{ 0xFFFFFFFF8000E089,"x64_enable_fpu"},
{ 0xFFFFFFFF8000E0AF,"x64_cpu_stop"},
{ 0xFFFFFFFF8000E0B3,"x64_EnableInterrupts"},
{ 0xFFFFFFFF8000E0B5,"x64_DisableInterrupts"},
{ 0xFFFFFFFF8000E0B7,"x64_outb"},
{ 0xFFFFFFFF8000E0C7,"x64_inb"},
{ 0xFFFFFFFF8000E0D4,"x64_insb"},
{ 0xFFFFFFFF8000E0E9,"x64_insw"},
{ 0xFFFFFFFF8000E0FF,"x64_outsb"},
{ 0xFFFFFFFF8000E114,"x64_outsw"},
{ 0xFFFFFFFF8000E12A,"x64_load_idt"},
{ 0xFFFFFFFF8000E136,"x64_gdt_flush"},
{ 0xFFFFFFFF8000E14E,"x64_tss_flush"},
{ 0xFFFFFFFF8000E155,"x64_panic"},
{ 0xFFFFFFFF8000E159,"x64_cli"},
{ 0xFFFFFFFF8000E15B,"x64_sti"},
{ 0xFFFFFFFF8000E15D,"x64_rdtsc"},
{ 0xFFFFFFFF8000E171,"x64_readcs"},
{ 0xFFFFFFFF8000E17C,"x64_readtr"},
{ 0xFFFFFFFF8000E189,"x64_readds"},
{ 0xFFFFFFFF8000E194,"x64_sreg"},
{ 0xFFFFFFFF8000E1A5,"x64_sreg.gdts"},
{ 0xFFFFFFFF8000E1AF,"x64_sreg.idts"},
{ 0xFFFFFFFF8000E1B9,"x64_sreg.none"},
{ 0xFFFFFFFF8000E1C8,"x64_sreg.main"},
{ 0xFFFFFFFF8000E1E4,"x64_sreg.end"},
{ 0xFFFFFFFF8000E1E9,"__text_end__"},
{NULL, NULL}
};
#pragma GCC diagnostic pop
