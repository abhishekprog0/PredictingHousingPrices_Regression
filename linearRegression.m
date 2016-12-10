
%% ======================= Part 1: Plotting =======================
fprintf('Plotting Data ...\n')
data = load('trainingdata.txt');
x = data(:, 1); o = data(:, 2);
m = length(o); % number of training examples

% Plot Data
plot(x,o, 'rx', 'Markersize',7)
xlabel('Population in 10000')
ylabel('Profits in 10000')


fprintf('Program paused. Press enter to continue.\n');
pause;

%% =================== Part 2: Gradient descent ===================
fprintf('Running Gradient Descent ...\n')

x = [ones(m, 1), data(:,1)]; % Add a column of ones to x
p= zeros(2, 1); % initialize fitting parameters

% Some gradient descent settings
iterations = 1500;
alpha = 0.01;

% compute and display initial cost
computeCost(x, o, p)

% run gradient descent
p = gradientDescent(x, o, p, alpha, iterations);

% print theta to screen
fprintf('Theta found by gradient descent: ');
fprintf('%f %f \n', p(1), p(2));

% Plot the linear fit
hold on; % keep previous plot visible
plot(x(:,2), x*p, '-')
legend('Training data', 'Linear regression')
hold off % don't overlay any more plots on this figure

% Predict values for population sizes of 35,000 and 70,000
predict1 = [1, 3.5] *p;
fprintf('For population = 35,000, we predict a profit of %f\n',...
    predict1*10000);
predict2 = [1, 7] * p;
fprintf('For population = 70,000, we predict a profit of %f\n',...
    predict2*10000);

fprintf('Program paused. Press enter to continue.\n');
pause;

%% ============= Part 3: Visualizing J(theta_0, theta_1) =============
fprintf('Visualizing J(theta_0, theta_1) ...\n')

% Grid over which we will calculate J
theta0_vals = linspace(-10, 10, 100);
theta1_vals = linspace(-1, 4, 100);

% initialize J_vals to a matrix of 0's
J_vals = zeros(length(theta0_vals), length(theta1_vals));

% Fill out J_vals
for i = 1:length(theta0_vals)
    for j = 1:length(theta1_vals)
	  t = [theta0_vals(i); theta1_vals(j)];    
	  J_vals(i,j) = computeCost(x, o, t);
    end
end


% Because of the way meshgrids work in the surf command, we need to 
% transpose J_vals before calling surf, or else the axes will be flipped
J_vals = J_vals';
% Surface plot
figure;
surf(theta0_vals, theta1_vals, J_vals)
xlabel('\theta_0'); ylabel('\theta_1');

% Contour plot
figure;
% Plot J_vals as 15 contours spaced logarithmically between 0.01 and 100
contour(theta0_vals, theta1_vals, J_vals, logspace(-2, 3, 20))
xlabel('\theta_0'); ylabel('\theta_1');
hold on;
plot(p(1), p(2), 'rx', 'MarkerSize', 10, 'LineWidth', 2);
