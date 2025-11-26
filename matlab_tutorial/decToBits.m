function bits = decToBits(n,nbits,order)
    if nargin < 2 || isempty(nbits)
        if (n == 0)
            nbits = 1;
        else 
            nbits = floor(log2(double(n))) + 1; 
        end
    end
    if nargin < 3
        order = 'MSB';
    end
    bits = zeros(1, nbits); % Initialize the bits array
    for i = 0:nbits-1
        if strcmp(order, 'MSB')
            bits(i+1) = bitget(n, nbits-i); % Get bits in MSB order
        else
            bits(i+1) = bitget(n, i+1); % Get bits in LSB order
        end
    end
end