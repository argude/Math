% Define a function named PositionMagnitude, with inputs x and y.
function r = PositionMagnitude(x,y) % We set an output variable equal to the function name.
    disp('starting function')  % Notice that the lines inside the function are idented.
    r = ( x.^2 + y.^2 ).^0.5   % Here we calculate the output variable.
end                            % Exit the function
