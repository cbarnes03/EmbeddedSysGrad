void SysTick Handler(void){
	PORTA = PORTA^0x01
}

void main(void){
	unsigned long n;
		while(1){
			n = PORTB;
			n = (n/4)+12;
			PORTD = n;
		}
	}
