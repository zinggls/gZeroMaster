/**
 * \file
 *
 * \brief SPI basic driver.
 *
 (c) 2020 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/**
 * \defgroup doc_driver_spi_basic SPI Basic
 * \ingroup doc_driver_spi
 *
 * \section doc_driver_spi_basic_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <spi_basic.h>
#include <atmel_start_pins.h>

typedef struct SPI_0_descriptor_s {
	spi_transfer_status_t status;
} SPI_0_descriptor_t;

static SPI_0_descriptor_t SPI_0_desc;

static void drive_slave_select_low(void);
static void drive_slave_select_high(void);

/**
 * \brief Initialize SPI interface
 * If module is configured to disabled state, the clock to the SPI is disabled
 * if this is supported by the device's clock system.
 *
 * \return Initialization status.
 * \retval 0 the SPI init was successful
 * \retval 1 the SPI init was not successful
 */
void SPI_0_init()
{

	/* Enable SPI */
	PRR &= ~(1 << PRSPI);

	SPCR = 1 << SPE                     /* SPI module enable: enabled */
	       | 0 << DORD                  /* Data order: disabled */
	       | 1 << MSTR                  /* Master/Slave select: enabled */
	       | 0 << CPOL                  /* Clock polarity: disabled */
	       | 0 << CPHA                  /* Clock phase: disabled */
	       | 0 << SPIE                  /* SPI interrupt enable: disabled */
	       | (0 << SPR1) | (0 << SPR0); /* SPI Clock rate selection: fosc/4 */

	// SPSR = (0 << SPI2X); /* Disable double SPI speed */

	SPI_0_desc.status = SPI_FREE;
}

/**
 * \brief Enable SPI_0
 * 1. If supported by the clock system, enables the clock to the SPI
 * 2. Enables the SPI module by setting the enable-bit in the SPI control register
 *
 * \return Nothing
 */
void SPI_0_enable()
{
	SPCR |= (1 << SPE);
}

/**
 * \brief Disable SPI_0
 * 1. Disables the SPI module by clearing the enable-bit in the SPI control register
 * 2. If supported by the clock system, disables the clock to the SPI
 *
 * \return Nothing
 */
void SPI_0_disable()
{
	SPCR &= ~(1 << SPE);
}

static void drive_slave_select_low()
{
	PORTB_set_pin_level(2, false);
}

static void drive_slave_select_high()
{
	PORTB_set_pin_level(2, true);
}


/**
 * \brief Exchange one byte over SPI SPI_0. Blocks until done.
 *
 * \param[in] data The byte to transfer
 *
 * \return Received data byte.
 */
uint8_t SPI_0_exchange_byte(uint8_t data)
{
	// Blocking wait for SPI free makes the function work
	// seamlessly also with IRQ drivers.
	while (SPI_0_desc.status == SPI_BUSY)
		;
	SPDR = data;
	while (!(SPSR & (1 << SPIF)))
		;
	return SPDR;
}

/**
 * \brief Exchange a buffer over SPI SPI_0. Blocks if using polled driver.
 *
 * \param[inout] block The buffer to transfer. Received data is returned here.
 * \param[in] size The size of buffer to transfer
 *
 * \return Nothing.
 */
void SPI_0_exchange_block(void *block, uint8_t size)
{
	uint8_t *b = (uint8_t *)block;
	while (size--) {
		SPDR = *b;
		while (!(SPSR & (1 << SPIF)))
			;
		*b = SPDR;
		b++;
	}
}

/**
 * \brief Write a buffer over SPI SPI_0. Blocks if using polled driver.
 *
 * \param[in] block The buffer to transfer
 * \param[in] size The size of buffer to transfer
 *
 * \return Nothing.
 */
void SPI_0_write_block(void *block, uint8_t size)
{
	uint8_t *b = (uint8_t *)block;
	while (size--) {
		SPDR = *b;
		while (!(SPSR & (1 << SPIF)))
			;
		b++;
	}
}

/**
 * \brief Read a buffer over SPI SPI_0. Blocks if using polled driver.
 *
 * Zeros are transmitted out of the SPI.
 *
 * \param[out] block Received data is written here.
 * \param[in] size The size of buffer to transfer
 *
 * \return Nothing.
 */
void SPI_0_read_block(void *block, uint8_t size)
{
	uint8_t *b = (uint8_t *)block;
	while (size--) {
		SPDR = 0;
		while (!(SPSR & (1 << SPIF)))
			;
		*b = SPDR;
		b++;
	}
}

#include <clock_config.h>
#include <util/delay.h>

void SPI_0_write_reg(uint8_t addr, uint8_t data)
{
	uint8_t temp[2] = {(addr << 1), data};

	_delay_ms(10);
	drive_slave_select_low();	
	SPI_0_write_block(temp, 2);
	drive_slave_select_high();
}

void SPI_0_read_reg(uint8_t addr, uint8_t* data)
{
	uint8_t temp = ((addr << 1) | 1);

	_delay_ms(10);
	drive_slave_select_low();
	SPI_0_write_block(&temp, 1);	
	SPI_0_read_block(data, 1);
	drive_slave_select_high();
}