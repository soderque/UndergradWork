function [val,pos] = mymax(v1)
%Produces maximum of a given column vector and its first position in the
%matrix. 
val=v1(1);
pos=1;
for i=1:length(v1)
    if v1(i)>val
        val=v1(i);
        pos=i;
    end
end
end

