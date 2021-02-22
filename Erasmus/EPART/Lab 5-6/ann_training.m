% read dataset, show and correct labels
[tvec tlab tstv tstl] = readSets(); 
[unique(tlab)'; unique(tstl)']
tlab += 1;
tstl += 1;

% how many samples are there in each class?
[unique(tlab)'; sum(tlab == unique(tlab)')]
[unique(tstl)'; sum(tstl == unique(tstl)')]

% display 100 samples of fashion-mnist as a square image
#imsize = 28;
#fim = zeros((imsize + 2) * 10 + 2);

%for clid = 1:10
%  rowid = (clid - 1) * (imsize + 2) + 3;
%  clsamples = find(tlab == clid)(1:10);
%  for spid = 1:10
%	colid = (spid - 1) * (imsize + 2) + 3;
%	im = 1-reshape(tvec(clsamples(spid),:), imsize, imsize)';
%	fim(rowid:rowid+imsize-1, colid:colid+imsize-1) = im;
%  end
%end
% imshow(fim)

% store data for normalization
mu = mean(tvec);
sig = std(tvec);

noHiddenNeurons = 100;
noEpochs = 500;
learningRate = 0.005;

% to get and save the rnd state generator use these three lines
%rand()
%rstate = rand("state");
%save rnd_state.txt rstate

% to load saved rnd state use these three lines
 rand()
 load rnd_state.txt 
 rand("state", rstate);

% no normalization
[hlnn olnn] = crann(columns(tvec), noHiddenNeurons, 10);
trainError = zeros(1, noEpochs);
testError = zeros(1, noEpochs);
trReport = [];
for epoch=1:noEpochs

	tic();
	[hlnn olnn terr] = backprop(tvec, tlab, hlnn, olnn, learningRate);
	clsRes = anncls(tvec, hlnn, olnn);
	cfmx = confMx(tlab, clsRes);
	errcf = compErrors(cfmx)
	trainError(epoch) = errcf(2);

	clsRes = anncls(tstv, hlnn, olnn);
	cfmx2 = confMx(tstl, clsRes);
	errcf2 = compErrors(cfmx2)
	testError(epoch) = errcf2(2);
	epochTime = toc();
	disp([epoch epochTime trainError(epoch) testError(epoch)])
	trReport = [trReport; epoch epochTime trainError(epoch) testError(epoch)];
	fflush(stdout);
end
