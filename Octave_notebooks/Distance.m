% Define a function named Distance, with inputs x and y.
function r = Distance(x,y) % We set an output variable equal to the function name.
    global xReference
    global yReference
    disp('starting function')  % Notice that the lines inside the function are idented.
    r = ( (x-xReference).^2 + (y-yReference).^2 ).^0.5   % Here we calculate the output variable.
end                            % Exit the function
