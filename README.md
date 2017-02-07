# LinearRegression
C++ implementation of **Simple Linear Regression** and **Multivariate Linear Regression** models using **Gradient Descent** Learning Algorithm.

The same will be used in the project of **Predicting Housing Prices** having number of features like *Size(in feet^2), No. of bedrooms, No. of floors, Age of house(in years)* etc. 

To learn about Linear Regression, check out **Andrew NG's** course videos on Machine Learning : https://www.coursera.org/learn/machine-learning/lecture/6Nj1q/multiple-features  

## Project Details

There are N feature variables of M training input data. For each of the M training input data, there are M training output data ( prize of the house ).

The task of this project is to build a model which can successfully predict the prize of house corresponding to new data involving N feature variables.

*The project code passed all the test cases provided by Hackerrank on an Expert level problem : https://www.hackerrank.com/challenges/predicting-house-prices.*

Added a comment line on the code for **Regularization of each feature variables using Mean Normalization**.

Things to improve in the code : Implementing **Stochastic gradient descent** and/or **stop when the improvement drops below a threshold** for improving the termination condition to lower the time complexity and performance efficiency of prediction
