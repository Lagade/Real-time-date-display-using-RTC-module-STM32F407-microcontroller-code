/*
 * stm32f407.h
 *
 *  Created on: 01-Feb-2021
 *      Author: Shubham
 */

#ifndef INC_STM32F407_H_
#define INC_STM32F407_H_

#include<stddef.h>
#include<stdint.h>

#define __vo volatile
#define __weak __attribute__((weak))

/*********Porcessor specific Details********/
/****ARM cortex Mx processor NVIC ISERx register Addresses*****/
#define NVIC_ISER0           ( (__vo uint32_t*)0xE000E100 )
#define NVIC_ISER1           ( (__vo uint32_t*)0xE000E104 )
#define NVIC_ISER2           ( (__vo uint32_t*)0xE000E108 )
#define NVIC_ISER3           ( (__vo uint32_t*)0xE000E10C )

/****ARM cortex Mx processor NVIC ICERx register Addresses*****/
#define NVIC_ICER0           ( (__vo uint32_t*)0XE000E180 )
#define NVIC_ICER1           ( (__vo uint32_t*)0XE000E184 )
#define NVIC_ICER2           ( (__vo uint32_t*)0XE000E188 )
#define NVIC_ICER3           ( (__vo uint32_t*)0XE000E18C )

/****ARM cortex Mx processor NVIC Priority base address register Addresses*****/
#define NVIC_PR_BASE_ADDR   ((__vo uint32_t*)0xE000E400 )

#define NO_PR_BITS_IMPLEMENTED           4

//Memory Base addresses
#define FLASH_BASEADDR       0x08000000U
#define SRAM1_BASEADDR       0x20000000U
#define SRAM2_BASEADDR       0x20001C00U  //this address is calulated please refer notes
#define ROM_BASEADDR         0x1FFF0000U  //aka system memory
#define SRAM                 SRAM1_BASEADDR

//Peripheral Bus Base addresses
#define PERIPHER_BASE        0x40000000U
#define APB1PERIPH_BASE      PERIPHER_BASE
#define APB2PERIPH_BASE      0x40010000U
#define AHB1PERIPH_BASE      0x40020000U
#define AHB2PERIPH_BASE      0x50000000U


//GPIO peripheral Base addresses
#define GPIOA_BASEADDR       (AHB1PERIPH_BASE + 0x0000)
#define GPIOB_BASEADDR       (AHB1PERIPH_BASE + 0x0400)
#define GPIOC_BASEADDR       (AHB1PERIPH_BASE + 0x0800)
#define GPIOD_BASEADDR       (AHB1PERIPH_BASE + 0x0C00)
#define GPIOE_BASEADDR       (AHB1PERIPH_BASE + 0x1000)
#define GPIOF_BASEADDR       (AHB1PERIPH_BASE + 0x1400)
#define GPIOG_BASEADDR       (AHB1PERIPH_BASE + 0x1800)
#define GPIOH_BASEADDR       (AHB1PERIPH_BASE + 0x1C00)
#define GPIOI_BASEADDR       (AHB1PERIPH_BASE + 0x2000)
#define GPIOJ_BASEADDR       (AHB1PERIPH_BASE + 0x2400)
#define GPIOK_BASEADDR       (AHB1PERIPH_BASE + 0x2800)
#define RCC_BASEADDR         (AHB1PERIPH_BASE + 0x3800)

#define I2C1_BASEADDR         (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASEADDR         (APB1PERIPH_BASE + 0x5800)
#define I2C3_BASEADDR         (APB1PERIPH_BASE + 0x5C00)

#define UART4_BASEADDR        (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASEADDR        (APB1PERIPH_BASE + 0x5000)
#define USART2_BASEADDR       (APB1PERIPH_BASE + 0x4400)
#define USART3_BASEADDR       (APB1PERIPH_BASE + 0x4800)

#define SPI2_BASEADDR         (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASEADDR         (APB1PERIPH_BASE + 0x3C00)

#define SPI1_BASEADDR         (APB2PERIPH_BASE + 0x3000)
#define USART1_BASEADDR        (APB2PERIPH_BASE + 0x1000)
#define USART6_BASEADDR       (APB2PERIPH_BASE + 0x1400)
#define EXTI_BASEADDR         (APB2PERIPH_BASE + 0x3C00)
#define SYSCFG_BASEADDR       (APB2PERIPH_BASE + 0x3800)

//Peripheral register defination structure
typedef struct
{
	__vo uint32_t MODER;    //Address offset: 0X00
	__vo uint32_t OTYPER;   //Address offset: 0x04
	__vo uint32_t OSPEEDR;
	__vo uint32_t PUPDR;
	__vo uint32_t IDR;
	__vo uint32_t ODR;
	__vo uint32_t BSRR;
	__vo uint32_t LCKR;
	__vo uint32_t AFR[2];  //AFR[0]: GPIO alt.function low register, AF[1]: GPIO alt.func. High register
}GPIO_Regdef_t;


typedef struct
{
	__vo uint32_t RCC_CR;
	__vo uint32_t PLLCFGR;
	__vo uint32_t CFGR;
	__vo uint32_t CIR;
	__vo uint32_t AHB1RSTR;
	__vo uint32_t AHB2RSTR;
	__vo uint32_t AHB3RSTR;
	     uint32_t Reserved0;
	     uint32_t Reserved1;
	     uint32_t Reserved2;
	     uint32_t Reserved3;
	__vo uint32_t APB1RSTR;
	__vo uint32_t APB2RSTR;
	__vo uint32_t AHB1ENR;
	__vo uint32_t AHB2ENR;
	__vo uint32_t AHB3ENR;
	__vo uint32_t APB1ENR;
	__vo uint32_t APB2ENR;
	     uint32_t Reserved4; // offset 0x48
	     uint32_t Reserved5; //offset 0x4C
    __vo uint32_t AHB1LPENR;
    __vo uint32_t AHB2LPENR;
    __vo uint32_t AHB3LPENR;
         uint32_t Reserved6; //offset 0x5C
    __vo uint32_t APB1LPENR;
    __vo uint32_t APB2LPENR;
         uint32_t Reserved7; //offset 0x68
         uint32_t Reserved8; //offset 0x6C
    __vo uint32_t BDCR;
    __vo uint32_t CSR;
         uint32_t Reserved9; //offset 0x78
         uint32_t Reserved10; //offset 0x7C
    __vo uint32_t SSCGR;
    __vo uint32_t PLLI2SCFGR;
}RCC_Regdef_t;

//Peripheral register defination structure for EXTI

typedef struct
{
	__vo uint32_t IMR;      //offset value: 0x00
	__vo uint32_t EMR;
	__vo uint32_t RTSR;
	__vo uint32_t FTSR;
	__vo uint32_t SWIER;
	__vo uint32_t PR;

}EXTI_RegDef_t;

//Peripheral register defination structure for SYSCFG

typedef struct
{
	__vo uint32_t MEMRMP;
	__vo uint32_t PMC;
	__vo uint32_t EXTICR[4];
	__vo uint32_t CMPR;

}SYSCFG_RegDef_t;


/*****Peripheral register defination structure for SPI*******/
typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;
}SPI_RegDef_t;

/*
 * Peripheral register defination structure for I2C
 */

typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t OAR1;
	__vo uint32_t OAR2;
	__vo uint32_t DR;
	__vo uint32_t SR1;
	__vo uint32_t SR2;
	__vo uint32_t CCR;
	__vo uint32_t TRISE;
	__vo uint32_t FLTR;
}I2C_RegDef_t;

/*
 * Peripheral register definition structure for USART
 */

typedef struct
{
	__vo uint32_t USART_SR;
	__vo uint32_t USART_DR;
	__vo uint32_t USART_BRR;
	__vo uint32_t USART_CR1;
	__vo uint32_t USART_CR2;
	__vo uint32_t USART_CR3;
	__vo uint32_t USART_GTPR;
}USART_Regdef_t;

//peripherla definations (Peripheral base address type casted to xxx_Regdef_t)

#define GPIOA      ((GPIO_Regdef_t*)GPIOA_BASEADDR)
#define GPIOB      ((GPIO_Regdef_t*)GPIOB_BASEADDR)
#define GPIOC      ((GPIO_Regdef_t*)GPIOC_BASEADDR)
#define GPIOD      ((GPIO_Regdef_t*)GPIOD_BASEADDR)
#define GPIOE      ((GPIO_Regdef_t*)GPIOE_BASEADDR)
#define GPIOF      ((GPIO_Regdef_t*)GPIOF_BASEADDR)
#define GPIOG      ((GPIO_Regdef_t*)GPIOG_BASEADDR)
#define GPIOH      ((GPIO_Regdef_t*)GPIOH_BASEADDR)
#define GPIOI      ((GPIO_Regdef_t*)GPIOI_BASEADDR)
#define GPIOJ      ((GPIO_Regdef_t*)GPIOJ_BASEADDR)
#define GPIOK      ((GPIO_Regdef_t*)GPIOK_BASEADDR)

#define RCC        ((RCC_Regdef_t*)RCC_BASEADDR)

#define EXTI       ((EXTI_RegDef_t*)EXTI_BASEADDR)

#define SYSCFG     ((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)

#define SPI1       ((SPI_RegDef_t*)SPI1_BASEADDR)
#define SPI2       ((SPI_RegDef_t*)SPI2_BASEADDR)
#define SPI3       ((SPI_RegDef_t*)SPI3_BASEADDR)

#define I2C1       ((I2C_RegDef_t*)I2C1_BASEADDR)
#define I2C2       ((I2C_RegDef_t*)I2C2_BASEADDR)
#define I2C3       ((I2C_RegDef_t*)I2C3_BASEADDR)

#define USART1     ((USART_Regdef_t*)USART1_BASEADDR)
#define USART2     ((USART_Regdef_t*)USART2_BASEADDR)
#define USART3     ((USART_Regdef_t*)USART3_BASEADDR)
#define UART4      ((USART_Regdef_t*)UART4_BASEADDR)
#define UART5      ((USART_Regdef_t*)UART5_BASEADDR)
#define USART6     ((USART_Regdef_t*)USART6_BASEADDR)

//Clock enable Macros for GPIOx peripherals
#define GPIOA_PCLK_EN()      ( RCC-> AHB1ENR |= (1 >> 0))
#define GPIOB_PCLK_EN()      ( RCC-> AHB1ENR |= (1 >> 1))
#define GPIOC_PCLK_EN()      ( RCC-> AHB1ENR |= (1 >> 2))
#define GPIOD_PCLK_EN()      ( RCC-> AHB1ENR |= (1 >> 3))
#define GPIOE_PCLK_EN()      ( RCC-> AHB1ENR |= (1 >> 4))
#define GPIOF_PCLK_EN()      ( RCC-> AHB1ENR |= (1 >> 5))
#define GPIOG_PCLK_EN()      ( RCC-> AHB1ENR |= (1 >> 6))
#define GPIOH_PCLK_EN()      ( RCC-> AHB1ENR |= (1 >> 7))
#define GPIOI_PCLK_EN()      ( RCC-> AHB1ENR |= (1 >> 8))

//Clock enable Macros for I2Cx peripherals

#define I2C1_PCLK_EN()       ( RCC ->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()       ( RCC ->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()       ( RCC ->APB1ENR |= (1 << 23))

//Clock enable Macros for SPIx peripherals

#define SPI1_PCLK_EN()        ( RCC ->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()        ( RCC ->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()        ( RCC ->APB1ENR |= (1 << 15))

//Clock enable Macros for USARTx peripherals

#define USART1_PCLK_EN()     ( RCC ->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()     ( RCC ->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()     ( RCC ->APB1ENR |= (1 << 18))
#define USART6_PCLK_EN()     ( RCC ->APB2ENR |= (1 << 5))

//Clock enable Macros for SYSCFG peripherals

#define SYSCFG_PCLK_EN()     ( RCC ->APB2ENR |= (1 << 14))

//Clock Disable Macros for GPIOx peripherals
#define GPIOA_PCLK_DI()      ( RCC-> AHB1ENR &= ~(1 >> 0))
#define GPIOB_PCLK_DI()      ( RCC-> AHB1ENR &= ~(1 >> 1))
#define GPIOC_PCLK_DI()      ( RCC-> AHB1ENR &= ~(1 >> 2))
#define GPIOD_PCLK_DI()      ( RCC-> AHB1ENR &= ~(1 >> 3))
#define GPIOE_PCLK_DI()      ( RCC-> AHB1ENR &= ~(1 >> 4))
#define GPIOF_PCLK_DI()      ( RCC-> AHB1ENR &= ~(1 >> 5))
#define GPIOG_PCLK_DI()      ( RCC-> AHB1ENR &= ~(1 >> 6))
#define GPIOH_PCLK_DI()      ( RCC-> AHB1ENR &= ~(1 >> 7))
#define GPIOI_PCLK_DI()      ( RCC-> AHB1ENR &= ~(1 >> 8))

//Clock Disble Macros for I2Cx peripherals

#define I2C1_PCLK_DI()       ( RCC ->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()       ( RCC ->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()       ( RCC ->APB1ENR &= ~(1 << 23))

//Clock Disble Macros for SPIx peripherals

#define SPI1_PCLK_DI()        ( RCC ->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()        ( RCC ->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()        ( RCC ->APB1ENR &= ~(1 << 15))

//Clock Disble Macros for USARTx peripherals

#define USART1_PCLK_DI()     ( RCC ->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()     ( RCC ->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()     ( RCC ->APB1ENR &= ~(1 << 18))
#define USART6_PCLK_DI()     ( RCC ->APB2ENR &= ~(1 << 5))


//Clock Disable Macros for SYSCFG peripherals

#define SYSCFG_PCLK_DI()     ( RCC ->APB2ENR &= ~(1 << 14))

//Macros to reset GPIOx peripherals

#define GPIOA_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0)); }while(0)
#define GPIOB_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1)); }while(0)
#define GPIOC_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2)); }while(0)
#define GPIOD_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3)); }while(0)
#define GPIOE_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4)); }while(0)
#define GPIOF_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5)); }while(0)
#define GPIOG_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6)); }while(0)
#define GPIOH_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7)); }while(0)
#define GPIOI_REG_RESET()    do{ (RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8)); }while(0)


//This macro returns a code (b/w 0 to 7) for given GPIO base address(x)
#define GPIO_BASEADDR_TO_CODE(x)         ( (x == GPIOA)?0:\
		                                  (x == GPIOB)?1:\
		                                  (x == GPIOC)?2:\
		                                  (x == GPIOD)?3:\
		                                  (x == GPIOE)?4:\
		                                  (x == GPIOF)?5:\
		                                  (x == GPIOG)?6:\
		                                  (x == GPIOH)?7:\
		                                  (x == GPIOI)?8:0 )

/*
 * IRQ(Interrupt Request) Numbers of STM32F407x MCU
 * NOTE: update these macros with valid values according to your MCU
 * TODO: You may complete this list for other peripherals
 */

#define IRQ_NO_EXTI0 		6     //this info is in reference manual in GPIO functional description.
#define IRQ_NO_EXTI1 		7
#define IRQ_NO_EXTI2 		8
#define IRQ_NO_EXTI3 		9
#define IRQ_NO_EXTI4 		10
#define IRQ_NO_EXTI9_5 		23
#define IRQ_NO_EXTI15_10 	40

#define IRQ_NO_SPI1         35   //for IRQ no. always refer the reference manual in that vector table in that position no.
#define IRQ_NO_SPI2         36
#define IRQ_NO_SPI3         51

#define IRQ_NO_I2C1_EV      31
#define IRQ_NO_I2C1_ER      32
#define IRQ_NO_I2C2_EV      33
#define IRQ_NO_I2C2_ER      34
#define IRQ_NO_I2C3_EV      72
#define IRQ_NO_I2C3_ER      73

#define IRQ_NO_USART1       37
#define IRQ_NO_USART2       38
#define IRQ_NO_USART3       39
#define IRQ_NO_USART6       71

/******************NVIC Priority macros defined***********/
#define NVIC_IRQ_PRI0        0
#define NVIC_IRQ_PRI1        1
#define NVIC_IRQ_PRI2        2
#define NVIC_IRQ_PRI3        3
#define NVIC_IRQ_PRI4        4
#define NVIC_IRQ_PRI5        5
#define NVIC_IRQ_PRI6        6
#define NVIC_IRQ_PRI7        7
#define NVIC_IRQ_PRI8        8
#define NVIC_IRQ_PRI9        9
#define NVIC_IRQ_PRI10       10
#define NVIC_IRQ_PRI11       11
#define NVIC_IRQ_PRI12       12
#define NVIC_IRQ_PRI13       13
#define NVIC_IRQ_PRI14       14
#define NVIC_IRQ_PRI15       15


/***********Bit Position defination of SPI Peripherals**********/

/*
 * Bit postion definition of SPI_CR1
 */
#define SPI_CR1_CPHA          0
#define SPI_CR1_CPOL          1
#define SPI_CR1_MSTR          2
#define SPI_CR1_BR            3
#define SPI_CR1_SPE           6
#define SPI_CR1_LSB_FIRST     7
#define SPI_CR1_SSI           8
#define SPI_CR1_SSM           9
#define SPI_CR1_RXONLY        10
#define SPI_CR1_DFF           11
#define SPI_CR1_CRCNEXT       12
#define SPI_CR1_CRCEN         13
#define SPI_CR1_BIDIOE        14
#define SPI_CR1_BIDIMODE      15

/*
 * Bit position definition of SPI_CR2
 */
#define SPI_CR2_RXDMAEN       0
#define SPI_CR2_TXDMAEN       1
#define SPI_CR2_SSOE          2
#define SPI_CR2_RES           3
#define SPI_CR2_FRF           4
#define SPI_CR2_ERRIE         5
#define SPI_CR2_RXNEIE        6
#define SPI_CR2_TXNEIE        7

/*
 * Bit position definition of SPI_SR
 */
#define SPI_SR_RXNE           0
#define SPI_SR_TXE            1
#define SPI_SR_CHSIDE         2
#define SPI_SR_UDR            3
#define SPI_SR_CRCERR         4
#define SPI_SR_MODF           5
#define SPI_SR_OVR            6
#define SPI_SR_BSY            7
#define SPI_SR_FRE            8

/*
 * Bit position defination for I2C CR1
 */

#define I2C_CR1_PE            0
#define I2C_CR1_NOSTRETCH     7
#define I2C_CR1_START         8
#define I2C_CR1_STOP          9
#define I2C_CR1_ACK           10
#define I2C_CR1_SWRST         15
#define I2C_CR1_POS           11
#define I2C_CR1_PEC           12
#define I2C_CR1_ALERT         13


/*
 * Bit position defination for I2C CR2
 */

#define I2C_CR2_FRQ           0
#define I2C_CR2_ITERREN       8
#define I2C_CR2_ITEVTEN       9
#define I2C_CR2_ITBUFEN       10
#define I2C_CR2_DMAEN         11
#define I2C_CR2_LAST          12

/*
 * Bit position defination for I2C SR1
 */

#define I2C_SR1_SB            0
#define I2C_SR1_ADDR          1
#define I2C_SR1_BTF           2
#define I2C_SR1_ADD10         3
#define I2C_SR1_STOPF         4
#define I2C_SR1_RXNE          6
#define I2C_SR1_TXE           7
#define I2C_SR1_BERR          8
#define I2C_SR1_ARLO          9
#define I2C_SR1_AF            10
#define I2C_SR1_OVR           11
#define I2C_SR1_PECERR        12
#define I2C_SR1_TIMEOUT       14
#define I2C_SR1_SMBALERT      15

/*
 * Bit position defination for I2C SR1
 */

#define I2C_SR2_MSL           0
#define I2C_SR2_BUSY          1
#define I2C_SR2_TRA           2
#define I2C_SR2_GENCALL       4
#define I2C_SR2_SMBDEFALUT    5
#define I2C_SR2_SMBHOST       6
#define I2C_SR2_DUALF         7
#define I2C_SR2_PEC           8

/*
 * Bit position defination for I2C CCR
 */

#define I2C_CCR              0
#define I2C_CCR_DUTY         14
#define I2C_CCR_FS           15

/*
 * Bit position definition for USART_SR
 */

#define USART_SR_PE          0
#define USART_SR_FE          1
#define USART_SR_NF          2
#define USART_SR_ORE         3
#define USART_SR_IDLE        4
#define USART_SR_RXNE        5
#define USART_SR_TC          6
#define USART_SR_TXE         7
#define USART_SR_LBD         8
#define USART_SR_CTS         9

/*
 * Bit position definition for USART_BRR
 */

#define USART_BRR_DIV_FRACTION   0
#define USART_BRR_DIV_MANTISSA   4

/*
 * Bit position definition for USART_CR1
 */
#define USART_CR1_SBK       0
#define USART_CR1_RWU       1
#define USART_CR1_RE        2
#define USART_CR1_TE        3
#define USART_CR1_IDLEIE    4
#define USART_CR1_RXNEIE    5
#define USART_CR1_TCIE      6
#define USART_CR1_TXEIE     7
#define USART_CR1_PEIE      8
#define USART_CR1_PS        9
#define USART_CR1_PCE       10
#define USART_CR1_WAKE      11
#define USART_CR1_M         12
#define USART_CR1_UE        13
#define USART_CR1_OVER8     15

/*
 * Bit position definition for USART_CR2
 */

#define USART_CR2_ADD       0
#define USART_CR2_LBDL      5
#define USART_CR2_LBDIE     6
#define USART_CR2_LBCL      8
#define USART_CR2_CPHA      9
#define USART_CR2_CPOL      10
#define USART_CR2_CLKEN     11
#define USART_CR2_STOP      12
#define USART_CR2_LINEN     14

/*
 * Bit position definition for USART_CR3
 */

#define USART_CR3_EIE         0
#define USART_CR3_IRNE        1
#define USART_CR3_IRLP        2
#define USART_CR3_HDSEL       3
#define USART_CR3_NACK        4
#define USART_CR3_SCEN        5
#define USART_CR3_DMAR        6
#define USART_CR3_DMAT        7
#define USART_CR3_RTSE        8
#define USART_CR3_CTSE        9
#define USART_CR3_CTSIE       10
#define USART_CR3_ONEBIT      11

/*
 * Bit position definition for USART_GTPR
 */

#define USART_GTPR_PSC       0
#define USART_GTPR_GT        8

//some generic macros

#define ENABLE                   1
#define DISABLE                  0
#define SET                    ENABLE
#define RESET                  DISABLE

#define GPIO_PIN_SET           SET
#define GPIO_PIN_RESET         RESET
#define FLAG_RESET             RESET
#define FLAG_SET               SET



#include "stm32f407_i2c_driver.h"
#include "stm32f407_rcc_driver.h"
#include "stm32f407_gpio_driver.h"
#include "ds1307.h"


#endif /* INC_STM32F407_H_ */
