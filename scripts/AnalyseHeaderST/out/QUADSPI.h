#ifndef __SOOL_QUADSPI_H
#define __SOOL_QUADSPI_H

#include "peripheral_include.h"
//SOOL-QUADSPI-INCLUDES
#if defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L4     ) 
//region defines

#define QUADSPI_ABR
#define QUADSPI_AR
#define QUADSPI_CCR
#define QUADSPI_CR
#define QUADSPI_DCR
#define QUADSPI_DLR
#define QUADSPI_DR
#define QUADSPI_FCR
#define QUADSPI_LPTR
#define QUADSPI_PIR
#define QUADSPI_PSMAR
#define QUADSPI_PSMKR
#define QUADSPI_SR

#if defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L431xx ) || defined(STM32L432xx ) ||\
    defined(STM32L433xx ) || defined(STM32L442xx ) || defined(STM32L443xx ) || defined(STM32L451xx ) ||\
    defined(STM32L452xx ) || defined(STM32L462xx ) || defined(STM32L496xx ) || defined(STM32L4A6xx ) 
#define QUADSPI_CCR_DHHC     DHHC                 // 1 bits @ 30
#define QUADSPI_CR_0_DFM     DFM                  // 1 bits @ 6
#define QUADSPI_CR_0_FSEL    FSEL                 // 1 bits @ 7
#else
#define QUADSPI_CCR_DHHC
#define QUADSPI_CR_0_DFM
#define QUADSPI_CR_0_FSEL
#endif

#if defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F7     ) 
#define QUADSPI_CR_0_FTHRES  FTHRES               // 5 bits @ 8
#else
#define QUADSPI_CR_0_FTHRES
#endif

#if defined(STM32H7     ) || defined(STM32L4     ) 
#define QUADSPI_CR_1
#endif

#if defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) 
#define QUADSPI_SR_0_FLEVEL  FLEVEL               // 6 bits @ 8
#else
#define QUADSPI_SR_0_FLEVEL
#endif

#if defined(STM32F7     ) || defined(STM32H7     ) || defined(STM32L4     ) 
#define QUADSPI_SR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class QUADSPI
		{
			//SOOL-QUADSPI-ENUMS
			
			public :
			
			#ifdef QUADSPI_ABR
			struct ABR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ALTERNATE            :32;
			
				//SOOL-QUADSPI_ABR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_AR
			struct AR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t ADDRESS              :32;
			
				//SOOL-QUADSPI_AR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_CCR
			struct CCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INSTRUCTION          :8;
					uint32_t IMODE                :2;
					uint32_t ADMODE               :2;
					uint32_t ADSIZE               :2;
					uint32_t ABMODE               :2;
					uint32_t ABSIZE               :2;
					uint32_t DCYC                 :5;
					uint32_t                      :1;
					uint32_t DMODE                :2;
					uint32_t FMODE                :2;
					uint32_t SIOO                 :1;
					uint32_t                      :1;
					uint32_t QUADSPI_CCR_DHHC     :1;
					uint32_t DDRM                 :1;
			
				//SOOL-QUADSPI_CCR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t EN                   :1;
						uint32_t ABORT                :1;
						uint32_t DMAEN                :1;
						uint32_t TCEN                 :1;
						uint32_t SSHIFT               :1;
						uint32_t                      :1;
						uint32_t QUADSPI_CR_0_DFM     :1;
						uint32_t QUADSPI_CR_0_FSEL    :1;
						uint32_t QUADSPI_CR_0_FTHRES  :5;
						uint32_t                      :3;
						uint32_t TEIE                 :1;
						uint32_t TCIE                 :1;
						uint32_t FTIE                 :1;
						uint32_t SMIE                 :1;
						uint32_t TOIE                 :1;
						uint32_t                      :1;
						uint32_t APMS                 :1;
						uint32_t PMM                  :1;
						uint32_t PRESCALER            :8;
					};
					#ifdef QUADSPI_CR_1
					struct
					{
						uint32_t                      :8;
						uint32_t FTHRES               :4;
						uint32_t                      :20;
					};
					#endif
				};
				//SOOL-QUADSPI_CR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_DCR
			struct DCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CKMODE               :1;
					uint32_t                      :7;
					uint32_t CSHT                 :3;
					uint32_t                      :5;
					uint32_t FSIZE                :5;
					uint32_t                      :11;
			
				//SOOL-QUADSPI_DCR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_DLR
			struct DLR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DL                   :32;
			
				//SOOL-QUADSPI_DLR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_DR
			struct DR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DATA                 :32;
			
				//SOOL-QUADSPI_DR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_FCR
			struct FCR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t CTEF                 :1;
					uint32_t CTCF                 :1;
					uint32_t                      :1;
					uint32_t CSMF                 :1;
					uint32_t CTOF                 :1;
					uint32_t                      :27;
			
				//SOOL-QUADSPI_FCR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_LPTR
			struct LPTR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t TIMEOUT              :16;
					uint32_t                      :16;
			
				//SOOL-QUADSPI_LPTR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_PIR
			struct PIR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t INTERVAL             :16;
					uint32_t                      :16;
			
				//SOOL-QUADSPI_PIR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_PSMAR
			struct PSMAR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MATCH                :32;
			
				//SOOL-QUADSPI_PSMAR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_PSMKR
			struct PSMKR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t MASK                 :32;
			
				//SOOL-QUADSPI_PSMKR-DECLARATION
			};
			#endif
			
			#ifdef QUADSPI_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					struct
					{
						uint32_t TEF                  :1;
						uint32_t TCF                  :1;
						uint32_t FTF                  :1;
						uint32_t SMF                  :1;
						uint32_t TOF                  :1;
						uint32_t BUSY                 :1;
						uint32_t                      :2;
						uint32_t QUADSPI_SR_0_FLEVEL  :6;
						uint32_t                      :18;
					};
					#ifdef QUADSPI_SR_1
					struct
					{
						uint32_t                      :8;
						uint32_t FLEVEL               :5;
						uint32_t                      :19;
					};
					#endif
				};
				//SOOL-QUADSPI_SR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					DCR_TypeDef DCR;     // @0x004
					SR_TypeDef SR;       // @0x008
					FCR_TypeDef FCR;     // @0x00c
					DLR_TypeDef DLR;     // @0x010
					CCR_TypeDef CCR;     // @0x014
					AR_TypeDef AR;       // @0x018
					ABR_TypeDef ABR;     // @0x01c
					DR_TypeDef DR;       // @0x020
					PSMKR_TypeDef PSMKR; // @0x024
					PSMAR_TypeDef PSMAR; // @0x028
					PIR_TypeDef PIR;     // @0x02c
					LPTR_TypeDef LPTR;   // @0x030
				};
			};
			private:
			QUADSPI() = delete;
			//SOOL-QUADSPI-DECLARATION
		};
		
		//region instances
#if defined(STM32F412Rx ) || defined(STM32F412Vx ) || defined(STM32F412Zx ) || defined(STM32F413xx ) ||\
    defined(STM32F423xx ) || defined(STM32F446xx ) || defined(STM32F469xx ) || defined(STM32F479xx ) ||\
    defined(STM32F7     ) || defined(STM32L4     ) 
#define QUADSPI_BASE_ADDR ((uint32_t)0xA0001000U)
#endif

#if defined(STM32H7     ) 
#define QUADSPI_BASE_ADDR ((uint32_t)0x52005000U)
#endif

#ifdef QUADSPI_BASE_ADDR
volatile class QUADSPI * const QUADSPI = reinterpret_cast<class QUADSPI* const>(QUADSPI_BASE_ADDR);
#endif
//endregion

//SOOL-QUADSPI-DEFINES
//SOOL-QUADSPI-DEFINITION
	};
};//region undef
#undef QUADSPI_CCR_DHHC
#undef QUADSPI_CR_0_DFM
#undef QUADSPI_CR_0_FSEL
#undef QUADSPI_CR_0_FTHRES
#undef QUADSPI_SR_0_FLEVEL
//endregion
#endif
#endif
