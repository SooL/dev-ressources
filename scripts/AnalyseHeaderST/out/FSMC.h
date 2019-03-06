#ifndef __SOOL_FSMC_H
#define __SOOL_FSMC_H

#include "peripheral_include.h"
//SOOL-FSMC-INCLUDES
#if defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F2     ) || defined(STM32F405xx ) || defined(STM32F407xx ) ||\
    defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32L151xD ) ||\
    defined(STM32L152xD ) || defined(STM32L162xD ) 
//region defines

#if defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) || defined(STM32F103xG ) ||\
    defined(STM32F2     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) 
#define FSMC_ECCR
#define FSMC_PATT
#define FSMC_PCR
#define FSMC_PMEM
#define FSMC_SR
#endif

#define FSMC_Bank1_BCR
#define FSMC_Bank1_BCR1
#define FSMC_Bank1_BTCR
#define FSMC_Bank1_BTR
#define FSMC_Bank1E_BWTR
#define FSMC_Bank4_PIO4

#if defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F2     ) || defined(STM32F405xx ) || defined(STM32F407xx ) ||\
    defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32L151xD ) || defined(STM32L152xD ) ||\
    defined(STM32L162xD ) 
#define FSMC_Bank1_BCR_WRAPMOD WRAPMOD              // 1 bits @ 10
#define FSMC_Bank1_BTCR_WRAPMOD WRAPMOD              // 1 bits @ 42
#else
#define FSMC_Bank1_BCR_WRAPMOD
#define FSMC_Bank1_BTCR_WRAPMOD
#endif

#if defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) ||\
    defined(STM32F412Zx ) || defined(STM32F413xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F423xx ) 
#define FSMC_Bank1_BCR_CPSIZE CPSIZE               // 3 bits @ 16
#define FSMC_Bank1_BCR1_CPSIZE CPSIZE               // 3 bits @ 16
#define FSMC_Bank1_BTCR_CPSIZE CPSIZE               // 3 bits @ 48
#else
#define FSMC_Bank1_BCR_CPSIZE
#define FSMC_Bank1_BCR1_CPSIZE
#define FSMC_Bank1_BTCR_CPSIZE
#endif

#if defined(STM32F2     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) 
#define FSMC_Bank1_BCR1_WRAPMOD WRAPMOD              // 1 bits @ 10
#else
#define FSMC_Bank1_BCR1_WRAPMOD
#endif

#if defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) 
#define FSMC_Bank1_BCR1_CCLKEN CCLKEN               // 1 bits @ 20
#define FSMC_Bank1_BCR1_WFDIS WFDIS                // 1 bits @ 21
#else
#define FSMC_Bank1_BCR1_CCLKEN
#define FSMC_Bank1_BCR1_WFDIS
#endif

#if defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) || defined(STM32F103xG ) ||\
    defined(STM32L151xD ) || defined(STM32L152xD ) || defined(STM32L162xD ) 
#define FSMC_Bank1E_BWTR_BUSTURN BUSTURN              // 4 bits @ 16
#else
#define FSMC_Bank1E_BWTR_BUSTURN
#endif

#if defined(STM32F100xE ) 
#define FSMC_Bank1E_BWTR_CLKDIV CLKDIV               // 4 bits @ 20
#define FSMC_Bank1E_BWTR_DATLAT DATLAT               // 4 bits @ 24
#else
#define FSMC_Bank1E_BWTR_CLKDIV
#define FSMC_Bank1E_BWTR_DATLAT
#endif

//endregion

namespace sool
{
	namespace core
	{
		class FSMC_Bank1
		{
			//SOOL-FSMC_Bank1-ENUMS
			
			public :
			
			#ifdef FSMC_Bank1_BCR
			struct BCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MBKEN                :1;
					uint32_t MUXEN                :1;
					uint32_t MTYP                 :2;
					uint32_t MWID                 :2;
					uint32_t FACCEN               :1;
					uint32_t                      :1;
					uint32_t BURSTEN              :1;
					uint32_t WAITPOL              :1;
					uint32_t FSMC_Bank1_BCR_WRAPMOD :1;
					uint32_t WAITCFG              :1;
					uint32_t WREN                 :1;
					uint32_t WAITEN               :1;
					uint32_t EXTMOD               :1;
					uint32_t ASYNCWAIT            :1;
					uint32_t FSMC_Bank1_BCR_CPSIZE :3;
					uint32_t CBURSTRW             :1;
					uint32_t                      :12;
			
				//SOOL-FSMC_Bank1_BCR-DECLARATION
			};
			#endif
			
			#ifdef FSMC_Bank1_BCR1
			struct BCR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MBKEN                :1;
					uint32_t MUXEN                :1;
					uint32_t MTYP                 :2;
					uint32_t MWID                 :2;
					uint32_t FACCEN               :1;
					uint32_t                      :1;
					uint32_t BURSTEN              :1;
					uint32_t WAITPOL              :1;
					uint32_t FSMC_Bank1_BCR1_WRAPMOD :1;
					uint32_t WAITCFG              :1;
					uint32_t WREN                 :1;
					uint32_t WAITEN               :1;
					uint32_t EXTMOD               :1;
					uint32_t ASYNCWAIT            :1;
					uint32_t FSMC_Bank1_BCR1_CPSIZE :3;
					uint32_t CBURSTRW             :1;
					uint32_t FSMC_Bank1_BCR1_CCLKEN :1;
					uint32_t FSMC_Bank1_BCR1_WFDIS :1;
					uint32_t                      :10;
			
				//SOOL-FSMC_Bank1_BCR1-DECLARATION
			};
			#endif
			
			#ifdef FSMC_Bank1_BTCR
			struct BTCR_TypeDef : public Reg64_t
			{
				using Reg64_t::operator=;
				
					uint32_t ADDSET               :4;
					uint32_t ADDHLD               :4;
					uint32_t DATAST               :8;
					uint32_t BUSTURN              :4;
					uint32_t CLKDIV               :4;
					uint32_t DATLAT               :4;
					uint32_t ACCMOD               :2;
					uint32_t                      :2;
					uint32_t MBKEN                :1;
					uint32_t MUXEN                :1;
					uint32_t MTYP                 :2;
					uint32_t MWID                 :2;
					uint32_t FACCEN               :1;
					uint32_t                      :1;
					uint32_t BURSTEN              :1;
					uint32_t WAITPOL              :1;
					uint32_t FSMC_Bank1_BTCR_WRAPMOD :1;
					uint32_t WAITCFG              :1;
					uint32_t WREN                 :1;
					uint32_t WAITEN               :1;
					uint32_t EXTMOD               :1;
					uint32_t ASYNCWAIT            :1;
					uint32_t FSMC_Bank1_BTCR_CPSIZE :3;
					uint32_t CBURSTRW             :1;
					uint32_t                      :12;
			
				//SOOL-FSMC_Bank1_BTCR-DECLARATION
			};
			#endif
			
			#ifdef FSMC_Bank1_BTR
			struct BTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ADDSET               :4;
					uint32_t ADDHLD               :4;
					uint32_t DATAST               :8;
					uint32_t BUSTURN              :4;
					uint32_t CLKDIV               :4;
					uint32_t DATLAT               :4;
					uint32_t ACCMOD               :2;
					uint32_t                      :2;
			
				//SOOL-FSMC_Bank1_BTR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					BTCR_TypeDef BTCR[4]; // @0x000
				};
				struct
				{
					BigArrayReg_t<BCR_TypeDef, 0, 8, 4> BCR; // @0x000
					__SOOL_PERIPH_PADDING_16;
				};
				struct
				{
					BigArrayReg_t<BTR_TypeDef, 4, 8, 4> BTR; // @0x000
					__SOOL_PERIPH_PADDING_16;
				};
				struct
				{
					BCR1_TypeDef BCR1;   // @0x000
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
					__SOOL_PERIPH_PADDING_4;
				};
			};
			private:
			FSMC_Bank1() = delete;
			//SOOL-FSMC_Bank1-DECLARATION
		};
		
		
		class FSMC_Bank1E
		{
			//SOOL-FSMC_Bank1E-ENUMS
			
			public :
			
			#ifdef FSMC_Bank1E_BWTR
			struct BWTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ADDSET               :4;
					uint32_t ADDHLD               :4;
					uint32_t DATAST               :8;
					uint32_t FSMC_Bank1E_BWTR_BUSTURN :4;
					uint32_t FSMC_Bank1E_BWTR_CLKDIV :4;
					uint32_t FSMC_Bank1E_BWTR_DATLAT :4;
					uint32_t ACCMOD               :2;
					uint32_t                      :2;
			
				//SOOL-FSMC_Bank1E_BWTR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					BWTR_TypeDef BWTR[4]; // @0x000
				};
			};
			private:
			FSMC_Bank1E() = delete;
			//SOOL-FSMC_Bank1E-DECLARATION
		};
		
		
		class FSMC_Bank2_3
		{
			//SOOL-FSMC_Bank2_3-ENUMS
			
			public :
			
			union
			{
				
				struct
				{
					PCR_TypeDef PCR2;    // @0x000
					SR_TypeDef SR2;      // @0x004
					PMEM_TypeDef PMEM2;  // @0x008
					PATT_TypeDef PATT2;  // @0x00c
					__SOOL_PERIPH_PADDING_4;
					ECCR_TypeDef ECCR2;  // @0x014
					__SOOL_PERIPH_PADDING_8;
					PCR_TypeDef PCR3;    // @0x020
					SR_TypeDef SR3;      // @0x024
					PMEM_TypeDef PMEM3;  // @0x028
					PATT_TypeDef PATT3;  // @0x02c
					__SOOL_PERIPH_PADDING_4;
					ECCR_TypeDef ECCR3;  // @0x034
				};
			};
			private:
			FSMC_Bank2_3() = delete;
			//SOOL-FSMC_Bank2_3-DECLARATION
		};
		
		
		class FSMC_Bank4
		{
			//SOOL-FSMC_Bank4-ENUMS
			
			public :
			
			#ifdef FSMC_Bank4_PIO4
			struct PIO4_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IOSET4               :8;
					uint32_t IOWAIT4              :8;
					uint32_t IOHOLD4              :8;
					uint32_t IOHIZ4               :8;
			
				//SOOL-FSMC_Bank4_PIO4-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					PCR_TypeDef PCR4;    // @0x000
					SR_TypeDef SR4;      // @0x004
					PMEM_TypeDef PMEM4;  // @0x008
					PATT_TypeDef PATT4;  // @0x00c
					PIO4_TypeDef PIO4;   // @0x010
				};
			};
			private:
			FSMC_Bank4() = delete;
			//SOOL-FSMC_Bank4-DECLARATION
		};
		
		//region instances
#if defined(STM32F100xE ) || defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) ||\
    defined(STM32F103xG ) || defined(STM32F2     ) || defined(STM32F405xx ) || defined(STM32F407xx ) ||\
    defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F423xx ) || defined(STM32L151xD ) ||\
    defined(STM32L152xD ) || defined(STM32L162xD ) 
#define FSMC_Bank1_BASE_ADDR ((uint32_t)0xA0000000U)
#define FSMC_Bank1E_BASE_ADDR ((uint32_t)0xA0000104U)
#endif

#if defined(STM32F101xE ) || defined(STM32F101xG ) || defined(STM32F103xE ) || defined(STM32F103xG ) ||\
    defined(STM32F2     ) || defined(STM32F405xx ) || defined(STM32F407xx ) || defined(STM32F415xx ) ||\
    defined(STM32F417xx ) 
#define FSMC_Bank2_3_BASE_ADDR ((uint32_t)0xA0000060U)
#define FSMC_Bank4_BASE_ADDR ((uint32_t)0xA00000A0U)
#endif

#ifdef FSMC_Bank1_BASE_ADDR
volatile class FSMC_Bank1 * const FSMC_Bank1 = reinterpret_cast<class FSMC_Bank1* const>(FSMC_Bank1_BASE_ADDR);
#endif
#ifdef FSMC_Bank1E_BASE_ADDR
volatile class FSMC_Bank1E * const FSMC_Bank1E = reinterpret_cast<class FSMC_Bank1E* const>(FSMC_Bank1E_BASE_ADDR);
#endif
#ifdef FSMC_Bank2_3_BASE_ADDR
volatile class FSMC_Bank2_3 * const FSMC_Bank2_3 = reinterpret_cast<class FSMC_Bank2_3* const>(FSMC_Bank2_3_BASE_ADDR);
#endif
#ifdef FSMC_Bank4_BASE_ADDR
volatile class FSMC_Bank4 * const FSMC_Bank4 = reinterpret_cast<class FSMC_Bank4* const>(FSMC_Bank4_BASE_ADDR);
#endif
//endregion

//SOOL-FSMC-DEFINES
//SOOL-FSMC-DEFINITION
	};
};//region undef
#undef FSMC_Bank1_BCR_WRAPMOD
#undef FSMC_Bank1_BTCR_WRAPMOD
#undef FSMC_Bank1_BCR_CPSIZE
#undef FSMC_Bank1_BCR1_CPSIZE
#undef FSMC_Bank1_BTCR_CPSIZE
#undef FSMC_Bank1_BCR1_WRAPMOD
#undef FSMC_Bank1_BCR1_CCLKEN
#undef FSMC_Bank1_BCR1_WFDIS
#undef FSMC_Bank1E_BWTR_BUSTURN
#undef FSMC_Bank1E_BWTR_CLKDIV
#undef FSMC_Bank1E_BWTR_DATLAT
//endregion
#endif
#endif
