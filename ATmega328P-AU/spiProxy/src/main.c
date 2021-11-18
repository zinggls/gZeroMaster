#include <atmel_start.h>
#include <string.h>
#include <avr/eeprom.h>

#define CHIP		"CHIP:B0"			//Chip model name	(MUST BE 7Bytes long)
#define SAVED		"Saved  "			//Saved message		(MUST BE 7Bytes long)
#define LOADED		"Loaded "			//Loaded message	(MUST BE 7Bytes long)
#define BASE_ADDR	((uint8_t*)0x0)

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

void eeprom_update_byte_from_SPI_0_read_reg(uint8_t addr)
{
	uint8_t readData;
	SPI_0_read_reg(addr, &readData);
	eeprom_update_byte(BASE_ADDR+addr,readData);
}

void SaveData()
{
	//RX
	eeprom_update_byte_from_SPI_0_read_reg(0x02);
	
	//TX
	eeprom_update_byte_from_SPI_0_read_reg(0x07);
	eeprom_update_byte_from_SPI_0_read_reg(0x06);
	eeprom_update_byte_from_SPI_0_read_reg(0x05);
	eeprom_update_byte_from_SPI_0_read_reg(0x0d);
	eeprom_update_byte_from_SPI_0_read_reg(0x0c);
	eeprom_update_byte_from_SPI_0_read_reg(0x0b);
	
	//BIAS
	eeprom_update_byte_from_SPI_0_read_reg(0x11);
	eeprom_update_byte_from_SPI_0_read_reg(0x12);
	eeprom_update_byte_from_SPI_0_read_reg(0x13);
	eeprom_update_byte_from_SPI_0_read_reg(0x14);
	eeprom_update_byte_from_SPI_0_read_reg(0x15);
	eeprom_update_byte_from_SPI_0_read_reg(0x16);
	eeprom_update_byte_from_SPI_0_read_reg(0x17);
	eeprom_update_byte_from_SPI_0_read_reg(0x18);
}

void SPI_0_write_reg_from_eeprom_read_byte(uint8_t addr)
{
	uint8_t readData = eeprom_read_byte(BASE_ADDR+addr);
	SPI_0_write_reg(addr, readData);
}

void LoadData()
{
	//RX
	SPI_0_write_reg_from_eeprom_read_byte(0x02);
	
	//TX
	SPI_0_write_reg_from_eeprom_read_byte(0x07);
	SPI_0_write_reg_from_eeprom_read_byte(0x06);
	SPI_0_write_reg_from_eeprom_read_byte(0x05);
	SPI_0_write_reg_from_eeprom_read_byte(0x0d);
	SPI_0_write_reg_from_eeprom_read_byte(0x0c);
	SPI_0_write_reg_from_eeprom_read_byte(0x0b);
	
	//BIAS
	SPI_0_write_reg_from_eeprom_read_byte(0x11);
	SPI_0_write_reg_from_eeprom_read_byte(0x12);
	SPI_0_write_reg_from_eeprom_read_byte(0x13);
	SPI_0_write_reg_from_eeprom_read_byte(0x14);
	SPI_0_write_reg_from_eeprom_read_byte(0x15);
	SPI_0_write_reg_from_eeprom_read_byte(0x16);
	SPI_0_write_reg_from_eeprom_read_byte(0x17);
	SPI_0_write_reg_from_eeprom_read_byte(0x18);
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
	
	LoadData();
	while (1) {
		char t_rx_addr[4] = {0, };
		char t_rx_data[4] = {0, };

		UART_RX_STR(t_rx_addr);		//Get Address
		data[0] = (uint8_t)(strtol(t_rx_addr, NULL, 16));
		
		rw = UART_RX_CH();	//Write or Read? "Write : 0, Read : 1"
		
		if(data[0] == 0xff) {
			/* Get Chip model name */
			UART_TX_STR(CHIP);		//Chip model name
			continue;
		}else if(data[0] == 0xf1) {
			/* Save to EEPROM */
			UART_RX_STR(t_rx_data);	//Data(hex), dummy data to be neglected
			SaveData();
			continue;			
		}else if(data[0] == 0xf2) {
			/* Load from EEPROM */
			UART_RX_STR(t_rx_data);	//Data(hex), dummy data to be neglected
			LoadData();
			continue;			
		}

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
