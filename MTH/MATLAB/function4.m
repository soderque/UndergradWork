function [outputArg2] = function4(k)
%Computes output of Problem 4 for prime numbers.
%   Give a positive integer k for input.
p = primes(k);
gaps=[];
for i=1:length(p)-1
    gaps(i) = p(i+1)-p(i);
end
outputArg2 = zeros(1,2);
r=1;
for i=1:length(gaps)
    if gaps(i)==2
        outputArg2(r,1)=p(i);
        outputArg2(r,2)=p(i+1);
        r = r+1;
    end
end
end