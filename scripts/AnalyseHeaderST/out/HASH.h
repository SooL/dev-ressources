#ifndef __SOOL_HASH_H
#define __SOOL_HASH_H

#include "peripheral_include.h"
//SOOL-HASH-INCLUDES
#if defined(STM32F756xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32L4A6xx ) ||\
    defined(STM32L4S5xx ) || defined(STM32L4S7xx ) || defined(STM32L4S9xx ) 
//region defines

#define HASH_CR
#define HASH_CSR
#define HASH_DIN
#define HASH_HR
#define HASH_IMR
#define HASH_SR
#define HASH_STR
#define HASH_DIGEST_HR

#if defined(STM32F215xx ) || defined(STM32F217xx ) 
#define HASH_CR_ALGO         ALGO                 // 1 bits @ 7
#else
#define HASH_CR_ALGO
#endif

#if defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F479xx ) || defined(STM32F756xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) ||\
    defined(STM32H750xx ) || defined(STM32H753xx ) || defined(STM32L4A6xx ) || defined(STM32L4S5xx ) ||\
    defined(STM32L4S7xx ) || defined(STM32L4S9xx ) 
#define HASH_CR_MDMAT        MDMAT                // 1 bits @ 13
#else
#define HASH_CR_MDMAT
#endif

#if defined(STM32F215xx ) || defined(STM32F217xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F479xx ) || defined(STM32F756xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32H750xx ) || defined(STM32H753xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4S5xx ) || defined(STM32L4S7xx ) || defined(STM32L4S9xx ) 
#define HASH_IMR_0
#define HASH_STR_0
#endif

#if defined(STM32F215xx ) || defined(STM32F217xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F479xx ) 
#define HASH_IMR_1
#define HASH_STR_1
#endif

//endregion

namespace sool
{
	namespace core
	{
		class HASH
		{
			//SOOL-HASH-ENUMS
			
			public :
			
			#ifdef HASH_CR
			struct CR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t                      :2;
					uint32_t INIT                 :1;
					uint32_t DMAE                 :1;
					uint32_t DATATYPE             :2;
					uint32_t MODE                 :1;
					uint32_t HASH_CR_ALGO         :1;
					uint32_t NBW                  :4;
					uint32_t DINNE                :1;
					uint32_t HASH_CR_MDMAT        :1;
					uint32_t                      :2;
					uint32_t LKEY                 :1;
					uint32_t                      :15;
			
				//SOOL-HASH_CR-DECLARATION
			};
			#endif
			
			#ifdef HASH_IMR
			struct IMR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HASH_IMR_0
					struct
					{
						uint32_t DINIE                :1;
						uint32_t DCIE                 :1;
						uint32_t                      :30;
					};
					#endif
					#ifdef HASH_IMR_1
					struct
					{
						uint32_t DINIM                :1;
						uint32_t DCIM                 :1;
						uint32_t                      :30;
					};
					#endif
				};
				//SOOL-HASH_IMR-DECLARATION
			};
			#endif
			
			#ifdef HASH_SR
			struct SR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
				
					uint32_t DINIS                :1;
					uint32_t DCIS                 :1;
					uint32_t DMAS                 :1;
					uint32_t BUSY                 :1;
					uint32_t                      :28;
			
				//SOOL-HASH_SR-DECLARATION
			};
			#endif
			
			#ifdef HASH_STR
			struct STR_TypeDef : public Reg32_t
			{
				using Reg32_t::operator=;
			
				union
				{
					#ifdef HASH_STR_0
					struct
					{
						uint32_t NBLW                 :5;
						uint32_t                      :3;
						uint32_t DCAL                 :1;
						uint32_t                      :23;
					};
					#endif
					#ifdef HASH_STR_1
					struct
					{
						uint32_t NBW                  :5;
						uint32_t                      :27;
					};
					#endif
				};
				//SOOL-HASH_STR-DECLARATION
			};
			#endif
			
			union
			{
				
				struct
				{
					CR_TypeDef CR;       // @0x000
					uint32_t DIN;        // @0x004
					STR_TypeDef STR;     // @0x008
					uint32_t HR[5];      // @0x00c
					IMR_TypeDef IMR;     // @0x020
					SR_TypeDef SR;       // @0x024
					__SOOL_PERIPH_PADDING_128;
					__SOOL_PERIPH_PADDING_64;
					__SOOL_PERIPH_PADDING_16;
					uint32_t CSR[54];    // @0x0f8
				};
			};
			private:
			HASH() = delete;
			//SOOL-HASH-DECLARATION
		};
		
		
		class HASH_DIGEST
		{
			//SOOL-HASH_DIGEST-ENUMS
			
			public :
			
			union
			{
				
				struct
				{
					uint32_t HR[8];      // @0x000
				};
			};
			private:
			HASH_DIGEST() = delete;
			//SOOL-HASH_DIGEST-DECLARATION
		};
		
		//region instances
#if defined(STM32F215xx ) || defined(STM32F217xx ) || defined(STM32F415xx ) || defined(STM32F417xx ) ||\
    defined(STM32F437xx ) || defined(STM32F439xx ) || defined(STM32F479xx ) || defined(STM32F756xx ) ||\
    defined(STM32F777xx ) || defined(STM32F779xx ) || defined(STM32L4A6xx ) || defined(STM32L4S5xx ) ||\
    defined(STM32L4S7xx ) || defined(STM32L4S9xx ) 
#define HASH_BASE_ADDR ((uint32_t)0x50060400U)
#endif

#if defined(STM32H750xx ) || defined(STM32H753xx ) 
#define HASH_BASE_ADDR ((uint32_t)0x48021400U)
#define HASH_DIGEST_BASE_ADDR ((uint32_t)0x48021710U)
#endif

#if defined(STM32F415xx ) || defined(STM32F417xx ) || defined(STM32F437xx ) || defined(STM32F439xx ) ||\
    defined(STM32F479xx ) || defined(STM32F756xx ) || defined(STM32F777xx ) || defined(STM32F779xx ) ||\
    defined(STM32L4A6xx ) || defined(STM32L4S5xx ) || defined(STM32L4S7xx ) || defined(STM32L4S9xx ) 
#define HASH_DIGEST_BASE_ADDR ((uint32_t)0x50060710U)
#endif

#ifdef HASH_BASE_ADDR
volatile class HASH * const HASH = reinterpret_cast<class HASH* const>(HASH_BASE_ADDR);
#endif
#ifdef HASH_DIGEST_BASE_ADDR
volatile class HASH_DIGEST * const HASH_DIGEST = reinterpret_cast<class HASH_DIGEST* const>(HASH_DIGEST_BASE_ADDR);
#endif
//endregion

//SOOL-HASH-DEFINES
//SOOL-HASH-DEFINITION
	};
};//region undef
#undef HASH_CR_ALGO
#undef HASH_CR_MDMAT
//endregion
#endif
#endif
