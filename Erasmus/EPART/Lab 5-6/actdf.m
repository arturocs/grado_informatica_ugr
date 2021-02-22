function res = actdf(sfvalue)
% derivative of sigmoid activation function
% sfvalue - value of sigmoid activation function (!!!)

	res=0.5*(1-sfvalue.^ 2);
