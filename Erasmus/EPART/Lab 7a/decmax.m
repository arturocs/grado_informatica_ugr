function labels = decmax(annout)
% Simplest ANN decision: maximum output value decides on the result
% annout - matrix of ANN outputs; each row contains ANN answer for one input sample
% labels - column vector of output labels 
%	[v, labels] = max(annout, [], 2);
  
	[v, labels] = max(annout, [], 2);

  labels(v < 0.7) = 11;
  
  