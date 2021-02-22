function pdf = pdf_parzen(pts, para)
% Approximates probability density function with Parzen window
% pts  - contains points for which pdf is computed (sample = row)
% para - structure containing parameters:
%	para.labels - class labels
%	para.samples - cell array containing class samples
%	para.parzenw - Parzen window width
% pdf - probability density matrix
%	row count = number of samples in pts
%	column count = number of classes

	% final result matrix
	pdf = rand(rows(pts), rows(para.samples));

	% YOUR CODE GOES HERE
	
	% for each class
	for clid = 1:rows(para.labels)
		% you know number of samples in this class so you can allocate 
		% intermediate matrix (it contains columns f1 f2 ... fn from diagram in instruction)
		clts = para.samples{clid};
		onedpdfs = zeros(rows(clts), columns(clts));	
		hn=para.parzenw/sqrt(rows(clts));
		% for each sample in pts
		for smpl = 1:rows(pts)
			% for each feature
			for ftid = 1:columns(pts)
				% fill proper column in onedpdfs with call to normpdf
				onedpdfs(:,ftid) = normpdf(clts(:,ftid), pts(smpl,ftid), hn);
			end
			% aggregate onedpdfs into a scalar value
			% and store it in proper element of pdf
			pdf(smpl, clid)=mean(prod(onedpdfs,2));		
		end

	end

end
