//SOOL-GPIO-INCLUDES-BEGIN
#include "RCC.h"

//SOOL-GPIO-INCLUDES-END
class GPIO
{
//SOOL-GPIO-SUB-TYPES-BEGIN
public:
//##################################################################################################
//#                                              Pin                                              #
//##################################################################################################
	enum class Pin : uint32_t
	{
		None = (0),
		P0 = (1U << 0U),
		P1 = (1U << 1U),
		P2 = (1U << 2U),
		P3 = (1U << 3U),
		P4 = (1U << 4U),
		P5 = (1U << 5U),
		P6 = (1U << 6U),
		P7 = (1U << 7U),
		P8 = (1U << 8U),
		P9 = (1U << 9U),
		P10 = (1U << 10U),
		P11 = (1U << 11U),
		P12 = (1U << 12U),
		P13 = (1U << 13U),
		P14 = (1U << 14U),
		P15 = (1U << 15U),
		All = 0xFFFF
	};

//##################################################################################################
//#                                             enums                                              #
//##################################################################################################
	enum class Mode : std::uint8_t
	{
		Input = 0, IN = 0,
#ifndef STM32F1
		Output = 1, OUT = 1,
		AlternateFunction = 2, AF = 2,
		Analog = 3,
#else
		Output_10MHz = 1, OUT_10M = 1,
		Output_2MHz = 2, OUT_2M = 2,
		Output_50MHz = 3, OUT_50M = 3,
#endif
		Mask = 3
	};
#ifndef STM32F1
	enum class OutType : std::uint8_t
	{
		PushPull = 0,
		OpenDrain = 1,
		Mask = 1
	};

	enum class Speed : std::uint8_t
	{
		Slow = 0,
		Medium = 1,
		High = 2,
		VeryHigh = 3,
		Mask = 3
	};

	enum class PuPd : std::uint8_t
	{
		NoPull = 0,
		PullUp = 1,
		PullDown = 2,
		Mask = 3
	};

	enum class AF : std::uint8_t
	{
		AF0 = 0x0U,
		AF1 = 0x1U,
		AF2 = 0x2U,
		AF3 = 0x3U,
		AF4 = 0x4U,
		AF5 = 0x5U,
		AF6 = 0x6U,
		AF7 = 0x7U,
		AF8 = 0x8U,
		AF9 = 0x9U,
		AF10 = 0xAU,
		AF11 = 0xBU,
		AF12 = 0xCU,
		AF13 = 0xDU,
		AF14 = 0xEU,
		AF15 = 0xFU,
		Mask = 0xFU
	};
#ifdef GPIO_ASCR
	enum class ASC : std::uint8_t
	{
		Disconnected = 0,
		Connected = 1,
		Mask = 1
	};
#endif
#else
	enum class CNF : std::uint8_t
	{
		IN_Analog = 0,
		IN_Floating = 1,
		IN_PuPd = 2,
		OUT_GP_PushPull = 0,
		OUT_GP_OpenDrain = 1,
		OUT_AF_PushPull = 2,
		OUT_AF_OpenDrain = 3,
		Mask = 3
	};
#endif

	struct PinConfig
	{
		Mode mode:2;

		PinConfig(const Mode &mode) : mode(mode), modif(1)
		{};
#ifndef STM32F1
		OutType outType:1;
		Speed speed:2;
		PuPd pupd:2;
		AF af:4;

		PinConfig(const OutType &oType) : outType(oType), modif(2)
		{};

		PinConfig(const Speed &speed) : speed(speed), modif(4)
		{};

		PinConfig(const PuPd &pupd) : pupd(pupd), modif(8)
		{};

		PinConfig(const AF &af) : af(af), modif(16)
		{};
#ifdef GPIO_ASCR
		ASC asc: 1;
		PinConfig(const ASC& asc):asc(asc), modif(32){};
#endif
#else
		CNF cnf : 2;
		PinConfig(const CNF& cnf):cnf(cnf), modif(2){};
#endif
		uint8_t modif;
	};
//SOOL-GPIO-SUB-TYPES-END

//SOOL-GPIO-DECLARATIONS-BEGIN
//##################################################################################################
//#                                              methods                                           #
//##################################################################################################
private:
	static constexpr uint32_t get_clock_enable_bit(const uint32_t addr);

public:
	static constexpr const Pin pin(unsigned int id);

	void enable_clock() volatile;

	void disable_clock() volatile;

	bool is_clock_enabled() const volatile;

	void set_AF(Pin pins, GPIO::AF af) volatile;

	bool set_locked(Pin pins, bool locked) volatile;

//SOOL-GPIO-DECLARATIONS-END
//SOOL-GPIO_ODR-DECLARATIONS-BEGIN
	const GPIO::ODR_TypeDef &operator=(const Pin &p) volatile;

	const GPIO::ODR_TypeDef &operator|=(const Pin &p) volatile;

	const GPIO::ODR_TypeDef &operator&=(const Pin &p) volatile;

	const GPIO::ODR_TypeDef &operator^=(const Pin &p) volatile;

	const GPIO::ODR_TypeDef &operator+=(const Pin &p) volatile;

	const GPIO::ODR_TypeDef &operator-=(const Pin &p) volatile;
//SOOL-GPIO_ODR-DECLARATIONS-END
};
//SOOL-GPIO-DEFINITIONS-BEGIN

template<unsigned char num>
struct StandAlone_Pin
{
#ifndef STM32F1
	union
	{
		GPIO port;
		struct
		{
			uint32_t : num * 2;
			GPIO::Mode mode            : 2;
			uint32_t :(32 - (num + 1) * 2);
			uint32_t : num * 1;
			GPIO::OutType outType    : 1;
			uint32_t :(32 - (num + 1) * 1);
			uint32_t : num * 2;
			GPIO::Speed speed        : 2;
			uint32_t :(32 - (num + 1) * 2);
			uint32_t : num * 2;
			GPIO::PuPd pupd            : 2;
			uint32_t :(32 - (num + 1) * 2);
			uint64_t : 64; // IDR,ODR
			uint64_t : 64; // BSRR,LCKR
			uint64_t : num * 4;
			GPIO::AF af                : 4;
			uint64_t :(64 - (num + 1) * 4);
#ifdef GPIO_ASCR
			uint32_t : 32; //BRR
			uint32_t: num*1; GPIO::ASC asc			: 1; uint32_t :(32 - (num+1)*1);
#endif
		};
	};

	const GPIO::OutType &operator=(const GPIO::OutType &oType) volatile;

	const GPIO::Speed &operator=(const GPIO::Speed &speed) volatile;

	const GPIO::PuPd &operator=(const GPIO::PuPd &pupd) volatile;

	const GPIO::AF &operator=(const GPIO::AF &af) volatile;

#ifdef GPIO_ASCR
	const GPIO::ASC& operator=(const GPIO::ASC& asc);
#endif

#else
	union
	{
		GPIO port;
		struct
		{
			uint32_t :num*4; GPIO::Mode mode :2; GPIO::CNF cnf :2; uint32_t : (64 - (num+1)*4);
		};
	};
	const GPIO::CNF& operator=(const CNF& cnf);
#endif

	const GPIO::Mode &operator=(const GPIO::Mode &mode) volatile;

	const GPIO::PinConfig &operator=(const GPIO::PinConfig &config) volatile;

	operator GPIO::PinConfig const() volatile;

	bool read() volatile;

	void write(bool value) volatile;

	void toggle() volatile;

	const GPIO::Pin pin() volatile;
} __attribute__((__aligned__(4)));
//#################################################################################################
//#                                  GPIO methods and operators                                   #
//#################################################################################################

inline constexpr const GPIO::Pin GPIO::pin(const unsigned int pin_num)
{
	return static_cast<GPIO::Pin>(1 << pin_num);
}

inline constexpr uint32_t GPIO::get_clock_enable_bit(const uint32_t addr)
{
#if defined(STM32F0     ) || defined(STM32F3     )
	unsigned int offset = 17u;
#else
	unsigned int offset = 0u;
#endif
	switch (addr) {
#ifdef GPIOA_BASE_ADDR
		case GPIOA_BASE_ADDR: return 1u << (offset + 0);
#endif
#ifdef GPIOB_BASE_ADDR
		case GPIOB_BASE_ADDR: return 1u << (offset + 1);
#endif
#ifdef GPIOC_BASE_ADDR
		case GPIOC_BASE_ADDR: return 1u << (offset + 2);
#endif
#ifdef GPIOD_BASE_ADDR
		case GPIOD_BASE_ADDR: return 1u << (offset + 3);
#endif
#ifdef GPIOE_BASE_ADDR
		case GPIOE_BASE_ADDR: return 1u << (offset + 4);
#endif
#ifdef GPIOF_BASE_ADDR
		case GPIOF_BASE_ADDR: return 1u << (offset + 5);
#endif
#ifdef GPIOG_BASE_ADDR
		case GPIOG_BASE_ADDR: return 1u << (offset + 6);
#endif
#ifdef GPIOH_BASE_ADDR
		case GPIOH_BASE_ADDR: return 1u << (offset + 7);
#endif
#ifdef GPIOI_BASE_ADDR
		case GPIOI_BASE_ADDR: return 1u << (offset + 8);
#endif
#ifdef GPIOJ_BASE_ADDR
		case GPIOJ_BASE_ADDR: return 1u << (offset + 9);
#endif
#ifdef GPIOK_BASE_ADDR
		case GPIOK_BASE_ADDR: return 1u << (offset + 10);
#endif
		default:
			return 0;
	}
}

inline void GPIO::enable_clock() volatile
{
	const unsigned int bit = GPIO::get_clock_enable_bit((unsigned int) reinterpret_cast<const std::size_t>(this));

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32F7     )
	RCC->AHB1ENR |= bit;
#elif defined(STM32L4     ) || defined(STM32L4P    )
	RCC->AHB2ENR |= bit;
#elif defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32L1     )
	RCC->AHBENR |= bit;
#elif defined(RCC_AHB4ENR)
	RCC->AHB4ENR |= bit;
#endif
}

inline void GPIO::disable_clock() volatile
{
	const unsigned int mask = ~GPIO::get_clock_enable_bit((unsigned int) reinterpret_cast<const std::size_t>(this));

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32F7     )
	RCC->AHB1ENR &= mask;
#elif defined(STM32L4     ) || defined(STM32L4P    )
	RCC->AHB2ENR &= mask;
#elif defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32L1     )
	RCC->AHBENR &= mask;
#elif defined(RCC_AHB4ENR)
	RCC->AHB4ENR &= mask;
#endif
}

inline bool GPIO::is_clock_enabled() const volatile
{
	const unsigned int bit = GPIO::get_clock_enable_bit((unsigned int) reinterpret_cast<const std::size_t>(this));

#if defined(STM32F2     ) || defined(STM32F4     ) || defined(STM32F7     )
	return (RCC->AHB1ENR & bit) == bit;
#elif defined(STM32L4     ) || defined(STM32L4P    )
	return (RCC->AHB2ENR & bit) == bit;
#elif defined(STM32F0     ) || defined(STM32F3     ) || defined(STM32L1     )
	return (RCC->AHBENR & bit) == bit;
#elif defined(RCC_AHB4ENR)
	return (RCC->AHB4ENR & bit) == bit;
#endif
}

//##################################################################################################
//#                                    Pin methods and operators                                   #
//##################################################################################################
inline constexpr GPIO::Pin operator|(const GPIO::Pin &a, const GPIO::Pin &b)
{ return static_cast<GPIO::Pin>(static_cast<const uint32_t>(a) | static_cast<const uint32_t>(b)); }

inline constexpr GPIO::Pin operator&(const GPIO::Pin &a, const GPIO::Pin &b)
{ return static_cast<GPIO::Pin>(static_cast<const uint32_t>(a) & static_cast<const uint32_t>(b)); }

inline constexpr GPIO::Pin operator~(const GPIO::Pin &a)
{ return static_cast<GPIO::Pin>(~static_cast<const uint32_t>(a)); }

inline constexpr GPIO::Pin operator+(const GPIO::Pin &a, const GPIO::Pin &b)
{ return a | b; }

inline constexpr GPIO::Pin operator-(const GPIO::Pin &a, const GPIO::Pin &b)
{ return a & (~b); }

inline constexpr GPIO::Pin &operator|=(GPIO::Pin &a, const GPIO::Pin &b)
{ return a = a | b; }


inline constexpr const uint32_t operator*(const GPIO::Pin &pins, const GPIO::Mode &mode)
{
	uint32_t v = 0, i = 16;
	while (i--) {
		if ((pins & GPIO::pin(i)) != GPIO::Pin::None)
			v |= static_cast<uint32_t>(mode) << (i * 2);
	}
	return v;
}

inline constexpr const uint32_t operator*(const GPIO::Mode &mode, const GPIO::Pin &pins)
{ return pins * mode; }

inline constexpr const uint32_t operator*(const GPIO::Pin &pins, const GPIO::OutType &type)
{ return static_cast<uint32_t>(pins) * static_cast<uint32_t>(type); }

inline constexpr const uint32_t operator*(const GPIO::OutType &type, const GPIO::Pin &pins)
{ return pins * type; }

inline constexpr const uint32_t operator*(const GPIO::Pin &pins, const GPIO::Speed &speed)
{
	uint32_t v = 0, i = 16;
	while (i--) {
		if ((pins & GPIO::pin(i)) != GPIO::Pin::None)
			v |= static_cast<uint32_t>(speed) << (i * 2);
	}
	return v;
}

inline constexpr const uint32_t operator*(const GPIO::Speed &speed, const GPIO::Pin &pins)
{ return pins * speed; }

inline constexpr const uint32_t operator*(const GPIO::Pin &pins, const GPIO::PuPd &pupd)
{
	uint32_t v = 0, i = 16;
	while (i--) {
		if ((pins & GPIO::pin(i)) != GPIO::Pin::None)
			v |= static_cast<uint32_t>(pupd) << (i * 2);
	}
	return v;
}

inline constexpr const uint32_t operator*(const GPIO::PuPd &pupd, const GPIO::Pin &pins)
{ return pins * pupd; }

inline constexpr const uint64_t operator*(const GPIO::Pin &pins, const GPIO::AF &af)
{
	uint64_t v = 0;
	uint32_t i = 16;
	while (i--) {
		if ((pins & GPIO::pin(i)) != GPIO::Pin::None)
			v |= ((uint64_t)
		static_cast<uint64_t>(af)) << (i * 4);
	}
	return v;
}

inline constexpr const uint64_t operator*(const GPIO::AF &af, const GPIO::Pin &pins)
{ return pins * af; }


inline const GPIO::ODR_TypeDef &GPIO::ODR_TypeDef::operator=(const GPIO::Pin &p) volatile
{
	*this = static_cast<uint32_t>(p);
	return *const_cast<const GPIO::ODR_TypeDef *>(this);
}

inline const GPIO::ODR_TypeDef &GPIO::ODR_TypeDef::operator&=(const GPIO::Pin &p) volatile
{
	*this &= static_cast<uint32_t>(p);
	return *const_cast<const GPIO::ODR_TypeDef *>(this);
}

inline const GPIO::ODR_TypeDef &GPIO::ODR_TypeDef::operator|=(const GPIO::Pin &p) volatile
{
	*reinterpret_cast<volatile uint32_t *>(this) |= static_cast<uint32_t>(p);
	return *const_cast<const GPIO::ODR_TypeDef *>(this);
}

inline const GPIO::ODR_TypeDef &GPIO::ODR_TypeDef::operator^=(const GPIO::Pin &p) volatile
{
	*this ^= static_cast<uint32_t>(p);
	return *const_cast<const GPIO::ODR_TypeDef *>(this);
}

inline const GPIO::ODR_TypeDef &GPIO::ODR_TypeDef::operator+=(const GPIO::Pin &p) volatile
{
	*this |= p;
	return *const_cast<const GPIO::ODR_TypeDef *>(this);
}

inline const GPIO::ODR_TypeDef &GPIO::ODR_TypeDef::operator-=(const GPIO::Pin &p) volatile
{
	*this &= ~p;
	return *const_cast<const GPIO::ODR_TypeDef *>(this);
}

//region PinConfig operators
inline const GPIO::PinConfig operator|(const GPIO::PinConfig &pin_conf, const GPIO::Mode &mode)
{
	GPIO::PinConfig result = pin_conf;
	result.mode = mode;
	result.modif |= 1;
	return result;
}

#ifndef STM32F1

inline const GPIO::PinConfig operator|(const GPIO::PinConfig &pin_conf, const GPIO::OutType &oType)
{
	GPIO::PinConfig result = pin_conf;
	result.outType = oType;
	result.modif |= 2;
	return result;
}

inline const GPIO::PinConfig operator|(const GPIO::PinConfig &pin_conf, const GPIO::Speed &speed)
{
	GPIO::PinConfig result = pin_conf;
	result.speed = speed;
	result.modif |= 4;
	return result;
}

inline const GPIO::PinConfig operator|(const GPIO::PinConfig &pin_conf, const GPIO::PuPd &pupd)
{
	GPIO::PinConfig result = pin_conf;
	result.pupd = pupd;
	result.modif |= 8;
	return result;
}

inline const GPIO::PinConfig operator|(const GPIO::PinConfig &pin_conf, const GPIO::AF &af)
{
	GPIO::PinConfig result = pin_conf;
	result.af = af;
	result.modif |= 16;
	return result;
}

#ifdef GPIO_ASC
inline const GPIO::PinConfig operator|(const GPIO::PinConfig& pin_conf, const GPIO::ASC& asc)
{
	GPIO::PinConfig result = pin_config;
	result.asc = asc;
	result.modif |= 32;
	return result;
}
#endif
#else
inline const GPIO::PinConfig operator|(const GPIO::PinConfig& pin_conf, const GPIO::CNF& cnf)
{
	GPIO::PinConfig result = pin_conf;
	result.cnf = cnf;
	result.modif |= 2;
	return result;
}
#endif

//endregion
template<unsigned char num>
inline const GPIO::PinConfig &StandAlone_Pin<num>::operator=(const GPIO::PinConfig &config) volatile
{
	if (config.modif & 1) this->mode = config.mode;
#ifndef STM32F1
	if (config.modif & 2)this->outType = config.outType;
	if (config.modif & 4)this->speed = config.speed;
	if (config.modif & 8)this->pupd = config.pupd;
	if (config.modif & 16)this->af = config.af;
#ifdef GPIO_ASCR
	if(config.modif & 32)this->asc = config.asc;
#endif
#else
	if(config.modif & 2)this->cnf = config.cnf;
#endif
	return config;
}

template<unsigned char num>
inline const GPIO::Mode &StandAlone_Pin<num>::operator=(const GPIO::Mode &mode) volatile
{
	this->mode = mode;
	return mode;
}

#ifndef STM32F1

template<unsigned char num>
inline const GPIO::OutType &StandAlone_Pin<num>::operator=(const GPIO::OutType &oType) volatile
{
	this->outType = oType;
	return oType;
}

template<unsigned char num>
inline const GPIO::Speed &StandAlone_Pin<num>::operator=(const GPIO::Speed &speed) volatile
{
	this->speed = speed;
	return speed;
}

template<unsigned char num>
inline const GPIO::PuPd &StandAlone_Pin<num>::operator=(const GPIO::PuPd &pupd) volatile
{
	this->pupd = pupd;
	return pupd;
}

template<unsigned char num>
inline const GPIO::AF &StandAlone_Pin<num>::operator=(const GPIO::AF &af) volatile
{
	this->af = af;
	return af;
}

template<unsigned char num>
inline StandAlone_Pin<num>::operator GPIO::PinConfig const() volatile
{
	const GPIO::Mode mode = this->mode;
	GPIO::PinConfig config(mode);
#ifndef STM32F1
	config.modif = 0b11111;
	config.outType = this->outType;
	config.speed = this->speed;
	config.pupd = this->pupd;
	config.af = this->af;
#ifdef GPIO_ASCR
	config.asc = this->asc;
#endif
#else
	config.modif = 0b11;
	config.cnf = this->cnf;
#endif
	return config;
}

#ifdef GPIO_ASCR
template<unsigned char num>
inline const GPIO::ASC& StandAlone_Pin<num>::operator=(const GPIO::ASC& asc)
{
	this->asc = asc;
	return asc;
}
#endif
#else // STM32F1
template<unsigned char num>
inline const GPIO::CNF& StandAlone_Pin<num>::operator=(const GPIO::CNF& cnf)
{
	this->cnf = cnf;
	return cnf;
}
#endif

template<unsigned char num>
inline bool StandAlone_Pin<num>::read() volatile
{
	return (bool) ((reinterpret_cast<volatile GPIO *>(this))->IDR & (1 << num));
}

template<unsigned char num>
inline void StandAlone_Pin<num>::write(bool value) volatile
{
	(reinterpret_cast<volatile GPIO *>(this))->BSRR = value ? (1 << num) : (1 << (num + 16));
}

template<unsigned char num>
inline void StandAlone_Pin<num>::toggle() volatile
{
	(reinterpret_cast<volatile GPIO *>(this))->ODR ^= (1 << num);
}

template<unsigned char num>
inline const GPIO::Pin StandAlone_Pin<num>::pin() volatile
{
	return GPIO::Pin(num);
}

//region PXn definitions
#ifdef GPIOA_BASE_ADDR
extern volatile StandAlone_Pin< 0>& PA0 ;
extern volatile StandAlone_Pin< 1>& PA1 ;
extern volatile StandAlone_Pin< 2>& PA2 ;
extern volatile StandAlone_Pin< 3>& PA3 ;
extern volatile StandAlone_Pin< 4>& PA4 ;
extern volatile StandAlone_Pin< 5>& PA5 ;
extern volatile StandAlone_Pin< 6>& PA6 ;
extern volatile StandAlone_Pin< 7>& PA7 ;
extern volatile StandAlone_Pin< 8>& PA8 ;
extern volatile StandAlone_Pin< 9>& PA9 ;
extern volatile StandAlone_Pin<10>& PA10;
extern volatile StandAlone_Pin<11>& PA11;
extern volatile StandAlone_Pin<12>& PA12;
extern volatile StandAlone_Pin<13>& PA13;
extern volatile StandAlone_Pin<14>& PA14;
extern volatile StandAlone_Pin<15>& PA15;
#endif
#ifdef GPIOB_BASE_ADDR
extern volatile StandAlone_Pin< 0>& PB0 ;
extern volatile StandAlone_Pin< 1>& PB1 ;
extern volatile StandAlone_Pin< 2>& PB2 ;
extern volatile StandAlone_Pin< 3>& PB3 ;
extern volatile StandAlone_Pin< 4>& PB4 ;
extern volatile StandAlone_Pin< 5>& PB5 ;
extern volatile StandAlone_Pin< 6>& PB6 ;
extern volatile StandAlone_Pin< 7>& PB7 ;
extern volatile StandAlone_Pin< 8>& PB8 ;
extern volatile StandAlone_Pin< 9>& PB9 ;
extern volatile StandAlone_Pin<10>& PB10;
extern volatile StandAlone_Pin<11>& PB11;
extern volatile StandAlone_Pin<12>& PB12;
extern volatile StandAlone_Pin<13>& PB13;
extern volatile StandAlone_Pin<14>& PB14;
extern volatile StandAlone_Pin<15>& PB15;
#endif
#ifdef GPIOC_BASE_ADDR
extern volatile StandAlone_Pin< 0>& PC0 ;
extern volatile StandAlone_Pin< 1>& PC1 ;
extern volatile StandAlone_Pin< 2>& PC2 ;
extern volatile StandAlone_Pin< 3>& PC3 ;
extern volatile StandAlone_Pin< 4>& PC4 ;
extern volatile StandAlone_Pin< 5>& PC5 ;
extern volatile StandAlone_Pin< 6>& PC6 ;
extern volatile StandAlone_Pin< 7>& PC7 ;
extern volatile StandAlone_Pin< 8>& PC8 ;
extern volatile StandAlone_Pin< 9>& PC9 ;
extern volatile StandAlone_Pin<10>& PC10;
extern volatile StandAlone_Pin<11>& PC11;
extern volatile StandAlone_Pin<12>& PC12;
extern volatile StandAlone_Pin<13>& PC13;
extern volatile StandAlone_Pin<14>& PC14;
extern volatile StandAlone_Pin<15>& PC15;
#endif
#ifdef GPIOD_BASE_ADDR
extern volatile StandAlone_Pin< 0>& PD0 ;
extern volatile StandAlone_Pin< 1>& PD1 ;
extern volatile StandAlone_Pin< 2>& PD2 ;
extern volatile StandAlone_Pin< 3>& PD3 ;
extern volatile StandAlone_Pin< 4>& PD4 ;
extern volatile StandAlone_Pin< 5>& PD5 ;
extern volatile StandAlone_Pin< 6>& PD6 ;
extern volatile StandAlone_Pin< 7>& PD7 ;
extern volatile StandAlone_Pin< 8>& PD8 ;
extern volatile StandAlone_Pin< 9>& PD9 ;
extern volatile StandAlone_Pin<10>& PD10;
extern volatile StandAlone_Pin<11>& PD11;
extern volatile StandAlone_Pin<12>& PD12;
extern volatile StandAlone_Pin<13>& PD13;
extern volatile StandAlone_Pin<14>& PD14;
extern volatile StandAlone_Pin<15>& PD15;
#endif
#ifdef GPIOE_BASE_ADDR
extern volatile StandAlone_Pin< 0>& PE0 ;
extern volatile StandAlone_Pin< 1>& PE1 ;
extern volatile StandAlone_Pin< 2>& PE2 ;
extern volatile StandAlone_Pin< 3>& PE3 ;
extern volatile StandAlone_Pin< 4>& PE4 ;
extern volatile StandAlone_Pin< 5>& PE5 ;
extern volatile StandAlone_Pin< 6>& PE6 ;
extern volatile StandAlone_Pin< 7>& PE7 ;
extern volatile StandAlone_Pin< 8>& PE8 ;
extern volatile StandAlone_Pin< 9>& PE9 ;
extern volatile StandAlone_Pin<10>& PE10;
extern volatile StandAlone_Pin<11>& PE11;
extern volatile StandAlone_Pin<12>& PE12;
extern volatile StandAlone_Pin<13>& PE13;
extern volatile StandAlone_Pin<14>& PE14;
extern volatile StandAlone_Pin<15>& PE15;
#endif
#ifdef GPIOF_BASE_ADDR
extern volatile StandAlone_Pin< 0>& PF0 ;
extern volatile StandAlone_Pin< 1>& PF1 ;
extern volatile StandAlone_Pin< 2>& PF2 ;
extern volatile StandAlone_Pin< 3>& PF3 ;
extern volatile StandAlone_Pin< 4>& PF4 ;
extern volatile StandAlone_Pin< 5>& PF5 ;
extern volatile StandAlone_Pin< 6>& PF6 ;
extern volatile StandAlone_Pin< 7>& PF7 ;
extern volatile StandAlone_Pin< 8>& PF8 ;
extern volatile StandAlone_Pin< 9>& PF9 ;
extern volatile StandAlone_Pin<10>& PF10;
extern volatile StandAlone_Pin<11>& PF11;
extern volatile StandAlone_Pin<12>& PF12;
extern volatile StandAlone_Pin<13>& PF13;
extern volatile StandAlone_Pin<14>& PF14;
extern volatile StandAlone_Pin<15>& PF15;
#endif
#ifdef GPIOG_BASE_ADDR
extern volatile StandAlone_Pin< 0>& PG0 ;
extern volatile StandAlone_Pin< 1>& PG1 ;
extern volatile StandAlone_Pin< 2>& PG2 ;
extern volatile StandAlone_Pin< 3>& PG3 ;
extern volatile StandAlone_Pin< 4>& PG4 ;
extern volatile StandAlone_Pin< 5>& PG5 ;
extern volatile StandAlone_Pin< 6>& PG6 ;
extern volatile StandAlone_Pin< 7>& PG7 ;
extern volatile StandAlone_Pin< 8>& PG8 ;
extern volatile StandAlone_Pin< 9>& PG9 ;
extern volatile StandAlone_Pin<10>& PG10;
extern volatile StandAlone_Pin<11>& PG11;
extern volatile StandAlone_Pin<12>& PG12;
extern volatile StandAlone_Pin<13>& PG13;
extern volatile StandAlone_Pin<14>& PG14;
extern volatile StandAlone_Pin<15>& PG15;
#endif
#ifdef GPIOH_BASE_ADDR
extern volatile StandAlone_Pin< 0>& PH0 ;
extern volatile StandAlone_Pin< 1>& PH1 ;
extern volatile StandAlone_Pin< 2>& PH2 ;
extern volatile StandAlone_Pin< 3>& PH3 ;
extern volatile StandAlone_Pin< 4>& PH4 ;
extern volatile StandAlone_Pin< 5>& PH5 ;
extern volatile StandAlone_Pin< 6>& PH6 ;
extern volatile StandAlone_Pin< 7>& PH7 ;
extern volatile StandAlone_Pin< 8>& PH8 ;
extern volatile StandAlone_Pin< 9>& PH9 ;
extern volatile StandAlone_Pin<10>& PH10;
extern volatile StandAlone_Pin<11>& PH11;
extern volatile StandAlone_Pin<12>& PH12;
extern volatile StandAlone_Pin<13>& PH13;
extern volatile StandAlone_Pin<14>& PH14;
extern volatile StandAlone_Pin<15>& PH15;
#endif
#ifdef GPIOI_BASE_ADDR
extern volatile StandAlone_Pin< 0>& PI0 ;
extern volatile StandAlone_Pin< 1>& PI1 ;
extern volatile StandAlone_Pin< 2>& PI2 ;
extern volatile StandAlone_Pin< 3>& PI3 ;
extern volatile StandAlone_Pin< 4>& PI4 ;
extern volatile StandAlone_Pin< 5>& PI5 ;
extern volatile StandAlone_Pin< 6>& PI6 ;
extern volatile StandAlone_Pin< 7>& PI7 ;
extern volatile StandAlone_Pin< 8>& PI8 ;
extern volatile StandAlone_Pin< 9>& PI9 ;
extern volatile StandAlone_Pin<10>& PI10;
extern volatile StandAlone_Pin<11>& PI11;
extern volatile StandAlone_Pin<12>& PI12;
extern volatile StandAlone_Pin<13>& PI13;
extern volatile StandAlone_Pin<14>& PI14;
extern volatile StandAlone_Pin<15>& PI15;
#endif
#ifdef GPIOJ_BASE_ADDR
extern volatile StandAlone_Pin< 0>& PJ0 ;
extern volatile StandAlone_Pin< 1>& PJ1 ;
extern volatile StandAlone_Pin< 2>& PJ2 ;
extern volatile StandAlone_Pin< 3>& PJ3 ;
extern volatile StandAlone_Pin< 4>& PJ4 ;
extern volatile StandAlone_Pin< 5>& PJ5 ;
extern volatile StandAlone_Pin< 6>& PJ6 ;
extern volatile StandAlone_Pin< 7>& PJ7 ;
extern volatile StandAlone_Pin< 8>& PJ8 ;
extern volatile StandAlone_Pin< 9>& PJ9 ;
extern volatile StandAlone_Pin<10>& PJ10;
extern volatile StandAlone_Pin<11>& PJ11;
extern volatile StandAlone_Pin<12>& PJ12;
extern volatile StandAlone_Pin<13>& PJ13;
extern volatile StandAlone_Pin<14>& PJ14;
extern volatile StandAlone_Pin<15>& PJ15;
#endif
#ifdef GPIOK_BASE_ADDR
extern volatile StandAlone_Pin< 0>& PK0 ;
extern volatile StandAlone_Pin< 1>& PK1 ;
extern volatile StandAlone_Pin< 2>& PK2 ;
extern volatile StandAlone_Pin< 3>& PK3 ;
extern volatile StandAlone_Pin< 4>& PK4 ;
extern volatile StandAlone_Pin< 5>& PK5 ;
extern volatile StandAlone_Pin< 6>& PK6 ;
extern volatile StandAlone_Pin< 7>& PK7 ;
extern volatile StandAlone_Pin< 8>& PK8 ;
extern volatile StandAlone_Pin< 9>& PK9 ;
extern volatile StandAlone_Pin<10>& PK10;
extern volatile StandAlone_Pin<11>& PK11;
extern volatile StandAlone_Pin<12>& PK12;
extern volatile StandAlone_Pin<13>& PK13;
extern volatile StandAlone_Pin<14>& PK14;
extern volatile StandAlone_Pin<15>& PK15;
#endif
//endregion
//SOOL-GPIO-DEFINITIONS-END

//SOOL-GPIO-DEFINES-BEGIN
//SOOL-GPIO-DEFINES-END
