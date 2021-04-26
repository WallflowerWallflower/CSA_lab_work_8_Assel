/*
 * csa_lab_work_8_Assel.c
 *
 * Created: 26.04.2021 11:08:57
 * Author : lenovo
 */ 

#include <avr/io.h>
#include <util/delay.h>
void lcd_init_first_pin(int reg_num) {
	PORTB = 0x02;
	_delay_ms(100);
	PORTA = reg_num;
	PORTB = 0x00;
	_delay_ms(100);
}


void lcd_display_first_str(char *string, int line) {
	lcd_init_first_pin(0x38);
	lcd_init_first_pin(0x0E);
	
	if(line == 1)
	lcd_init_first_pin(0x80);
	
	if(line == 2)
	lcd_init_first_pin(0xC0);
	
	for(int i = 0; string[i] != '\0'; i++) {
		lcs_display_first_char(string[i]);
	}
}


void lcs_display_first_char(char *character) {
	PORTB = 0x03;
	PORTA = character;
	_delay_ms(50);
	PORTB = 0x01;
}




void lcd_init_second_pin(int reg_num) {
	PORTE = 0x02;
	_delay_ms(100);
	PORTD = reg_num;
	PORTE = 0x00;
	_delay_ms(100);
}

void lcd_display_second_str(char *string, int line) {
	lcd_init_second_pin(0x38);//0x38
	lcd_init_second_pin(0x0E);
	
	if(line == 1)
	lcd_init_second_pin(0x80);
	
	if(line == 2)
	lcd_init_second_pin(0xC0);
	
	if(line == 3)
	lcd_init_second_pin(0x90);
	
	if(line == 4)
	lcd_init_second_pin(0xD0);
	
	for(int i = 0; string[i] != '\0'; i++) {
		lcs_display_second_char(string[i]);
	}
}

void lcs_display_second_char(char *character) {
	PORTE = 0x03;
	PORTD = character;
	_delay_ms(50);
	PORTE = 0x01;
}

int main(void)
{
	
	DDRA = 0b11111111;
	DDRB = 0b11111111;
	
	lcd_display_first_str("Assel", 1);
	lcd_display_first_str("Mussamatdin", 2);
	
	DDRD = 0b11111111;
	DDRE = 0b11111111;
	
	lcd_display_second_str("Assel", 1);
	lcd_display_second_str("Mussamatdin", 2);
	lcd_display_second_str("Amangeldikyzy", 3);
	lcd_display_second_str("IS-1808K", 4);
}

