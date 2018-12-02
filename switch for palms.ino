int microfone = 4; 
int led = 8;

int contPalmas = 0; 
int palmasRequeridaLigaLed = 3; 
int palmasRequeridaDesligaLed = 2; 


unsigned long tempMaxSom = 1000;
unsigned long tempMinSom = 300;
unsigned long compriSonoro = 100; 
unsigned long time;
unsigned long startTime = 0;

void setup() {
  pinMode(microfone, INPUT); 
  pinMode(led, OUTPUT); 
  digitalWrite(led, HIGH);
}

void loop() {
   time = millis();
   unsigned long tempoAposPalma = time - startTime;
  
  if (tempoAposPalma >= compriSonoro && digitalRead(microfone) == LOW) {
  
    if (tempoAposPalma < tempMinSom || tempoAposPalma > tempMaxSom) {
      contPalmas = 0;
      startTime = millis();
    } else {
      contPalmas ++;
      startTime = millis();
      }
   
    if((contPalmas>=palmasRequeridaLigaLed-1)&&(digitalRead(led)==HIGH)){
    
      digitalWrite(led, LOW);
      contPalmas = 0;
    }
  
  
    if((contPalmas>=palmasRequeridaDesligaLed-1)&&(digitalRead(led)==LOW)){
      digitalWrite(led, HIGH);
      contPalmas = 0;
    }
  }
}
