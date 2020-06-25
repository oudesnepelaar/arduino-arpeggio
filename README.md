# arduino-arpeggio
Plays musical chords on an Arduino driven piezo buzzer by use of arpeggio

This file can be used to #include in an Arduino UNO/NANO .ino Sketch, and adds some
basic oscillation frequencies and chords as constants in PROGMEM.

It also uses #define to add musical note labels (C through B)
that can very easily be added into an Array to define a sequence of chords
to be played.

As this drives a passive piezo buzzer through PMW, the chords have to be
broken up into the constituent notes, which will be repeated in rapid
succession to simulate the playing of several notes at the same time.

This technique of playing broken chords is called Arpeggio.
The was commonly used in 8-bit computer games which often had single voice
sound channels available. Using the effect of playing music this way,
will immediately conjure memories of such 8-bit computer games.

The mapping of chords and frequencies is all stored in PROGMEM
(the Flash memory on the Arduino), which allows this library to be used
while hardly impacting the dynamic memory at all.

One can easily edit the chord and frequency definitions to extend the range
or to define different modes or chords progressions, which will very much
enrich the musical impression.

The goal of writing this, was to provide a simple starter file with a small footprint,
that allows to quickly and easily play cheerful tunes on the otherwise limited
piezo buzzers attached to an Arduino.

I've tried my best to create a proper Library from this header file,
but for some reason the code doesn't work anymore when I put it in a
class file. I've basically exhausted my patience figuring out how to make
it work after several days of reading up on C++ and watching YouTube tutorials.
The problem seems to be the way Arduino UNO PROGMEM space is addressed.

I welcome anyone who likes, to give it a shot, but honestly for practical use
this header file works fine for me. But, feel free to fork this repo and
go wild on a different version, using .cpp/.h files, exploring different
musical combos. The code is free to use as is, alter and redistribute.

The included .ino Sketch serves as an example of how it can be used.
Make sure to use a PWM enabled output to connect the buzzer to.


Ferrie J Bank,
Amsterdam 26 June 2020

https://github.com/oudesnepelaar/arduino-arpeggio