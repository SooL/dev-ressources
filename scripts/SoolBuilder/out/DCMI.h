#ifndef __SOOL_DCMI_H
#define __SOOL_DCMI_H

#include "peripheral_include.h"
//SOOL-DCMI-INCLUDES
#if defined(STM32F207xx ) || defined(STM32F217xx ) || defined(STM32F407xx ) || defined(STM32F417xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) ||\
    defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) ||\
    defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
//region defines

#define DCMI_CR
#define DCMI_CWSIZER
#define DCMI_CWSTRTR
#define DCMI_DR
#define DCMI_ESCR
#define DCMI_ESUR
#define DCMI_ICR
#define DCMI_IER
#define DCMI_MISR
#define DCMI_RISR
#define DCMI_SR

#if defined(STM32F207xx ) || defined(STM32F217xx ) || defined(STM32F407xx ) || defined(STM32F417xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) ||\
    defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) ||\
    defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) 
#define DCMI_CR_0_FCRC0      FCRC0                // 1 bits @ 8
#define DCMI_CR_0_FCRC1      FCRC1                // 1 bits @ 9
#define DCMI_CR_0_EDM0       EDM0                 // 1 bits @ 10
#define DCMI_CR_0_EDM1       EDM1                 // 1 bits @ 11
#else
#define DCMI_CR_0_FCRC0
#define DCMI_CR_0_FCRC1
#define DCMI_CR_0_EDM0
#define DCMI_CR_0_EDM1
#endif

#if defined(STM32F207xx ) || defined(STM32F217xx ) || defined(STM32F407xx ) || defined(STM32F429xx ) ||\
    defined(STM32F745xx ) || defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F765xx ) ||\
    defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) ||\
    defined(STM32H7     ) 
#define DCMI_CR_0_CRE        CRE                  // 1 bits @ 12
#else
#define DCMI_CR_0_CRE
#endif

#if defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) 
#define DCMI_CR_0_OUTEN      OUTEN                // 1 bits @ 13
#define DCMI_CR_0_BSM0       BSM0                 // 1 bits @ 16
#define DCMI_CR_0_BSM1       BSM1                 // 1 bits @ 17
#else
#define DCMI_CR_0_OUTEN
#define DCMI_CR_0_BSM0
#define DCMI_CR_0_BSM1
#endif

#if defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) ||\
    defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) ||\
    defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H7     ) ||\
    defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DCMI_CR_0_OEBS       OEBS                 // 1 bits @ 18
#define DCMI_CR_0_LSM        LSM                  // 1 bits @ 19
#define DCMI_CR_0_OELS       OELS                 // 1 bits @ 20
#else
#define DCMI_CR_0_OEBS
#define DCMI_CR_0_LSM
#define DCMI_CR_0_OELS
#endif

#if defined(STM32F745xx ) || defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F765xx ) ||\
    defined(STM32F767xx ) || defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) ||\
    defined(STM32H7     ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DCMI_CR_1
#endif

#if defined(STM32L496xx ) || defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DCMI_CR_1_FCRC       FCRC                 // 2 bits @ 8
#define DCMI_CR_1_EDM        EDM                  // 2 bits @ 10
#define DCMI_IER_1
#else
#define DCMI_CR_1_FCRC
#define DCMI_CR_1_EDM
#endif

//endregion

namespace sool
{
	namespace core
	{
		class DCMI
		{
			//SOOL-DCMI-ENUMS
			
			public :
			
			#ifdef DCMI_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t CAPTURE              :1;
						uint32_t CM                   :1;
						uint32_t CROP                 :1;
						uint32_t JPEG                 :1;
						uint32_t ESS                  :1;
						uint32_t PCKPOL               :1;
						uint32_t HSPOL                :1;
						uint32_t VSPOL                :1;
						uint32_t DCMI_CR_0_FCRC0      :1;
						uint32_t DCMI_CR_0_FCRC1      :1;
						uint32_t DCMI_CR_0_EDM0       :1;
						uint32_t DCMI_CR_0_EDM1       :1;
						uint32_t DCMI_CR_0_CRE        :1;
						uint32_t DCMI_CR_0_OUTEN      :1;
						uint32_t ENABLE               :1;
						uint32_t                      :1;
						uint32_t DCMI_CR_0_BSM0       :1;
						uint32_t DCMI_CR_0_BSM1       :1;
						uint32_t DCMI_CR_0_OEBS       :1;
						uint32_t DCMI_CR_0_LSM        :1;
						uint32_t DCMI_CR_0_OELS       :1;
						uint32_t                      :11;
					};
					#ifdef DCMI_CR_1
					struct
					{
						uint32_t                      :8;
						uint32_t DCMI_CR_1_FCRC       :2;
						uint32_t DCMI_CR_1_EDM        :2;
						uint32_t                      :4;
						uint32_t BSM                  :2;
						uint32_t                      :14;
					};
					#endif
				};
				//SOOL-DCMI_CR-DECLARATION
			};
			#endif
			
			#ifdef DCMI_CWSIZER
			struct CWSIZER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CAPCNT               :14;
					uint32_t                      :2;
					uint32_t VLINE                :14;
					uint32_t                      :2;
			
				//SOOL-DCMI_CWSIZER-DECLARATION
			};
			#endif
			
			#ifdef DCMI_CWSTRTR
			struct CWSTRTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HOFFCNT              :14;
					uint32_t                      :2;
					uint32_t VST                  :13;
					uint32_t                      :3;
			
				//SOOL-DCMI_CWSTRTR-DECLARATION
			};
			#endif
			
			#ifdef DCMI_DR
			struct DR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t BYTE0                :8;
					uint32_t BYTE1                :8;
					uint32_t BYTE2                :8;
					uint32_t BYTE3                :8;
			
				//SOOL-DCMI_DR-DECLARATION
			};
			#endif
			
			#ifdef DCMI_ESCR
			struct ESCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FSC                  :8;
					uint32_t LSC                  :8;
					uint32_t LEC                  :8;
					uint32_t FEC                  :8;
			
				//SOOL-DCMI_ESCR-DECLARATION
			};
			#endif
			
			#ifdef DCMI_ESUR
			struct ESUR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FSU                  :8;
					uint32_t LSU                  :8;
					uint32_t LEU                  :8;
					uint32_t FEU                  :8;
			
				//SOOL-DCMI_ESUR-DECLARATION
			};
			#endif
			
			#ifdef DCMI_ICR
			struct ICR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FRAME_ISC            :1;
					uint32_t OVR_ISC              :1;
					uint32_t ERR_ISC              :1;
					uint32_t VSYNC_ISC            :1;
					uint32_t LINE_ISC             :1;
					uint32_t                      :27;
			
				//SOOL-DCMI_ICR-DECLARATION
			};
			#endif
			
			#ifdef DCMI_IER
			struct IER_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t FRAME_IE             :1;
						uint32_t OVR_IE               :1;
						uint32_t ERR_IE               :1;
						uint32_t VSYNC_IE             :1;
						uint32_t LINE_IE              :1;
						uint32_t                      :27;
					};
					#ifdef DCMI_IER_1
					struct
					{
						uint32_t INT_IE               :5;
						uint32_t                      :27;
					};
					#endif
				};
				//SOOL-DCMI_IER-DECLARATION
			};
			#endif
			
			#ifdef DCMI_MISR
			struct MISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FRAME_MIS            :1;
					uint32_t OVR_MIS              :1;
					uint32_t ERR_MIS              :1;
					uint32_t VSYNC_MIS            :1;
					uint32_t LINE_MIS             :1;
					uint32_t                      :27;
			
				//SOOL-DCMI_MISR-DECLARATION
			};
			#endif
			
			#ifdef DCMI_RISR
			struct RISR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t FRAME_RIS            :1;
					uint32_t OVR_RIS              :1;
					uint32_t ERR_RIS              :1;
					uint32_t VSYNC_RIS            :1;
					uint32_t LINE_RIS             :1;
					uint32_t                      :27;
			
				//SOOL-DCMI_RISR-DECLARATION
			};
			#endif
			
			#ifdef DCMI_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t HSYNC                :1;
					uint32_t VSYNC                :1;
					uint32_t FNE                  :1;
					uint32_t                      :29;
			
				//SOOL-DCMI_SR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					SR_TypeDef SR;       // @0x004
					RISR_TypeDef RISR;   // @0x008
					IER_TypeDef IER;     // @0x00c
					MISR_TypeDef MISR;   // @0x010
					ICR_TypeDef ICR;     // @0x014
					ESCR_TypeDef ESCR;   // @0x018
					ESUR_TypeDef ESUR;   // @0x01c
					CWSTRTR_TypeDef CWSTRTR; // @0x020
					CWSIZER_TypeDef CWSIZER; // @0x024
					DR_TypeDef DR;       // @0x028
				};
			};
			private:
			DCMI() = delete;
			//SOOL-DCMI-DECLARATION
		};
		
		//region instances
#if defined(STM32F207xx ) || defined(STM32F217xx ) || defined(STM32F407xx ) || defined(STM32F417xx ) ||\
    defined(STM32F427xx ) || defined(STM32F429xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) || defined(STM32F745xx ) ||\
    defined(STM32F746xx ) || defined(STM32F756xx ) || defined(STM32F765xx ) || defined(STM32F767xx ) ||\
    defined(STM32F769xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32L496xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4P    ) 
#define DCMI_BASE_ADDR ((uint32_t)0x50050000U)
#endif

#if defined(STM32H7     ) 
#define DCMI_BASE_ADDR ((uint32_t)0x48020000U)
#endif

#ifdef DCMI_BASE_ADDR
volatile class DCMI * const DCMI = reinterpret_cast<class DCMI* const>(DCMI_BASE_ADDR);
#endif
//endregion

//SOOL-DCMI-DEFINES
//SOOL-DCMI-DEFINITION
	};
};//region undef
#undef DCMI_CR_0_FCRC0
#undef DCMI_CR_0_FCRC1
#undef DCMI_CR_0_EDM0
#undef DCMI_CR_0_EDM1
#undef DCMI_CR_0_CRE
#undef DCMI_CR_0_OUTEN
#undef DCMI_CR_0_BSM0
#undef DCMI_CR_0_BSM1
#undef DCMI_CR_0_OEBS
#undef DCMI_CR_0_LSM
#undef DCMI_CR_0_OELS
#undef DCMI_CR_1_FCRC
#undef DCMI_CR_1_EDM
//endregion
#endif
#endif
