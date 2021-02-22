% tiny data file to verify pdf functions
load pdf_test.txt
size(pdf_test)

% how many classes are there?
labels = unique(pdf_test(:,1))

% how many samples are in each class?
[labels'; sum(pdf_test(:,1) == labels')]
		  % ^^^ how does this expression work?

% what's the layout of the samples?
plot2features(pdf_test, 2, 3)


pdfindep_para = para_indep(pdf_test)
% para_indep indep is already implemented; it should give:

% pdfindep_para =
%  scalar structure containing the fields:
%    labels =
%       1
%       2
%    mu =
%       0.7970000   0.8200000
%      -0.0090000   0.0270000
%    sig =
%       0.21772   0.19172
%       0.19087   0.27179

% now you have to implement pdf_indep 
pi_pdf = pdf_indep(pdf_test([2 7 12 17],2:end), pdfindep_para)

%pi_pdf =
%  1.4700e+000  4.5476e-007
%  3.4621e+000  4.9711e-005
%  6.7800e-011  2.7920e-001
%  5.6610e-008  1.8097e+000

% multivariate normal distribution - parameters ...

pdfmulti_para = para_multi(pdf_test)

%pdfmulti_para =
%  scalar structure containing the fields:
%    labels =
%       1
%       2
%    mu =
%       0.7970000   0.8200000
%      -0.0090000   0.0270000
%    sig =
%    ans(:,:,1) =
%       0.047401   0.018222
%       0.018222   0.036756
%    ans(:,:,2) =
%       0.036432  -0.033186
%      -0.033186   0.073868  

% ... and probability density function (use mvnpdf in pdf_multi)
pm_pdf = pdf_multi(pdf_test([2 7 12 17],2:end), pdfmulti_para)

%pm_pdf =
%  7.9450e-001  6.5308e-017
%  3.9535e+000  3.8239e-013
%  1.6357e-009  8.6220e-001
%  4.5833e-006  2.8928e+000

% parameters for Parzen window approximation 
pdfparzen_para = para_parzen(pdf_test, 0.5)
									 % ^^^ window width

%pdfparzen_para =
%  scalar structure containing the fields:
%    labels =
%       1
%       2
%    samples =
%    {
%      [1,1] =
%         1.10000   0.95000
%         0.98000   0.61000
% .....
%         0.69000   0.93000
%         0.79000   1.01000
%      [2,1] =
%        -0.010000   0.380000
%         0.250000  -0.440000
% .....
%        -0.110000   0.030000
%         0.120000  -0.090000
%    }
%    parzenw =  0.50000

pp_pdf = pdf_parzen(pdf_test([2 7 12 17],2:end), pdfparzen_para)

%pp_pdf =
%  9.7779e-001  6.1499e-008
%  2.1351e+000  4.2542e-006
%  9.4059e-010  9.8823e-001
%  2.0439e-006  1.9815e+000


% now you can start work with cards!
[train test] = load_cardsuits_data();

% Our first look at the data
size(train)
size(test)
labels = unique(train(:,1))
unique(test(:,1))
[labels'; sum(train(:,1) == labels')]

% the first task after loading the data is checking
% training set for outliers; to this end we usually compute 
% simple statistics: mean, median, std, 
% and/or plot histogram of individual feature: hist
% and/or plot two features at a time: plot2features

[mean(train); median(train)]
hist(train(:,1))
plot2features(train, 4, 6)
					%^^^^ just an example
					
% to identify outliers you can use two output argument versions 
% of min and max functions

[mv midx] = min(train)

% because the minimum or maximum values can be determined always,
% it's worth to look at neighbors of the suspected sample in the training set

% let's assume that sample 41 is suspected
midx = 41
train(midx-1:midx+1, :)
% it seems that these three rows are very similar to each other...
% that's because 41 is evidently not an outlier index

% if you're sure tha midx sample should be removed:
size(train)
train([186,642],:)=[];
size(train)

plot2features(train, 2, 3)

% the procedure of searching for and removing outliers must be repeated 
% until no outliers exist in the training set

% after removing outliers, you can deal with the selection of TWO features for classification
% in this case, it is enough to look at the graphs of two features and choose the ones that
% give relatively well separated classes

% after selecting features reduce both sets:
train = train(:, [1 2 3]);
test = test(:, [1 2 3]);

	
	
% POINT 2

pdfindep_para = para_indep(train);
pdfmulti_para = para_multi(train);
pdfparzen_para = para_parzen(train, 0.001); 
% this window width should be included in your report!

% Point 2 results
base_ercf = zeros(1,3);
base_ercf(1) = mean(bayescls(test(:,2:end), @pdf_indep, pdfindep_para) != test(:,1));
base_ercf(2) = mean(bayescls(test(:,2:end), @pdf_multi, pdfmulti_para) != test(:,1));
base_ercf(3) = mean(bayescls(test(:,2:end), @pdf_parzen, pdfparzen_para) != test(:,1));
base_ercf

% POINT 3

% In the next point, the reduce function will be useful, which reduces the number of samples 
% in the individual classes (in this case, the reduction will be the same in all classes - 
% OF THE TRAINING SET)
% Because reduce has to draw samples randomly, the experiment should be repeated 5 times
% In the report, please provide only the mean value and the standard deviation 
% of the error coefficient


parts = [0.1 0.1 0.1 0.1 0.1 0.1 0.1 0.1; 0.25 0.25 0.25 0.25 0.25 0.25 0.25 0.25; 0.5 0.5 0.5 0.5 0.5 0.5 0.5 0.5];


rep_cnt = 5; % at least

% YOUR CODE GOES HERE 
%

% note that for given experiment you should reduce all classes in the training
% set with the same reduction coefficient; assuming that class_count is the 
% number of different classes in the training set you can take 3/4 random samples
% of each class with:
% 	reduced_train = reduce(train, 0.75 * ones(1, class_count))
% 

err= zeros(rep_cnt, rows(parts)); % matrix of error coefficients
% pdfparzen_para.labels = labels;
% pdfparzen_para.parzenw = 0.0001;

for i = 1:rows(parts) % for each size
    for j = 1:rep_cnt % we repeat 5 times
        reduced_train= reduce(train, parts(i,:)); % we reduce the training set
        pdfparzen_para.samples = cell(rows(labels),1);
        for k = 1:rows(labels) % we update the samples of the parzen window
            pdfparzen_para.samples{k} = reduced_train(reduced_train(:,1) == labels(k), 2:end);
        end
        err(j,i) = mean(bayescls(test(:,2:end), @pdf_parzen, pdfparzen_para) != test(:,1)); % we save the error coefficient
    end
end

mean (err) % mean of the error coefficient

std (err) % standard deviation of the error coefficient

% POINT 4
% Point 4 concerns only Parzen window classifier (on the full training set)

parzen_widths = [0.0001, 0.0005, 0.001, 0.005, 0.01];
parzen_res = zeros(1, columns(parzen_widths));

% YOUR CODE GOES HERE 
%

for i=1:rows(labels)
	pdfparzen_para.samples{i} = train(train(:,1) == labels(i), 2:end);
end
for i=1:columns(parzen_widths)
	pdfparzen_para.parzenw = parzen_widths(i);
	parzen_res(i) = mean(bayescls(test(:,2:end), @pdf_parzen, pdfparzen_para) != test(:,1) );
end


[parzen_widths; parzen_res]
% Plots are sometimes better than numerical results
semilogx(parzen_widths, parzen_res)

% POINT 5
% In point 5 you should reduce TEST SET (no need to touch train set)
%
 
apriori = [0.085 0.165 0.165 0.085 0.085 0.165 0.165 0.085];
parts = [0.5 1.0 1.0 0.5 0.5 1.0 1.0 0.5];

% YOUR CODE GOES HERE 
%
pdfparzen_para.labels = labels;
pdfparzen_para.samples = cell(rows(labels),1)
pdfparzen_para.parzenw = 0.0001; % width of the window

for i=1:rows(labels)
	pdfparzen_para.samples{i} = train(train(:,1) == labels(i), 2:end);
end


err = mean(bayescls(test(:,2:end), @pdf_parzen, pdfparzen_para, apriori) != test(:,1))
tmp = reduce(test, parts);
err = mean(bayescls(tmp(:,2:end), @pdf_parzen, pdfparzen_para, apriori) != tmp(:,1))


% POINT 6
% In point 6 we should consider data normalization

std(train(:,2:end))

% Should we normalize?
% If YES remember to normalize BOTH training and testing sets

% YOUR CODE GOES HERE 
%

normfact = std(train)
normfact(1)=1
train_norm=bsxfun(@rdivide, train, normfact);
test_norm = bsxfun(@rdivide, test, normfact);
std(train)
std(train_norm)
unique(train_norm(:,1))
std(test_norm)


res = zeros (rows(train_norm), 1);
for i=1:rows(train_norm)
	res(i) = cls1nn( train_norm(i, 2:end), train_norm([1:i-1 i+1:end], :));
end
err = mean(res != train_norm(:,1))


pdfindep_para.labels = labels;
pdfindep_para.mu = zeros(rows(labels), columns(train)-1);
pdfindep_para.sig = zeros(rows(labels), columns(train)-1); 

for i=1:rows(labels)
	cl = labels(i);
	pdfindep_para.mu(i, :) = mean(train_norm(train_norm(:,1)==cl, 2:end));
	pdfindep_para.sig(i, :) = std(train_norm(train_norm(:,1)==cl, 2:end));
end

base_ercf(1)

mean(bayescls(test_norm(:,2:end), @pdf_indep, pdfindep_para) != test_norm(:,1) )


