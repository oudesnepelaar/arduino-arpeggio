#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976

const int chord_length = 4;

const uint16_t CHORD_REST[] PROGMEM = {0, 0, 0, 0};

const uint16_t CHORD_C[] PROGMEM = {NOTE_C5, NOTE_E4, NOTE_G4, NOTE_C6};
const uint16_t CHORD_CS[] PROGMEM = {NOTE_CS5, NOTE_F4, NOTE_GS4, NOTE_CS6};
const uint16_t CHORD_D[] PROGMEM = {NOTE_D5, NOTE_FS4, NOTE_A4, NOTE_D6};
const uint16_t CHORD_DS[] PROGMEM = {NOTE_DS5, NOTE_F4, NOTE_AS4, NOTE_DS6};
const uint16_t CHORD_E[] PROGMEM = {NOTE_E5, NOTE_GS4, NOTE_B4, NOTE_E6};
const uint16_t CHORD_F[] PROGMEM = {NOTE_F5, NOTE_A4, NOTE_C4, NOTE_F6};
const uint16_t CHORD_FS[] PROGMEM = {NOTE_FS5, NOTE_C4, NOTE_DS4, NOTE_FS6};
const uint16_t CHORD_G[] PROGMEM = {NOTE_G5, NOTE_B4, NOTE_D4, NOTE_G6};
const uint16_t CHORD_GS[] PROGMEM = {NOTE_GS5, NOTE_C4, NOTE_DS4, NOTE_GS6};
const uint16_t CHORD_A[] PROGMEM = {NOTE_A5, NOTE_CS4, NOTE_E4, NOTE_A6};
const uint16_t CHORD_AS[] PROGMEM = {NOTE_AS5, NOTE_D4, NOTE_F4, NOTE_AS6};
const uint16_t CHORD_B[] PROGMEM = {NOTE_B5, NOTE_DS4, NOTE_FS4, NOTE_B6};

const uint16_t CHORDS[13] PROGMEM = {CHORD_REST, CHORD_C, CHORD_CS, CHORD_D, CHORD_DS, CHORD_E, CHORD_F, CHORD_FS, CHORD_G, CHORD_GS, CHORD_A, CHORD_AS, CHORD_B};

#define R 0
#define C 1
#define CS 2
#define D 3
#define DS 4
#define E 5
#define F 6
#define FS 7
#define G 8
#define GS 9
#define A 10
#define AS 11
#define B 12

void fetchFrequencies (byte scoreElement, uint16_t target[]) {

   int dataLength = chord_length * 2;

   uint16_t address = pgm_read_word(CHORDS + scoreElement);
   memcpy_P(target, address, dataLength);
}

void play (byte score[], int scoreSize, int score_note_millis, int buzzerPin) {

  uint16_t currentFreqs[chord_length];
  
  for (int scoreIndex = 0; scoreIndex < scoreSize; scoreIndex++) {

    byte currentNote = score[scoreIndex];
    fetchFrequencies(currentNote, currentFreqs);
    
    int toneDuration = (score_note_millis / chord_length);

    for (int i = 0; i < chord_length; i++) {
      
      if (currentFreqs[i] > 0) tone (buzzerPin, currentFreqs[i]);
      delay (toneDuration); // wait playing the next tone, until the current tone is done playing :-)
      noTone (buzzerPin);
    }
  }
}
