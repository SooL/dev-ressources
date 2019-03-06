#ifndef __SOOL_FMC_H
#define __SOOL_FMC_H

#include "peripheral_include.h"
//SOOL-FMC-INCLUDES
#if defined(STM32F302xE ) || defined(STM32F303xE ) || defined(STM32F398xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32H7     ) ||\
    defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
//region defines

#define FMC_ECCR
#define FMC_PATT
#define FMC_PCR
#define FMC_PMEM
#define FMC_SR
#define FMC_Bank1_BCR
#define FMC_Bank1_BCR1
#define FMC_Bank1_BTCR
#define FMC_Bank1_BTR
#define FMC_Bank1E_BWTR
#define FMC_Bank4_PIO4
#define FMC_Bank5_6_SDCMR
#define FMC_Bank5_6_SDCR
#define FMC_Bank5_6_SDRTR
#define FMC_Bank5_6_SDSR
#define FMC_Bank5_6_SDTR

#if defined(STM32F302xE ) || defined(STM32F303xE ) || defined(STM32F398xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define FMC_PCR_PTYP         PTYP                 // 1 bits @ 3
#else
#define FMC_PCR_PTYP
#endif

#if defined(STM32F302xE ) || defined(STM32F303xE ) || defined(STM32F398xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F7     ) 
#define FMC_Bank1_BCR_WRAPMOD WRAPMOD              // 1 bits @ 10
#define FMC_Bank1_BCR1_WRAPMOD WRAPMOD              // 1 bits @ 10
#define FMC_Bank1_BTCR_WRAPMOD WRAPMOD              // 1 bits @ 42
#else
#define FMC_Bank1_BCR_WRAPMOD
#define FMC_Bank1_BCR1_WRAPMOD
#define FMC_Bank1_BTCR_WRAPMOD
#endif

#if defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define FMC_Bank1_BCR_CPSIZE CPSIZE               // 3 bits @ 16
#define FMC_Bank1_BTCR_CPSIZE CPSIZE               // 3 bits @ 48
#else
#define FMC_Bank1_BCR_CPSIZE
#define FMC_Bank1_BTCR_CPSIZE
#endif

#if defined(STM32L4P    ) 
#define FMC_Bank1_BCR_NBLSET NBLSET               // 2 bits @ 22
#define FMC_Bank1_BTCR_DATAHLD DATAHLD              // 2 bits @ 30
#define FMC_Bank1_BTCR_NBLSET NBLSET               // 2 bits @ 54
#define FMC_Bank1_BTR_DATAHLD DATAHLD              // 2 bits @ 30
#define FMC_Bank1E_BWTR_0_DATAHLD DATAHLD              // 2 bits @ 30
#else
#define FMC_Bank1_BCR_NBLSET
#define FMC_Bank1_BTCR_DATAHLD
#define FMC_Bank1_BTCR_NBLSET
#define FMC_Bank1_BTR_DATAHLD
#define FMC_Bank1E_BWTR_0_DATAHLD
#endif

#if defined(STM32F302xE ) || defined(STM32F303xE ) || defined(STM32F398xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) || defined(STM32H7     ) 
#define FMC_Bank1_BCR1_MBKEN MBKEN                // 1 bits @ 0
#define FMC_Bank1_BCR1_MUXEN MUXEN                // 1 bits @ 1
#define FMC_Bank1_BCR1_MTYP  MTYP                 // 2 bits @ 2
#define FMC_Bank1_BCR1_MWID  MWID                 // 2 bits @ 4
#define FMC_Bank1_BCR1_FACCEN FACCEN               // 1 bits @ 6
#define FMC_Bank1_BCR1_BURSTEN BURSTEN              // 1 bits @ 8
#define FMC_Bank1_BCR1_WAITPOL WAITPOL              // 1 bits @ 9
#define FMC_Bank1_BCR1_WAITCFG WAITCFG              // 1 bits @ 11
#define FMC_Bank1_BCR1_WREN  WREN                 // 1 bits @ 12
#define FMC_Bank1_BCR1_WAITEN WAITEN               // 1 bits @ 13
#define FMC_Bank1_BCR1_EXTMOD EXTMOD               // 1 bits @ 14
#define FMC_Bank1_BCR1_ASYNCWAIT ASYNCWAIT            // 1 bits @ 15
#define FMC_Bank1_BCR1_CBURSTRW CBURSTRW             // 1 bits @ 19
#else
#define FMC_Bank1_BCR1_MBKEN
#define FMC_Bank1_BCR1_MUXEN
#define FMC_Bank1_BCR1_MTYP
#define FMC_Bank1_BCR1_MWID
#define FMC_Bank1_BCR1_FACCEN
#define FMC_Bank1_BCR1_BURSTEN
#define FMC_Bank1_BCR1_WAITPOL
#define FMC_Bank1_BCR1_WAITCFG
#define FMC_Bank1_BCR1_WREN
#define FMC_Bank1_BCR1_WAITEN
#define FMC_Bank1_BCR1_EXTMOD
#define FMC_Bank1_BCR1_ASYNCWAIT
#define FMC_Bank1_BCR1_CBURSTRW
#endif

#if defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) 
#define FMC_Bank1_BCR1_CPSIZE CPSIZE               // 3 bits @ 16
#else
#define FMC_Bank1_BCR1_CPSIZE
#endif

#if defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) ||\
    defined(STM32H7     ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define FMC_Bank1_BCR1_WFDIS WFDIS                // 1 bits @ 21
#else
#define FMC_Bank1_BCR1_WFDIS
#endif

#if defined(STM32H7     ) 
#define FMC_Bank1_BCR1_BMAP  BMAP                 // 2 bits @ 24
#define FMC_Bank1_BCR1_FMCEN FMCEN                // 1 bits @ 31
#else
#define FMC_Bank1_BCR1_BMAP
#define FMC_Bank1_BCR1_FMCEN
#endif

#if defined(STM32F302xE ) || defined(STM32F303xE ) || defined(STM32F398xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define FMC_Bank1E_BWTR_0
#endif

#if defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define FMC_Bank1E_BWTR_0_BUSTURN BUSTURN              // 4 bits @ 16
#else
#define FMC_Bank1E_BWTR_0_BUSTURN
#endif

#if defined(STM32F302xE ) || defined(STM32F303xE ) || defined(STM32F398xx ) 
#define FMC_Bank1E_BWTR_1
#endif

#if defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) 
#define FMC_Bank5_6_SDSR_BUSY BUSY                 // 1 bits @ 5
#else
#define FMC_Bank5_6_SDSR_BUSY
#endif

//endregion

namespace sool
{
	namespace core
	{
		class FMC_Bank1
		{
			//SOOL-FMC_Bank1-ENUMS
			
			public :
			
			#ifdef FMC_Bank1_BCR
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
					uint32_t FMC_Bank1_BCR_WRAPMOD :1;
					uint32_t WAITCFG              :1;
					uint32_t WREN                 :1;
					uint32_t WAITEN               :1;
					uint32_t EXTMOD               :1;
					uint32_t ASYNCWAIT            :1;
					uint32_t FMC_Bank1_BCR_CPSIZE :3;
					uint32_t CBURSTRW             :1;
					uint32_t                      :2;
					uint32_t FMC_Bank1_BCR_NBLSET :2;
					uint32_t                      :8;
			
				//SOOL-FMC_Bank1_BCR-DECLARATION
			};
			#endif
			
			#ifdef FMC_Bank1_BCR1
			struct BCR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FMC_Bank1_BCR1_MBKEN :1;
					uint32_t FMC_Bank1_BCR1_MUXEN :1;
					uint32_t FMC_Bank1_BCR1_MTYP  :2;
					uint32_t FMC_Bank1_BCR1_MWID  :2;
					uint32_t FMC_Bank1_BCR1_FACCEN :1;
					uint32_t                      :1;
					uint32_t FMC_Bank1_BCR1_BURSTEN :1;
					uint32_t FMC_Bank1_BCR1_WAITPOL :1;
					uint32_t FMC_Bank1_BCR1_WRAPMOD :1;
					uint32_t FMC_Bank1_BCR1_WAITCFG :1;
					uint32_t FMC_Bank1_BCR1_WREN  :1;
					uint32_t FMC_Bank1_BCR1_WAITEN :1;
					uint32_t FMC_Bank1_BCR1_EXTMOD :1;
					uint32_t FMC_Bank1_BCR1_ASYNCWAIT :1;
					uint32_t FMC_Bank1_BCR1_CPSIZE :3;
					uint32_t FMC_Bank1_BCR1_CBURSTRW :1;
					uint32_t CCLKEN               :1;
					uint32_t FMC_Bank1_BCR1_WFDIS :1;
					uint32_t                      :2;
					uint32_t FMC_Bank1_BCR1_BMAP  :2;
					uint32_t                      :5;
					uint32_t FMC_Bank1_BCR1_FMCEN :1;
			
				//SOOL-FMC_Bank1_BCR1-DECLARATION
			};
			#endif
			
			#ifdef FMC_Bank1_BTCR
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
					uint32_t FMC_Bank1_BTCR_DATAHLD :2;
					uint32_t MBKEN                :1;
					uint32_t MUXEN                :1;
					uint32_t MTYP                 :2;
					uint32_t MWID                 :2;
					uint32_t FACCEN               :1;
					uint32_t                      :1;
					uint32_t BURSTEN              :1;
					uint32_t WAITPOL              :1;
					uint32_t FMC_Bank1_BTCR_WRAPMOD :1;
					uint32_t WAITCFG              :1;
					uint32_t WREN                 :1;
					uint32_t WAITEN               :1;
					uint32_t EXTMOD               :1;
					uint32_t ASYNCWAIT            :1;
					uint32_t FMC_Bank1_BTCR_CPSIZE :3;
					uint32_t CBURSTRW             :1;
					uint32_t                      :2;
					uint32_t FMC_Bank1_BTCR_NBLSET :2;
					uint32_t                      :8;
			
				//SOOL-FMC_Bank1_BTCR-DECLARATION
			};
			#endif
			
			#ifdef FMC_Bank1_BTR
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
					uint32_t FMC_Bank1_BTR_DATAHLD :2;
			
				//SOOL-FMC_Bank1_BTR-DECLARATION
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
			FMC_Bank1() = delete;
			//SOOL-FMC_Bank1-DECLARATION
		};
		
		
		class FMC_Bank1E
		{
			//SOOL-FMC_Bank1E-ENUMS
			
			public :
			
			#ifdef FMC_Bank1E_BWTR
			struct BWTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef FMC_Bank1E_BWTR_0
					struct
					{
						uint32_t ADDSET               :4;
						uint32_t ADDHLD               :4;
						uint32_t DATAST               :8;
						uint32_t FMC_Bank1E_BWTR_0_BUSTURN :4;
						uint32_t                      :8;
						uint32_t ACCMOD               :2;
						uint32_t FMC_Bank1E_BWTR_0_DATAHLD :2;
					};
					#endif
					#ifdef FMC_Bank1E_BWTR_1
					struct
					{
						uint32_t                      :4;
						uint32_t ADDHLDx              :4;
						uint32_t DATASTx              :8;
						uint32_t                      :12;
						uint32_t ACCMODx              :2;
						uint32_t                      :2;
					};
					#endif
				};
				//SOOL-FMC_Bank1E_BWTR-DECLARATION
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
			FMC_Bank1E() = delete;
			//SOOL-FMC_Bank1E-DECLARATION
		};
		
		
		class FMC_Bank2
		{
			//SOOL-FMC_Bank2-ENUMS
			
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
				};
			};
			private:
			FMC_Bank2() = delete;
			//SOOL-FMC_Bank2-DECLARATION
		};
		
		
		class FMC_Bank2_3
		{
			//SOOL-FMC_Bank2_3-ENUMS
			
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
			FMC_Bank2_3() = delete;
			//SOOL-FMC_Bank2_3-DECLARATION
		};
		
		
		class FMC_Bank3
		{
			//SOOL-FMC_Bank3-ENUMS
			
			public :
			
			union
			{
				
				struct
				{
					PCR_TypeDef PCR;     // @0x000
					SR_TypeDef SR;       // @0x004
					PMEM_TypeDef PMEM;   // @0x008
					PATT_TypeDef PATT;   // @0x00c
					__SOOL_PERIPH_PADDING_4;
					ECCR_TypeDef ECCR;   // @0x014
				};
			};
			private:
			FMC_Bank3() = delete;
			//SOOL-FMC_Bank3-DECLARATION
		};
		
		
		class FMC_Bank4
		{
			//SOOL-FMC_Bank4-ENUMS
			
			public :
			
			#ifdef FMC_Bank4_PIO4
			struct PIO4_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IOSET4               :8;
					uint32_t IOWAIT4              :8;
					uint32_t IOHOLD4              :8;
					uint32_t IOHIZ4               :8;
			
				//SOOL-FMC_Bank4_PIO4-DECLARATION
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
			FMC_Bank4() = delete;
			//SOOL-FMC_Bank4-DECLARATION
		};
		
		
		class FMC_Bank5_6
		{
			//SOOL-FMC_Bank5_6-ENUMS
			
			public :
			
			#ifdef FMC_Bank5_6_SDCMR
			struct SDCMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MODE                 :3;
					uint32_t CTB2                 :1;
					uint32_t CTB1                 :1;
					uint32_t NRFS                 :4;
					uint32_t MRD                  :13;
					uint32_t                      :10;
			
				//SOOL-FMC_Bank5_6_SDCMR-DECLARATION
			};
			#endif
			
			#ifdef FMC_Bank5_6_SDCR
			struct SDCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t NC                   :2;
					uint32_t NR                   :2;
					uint32_t MWID                 :2;
					uint32_t NB                   :1;
					uint32_t CAS                  :2;
					uint32_t WP                   :1;
					uint32_t SDCLK                :2;
					uint32_t RBURST               :1;
					uint32_t RPIPE                :2;
					uint32_t                      :17;
			
				//SOOL-FMC_Bank5_6_SDCR-DECLARATION
			};
			#endif
			
			#ifdef FMC_Bank5_6_SDRTR
			struct SDRTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CRE                  :1;
					uint32_t COUNT                :13;
					uint32_t REIE                 :1;
					uint32_t                      :17;
			
				//SOOL-FMC_Bank5_6_SDRTR-DECLARATION
			};
			#endif
			
			#ifdef FMC_Bank5_6_SDSR
			struct SDSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RE                   :1;
					uint32_t MODES1               :2;
					uint32_t MODES2               :2;
					uint32_t FMC_Bank5_6_SDSR_BUSY :1;
					uint32_t                      :26;
			
				//SOOL-FMC_Bank5_6_SDSR-DECLARATION
			};
			#endif
			
			#ifdef FMC_Bank5_6_SDTR
			struct SDTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TMRD                 :4;
					uint32_t TXSR                 :4;
					uint32_t TRAS                 :4;
					uint32_t TRC                  :4;
					uint32_t TWR                  :4;
					uint32_t TRP                  :4;
					uint32_t TRCD                 :4;
					uint32_t                      :4;
			
				//SOOL-FMC_Bank5_6_SDTR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					SDCR_TypeDef SDCR[2]; // @0x000
					SDTR_TypeDef SDTR[2]; // @0x008
					SDCMR_TypeDef SDCMR; // @0x010
					SDRTR_TypeDef SDRTR; // @0x014
					SDSR_TypeDef SDSR;   // @0x018
				};
			};
			private:
			FMC_Bank5_6() = delete;
			//SOOL-FMC_Bank5_6-DECLARATION
		};
		
		//region instances
#if defined(STM32F302xE ) || defined(STM32F303xE ) || defined(STM32F398xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F446xx ) ||\
    defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) 
#define FMC_Bank1_BASE_ADDR ((uint32_t)0xA0000000U)
#define FMC_Bank1E_BASE_ADDR ((uint32_t)0xA0000104U)
#endif

#if defined(STM32H7     ) 
#define FMC_Bank1_BASE_ADDR ((uint32_t)0x52004000U)
#define FMC_Bank1E_BASE_ADDR ((uint32_t)0x52004104U)
#define FMC_Bank2_BASE_ADDR ((uint32_t)0x52004060U)
#define FMC_Bank3_BASE_ADDR ((uint32_t)0x52004080U)
#define FMC_Bank5_6_BASE_ADDR ((uint32_t)0x52004140U)
#endif

#if defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define FMC_Bank1_R_BASE_ADDR ((uint32_t)0xA0000000U)
#define FMC_Bank1E_R_BASE_ADDR ((uint32_t)0xA0000104U)
#define FMC_Bank3_R_BASE_ADDR ((uint32_t)0xA0000080U)
#endif

#if defined(STM32F302xE ) || defined(STM32F303xE ) || defined(STM32F398xx ) || defined(STM32F427xx ) ||\
    defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) 
#define FMC_Bank2_3_BASE_ADDR ((uint32_t)0xA0000060U)
#define FMC_Bank4_BASE_ADDR ((uint32_t)0xA00000A0U)
#endif

#if defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) 
#define FMC_Bank3_BASE_ADDR ((uint32_t)0xA0000080U)
#endif

#if defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F7     ) 
#define FMC_Bank5_6_BASE_ADDR ((uint32_t)0xA0000140U)
#endif

#ifdef FMC_Bank1_BASE_ADDR
volatile class FMC_Bank1 * const FMC_Bank1 = reinterpret_cast<class FMC_Bank1* const>(FMC_Bank1_BASE_ADDR);
#endif
#ifdef FMC_Bank1E_BASE_ADDR
volatile class FMC_Bank1E * const FMC_Bank1E = reinterpret_cast<class FMC_Bank1E* const>(FMC_Bank1E_BASE_ADDR);
#endif
#ifdef FMC_Bank2_BASE_ADDR
volatile class FMC_Bank2 * const FMC_Bank2 = reinterpret_cast<class FMC_Bank2* const>(FMC_Bank2_BASE_ADDR);
#endif
#ifdef FMC_Bank3_BASE_ADDR
volatile class FMC_Bank3 * const FMC_Bank3 = reinterpret_cast<class FMC_Bank3* const>(FMC_Bank3_BASE_ADDR);
#endif
#ifdef FMC_Bank5_6_BASE_ADDR
volatile class FMC_Bank5_6 * const FMC_Bank5_6 = reinterpret_cast<class FMC_Bank5_6* const>(FMC_Bank5_6_BASE_ADDR);
#endif
#ifdef FMC_Bank1_R_BASE_ADDR
volatile class FMC_Bank1 * const FMC_Bank1_R = reinterpret_cast<class FMC_Bank1* const>(FMC_Bank1_R_BASE_ADDR);
#endif
#ifdef FMC_Bank1E_R_BASE_ADDR
volatile class FMC_Bank1E * const FMC_Bank1E_R = reinterpret_cast<class FMC_Bank1E* const>(FMC_Bank1E_R_BASE_ADDR);
#endif
#ifdef FMC_Bank3_R_BASE_ADDR
volatile class FMC_Bank3 * const FMC_Bank3_R = reinterpret_cast<class FMC_Bank3* const>(FMC_Bank3_R_BASE_ADDR);
#endif
#ifdef FMC_Bank2_3_BASE_ADDR
volatile class FMC_Bank2_3 * const FMC_Bank2_3 = reinterpret_cast<class FMC_Bank2_3* const>(FMC_Bank2_3_BASE_ADDR);
#endif
#ifdef FMC_Bank4_BASE_ADDR
volatile class FMC_Bank4 * const FMC_Bank4 = reinterpret_cast<class FMC_Bank4* const>(FMC_Bank4_BASE_ADDR);
#endif
//endregion

//SOOL-FMC-DEFINES
//SOOL-FMC-DEFINITION
	};
};//region undef
#undef FMC_PCR_PTYP
#undef FMC_Bank1_BCR_WRAPMOD
#undef FMC_Bank1_BCR1_WRAPMOD
#undef FMC_Bank1_BTCR_WRAPMOD
#undef FMC_Bank1_BCR_CPSIZE
#undef FMC_Bank1_BTCR_CPSIZE
#undef FMC_Bank1_BCR_NBLSET
#undef FMC_Bank1_BTCR_DATAHLD
#undef FMC_Bank1_BTCR_NBLSET
#undef FMC_Bank1_BTR_DATAHLD
#undef FMC_Bank1E_BWTR_0_DATAHLD
#undef FMC_Bank1_BCR1_MBKEN
#undef FMC_Bank1_BCR1_MUXEN
#undef FMC_Bank1_BCR1_MTYP
#undef FMC_Bank1_BCR1_MWID
#undef FMC_Bank1_BCR1_FACCEN
#undef FMC_Bank1_BCR1_BURSTEN
#undef FMC_Bank1_BCR1_WAITPOL
#undef FMC_Bank1_BCR1_WAITCFG
#undef FMC_Bank1_BCR1_WREN
#undef FMC_Bank1_BCR1_WAITEN
#undef FMC_Bank1_BCR1_EXTMOD
#undef FMC_Bank1_BCR1_ASYNCWAIT
#undef FMC_Bank1_BCR1_CBURSTRW
#undef FMC_Bank1_BCR1_CPSIZE
#undef FMC_Bank1_BCR1_WFDIS
#undef FMC_Bank1_BCR1_BMAP
#undef FMC_Bank1_BCR1_FMCEN
#undef FMC_Bank1E_BWTR_0_BUSTURN
#undef FMC_Bank5_6_SDSR_BUSY
//endregion
#endif
#endif
