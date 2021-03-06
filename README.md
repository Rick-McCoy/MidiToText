# MiditoText

Using Midicsv, This program converts MID files to TXT. Made for Karpathy's [char-rnn](https://github.com/karpathy/char-rnn) training set generation. Only works for the 88 keys in standard pianos. ABANDONED.

## Motivation

Largely based on [this](https://www.youtube.com/watch?v=SacogDL_4JU&t=634s) video.

## Installation

No installation needed. Download John Walker's [Midicsv](https://fourmilab.ch/webtools/midicsv/).

## Reference

For Midicsv instructions, visit John Walker's [site](https://fourmilab.ch/webtools/midicsv/). This description will use terms explained on detail on that site. All of my programs are only made with basic C++ knowledge. Visit Karpathy's [char-rnn](https://github.com/karpathy/char-rnn) for the wonderful LSTM he made.

## Tests

All of this presumes everything's in D drive.

Let's say you have an input.MID file. We want to process this to input.txt. Open Command and type:
```
D:\Midicsv.exe D:\Input.MID D:\1.csv
```
Then compile CSVtoTXT.cpp and you'll find input.txt in D:\input.txt.

If you want to create a large dataset from many MID files, do the following.

Let's say you have 1000 Midi files, 1.MID to 1000.MID. Open Command and type:
```
for /L %i in (1, 1, 1000) do D:\Midicsv.exe D:\%i.MID D:\%i.csv
```
Then open CSVtoTXT.cpp and change line 5:
```
for(int x = 1; x<=1;x++)
```
to
```
for(int x = 1;x<=1000;x++)
```
Then compile CSVtoTXT.cpp and you'll find input.txt in the D drive.

The seperate Midi files will be included in the input.txt in the following format:

```
1

/* Here comes a bunch of ascii characters */


2

/* Here too  */

```
They will be labeled by their names and will be seperated by 2 new lines.

If you want to convert your LSTM's output to MID files, do the following:

Put output in Input.txt and compile Parse.txt to get Multiple Input-(Number).txt files.

Then change line 5 in TXTtoCSV.cpp from
```
for(int x = 1;x<=1;x++)
```
to
```
for(int x=1;x<=(Your input numbers);x++)
```
then compile TXTtoCSV.cpp to get multiple Output-(Number).txt files.

Finally open command and type
```
for /L %i in (1, 1, (Your input numbers)) do D:\Csvmidi.exe D:\Output-00%i.csv D:\Output-00%i.MID
```
(If you have less than 10 outputs to convert. If you have more, you can figure it out.)

## Format

A piano has 88 keys. This program converts those 88 keys into 88 ascii characters, from !(33) to x(120). The time field is split into 8ths of the division specified in the [Midicsv file format documentation](http://www.fourmilab.ch/webtools/midicsv/). Notes that are played simultaneously during the basic duration is printed next to each other. Notes are seperated by spaces. Any duration that does not play a note does not print anything, therefore two or more spaces are printed each after another.

For example, Middle C is the 40th key, therefore corresponding to H(72) in ascii. If this key is played for 4 durations, then it is written as
```
H H H H
```
If Middle C, E and G is played simultaneously for 4 durations, then it's written as
```
HJL HJL HJL HJL
```
If Middle C, E and G is played simultaneously for 4 durations, and only the G continues for 4 durations:
```
HJL HJL HJL HJL L L L L
```

## Acknowledgements

* Everyone that will (hopefully) help
* Karpathy for creating his wonderful RNN
* John Walker for creating MidiToCSV. Seriously, what I did was minimal.

## Todos
* Unfortunately, this loses a lot of information. For example, notes get sqaushed into 8ths of the division, and notes that turn off and turns right back on at the same time is considered a continued note.  Currently working on [Mascii](http://mascii.org/) converter. This will hopefully solve most problems.
* Most importantly, char-rnn does not like this. It's too unstructured for the LSTM to follow, and the error did not go below 0.54 during 500 iterations on a 10MB dataset. I tried the raw output from MiditoCSV, but it's too structured for the LSTM to produce a MID-convertible CSV file. As I said, Mascii will hopefully solve this.

## Comments

A novice coder will produce a better program in 10 minutes. This hopefully will not have any bugs.

NOTE: After discovering [ABC Notation](http://abcnotation.com/), I concluded that this is far more useful than Mascii. There is a MidiToABC tool out there in the internet. THEREFORE THIS PROJECT IS CLOSED.

Contact: rickmccoy3141@gmail.com

## License

[MIT](https://opensource.org/licenses/MIT)
