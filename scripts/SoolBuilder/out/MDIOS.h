#ifndef __SOOL_MDIOS_H
#define __SOOL_MDIOS_H

#include "peripheral_include.h"
//SOOL-MDIOS-INCLUDES
#if defined(STM32H7     ) 
//region defines

#define MDIOS_CLRFR
#define MDIOS_CR
#define MDIOS_CRDFR
#define MDIOS_CWRFR
#define MDIOS_DINR0
#define MDIOS_DINR1
#define MDIOS_DINR10
#define MDIOS_DINR11
#define MDIOS_DINR12
#define MDIOS_DINR13
#define MDIOS_DINR14
#define MDIOS_DINR15
#define MDIOS_DINR16
#define MDIOS_DINR17
#define MDIOS_DINR18
#define MDIOS_DINR19
#define MDIOS_DINR2
#define MDIOS_DINR20
#define MDIOS_DINR21
#define MDIOS_DINR22
#define MDIOS_DINR23
#define MDIOS_DINR24
#define MDIOS_DINR25
#define MDIOS_DINR26
#define MDIOS_DINR27
#define MDIOS_DINR28
#define MDIOS_DINR29
#define MDIOS_DINR3
#define MDIOS_DINR30
#define MDIOS_DINR31
#define MDIOS_DINR4
#define MDIOS_DINR5
#define MDIOS_DINR6
#define MDIOS_DINR7
#define MDIOS_DINR8
#define MDIOS_DINR9
#define MDIOS_DOUTR0
#define MDIOS_DOUTR1
#define MDIOS_DOUTR10
#define MDIOS_DOUTR11
#define MDIOS_DOUTR12
#define MDIOS_DOUTR13
#define MDIOS_DOUTR14
#define MDIOS_DOUTR15
#define MDIOS_DOUTR16
#define MDIOS_DOUTR17
#define MDIOS_DOUTR18
#define MDIOS_DOUTR19
#define MDIOS_DOUTR2
#define MDIOS_DOUTR20
#define MDIOS_DOUTR21
#define MDIOS_DOUTR22
#define MDIOS_DOUTR23
#define MDIOS_DOUTR24
#define MDIOS_DOUTR25
#define MDIOS_DOUTR26
#define MDIOS_DOUTR27
#define MDIOS_DOUTR28
#define MDIOS_DOUTR29
#define MDIOS_DOUTR3
#define MDIOS_DOUTR30
#define MDIOS_DOUTR31
#define MDIOS_DOUTR4
#define MDIOS_DOUTR5
#define MDIOS_DOUTR6
#define MDIOS_DOUTR7
#define MDIOS_DOUTR8
#define MDIOS_DOUTR9
#define MDIOS_RDFR
#define MDIOS_SR
#define MDIOS_WRFR

#if defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) || defined(STM32H7     ) 
#define MDIOS_SR_0
#endif

//endregion

namespace sool
{
	namespace core
	{
		class MDIOS
		{
			//SOOL-MDIOS-ENUMS
			
			public :
			
			#ifdef MDIOS_CLRFR
			struct CLRFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CPERF                :1;
					uint32_t CSERF                :1;
					uint32_t CTERF                :1;
					uint32_t                      :29;
			
				//SOOL-MDIOS_CLRFR-DECLARATION
			};
			#endif
			
			#ifdef MDIOS_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t EN                   :1;
					uint32_t WRIE                 :1;
					uint32_t RDIE                 :1;
					uint32_t EIE                  :1;
					uint32_t                      :3;
					uint32_t DPC                  :1;
					uint32_t PORT_ADDRESS         :5;
					uint32_t                      :19;
			
				//SOOL-MDIOS_CR-DECLARATION
			};
			#endif
			
			#ifdef MDIOS_CRDFR
			struct CRDFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CRDF                 :32;
			
				//SOOL-MDIOS_CRDFR-DECLARATION
			};
			#endif
			
			#ifdef MDIOS_CWRFR
			struct CWRFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CWRF                 :32;
			
				//SOOL-MDIOS_CWRFR-DECLARATION
			};
			#endif
			
			#ifdef MDIOS_RDFR
			struct RDFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t RDF                  :32;
			
				//SOOL-MDIOS_RDFR-DECLARATION
			};
			#endif
			
			#ifdef MDIOS_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef MDIOS_SR_0
					struct
					{
						uint32_t PERF                 :1;
						uint32_t SERF                 :1;
						uint32_t TERF                 :1;
						uint32_t                      :29;
					};
					#endif
					struct
					{
						uint32_t CPERF                :1;
						uint32_t CSERF                :1;
						uint32_t CTERF                :1;
						uint32_t                      :29;
					};
				};
				//SOOL-MDIOS_SR-DECLARATION
			};
			#endif
			
			#ifdef MDIOS_WRFR
			struct WRFR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t WRF                  :32;
			
				//SOOL-MDIOS_WRFR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					WRFR_TypeDef WRFR;   // @0x004
					CWRFR_TypeDef CWRFR; // @0x008
					RDFR_TypeDef RDFR;   // @0x00c
					CRDFR_TypeDef CRDFR; // @0x010
					SR_TypeDef SR;       // @0x014
					CLRFR_TypeDef CLRFR; // @0x018
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_4;
					uint32_t DINR0;      // @0x100
					uint32_t DINR1;      // @0x104
					uint32_t DINR2;      // @0x108
					uint32_t DINR3;      // @0x10c
					uint32_t DINR4;      // @0x110
					uint32_t DINR5;      // @0x114
					uint32_t DINR6;      // @0x118
					uint32_t DINR7;      // @0x11c
					uint32_t DINR8;      // @0x120
					uint32_t DINR9;      // @0x124
					uint32_t DINR10;     // @0x128
					uint32_t DINR11;     // @0x12c
					uint32_t DINR12;     // @0x130
					uint32_t DINR13;     // @0x134
					uint32_t DINR14;     // @0x138
					uint32_t DINR15;     // @0x13c
					uint32_t DINR16;     // @0x140
					uint32_t DINR17;     // @0x144
					uint32_t DINR18;     // @0x148
					uint32_t DINR19;     // @0x14c
					uint32_t DINR20;     // @0x150
					uint32_t DINR21;     // @0x154
					uint32_t DINR22;     // @0x158
					uint32_t DINR23;     // @0x15c
					uint32_t DINR24;     // @0x160
					uint32_t DINR25;     // @0x164
					uint32_t DINR26;     // @0x168
					uint32_t DINR27;     // @0x16c
					uint32_t DINR28;     // @0x170
					uint32_t DINR29;     // @0x174
					uint32_t DINR30;     // @0x178
					uint32_t DINR31;     // @0x17c
					uint32_t DOUTR0;     // @0x180
					uint32_t DOUTR1;     // @0x184
					uint32_t DOUTR2;     // @0x188
					uint32_t DOUTR3;     // @0x18c
					uint32_t DOUTR4;     // @0x190
					uint32_t DOUTR5;     // @0x194
					uint32_t DOUTR6;     // @0x198
					uint32_t DOUTR7;     // @0x19c
					uint32_t DOUTR8;     // @0x1a0
					uint32_t DOUTR9;     // @0x1a4
					uint32_t DOUTR10;    // @0x1a8
					uint32_t DOUTR11;    // @0x1ac
					uint32_t DOUTR12;    // @0x1b0
					uint32_t DOUTR13;    // @0x1b4
					uint32_t DOUTR14;    // @0x1b8
					uint32_t DOUTR15;    // @0x1bc
					uint32_t DOUTR16;    // @0x1c0
					uint32_t DOUTR17;    // @0x1c4
					uint32_t DOUTR18;    // @0x1c8
					uint32_t DOUTR19;    // @0x1cc
					uint32_t DOUTR20;    // @0x1d0
					uint32_t DOUTR21;    // @0x1d4
					uint32_t DOUTR22;    // @0x1d8
					uint32_t DOUTR23;    // @0x1dc
					uint32_t DOUTR24;    // @0x1e0
					uint32_t DOUTR25;    // @0x1e4
					uint32_t DOUTR26;    // @0x1e8
					uint32_t DOUTR27;    // @0x1ec
					uint32_t DOUTR28;    // @0x1f0
					uint32_t DOUTR29;    // @0x1f4
					uint32_t DOUTR30;    // @0x1f8
					uint32_t DOUTR31;    // @0x1fc
				};
			};
			private:
			MDIOS() = delete;
			//SOOL-MDIOS-DECLARATION
		};
		
		//region instances
#if defined(STM32F765xx ) || defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) ||\
    defined(STM32F779xx ) 
#define MDIOS_BASE_ADDR ((uint32_t)0x40017800U)
#endif

#define MDIOS_BASE_ADDR ((uint32_t)0x40009400U)
#ifdef MDIOS_BASE_ADDR
volatile class MDIOS * const MDIOS = reinterpret_cast<class MDIOS* const>(MDIOS_BASE_ADDR);
#endif
//endregion

//SOOL-MDIOS-DEFINES
//SOOL-MDIOS-DEFINITION
	};
};//region undef
//endregion
#endif
#endif
