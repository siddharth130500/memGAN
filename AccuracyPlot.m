load('accuracy.mat');
sz = size(accuracy,2);

x = zeros(1,sz);
for i=1:sz
    x(i)=i;
end

figure, plot(x,accuracy);
xlabel('epochs');
ylabel('accuracy');