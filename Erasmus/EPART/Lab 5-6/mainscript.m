% load data and remap labels
[tvec tlab tstv tstl] = readSets(); 
tlab += 1;
tstl += 1;

% remove columns with zero std 
toPreserve = std(tvec) != 0;
tvec = tvec(:, toPreserve);
tstv = tstv(:, toPreserve);

% Data is ready - first prepare ANN classifier
% we'll need:
%	activation function (actf)
%	two matrices containing weights of our ANN
%		let's close this code in separate function (crann)
%	classifier function itself
 features_size = columns(tvec);
  labels_size = rows(unique(tlab)); 
[hidl outl] =  crann(features_size, 80 , labels_size);

% xor data set
tset = tvec(1:40000,:);
tslb = tlab(1:40000,:);

res = anncls(tset, hidl, outl);
cmx = confMx(tslb, res)
compErrors(cmx)

% classifier is ready; now time for training
% we'll need:
%	derivative of the activation function
%	backprop function which performs iterative backpropagation training

#plot(x, actdf(x))
[hhidl ooutl ter] = backprop(tset, tslb, hidl, outl, 0.005);

for q=1:30
	[hhidl ooutl ter] = backprop(tset, tslb, hhidl, ooutl, 0.005);
	res = anncls(tset, hhidl, ooutl);
	cmx = confMx(tslb, res);
	compErrors(cmx)
end
 
 
