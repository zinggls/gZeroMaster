﻿#include <atmel_start.h>
#include <string.h>
#define CHIP		"CHIP:B0"			//Chip model name	(MUST BE 7Bytes long)

/*
 * UART Initiallize
 */
 
 
/*
 * UART 문자 출력
 */
void UART_TX_CH(unsigned char c) {
    while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = c;
}

void UART_TX_STR(char *s) {
	while(*s) {
		UART_TX_CH(*s++);
	}
}

unsigned char UART_RX_CH(void)
{
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}

void UART_RX_STR(char* s)
{
	while(1)
	{
		unsigned char temp;
		temp = UART_RX_CH();
		if( (temp == '\0') | (temp == '\n') | (temp == '\r'))
		break;
		*s++ = temp;
	}
}

void hextostr(uint8_t h, char* str)
{
	uint8_t changeData[2] = {0, };
	uint8_t i = 0;
		
	changeData[0] = (h >> 4);
	changeData[1] = (h & 0xf);
	
	for(i = 0; i < 2; i++)
	{
		if ( changeData[i] >= 10 )
			str[i] = changeData[i] - 10 + 'A';
		else
			str[i] = changeData[i] + '0';
	}
}

void B0_Init(void)
{
	SPI_0_write_reg(0x02, 0x18); //RX_REG1 INIT
	SPI_0_write_reg(0x07, 0x0); //TX_REG1[23:16] INIT
	SPI_0_write_reg(0x06, 0x10); //TX_REG1[15:8] INIT
	SPI_0_write_reg(0x05, 0x10); //TX_REG1[7:0] INIT
	SPI_0_write_reg(0x0d, 0x01); //TX_REG2[16] INIT
	SPI_0_write_reg(0x0c, 0xf7); //TX_REG2[15:8] INIT
	SPI_0_write_reg(0x0b, 0xb7); //TX_REG2[7:0] INIT
	SPI_0_write_reg(0x11, 0x01); //BIAS_REG1[0] INIT
	SPI_0_write_reg(0x12, 0x99); //BIAS_REG2 INIT
	SPI_0_write_reg(0x13, 0x99); //BIAS_REG3 INIT
	SPI_0_write_reg(0x14, 0x96); //BIAS_REG4 INIT
	SPI_0_write_reg(0x15, 0x66); //BIAS_REG5 INIT
	SPI_0_write_reg(0x16, 0x66); //BIAS_REG6 INIT
	SPI_0_write_reg(0x17, 0x06); //BIAS_REG7 INIT
	SPI_0_write_reg(0x18, 0x50); //BIAS_REG8 INIT
}

void B0_reg_show(void)
{
	uint8_t rx_data = 0;
	char t_tx[3] = {0, };
	
	UART_TX_STR("RX_REG1[4:0] : ");
	SPI_0_read_reg(0x02, &rx_data);
	hextostr((rx_data & 0x1f), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("TX_REG1[23:16] : ");
	SPI_0_read_reg(0x07, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("TX_REG1[15:8] : ");
	SPI_0_read_reg(0x06, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("TX_REG1[7:0] : ");
	SPI_0_read_reg(0x05, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("TX_REG2[16] : ");
	SPI_0_read_reg(0x0d, &rx_data);
	hextostr((rx_data & 1), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("TX_REG2[15:8] : ");
	SPI_0_read_reg(0x0c, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("TX_REG2[7:0] : ");
	SPI_0_read_reg(0x0b, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("BIAS_REG1[0] : ");
	SPI_0_read_reg(0x11, &rx_data);
	hextostr((rx_data & 0x1), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("BIAS_REG2[7:0] : ");
	SPI_0_read_reg(0x12, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("BIAS_REG3[7:0] : ");
	SPI_0_read_reg(0x13, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("BIAS_REG4[7:0] : ");
	SPI_0_read_reg(0x14, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("BIAS_REG5[7:0] : ");
	SPI_0_read_reg(0x15, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("BIAS_REG6[7:0] : ");
	SPI_0_read_reg(0x16, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("BIAS_REG7[7:0] : ");
	SPI_0_read_reg(0x17, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
	UART_TX_STR("BIAS_REG8[7:0] : ");
	SPI_0_read_reg(0x18, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
}

void chip_show()
{
	UART_TX_STR(CHIP);		//Chip model name
}

int main(void)
{
	uint8_t rw = 0;
	uint8_t data[2] = {0, };
	char t_tx[3] = {0, };
		
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();	
	B0_Init();
	/* Replace with your application code */
	while (1) {
		char t_rx_addr[4] = {0, };
		char t_rx_data[4] = {0, };

		UART_RX_STR(t_rx_addr);		//Get Address
		data[0] = (uint8_t)(strtol(t_rx_addr, NULL, 16));
		
		if(data[0] == 0xff) {
			UART_RX_CH();	//Don't care input character, just to be consistent with the read/write
			chip_show();
			continue;
		}
		
		if(data[0] > 0x7f)
		{
			B0_reg_show();
			continue;
		}

		rw = UART_RX_CH();	//Write or Read? "Write : 0, Read : 1"
		rw = rw & 1;
		if(!rw) {
			/* Write */
			UART_RX_STR(t_rx_data);	//Data(hex)
		    data[1] = (uint8_t)(strtol(t_rx_data, NULL, 16));						
			SPI_0_write_reg(data[0], data[1]);			
		}else{
			/* Read */
			SPI_0_read_reg(data[0], &data[1]);	//Data(hex)
			hextostr(data[1], t_tx);
			UART_TX_STR(t_tx);
		}
	}
}
