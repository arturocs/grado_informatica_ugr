## Pattern Recognition Laboratory – Sessions #3 & #4 Recognition of handwritten digits with linear classifiers 

#### By: Arturo Cortés Sánchez

1.  Error rates of individual basic classifiers in canonical OVO solution (for original & extended data set). Digit classification results for both cases. 

   Original:

   ````octave
   >> compErrors(cfmx)
   ans =
   
      0.913500   0.059800   0.026700
   ````

   Extended:

   ````matlab
   >> compErrors(cfmx)
   ans =
   
      0.9596000   0.0314000   0.0090000
   ````

   

2. Error rates of individual basic classifiers in OVR solution (for original & extended data set). Digit classification results for both cases. 

   Original:

   ````matlab
   >> compErrors(cfmx)
   ans =
   
      0.0023000   0.7347000   0.2630000
   ````

   Extended:

   ````matlab
   >> compErrors(cfmx)
   ans =
   
      0.00050000   0.84440000   0.15510000
   ````

   

3. Error rates of individual basic classifiers in OVR solution trained on balanced positive/negative class training set (for original & extended data set). Digit classification results for both cases.

   Original:

   ````octave
   >> compErrors(cfmx)
   ans =
   
      0.0036500   0.7297333   0.2666167
   ````

   Extended:

   ````octave
   >> compErrors(cfmx)
   ans =
   
      0.0016000   0.8474833   0.1509167
   ````

   