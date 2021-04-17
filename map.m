
load('conductance.mat');
A = permute(GW0_g,[2 3 1]);
Q = size(A,3);
W = A(:,:,1);
W1 = A(:,:,2);
h = pcolor(W);
drawnow();
pause(0.3);
for K = 3 : Q
    W = A(:,:,K);
    set(h, 'CData', W);
    %caxis([8, 9]);
    colorbar;
    drawnow();
    pause(0.05);
end