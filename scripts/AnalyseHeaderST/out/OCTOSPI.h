#ifndef __SOOL_OCTOSPI_H
#define __SOOL_OCTOSPI_H

#include "peripheral_include.h"
//SOOL-OCTOSPI-INCLUDES
#if defined(STM32L4P    ) 
//region defines

#define OCTOSPI_ABR
#define OCTOSPI_AR
#define OCTOSPI_CCR
#define OCTOSPI_CR
#define OCTOSPI_DCR1
#define OCTOSPI_DCR2
#define OCTOSPI_DCR3
#define OCTOSPI_DLR
#define OCTOSPI_DR
#define OCTOSPI_FCR
#define OCTOSPI_HLCR
#define OCTOSPI_IR
#define OCTOSPI_LPTR
#define OCTOSPI_PIR
#define OCTOSPI_PSMAR
#define OCTOSPI_PSMKR
#define OCTOSPI_SR
#define OCTOSPI_TCR
#define OCTOSPI_VERR
#define OCTOSPI_WABR
#define OCTOSPI_WCCR
#define OCTOSPI_WIR
#define OCTOSPI_WTCR

//endregion

namespace sool
{
	namespace core
	{
		class OCTOSPI
		{
			//SOOL-OCTOSPI-ENUMS
			
			public :
			
			#ifdef OCTOSPI_ABR
			struct ABR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ALTERNATE            :32;
			
				//SOOL-OCTOSPI_ABR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_AR
			struct AR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ADDRESS              :32;
			
				//SOOL-OCTOSPI_AR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_CCR
			struct CCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IMODE                :3;
					uint32_t IDTR                 :1;
					uint32_t ISIZE                :2;
					uint32_t                      :2;
					uint32_t ADMODE               :3;
					uint32_t ADDTR                :1;
					uint32_t ADSIZE               :2;
					uint32_t                      :2;
					uint32_t ABMODE               :3;
					uint32_t ABDTR                :1;
					uint32_t ABSIZE               :2;
					uint32_t                      :2;
					uint32_t DMODE                :3;
					uint32_t DDTR                 :1;
					uint32_t                      :1;
					uint32_t DQSE                 :1;
					uint32_t                      :1;
					uint32_t SIOO                 :1;
			
				//SOOL-OCTOSPI_CCR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EN                   :1;
					uint32_t ABORT                :1;
					uint32_t DMAEN                :1;
					uint32_t TCEN                 :1;
					uint32_t                      :2;
					uint32_t DQM                  :1;
					uint32_t FSEL                 :1;
					uint32_t FTHRES               :5;
					uint32_t                      :3;
					uint32_t TEIE                 :1;
					uint32_t TCIE                 :1;
					uint32_t FTIE                 :1;
					uint32_t SMIE                 :1;
					uint32_t TOIE                 :1;
					uint32_t                      :1;
					uint32_t APMS                 :1;
					uint32_t PMM                  :1;
					uint32_t                      :4;
					uint32_t FMODE                :2;
					uint32_t                      :2;
			
				//SOOL-OCTOSPI_CR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_DCR1
			struct DCR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CKMODE               :1;
					uint32_t FRCK                 :1;
					uint32_t                      :6;
					uint32_t CSHT                 :3;
					uint32_t                      :5;
					uint32_t DEVSIZE              :5;
					uint32_t                      :3;
					uint32_t MTYP                 :3;
					uint32_t                      :5;
			
				//SOOL-OCTOSPI_DCR1-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_DCR2
			struct DCR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PRESCALER            :8;
					uint32_t                      :8;
					uint32_t WRAPSIZE             :3;
					uint32_t                      :13;
			
				//SOOL-OCTOSPI_DCR2-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_DCR3
			struct DCR3_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :16;
					uint32_t CSBOUND              :5;
					uint32_t                      :11;
			
				//SOOL-OCTOSPI_DCR3-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_DLR
			struct DLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DL                   :32;
			
				//SOOL-OCTOSPI_DLR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_DR
			struct DR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATA                 :32;
			
				//SOOL-OCTOSPI_DR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_FCR
			struct FCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CTEF                 :1;
					uint32_t CTCF                 :1;
					uint32_t                      :1;
					uint32_t CSMF                 :1;
					uint32_t                      :4;
					uint32_t TOF                  :1;
					uint32_t                      :23;
			
				//SOOL-OCTOSPI_FCR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_HLCR
			struct HLCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t LM                   :1;
					uint32_t WZL                  :1;
					uint32_t                      :6;
					uint32_t TACC                 :8;
					uint32_t TRWR                 :8;
					uint32_t                      :8;
			
				//SOOL-OCTOSPI_HLCR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_IR
			struct IR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INSTRUCTION          :32;
			
				//SOOL-OCTOSPI_IR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_LPTR
			struct LPTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TIMEOUT              :16;
					uint32_t                      :16;
			
				//SOOL-OCTOSPI_LPTR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_PIR
			struct PIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INTERVAL             :16;
					uint32_t                      :16;
			
				//SOOL-OCTOSPI_PIR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_PSMAR
			struct PSMAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MATCH                :32;
			
				//SOOL-OCTOSPI_PSMAR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_PSMKR
			struct PSMKR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MASK                 :32;
			
				//SOOL-OCTOSPI_PSMKR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TEF                  :1;
					uint32_t TCF                  :1;
					uint32_t FTF                  :1;
					uint32_t SMF                  :1;
					uint32_t TOF                  :1;
					uint32_t BUSY                 :1;
					uint32_t                      :2;
					uint32_t FLEVEL               :6;
					uint32_t                      :18;
			
				//SOOL-OCTOSPI_SR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_TCR
			struct TCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DCYC                 :5;
					uint32_t                      :23;
					uint32_t DHQC                 :1;
					uint32_t                      :1;
					uint32_t SSHIFT               :1;
					uint32_t                      :1;
			
				//SOOL-OCTOSPI_TCR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_VERR
			struct VERR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MINREV               :4;
					uint32_t MAJREV               :4;
					uint32_t                      :24;
			
				//SOOL-OCTOSPI_VERR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_WABR
			struct WABR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ALTERNATE            :32;
			
				//SOOL-OCTOSPI_WABR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_WCCR
			struct WCCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IMODE                :3;
					uint32_t IDTR                 :1;
					uint32_t ISIZE                :2;
					uint32_t                      :2;
					uint32_t ADMODE               :3;
					uint32_t ADDTR                :1;
					uint32_t ADSIZE               :2;
					uint32_t                      :2;
					uint32_t ABMODE               :3;
					uint32_t ABDTR                :1;
					uint32_t ABSIZE               :2;
					uint32_t                      :2;
					uint32_t DMODE                :3;
					uint32_t DDTR                 :1;
					uint32_t                      :1;
					uint32_t DQSE                 :1;
					uint32_t                      :1;
					uint32_t SIOO                 :1;
			
				//SOOL-OCTOSPI_WCCR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_WIR
			struct WIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INSTRUCTION          :32;
			
				//SOOL-OCTOSPI_WIR-DECLARATION
			};
			#endif
			
			#ifdef OCTOSPI_WTCR
			struct WTCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DCYC                 :5;
					uint32_t                      :27;
			
				//SOOL-OCTOSPI_WTCR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					__SOOL_PERIPH_PADDING_4;
					DCR1_TypeDef DCR1;   // @0x008
					DCR2_TypeDef DCR2;   // @0x00c
					DCR3_TypeDef DCR3;   // @0x010
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					SR_TypeDef SR;       // @0x020
					FCR_TypeDef FCR;     // @0x024
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					DLR_TypeDef DLR;     // @0x040
					__SOOL_PERIPH_PADDING_4;
					AR_TypeDef AR;       // @0x048
					__SOOL_PERIPH_PADDING_4;
					DR_TypeDef DR;       // @0x050
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					PSMKR_TypeDef PSMKR; // @0x080
					__SOOL_PERIPH_PADDING_4;
					PSMAR_TypeDef PSMAR; // @0x088
					__SOOL_PERIPH_PADDING_4;
					PIR_TypeDef PIR;     // @0x090
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					CCR_TypeDef CCR;     // @0x100
					__SOOL_PERIPH_PADDING_4;
					TCR_TypeDef TCR;     // @0x108
					__SOOL_PERIPH_PADDING_4;
					IR_TypeDef IR;       // @0x110
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					ABR_TypeDef ABR;     // @0x120
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					LPTR_TypeDef LPTR;   // @0x130
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					WCCR_TypeDef WCCR;   // @0x180
					__SOOL_PERIPH_PADDING_4;
					WTCR_TypeDef WTCR;   // @0x188
					__SOOL_PERIPH_PADDING_4;
					WIR_TypeDef WIR;     // @0x190
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					WABR_TypeDef WABR;   // @0x1a0
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
					HLCR_TypeDef HLCR;   // @0x200
					__SOOL_PERIPH_PADDING_256;
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					VERR_TypeDef VERR;   // @0x3f4
				};
			};
			private:
			OCTOSPI() = delete;
			//SOOL-OCTOSPI-DECLARATION
		};
		
		//region instances
#define OCTOSPI1_BASE_ADDR ((uint32_t)0xA0001000U)
#define OCTOSPI2_BASE_ADDR ((uint32_t)0xA0001400U)
#ifdef OCTOSPI1_BASE_ADDR
volatile class OCTOSPI * const OCTOSPI1 = reinterpret_cast<class OCTOSPI* const>(OCTOSPI1_BASE_ADDR);
#endif
#ifdef OCTOSPI2_BASE_ADDR
volatile class OCTOSPI * const OCTOSPI2 = reinterpret_cast<class OCTOSPI* const>(OCTOSPI2_BASE_ADDR);
#endif
//endregion

//SOOL-OCTOSPI-DEFINES
//SOOL-OCTOSPI-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
