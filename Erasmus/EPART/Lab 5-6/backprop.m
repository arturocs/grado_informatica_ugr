function [hidlw outlw terr] = backprop(tset, tslb, inihidlw, inioutlw, lr)
% derivative of sigmoid activation function
% tset - training set (every row represents a sample)
% tslb - column vector of labels 
% inihidlw - initial hidden layer weight matrix
% inioutlw - initial output layer weight matrix
% lr - learning rate

% hidlw - hidden layer weight matrix
% outlw - output layer weight matrix
% terr - total squared error of the ANN

% 1. Set output matrices to initial values
	hidlw = inihidlw;
	outlw = inioutlw;
	
% 2. Set total error to 0
	terr = 0;
	
	minusones = -1 * ones(1, columns(outlw));
% foreach sample in the training set
	for i=1:rows(tset)
		% 3. Set desired output of the ANN
		dout = -1 * ones(1, columns(outlw)); %start everithing at -1
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
