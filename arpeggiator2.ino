/* 
  Sequencing chords using arpeggio for a piezo buzzer.
  by Ferrie Bank - Amsterdam, 22 June 2020
*/

#include "pitches.h"
#include "chords.h"

const int whole_note_millis = 1000;
const int score_element_resolution = 16; // each element in the score array represents a 1/4 (= 1/resolution value) note duration.
const int score_note_millis = (whole_note_millis / score_element_resolution);

const int BUZZER_PIN = 11;

const char score[] = {

    'D', 'D', 'R', 'R',
    'D', 'D', 'R', 'R',
    'C', 'C', 'R', 'R',
    'D', 'D', 'D', 'D',
    'R', 'R', 'R', 'R',
    'A', 'A', 'A', 'A',
    'R', 'R', 'R', 'R',
    'H', 'H', 'H', 'H',
    'R', 'R', 'R', 'R',
    'G', 'G', 'G', 'G',
    'R', 'R', 'R', 'R',
    'D', 'D', 'D', 'D',
    'F', 'F', 'F', 'F',
    'F', 'F', 'F', 'R',
    'D', 'D', 'D', 'D'
  };


void setup() {

  uint16_t currentFreqs[chord_length];
  
  for (int scoreIndex = 0; scoreIndex < sizeof(score); scoreIndex++) {

    char currentNote = score[scoreIndex];
    fetchFrequencies(currentNote, currentFreqs);
    
    int toneDuration = (score_note_millis / chord_length);

    for (int i = 0; i < chord_length; i++) {
      
      if (currentFreqs[i] > 0) tone(BUZZER_PIN, currentFreqs[i]);
      delay(toneDuration); // wait playing the next tone, until the current tone is done playing :-)
      noTone(BUZZER_PIN);
    }
  }
}

void fetchFrequencies(char scoreElement, uint16_t target[]) {

   int dataLength = chord_length * 2;
    
    switch (scoreElement) {
      
      case 'A':
        memcpy(target, CHORD_A5, dataLength);
        break;
        
      case 'C':
        memcpy(target, CHORD_C5, dataLength);
        break;
        
      case 'D':
        memcpy(target, CHORD_D5, dataLength);
        break;
        
      case 'F':
        memcpy(target, CHORD_F5, dataLength);
        break;
        
      case 'G':
        memcpy(target, CHORD_G5, dataLength);
        break;

      case 'H':
        memcpy(target, CHORD_GS5, dataLength);
        break;

      case 'R':
        memcpy(target, CHORD_REST, dataLength);
        break;
    }
}

void loop() {
}
