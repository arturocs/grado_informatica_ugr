## Pattern Recognition Laboratory – Sessions #5 & #6 Fashion items classification with neural networks 

##### By Arturo Cortés Sánchez



Backpropagation function used:

````octave
function [hidlw outlw terr] = backprop(tset, tslb, inihidlw, inioutlw, lr)
% 1. Set output matrices to initial values
	hidlw = inihidlw;
	outlw = inioutlw;
% 2. Set total error to 0
	terr = 0;
	minusones = -1 * ones(1, columns(outlw));
% foreach sample in the training set
	for i=1:rows(tset)
		% 3. Set desired output of the ANN
		dout = -1 * ones(1, columns(outlw));%start everithing at -1
      	dout(tslb(i)) = 1; % change the current iterator to 1 
		% 4. Propagate input forward through the ANN
      	hlout =actf(tset(i, :) * hidlw(1:end-1, :) + hidlw(end, :));
     	outf = actf(hlout * outlw(1:end-1, :) + outlw(end, :));
		% 5. Adjust total error
        terr = sum(((dout - outf) .^ 2) .* 0.5);
        % 6. Compute delta error of the output layer
        d_out=(dout - outf) .* actdf(outf);
        % 7. Compute delta error of the hidden layer
        d_hid=(outlw * d_out')(1:end-1) .* actdf(hlout)';
      	% 8. Update output layer weights
      	outlw += lr * [hlout 1]' * d_out;
      	% 9. Update hidden layer weights
     	hidlw += lr * [tset(i,:) 1]' *d_hid';
	end
````



---



Sigmoid activation function

````octave
res = 2 ./ 	(1+exp(-2*tact)) - 1;
````

Derivative of sigmoid activation function

````octave
res=0.5*(1-sfvalue.^ 2);
````



----



Training set results:

````octave
>> errcf
errcf =

   0.93715   0.06285   0.00000


>> cfmx
cfmx =

   5677      9     56    103     20      2     93      0     37      3      0
     12   5918      2     52      7      1      5      1      1      1      0
     92      3   5151     77    396      0    260      0     19      2      0
     76     11     20   5766     85      0     30      0     12      0      0
     21      4    238    129   5372      0    219      0     16      1      0
      1      0      0      3      0   5919      1     43      7     26      0
    679      8    218    165    207      0   4671      1     50      1      0
      0      0      1      0      0      8      0   5925      3     63      0
     14      0     12     17     13      1     14      7   5919      3      0
      1      0      0      1      0      5      0     80      2   5911      0


````

Test set results:

````octave
>> errcf2
errcf2 =

   0.88010   0.11990   0.00000


>> cfmx2
cfmx2 =

   865     0    19    34     7     2    61     0    12     0     0
     6   968     2    17     3     0     2     0     2     0     0
    18     0   780    18   106     0    76     0     2     0     0
    30     7    12   907    33     0     9     0     1     1     0
     0     1    78    37   803     1    70     0    10     0     0
     1     0     0     1     0   948     0    27     2    21     0
   178     1    74    38    66     0   631     0    12     0     0
     0     0     0     0     0    11     0   968     0    21     0
     4     2     3     8     3     2     3     5   970     0     0
     0     0     0     0     0     7     1    31     0   961     0
````

