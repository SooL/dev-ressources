#ifndef __SOOL_HRTIM_H
#define __SOOL_HRTIM_H

#include "peripheral_include.h"
//SOOL-HRTIM-INCLUDES
#if defined(STM32F334x8 ) || defined(STM32H7     ) 
//region defines

#define HRTIM_Common_ADC1R
#define HRTIM_Common_ADC2R
#define HRTIM_Common_ADC3R
#define HRTIM_Common_ADC4R
#define HRTIM_Common_BDMADR
#define HRTIM_Common_BDMUPR
#define HRTIM_Common_BDTUPR
#define HRTIM_Common_BMCMPR
#define HRTIM_Common_BMCR
#define HRTIM_Common_BMPER
#define HRTIM_Common_BMTRGR
#define HRTIM_Common_CR1
#define HRTIM_Common_CR2
#define HRTIM_Common_DLLCR
#define HRTIM_Common_EECR1
#define HRTIM_Common_EECR2
#define HRTIM_Common_EECR3
#define HRTIM_Common_FLTINR1
#define HRTIM_Common_FLTINR2
#define HRTIM_Common_ICR
#define HRTIM_Common_IER
#define HRTIM_Common_ISR
#define HRTIM_Common_ODISR
#define HRTIM_Common_ODSR
#define HRTIM_Common_OENR
#define HRTIM_Master_MCMP1R
#define HRTIM_Master_MCMP2R
#define HRTIM_Master_MCMP3R
#define HRTIM_Master_MCMP4R
#define HRTIM_Master_MCNTR
#define HRTIM_Master_MCR
#define HRTIM_Master_MDIER
#define HRTIM_Master_MICR
#define HRTIM_Master_MISR
#define HRTIM_Master_MPER
#define HRTIM_Master_MREP
#define HRTIM_Timerx_CHPR
#define HRTIM_Timerx_CMP1CR
#define HRTIM_Timerx_CMP1R
#define HRTIM_Timerx_CMP2R
#define HRTIM_Timerx_CMP3R
#define HRTIM_Timerx_CMP4R
#define HRTIM_Timerx_CNTR
#define HRTIM_Timerx_CPT1CR
#define HRTIM_Timerx_CPT1R
#define HRTIM_Timerx_CPT2CR
#define HRTIM_Timerx_CPT2R
#define HRTIM_Timerx_DTR
#define HRTIM_Timerx_EEFR1
#define HRTIM_Timerx_EEFR2
#define HRTIM_Timerx_FLTR
#define HRTIM_Timerx_OUTR
#define HRTIM_Timerx_PERR
#define HRTIM_Timerx_REPR
#define HRTIM_Timerx_RST1R
#define HRTIM_Timerx_RST2R
#define HRTIM_Timerx_RSTR
#define HRTIM_Timerx_SET1R
#define HRTIM_Timerx_SET2R
#define HRTIM_Timerx_TIMCR
#define HRTIM_Timerx_TIMDIER
#define HRTIM_Timerx_TIMICR
#define HRTIM_Timerx_TIMISR

#if defined(STM32F334x8 ) 
#define HRTIM_Common_ICR_DLLRDYC DLLRDYC              // 1 bits @ 16
#define HRTIM_Common_IER_DLLRDY DLLRDY               // 1 bits @ 16
#define HRTIM_Common_ISR_DLLRDY DLLRDY               // 1 bits @ 16
#define HRTIM_Master_MCMP1R_0
#define HRTIM_Master_MCMP1R_1
#define HRTIM_Master_MCMP1R_2
#define HRTIM_Master_MCMP1R_3
#define HRTIM_Master_MCNTR_0
#define HRTIM_Master_MPER_0
#define HRTIM_Master_MREP_0
#define HRTIM_Timerx_CMP1R_0
#define HRTIM_Timerx_CMP2R_0
#define HRTIM_Timerx_CMP3R_0
#define HRTIM_Timerx_CMP4R_0
#define HRTIM_Timerx_CNTR_0
#define HRTIM_Timerx_CPT1R_0
#define HRTIM_Timerx_CPT2R_0
#define HRTIM_Timerx_PERR_0
#define HRTIM_Timerx_REPR_0
#define HRTIM_Timerx_TIMICR_0_DLYPRT1C DLYPRT1C             // 1 bits @ 14
#define HRTIM_Timerx_TIMICR_0_DLYPRT2C DLYPRT2C             // 1 bits @ 15
#else
#define HRTIM_Common_ICR_DLLRDYC
#define HRTIM_Common_IER_DLLRDY
#define HRTIM_Common_ISR_DLLRDY
#define HRTIM_Timerx_TIMICR_0_DLYPRT1C
#define HRTIM_Timerx_TIMICR_0_DLYPRT2C
#endif

#if defined(STM32H7     ) 
#define HRTIM_Master_MCMP1R_4
#define HRTIM_Master_MCMP1R_5
#define HRTIM_Master_MCMP1R_6
#define HRTIM_Master_MCMP1R_7
#define HRTIM_Master_MCNTR_1
#define HRTIM_Master_MPER_1
#define HRTIM_Master_MREP_1
#define HRTIM_Timerx_CMP1R_1
#define HRTIM_Timerx_CMP2R_1
#define HRTIM_Timerx_CMP3R_1
#define HRTIM_Timerx_CMP4R_1
#define HRTIM_Timerx_CNTR_1
#define HRTIM_Timerx_CPT1R_1
#define HRTIM_Timerx_CPT2R_1
#define HRTIM_Timerx_PERR_1
#define HRTIM_Timerx_REPR_1
#define HRTIM_Timerx_TIMICR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class HRTIM_Common
		{
			//SOOL-HRTIM_Common-ENUMS
			
			public :
			
			#ifdef HRTIM_Common_ADC1R
			struct ADC1R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t AD1MC1               :1;
					uint32_t AD1MC2               :1;
					uint32_t AD1MC3               :1;
					uint32_t AD1MC4               :1;
					uint32_t AD1MPER              :1;
					uint32_t AD1EEV1              :1;
					uint32_t AD1EEV2              :1;
					uint32_t AD1EEV3              :1;
					uint32_t AD1EEV4              :1;
					uint32_t AD1EEV5              :1;
					uint32_t AD1TAC2              :1;
					uint32_t AD1TAC3              :1;
					uint32_t AD1TAC4              :1;
					uint32_t AD1TAPER             :1;
					uint32_t AD1TARST             :1;
					uint32_t AD1TBC2              :1;
					uint32_t AD1TBC3              :1;
					uint32_t AD1TBC4              :1;
					uint32_t AD1TBPER             :1;
					uint32_t AD1TBRST             :1;
					uint32_t AD1TCC2              :1;
					uint32_t AD1TCC3              :1;
					uint32_t AD1TCC4              :1;
					uint32_t AD1TCPER             :1;
					uint32_t AD1TDC2              :1;
					uint32_t AD1TDC3              :1;
					uint32_t AD1TDC4              :1;
					uint32_t AD1TDPER             :1;
					uint32_t AD1TEC2              :1;
					uint32_t AD1TEC3              :1;
					uint32_t AD1TEC4              :1;
					uint32_t AD1TEPER             :1;
			
				//SOOL-HRTIM_Common_ADC1R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_ADC2R
			struct ADC2R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t AD2MC1               :1;
					uint32_t AD2MC2               :1;
					uint32_t AD2MC3               :1;
					uint32_t AD2MC4               :1;
					uint32_t AD2MPER              :1;
					uint32_t AD2EEV6              :1;
					uint32_t AD2EEV7              :1;
					uint32_t AD2EEV8              :1;
					uint32_t AD2EEV9              :1;
					uint32_t AD2EEV10             :1;
					uint32_t AD2TAC2              :1;
					uint32_t AD2TAC3              :1;
					uint32_t AD2TAC4              :1;
					uint32_t AD2TAPER             :1;
					uint32_t AD2TBC2              :1;
					uint32_t AD2TBC3              :1;
					uint32_t AD2TBC4              :1;
					uint32_t AD2TBPER             :1;
					uint32_t AD2TCC2              :1;
					uint32_t AD2TCC3              :1;
					uint32_t AD2TCC4              :1;
					uint32_t AD2TCPER             :1;
					uint32_t AD2TCRST             :1;
					uint32_t AD2TDC2              :1;
					uint32_t AD2TDC3              :1;
					uint32_t AD2TDC4              :1;
					uint32_t AD2TDPER             :1;
					uint32_t AD2TDRST             :1;
					uint32_t AD2TEC2              :1;
					uint32_t AD2TEC3              :1;
					uint32_t AD2TEC4              :1;
					uint32_t AD2TERST             :1;
			
				//SOOL-HRTIM_Common_ADC2R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_ADC3R
			struct ADC3R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t AD3MC1               :1;
					uint32_t AD3MC2               :1;
					uint32_t AD3MC3               :1;
					uint32_t AD3MC4               :1;
					uint32_t AD3MPER              :1;
					uint32_t AD3EEV1              :1;
					uint32_t AD3EEV2              :1;
					uint32_t AD3EEV3              :1;
					uint32_t AD3EEV4              :1;
					uint32_t AD3EEV5              :1;
					uint32_t AD3TAC2              :1;
					uint32_t AD3TAC3              :1;
					uint32_t AD3TAC4              :1;
					uint32_t AD3TAPER             :1;
					uint32_t AD3TARST             :1;
					uint32_t AD3TBC2              :1;
					uint32_t AD3TBC3              :1;
					uint32_t AD3TBC4              :1;
					uint32_t AD3TBPER             :1;
					uint32_t AD3TBRST             :1;
					uint32_t AD3TCC2              :1;
					uint32_t AD3TCC3              :1;
					uint32_t AD3TCC4              :1;
					uint32_t AD3TCPER             :1;
					uint32_t AD3TDC2              :1;
					uint32_t AD3TDC3              :1;
					uint32_t AD3TDC4              :1;
					uint32_t AD3TDPER             :1;
					uint32_t AD3TEC2              :1;
					uint32_t AD3TEC3              :1;
					uint32_t AD3TEC4              :1;
					uint32_t AD3TEPER             :1;
			
				//SOOL-HRTIM_Common_ADC3R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_ADC4R
			struct ADC4R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t AD4MC1               :1;
					uint32_t AD4MC2               :1;
					uint32_t AD4MC3               :1;
					uint32_t AD4MC4               :1;
					uint32_t AD4MPER              :1;
					uint32_t AD4EEV6              :1;
					uint32_t AD4EEV7              :1;
					uint32_t AD4EEV8              :1;
					uint32_t AD4EEV9              :1;
					uint32_t AD4EEV10             :1;
					uint32_t AD4TAC2              :1;
					uint32_t AD4TAC3              :1;
					uint32_t AD4TAC4              :1;
					uint32_t AD4TAPER             :1;
					uint32_t AD4TBC2              :1;
					uint32_t AD4TBC3              :1;
					uint32_t AD4TBC4              :1;
					uint32_t AD4TBPER             :1;
					uint32_t AD4TCC2              :1;
					uint32_t AD4TCC3              :1;
					uint32_t AD4TCC4              :1;
					uint32_t AD4TCPER             :1;
					uint32_t AD4TCRST             :1;
					uint32_t AD4TDC2              :1;
					uint32_t AD4TDC3              :1;
					uint32_t AD4TDC4              :1;
					uint32_t AD4TDPER             :1;
					uint32_t AD4TDRST             :1;
					uint32_t AD4TEC2              :1;
					uint32_t AD4TEC3              :1;
					uint32_t AD4TEC4              :1;
					uint32_t AD4TERST             :1;
			
				//SOOL-HRTIM_Common_ADC4R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_BDMADR
			struct BDMADR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BDMADR               :32;
			
				//SOOL-HRTIM_Common_BDMADR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_BDMUPR
			struct BDMUPR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MCR                  :1;
					uint32_t MICR                 :1;
					uint32_t MDIER                :1;
					uint32_t MCNT                 :1;
					uint32_t MPER                 :1;
					uint32_t MREP                 :1;
					uint32_t MCMP1                :1;
					uint32_t MCMP2                :1;
					uint32_t MCMP3                :1;
					uint32_t MCMP4                :1;
					uint32_t                      :22;
			
				//SOOL-HRTIM_Common_BDMUPR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_BDTUPR
			struct BDTUPR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TIMCR                :1;
					uint32_t TIMICR               :1;
					uint32_t TIMDIER              :1;
					uint32_t TIMCNT               :1;
					uint32_t TIMPER               :1;
					uint32_t TIMREP               :1;
					uint32_t TIMCMP1              :1;
					uint32_t TIMCMP2              :1;
					uint32_t TIMCMP3              :1;
					uint32_t TIMCMP4              :1;
					uint32_t TIMDTR               :1;
					uint32_t TIMSET1R             :1;
					uint32_t TIMRST1R             :1;
					uint32_t TIMSET2R             :1;
					uint32_t TIMRST2R             :1;
					uint32_t TIMEEFR1             :1;
					uint32_t TIMEEFR2             :1;
					uint32_t TIMRSTR              :1;
					uint32_t TIMCHPR              :1;
					uint32_t TIMOUTR              :1;
					uint32_t TIMFLTR              :1;
					uint32_t                      :11;
			
				//SOOL-HRTIM_Common_BDTUPR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_BMCMPR
			struct BMCMPR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BMCMPR               :16;
					uint32_t                      :16;
			
				//SOOL-HRTIM_Common_BMCMPR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_BMCR
			struct BMCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BME                  :1;
					uint32_t BMOM                 :1;
					uint32_t BMCLK                :4;
					uint32_t BMPRSC               :4;
					uint32_t BMPREN               :1;
					uint32_t                      :5;
					uint32_t MTBM                 :1;
					uint32_t TABM                 :1;
					uint32_t TBBM                 :1;
					uint32_t TCBM                 :1;
					uint32_t TDBM                 :1;
					uint32_t TEBM                 :1;
					uint32_t                      :9;
					uint32_t BMSTAT               :1;
			
				//SOOL-HRTIM_Common_BMCR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_BMPER
			struct BMPER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BMPER                :16;
					uint32_t                      :16;
			
				//SOOL-HRTIM_Common_BMPER-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_BMTRGR
			struct BMTRGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SW                   :1;
					uint32_t MSTRST               :1;
					uint32_t MSTREP               :1;
					uint32_t MSTCMP1              :1;
					uint32_t MSTCMP2              :1;
					uint32_t MSTCMP3              :1;
					uint32_t MSTCMP4              :1;
					uint32_t TARST                :1;
					uint32_t TAREP                :1;
					uint32_t TACMP1               :1;
					uint32_t TACMP2               :1;
					uint32_t TBRST                :1;
					uint32_t TBREP                :1;
					uint32_t TBCMP1               :1;
					uint32_t TBCMP2               :1;
					uint32_t TCRST                :1;
					uint32_t TCREP                :1;
					uint32_t TCCMP1               :1;
					uint32_t TCCMP2               :1;
					uint32_t TDRST                :1;
					uint32_t TDREP                :1;
					uint32_t TDCMP1               :1;
					uint32_t TDCMP2               :1;
					uint32_t TERST                :1;
					uint32_t TEREP                :1;
					uint32_t TECMP1               :1;
					uint32_t TECMP2               :1;
					uint32_t TAEEV7               :1;
					uint32_t TDEEV8               :1;
					uint32_t EEV7                 :1;
					uint32_t EEV8                 :1;
					uint32_t OCHPEV               :1;
			
				//SOOL-HRTIM_Common_BMTRGR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_CR1
			struct CR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MUDIS                :1;
					uint32_t TAUDIS               :1;
					uint32_t TBUDIS               :1;
					uint32_t TCUDIS               :1;
					uint32_t TDUDIS               :1;
					uint32_t TEUDIS               :1;
					uint32_t                      :10;
					uint32_t ADC1USRC             :3;
					uint32_t ADC2USRC             :3;
					uint32_t ADC3USRC             :3;
					uint32_t ADC4USRC             :3;
					uint32_t                      :4;
			
				//SOOL-HRTIM_Common_CR1-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_CR2
			struct CR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MSWU                 :1;
					uint32_t TASWU                :1;
					uint32_t TBSWU                :1;
					uint32_t TCSWU                :1;
					uint32_t TDSWU                :1;
					uint32_t TESWU                :1;
					uint32_t                      :2;
					uint32_t MRST                 :1;
					uint32_t TARST                :1;
					uint32_t TBRST                :1;
					uint32_t TCRST                :1;
					uint32_t TDRST                :1;
					uint32_t TERST                :1;
					uint32_t                      :18;
			
				//SOOL-HRTIM_Common_CR2-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_DLLCR
			struct DLLCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CAL                  :1;
					uint32_t CALEN                :1;
					uint32_t CALRTE               :2;
					uint32_t                      :28;
			
				//SOOL-HRTIM_Common_DLLCR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_EECR1
			struct EECR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EE1SRC               :2;
					uint32_t EE1POL               :1;
					uint32_t EE1SNS               :2;
					uint32_t EE1FAST              :1;
					uint32_t EE2SRC               :2;
					uint32_t EE2POL               :1;
					uint32_t EE2SNS               :2;
					uint32_t EE2FAST              :1;
					uint32_t EE3SRC               :2;
					uint32_t EE3POL               :1;
					uint32_t EE3SNS               :2;
					uint32_t EE3FAST              :1;
					uint32_t EE4SRC               :2;
					uint32_t EE4POL               :1;
					uint32_t EE4SNS               :2;
					uint32_t EE4FAST              :1;
					uint32_t EE5SRC               :2;
					uint32_t EE5POL               :1;
					uint32_t EE5SNS               :2;
					uint32_t EE5FAST              :1;
					uint32_t                      :2;
			
				//SOOL-HRTIM_Common_EECR1-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_EECR2
			struct EECR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EE6SRC               :2;
					uint32_t EE6POL               :1;
					uint32_t EE6SNS               :2;
					uint32_t                      :1;
					uint32_t EE7SRC               :2;
					uint32_t EE7POL               :1;
					uint32_t EE7SNS               :2;
					uint32_t                      :1;
					uint32_t EE8SRC               :2;
					uint32_t EE8POL               :1;
					uint32_t EE8SNS               :2;
					uint32_t                      :1;
					uint32_t EE9SRC               :2;
					uint32_t EE9POL               :1;
					uint32_t EE9SNS               :2;
					uint32_t                      :1;
					uint32_t EE10SRC              :2;
					uint32_t EE10POL              :1;
					uint32_t EE10SNS              :2;
					uint32_t                      :3;
			
				//SOOL-HRTIM_Common_EECR2-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_EECR3
			struct EECR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EE6F                 :4;
					uint32_t                      :2;
					uint32_t EE7F                 :4;
					uint32_t                      :2;
					uint32_t EE8F                 :4;
					uint32_t                      :2;
					uint32_t EE9F                 :4;
					uint32_t                      :2;
					uint32_t EE10F                :4;
					uint32_t                      :2;
					uint32_t EEVSD                :2;
			
				//SOOL-HRTIM_Common_EECR3-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_FLTINR1
			struct FLTINR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FLT1E                :1;
					uint32_t FLT1P                :1;
					uint32_t FLT1SRC              :1;
					uint32_t FLT1F                :4;
					uint32_t FLT1LCK              :1;
					uint32_t FLT2E                :1;
					uint32_t FLT2P                :1;
					uint32_t FLT2SRC              :1;
					uint32_t FLT2F                :4;
					uint32_t FLT2LCK              :1;
					uint32_t FLT3E                :1;
					uint32_t FLT3P                :1;
					uint32_t FLT3SRC              :1;
					uint32_t FLT3F                :4;
					uint32_t FLT3LCK              :1;
					uint32_t FLT4E                :1;
					uint32_t FLT4P                :1;
					uint32_t FLT4SRC              :1;
					uint32_t FLT4F                :4;
					uint32_t FLT4LCK              :1;
			
				//SOOL-HRTIM_Common_FLTINR1-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_FLTINR2
			struct FLTINR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FLT5E                :1;
					uint32_t FLT5P                :1;
					uint32_t FLT5SRC              :1;
					uint32_t FLT5F                :4;
					uint32_t FLT5LCK              :1;
					uint32_t                      :16;
					uint32_t FLTSD                :2;
					uint32_t                      :6;
			
				//SOOL-HRTIM_Common_FLTINR2-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FLT1C                :1;
					uint32_t FLT2C                :1;
					uint32_t FLT3C                :1;
					uint32_t FLT4C                :1;
					uint32_t FLT5C                :1;
					uint32_t SYSFLTC              :1;
					uint32_t                      :10;
					uint32_t HRTIM_Common_ICR_DLLRDYC :1;
					uint32_t BMPERC               :1;
					uint32_t                      :14;
			
				//SOOL-HRTIM_Common_ICR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_IER
			struct IER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FLT1                 :1;
					uint32_t FLT2                 :1;
					uint32_t FLT3                 :1;
					uint32_t FLT4                 :1;
					uint32_t FLT5                 :1;
					uint32_t SYSFLT               :1;
					uint32_t                      :10;
					uint32_t HRTIM_Common_IER_DLLRDY :1;
					uint32_t BMPER                :1;
					uint32_t                      :14;
			
				//SOOL-HRTIM_Common_IER-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_ISR
			struct ISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FLT1                 :1;
					uint32_t FLT2                 :1;
					uint32_t FLT3                 :1;
					uint32_t FLT4                 :1;
					uint32_t FLT5                 :1;
					uint32_t SYSFLT               :1;
					uint32_t                      :10;
					uint32_t HRTIM_Common_ISR_DLLRDY :1;
					uint32_t BMPER                :1;
					uint32_t                      :14;
			
				//SOOL-HRTIM_Common_ISR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_ODISR
			struct ODISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TA1ODIS              :1;
					uint32_t TA2ODIS              :1;
					uint32_t TB1ODIS              :1;
					uint32_t TB2ODIS              :1;
					uint32_t TC1ODIS              :1;
					uint32_t TC2ODIS              :1;
					uint32_t TD1ODIS              :1;
					uint32_t TD2ODIS              :1;
					uint32_t TE1ODIS              :1;
					uint32_t TE2ODIS              :1;
					uint32_t                      :22;
			
				//SOOL-HRTIM_Common_ODISR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_ODSR
			struct ODSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TA1ODS               :1;
					uint32_t TA2ODS               :1;
					uint32_t TB1ODS               :1;
					uint32_t TB2ODS               :1;
					uint32_t TC1ODS               :1;
					uint32_t TC2ODS               :1;
					uint32_t TD1ODS               :1;
					uint32_t TD2ODS               :1;
					uint32_t TE1ODS               :1;
					uint32_t TE2ODS               :1;
					uint32_t                      :22;
			
				//SOOL-HRTIM_Common_ODSR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Common_OENR
			struct OENR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TA1OEN               :1;
					uint32_t TA2OEN               :1;
					uint32_t TB1OEN               :1;
					uint32_t TB2OEN               :1;
					uint32_t TC1OEN               :1;
					uint32_t TC2OEN               :1;
					uint32_t TD1OEN               :1;
					uint32_t TD2OEN               :1;
					uint32_t TE1OEN               :1;
					uint32_t TE2OEN               :1;
					uint32_t                      :22;
			
				//SOOL-HRTIM_Common_OENR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR1_TypeDef CR1;     // @0x000
					CR2_TypeDef CR2;     // @0x004
					ISR_TypeDef ISR;     // @0x008
					ICR_TypeDef ICR;     // @0x00c
					IER_TypeDef IER;     // @0x010
					OENR_TypeDef OENR;   // @0x014
					ODISR_TypeDef ODISR; // @0x018
					ODSR_TypeDef ODSR;   // @0x01c
					BMCR_TypeDef BMCR;   // @0x020
					BMTRGR_TypeDef BMTRGR; // @0x024
					BMCMPR_TypeDef BMCMPR; // @0x028
					BMPER_TypeDef BMPER; // @0x02c
					EECR1_TypeDef EECR1; // @0x030
					EECR2_TypeDef EECR2; // @0x034
					EECR3_TypeDef EECR3; // @0x038
					ADC1R_TypeDef ADC1R; // @0x03c
					ADC2R_TypeDef ADC2R; // @0x040
					ADC3R_TypeDef ADC3R; // @0x044
					ADC4R_TypeDef ADC4R; // @0x048
					DLLCR_TypeDef DLLCR; // @0x04c
					FLTINR1_TypeDef FLTINR1; // @0x050
					FLTINR2_TypeDef FLTINR2; // @0x054
					BDMUPR_TypeDef BDMUPR; // @0x058
					BDTUPR_TypeDef BDTAUPR; // @0x05c
					BDTUPR_TypeDef BDTBUPR; // @0x060
					BDTUPR_TypeDef BDTCUPR; // @0x064
					BDTUPR_TypeDef BDTDUPR; // @0x068
					BDTUPR_TypeDef BDTEUPR; // @0x06c
					BDMADR_TypeDef BDMADR; // @0x070
				};
			};
			private:
			HRTIM_Common() = delete;
			//SOOL-HRTIM_Common-DECLARATION
		};
		
		
		class HRTIM_Master
		{
			//SOOL-HRTIM_Master-ENUMS
			
			public :
			
			#ifdef HRTIM_Master_MCMP1R
			struct MCMP1R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Master_MCMP1R_0
					struct
					{
						uint32_t MCMP1R               :32;
					};
					#endif
					#ifdef HRTIM_Master_MCMP1R_1
					struct
					{
						uint32_t MCMP2R               :32;
					};
					#endif
					#ifdef HRTIM_Master_MCMP1R_2
					struct
					{
						uint32_t MCMP3R               :32;
					};
					#endif
					#ifdef HRTIM_Master_MCMP1R_3
					struct
					{
						uint32_t MCMP4R               :32;
					};
					#endif
					#ifdef HRTIM_Master_MCMP1R_4
					struct
					{
						uint32_t MCMP1R               :16;
						uint32_t                      :16;
					};
					#endif
					#ifdef HRTIM_Master_MCMP1R_5
					struct
					{
						uint32_t MCMP2R               :16;
						uint32_t                      :16;
					};
					#endif
					#ifdef HRTIM_Master_MCMP1R_6
					struct
					{
						uint32_t MCMP3R               :16;
						uint32_t                      :16;
					};
					#endif
					#ifdef HRTIM_Master_MCMP1R_7
					struct
					{
						uint32_t MCMP4R               :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-HRTIM_Master_MCMP1R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Master_MCMP2R
			struct MCMP2R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MCMP2R               :32;
			
				//SOOL-HRTIM_Master_MCMP2R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Master_MCMP3R
			struct MCMP3R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MCMP3R               :32;
			
				//SOOL-HRTIM_Master_MCMP3R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Master_MCMP4R
			struct MCMP4R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MCMP4R               :32;
			
				//SOOL-HRTIM_Master_MCMP4R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Master_MCNTR
			struct MCNTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Master_MCNTR_0
					struct
					{
						uint32_t MCNTR                :32;
					};
					#endif
					#ifdef HRTIM_Master_MCNTR_1
					struct
					{
						uint32_t MCNTR                :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-HRTIM_Master_MCNTR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Master_MCR
			struct MCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CK_PSC               :3;
					uint32_t CONT                 :1;
					uint32_t RETRIG               :1;
					uint32_t HALF                 :1;
					uint32_t                      :2;
					uint32_t SYNC_IN              :2;
					uint32_t SYNCRSTM             :1;
					uint32_t SYNCSTRTM            :1;
					uint32_t SYNC_OUT             :2;
					uint32_t SYNC_SRC             :2;
					uint32_t MCEN                 :1;
					uint32_t TACEN                :1;
					uint32_t TBCEN                :1;
					uint32_t TCCEN                :1;
					uint32_t TDCEN                :1;
					uint32_t TECEN                :1;
					uint32_t                      :3;
					uint32_t DACSYNC              :2;
					uint32_t PREEN                :1;
					uint32_t                      :1;
					uint32_t MREPU                :1;
					uint32_t BRSTDMA              :2;
			
				//SOOL-HRTIM_Master_MCR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Master_MDIER
			struct MDIER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MCMP1IE              :1;
					uint32_t MCMP2IE              :1;
					uint32_t MCMP3IE              :1;
					uint32_t MCMP4IE              :1;
					uint32_t MREPIE               :1;
					uint32_t SYNCIE               :1;
					uint32_t MUPDIE               :1;
					uint32_t                      :9;
					uint32_t MCMP1DE              :1;
					uint32_t MCMP2DE              :1;
					uint32_t MCMP3DE              :1;
					uint32_t MCMP4DE              :1;
					uint32_t MREPDE               :1;
					uint32_t SYNCDE               :1;
					uint32_t MUPDDE               :1;
					uint32_t                      :9;
			
				//SOOL-HRTIM_Master_MDIER-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Master_MICR
			struct MICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MCMP1                :1;
					uint32_t MCMP2                :1;
					uint32_t MCMP3                :1;
					uint32_t MCMP4                :1;
					uint32_t MREP                 :1;
					uint32_t SYNC                 :1;
					uint32_t MUPD                 :1;
					uint32_t                      :25;
			
				//SOOL-HRTIM_Master_MICR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Master_MISR
			struct MISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MCMP1                :1;
					uint32_t MCMP2                :1;
					uint32_t MCMP3                :1;
					uint32_t MCMP4                :1;
					uint32_t MREP                 :1;
					uint32_t SYNC                 :1;
					uint32_t MUPD                 :1;
					uint32_t                      :25;
			
				//SOOL-HRTIM_Master_MISR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Master_MPER
			struct MPER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Master_MPER_0
					struct
					{
						uint32_t MPER                 :32;
					};
					#endif
					#ifdef HRTIM_Master_MPER_1
					struct
					{
						uint32_t MPER                 :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-HRTIM_Master_MPER-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Master_MREP
			struct MREP_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Master_MREP_0
					struct
					{
						uint32_t MREP                 :32;
					};
					#endif
					#ifdef HRTIM_Master_MREP_1
					struct
					{
						uint32_t MREP                 :8;
						uint32_t                      :24;
					};
					#endif
				};
				//SOOL-HRTIM_Master_MREP-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					MCR_TypeDef MCR;     // @0x000
					MISR_TypeDef MISR;   // @0x004
					MICR_TypeDef MICR;   // @0x008
					MDIER_TypeDef MDIER; // @0x00c
					MCNTR_TypeDef MCNTR; // @0x010
					MPER_TypeDef MPER;   // @0x014
					MREP_TypeDef MREP;   // @0x018
					MCMP1R_TypeDef MCMP1R; // @0x01c
					__SOOL_PERIPH_PADDING_4;
					MCMP2R_TypeDef MCMP2R; // @0x024
					MCMP3R_TypeDef MCMP3R; // @0x028
					MCMP4R_TypeDef MCMP4R; // @0x02c
				};
			};
			private:
			HRTIM_Master() = delete;
			//SOOL-HRTIM_Master-DECLARATION
		};
		
		
		class HRTIM_Timerx
		{
			//SOOL-HRTIM_Timerx-ENUMS
			
			public :
			
			#ifdef HRTIM_Timerx_CHPR
			struct CHPR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CARFRQ               :4;
					uint32_t CARDTY               :3;
					uint32_t STRPW                :4;
					uint32_t                      :21;
			
				//SOOL-HRTIM_Timerx_CHPR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_CMP1CR
			struct CMP1CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMP1CR               :32;
			
				//SOOL-HRTIM_Timerx_CMP1CR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_CMP1R
			struct CMP1R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Timerx_CMP1R_0
					struct
					{
						uint32_t CMP1R                :32;
					};
					#endif
					#ifdef HRTIM_Timerx_CMP1R_1
					struct
					{
						uint32_t CMP1R                :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-HRTIM_Timerx_CMP1R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_CMP2R
			struct CMP2R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Timerx_CMP2R_0
					struct
					{
						uint32_t CMP2R                :32;
					};
					#endif
					#ifdef HRTIM_Timerx_CMP2R_1
					struct
					{
						uint32_t CMP2R                :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-HRTIM_Timerx_CMP2R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_CMP3R
			struct CMP3R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Timerx_CMP3R_0
					struct
					{
						uint32_t CMP3R                :32;
					};
					#endif
					#ifdef HRTIM_Timerx_CMP3R_1
					struct
					{
						uint32_t CMP3R                :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-HRTIM_Timerx_CMP3R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_CMP4R
			struct CMP4R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Timerx_CMP4R_0
					struct
					{
						uint32_t CMP4R                :32;
					};
					#endif
					#ifdef HRTIM_Timerx_CMP4R_1
					struct
					{
						uint32_t CMP4R                :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-HRTIM_Timerx_CMP4R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_CNTR
			struct CNTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Timerx_CNTR_0
					struct
					{
						uint32_t CNTR                 :32;
					};
					#endif
					#ifdef HRTIM_Timerx_CNTR_1
					struct
					{
						uint32_t CNTR                 :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-HRTIM_Timerx_CNTR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_CPT1CR
			struct CPT1CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SWCPT                :1;
					uint32_t UPDCPT               :1;
					uint32_t EXEV1CPT             :1;
					uint32_t EXEV2CPT             :1;
					uint32_t EXEV3CPT             :1;
					uint32_t EXEV4CPT             :1;
					uint32_t EXEV5CPT             :1;
					uint32_t EXEV6CPT             :1;
					uint32_t EXEV7CPT             :1;
					uint32_t EXEV8CPT             :1;
					uint32_t EXEV9CPT             :1;
					uint32_t EXEV10CPT            :1;
					uint32_t TA1SET               :1;
					uint32_t TA1RST               :1;
					uint32_t TIMACMP1             :1;
					uint32_t TIMACMP2             :1;
					uint32_t TB1SET               :1;
					uint32_t TB1RST               :1;
					uint32_t TIMBCMP1             :1;
					uint32_t TIMBCMP2             :1;
					uint32_t TC1SET               :1;
					uint32_t TC1RST               :1;
					uint32_t TIMCCMP1             :1;
					uint32_t TIMCCMP2             :1;
					uint32_t TD1SET               :1;
					uint32_t TD1RST               :1;
					uint32_t TIMDCMP1             :1;
					uint32_t TIMDCMP2             :1;
					uint32_t TE1SET               :1;
					uint32_t TE1RST               :1;
					uint32_t TIMECMP1             :1;
					uint32_t TIMECMP2             :1;
			
				//SOOL-HRTIM_Timerx_CPT1CR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_CPT1R
			struct CPT1R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Timerx_CPT1R_0
					struct
					{
						uint32_t CPT1R                :32;
					};
					#endif
					#ifdef HRTIM_Timerx_CPT1R_1
					struct
					{
						uint32_t CPT1R                :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-HRTIM_Timerx_CPT1R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_CPT2CR
			struct CPT2CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SWCPT                :1;
					uint32_t UPDCPT               :1;
					uint32_t EXEV1CPT             :1;
					uint32_t EXEV2CPT             :1;
					uint32_t EXEV3CPT             :1;
					uint32_t EXEV4CPT             :1;
					uint32_t EXEV5CPT             :1;
					uint32_t EXEV6CPT             :1;
					uint32_t EXEV7CPT             :1;
					uint32_t EXEV8CPT             :1;
					uint32_t EXEV9CPT             :1;
					uint32_t EXEV10CPT            :1;
					uint32_t TA1SET               :1;
					uint32_t TA1RST               :1;
					uint32_t TIMACMP1             :1;
					uint32_t TIMACMP2             :1;
					uint32_t TB1SET               :1;
					uint32_t TB1RST               :1;
					uint32_t TIMBCMP1             :1;
					uint32_t TIMBCMP2             :1;
					uint32_t TC1SET               :1;
					uint32_t TC1RST               :1;
					uint32_t TIMCCMP1             :1;
					uint32_t TIMCCMP2             :1;
					uint32_t TD1SET               :1;
					uint32_t TD1RST               :1;
					uint32_t TIMDCMP1             :1;
					uint32_t TIMDCMP2             :1;
					uint32_t TE1SET               :1;
					uint32_t TE1RST               :1;
					uint32_t TIMECMP1             :1;
					uint32_t TIMECMP2             :1;
			
				//SOOL-HRTIM_Timerx_CPT2CR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_CPT2R
			struct CPT2R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Timerx_CPT2R_0
					struct
					{
						uint32_t CPT2R                :32;
					};
					#endif
					#ifdef HRTIM_Timerx_CPT2R_1
					struct
					{
						uint32_t CPT2R                :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-HRTIM_Timerx_CPT2R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_DTR
			struct DTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t DTR                  :9;
						uint32_t SDTR                 :1;
						uint32_t DTPRSC               :3;
						uint32_t                      :1;
						uint32_t DTRSLK               :1;
						uint32_t DTRLK                :1;
						uint32_t DTF                  :9;
						uint32_t SDTF                 :1;
						uint32_t                      :4;
						uint32_t DTFSLK               :1;
						uint32_t DTFLK                :1;
					};
					struct
					{
						uint32_t DT0                  :1;
						uint32_t DT1                  :1;
						uint32_t DT2                  :1;
						uint32_t DT3                  :1;
						uint32_t DT4                  :1;
						uint32_t DT5                  :1;
						uint32_t DT6                  :1;
						uint32_t DT7                  :1;
						uint32_t DT8                  :1;
						uint32_t                      :23;
					};
				};
				//SOOL-HRTIM_Timerx_DTR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_EEFR1
			struct EEFR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EE1LTCH              :1;
					uint32_t EE1FLTR              :4;
					uint32_t                      :1;
					uint32_t EE2LTCH              :1;
					uint32_t EE2FLTR              :4;
					uint32_t                      :1;
					uint32_t EE3LTCH              :1;
					uint32_t EE3FLTR              :4;
					uint32_t                      :1;
					uint32_t EE4LTCH              :1;
					uint32_t EE4FLTR              :4;
					uint32_t                      :1;
					uint32_t EE5LTCH              :1;
					uint32_t EE5FLTR              :4;
					uint32_t                      :3;
			
				//SOOL-HRTIM_Timerx_EEFR1-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_EEFR2
			struct EEFR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EE6LTCH              :1;
					uint32_t EE6FLTR              :4;
					uint32_t                      :1;
					uint32_t EE7LTCH              :1;
					uint32_t EE7FLTR              :4;
					uint32_t                      :1;
					uint32_t EE8LTCH              :1;
					uint32_t EE8FLTR              :4;
					uint32_t                      :1;
					uint32_t EE9LTCH              :1;
					uint32_t EE9FLTR              :4;
					uint32_t                      :1;
					uint32_t EE10LTCH             :1;
					uint32_t EE10FLTR             :4;
					uint32_t                      :3;
			
				//SOOL-HRTIM_Timerx_EEFR2-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_FLTR
			struct FLTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FLT1EN               :1;
					uint32_t FLT2EN               :1;
					uint32_t FLT3EN               :1;
					uint32_t FLT4EN               :1;
					uint32_t FLT5EN               :1;
					uint32_t                      :26;
					uint32_t FLTLCK               :1;
			
				//SOOL-HRTIM_Timerx_FLTR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_OUTR
			struct OUTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :1;
					uint32_t POL1                 :1;
					uint32_t IDLM1                :1;
					uint32_t IDLES1               :1;
					uint32_t FAULT1               :2;
					uint32_t CHP1                 :1;
					uint32_t DIDL1                :1;
					uint32_t DTEN                 :1;
					uint32_t DLYPRTEN             :1;
					uint32_t DLYPRT               :3;
					uint32_t                      :4;
					uint32_t POL2                 :1;
					uint32_t IDLM2                :1;
					uint32_t IDLES2               :1;
					uint32_t FAULT2               :2;
					uint32_t CHP2                 :1;
					uint32_t DIDL2                :1;
					uint32_t                      :8;
			
				//SOOL-HRTIM_Timerx_OUTR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_PERR
			struct PERR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Timerx_PERR_0
					struct
					{
						uint32_t PER                  :32;
					};
					#endif
					#ifdef HRTIM_Timerx_PERR_1
					struct
					{
						uint32_t PER                  :16;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-HRTIM_Timerx_PERR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_REPR
			struct REPR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HRTIM_Timerx_REPR_0
					struct
					{
						uint32_t REP                  :32;
					};
					#endif
					#ifdef HRTIM_Timerx_REPR_1
					struct
					{
						uint32_t REP                  :8;
						uint32_t                      :24;
					};
					#endif
				};
				//SOOL-HRTIM_Timerx_REPR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_RST1R
			struct RST1R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SRT                  :1;
					uint32_t RESYNC               :1;
					uint32_t PER                  :1;
					uint32_t CMP1                 :1;
					uint32_t CMP2                 :1;
					uint32_t CMP3                 :1;
					uint32_t CMP4                 :1;
					uint32_t MSTPER               :1;
					uint32_t MSTCMP1              :1;
					uint32_t MSTCMP2              :1;
					uint32_t MSTCMP3              :1;
					uint32_t MSTCMP4              :1;
					uint32_t TIMEVNT1             :1;
					uint32_t TIMEVNT2             :1;
					uint32_t TIMEVNT3             :1;
					uint32_t TIMEVNT4             :1;
					uint32_t TIMEVNT5             :1;
					uint32_t TIMEVNT6             :1;
					uint32_t TIMEVNT7             :1;
					uint32_t TIMEVNT8             :1;
					uint32_t TIMEVNT9             :1;
					uint32_t EXTVNT1              :1;
					uint32_t EXTVNT2              :1;
					uint32_t EXTVNT3              :1;
					uint32_t EXTVNT4              :1;
					uint32_t EXTVNT5              :1;
					uint32_t EXTVNT6              :1;
					uint32_t EXTVNT7              :1;
					uint32_t EXTVNT8              :1;
					uint32_t EXTVNT9              :1;
					uint32_t EXTVNT10             :1;
					uint32_t UPDATE               :1;
			
				//SOOL-HRTIM_Timerx_RST1R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_RST2R
			struct RST2R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SRT                  :1;
					uint32_t RESYNC               :1;
					uint32_t PER                  :1;
					uint32_t CMP1                 :1;
					uint32_t CMP2                 :1;
					uint32_t CMP3                 :1;
					uint32_t CMP4                 :1;
					uint32_t MSTPER               :1;
					uint32_t MSTCMP1              :1;
					uint32_t MSTCMP2              :1;
					uint32_t MSTCMP3              :1;
					uint32_t MSTCMP4              :1;
					uint32_t TIMEVNT1             :1;
					uint32_t TIMEVNT2             :1;
					uint32_t TIMEVNT3             :1;
					uint32_t TIMEVNT4             :1;
					uint32_t TIMEVNT5             :1;
					uint32_t TIMEVNT6             :1;
					uint32_t TIMEVNT7             :1;
					uint32_t TIMEVNT8             :1;
					uint32_t TIMEVNT9             :1;
					uint32_t EXTVNT1              :1;
					uint32_t EXTVNT2              :1;
					uint32_t EXTVNT3              :1;
					uint32_t EXTVNT4              :1;
					uint32_t EXTVNT5              :1;
					uint32_t EXTVNT6              :1;
					uint32_t EXTVNT7              :1;
					uint32_t EXTVNT8              :1;
					uint32_t EXTVNT9              :1;
					uint32_t EXTVNT10             :1;
					uint32_t UPDATE               :1;
			
				//SOOL-HRTIM_Timerx_RST2R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_RSTR
			struct RSTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :1;
					uint32_t UPDATE               :1;
					uint32_t CMP2                 :1;
					uint32_t CMP4                 :1;
					uint32_t MSTPER               :1;
					uint32_t MSTCMP1              :1;
					uint32_t MSTCMP2              :1;
					uint32_t MSTCMP3              :1;
					uint32_t MSTCMP4              :1;
					uint32_t EXTEVNT1             :1;
					uint32_t EXTEVNT2             :1;
					uint32_t EXTEVNT3             :1;
					uint32_t EXTEVNT4             :1;
					uint32_t EXTEVNT5             :1;
					uint32_t EXTEVNT6             :1;
					uint32_t EXTEVNT7             :1;
					uint32_t EXTEVNT8             :1;
					uint32_t EXTEVNT9             :1;
					uint32_t EXTEVNT10            :1;
					uint32_t TIMBCMP1             :1;
					uint32_t TIMBCMP2             :1;
					uint32_t TIMBCMP4             :1;
					uint32_t TIMCCMP1             :1;
					uint32_t TIMCCMP2             :1;
					uint32_t TIMCCMP4             :1;
					uint32_t TIMDCMP1             :1;
					uint32_t TIMDCMP2             :1;
					uint32_t TIMDCMP4             :1;
					uint32_t TIMECMP1             :1;
					uint32_t TIMECMP2             :1;
					uint32_t TIMECMP4             :1;
					uint32_t                      :1;
			
				//SOOL-HRTIM_Timerx_RSTR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_SET1R
			struct SET1R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SST                  :1;
					uint32_t RESYNC               :1;
					uint32_t PER                  :1;
					uint32_t CMP1                 :1;
					uint32_t CMP2                 :1;
					uint32_t CMP3                 :1;
					uint32_t CMP4                 :1;
					uint32_t MSTPER               :1;
					uint32_t MSTCMP1              :1;
					uint32_t MSTCMP2              :1;
					uint32_t MSTCMP3              :1;
					uint32_t MSTCMP4              :1;
					uint32_t TIMEVNT1             :1;
					uint32_t TIMEVNT2             :1;
					uint32_t TIMEVNT3             :1;
					uint32_t TIMEVNT4             :1;
					uint32_t TIMEVNT5             :1;
					uint32_t TIMEVNT6             :1;
					uint32_t TIMEVNT7             :1;
					uint32_t TIMEVNT8             :1;
					uint32_t TIMEVNT9             :1;
					uint32_t EXTVNT1              :1;
					uint32_t EXTVNT2              :1;
					uint32_t EXTVNT3              :1;
					uint32_t EXTVNT4              :1;
					uint32_t EXTVNT5              :1;
					uint32_t EXTVNT6              :1;
					uint32_t EXTVNT7              :1;
					uint32_t EXTVNT8              :1;
					uint32_t EXTVNT9              :1;
					uint32_t EXTVNT10             :1;
					uint32_t UPDATE               :1;
			
				//SOOL-HRTIM_Timerx_SET1R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_SET2R
			struct SET2R_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SST                  :1;
					uint32_t RESYNC               :1;
					uint32_t PER                  :1;
					uint32_t CMP1                 :1;
					uint32_t CMP2                 :1;
					uint32_t CMP3                 :1;
					uint32_t CMP4                 :1;
					uint32_t MSTPER               :1;
					uint32_t MSTCMP1              :1;
					uint32_t MSTCMP2              :1;
					uint32_t MSTCMP3              :1;
					uint32_t MSTCMP4              :1;
					uint32_t TIMEVNT1             :1;
					uint32_t TIMEVNT2             :1;
					uint32_t TIMEVNT3             :1;
					uint32_t TIMEVNT4             :1;
					uint32_t TIMEVNT5             :1;
					uint32_t TIMEVNT6             :1;
					uint32_t TIMEVNT7             :1;
					uint32_t TIMEVNT8             :1;
					uint32_t TIMEVNT9             :1;
					uint32_t EXTVNT1              :1;
					uint32_t EXTVNT2              :1;
					uint32_t EXTVNT3              :1;
					uint32_t EXTVNT4              :1;
					uint32_t EXTVNT5              :1;
					uint32_t EXTVNT6              :1;
					uint32_t EXTVNT7              :1;
					uint32_t EXTVNT8              :1;
					uint32_t EXTVNT9              :1;
					uint32_t EXTVNT10             :1;
					uint32_t UPDATE               :1;
			
				//SOOL-HRTIM_Timerx_SET2R-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_TIMCR
			struct TIMCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CK_PSC               :3;
					uint32_t CONT                 :1;
					uint32_t RETRIG               :1;
					uint32_t HALF                 :1;
					uint32_t PSHPLL               :1;
					uint32_t                      :3;
					uint32_t SYNCRST              :1;
					uint32_t SYNCSTRT             :1;
					uint32_t DELCMP2              :2;
					uint32_t DELCMP4              :2;
					uint32_t                      :1;
					uint32_t TREPU                :1;
					uint32_t TRSTU                :1;
					uint32_t TAU                  :1;
					uint32_t TBU                  :1;
					uint32_t TCU                  :1;
					uint32_t TDU                  :1;
					uint32_t TEU                  :1;
					uint32_t MSTU                 :1;
					uint32_t DACSYNC              :2;
					uint32_t PREEN                :1;
					uint32_t UPDGAT               :4;
			
				//SOOL-HRTIM_Timerx_TIMCR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_TIMDIER
			struct TIMDIER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMP1IE               :1;
					uint32_t CMP2IE               :1;
					uint32_t CMP3IE               :1;
					uint32_t CMP4IE               :1;
					uint32_t REPIE                :1;
					uint32_t                      :1;
					uint32_t UPDIE                :1;
					uint32_t CPT1IE               :1;
					uint32_t CPT2IE               :1;
					uint32_t SET1IE               :1;
					uint32_t RST1IE               :1;
					uint32_t SET2IE               :1;
					uint32_t RST2IE               :1;
					uint32_t RSTIE                :1;
					uint32_t DLYPRTIE             :1;
					uint32_t                      :1;
					uint32_t CMP1DE               :1;
					uint32_t CMP2DE               :1;
					uint32_t CMP3DE               :1;
					uint32_t CMP4DE               :1;
					uint32_t REPDE                :1;
					uint32_t                      :1;
					uint32_t UPDDE                :1;
					uint32_t CPT1DE               :1;
					uint32_t CPT2DE               :1;
					uint32_t SET1DE               :1;
					uint32_t RST1DE               :1;
					uint32_t SET2DE               :1;
					uint32_t RST2DE               :1;
					uint32_t RSTDE                :1;
					uint32_t DLYPRTDE             :1;
					uint32_t                      :1;
			
				//SOOL-HRTIM_Timerx_TIMDIER-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_TIMICR
			struct TIMICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t CMP1C                :1;
						uint32_t CMP2C                :1;
						uint32_t CMP3C                :1;
						uint32_t CMP4C                :1;
						uint32_t REPC                 :1;
						uint32_t                      :1;
						uint32_t UPDC                 :1;
						uint32_t CPT1C                :1;
						uint32_t CPT2C                :1;
						uint32_t SET1C                :1;
						uint32_t RST1C                :1;
						uint32_t SET2C                :1;
						uint32_t RST2C                :1;
						uint32_t RSTC                 :1;
						uint32_t HRTIM_Timerx_TIMICR_0_DLYPRT1C :1;
						uint32_t HRTIM_Timerx_TIMICR_0_DLYPRT2C :1;
						uint32_t                      :16;
					};
					#ifdef HRTIM_Timerx_TIMICR_1
					struct
					{
						uint32_t                      :14;
						uint32_t DLYPRTC              :1;
						uint32_t                      :17;
					};
					#endif
				};
				//SOOL-HRTIM_Timerx_TIMICR-DECLARATION
			};
			#endif
			
			#ifdef HRTIM_Timerx_TIMISR
			struct TIMISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CMP1                 :1;
					uint32_t CMP2                 :1;
					uint32_t CMP3                 :1;
					uint32_t CMP4                 :1;
					uint32_t REP                  :1;
					uint32_t                      :1;
					uint32_t UPD                  :1;
					uint32_t CPT1                 :1;
					uint32_t CPT2                 :1;
					uint32_t SET1                 :1;
					uint32_t RST1                 :1;
					uint32_t SET2                 :1;
					uint32_t RST2                 :1;
					uint32_t RST                  :1;
					uint32_t DLYPRT               :1;
					uint32_t                      :1;
					uint32_t CPPSTAT              :1;
					uint32_t IPPSTAT              :1;
					uint32_t O1STAT               :1;
					uint32_t O2STAT               :1;
					uint32_t O1CPY                :1;
					uint32_t O2CPY                :1;
					uint32_t                      :10;
			
				//SOOL-HRTIM_Timerx_TIMISR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					TIMCR_TypeDef TIMCR; // @0x000
					TIMISR_TypeDef TIMISR; // @0x004
					TIMICR_TypeDef TIMICR; // @0x008
					TIMDIER_TypeDef TIMDIER; // @0x00c
					CNTR_TypeDef CNTR;   // @0x010
					PERR_TypeDef PERR;   // @0x014
					REPR_TypeDef REPR;   // @0x018
					CMP1R_TypeDef CMP1R; // @0x01c
					CMP1CR_TypeDef CMP1CR; // @0x020
					CMP2R_TypeDef CMP2R; // @0x024
					CMP3R_TypeDef CMP3R; // @0x028
					CMP4R_TypeDef CMP4R; // @0x02c
					CPT1R_TypeDef CPT1R; // @0x030
					CPT2R_TypeDef CPT2R; // @0x034
					DTR_TypeDef DTR;     // @0x038
					SET1R_TypeDef SET1R; // @0x03c
					RST1R_TypeDef RST1R; // @0x040
					SET2R_TypeDef SET2R; // @0x044
					RST2R_TypeDef RST2R; // @0x048
					EEFR1_TypeDef EEFR1; // @0x04c
					EEFR2_TypeDef EEFR2; // @0x050
					RSTR_TypeDef RSTR;   // @0x054
					CHPR_TypeDef CHPR;   // @0x058
					CPT1CR_TypeDef CPT1CR; // @0x05c
					CPT2CR_TypeDef CPT2CR; // @0x060
					OUTR_TypeDef OUTR;   // @0x064
					FLTR_TypeDef FLTR;   // @0x068
				};
			};
			private:
			HRTIM_Timerx() = delete;
			//SOOL-HRTIM_Timerx-DECLARATION
		};
		
		//region instances
#define HRTIM1_BASE_ADDR ((uint32_t)0x40017400U)
#if defined(STM32F334x8 ) || defined(STM32H7     ) 
#define HRTIM1_COMMON_BASE_ADDR ((uint32_t)0x40017780U)
#endif

#ifdef HRTIM1_BASE_ADDR
volatile class HRTIM * const HRTIM1 = reinterpret_cast<class HRTIM* const>(HRTIM1_BASE_ADDR);
#endif
#ifdef HRTIM1_COMMON_BASE_ADDR
volatile class HRTIM_Common * const HRTIM1_COMMON = reinterpret_cast<class HRTIM_Common* const>(HRTIM1_COMMON_BASE_ADDR);
#endif
//endregion

//SOOL-HRTIM-DEFINES
//SOOL-HRTIM-DEFINITION
	};
};//region undef
#undef HRTIM_Common_ICR_DLLRDYC
#undef HRTIM_Common_IER_DLLRDY
#undef HRTIM_Common_ISR_DLLRDY
#undef HRTIM_Timerx_TIMICR_0_DLYPRT1C
#undef HRTIM_Timerx_TIMICR_0_DLYPRT2C
//endregion
#endif
#endif
