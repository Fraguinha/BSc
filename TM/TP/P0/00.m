% 1
num = 39222

% 2
numalt = num

% 3
numalt += 5

% 4
whos num

% 5
num = int32(num)

% 6
whos num

% 7
vcol = [1:10]'

% 8
vcol(5)

% 9
vcol(7) = 100

% 10
vcol(2:2:end)

% 11
vcol(1:2:end)

% 12
vcolinv1 = [vcol(end:-1:1)]

% 13
vcolinv2 = [vcolinv1(2:7)]

% 14
vlin1 = vcol'

% 15
vlin2 = vlin1(end:-1:1)

% 16
vlin = [vlin1 vlin2]

% 17
size(vlin1)
size(vlin2)
size(vlin)

% 18
vlin100 = 1:100

% 19
vpar100 = 2:2:100

% 20
vimpar100 = 1:2:100

% 21
vlincem = zeros([1, 100])
vlincem(1:2:end) = vimpar100
vlincem(2:2:end) = vpar100
