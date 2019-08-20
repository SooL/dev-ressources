#ifndef __SOOL_DSI_H
#define __SOOL_DSI_H

#include "peripheral_include.h"
//SOOL-DSI-INCLUDES
#if defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32L4R9xx ) || defined(STM32L4S9xx ) 
//region defines

#define DSI_CCR
#define DSI_CLCR
#define DSI_CLTCR
#define DSI_CMCR
#define DSI_CR
#define DSI_DLTCR
#define DSI_FIR
#define DSI_FIR0
#define DSI_FIR1
#define DSI_GHCR
#define DSI_GPDR
#define DSI_GPSR
#define DSI_GVCIDR
#define DSI_IER
#define DSI_IER0
#define DSI_IER1
#define DSI_ISR
#define DSI_ISR0
#define DSI_ISR1
#define DSI_LCCCR
#define DSI_LCCR
#define DSI_LCOLCR
#define DSI_LCVCIDR
#define DSI_LPCR
#define DSI_LPMCCR
#define DSI_LPMCR
#define DSI_LVCIDR
#define DSI_MCR
#define DSI_PCONFR
#define DSI_PCR
#define DSI_PCTLR
#define DSI_PSR
#define DSI_PTTCR
#define DSI_PUCR
#define DSI_TCCR
#define DSI_VCCCR
#define DSI_VCCR
#define DSI_VHBPCCR
#define DSI_VHBPCR
#define DSI_VHSACCR
#define DSI_VHSACR
#define DSI_VLCCR
#define DSI_VLCR
#define DSI_VMCCR
#define DSI_VMCR
#define DSI_VNPCCR
#define DSI_VNPCR
#define DSI_VPCCR
#define DSI_VPCR
#define DSI_VR
#define DSI_VSCR
#define DSI_VVACCR
#define DSI_VVACR
#define DSI_VVBPCCR
#define DSI_VVBPCR
#define DSI_VVFPCCR
#define DSI_VVFPCR
#define DSI_VVSACCR
#define DSI_VVSACR
#define DSI_WCFGR
#define DSI_WCR
#define DSI_WIER
#define DSI_WIFCR
#define DSI_WISR
#define DSI_WPCR
#define DSI_WRPCR

#if defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F769xx ) || defined(STM32F779xx ) ||\
    defined(STM32L4R9xx ) || defined(STM32L4S9xx ) 
#define DSI_CCR_0
#define DSI_CCR_1
#define DSI_CLTCR_0
#define DSI_CLTCR_1
#define DSI_DLTCR_0
#define DSI_DLTCR_1
#define DSI_GHCR_0
#define DSI_GHCR_1
#define DSI_GVCIDR_0
#define DSI_GVCIDR_1
#define DSI_LCCCR_0
#define DSI_LCCCR_1
#define DSI_LCCR_0
#define DSI_LCCR_1
#define DSI_LCOLCR_0
#define DSI_LCOLCR_1
#define DSI_LCVCIDR_0
#define DSI_LCVCIDR_1
#define DSI_LPMCCR_0
#define DSI_LPMCCR_1
#define DSI_LPMCR_0
#define DSI_LPMCR_1
#define DSI_LVCIDR_0
#define DSI_LVCIDR_1
#define DSI_PCONFR_0
#define DSI_PCONFR_1
#define DSI_PTTCR_0
#define DSI_PTTCR_1
#define DSI_VCCCR_0
#define DSI_VCCCR_1
#define DSI_VCCR_0
#define DSI_VCCR_1
#define DSI_VHBPCCR_0
#define DSI_VHBPCCR_1
#define DSI_VHBPCR_0
#define DSI_VHBPCR_1
#define DSI_VHSACCR_0
#define DSI_VHSACCR_1
#define DSI_VHSACR_0
#define DSI_VHSACR_1
#define DSI_VLCCR_0
#define DSI_VLCCR_1
#define DSI_VLCR_0
#define DSI_VLCR_1
#define DSI_VMCCR_0
#define DSI_VMCCR_1
#define DSI_VMCR_0
#define DSI_VMCR_1
#define DSI_VNPCCR_0
#define DSI_VNPCCR_1
#define DSI_VNPCR_0
#define DSI_VNPCR_1
#define DSI_VPCCR_0
#define DSI_VPCCR_1
#define DSI_VPCR_0
#define DSI_VPCR_1
#define DSI_VVACCR_0
#define DSI_VVACCR_1
#define DSI_VVACR_0
#define DSI_VVACR_1
#define DSI_VVBPCCR_0
#define DSI_VVBPCCR_1
#define DSI_VVBPCR_0
#define DSI_VVBPCR_1
#define DSI_VVFPCCR_0
#define DSI_VVFPCCR_1
#define DSI_VVFPCR_0
#define DSI_VVFPCR_1
#define DSI_VVSACCR_0
#define DSI_VVSACCR_1
#define DSI_VVSACR_0
#define DSI_VVSACR_1
#define DSI_WCFGR_0
#define DSI_WCFGR_1
#define DSI_WPCR_0
#define DSI_WPCR_1
#define DSI_WRPCR_0
#define DSI_WRPCR_1
#endif

#if defined(STM32F469xx ) || defined(STM32F479xx ) 
#define DSI_TDCCR
#define DSI_TDCR
#define DSI_MAP0_TDCR        TDCR_TypeDef TDCR
#define DSI_MAP0_TDCCR       TDCCR_TypeDef TDCCR
#else
#define DSI_MAP0_TDCR __SOOL_PERIPH_PADDING_4
#define DSI_MAP0_TDCCR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F769xx ) || defined(STM32F779xx ) 
#define DSI_TDCCR_0
#define DSI_TDCCR_1
#define DSI_TDCR_0
#define DSI_TDCR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class DSI
		{
			//SOOL-DSI-ENUMS
			
			public :
			
			#ifdef DSI_CCR
			struct CCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_CCR_0
					struct
					{
						uint32_t TXECKDIV             :8;
						uint32_t TOCKDIV              :8;
						uint32_t                      :16;
					};
					#endif
					#ifdef DSI_CCR_1
					struct
					{
						uint32_t TXECKDIV0            :1;
						uint32_t TXECKDIV1            :1;
						uint32_t TXECKDIV2            :1;
						uint32_t TXECKDIV3            :1;
						uint32_t TXECKDIV4            :1;
						uint32_t TXECKDIV5            :1;
						uint32_t TXECKDIV6            :1;
						uint32_t TXECKDIV7            :1;
						uint32_t TOCKDIV0             :1;
						uint32_t TOCKDIV1             :1;
						uint32_t TOCKDIV2             :1;
						uint32_t TOCKDIV3             :1;
						uint32_t TOCKDIV4             :1;
						uint32_t TOCKDIV5             :1;
						uint32_t TOCKDIV6             :1;
						uint32_t TOCKDIV7             :1;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-DSI_CCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_CLCR
			struct CLCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DPCC                 :1;
					uint32_t ACR                  :1;
					uint32_t                      :30;
			
				//SOOL-DSI_CLCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_CLTCR
			struct CLTCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_CLTCR_0
					struct
					{
						uint32_t LP2HS_TIME           :10;
						uint32_t                      :6;
						uint32_t HS2LP_TIME           :10;
						uint32_t                      :6;
					};
					#endif
					#ifdef DSI_CLTCR_1
					struct
					{
						uint32_t LP2HS_TIME0          :1;
						uint32_t LP2HS_TIME1          :1;
						uint32_t LP2HS_TIME2          :1;
						uint32_t LP2HS_TIME3          :1;
						uint32_t LP2HS_TIME4          :1;
						uint32_t LP2HS_TIME5          :1;
						uint32_t LP2HS_TIME6          :1;
						uint32_t LP2HS_TIME7          :1;
						uint32_t LP2HS_TIME8          :1;
						uint32_t LP2HS_TIME9          :1;
						uint32_t                      :6;
						uint32_t HS2LP_TIME0          :1;
						uint32_t HS2LP_TIME1          :1;
						uint32_t HS2LP_TIME2          :1;
						uint32_t HS2LP_TIME3          :1;
						uint32_t HS2LP_TIME4          :1;
						uint32_t HS2LP_TIME5          :1;
						uint32_t HS2LP_TIME6          :1;
						uint32_t HS2LP_TIME7          :1;
						uint32_t HS2LP_TIME8          :1;
						uint32_t HS2LP_TIME9          :1;
						uint32_t                      :6;
					};
					#endif
				};
				//SOOL-DSI_CLTCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_CMCR
			struct CMCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TEARE                :1;
					uint32_t ARE                  :1;
					uint32_t                      :6;
					uint32_t GSW0TX               :1;
					uint32_t GSW1TX               :1;
					uint32_t GSW2TX               :1;
					uint32_t GSR0TX               :1;
					uint32_t GSR1TX               :1;
					uint32_t GSR2TX               :1;
					uint32_t GLWTX                :1;
					uint32_t                      :1;
					uint32_t DSW0TX               :1;
					uint32_t DSW1TX               :1;
					uint32_t DSR0TX               :1;
					uint32_t DLWTX                :1;
					uint32_t                      :4;
					uint32_t MRDPS                :1;
					uint32_t                      :7;
			
				//SOOL-DSI_CMCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EN                   :1;
					uint32_t                      :31;
			
				//SOOL-DSI_CR-DECLARATION
			};
			#endif
			
			#ifdef DSI_DLTCR
			struct DLTCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_DLTCR_0
					struct
					{
						uint32_t MRD_TIME             :15;
						uint32_t                      :1;
						uint32_t LP2HS_TIME           :8;
						uint32_t HS2LP_TIME           :8;
					};
					#endif
					#ifdef DSI_DLTCR_1
					struct
					{
						uint32_t MRD_TIME0            :1;
						uint32_t MRD_TIME1            :1;
						uint32_t MRD_TIME2            :1;
						uint32_t MRD_TIME3            :1;
						uint32_t MRD_TIME4            :1;
						uint32_t MRD_TIME5            :1;
						uint32_t MRD_TIME6            :1;
						uint32_t MRD_TIME7            :1;
						uint32_t MRD_TIME8            :1;
						uint32_t MRD_TIME9            :1;
						uint32_t MRD_TIME10           :1;
						uint32_t MRD_TIME11           :1;
						uint32_t MRD_TIME12           :1;
						uint32_t MRD_TIME13           :1;
						uint32_t MRD_TIME14           :1;
						uint32_t                      :1;
						uint32_t LP2HS_TIME0          :1;
						uint32_t LP2HS_TIME1          :1;
						uint32_t LP2HS_TIME2          :1;
						uint32_t LP2HS_TIME3          :1;
						uint32_t LP2HS_TIME4          :1;
						uint32_t LP2HS_TIME5          :1;
						uint32_t LP2HS_TIME6          :1;
						uint32_t LP2HS_TIME7          :1;
						uint32_t HS2LP_TIME0          :1;
						uint32_t HS2LP_TIME1          :1;
						uint32_t HS2LP_TIME2          :1;
						uint32_t HS2LP_TIME3          :1;
						uint32_t HS2LP_TIME4          :1;
						uint32_t HS2LP_TIME5          :1;
						uint32_t HS2LP_TIME6          :1;
						uint32_t HS2LP_TIME7          :1;
					};
					#endif
				};
				//SOOL-DSI_DLTCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_FIR0
			struct FIR0_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FAE0                 :1;
					uint32_t FAE1                 :1;
					uint32_t FAE2                 :1;
					uint32_t FAE3                 :1;
					uint32_t FAE4                 :1;
					uint32_t FAE5                 :1;
					uint32_t FAE6                 :1;
					uint32_t FAE7                 :1;
					uint32_t FAE8                 :1;
					uint32_t FAE9                 :1;
					uint32_t FAE10                :1;
					uint32_t FAE11                :1;
					uint32_t FAE12                :1;
					uint32_t FAE13                :1;
					uint32_t FAE14                :1;
					uint32_t FAE15                :1;
					uint32_t FPE0                 :1;
					uint32_t FPE1                 :1;
					uint32_t FPE2                 :1;
					uint32_t FPE3                 :1;
					uint32_t FPE4                 :1;
					uint32_t                      :11;
			
				//SOOL-DSI_FIR0-DECLARATION
			};
			#endif
			
			#ifdef DSI_FIR1
			struct FIR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FTOHSTX              :1;
					uint32_t FTOLPRX              :1;
					uint32_t FECCSE               :1;
					uint32_t FECCME               :1;
					uint32_t FCRCE                :1;
					uint32_t FPSE                 :1;
					uint32_t FEOTPE               :1;
					uint32_t FLPWRE               :1;
					uint32_t FGCWRE               :1;
					uint32_t FGPWRE               :1;
					uint32_t FGPTXE               :1;
					uint32_t FGPRDE               :1;
					uint32_t FGPRXE               :1;
					uint32_t                      :19;
			
				//SOOL-DSI_FIR1-DECLARATION
			};
			#endif
			
			#ifdef DSI_GHCR
			struct GHCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_GHCR_0
					struct
					{
						uint32_t DT                   :6;
						uint32_t VCID                 :2;
						uint32_t WCLSB                :8;
						uint32_t WCMSB                :8;
						uint32_t                      :8;
					};
					#endif
					#ifdef DSI_GHCR_1
					struct
					{
						uint32_t DT0                  :1;
						uint32_t DT1                  :1;
						uint32_t DT2                  :1;
						uint32_t DT3                  :1;
						uint32_t DT4                  :1;
						uint32_t DT5                  :1;
						uint32_t VCID0                :1;
						uint32_t VCID1                :1;
						uint32_t WCLSB0               :1;
						uint32_t WCLSB1               :1;
						uint32_t WCLSB2               :1;
						uint32_t WCLSB3               :1;
						uint32_t WCLSB4               :1;
						uint32_t WCLSB5               :1;
						uint32_t WCLSB6               :1;
						uint32_t WCLSB7               :1;
						uint32_t WCMSB0               :1;
						uint32_t WCMSB1               :1;
						uint32_t WCMSB2               :1;
						uint32_t WCMSB3               :1;
						uint32_t WCMSB4               :1;
						uint32_t WCMSB5               :1;
						uint32_t WCMSB6               :1;
						uint32_t WCMSB7               :1;
						uint32_t                      :8;
					};
					#endif
				};
				//SOOL-DSI_GHCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_GPDR
			struct GPDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATA1                :8;
					uint32_t DATA2                :8;
					uint32_t DATA3                :8;
					uint32_t DATA4                :8;
			
				//SOOL-DSI_GPDR-DECLARATION
			};
			#endif
			
			#ifdef DSI_GPSR
			struct GPSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMDFE                :1;
					uint32_t CMDFF                :1;
					uint32_t PWRFE                :1;
					uint32_t PWRFF                :1;
					uint32_t PRDFE                :1;
					uint32_t PRDFF                :1;
					uint32_t RCB                  :1;
					uint32_t                      :25;
			
				//SOOL-DSI_GPSR-DECLARATION
			};
			#endif
			
			#ifdef DSI_GVCIDR
			struct GVCIDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_GVCIDR_0
					struct
					{
						uint32_t VCID                 :2;
						uint32_t                      :30;
					};
					#endif
					#ifdef DSI_GVCIDR_1
					struct
					{
						uint32_t VCID0                :1;
						uint32_t VCID1                :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-DSI_GVCIDR-DECLARATION
			};
			#endif
			
			#ifdef DSI_IER0
			struct IER0_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t AE0IE                :1;
					uint32_t AE1IE                :1;
					uint32_t AE2IE                :1;
					uint32_t AE3IE                :1;
					uint32_t AE4IE                :1;
					uint32_t AE5IE                :1;
					uint32_t AE6IE                :1;
					uint32_t AE7IE                :1;
					uint32_t AE8IE                :1;
					uint32_t AE9IE                :1;
					uint32_t AE10IE               :1;
					uint32_t AE11IE               :1;
					uint32_t AE12IE               :1;
					uint32_t AE13IE               :1;
					uint32_t AE14IE               :1;
					uint32_t AE15IE               :1;
					uint32_t PE0IE                :1;
					uint32_t PE1IE                :1;
					uint32_t PE2IE                :1;
					uint32_t PE3IE                :1;
					uint32_t PE4IE                :1;
					uint32_t                      :11;
			
				//SOOL-DSI_IER0-DECLARATION
			};
			#endif
			
			#ifdef DSI_IER1
			struct IER1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TOHSTXIE             :1;
					uint32_t TOLPRXIE             :1;
					uint32_t ECCSEIE              :1;
					uint32_t ECCMEIE              :1;
					uint32_t CRCEIE               :1;
					uint32_t PSEIE                :1;
					uint32_t EOTPEIE              :1;
					uint32_t LPWREIE              :1;
					uint32_t GCWREIE              :1;
					uint32_t GPWREIE              :1;
					uint32_t GPTXEIE              :1;
					uint32_t GPRDEIE              :1;
					uint32_t GPRXEIE              :1;
					uint32_t                      :19;
			
				//SOOL-DSI_IER1-DECLARATION
			};
			#endif
			
			#ifdef DSI_ISR0
			struct ISR0_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t AE0                  :1;
					uint32_t AE1                  :1;
					uint32_t AE2                  :1;
					uint32_t AE3                  :1;
					uint32_t AE4                  :1;
					uint32_t AE5                  :1;
					uint32_t AE6                  :1;
					uint32_t AE7                  :1;
					uint32_t AE8                  :1;
					uint32_t AE9                  :1;
					uint32_t AE10                 :1;
					uint32_t AE11                 :1;
					uint32_t AE12                 :1;
					uint32_t AE13                 :1;
					uint32_t AE14                 :1;
					uint32_t AE15                 :1;
					uint32_t PE0                  :1;
					uint32_t PE1                  :1;
					uint32_t PE2                  :1;
					uint32_t PE3                  :1;
					uint32_t PE4                  :1;
					uint32_t                      :11;
			
				//SOOL-DSI_ISR0-DECLARATION
			};
			#endif
			
			#ifdef DSI_ISR1
			struct ISR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TOHSTX               :1;
					uint32_t TOLPRX               :1;
					uint32_t ECCSE                :1;
					uint32_t ECCME                :1;
					uint32_t CRCE                 :1;
					uint32_t PSE                  :1;
					uint32_t EOTPE                :1;
					uint32_t LPWRE                :1;
					uint32_t GCWRE                :1;
					uint32_t GPWRE                :1;
					uint32_t GPTXE                :1;
					uint32_t GPRDE                :1;
					uint32_t GPRXE                :1;
					uint32_t                      :19;
			
				//SOOL-DSI_ISR1-DECLARATION
			};
			#endif
			
			#ifdef DSI_LCCCR
			struct LCCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_LCCCR_0
					struct
					{
						uint32_t COLC                 :4;
						uint32_t                      :4;
						uint32_t LPE                  :1;
						uint32_t                      :23;
					};
					#endif
					#ifdef DSI_LCCCR_1
					struct
					{
						uint32_t COLC0                :1;
						uint32_t COLC1                :1;
						uint32_t COLC2                :1;
						uint32_t COLC3                :1;
						uint32_t                      :28;
					};
					#endif
				};
				//SOOL-DSI_LCCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_LCCR
			struct LCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_LCCR_0
					struct
					{
						uint32_t CMDSIZE              :16;
						uint32_t                      :16;
					};
					#endif
					#ifdef DSI_LCCR_1
					struct
					{
						uint32_t CMDSIZE0             :1;
						uint32_t CMDSIZE1             :1;
						uint32_t CMDSIZE2             :1;
						uint32_t CMDSIZE3             :1;
						uint32_t CMDSIZE4             :1;
						uint32_t CMDSIZE5             :1;
						uint32_t CMDSIZE6             :1;
						uint32_t CMDSIZE7             :1;
						uint32_t CMDSIZE8             :1;
						uint32_t CMDSIZE9             :1;
						uint32_t CMDSIZE10            :1;
						uint32_t CMDSIZE11            :1;
						uint32_t CMDSIZE12            :1;
						uint32_t CMDSIZE13            :1;
						uint32_t CMDSIZE14            :1;
						uint32_t CMDSIZE15            :1;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-DSI_LCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_LCOLCR
			struct LCOLCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_LCOLCR_0
					struct
					{
						uint32_t COLC                 :4;
						uint32_t                      :1;
						uint32_t COLC1                :1;
						uint32_t COLC2                :1;
						uint32_t COLC3                :1;
						uint32_t LPE                  :1;
						uint32_t                      :23;
					};
					#endif
					#ifdef DSI_LCOLCR_1
					struct
					{
						uint32_t COLC0                :1;
						uint32_t                      :31;
					};
					#endif
				};
				//SOOL-DSI_LCOLCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_LCVCIDR
			struct LCVCIDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_LCVCIDR_0
					struct
					{
						uint32_t VCID                 :2;
						uint32_t                      :30;
					};
					#endif
					#ifdef DSI_LCVCIDR_1
					struct
					{
						uint32_t VCID0                :1;
						uint32_t VCID1                :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-DSI_LCVCIDR-DECLARATION
			};
			#endif
			
			#ifdef DSI_LPCR
			struct LPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DEP                  :1;
					uint32_t VSP                  :1;
					uint32_t HSP                  :1;
					uint32_t                      :29;
			
				//SOOL-DSI_LPCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_LPMCCR
			struct LPMCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_LPMCCR_0
					struct
					{
						uint32_t VLPSIZE              :8;
						uint32_t                      :8;
						uint32_t LPSIZE               :8;
						uint32_t                      :8;
					};
					#endif
					#ifdef DSI_LPMCCR_1
					struct
					{
						uint32_t VLPSIZE0             :1;
						uint32_t VLPSIZE1             :1;
						uint32_t VLPSIZE2             :1;
						uint32_t VLPSIZE3             :1;
						uint32_t VLPSIZE4             :1;
						uint32_t VLPSIZE5             :1;
						uint32_t VLPSIZE6             :1;
						uint32_t VLPSIZE7             :1;
						uint32_t                      :8;
						uint32_t LPSIZE0              :1;
						uint32_t LPSIZE1              :1;
						uint32_t LPSIZE2              :1;
						uint32_t LPSIZE3              :1;
						uint32_t LPSIZE4              :1;
						uint32_t LPSIZE5              :1;
						uint32_t LPSIZE6              :1;
						uint32_t LPSIZE7              :1;
						uint32_t                      :8;
					};
					#endif
				};
				//SOOL-DSI_LPMCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_LPMCR
			struct LPMCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_LPMCR_0
					struct
					{
						uint32_t VLPSIZE              :8;
						uint32_t                      :8;
						uint32_t LPSIZE               :8;
						uint32_t                      :8;
					};
					#endif
					#ifdef DSI_LPMCR_1
					struct
					{
						uint32_t VLPSIZE0             :1;
						uint32_t VLPSIZE1             :1;
						uint32_t VLPSIZE2             :1;
						uint32_t VLPSIZE3             :1;
						uint32_t VLPSIZE4             :1;
						uint32_t VLPSIZE5             :1;
						uint32_t VLPSIZE6             :1;
						uint32_t VLPSIZE7             :1;
						uint32_t                      :8;
						uint32_t LPSIZE0              :1;
						uint32_t LPSIZE1              :1;
						uint32_t LPSIZE2              :1;
						uint32_t LPSIZE3              :1;
						uint32_t LPSIZE4              :1;
						uint32_t LPSIZE5              :1;
						uint32_t LPSIZE6              :1;
						uint32_t LPSIZE7              :1;
						uint32_t                      :8;
					};
					#endif
				};
				//SOOL-DSI_LPMCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_LVCIDR
			struct LVCIDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_LVCIDR_0
					struct
					{
						uint32_t VCID                 :2;
						uint32_t                      :30;
					};
					#endif
					#ifdef DSI_LVCIDR_1
					struct
					{
						uint32_t VCID0                :1;
						uint32_t VCID1                :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-DSI_LVCIDR-DECLARATION
			};
			#endif
			
			#ifdef DSI_MCR
			struct MCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMDM                 :1;
					uint32_t                      :31;
			
				//SOOL-DSI_MCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_PCONFR
			struct PCONFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_PCONFR_0
					struct
					{
						uint32_t NL                   :2;
						uint32_t                      :6;
						uint32_t SW_TIME              :8;
						uint32_t                      :16;
					};
					#endif
					#ifdef DSI_PCONFR_1
					struct
					{
						uint32_t NL0                  :1;
						uint32_t NL1                  :1;
						uint32_t                      :6;
						uint32_t SW_TIME0             :1;
						uint32_t SW_TIME1             :1;
						uint32_t SW_TIME2             :1;
						uint32_t SW_TIME3             :1;
						uint32_t SW_TIME4             :1;
						uint32_t SW_TIME5             :1;
						uint32_t SW_TIME6             :1;
						uint32_t SW_TIME7             :1;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-DSI_PCONFR-DECLARATION
			};
			#endif
			
			#ifdef DSI_PCR
			struct PCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ETTXE                :1;
					uint32_t ETRXE                :1;
					uint32_t BTAE                 :1;
					uint32_t ECCRXE               :1;
					uint32_t CRCRXE               :1;
					uint32_t                      :27;
			
				//SOOL-DSI_PCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_PCTLR
			struct PCTLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :1;
					uint32_t DEN                  :1;
					uint32_t CKE                  :1;
					uint32_t                      :29;
			
				//SOOL-DSI_PCTLR-DECLARATION
			};
			#endif
			
			#ifdef DSI_PSR
			struct PSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :1;
					uint32_t PD                   :1;
					uint32_t PSSC                 :1;
					uint32_t UANC                 :1;
					uint32_t PSS0                 :1;
					uint32_t UAN0                 :1;
					uint32_t RUE0                 :1;
					uint32_t PSS1                 :1;
					uint32_t UAN1                 :1;
					uint32_t                      :23;
			
				//SOOL-DSI_PSR-DECLARATION
			};
			#endif
			
			#ifdef DSI_PTTCR
			struct PTTCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_PTTCR_0
					struct
					{
						uint32_t TX_TRIG              :4;
						uint32_t                      :28;
					};
					#endif
					#ifdef DSI_PTTCR_1
					struct
					{
						uint32_t TX_TRIG0             :1;
						uint32_t TX_TRIG1             :1;
						uint32_t TX_TRIG2             :1;
						uint32_t TX_TRIG3             :1;
						uint32_t                      :28;
					};
					#endif
				};
				//SOOL-DSI_PTTCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_PUCR
			struct PUCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t URCL                 :1;
					uint32_t UECL                 :1;
					uint32_t URDL                 :1;
					uint32_t UEDL                 :1;
					uint32_t                      :28;
			
				//SOOL-DSI_PUCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_TCCR
			struct TCCR_TypeDef : public BigArrayReg_t<uint32_t, 0, 4, 6>
			{
				using BigArrayReg_t<uint32_t, 0, 4, 6>::operator=;
				
					uint32_t LPRX_TOCNT           :16;
					uint32_t HSTX_TOCNT           :16;
					uint32_t HSRD_TOCNT           :16;
					uint32_t                      :16;
					uint32_t LPRD_TOCNT           :16;
					uint32_t                      :16;
					uint32_t HSWR_TOCNT           :16;
					uint32_t                      :8;
					uint32_t PM                   :1;
					uint32_t                      :7;
					uint32_t LPWR_TOCNT           :16;
					uint32_t                      :16;
					uint32_t BTA_TOCNT            :16;
					uint32_t                      :16;
			
				//SOOL-DSI_TCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_TDCCR
			struct TDCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_TDCCR_0
					struct
					{
						uint32_t TDCC3DM              :2;
						uint32_t TDCC3DF              :2;
						uint32_t SVS                  :1;
						uint32_t RF                   :1;
						uint32_t                      :10;
						uint32_t S3DC                 :1;
						uint32_t                      :15;
					};
					#endif
					#ifdef DSI_TDCCR_1
					struct
					{
						uint32_t TDCC3DM0             :1;
						uint32_t TDCC3DM1             :1;
						uint32_t TDCC3DF0             :1;
						uint32_t TDCC3DF1             :1;
						uint32_t                      :28;
					};
					#endif
				};
				//SOOL-DSI_TDCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_TDCR
			struct TDCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_TDCR_0
					struct
					{
						uint32_t TDC3DM               :2;
						uint32_t TDC3DF               :2;
						uint32_t SVS                  :1;
						uint32_t RF                   :1;
						uint32_t                      :10;
						uint32_t S3DC                 :1;
						uint32_t                      :15;
					};
					#endif
					#ifdef DSI_TDCR_1
					struct
					{
						uint32_t TDC3DM0              :1;
						uint32_t TDC3DM1              :1;
						uint32_t TDC3DF0              :1;
						uint32_t TDC3DF1              :1;
						uint32_t                      :28;
					};
					#endif
				};
				//SOOL-DSI_TDCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VCCCR
			struct VCCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VCCCR_0
					struct
					{
						uint32_t NUMC                 :13;
						uint32_t                      :19;
					};
					#endif
					#ifdef DSI_VCCCR_1
					struct
					{
						uint32_t NUMC0                :1;
						uint32_t NUMC1                :1;
						uint32_t NUMC2                :1;
						uint32_t NUMC3                :1;
						uint32_t NUMC4                :1;
						uint32_t NUMC5                :1;
						uint32_t NUMC6                :1;
						uint32_t NUMC7                :1;
						uint32_t NUMC8                :1;
						uint32_t NUMC9                :1;
						uint32_t NUMC10               :1;
						uint32_t NUMC11               :1;
						uint32_t NUMC12               :1;
						uint32_t                      :19;
					};
					#endif
				};
				//SOOL-DSI_VCCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VCCR
			struct VCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VCCR_0
					struct
					{
						uint32_t NUMC                 :13;
						uint32_t                      :19;
					};
					#endif
					#ifdef DSI_VCCR_1
					struct
					{
						uint32_t NUMC0                :1;
						uint32_t NUMC1                :1;
						uint32_t NUMC2                :1;
						uint32_t NUMC3                :1;
						uint32_t NUMC4                :1;
						uint32_t NUMC5                :1;
						uint32_t NUMC6                :1;
						uint32_t NUMC7                :1;
						uint32_t NUMC8                :1;
						uint32_t NUMC9                :1;
						uint32_t NUMC10               :1;
						uint32_t NUMC11               :1;
						uint32_t NUMC12               :1;
						uint32_t                      :19;
					};
					#endif
				};
				//SOOL-DSI_VCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VHBPCCR
			struct VHBPCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VHBPCCR_0
					struct
					{
						uint32_t HBP                  :12;
						uint32_t                      :20;
					};
					#endif
					#ifdef DSI_VHBPCCR_1
					struct
					{
						uint32_t HBP0                 :1;
						uint32_t HBP1                 :1;
						uint32_t HBP2                 :1;
						uint32_t HBP3                 :1;
						uint32_t HBP4                 :1;
						uint32_t HBP5                 :1;
						uint32_t HBP6                 :1;
						uint32_t HBP7                 :1;
						uint32_t HBP8                 :1;
						uint32_t HBP9                 :1;
						uint32_t HBP10                :1;
						uint32_t HBP11                :1;
						uint32_t                      :20;
					};
					#endif
				};
				//SOOL-DSI_VHBPCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VHBPCR
			struct VHBPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VHBPCR_0
					struct
					{
						uint32_t HBP                  :12;
						uint32_t                      :20;
					};
					#endif
					#ifdef DSI_VHBPCR_1
					struct
					{
						uint32_t HBP0                 :1;
						uint32_t HBP1                 :1;
						uint32_t HBP2                 :1;
						uint32_t HBP3                 :1;
						uint32_t HBP4                 :1;
						uint32_t HBP5                 :1;
						uint32_t HBP6                 :1;
						uint32_t HBP7                 :1;
						uint32_t HBP8                 :1;
						uint32_t HBP9                 :1;
						uint32_t HBP10                :1;
						uint32_t HBP11                :1;
						uint32_t                      :20;
					};
					#endif
				};
				//SOOL-DSI_VHBPCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VHSACCR
			struct VHSACCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VHSACCR_0
					struct
					{
						uint32_t HSA                  :12;
						uint32_t                      :20;
					};
					#endif
					#ifdef DSI_VHSACCR_1
					struct
					{
						uint32_t HSA0                 :1;
						uint32_t HSA1                 :1;
						uint32_t HSA2                 :1;
						uint32_t HSA3                 :1;
						uint32_t HSA4                 :1;
						uint32_t HSA5                 :1;
						uint32_t HSA6                 :1;
						uint32_t HSA7                 :1;
						uint32_t HSA8                 :1;
						uint32_t HSA9                 :1;
						uint32_t HSA10                :1;
						uint32_t HSA11                :1;
						uint32_t                      :20;
					};
					#endif
				};
				//SOOL-DSI_VHSACCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VHSACR
			struct VHSACR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VHSACR_0
					struct
					{
						uint32_t HSA                  :12;
						uint32_t                      :20;
					};
					#endif
					#ifdef DSI_VHSACR_1
					struct
					{
						uint32_t HSA0                 :1;
						uint32_t HSA1                 :1;
						uint32_t HSA2                 :1;
						uint32_t HSA3                 :1;
						uint32_t HSA4                 :1;
						uint32_t HSA5                 :1;
						uint32_t HSA6                 :1;
						uint32_t HSA7                 :1;
						uint32_t HSA8                 :1;
						uint32_t HSA9                 :1;
						uint32_t HSA10                :1;
						uint32_t HSA11                :1;
						uint32_t                      :20;
					};
					#endif
				};
				//SOOL-DSI_VHSACR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VLCCR
			struct VLCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VLCCR_0
					struct
					{
						uint32_t HLINE                :15;
						uint32_t                      :17;
					};
					#endif
					#ifdef DSI_VLCCR_1
					struct
					{
						uint32_t HLINE0               :1;
						uint32_t HLINE1               :1;
						uint32_t HLINE2               :1;
						uint32_t HLINE3               :1;
						uint32_t HLINE4               :1;
						uint32_t HLINE5               :1;
						uint32_t HLINE6               :1;
						uint32_t HLINE7               :1;
						uint32_t HLINE8               :1;
						uint32_t HLINE9               :1;
						uint32_t HLINE10              :1;
						uint32_t HLINE11              :1;
						uint32_t HLINE12              :1;
						uint32_t HLINE13              :1;
						uint32_t HLINE14              :1;
						uint32_t                      :17;
					};
					#endif
				};
				//SOOL-DSI_VLCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VLCR
			struct VLCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VLCR_0
					struct
					{
						uint32_t HLINE                :15;
						uint32_t                      :17;
					};
					#endif
					#ifdef DSI_VLCR_1
					struct
					{
						uint32_t HLINE0               :1;
						uint32_t HLINE1               :1;
						uint32_t HLINE2               :1;
						uint32_t HLINE3               :1;
						uint32_t HLINE4               :1;
						uint32_t HLINE5               :1;
						uint32_t HLINE6               :1;
						uint32_t HLINE7               :1;
						uint32_t HLINE8               :1;
						uint32_t HLINE9               :1;
						uint32_t HLINE10              :1;
						uint32_t HLINE11              :1;
						uint32_t HLINE12              :1;
						uint32_t HLINE13              :1;
						uint32_t HLINE14              :1;
						uint32_t                      :17;
					};
					#endif
				};
				//SOOL-DSI_VLCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VMCCR
			struct VMCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VMCCR_0
					struct
					{
						uint32_t VMT                  :2;
						uint32_t                      :6;
						uint32_t LPVSAE               :1;
						uint32_t LPVBPE               :1;
						uint32_t LPVFPE               :1;
						uint32_t LPVAE                :1;
						uint32_t LPHBPE               :1;
						uint32_t LPHFE                :1;
						uint32_t FBTAAE               :1;
						uint32_t LPCE                 :1;
						uint32_t                      :16;
					};
					#endif
					#ifdef DSI_VMCCR_1
					struct
					{
						uint32_t VMT0                 :1;
						uint32_t VMT1                 :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-DSI_VMCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VMCR
			struct VMCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VMCR_0
					struct
					{
						uint32_t VMT                  :2;
						uint32_t                      :6;
						uint32_t LPVSAE               :1;
						uint32_t LPVBPE               :1;
						uint32_t LPVFPE               :1;
						uint32_t LPVAE                :1;
						uint32_t LPHBPE               :1;
						uint32_t LPHFPE               :1;
						uint32_t FBTAAE               :1;
						uint32_t LPCE                 :1;
						uint32_t PGE                  :1;
						uint32_t                      :3;
						uint32_t PGM                  :1;
						uint32_t                      :3;
						uint32_t PGO                  :1;
						uint32_t                      :7;
					};
					#endif
					#ifdef DSI_VMCR_1
					struct
					{
						uint32_t VMT0                 :1;
						uint32_t VMT1                 :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-DSI_VMCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VNPCCR
			struct VNPCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VNPCCR_0
					struct
					{
						uint32_t NPSIZE               :13;
						uint32_t                      :19;
					};
					#endif
					#ifdef DSI_VNPCCR_1
					struct
					{
						uint32_t NPSIZE0              :1;
						uint32_t NPSIZE1              :1;
						uint32_t NPSIZE2              :1;
						uint32_t NPSIZE3              :1;
						uint32_t NPSIZE4              :1;
						uint32_t NPSIZE5              :1;
						uint32_t NPSIZE6              :1;
						uint32_t NPSIZE7              :1;
						uint32_t NPSIZE8              :1;
						uint32_t NPSIZE9              :1;
						uint32_t NPSIZE10             :1;
						uint32_t NPSIZE11             :1;
						uint32_t NPSIZE12             :1;
						uint32_t                      :19;
					};
					#endif
				};
				//SOOL-DSI_VNPCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VNPCR
			struct VNPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VNPCR_0
					struct
					{
						uint32_t NPSIZE               :13;
						uint32_t                      :19;
					};
					#endif
					#ifdef DSI_VNPCR_1
					struct
					{
						uint32_t NPSIZE0              :1;
						uint32_t NPSIZE1              :1;
						uint32_t NPSIZE2              :1;
						uint32_t NPSIZE3              :1;
						uint32_t NPSIZE4              :1;
						uint32_t NPSIZE5              :1;
						uint32_t NPSIZE6              :1;
						uint32_t NPSIZE7              :1;
						uint32_t NPSIZE8              :1;
						uint32_t NPSIZE9              :1;
						uint32_t NPSIZE10             :1;
						uint32_t NPSIZE11             :1;
						uint32_t NPSIZE12             :1;
						uint32_t                      :19;
					};
					#endif
				};
				//SOOL-DSI_VNPCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VPCCR
			struct VPCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VPCCR_0
					struct
					{
						uint32_t VPSIZE               :14;
						uint32_t                      :18;
					};
					#endif
					#ifdef DSI_VPCCR_1
					struct
					{
						uint32_t VPSIZE0              :1;
						uint32_t VPSIZE1              :1;
						uint32_t VPSIZE2              :1;
						uint32_t VPSIZE3              :1;
						uint32_t VPSIZE4              :1;
						uint32_t VPSIZE5              :1;
						uint32_t VPSIZE6              :1;
						uint32_t VPSIZE7              :1;
						uint32_t VPSIZE8              :1;
						uint32_t VPSIZE9              :1;
						uint32_t VPSIZE10             :1;
						uint32_t VPSIZE11             :1;
						uint32_t VPSIZE12             :1;
						uint32_t VPSIZE13             :1;
						uint32_t                      :18;
					};
					#endif
				};
				//SOOL-DSI_VPCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VPCR
			struct VPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VPCR_0
					struct
					{
						uint32_t VPSIZE               :14;
						uint32_t                      :18;
					};
					#endif
					#ifdef DSI_VPCR_1
					struct
					{
						uint32_t VPSIZE0              :1;
						uint32_t VPSIZE1              :1;
						uint32_t VPSIZE2              :1;
						uint32_t VPSIZE3              :1;
						uint32_t VPSIZE4              :1;
						uint32_t VPSIZE5              :1;
						uint32_t VPSIZE6              :1;
						uint32_t VPSIZE7              :1;
						uint32_t VPSIZE8              :1;
						uint32_t VPSIZE9              :1;
						uint32_t VPSIZE10             :1;
						uint32_t VPSIZE11             :1;
						uint32_t VPSIZE12             :1;
						uint32_t VPSIZE13             :1;
						uint32_t                      :18;
					};
					#endif
				};
				//SOOL-DSI_VPCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VSCR
			struct VSCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EN                   :1;
					uint32_t                      :7;
					uint32_t UR                   :1;
					uint32_t                      :23;
			
				//SOOL-DSI_VSCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VVACCR
			struct VVACCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VVACCR_0
					struct
					{
						uint32_t VA                   :14;
						uint32_t                      :18;
					};
					#endif
					#ifdef DSI_VVACCR_1
					struct
					{
						uint32_t VA0                  :1;
						uint32_t VA1                  :1;
						uint32_t VA2                  :1;
						uint32_t VA3                  :1;
						uint32_t VA4                  :1;
						uint32_t VA5                  :1;
						uint32_t VA6                  :1;
						uint32_t VA7                  :1;
						uint32_t VA8                  :1;
						uint32_t VA9                  :1;
						uint32_t VA10                 :1;
						uint32_t VA11                 :1;
						uint32_t VA12                 :1;
						uint32_t VA13                 :1;
						uint32_t                      :18;
					};
					#endif
				};
				//SOOL-DSI_VVACCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VVACR
			struct VVACR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VVACR_0
					struct
					{
						uint32_t VA                   :14;
						uint32_t                      :18;
					};
					#endif
					#ifdef DSI_VVACR_1
					struct
					{
						uint32_t VA0                  :1;
						uint32_t VA1                  :1;
						uint32_t VA2                  :1;
						uint32_t VA3                  :1;
						uint32_t VA4                  :1;
						uint32_t VA5                  :1;
						uint32_t VA6                  :1;
						uint32_t VA7                  :1;
						uint32_t VA8                  :1;
						uint32_t VA9                  :1;
						uint32_t VA10                 :1;
						uint32_t VA11                 :1;
						uint32_t VA12                 :1;
						uint32_t VA13                 :1;
						uint32_t                      :18;
					};
					#endif
				};
				//SOOL-DSI_VVACR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VVBPCCR
			struct VVBPCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VVBPCCR_0
					struct
					{
						uint32_t VBP                  :10;
						uint32_t                      :22;
					};
					#endif
					#ifdef DSI_VVBPCCR_1
					struct
					{
						uint32_t VBP0                 :1;
						uint32_t VBP1                 :1;
						uint32_t VBP2                 :1;
						uint32_t VBP3                 :1;
						uint32_t VBP4                 :1;
						uint32_t VBP5                 :1;
						uint32_t VBP6                 :1;
						uint32_t VBP7                 :1;
						uint32_t VBP8                 :1;
						uint32_t VBP9                 :1;
						uint32_t                      :22;
					};
					#endif
				};
				//SOOL-DSI_VVBPCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VVBPCR
			struct VVBPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VVBPCR_0
					struct
					{
						uint32_t VBP                  :10;
						uint32_t                      :22;
					};
					#endif
					#ifdef DSI_VVBPCR_1
					struct
					{
						uint32_t VBP0                 :1;
						uint32_t VBP1                 :1;
						uint32_t VBP2                 :1;
						uint32_t VBP3                 :1;
						uint32_t VBP4                 :1;
						uint32_t VBP5                 :1;
						uint32_t VBP6                 :1;
						uint32_t VBP7                 :1;
						uint32_t VBP8                 :1;
						uint32_t VBP9                 :1;
						uint32_t                      :22;
					};
					#endif
				};
				//SOOL-DSI_VVBPCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VVFPCCR
			struct VVFPCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VVFPCCR_0
					struct
					{
						uint32_t VFP                  :10;
						uint32_t                      :22;
					};
					#endif
					#ifdef DSI_VVFPCCR_1
					struct
					{
						uint32_t VFP0                 :1;
						uint32_t VFP1                 :1;
						uint32_t VFP2                 :1;
						uint32_t VFP3                 :1;
						uint32_t VFP4                 :1;
						uint32_t VFP5                 :1;
						uint32_t VFP6                 :1;
						uint32_t VFP7                 :1;
						uint32_t VFP8                 :1;
						uint32_t VFP9                 :1;
						uint32_t                      :22;
					};
					#endif
				};
				//SOOL-DSI_VVFPCCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VVFPCR
			struct VVFPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VVFPCR_0
					struct
					{
						uint32_t VFP                  :10;
						uint32_t                      :22;
					};
					#endif
					#ifdef DSI_VVFPCR_1
					struct
					{
						uint32_t VFP0                 :1;
						uint32_t VFP1                 :1;
						uint32_t VFP2                 :1;
						uint32_t VFP3                 :1;
						uint32_t VFP4                 :1;
						uint32_t VFP5                 :1;
						uint32_t VFP6                 :1;
						uint32_t VFP7                 :1;
						uint32_t VFP8                 :1;
						uint32_t VFP9                 :1;
						uint32_t                      :22;
					};
					#endif
				};
				//SOOL-DSI_VVFPCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VVSACCR
			struct VVSACCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VVSACCR_0
					struct
					{
						uint32_t VSA                  :10;
						uint32_t                      :22;
					};
					#endif
					#ifdef DSI_VVSACCR_1
					struct
					{
						uint32_t VSA0                 :1;
						uint32_t VSA1                 :1;
						uint32_t VSA2                 :1;
						uint32_t VSA3                 :1;
						uint32_t VSA4                 :1;
						uint32_t VSA5                 :1;
						uint32_t VSA6                 :1;
						uint32_t VSA7                 :1;
						uint32_t VSA8                 :1;
						uint32_t VSA9                 :1;
						uint32_t                      :22;
					};
					#endif
				};
				//SOOL-DSI_VVSACCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_VVSACR
			struct VVSACR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_VVSACR_0
					struct
					{
						uint32_t VSA                  :10;
						uint32_t                      :22;
					};
					#endif
					#ifdef DSI_VVSACR_1
					struct
					{
						uint32_t VSA0                 :1;
						uint32_t VSA1                 :1;
						uint32_t VSA2                 :1;
						uint32_t VSA3                 :1;
						uint32_t VSA4                 :1;
						uint32_t VSA5                 :1;
						uint32_t VSA6                 :1;
						uint32_t VSA7                 :1;
						uint32_t VSA8                 :1;
						uint32_t VSA9                 :1;
						uint32_t                      :22;
					};
					#endif
				};
				//SOOL-DSI_VVSACR-DECLARATION
			};
			#endif
			
			#ifdef DSI_WCFGR
			struct WCFGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_WCFGR_0
					struct
					{
						uint32_t DSIM                 :1;
						uint32_t COLMUX               :3;
						uint32_t TESRC                :1;
						uint32_t TEPOL                :1;
						uint32_t AR                   :1;
						uint32_t VSPOL                :1;
						uint32_t                      :24;
					};
					#endif
					#ifdef DSI_WCFGR_1
					struct
					{
						uint32_t                      :1;
						uint32_t COLMUX0              :1;
						uint32_t COLMUX1              :1;
						uint32_t COLMUX2              :1;
						uint32_t                      :28;
					};
					#endif
				};
				//SOOL-DSI_WCFGR-DECLARATION
			};
			#endif
			
			#ifdef DSI_WCR
			struct WCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t COLM                 :1;
					uint32_t SHTDN                :1;
					uint32_t LTDCEN               :1;
					uint32_t DSIEN                :1;
					uint32_t                      :28;
			
				//SOOL-DSI_WCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_WIER
			struct WIER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TEIE                 :1;
					uint32_t ERIE                 :1;
					uint32_t                      :7;
					uint32_t PLLLIE               :1;
					uint32_t PLLUIE               :1;
					uint32_t                      :2;
					uint32_t RRIE                 :1;
					uint32_t                      :18;
			
				//SOOL-DSI_WIER-DECLARATION
			};
			#endif
			
			#ifdef DSI_WIFCR
			struct WIFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CTEIF                :1;
					uint32_t CERIF                :1;
					uint32_t                      :7;
					uint32_t CPLLLIF              :1;
					uint32_t CPLLUIF              :1;
					uint32_t                      :2;
					uint32_t CRRIF                :1;
					uint32_t                      :18;
			
				//SOOL-DSI_WIFCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_WISR
			struct WISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TEIF                 :1;
					uint32_t ERIF                 :1;
					uint32_t BUSY                 :1;
					uint32_t                      :5;
					uint32_t PLLLS                :1;
					uint32_t PLLLIF               :1;
					uint32_t PLLUIF               :1;
					uint32_t                      :1;
					uint32_t RRS                  :1;
					uint32_t RRIF                 :1;
					uint32_t                      :18;
			
				//SOOL-DSI_WISR-DECLARATION
			};
			#endif
			
			#ifdef DSI_WPCR
			struct WPCR_TypeDef : public BigArrayReg_t<uint32_t, 0, 4, 5>
			{
				using BigArrayReg_t<uint32_t, 0, 4, 5>::operator=;
			
				union
				{
					#ifdef DSI_WPCR_0
					struct
					{
						uint32_t UIX4                 :6;
						uint32_t SWCL                 :1;
						uint32_t SWDL0                :1;
						uint32_t SWDL1                :1;
						uint32_t HSICL                :1;
						uint32_t HSIDL0               :1;
						uint32_t HSIDL1               :1;
						uint32_t FTXSMCL              :1;
						uint32_t FTXSMDL              :1;
						uint32_t CDOFFDL              :1;
						uint32_t                      :1;
						uint32_t TDDL                 :1;
						uint32_t                      :1;
						uint32_t PDEN                 :1;
						uint32_t TCLKPREPEN           :1;
						uint32_t TCLKZEROEN           :1;
						uint32_t THSPREPEN            :1;
						uint32_t THSTRAILEN           :1;
						uint32_t THSZEROEN            :1;
						uint32_t TLPXDEN              :1;
						uint32_t THSEXITEN            :1;
						uint32_t TLPXCEN              :1;
						uint32_t TCLKPOSTEN           :1;
						uint32_t                      :4;
						uint32_t HSTXDCL              :2;
						uint32_t HSTXDDL              :2;
						uint32_t                      :2;
						uint32_t LPSRCCL              :2;
						uint32_t LPSRCDL              :2;
						uint32_t                      :2;
						uint32_t SDDC                 :1;
						uint32_t                      :1;
						uint32_t LPRXVCDL             :2;
						uint32_t HSTXSRCCL            :2;
						uint32_t HSTXSRCDL            :2;
						uint32_t                      :2;
						uint32_t FLPRXLPM             :1;
						uint32_t                      :2;
						uint32_t LPRXFT               :2;
						uint32_t                      :5;
						uint32_t TCLKPREP             :8;
						uint32_t TCLKZERO             :8;
						uint32_t THSPREP              :8;
						uint32_t THSTRAIL             :8;
						uint32_t THSZERO              :8;
						uint32_t TLPXD                :8;
						uint32_t THSEXIT              :8;
						uint32_t TLPXC                :8;
						uint32_t TCLKPOST             :8;
						uint32_t                      :24;
					};
					#endif
					#ifdef DSI_WPCR_1
					struct
					{
						uint32_t                      :32;
						uint32_t HSTXDCL0             :1;
						uint32_t HSTXDCL1             :1;
						uint32_t HSTXDDL0             :1;
						uint32_t HSTXDDL1             :1;
						uint32_t                      :2;
						uint32_t LPSRCCL0             :1;
						uint32_t LPSRCCL1             :1;
						uint32_t LPSRCDL0             :1;
						uint32_t LPSRCDL1             :1;
						uint32_t                      :4;
						uint32_t LPRXVCDL0            :1;
						uint32_t LPRXVCDL1            :1;
						uint32_t HSTXSRCCL0           :1;
						uint32_t HSTXSRCCL1           :1;
						uint32_t HSTXSRCDL0           :1;
						uint32_t HSTXSRCDL1           :1;
						uint32_t                      :5;
						uint32_t LPRXFT0              :1;
						uint32_t LPRXFT1              :1;
						uint32_t                      :5;
						uint32_t TCLKPREP0            :1;
						uint32_t TCLKPREP1            :1;
						uint32_t TCLKPREP2            :1;
						uint32_t TCLKPREP3            :1;
						uint32_t TCLKPREP4            :1;
						uint32_t TCLKPREP5            :1;
						uint32_t TCLKPREP6            :1;
						uint32_t TCLKPREP7            :1;
						uint32_t TCLKZERO0            :1;
						uint32_t TCLKZERO1            :1;
						uint32_t TCLKZERO2            :1;
						uint32_t TCLKZERO3            :1;
						uint32_t TCLKZERO4            :1;
						uint32_t TCLKZERO5            :1;
						uint32_t TCLKZERO6            :1;
						uint32_t TCLKZERO7            :1;
						uint32_t THSPREP0             :1;
						uint32_t THSPREP1             :1;
						uint32_t THSPREP2             :1;
						uint32_t THSPREP3             :1;
						uint32_t THSPREP4             :1;
						uint32_t THSPREP5             :1;
						uint32_t THSPREP6             :1;
						uint32_t THSPREP7             :1;
						uint32_t THSTRAIL0            :1;
						uint32_t THSTRAIL1            :1;
						uint32_t THSTRAIL2            :1;
						uint32_t THSTRAIL3            :1;
						uint32_t THSTRAIL4            :1;
						uint32_t THSTRAIL5            :1;
						uint32_t THSTRAIL6            :1;
						uint32_t THSTRAIL7            :1;
						uint32_t THSZERO0             :1;
						uint32_t THSZERO1             :1;
						uint32_t THSZERO2             :1;
						uint32_t THSZERO3             :1;
						uint32_t THSZERO4             :1;
						uint32_t THSZERO5             :1;
						uint32_t THSZERO6             :1;
						uint32_t THSZERO7             :1;
						uint32_t TLPXD0               :1;
						uint32_t TLPXD1               :1;
						uint32_t TLPXD2               :1;
						uint32_t TLPXD3               :1;
						uint32_t TLPXD4               :1;
						uint32_t TLPXD5               :1;
						uint32_t TLPXD6               :1;
						uint32_t TLPXD7               :1;
						uint32_t THSEXIT0             :1;
						uint32_t THSEXIT1             :1;
						uint32_t THSEXIT2             :1;
						uint32_t THSEXIT3             :1;
						uint32_t THSEXIT4             :1;
						uint32_t THSEXIT5             :1;
						uint32_t THSEXIT6             :1;
						uint32_t THSEXIT7             :1;
						uint32_t TLPXC0               :1;
						uint32_t TLPXC1               :1;
						uint32_t TLPXC2               :1;
						uint32_t TLPXC3               :1;
						uint32_t TLPXC4               :1;
						uint32_t TLPXC5               :1;
						uint32_t TLPXC6               :1;
						uint32_t TLPXC7               :1;
						uint32_t TCLKPOST0            :1;
						uint32_t TCLKPOST1            :1;
						uint32_t TCLKPOST2            :1;
						uint32_t TCLKPOST3            :1;
						uint32_t TCLKPOST4            :1;
						uint32_t TCLKPOST5            :1;
						uint32_t TCLKPOST6            :1;
						uint32_t TCLKPOST7            :1;
						uint32_t                      :24;
					};
					#endif
				};
				//SOOL-DSI_WPCR-DECLARATION
			};
			#endif
			
			#ifdef DSI_WRPCR
			struct WRPCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DSI_WRPCR_0
					struct
					{
						uint32_t PLLEN                :1;
						uint32_t                      :1;
						uint32_t PLL_NDIV             :7;
						uint32_t                      :2;
						uint32_t PLL_IDF              :4;
						uint32_t                      :1;
						uint32_t PLL_ODF              :2;
						uint32_t                      :6;
						uint32_t REGEN                :1;
						uint32_t                      :7;
					};
					#endif
					#ifdef DSI_WRPCR_1
					struct
					{
						uint32_t                      :2;
						uint32_t PLL_NDIV0            :1;
						uint32_t PLL_NDIV1            :1;
						uint32_t PLL_NDIV2            :1;
						uint32_t PLL_NDIV3            :1;
						uint32_t PLL_NDIV4            :1;
						uint32_t PLL_NDIV5            :1;
						uint32_t PLL_NDIV6            :1;
						uint32_t                      :2;
						uint32_t PLL_IDF0             :1;
						uint32_t PLL_IDF1             :1;
						uint32_t PLL_IDF2             :1;
						uint32_t PLL_IDF3             :1;
						uint32_t                      :1;
						uint32_t PLL_ODF0             :1;
						uint32_t PLL_ODF1             :1;
						uint32_t                      :14;
					};
					#endif
				};
				//SOOL-DSI_WRPCR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					uint32_t VR;         // @0x000
					CR_TypeDef CR;       // @0x004
					CCR_TypeDef CCR;     // @0x008
					LVCIDR_TypeDef LVCIDR; // @0x00c
					LCOLCR_TypeDef LCOLCR; // @0x010
					LPCR_TypeDef LPCR;   // @0x014
					LPMCR_TypeDef LPMCR; // @0x018
					__SOOL_PERIPH_PADDING_16;
					PCR_TypeDef PCR;     // @0x02c
					GVCIDR_TypeDef GVCIDR; // @0x030
					MCR_TypeDef MCR;     // @0x034
					VMCR_TypeDef VMCR;   // @0x038
					VPCR_TypeDef VPCR;   // @0x03c
					VCCR_TypeDef VCCR;   // @0x040
					VNPCR_TypeDef VNPCR; // @0x044
					VHSACR_TypeDef VHSACR; // @0x048
					VHBPCR_TypeDef VHBPCR; // @0x04c
					VLCR_TypeDef VLCR;   // @0x050
					VVSACR_TypeDef VVSACR; // @0x054
					VVBPCR_TypeDef VVBPCR; // @0x058
					VVFPCR_TypeDef VVFPCR; // @0x05c
					VVACR_TypeDef VVACR; // @0x060
					LCCR_TypeDef LCCR;   // @0x064
					CMCR_TypeDef CMCR;   // @0x068
					GHCR_TypeDef GHCR;   // @0x06c
					GPDR_TypeDef GPDR;   // @0x070
					GPSR_TypeDef GPSR;   // @0x074
					TCCR_TypeDef TCCR;   // @0x078
					DSI_MAP0_TDCR;       // @0x090
					CLCR_TypeDef CLCR;   // @0x094
					CLTCR_TypeDef CLTCR; // @0x098
					DLTCR_TypeDef DLTCR; // @0x09c
					PCTLR_TypeDef PCTLR; // @0x0a0
					PCONFR_TypeDef PCONFR; // @0x0a4
					PUCR_TypeDef PUCR;   // @0x0a8
					PTTCR_TypeDef PTTCR; // @0x0ac
					PSR_TypeDef PSR;     // @0x0b0
					__SOOL_PERIPH_PADDING_8;
					uint64_t ISR;        // @0x0bc
					uint64_t IER;        // @0x0c4
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					uint64_t FIR;        // @0x0d8
					__SOOL_PERIPH_PADDING_32;
					VSCR_TypeDef VSCR;   // @0x100
					__SOOL_PERIPH_PADDING_8;
					LCVCIDR_TypeDef LCVCIDR; // @0x10c
					LCCCR_TypeDef LCCCR; // @0x110
					__SOOL_PERIPH_PADDING_4;
					LPMCCR_TypeDef LPMCCR; // @0x118
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					VMCCR_TypeDef VMCCR; // @0x138
					VPCCR_TypeDef VPCCR; // @0x13c
					VCCCR_TypeDef VCCCR; // @0x140
					VNPCCR_TypeDef VNPCCR; // @0x144
					VHSACCR_TypeDef VHSACCR; // @0x148
					VHBPCCR_TypeDef VHBPCCR; // @0x14c
					VLCCR_TypeDef VLCCR; // @0x150
					VVSACCR_TypeDef VVSACCR; // @0x154
					VVBPCCR_TypeDef VVBPCCR; // @0x158
					VVFPCCR_TypeDef VVFPCCR; // @0x15c
					VVACCR_TypeDef VVACCR; // @0x160
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					DSI_MAP0_TDCCR;      // @0x190
					__SOOL_PERIPH_PADDING_512;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					WCFGR_TypeDef WCFGR; // @0x400
					WCR_TypeDef WCR;     // @0x404
					WIER_TypeDef WIER;   // @0x408
					WISR_TypeDef WISR;   // @0x40c
					WIFCR_TypeDef WIFCR; // @0x410
					__SOOL_PERIPH_PADDING_4;
					WPCR_TypeDef WPCR;   // @0x418
					__SOOL_PERIPH_PADDING_4;
					WRPCR_TypeDef WRPCR; // @0x430
				};
				struct
				{
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ISR0_TypeDef ISR0;   // @0x0bc
					ISR1_TypeDef ISR1;   // @0x0c0
					IER0_TypeDef IER0;   // @0x0c4
					IER1_TypeDef IER1;   // @0x0c8
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					FIR0_TypeDef FIR0;   // @0x0d8
					FIR1_TypeDef FIR1;   // @0x0dc
					__SOOL_PERIPH_PADDING_512;
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_4;
				};
			};
			private:
			DSI() = delete;
			//SOOL-DSI-DECLARATION
		};
		
		//region instances
#if defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F769xx ) || defined(STM32F779xx ) ||\
    defined(STM32L4R9xx ) || defined(STM32L4S9xx ) 
#define DSI_BASE_ADDR ((uint32_t)0x40016C00U)
#endif

#ifdef DSI_BASE_ADDR
volatile class DSI * const DSI = reinterpret_cast<class DSI* const>(DSI_BASE_ADDR);
#endif
//endregion

//SOOL-DSI-DEFINES
//SOOL-DSI-DEFINITION
	};
};//region undef
#undef DSI_MAP0_TDCR
#undef DSI_MAP0_TDCCR
//endregion
#endif
#endif
