/* 
  Sequencing chords using arpeggio for a piezo buzzer.
  by Ferrie Bank - Amsterdam, 22 June 2020
*/

#include "chords.h"

const int whole_note_millis = 1000;
const int score_element_resolution = 16; // each element in the score array represents a 1/16 (= 1/resolution value) note duration.
const int score_note_millis = (whole_note_millis / score_element_resolution);

const int BUZZER_PIN = 11;

const byte score[] = {

    D, D, R, R,
    D, D, R, R,
    C, C, R, R,
    D, D, D, D,
    R, R, R, R,
    A, A, A, A,
    R, R, R, R,
    GS, GS, GS, GS,
    R, R, R, R,
    G, G, G, G,
    R, R, R, R,
    D, D, D, D,
    F, F, F, F,
    F, F, F, R,
    D, D, D, D
};

const byte another[] = {

   C, CS, D, DS, E, F, FS, G, GS, A, AS, B, AS, A, GS, G, FS, F, E, DS, D, CS, C
};


void setup() {

  play (score, sizeof(score), score_note_millis, BUZZER_PIN);
  delay (1000);
  play (another, sizeof(another), score_note_millis, BUZZER_PIN);
}

void loop() {
}
