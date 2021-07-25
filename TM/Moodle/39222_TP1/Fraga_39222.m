% 1
[y, Fs] = audioread('Audio/39222.wav');

% 2
name = y(0 * Fs + 1: 3 * Fs);
number = y(3 * Fs + 1: 5 * Fs);

% 3
reverse = [number; name];

% 4
backwards = name(3 * Fs : -1 : 0 * Fs + 1);

% 5
[music, FsM] = audioread('Audio/guitar.wav');
clip = music(0 * FsM + 1 : 10 * FsM);

ramp = 1/(FsM * 10):1/(FsM * 10):1;
ramp = ramp';

padding = 441000 - length(name);
padding = zeros(padding,1);

name = [name; padding];

clip = clip;
clip = clip .* ramp;

mix = clip + name;

% 6
M = length(name);
t = (0:M-1)/Fs;
subplot(3,1,1), plot(t, name);
ind = 4800:6400;
subplot(3,1,2), plot(t(ind), name(ind));
ind = find(t>0.68 & t<0.72);
subplot(3,1,3), plot(t(ind), name(ind));

% Pitch
pitch = 1/0.006;
