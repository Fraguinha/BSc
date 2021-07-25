close all, clear all, clc

pkg load image

I = imread('selfie.jpeg');
J = imread('cute.jpeg');

% 1

D = im2double(I);

r = D(:,:,1);
g = D(:,:,2);
b = D(:,:,3);

c = 1 - r;
m = 1 - g;
y = 1 - b;

CMY(:,:,1) = c;
CMY(:,:,2) = m;
CMY(:,:,3) = y;

subplot(1, 2, 1), imshow(I);
subplot(1, 2, 2), imshow(CMY);

% 2

RBG(:,:,1) = r;
RBG(:,:,2) = b;
RBG(:,:,3) = g;

subplot(1, 2, 1), imshow(I);
subplot(1, 2, 2), imshow(RBG);

% 3

BW = rgb2gray(I);

subplot(1, 2, 1), imshow(I);
subplot(1, 2, 2), imshow(BW);

% 4

D = im2double(J);

r = D(:,:,1);
g = D(:,:,2);
b = D(:,:,3);

J1(:,:,1) = 2*r; J1(:,:,2) =   g; J1(:,:,3) =   b;
J2(:,:,1) = 2*r; J2(:,:,2) =   b; J2(:,:,3) =   g;
J3(:,:,1) =   g; J3(:,:,2) = 2*r; J3(:,:,3) =   b;
J4(:,:,1) =   g; J4(:,:,2) =   b; J4(:,:,3) = 2*r;
J5(:,:,1) =   b; J5(:,:,2) = 2*r; J5(:,:,3) =   g;
J6(:,:,1) =   b; J6(:,:,2) =   g; J6(:,:,3) = 2*r;

 J7(:,:,1) =   r;  J7(:,:,2) = 2*g;  J7(:,:,3) =   b;
 J8(:,:,1) =   r;  J8(:,:,2) =   b;  J8(:,:,3) = 2*g;
 J9(:,:,1) = 2*g;  J9(:,:,2) =   r;  J9(:,:,3) =   b;
J10(:,:,1) = 2*g; J10(:,:,2) =   b; J10(:,:,3) =   r;
J11(:,:,1) =   b; J11(:,:,2) =   r; J11(:,:,3) = 2*g;
J12(:,:,1) =   b; J12(:,:,2) = 2*g; J12(:,:,3) =   r;

J13(:,:,1) =   r; J13(:,:,2) =   g; J13(:,:,3) = 2*b;
J14(:,:,1) =   r; J14(:,:,2) = 2*b; J14(:,:,3) =   g;
J15(:,:,1) =   g; J15(:,:,2) =   r; J15(:,:,3) = 2*b;
J16(:,:,1) =   g; J16(:,:,2) = 2*b; J16(:,:,3) =   r;
J17(:,:,1) = 2*b; J17(:,:,2) =   r; J17(:,:,3) =   g;
J18(:,:,1) = 2*b; J18(:,:,2) =   g; J18(:,:,3) =   r;

subplot(3,6,1),  imshow(J1);
subplot(3,6,2),  imshow(J2);
subplot(3,6,3),  imshow(J3);
subplot(3,6,4),  imshow(J4);
subplot(3,6,5),  imshow(J5);
subplot(3,6,6),  imshow(J6);
subplot(3,6,7),  imshow(J7);
subplot(3,6,8),  imshow(J8);
subplot(3,6,9),  imshow(J9);
subplot(3,6,10), imshow(J10);
subplot(3,6,11), imshow(J11);
subplot(3,6,12), imshow(J12);
subplot(3,6,13), imshow(J13);
subplot(3,6,14), imshow(J14);
subplot(3,6,15), imshow(J15);
subplot(3,6,16), imshow(J16);
subplot(3,6,17), imshow(J17);
subplot(3,6,18), imshow(J18);

% 5

SMALL = imresize(J, 0.1);
LOGO = I;

LOGO(1:size(SMALL)(1), size(LOGO)(2)-size(SMALL)(2)+1:end, :) = SMALL;
subplot(1, 1, 1), imshow(LOGO);


% 6

MEDIUM1 = imresize(J, 0.4);
MEDIUM2 = imcrop(I, [0, 0, size(MEDIUM1)(2), size(MEDIUM1)(1)]);

BACKGROUND = 0.2 .* MEDIUM1 .+ MEDIUM2;

imshow(BACKGROUND);

% 7 % Não funciona no octave, mas experimentei no matlab online e funcionava

[X1, map1] = rgb2ind(J, 256);
[X2, map2] = rgb2ind(J, 128);
[X3, map3] = rgb2ind(J, 64);
[X4, map4] = rgb2ind(J, 32);
[X5, map5] = rgb2ind(J, 16);
[X6, map6] = rgb2ind(J, 8);


ax1 = subplot(2, 3, 1), imagesc(X1), colormap(ax1, map1);
ax2 = subplot(2, 3, 2), imagesc(X2), colormap(ax2, map2);
ax3 = subplot(2, 3, 3), imagesc(X3), colormap(ax3, map3);
ax4 = subplot(2, 3, 4), imagesc(X4), colormap(ax4, map4);
ax5 = subplot(2, 3, 5), imagesc(X5), colormap(ax5, map5);
ax6 = subplot(2, 3, 6), imagesc(X6), colormap(ax6, map6);
