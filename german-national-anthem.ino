#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_FS4 370
#define NOTE_F5  698

const int audioPin = 9;
int tempo = 100; 

int melody[] = {
  // "Einigkeit und Recht und Freiheit..."
  NOTE_G4, 4,
  NOTE_A4, 8, NOTE_G4, 8, NOTE_FS4, 8, NOTE_G4, 8,
  NOTE_C5, 4, NOTE_B4, 4, NOTE_A4, 4, NOTE_G4, 4,
  NOTE_E5, 4, NOTE_D5, 4, NOTE_C5, 4, NOTE_B4, 4,
  NOTE_A4, 4, NOTE_G4, 4, NOTE_FS4, 4, NOTE_G4, 2,
  
  // "Für das deutsche Vaterland..."
  NOTE_G4, 4,
  NOTE_A4, 8, NOTE_G4, 8, NOTE_FS4, 8, NOTE_G4, 8,
  NOTE_C5, 4, NOTE_B4, 4, NOTE_A4, 4, NOTE_G4, 4,
  NOTE_E5, 4, NOTE_D5, 4, NOTE_C5, 4, NOTE_B4, 4,
  NOTE_A4, 4, NOTE_G4, 4, NOTE_FS4, 4, NOTE_G4, 2,

  // "Danach lasst uns alle streben..."
  NOTE_D5, 4,
  NOTE_D5, 4, NOTE_E5, 4, NOTE_F5, 4, NOTE_F5, 4,
  NOTE_E5, 4, NOTE_D5, 4, NOTE_E5, 2,
  NOTE_C5, 4, NOTE_C5, 4, NOTE_D5, 4, NOTE_E5, 4,
  NOTE_D5, 4, NOTE_C5, 4, NOTE_B4, 2,

  // "Blühe deutsches Vaterland!"
  NOTE_G4, 4,
  NOTE_A4, 8, NOTE_G4, 8, NOTE_FS4, 8, NOTE_G4, 8,
  NOTE_C5, 4, NOTE_B4, 4, NOTE_A4, 4, NOTE_G4, 4,
  NOTE_E5, 4, NOTE_D5, 4, NOTE_C5, 4, NOTE_B4, 4,
  NOTE_A4, 4, NOTE_B4, 4, NOTE_C5, 2
};

void playPianoNote(int frequency, int duration) {
  unsigned long start = millis();
  
  
  while (millis() - start < duration) {
    int elapsed = millis() - start;
   
    int pulseWidth = map(elapsed, 0, duration, 10, 1); 
    
    if (pulseWidth > 0) {
      tone(audioPin, frequency, pulseWidth);
    }
    
    
    delay(15); 
  }
  noTone(audioPin);
}

void setup() {
  pinMode(audioPin, OUTPUT);
  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  int wholenote = (60000 * 4) / tempo;

  for (int i = 0; i < notes; i++) {
    int noteDuration = wholenote / melody[i * 2 + 1];
    
    playPianoNote(melody[i * 2], noteDuration);
    
    delay(noteDuration * 0.1); 
  }
}

void loop() {}
//greatings to my music teacher :-D
