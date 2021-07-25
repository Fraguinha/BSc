% 1

x = 0:0.01:1;
figure(1);
filename = 'custom.gif';

for n = -1:0.05:1
  y = n .* x;    % Função que se pretende desenhar
  plot(x,y)
  axis([-1 1 -1 1])
  drawnow
  frame = getframe(1);  % guarda o plot como uma movie frame
  im = frame2im(frame);  % converte a frame para uma imagem
  [A,map] = rgb2ind(im, 256);  % converte a imagem para uma imagem indexada
  if n == -1;
    imwrite(A,map,filename,'gif','LoopCount',Inf,'DelayTime',0.1);   % na primeira execução, escreve a imagem no gif
  else
    imwrite(A,map,filename,'gif','WriteMode','append','DelayTime',0.1);  % nas outras execuções, da append da imagem ao gif
    if n == -1 + (5 * 0.05);
      imwrite(A,map,'5.gif','gif','LoopCount',Inf,'DelayTime',0.1);
      imwrite(im,'5.jpg','jpg');
      imwrite(im,'5.png','png');
    end
  end
end

for n = 1:-0.05:-1
  y = n .* x;
  plot(x,y)
  axis([-1 1 -1 1])
  drawnow
  frame = getframe(1);
  im = frame2im(frame);
  [A,map] = rgb2ind(im,256);
  imwrite(A,map,filename,'gif','WriteMode','append','DelayTime',0.1);
end
