#include <atmel_start.h>
#include <string.h>
#include <avr/eeprom.h>

#define SAVED		"Saved  "			//Saved message		(MUST BE 7Bytes long)
#define LOADED		"Loaded "			//Loaded message	(MUST BE 7Bytes long)
#define VERSION		"01"				//Version			(MUST BE 2Bytes long)
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

void Zing400Rx_Init(void)
{
	SPI_0_write_reg(0x02, 0x18); //RX_REG1[4:3] INIT
	SPI_0_write_reg(0x11, 0x01); //BIAS_REG1[0] INIT
	SPI_0_write_reg(0x14, 0x96); //BIAS_REG4[7:0] INIT
	SPI_0_write_reg(0x15, 0x66); //BIAS_REG5[7:0] INIT
	SPI_0_write_reg(0x16, 0x66); //BIAS_REG6[7:0] INIT
	SPI_0_write_reg(0x17, 0x06); //BIAS_REG7[7:0] INIT
	SPI_0_write_reg(0x18, 0x06); //BIAS_REG8[7:0] INIT

	SPI_0_write_reg(0x26, 0x00); //RegOut26[3:0] INIT
	SPI_0_write_reg(0x27, 0x00); //RegOut27[7:0] INIT
	SPI_0_write_reg(0x28, 0x00); //RegOut28[7:0] INIT
	SPI_0_write_reg(0x29, 0x00); //RegOut29[7:0] INIT
	SPI_0_write_reg(0x2a, 0x00); //RegOut2A[7:0] INIT
	SPI_0_write_reg(0x2b, 0x00); //RegOut2B[7:0] INIT
	SPI_0_write_reg(0x2c, 0x10); //RegOut2C[7:0] INIT
}

void Zing400Tx_Init(void)
{
	SPI_0_write_reg(0x07, 0x0); //TX_REG1[23:16] INIT
	SPI_0_write_reg(0x06, 0x10); //TX_REG1[15:8] INIT
	SPI_0_write_reg(0x05, 0x10); //TX_REG1[7:0] INIT
	SPI_0_write_reg(0x0d, 0x01); //TX_REG2[16] INIT
	SPI_0_write_reg(0x0c, 0xe0); //TX_REG2[15:13] INIT
	SPI_0_write_reg(0x0b, 0x07); //TX_REG2[3:0] INIT

	SPI_0_write_reg(0x24, 0x01); //RegOut24[0] INIT
	SPI_0_write_reg(0x25, 0x78); //RegOut25[7:0] INIT
	SPI_0_write_reg(0x26, 0x80); //RegOut26[7:0] INIT
	SPI_0_write_reg(0x27, 0x00); //RegOut27[7:0] INIT
	SPI_0_write_reg(0x28, 0x00); //RegOut28[7:0] INIT
	SPI_0_write_reg(0x29, 0x00); //RegOut29[7:0] INIT
	SPI_0_write_reg(0x2a, 0x00); //RegOut2a[7:0] INIT
	SPI_0_write_reg(0x2b, 0x00); //RegOut2b[7:0] INIT
}

void eeprom_update_byte_from_SPI_0_read_reg(uint8_t addr)
{
	uint8_t readData;
	SPI_0_read_reg(addr, &readData);
	eeprom_update_byte(BASE_ADDR+addr,readData);
}

void B0_SaveData()
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

void Zing400Rx_SaveData()
{
	eeprom_update_byte_from_SPI_0_read_reg(0x02);
	eeprom_update_byte_from_SPI_0_read_reg(0x11);
	eeprom_update_byte_from_SPI_0_read_reg(0x14);
	eeprom_update_byte_from_SPI_0_read_reg(0x15);
	eeprom_update_byte_from_SPI_0_read_reg(0x16);
	eeprom_update_byte_from_SPI_0_read_reg(0x17);
	eeprom_update_byte_from_SPI_0_read_reg(0x18);

	eeprom_update_byte_from_SPI_0_read_reg(0x26);
	eeprom_update_byte_from_SPI_0_read_reg(0x27);
	eeprom_update_byte_from_SPI_0_read_reg(0x28);
	eeprom_update_byte_from_SPI_0_read_reg(0x29);
	eeprom_update_byte_from_SPI_0_read_reg(0x2a);
	eeprom_update_byte_from_SPI_0_read_reg(0x2b);
	eeprom_update_byte_from_SPI_0_read_reg(0x2c);
}

void Zing400Tx_SaveData()
{
	eeprom_update_byte_from_SPI_0_read_reg(0x07);
	eeprom_update_byte_from_SPI_0_read_reg(0x06);
	eeprom_update_byte_from_SPI_0_read_reg(0x05);
	eeprom_update_byte_from_SPI_0_read_reg(0x0d);
	eeprom_update_byte_from_SPI_0_read_reg(0x0c);
	eeprom_update_byte_from_SPI_0_read_reg(0x0b);
	
	eeprom_update_byte_from_SPI_0_read_reg(0x24);
	eeprom_update_byte_from_SPI_0_read_reg(0x25);
	eeprom_update_byte_from_SPI_0_read_reg(0x26);
	eeprom_update_byte_from_SPI_0_read_reg(0x27);
	eeprom_update_byte_from_SPI_0_read_reg(0x28);
	eeprom_update_byte_from_SPI_0_read_reg(0x29);
	eeprom_update_byte_from_SPI_0_read_reg(0x2a);
	eeprom_update_byte_from_SPI_0_read_reg(0x2b);
}

void SaveData(uint8_t n)
{
	switch(n){
	case 1:
		B0_SaveData();
		break;
	case 2:
		Zing400Rx_SaveData();
		break;
	case 3:
		Zing400Tx_SaveData();
		break;
	default:
		break;
	}
}

void SPI_0_write_reg_from_eeprom_read_byte(uint8_t addr)
{
	uint8_t readData = eeprom_read_byte(BASE_ADDR+addr);
	SPI_0_write_reg(addr, readData);
}

void B0_LoadData()
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

void Zing400Rx_LoadData()
{
	SPI_0_write_reg_from_eeprom_read_byte(0x02);
	SPI_0_write_reg_from_eeprom_read_byte(0x11);
	SPI_0_write_reg_from_eeprom_read_byte(0x14);
	SPI_0_write_reg_from_eeprom_read_byte(0x15);
	SPI_0_write_reg_from_eeprom_read_byte(0x16);
	SPI_0_write_reg_from_eeprom_read_byte(0x17);
	SPI_0_write_reg_from_eeprom_read_byte(0x18);

	SPI_0_write_reg_from_eeprom_read_byte(0x26);
	SPI_0_write_reg_from_eeprom_read_byte(0x27);
	SPI_0_write_reg_from_eeprom_read_byte(0x28);
	SPI_0_write_reg_from_eeprom_read_byte(0x29);
	SPI_0_write_reg_from_eeprom_read_byte(0x2a);
	SPI_0_write_reg_from_eeprom_read_byte(0x2b);
	SPI_0_write_reg_from_eeprom_read_byte(0x2c);	
}

void Zing400Tx_LoadData()
{
	SPI_0_write_reg_from_eeprom_read_byte(0x07);
	SPI_0_write_reg_from_eeprom_read_byte(0x06);
	SPI_0_write_reg_from_eeprom_read_byte(0x05);
	SPI_0_write_reg_from_eeprom_read_byte(0x0d);
	SPI_0_write_reg_from_eeprom_read_byte(0x0c);
	SPI_0_write_reg_from_eeprom_read_byte(0x0b);
	
	SPI_0_write_reg_from_eeprom_read_byte(0x24);
	SPI_0_write_reg_from_eeprom_read_byte(0x25);
	SPI_0_write_reg_from_eeprom_read_byte(0x26);
	SPI_0_write_reg_from_eeprom_read_byte(0x27);
	SPI_0_write_reg_from_eeprom_read_byte(0x28);
	SPI_0_write_reg_from_eeprom_read_byte(0x29);
	SPI_0_write_reg_from_eeprom_read_byte(0x2a);
	SPI_0_write_reg_from_eeprom_read_byte(0x2b);
}

void LoadData(uint8_t n)
{
	switch(n){
	case 1:
		B0_LoadData();
		break;
	case 2:
		Zing400Rx_LoadData();
		break;
	case 3:
		Zing400Tx_LoadData();
		break;
	default:
		break;
	}
}

void Init(uint8_t n)
{	
	switch(n){
	case 1:
		B0_Init();
		UART_TX_STR("B0_Init");
		break;
	case 2:
		Zing400Rx_Init();
		UART_TX_STR("Zing400Rx_Init");
		break;
	case 3:
		Zing400Tx_Init();
		UART_TX_STR("Zing400Tx_Init");
		break;
	default:
		UART_TX_STR("Init Error");
		break;
	}
	UART_TX_CH(0x0A);
	UART_TX_CH(0x0D);
}

uint8_t choose()
{
	char buffer[4] = {0, };
	UART_RX_STR(buffer);
	return (uint8_t)(strtol(buffer, NULL, 16));
}

void SendChipName(uint8_t n)
{
	switch(n){
	case 1:
		UART_TX_STR("CHIP:B0");		//Chip model name	(MUST BE 7Bytes long)
		break;
	case 2:
		UART_TX_STR("CHIP:BR");		//Chip model name	(MUST BE 7Bytes long)
		break;
	case 3:
		UART_TX_STR("CHIP:BT");		//Chip model name	(MUST BE 7Bytes long)
		break;
	default:
		break;
	}
}

int main(void)
{
	uint8_t rw = 0;
	uint8_t data[2] = {0, };
	char t_tx[3] = {0, };
	uint8_t chip = 0;
		
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();	
	
Init:
	chip = choose();
	Init(chip);
	
	/* Replace with your application code */
	
	LoadData(chip);
	while (1) {
		char t_rx_addr[4] = {0, };
		char t_rx_data[4] = {0, };

		UART_RX_STR(t_rx_addr);		//Get Address
		data[0] = (uint8_t)(strtol(t_rx_addr, NULL, 16));
		
		rw = UART_RX_CH();	//Write or Read? "Write : 0, Read : 1"
		
		if(data[0] == 0xff) {
			/* Get Chip model name */
			SendChipName(chip);
			continue;
		}else if(data[0] == 0xf1) {
			/* Save to EEPROM */
			UART_RX_STR(t_rx_data);	//Data(hex), dummy data to be neglected
			SaveData(chip);
			continue;			
		}else if(data[0] == 0xf2) {
			/* Load from EEPROM */
			UART_RX_STR(t_rx_data);	//Data(hex), dummy data to be neglected
			LoadData(chip);
			continue;			
		}else if(data[0] == 0xf3) {
			/* Get FW Version */
			UART_TX_STR(VERSION);	//FW Version
			continue;
		}else if(data[0] == 0xf4) {
			chip = 0;
			goto Init;
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
