#ifndef __SOOL_OB_H
#define __SOOL_OB_H

#include "peripheral_include.h"
//SOOL-OB-INCLUDES
#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F3     ) || defined(STM32L0     ) ||\
    defined(STM32L1     ) 
//region defines

#if defined(STM32F0     ) 
#define OB_DATA0
#define OB_DATA1
#define OB_MAP0_DATA0        uint16_t DATA0
#define OB_MAP0_DATA1        uint16_t DATA1
#else
#define OB_MAP0_DATA0 __SOOL_PERIPH_PADDING_2
#define OB_MAP0_DATA1 __SOOL_PERIPH_PADDING_2
#endif

#if defined(STM32F1     ) 
#define OB_Data0
#define OB_Data1
#define OB_MAP2_Data0        Data0_TypeDef Data0
#define OB_MAP1_Data1        Data1_TypeDef Data1
#else
#define OB_MAP2_Data0 __SOOL_PERIPH_PADDING_2
#define OB_MAP1_Data1 __SOOL_PERIPH_PADDING_2
#endif

#define OB_RDP
#define OB_USER

#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F3     ) 
#define OB_WRP0
#define OB_MAP1_USER         USER_TypeDef USER
#define OB_MAP0_WRP0         WRP0_TypeDef WRP0
#else
#define OB_MAP1_USER __SOOL_PERIPH_PADDING_4
#define OB_MAP0_WRP0 __SOOL_PERIPH_PADDING_2
#endif

#if defined(STM32L0     ) || defined(STM32L1     ) 
#define OB_WRP01
#define OB_MAP3_USER         USER_TypeDef USER
#define OB_MAP1_WRP01        uint32_t WRP01
#else
#define OB_MAP3_USER __SOOL_PERIPH_PADDING_4
#define OB_MAP1_WRP01 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F030x8 ) || defined(STM32F030xC ) || defined(STM32F051x8 ) || defined(STM32F058xx ) ||\
    defined(STM32F070xB ) || defined(STM32F071xB ) || defined(STM32F072xB ) || defined(STM32F078xx ) ||\
    defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F1     ) || defined(STM32F3     ) 
#define OB_WRP1
#define OB_MAP0_WRP1         WRP1_TypeDef WRP1
#else
#define OB_MAP0_WRP1 __SOOL_PERIPH_PADDING_2
#endif

#if defined(STM32L151xD ) || defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xD ) ||\
    defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xD ) || defined(STM32L162xDx) ||\
    defined(STM32L162xE ) 
#define OB_WRP1011
#define OB_WRP89
#define OB_MAP0_WRP89        uint32_t WRP89
#define OB_MAP0_WRP1011      uint32_t WRP1011
#else
#define OB_MAP0_WRP89 __SOOL_PERIPH_PADDING_4
#define OB_MAP0_WRP1011 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xDx) || defined(STM32L152xE ) ||\
    defined(STM32L162xDx) || defined(STM32L162xE ) 
#define OB_WRP1213
#define OB_WRP1415
#define OB_MAP0_WRP1213      uint32_t WRP1213
#define OB_MAP0_WRP1415      uint32_t WRP1415
#else
#define OB_MAP0_WRP1213 __SOOL_PERIPH_PADDING_4
#define OB_MAP0_WRP1415 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32F030xC ) || defined(STM32F070xB ) || defined(STM32F071xB ) || defined(STM32F072xB ) ||\
    defined(STM32F078xx ) || defined(STM32F091xC ) || defined(STM32F098xx ) || defined(STM32F1     ) ||\
    defined(STM32F3     ) 
#define OB_WRP2
#define OB_WRP3
#define OB_MAP0_WRP2         WRP2_TypeDef WRP2
#define OB_MAP0_WRP3         WRP3_TypeDef WRP3
#else
#define OB_MAP0_WRP2 __SOOL_PERIPH_PADDING_2
#define OB_MAP0_WRP3 __SOOL_PERIPH_PADDING_2
#endif

#if defined(STM32L071xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L081xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L1     ) 
#define OB_WRP23
#define OB_MAP1_WRP23        uint32_t WRP23
#else
#define OB_MAP1_WRP23 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L071xx ) || defined(STM32L072xx ) || defined(STM32L073xx ) || defined(STM32L081xx ) ||\
    defined(STM32L082xx ) || defined(STM32L083xx ) || defined(STM32L100xC ) || defined(STM32L151xC ) ||\
    defined(STM32L151xCA) || defined(STM32L151xD ) || defined(STM32L151xDx) || defined(STM32L151xE ) ||\
    defined(STM32L152xC ) || defined(STM32L152xCA) || defined(STM32L152xD ) || defined(STM32L152xDx) ||\
    defined(STM32L152xE ) || defined(STM32L162xC ) || defined(STM32L162xCA) || defined(STM32L162xD ) ||\
    defined(STM32L162xDx) || defined(STM32L162xE ) 
#define OB_WRP45
#define OB_MAP0_WRP45        uint32_t WRP45
#else
#define OB_MAP0_WRP45 __SOOL_PERIPH_PADDING_4
#endif

#if defined(STM32L100xC ) || defined(STM32L151xC ) || defined(STM32L151xCA) || defined(STM32L151xD ) ||\
    defined(STM32L151xDx) || defined(STM32L151xE ) || defined(STM32L152xC ) || defined(STM32L152xCA) ||\
    defined(STM32L152xD ) || defined(STM32L152xDx) || defined(STM32L152xE ) || defined(STM32L162xC ) ||\
    defined(STM32L162xCA) || defined(STM32L162xD ) || defined(STM32L162xDx) || defined(STM32L162xE ) 
#define OB_WRP67
#define OB_MAP0_WRP67        uint32_t WRP67
#else
#define OB_MAP0_WRP67 __SOOL_PERIPH_PADDING_4
#endif

//endregion

namespace sool
{
	namespace core
	{
		class OB
		{
			//SOOL-OB-ENUMS
			
			public :
			
			#ifdef OB_Data0
			struct Data0_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t DATA0                :8;
					uint16_t nDATA0               :8;
			
				//SOOL-OB_Data0-DECLARATION
			};
			#endif
			
			#ifdef OB_Data1
			struct Data1_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t DATA1                :8;
					uint16_t nDATA1               :8;
			
				//SOOL-OB_Data1-DECLARATION
			};
			#endif
			
			#ifdef OB_RDP
			struct RDP_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint32_t RDP                  :8;
					uint32_t nRDP                 :8;
					uint32_t                      :16;
			
				//SOOL-OB_RDP-DECLARATION
			};
			#endif
			
			#ifdef OB_USER
			struct USER_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint32_t                      :16;
					uint32_t USER                 :8;
					uint32_t nUSER                :8;
			
				//SOOL-OB_USER-DECLARATION
			};
			#endif
			
			#ifdef OB_WRP0
			struct WRP0_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t WRP0                 :8;
					uint16_t nWRP0                :8;
			
				//SOOL-OB_WRP0-DECLARATION
			};
			#endif
			
			#ifdef OB_WRP1
			struct WRP1_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t WRP1                 :8;
					uint16_t nWRP1                :8;
			
				//SOOL-OB_WRP1-DECLARATION
			};
			#endif
			
			#ifdef OB_WRP2
			struct WRP2_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t WRP2                 :8;
					uint16_t nWRP2                :8;
			
				//SOOL-OB_WRP2-DECLARATION
			};
			#endif
			
			#ifdef OB_WRP3
			struct WRP3_TypeDef : public Reg16_t
			{
				using Reg16_t::operator=;
				
					uint16_t WRP3                 :8;
					uint16_t nWRP3                :8;
			
				//SOOL-OB_WRP3-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					RDP_TypeDef RDP;     // @0x000
					OB_MAP0_DATA0;       // @0x004
					OB_MAP0_DATA1;       // @0x006
					OB_MAP0_WRP0;        // @0x008
					OB_MAP0_WRP1;        // @0x00a
					OB_MAP0_WRP2;        // @0x00c
					OB_MAP0_WRP3;        // @0x00e
					OB_MAP0_WRP45;       // @0x010
					OB_MAP0_WRP67;       // @0x014
					OB_MAP0_WRP89;       // @0x018
					OB_MAP0_WRP1011;     // @0x01c
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					OB_MAP0_WRP1213;     // @0x080
					OB_MAP0_WRP1415;     // @0x084
				};
				struct
				{
					__SOOL_PERIPH_PADDING_2;
					OB_MAP1_USER;        // @0x002
					OB_MAP1_Data1;       // @0x006
					OB_MAP1_WRP01;       // @0x008
					OB_MAP1_WRP23;       // @0x00c
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_32;
					__SOOL_PERIPH_PADDING_16;
					__SOOL_PERIPH_PADDING_8;
				};
				struct
				{
					__SOOL_PERIPH_PADDING_4;
					OB_MAP2_Data0;       // @0x004
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_2;
				};
				struct
				{
					__SOOL_PERIPH_PADDING_4;
					OB_MAP3_USER;        // @0x004
					__SOOL_PERIPH_PADDING_128;
				};
			};
			private:
			OB() = delete;
			//SOOL-OB-DECLARATION
		};
		
		//region instances
#if defined(STM32F0     ) || defined(STM32F1     ) || defined(STM32F3     ) 
#define OB_BASE_ADDR ((uint32_t)0x1FFFF800U)
#endif

#if defined(STM32L0     ) || defined(STM32L1     ) 
#define OB_BASE_ADDR ((uint32_t)0x1FF80000U)
#endif

#ifdef OB_BASE_ADDR
volatile class OB * const OB = reinterpret_cast<class OB* const>(OB_BASE_ADDR);
#endif
//endregion

//SOOL-OB-DEFINES
//SOOL-OB-DEFINITION
	};
};//region undef
#undef OB_MAP0_DATA0
#undef OB_MAP0_DATA1
#undef OB_MAP2_Data0
#undef OB_MAP1_Data1
#undef OB_MAP1_USER
#undef OB_MAP0_WRP0
#undef OB_MAP3_USER
#undef OB_MAP1_WRP01
#undef OB_MAP0_WRP1
#undef OB_MAP0_WRP89
#undef OB_MAP0_WRP1011
#undef OB_MAP0_WRP1213
#undef OB_MAP0_WRP1415
#undef OB_MAP0_WRP2
#undef OB_MAP0_WRP3
#undef OB_MAP1_WRP23
#undef OB_MAP0_WRP45
#undef OB_MAP0_WRP67
//endregion
#endif
#endif
