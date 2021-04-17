clc;
load('conductance.mat');
A = permute(GW0_d,[2 3 1]);
E = zeros(size(A));
V_set = 0.8; % Fixed SET voltage
V_reset = 0.8; % Fixed RESET voltage
tp = 100*10^-9;
Q = size(A,3);
E_epoch = zeros([95,1]); x=zeros([95,1]);

for k = 2:Q
    E(:,:,k) = (V_set^2*(A(:,:,k) > A(:,:,k-1))+V_reset^2*(A(:,:,k) < A(:,:,k-1))).*(A(:,:,k-1))*tp;
    E1 = E(:,:,k);
    E_epoch(k) = sum(E1,'all')+E_epoch(k-1);
    x(k)=k;
end
total_E = sum(E, 'all');

plot(x,E_epoch,'-o');
