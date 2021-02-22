function ovosp = trainOVRensamble(tset, tlab, htrain)
% Trains a set of linear classifiers (one versus one class)
% on the training set using trainSelect function
% tset - training set samples
% tlab - labels of the samples in the training set
% htrain - handle to proper function computing separating plane
% ovosp - one versus one class linear classifiers matrix
%   the first column contains positive class label
%   the second column contains negative class label
%   columns (3:end) contain separating plane coefficients

  labels = unique(tlab);
  
  % nchoosek produces all possible unique pairs of labels
  % that's exactly what we need for ovo classifier
  ovosp = zeros(rows(labels), 2 + 1 + columns(tset));
  
  for i=1:rows(labels)
	% store labels in the first two columns
    ovosp(i, 1:2) = [labels(i) 0];
	
	% select samples of two digits from the training set
    posSamples = tset(tlab == labels(i), :);
    negSamples = tset(tlab != labels(i), :);
	
	% train 5 classifiers and select the best one
    [sp fp fn] = trainSelect(posSamples, negSamples, 5, htrain);
	
	% what to do with errors?
	% it would be wise to add additional output argument
	% to return error coefficients
	
    % store the separating plane coefficients (this is our classifier)
	% in ovo matrix
    ovosp(i, 3:end) = sp; 
  end
