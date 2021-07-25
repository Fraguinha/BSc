% 1
[y1, Fs1] = audioread("Audios/bass.wav");
[y2, Fs2] = audioread("Audios/guitar.wav");
[y3, Fs3] = audioread("Audios/drums.wav");

% 2
Fs1
Fs2
Fs3

% 3
length(y1)/Fs1
length(y2)/Fs2
length(y3)/Fs3

% 4
drum12 = y3(11 * Fs3 + 1: 12 * Fs3);

% 5
repeat = [drum12; drum12; drum12; drum12];

% 6
bass_seg = y1(10 * Fs1 + 1: 20 * Fs1);
guitar_seg = y2(10 * Fs2 + 1: 20 * Fs2);
drum_seg = y3(10 * Fs3 + 1: 20 * Fs3);

% 7
% plot(bass_seg)
% plot(guitar_seg)
% plot(drum_seg)

% 8
% sound(bass_seg, Fs1)
% sound(guitar_seg, Fs2)
% sound(drum_seg, Fs3)

% 9
% sound(bass_seg, Fs1 * 2)
% sound(guitar_seg, Fs2 * 2)
% sound(drum_seg, Fs3 * 2)

% 10
% sound(drum_seg + guitar_seg, (Fs1 + Fs2) / 2)

% 11
% sound(bass_seg + guitar_seg + drum_seg, (Fs1 + Fs2 + Fs3) / 3)

% 12
% sound(bass_seg * 3, Fs1)

% 13
% sound(guitar_seg * 0.15, Fs2)

% 14
% sound(bass_seg * 3 + guitar_seg * 0.15 + drum_seg, (Fs1 + Fs2 + Fs3) / 3)

% 15
ramp = 1/(Fs3 * 10):1/(Fs3 * 10):1;
ramp1 = ramp';

new_drum = drum_seg .* ramp1;
sound(new_drum, Fs3)

% 16
ramp2 = ramp';
mat = [ramp1 ramp2];
stereo_drum = drum_seg .* mat;
sound(stereo_drum, Fs3)

% 17
% play with sound
