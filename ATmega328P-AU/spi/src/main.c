#include <atmel_start.h>
#include <string.h>

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

void Zing500Rx_Init(void)
{
}

void Zing500Tx_Init(void)
{
}

void reg_show(char *name,uint8_t addr)
{
	uint8_t rx_data = 0;
	char t_tx[3] = {0, };
	
	UART_TX_STR(name);
	SPI_0_read_reg(addr, &rx_data);
	hextostr((rx_data), t_tx);
	UART_TX_STR(t_tx);
	UART_TX_CH(0x0a);
}

void B0_reg_show(void)
{
	reg_show("RX_REG1[4:0] : ",0x02);
	reg_show("TX_REG1[23:16] : ",0x07);
	reg_show("TX_REG1[15:8] : ",0x06);
	reg_show("TX_REG1[7:0] : ",0x05);
	reg_show("TX_REG2[16] : ",0x0d);
	reg_show("TX_REG2[15:8] : ",0x0c);
	reg_show("TX_REG2[7:0] : ",0x0b);
	
	reg_show("BIAS_REG1[0] : ",0x11);
	reg_show("BIAS_REG2[7:0] : ",0x12);
	reg_show("BIAS_REG3[7:0] : ",0x13);
	reg_show("BIAS_REG4[7:0] : ",0x14);
	reg_show("BIAS_REG5[7:0] : ",0x15);
	reg_show("BIAS_REG6[7:0] : ",0x16);
	reg_show("BIAS_REG7[7:0] : ",0x17);
	reg_show("BIAS_REG8[7:0] : ",0x18);
}

void Zing400Rx_reg_show(void)
{
	reg_show("RX_REG1[4:3] : ",0x02);
	reg_show("BIAS_REG1[0] : ",0x11);
	reg_show("BIAS_REG4[7:0] : ",0x14);
	reg_show("BIAS_REG5[7:0] : ",0x15);
	reg_show("BIAS_REG6[7:0] : ",0x16);
	reg_show("BIAS_REG7[7:0] : ",0x17);
	reg_show("BIAS_REG8[7:0] : ",0x18);

	reg_show("RegOut26[3:0] : ",0x26);
	reg_show("RegOut27[7:0] : ",0x27);
	reg_show("RegOut28[7:0] : ",0x28);
	reg_show("RegOut29[7:0] : ",0x29);
	reg_show("RegOut2a[7:0] : ",0x2a);
	reg_show("RegOut2b[7:0] : ",0x2b);
	reg_show("RegOut2c[7:0] : ",0x2c);
}

void Zing400Tx_reg_show(void)
{
	reg_show("TX_REG1[23:16] : ",0x07);
	reg_show("TX_REG1[15:8] : ",0x06);
	reg_show("TX_REG1[7:0] : ",0x05);
	reg_show("TX_REG2[16] : ",0x0d);
	reg_show("TX_REG2[15:13] : ",0x0c);
	reg_show("TX_REG2[3:0] : ",0x0b);

	reg_show("RegOut24[0] : ",0x24);
	reg_show("RegOut25[7:0] : ",0x25);
	reg_show("RegOut26[7:0] : ",0x26);
	reg_show("RegOut27[7:0] : ",0x27);
	reg_show("RegOut28[7:0] : ",0x28);
	reg_show("RegOut29[7:0] : ",0x29);
	reg_show("RegOut2a[7:0] : ",0x2a);
	reg_show("RegOut2b[7:0] : ",0x2b);
}

void Zing500Rx_reg_show(void)
{
	reg_show("RX_REG1[7:0] : ",0x00);
	reg_show("BIAS_REG1[7:0] : ",0x10);
	reg_show("BIAS_REG2[7:0] : ",0x11);
	reg_show("BIAS_REG3[7:0] : ",0x12);
	reg_show("BIAS_REG4[7:0] : ",0x13);
	reg_show("BIAS_REG5[7:0] : ",0x14);
	reg_show("BIAS_REG6[7:0] : ",0x15);
	reg_show("BIAS_REG7[7:0] : ",0x16);
}

void Zing500Tx_reg_show(void)
{
}

void Init(uint8_t n)
{
	switch(n){
	case 1:
		B0_Init();
		break;
	case 2:
		Zing400Rx_Init();
		break;
	case 3:
		Zing400Tx_Init();
		break;
	case 4:
		Zing500Rx_Init();
		break;
	case 5:
		Zing500Tx_Init();
		break;
	default:
		break;
	}
}

void show(uint8_t n)
{
	switch(n){
	case 1:
		B0_reg_show();
		break;
	case 2:
		Zing400Rx_reg_show();
		break;
	case 3:
		Zing400Tx_reg_show();
		break;
	case 4:
		Zing500Rx_reg_show();
		break;
	case 5:
		Zing500Tx_reg_show();
		break;
	default:
		break;
	}
}

void show_chip(uint8_t n)
{
	switch(n){
	case 1:
		UART_TX_STR("[Zing200x] ");
		break;
	case 2:
		UART_TX_STR("[Zing400R] ");
		break;
	case 3:
		UART_TX_STR("[Zing400T] ");
		break;
	case 4:
		UART_TX_STR("[Zing500R] ");
		break;
	case 5:
		UART_TX_STR("[Zing500T] ");
		break;
	default:
		break;
	}
}

uint8_t choose()
{
	char buffer[4] = {0, };
	
	while(1) {
		UART_TX_STR("Choose chipset model number to use, Zing200x(1), Zing400R(2) Zing400T(3) Zing500R(4) Zing500T(5) : ");
		UART_RX_STR(buffer);
		UART_TX_STR(buffer);
		UART_TX_CH(0x0A);
		UART_TX_CH(0x0D);
	
		uint8_t number = (uint8_t)(strtol(buffer, NULL, 10));
		if(number>=1 && number<=5) {
			show_chip(number);
			UART_TX_STR("selected\n");
			return number;
		}else{
			UART_TX_STR("Wrong number selected\n");
		}
		UART_TX_CH(0x0A);
		UART_TX_CH(0x0D);
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
	
	chip = choose();
	Init(chip);
	
	/* Replace with your application code */
	while (1) {
	  char t_rx_addr[4] = {0, };
	  char t_rx_data[4] = {0, };
	  show_chip(chip);
	  UART_TX_STR("If the input address is greater than 0x80, all register values are displayed\n");
	  UART_TX_STR("Please Input Address(hex) : ");
	  UART_RX_STR(t_rx_addr);
	  UART_TX_CH(0x0A);
	  data[0] = (uint8_t)(strtol(t_rx_addr, NULL, 16));
	  UART_TX_CH(0x0a);
	  UART_TX_STR("Input Address(hex) : ");
	  UART_TX_STR(t_rx_addr);
	  UART_TX_CH(0x0a);
	  if(data[0] > 0x7f)
	  {
		  show(chip);
		  continue;
	  }
	  UART_TX_STR("Write : 0, Read : 1");
	  UART_TX_CH(0x0A);
	  rw = UART_RX_CH();
 	  rw = rw & 1;
		if(!rw)
		{
			UART_TX_STR("Write\n");
			UART_TX_STR("Please Input Data(hex) : ");
			UART_TX_CH(0x0A);
			UART_RX_STR(t_rx_data);
			UART_TX_CH(0x0A);
			UART_TX_STR("Input Data(hex) : ");
			UART_TX_STR(t_rx_data);
			UART_TX_CH(0x0A);
		    data[1] = (uint8_t)(strtol(t_rx_data, NULL, 16));						
			SPI_0_write_reg(data[0], data[1]);			
		}		
		else
		{
			UART_TX_STR("Read\n");
			SPI_0_read_reg(data[0], &data[1]);
			UART_TX_STR("Output Data(hex) : ");
			hextostr(data[1], t_tx);
			UART_TX_STR(t_tx);
			UART_TX_CH(0x0a);		
		}
	}
}
