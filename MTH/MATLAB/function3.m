function [outputArg1] = function3(x,C)
%Function computes output of Problem 3 f(x).
%   Input extra parameter C.
outputArg1 = x*exp(-C*x.^2);
end