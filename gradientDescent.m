function [p, J_history] = gradientDescent(x, o, p, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESENT(X, y, theta, alpha, num_iters) updates theta by 
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(o); % number of training examples
J_history = zeros(num_iters, 1);

for iter = 1:num_iters

    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta. 
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCost) and gradient here.
    %
    pred = x*p
    error1 = (pred - o).*x(:,1)
    error2 =(pred - o).*x(:,2)
    p(1) = p(1) - (alpha/m)* sum(error1)
    p(2) = p(2) - (alpha/m)*sum(error2)
    






    % ============================================================

    % Save the cost J in every iteration    
    J_history(iter) = computeCost(x, o, p);

end

end
