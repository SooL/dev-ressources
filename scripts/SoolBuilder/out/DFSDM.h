#ifndef __SOOL_DFSDM_H
#define __SOOL_DFSDM_H

#include "peripheral_include.h"
//SOOL-DFSDM-INCLUDES
#if defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) ||\
    defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) ||\
    defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
//region defines

#define DFSDM_Channel_CHAWSCDR
#define DFSDM_Channel_CHCFGR1
#define DFSDM_Channel_CHCFGR2
#define DFSDM_Channel_CHDATINR
#define DFSDM_Channel_CHWDATR
#define DFSDM_Filter_FLTAWCFR
#define DFSDM_Filter_FLTAWHTR
#define DFSDM_Filter_FLTAWLTR
#define DFSDM_Filter_FLTAWSR
#define DFSDM_Filter_FLTCNVTIMR
#define DFSDM_Filter_FLTCR1
#define DFSDM_Filter_FLTCR2
#define DFSDM_Filter_FLTEXMAX
#define DFSDM_Filter_FLTEXMIN
#define DFSDM_Filter_FLTFCR
#define DFSDM_Filter_FLTICR
#define DFSDM_Filter_FLTISR
#define DFSDM_Filter_FLTJCHGR
#define DFSDM_Filter_FLTJDATAR
#define DFSDM_Filter_FLTRDATAR

#if defined(STM32L4P    ) 
#define DFSDM_Channel_CHDLYR
#define DFSDM_Channel_MAP0_CHDLYR CHDLYR_TypeDef CHDLYR
#else
#define DFSDM_Channel_MAP0_CHDLYR __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) 
#define DFSDM_Filter_FLTAWCFR_0
#define DFSDM_Filter_FLTAWSR_0
#define DFSDM_Filter_FLTCR2_0_EXCH EXCH                 // 4 bits @ 8
#define DFSDM_Filter_FLTCR2_0_AWDCH AWDCH                // 4 bits @ 16
#define DFSDM_Filter_FLTICR_0_CLRCKABF CLRCKABF             // 4 bits @ 16
#define DFSDM_Filter_FLTICR_0_CLRSCSDF CLRSCSDF             // 4 bits @ 24
#define DFSDM_Filter_FLTISR_0_CKABF CKABF                // 4 bits @ 16
#define DFSDM_Filter_FLTISR_0_SCDF SCDF                 // 4 bits @ 24
#define DFSDM_Filter_FLTJCHGR_0
#else
#define DFSDM_Filter_FLTCR2_0_EXCH
#define DFSDM_Filter_FLTCR2_0_AWDCH
#define DFSDM_Filter_FLTICR_0_CLRCKABF
#define DFSDM_Filter_FLTICR_0_CLRSCSDF
#define DFSDM_Filter_FLTISR_0_CKABF
#define DFSDM_Filter_FLTISR_0_SCDF
#endif

#if defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) ||\
    defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) ||\
    defined(STM32L451xx ) || defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) ||\
    defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DFSDM_Filter_FLTAWCFR_1
#define DFSDM_Filter_FLTAWSR_1
#define DFSDM_Filter_FLTCR2_1
#define DFSDM_Filter_FLTICR_1
#define DFSDM_Filter_FLTISR_1
#define DFSDM_Filter_FLTJCHGR_1
#endif

#if defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32L451xx ) || defined(STM32L452xx ) ||\
    defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) ||\
    defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) 
#define DFSDM_Filter_FLTCR1_0_JEXTSEL JEXTSEL              // 3 bits @ 8
#else
#define DFSDM_Filter_FLTCR1_0_JEXTSEL
#endif

#if defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) || defined(STM32H7     ) || defined(STM32L4P    ) 
#define DFSDM_Filter_FLTCR1_1
#endif

#if defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) ||\
    defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32L451xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) ||\
    defined(STM32L476xx ) || defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DFSDM_Filter_FLTICR_1_CLRSCSDF CLRSCSDF             // 8 bits @ 24
#else
#define DFSDM_Filter_FLTICR_1_CLRSCSDF
#endif

#if defined(STM32H7     ) 
#define DFSDM_Filter_FLTICR_2
#endif

//endregion

namespace sool
{
	namespace core
	{
		class DFSDM_Channel
		{
			//SOOL-DFSDM_Channel-ENUMS
			
			public :
			
			#ifdef DFSDM_Channel_CHAWSCDR
			struct CHAWSCDR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SCDT                 :8;
					uint32_t                      :4;
					uint32_t BKSCD                :4;
					uint32_t AWFOSR               :5;
					uint32_t                      :1;
					uint32_t AWFORD               :2;
					uint32_t                      :8;
			
				//SOOL-DFSDM_Channel_CHAWSCDR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Channel_CHCFGR1
			struct CHCFGR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t SITP                 :2;
					uint32_t SPICKSEL             :2;
					uint32_t                      :1;
					uint32_t SCDEN                :1;
					uint32_t CKABEN               :1;
					uint32_t CHEN                 :1;
					uint32_t CHINSEL              :1;
					uint32_t                      :3;
					uint32_t DATMPX               :2;
					uint32_t DATPACK              :2;
					uint32_t CKOUTDIV             :8;
					uint32_t                      :6;
					uint32_t CKOUTSRC             :1;
					uint32_t DFSDMEN              :1;
			
				//SOOL-DFSDM_Channel_CHCFGR1-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Channel_CHCFGR2
			struct CHCFGR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :3;
					uint32_t DTRBS                :5;
					uint32_t OFFSET               :24;
			
				//SOOL-DFSDM_Channel_CHCFGR2-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Channel_CHDATINR
			struct CHDATINR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INDAT0               :16;
					uint32_t INDAT1               :16;
			
				//SOOL-DFSDM_Channel_CHDATINR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Channel_CHDLYR
			struct CHDLYR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t PLSSKP               :6;
					uint32_t                      :26;
			
				//SOOL-DFSDM_Channel_CHDLYR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Channel_CHWDATR
			struct CHWDATR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t WDATA                :16;
					uint32_t                      :16;
			
				//SOOL-DFSDM_Channel_CHWDATR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CHCFGR1_TypeDef CHCFGR1; // @0x000
					CHCFGR2_TypeDef CHCFGR2; // @0x004
					CHAWSCDR_TypeDef CHAWSCDR; // @0x008
					CHWDATR_TypeDef CHWDATR; // @0x00c
					CHDATINR_TypeDef CHDATINR; // @0x010
					DFSDM_Channel_MAP0_CHDLYR; // @0x014
				};
			};
			private:
			DFSDM_Channel() = delete;
			//SOOL-DFSDM_Channel-DECLARATION
		};
		
		
		class DFSDM_Filter
		{
			//SOOL-DFSDM_Filter-ENUMS
			
			public :
			
			#ifdef DFSDM_Filter_FLTAWCFR
			struct FLTAWCFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DFSDM_Filter_FLTAWCFR_0
					struct
					{
						uint32_t CLRAWLTF             :4;
						uint32_t                      :4;
						uint32_t CLRAWHTF             :4;
						uint32_t                      :20;
					};
					#endif
					#ifdef DFSDM_Filter_FLTAWCFR_1
					struct
					{
						uint32_t CLRAWLTF             :8;
						uint32_t CLRAWHTF             :8;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-DFSDM_Filter_FLTAWCFR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTAWHTR
			struct FLTAWHTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BKAWH                :4;
					uint32_t                      :4;
					uint32_t AWHT                 :24;
			
				//SOOL-DFSDM_Filter_FLTAWHTR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTAWLTR
			struct FLTAWLTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BKAWL                :4;
					uint32_t                      :4;
					uint32_t AWLT                 :24;
			
				//SOOL-DFSDM_Filter_FLTAWLTR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTAWSR
			struct FLTAWSR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DFSDM_Filter_FLTAWSR_0
					struct
					{
						uint32_t AWLTF                :4;
						uint32_t                      :4;
						uint32_t AWHTF                :4;
						uint32_t                      :20;
					};
					#endif
					#ifdef DFSDM_Filter_FLTAWSR_1
					struct
					{
						uint32_t AWLTF                :8;
						uint32_t AWHTF                :8;
						uint32_t                      :16;
					};
					#endif
				};
				//SOOL-DFSDM_Filter_FLTAWSR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTCNVTIMR
			struct FLTCNVTIMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :4;
					uint32_t CNVCNT               :28;
			
				//SOOL-DFSDM_Filter_FLTCNVTIMR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTCR1
			struct FLTCR1_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t DFEN                 :1;
						uint32_t JSWSTART             :1;
						uint32_t                      :1;
						uint32_t JSYNC                :1;
						uint32_t JSCAN                :1;
						uint32_t JDMAEN               :1;
						uint32_t                      :2;
						uint32_t DFSDM_Filter_FLTCR1_0_JEXTSEL :3;
						uint32_t                      :2;
						uint32_t JEXTEN               :2;
						uint32_t                      :2;
						uint32_t RSWSTART             :1;
						uint32_t RCONT                :1;
						uint32_t RSYNC                :1;
						uint32_t                      :1;
						uint32_t RDMAEN               :1;
						uint32_t                      :2;
						uint32_t RCH                  :3;
						uint32_t                      :2;
						uint32_t FAST                 :1;
						uint32_t AWFSEL               :1;
						uint32_t                      :1;
					};
					#ifdef DFSDM_Filter_FLTCR1_1
					struct
					{
						uint32_t                      :8;
						uint32_t JEXTSEL              :5;
						uint32_t                      :19;
					};
					#endif
				};
				//SOOL-DFSDM_Filter_FLTCR1-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTCR2
			struct FLTCR2_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t JEOCIE               :1;
						uint32_t REOCIE               :1;
						uint32_t JOVRIE               :1;
						uint32_t ROVRIE               :1;
						uint32_t AWDIE                :1;
						uint32_t SCDIE                :1;
						uint32_t CKABIE               :1;
						uint32_t                      :1;
						uint32_t DFSDM_Filter_FLTCR2_0_EXCH :4;
						uint32_t                      :4;
						uint32_t DFSDM_Filter_FLTCR2_0_AWDCH :4;
						uint32_t                      :12;
					};
					#ifdef DFSDM_Filter_FLTCR2_1
					struct
					{
						uint32_t                      :8;
						uint32_t EXCH                 :8;
						uint32_t AWDCH                :8;
						uint32_t                      :8;
					};
					#endif
				};
				//SOOL-DFSDM_Filter_FLTCR2-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTEXMAX
			struct FLTEXMAX_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EXMAXCH              :3;
					uint32_t                      :5;
					uint32_t EXMAX                :24;
			
				//SOOL-DFSDM_Filter_FLTEXMAX-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTEXMIN
			struct FLTEXMIN_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EXMINCH              :3;
					uint32_t                      :5;
					uint32_t EXMIN                :24;
			
				//SOOL-DFSDM_Filter_FLTEXMIN-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTFCR
			struct FLTFCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t IOSR                 :8;
					uint32_t                      :8;
					uint32_t FOSR                 :10;
					uint32_t                      :3;
					uint32_t FORD                 :3;
			
				//SOOL-DFSDM_Filter_FLTFCR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTICR
			struct FLTICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t                      :2;
						uint32_t CLRJOVRF             :1;
						uint32_t CLRROVRF             :1;
						uint32_t                      :12;
						uint32_t DFSDM_Filter_FLTICR_0_CLRCKABF :4;
						uint32_t                      :4;
						uint32_t DFSDM_Filter_FLTICR_0_CLRSCSDF :4;
						uint32_t                      :4;
					};
					#ifdef DFSDM_Filter_FLTICR_1
					struct
					{
						uint32_t                      :16;
						uint32_t CLRCKABF             :8;
						uint32_t DFSDM_Filter_FLTICR_1_CLRSCSDF :8;
					};
					#endif
					#ifdef DFSDM_Filter_FLTICR_2
					struct
					{
						uint32_t                      :24;
						uint32_t CLRSCDF              :8;
					};
					#endif
				};
				//SOOL-DFSDM_Filter_FLTICR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTISR
			struct FLTISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t JEOCF                :1;
						uint32_t REOCF                :1;
						uint32_t JOVRF                :1;
						uint32_t ROVRF                :1;
						uint32_t AWDF                 :1;
						uint32_t                      :8;
						uint32_t JCIP                 :1;
						uint32_t RCIP                 :1;
						uint32_t                      :1;
						uint32_t DFSDM_Filter_FLTISR_0_CKABF :4;
						uint32_t                      :4;
						uint32_t DFSDM_Filter_FLTISR_0_SCDF :4;
						uint32_t                      :4;
					};
					#ifdef DFSDM_Filter_FLTISR_1
					struct
					{
						uint32_t                      :16;
						uint32_t CKABF                :8;
						uint32_t SCDF                 :8;
					};
					#endif
				};
				//SOOL-DFSDM_Filter_FLTISR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTJCHGR
			struct FLTJCHGR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef DFSDM_Filter_FLTJCHGR_0
					struct
					{
						uint32_t JCHG                 :4;
						uint32_t                      :28;
					};
					#endif
					#ifdef DFSDM_Filter_FLTJCHGR_1
					struct
					{
						uint32_t JCHG                 :8;
						uint32_t                      :24;
					};
					#endif
				};
				//SOOL-DFSDM_Filter_FLTJCHGR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTJDATAR
			struct FLTJDATAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t JDATACH              :3;
					uint32_t                      :5;
					uint32_t JDATA                :24;
			
				//SOOL-DFSDM_Filter_FLTJDATAR-DECLARATION
			};
			#endif
			
			#ifdef DFSDM_Filter_FLTRDATAR
			struct FLTRDATAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RDATACH              :3;
					uint32_t                      :1;
					uint32_t RPEND                :1;
					uint32_t                      :3;
					uint32_t RDATA                :24;
			
				//SOOL-DFSDM_Filter_FLTRDATAR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					FLTCR1_TypeDef FLTCR1; // @0x000
					FLTCR2_TypeDef FLTCR2; // @0x004
					FLTISR_TypeDef FLTISR; // @0x008
					FLTICR_TypeDef FLTICR; // @0x00c
					FLTJCHGR_TypeDef FLTJCHGR; // @0x010
					FLTFCR_TypeDef FLTFCR; // @0x014
					FLTJDATAR_TypeDef FLTJDATAR; // @0x018
					FLTRDATAR_TypeDef FLTRDATAR; // @0x01c
					FLTAWHTR_TypeDef FLTAWHTR; // @0x020
					FLTAWLTR_TypeDef FLTAWLTR; // @0x024
					FLTAWSR_TypeDef FLTAWSR; // @0x028
					FLTAWCFR_TypeDef FLTAWCFR; // @0x02c
					FLTEXMAX_TypeDef FLTEXMAX; // @0x030
					FLTEXMIN_TypeDef FLTEXMIN; // @0x034
					FLTCNVTIMR_TypeDef FLTCNVTIMR; // @0x038
				};
			};
			private:
			DFSDM_Filter() = delete;
			//SOOL-DFSDM_Filter-DECLARATION
		};
		
		//region instances
#if defined(STM32F412Cx ) || defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) ||\
    defined(STM32F413xx ) || defined(STM32F423xx ) || defined(STM32L451xx ) || defined(STM32L452xx ) ||\
    defined(STM32L462xx ) || defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) ||\
    defined(STM32L485xx ) || defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4P    ) 
#define DFSDM1_Channel0_BASE_ADDR ((uint32_t)0x40016000U)
#define DFSDM1_Channel1_BASE_ADDR ((uint32_t)0x40016020U)
#define DFSDM1_Channel2_BASE_ADDR ((uint32_t)0x40016040U)
#define DFSDM1_Channel3_BASE_ADDR ((uint32_t)0x40016060U)
#define DFSDM1_Filter0_BASE_ADDR ((uint32_t)0x40016100U)
#define DFSDM1_Filter1_BASE_ADDR ((uint32_t)0x40016180U)
#endif

#if defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) 
#define DFSDM1_Channel0_BASE_ADDR ((uint32_t)0x40017400U)
#define DFSDM1_Channel1_BASE_ADDR ((uint32_t)0x40017420U)
#define DFSDM1_Channel2_BASE_ADDR ((uint32_t)0x40017440U)
#define DFSDM1_Channel3_BASE_ADDR ((uint32_t)0x40017460U)
#define DFSDM1_Channel4_BASE_ADDR ((uint32_t)0x40017480U)
#define DFSDM1_Channel5_BASE_ADDR ((uint32_t)0x400174A0U)
#define DFSDM1_Channel6_BASE_ADDR ((uint32_t)0x400174C0U)
#define DFSDM1_Channel7_BASE_ADDR ((uint32_t)0x400174E0U)
#define DFSDM1_Filter0_BASE_ADDR ((uint32_t)0x40017500U)
#define DFSDM1_Filter1_BASE_ADDR ((uint32_t)0x40017580U)
#define DFSDM1_Filter2_BASE_ADDR ((uint32_t)0x40017600U)
#define DFSDM1_Filter3_BASE_ADDR ((uint32_t)0x40017680U)
#endif

#if defined(STM32H7     ) 
#define DFSDM1_Channel0_BASE_ADDR ((uint32_t)0x40017000U)
#define DFSDM1_Channel1_BASE_ADDR ((uint32_t)0x40017020U)
#define DFSDM1_Channel2_BASE_ADDR ((uint32_t)0x40017040U)
#define DFSDM1_Channel3_BASE_ADDR ((uint32_t)0x40017060U)
#define DFSDM1_Channel4_BASE_ADDR ((uint32_t)0x40017080U)
#define DFSDM1_Channel5_BASE_ADDR ((uint32_t)0x400170A0U)
#define DFSDM1_Channel6_BASE_ADDR ((uint32_t)0x400170C0U)
#define DFSDM1_Channel7_BASE_ADDR ((uint32_t)0x400170E0U)
#define DFSDM1_Filter0_BASE_ADDR ((uint32_t)0x40017100U)
#define DFSDM1_Filter1_BASE_ADDR ((uint32_t)0x40017180U)
#define DFSDM1_Filter2_BASE_ADDR ((uint32_t)0x40017200U)
#define DFSDM1_Filter3_BASE_ADDR ((uint32_t)0x40017280U)
#endif

#if defined(STM32F413xx ) || defined(STM32F423xx ) 
#define DFSDM2_Channel0_BASE_ADDR ((uint32_t)0x40016400U)
#define DFSDM2_Channel1_BASE_ADDR ((uint32_t)0x40016420U)
#define DFSDM2_Channel2_BASE_ADDR ((uint32_t)0x40016440U)
#define DFSDM2_Channel3_BASE_ADDR ((uint32_t)0x40016460U)
#define DFSDM2_Channel4_BASE_ADDR ((uint32_t)0x40016480U)
#define DFSDM2_Channel5_BASE_ADDR ((uint32_t)0x400164A0U)
#define DFSDM2_Channel6_BASE_ADDR ((uint32_t)0x400164C0U)
#define DFSDM2_Channel7_BASE_ADDR ((uint32_t)0x400164E0U)
#define DFSDM2_Filter0_BASE_ADDR ((uint32_t)0x40016500U)
#define DFSDM2_Filter1_BASE_ADDR ((uint32_t)0x40016580U)
#define DFSDM2_Filter2_BASE_ADDR ((uint32_t)0x40016600U)
#define DFSDM2_Filter3_BASE_ADDR ((uint32_t)0x40016680U)
#endif

#if defined(STM32L471xx ) || defined(STM32L475xx ) || defined(STM32L476xx ) || defined(STM32L485xx ) ||\
    defined(STM32L486xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DFSDM1_Channel4_BASE_ADDR ((uint32_t)0x40016080U)
#define DFSDM1_Channel5_BASE_ADDR ((uint32_t)0x400160A0U)
#define DFSDM1_Channel6_BASE_ADDR ((uint32_t)0x400160C0U)
#define DFSDM1_Channel7_BASE_ADDR ((uint32_t)0x400160E0U)
#define DFSDM1_Filter2_BASE_ADDR ((uint32_t)0x40016200U)
#define DFSDM1_Filter3_BASE_ADDR ((uint32_t)0x40016280U)
#endif

#ifdef DFSDM1_Channel0_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM1_Channel0 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM1_Channel0_BASE_ADDR);
#endif
#ifdef DFSDM1_Channel1_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM1_Channel1 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM1_Channel1_BASE_ADDR);
#endif
#ifdef DFSDM1_Channel2_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM1_Channel2 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM1_Channel2_BASE_ADDR);
#endif
#ifdef DFSDM1_Channel3_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM1_Channel3 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM1_Channel3_BASE_ADDR);
#endif
#ifdef DFSDM1_Filter0_BASE_ADDR
volatile class DFSDM_Filter * const DFSDM1_Filter0 = reinterpret_cast<class DFSDM_Filter* const>(DFSDM1_Filter0_BASE_ADDR);
#endif
#ifdef DFSDM1_Filter1_BASE_ADDR
volatile class DFSDM_Filter * const DFSDM1_Filter1 = reinterpret_cast<class DFSDM_Filter* const>(DFSDM1_Filter1_BASE_ADDR);
#endif
#ifdef DFSDM1_Channel4_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM1_Channel4 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM1_Channel4_BASE_ADDR);
#endif
#ifdef DFSDM1_Channel5_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM1_Channel5 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM1_Channel5_BASE_ADDR);
#endif
#ifdef DFSDM1_Channel6_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM1_Channel6 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM1_Channel6_BASE_ADDR);
#endif
#ifdef DFSDM1_Channel7_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM1_Channel7 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM1_Channel7_BASE_ADDR);
#endif
#ifdef DFSDM1_Filter2_BASE_ADDR
volatile class DFSDM_Filter * const DFSDM1_Filter2 = reinterpret_cast<class DFSDM_Filter* const>(DFSDM1_Filter2_BASE_ADDR);
#endif
#ifdef DFSDM1_Filter3_BASE_ADDR
volatile class DFSDM_Filter * const DFSDM1_Filter3 = reinterpret_cast<class DFSDM_Filter* const>(DFSDM1_Filter3_BASE_ADDR);
#endif
#ifdef DFSDM2_Channel0_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM2_Channel0 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM2_Channel0_BASE_ADDR);
#endif
#ifdef DFSDM2_Channel1_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM2_Channel1 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM2_Channel1_BASE_ADDR);
#endif
#ifdef DFSDM2_Channel2_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM2_Channel2 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM2_Channel2_BASE_ADDR);
#endif
#ifdef DFSDM2_Channel3_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM2_Channel3 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM2_Channel3_BASE_ADDR);
#endif
#ifdef DFSDM2_Channel4_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM2_Channel4 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM2_Channel4_BASE_ADDR);
#endif
#ifdef DFSDM2_Channel5_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM2_Channel5 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM2_Channel5_BASE_ADDR);
#endif
#ifdef DFSDM2_Channel6_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM2_Channel6 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM2_Channel6_BASE_ADDR);
#endif
#ifdef DFSDM2_Channel7_BASE_ADDR
volatile class DFSDM_Channel * const DFSDM2_Channel7 = reinterpret_cast<class DFSDM_Channel* const>(DFSDM2_Channel7_BASE_ADDR);
#endif
#ifdef DFSDM2_Filter0_BASE_ADDR
volatile class DFSDM_Filter * const DFSDM2_Filter0 = reinterpret_cast<class DFSDM_Filter* const>(DFSDM2_Filter0_BASE_ADDR);
#endif
#ifdef DFSDM2_Filter1_BASE_ADDR
volatile class DFSDM_Filter * const DFSDM2_Filter1 = reinterpret_cast<class DFSDM_Filter* const>(DFSDM2_Filter1_BASE_ADDR);
#endif
#ifdef DFSDM2_Filter2_BASE_ADDR
volatile class DFSDM_Filter * const DFSDM2_Filter2 = reinterpret_cast<class DFSDM_Filter* const>(DFSDM2_Filter2_BASE_ADDR);
#endif
#ifdef DFSDM2_Filter3_BASE_ADDR
volatile class DFSDM_Filter * const DFSDM2_Filter3 = reinterpret_cast<class DFSDM_Filter* const>(DFSDM2_Filter3_BASE_ADDR);
#endif
//endregion

//SOOL-DFSDM-DEFINES
//SOOL-DFSDM-DEFINITION
	};
};//region undef
#undef DFSDM_Channel_MAP0_CHDLYR
#undef DFSDM_Filter_FLTCR2_0_EXCH
#undef DFSDM_Filter_FLTCR2_0_AWDCH
#undef DFSDM_Filter_FLTICR_0_CLRCKABF
#undef DFSDM_Filter_FLTICR_0_CLRSCSDF
#undef DFSDM_Filter_FLTISR_0_CKABF
#undef DFSDM_Filter_FLTISR_0_SCDF
#undef DFSDM_Filter_FLTCR1_0_JEXTSEL
#undef DFSDM_Filter_FLTICR_1_CLRSCSDF
//endregion
#endif
#endif
