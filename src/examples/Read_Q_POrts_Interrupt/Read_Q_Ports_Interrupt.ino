const int STQ = 3;   
const int Q4 = A0;
const int Q3 = A1;
const int Q2 = A2;
const int Q1 = A3;

volatile 	byte DTMFread = 128;

readQPorts(){
	DTMFread=0;
	if(digitalRead(Q1)==HIGH){      //If Q1 reads HIGH, then add 1 to the DTMFread variable
	  DTMFread=DTMFread+1;
	}
	if(digitalRead(Q2)==HIGH){      //If Q2 reads HIGH, then add 2 to the DTMFread variable
		DTMFread=DTMFread+2;
	}
	if(digitalRead(Q3)==HIGH){      //If Q3 reads HIGH, then add 4 to the DTMFread variable
		DTMFread=DTMFread+4;
	}
	if(digitalRead(Q4)==HIGH){      //If Q4 reads HIGH, then add 8 to the DTMFread variable
		DTMFread=DTMFread+8;
	}
	
}

void setup() {
	pinMode(STQ, INPUT_PULLUP);
	pinMode(Q4, INPUT_PULLUP);
	pinMode(Q3, INPUT_PULLUP);
	pinMode(Q2, INPUT_PULLUP);
	pinMode(Q1, INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(STQ), readQPorts, RISING);
}

void loop(){
	if (DTMFread < 17){
		Serial.print(DTMFread);
		DTMFread = 17;
	}
}